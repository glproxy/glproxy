#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright © 2013 Intel Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.

import sys
import argparse
import xml.etree.ElementTree as ET
import re
import os

class GLProvider(object):
    def __init__(self, condition, name):
        # A dict describing the condition.
        self.condition = condition

        # The name of the function to be loaded (possibly an
        # ARB/EXT/whatever-decorated variant).
        self.name = name
        if 'extension' in condition:
            self.sort_key = '2extension:' + condition['extension']
        elif 'version' in condition:
            self.sort_key = '1version:' + '{0:08d}'.format(condition['version'])
        else:
            self.sort_key = '0direct:'
        self.condition_name = self.sort_key

class GLFunction(object):
    def __init__(self, ret_type, name):
        self.name = name
        self.ptr_type = 'PFN' + name.upper() + 'PROC'
        self.ret_type = ret_type
        self.providers = {}
        self.args = []


        self.wrapped_name = name
        self.public = 'GLPROXY_IMPORTEXPORT '

        # This is the string of C code for passing through the
        # arguments to the function.
        self.args_list = ''

        # This is the string of C code for declaring the arguments
        # list.
        self.args_decl = 'void'

        # This is the string name of the function that this is an
        # alias of, or self.name.  This initially comes from the
        # registry, and may get updated if it turns out our alias is
        # itself an alias (for example glFramebufferTextureEXT ->
        # glFramebufferTextureARB -> glFramebufferTexture)
        self.alias_name = name

        # After alias resolution, this is the function that this is an
        # alias of.
        self.alias_func = None

        # For the root of an alias tree, this lists the functions that
        # are marked as aliases of it, so that it can write a resolver
        # for all of them.
        self.alias_exts = []

    def add_arg(self, type, name):
        # Reword glDepthRange() arguments to avoid clashing with the
        # "near" and "far" keywords on win32.
        if name == "near":
            name = "hither"
        elif name == "far":
            name = "yon"

        # Mac screwed up GLhandleARB and made it a void * instead of
        # uint32_t, despite it being specced as only necessarily 32
        # bits wide, causing portability problems all over.  There are
        # prototype conflicts between things like
        # glAttachShader(GLuint program, GLuint shader) and
        # glAttachObjectARB(GLhandleARB container, GLhandleARB obj),
        # even though they are marked as aliases in the XML (and being
        # aliases in Mesa).
        #
        # We retain those aliases.  In the x86_64 ABI, the first 6
        # args are stored in 64-bit registers, so the calls end up
        # being the same despite the different types.  We just need to
        # add a cast to khronos_uintptr_t to shut up the compiler.
        if type == 'GLhandleARB':
            assert(len(self.args) < 6)
            arg_list_name = '(khronos_uintptr_t)' + name
        else:
            arg_list_name = name

        self.args.append((type, name))
        if self.args_decl == 'void':
            self.args_list = arg_list_name
            self.args_decl = type + ' ' + name
        else:
            self.args_list += ', ' + arg_list_name
            self.args_decl += ', ' + type + ' ' + name

    def add_provider(self, condition):
        self.providers[str(condition)] = GLProvider(condition, self.name)

    def add_alias(self, ext):
        assert self.alias_func is None

        self.alias_exts.append(ext)
        ext.alias_func = self

class Generator(object):
    def __init__(self, target):
        self.target = target
        self.enums = {}
        self.functions = {}
        self.sorted_function = None
        self.max_enum_name_len = 1
        self.copyright_comment = None
        self.typedefs = ''
        self.out_file = None

        # GL versions named in the registry, which we should generate
        # #defines for.
        self.supported_versions = set()

        # Extensions named in the registry, which we should generate
        # #defines for.
        self.supported_extensions = set()


    def all_text_until_element_name(self, element, element_name):
        text = ''

        if element.text is not None:
            text += element.text

        for child in element:
            if child.tag == element_name:
                break
            if child.text:
                text += child.text
            if child.tail:
                text += child.tail
        return text

    def out(self, text):
        self.out_file.write(text)

    def outln(self, text):
        self.out_file.write(text + '\n')

    def parse_typedefs(self, reg):
        for t in reg.findall('types/type'):
            if 'name' in t.attrib and t.attrib['name'] not in {'GLhandleARB'}:
                continue

            # The gles1/gles2-specific types are redundant
            # declarations, and the different types used for them (int
            # vs int32_t) caused problems on win32 builds.
            api = t.get('api')
            if api:
                continue

            if t.text is not None:
                self.typedefs += t.text

            for child in t:
                if child.tag == 'apientry':
                    self.typedefs += 'APIENTRY'
                if child.text:
                    self.typedefs += child.text
                if child.tail:
                    self.typedefs += child.tail
            self.typedefs += '\n'

    def parse_enums(self, reg):
        for enum in reg.findall('enums/enum'):
            name = enum.get('name')

            # wgl.xml's 0xwhatever definitions end up colliding with
            # wingdi.h's decimal definitions of these.
            if ('WGL_SWAP_OVERLAY' in name or
                'WGL_SWAP_UNDERLAY' in name or
                'WGL_SWAP_MAIN_PLANE' in name):
                continue

            self.max_enum_name_len = max(self.max_enum_name_len, len(name))
            self.enums[name] = enum.get('value')

    def get_function_return_type(self, proto):
        # Everything up to the start of the name element is the return type.
        return self.all_text_until_element_name(proto, 'name').strip()

    def parse_function_definitions(self, reg):
        for command in reg.findall('commands/command'):
            proto = command.find('proto')
            name = proto.find('name').text
            ret_type = self.get_function_return_type(proto)

            func = GLFunction(ret_type, name)

            for arg in command.findall('param'):
                func.add_arg(self.all_text_until_element_name(arg, 'name').strip(),
                             arg.find('name').text)

            alias = command.find('alias')
            if alias is not None:
                # Note that some alias references appear before the
                # target command is defined (glAttachObjectARB() ->
                # glAttachShader(), for example).
                func.alias_name = alias.get('name')

            self.functions[name] = func

    def drop_weird_glx_functions(self):
        # Drop a few ancient SGIX GLX extensions that use types not defined
        # anywhere in Xlib.  In glxext.h, they're protected by #ifdefs for the
        # headers that defined them.
        weird_functions = [name for name, func in self.functions.items()
                           if 'VLServer' in func.args_decl
                           or 'DMparams' in func.args_decl]

        for name in weird_functions:
            del self.functions[name]

    def resolve_aliases(self):
        for func in self.functions.values():
            # Find the root of the alias tree, and add ourselves to it.
            if func.alias_name != func.name:
                alias_func = func
                while alias_func.alias_name != alias_func.name:
                    alias_func = self.functions[alias_func.alias_name]
                func.alias_name = alias_func.name
                func.alias_func = alias_func
                alias_func.alias_exts.append(func)

    def prepare_provider_enum(self):
        self.provider_enum = {}

        # We assume that for any given provider, all functions using
        # it will have the same loader.  This lets us generate a
        # general C function for detecting conditions and calling the
        # dlsym/getprocaddress, and have our many resolver stubs just
        # call it with a table of values.
        for func in self.functions.values():
            for provider in func.providers.values():
                if provider.condition_name in self.provider_enum:
                    assert(self.provider_enum[provider.condition_name] == provider.condition)
                    continue

                self.provider_enum[provider.condition_name] = provider.condition;

    def sort_functions(self):
        self.sorted_functions = sorted(self.functions.values(), key=lambda func:func.name)

    def process_require_statements(self, feature, condition):
        for command in feature.findall('require/command'):
            name = command.get('name')

            # wgl.xml describes 6 functions in WGL 1.0 that are in
            # gdi32.dll instead of opengl32.dll, and we would need to
            # change up our symbol loading to support that.  Just
            # don't wrap those functions.
            if self.target == 'wgl' and 'wgl' not in name:
                del self.functions[name]
                continue;

            func = self.functions[name]
            func.add_provider(condition)

    def parse_function_providers(self, reg):
        self.es_version_start = 10000
        for feature in reg.findall('feature'):
            api = feature.get('api') # string gl, gles1, gles2, glx
            m = re.match('([0-9])\.([0-9])', feature.get('number'))
            version_major = int(m.group(1))
            version_minor = int(m.group(2))
            version = version_major * 10 + version_minor

            self.supported_versions.add(feature.get('name'))
            condition = {}
            if api == 'gl':
                condition = {
                  'api':'gl',
                  'enum_name': 'OpenGL_Desktop_{0}_{1}'.format(version_major, version_minor),
                  'version': version
                }
            elif api == 'gles2':
                condition = {
                  'api':'gl',
                  'enum_name': 'OpenGL_ES_{0}_{1}'.format(version_major, version_minor),
                  'version': self.es_version_start + version
                }
            elif api == 'gles1':
                condition = {
                  'api':'gl',
                  'enum_name': 'OpenGL_ES_1_0',
                  'version': self.es_version_start + 10
                }
            elif api == 'glx':
                condition = {
                  'api':'glx',
                  'enum_name': 'GLX_{0}_{1}'.format(version_major, version_minor),
                  "direct": True,
                  'version': version
                }
            elif api == 'egl':
                condition = {
                  'api':'egl',
                  'enum_name': 'EGL_{0}_{1}'.format(version_major, version_minor),
                  'version': version
                }
                if version == 10:
                  condition['direct'] = True
            elif api == 'wgl':
                condition = {
                  'api':'wgl',
                  "direct": True,
                  'enum_name': 'WGL_{0}_{1}'.format(version_major, version_minor),
                  'version': version
                }
            else:
                print('unknown API: "{0}"'.format(api))
                continue

            self.process_require_statements(feature, condition)

        for extension_feature in reg.findall('extensions/extension'):
            extname = extension_feature.get('name')

            self.supported_extensions.add(extname)

            # 'supported' is a set of strings like gl, gles1, gles2,
            # or glx, which are separated by '|'
            apis = extension_feature.get('supported').split('|')
            if 'glx' in apis:
                self.process_require_statements(extension_feature, {
                  'api':'glx',
                  'extension': extname
                })
            if 'egl' in apis:
                self.process_require_statements(extension_feature, {
                  'api':'egl',
                  'extension': extname
                })
            if 'wgl' in apis:
                self.process_require_statements(extension_feature, {
                  'api':'wgl',
                  'extension': extname
                })
            if {'gl', 'gles1', 'gles2'}.intersection(apis):
                self.process_require_statements(extension_feature, {
                  'api':'gl',
                  'extension': extname
                })

    def fixup_bootstrap_function(self, name):
        # We handle glGetString(), glGetIntegerv(), and
        # glXGetProcAddressARB() specially, because we need to use
        # them in the process of deciding on loaders for resolving,
        # and the naive code generation would result in their
        # resolvers calling their own resolvers.
        if name not in self.functions:
            return

        func = self.functions[name]
        for key in func.providers:
            func.providers[key].condition['direct'] = True

    def parse(self, file):
        reg = ET.parse(file)
        if reg.find('comment') != None:
            self.copyright_comment = reg.find('comment').text
        else:
            self.copyright_comment = ''
        self.parse_typedefs(reg)
        self.parse_enums(reg)
        self.parse_function_definitions(reg)
        self.parse_function_providers(reg)

    def write_copyright_comment_body(self):
        for line in self.copyright_comment.splitlines():
            if '-----' in line:
                break
            self.outln(' * ' + line)

    def write_enums(self):
        for name in sorted(self.supported_versions):
            self.outln('#define {0} 1'.format(name))
        self.outln('')

        for name in sorted(self.supported_extensions):
            self.outln('#define {0} 1'.format(name))
        self.outln('')

        # We want to sort by enum number (which puts a bunch of things
        # in a logical order), then by name after that, so we do those
        # sorts in reverse.  This is still way uglier than doing some
        # sort based on what version/extensions things are introduced
        # in, but we haven't paid any attention to those attributes
        # for enums yet.
        sorted_by_name = sorted(self.enums.keys())
        sorted_by_number = sorted(sorted_by_name, key=lambda name: self.enums[name])
        for name in sorted_by_number:
            self.outln('#define ' + name.ljust(self.max_enum_name_len + 3) + self.enums[name] + '')

    def write_function_ptr_typedefs(self):
        for func in self.sorted_functions:
            providers = self.get_function_ptr_providers(func)
            if len(providers) > 0:
              self.outln('typedef {0} (GLAPIENTRY *{1})({2});'.format(func.ret_type,
                                                                    func.ptr_type,
                                                                    func.args_decl))

    def write_header_header(self, file):
        self.out_file = open(file, 'w')

        self.outln('/* GL dispatch header.')
        self.outln(' * This is code-generated from the GL API XML files from Khronos.')
        self.write_copyright_comment_body()
        self.outln(' */')
        self.outln('')

        self.outln('#pragma once')

        self.outln('#include <stddef.h>')
        self.outln('')

    def write_header(self, file):
        self.write_header_header(file)

        self.out(self.typedefs)
        self.outln('')
        self.write_enums()
        self.outln('')
        self.write_function_ptr_typedefs()

        for func in self.sorted_functions:
            providers = self.get_function_ptr_providers(func)
            if len(providers) > 0:
              self.outln('GLPROXY_IMPORTEXPORT {0} GLPROXY_CALLSPEC glproxy_{1}({2});'.format(func.ret_type,
                                                                                     func.name,
                                                                                     func.args_decl))
            self.outln('')

        for func in self.sorted_functions:
            self.outln('#define {0} glproxy_{0}'.format(func.name))

    def get_function_ptr_providers(self, func):
        providers = []
        # Make a local list of all the providers for this alias group
        alias_root = func;
        if func.alias_func:
            alias_root = func.alias_func
        for provider in alias_root.providers.values():
            providers.append(provider)
        for alias_func in alias_root.alias_exts:
            for provider in alias_func.providers.values():
                providers.append(provider)

        # Add some partial aliases of a few functions.  These are ones
        # that aren't quite aliases, because of some trivial behavior
        # difference (like whether to produce an error for a
        # non-Genned name), but where we'd like to fall back to the
        # similar function if the proper one isn't present.
        half_aliases = {
            'glBindVertexArray' : 'glBindVertexArrayAPPLE',
            'glBindVertexArrayAPPLE' : 'glBindVertexArray',
            'glBindFramebuffer' : 'glBindFramebufferEXT',
            'glBindFramebufferEXT' : 'glBindFramebuffer',
            'glBindRenderbuffer' : 'glBindRenderbufferEXT',
            'glBindRenderbufferEXT' : 'glBindRenderbuffer',
        }
        if func.name in half_aliases:
            alias_func = self.functions[half_aliases[func.name]]
            for provider in alias_func.providers.values():
                providers.append(provider)

        def provider_sort(provider):
            return (provider.name != func.name, provider.name, provider.sort_key)
        providers.sort(key=provider_sort);
        return providers

    def write_thunks(self, func, offset):
        # Writes out the function that's initially plugged into the
        # global function pointer, which resolves, updates the global
        # function pointer, and calls down to it.
        #
        # It also writes out the actual initialized global function
        # pointer.
        uppder_name = 'PFN{0}PROC'.format(func.wrapped_name.upper())
        if func.ret_type == 'void' or func.ret_type == 'VOID':
            self.outln('GEN_THUNK({0}, {1}, ({2}), ({3}), {4}, {5})'.format(self.target,
                                                              func.wrapped_name,
                                                              func.args_decl,
                                                              func.args_list,
                                                              offset,
                                                              uppder_name))
        else:
            self.outln('GEN_THUNK_RET({0}, {1}, {2}, ({3}), ({4}), {5}, {6})'.format(self.target, func.ret_type,
                                                                       func.wrapped_name,
                                                                       func.args_decl,
                                                                       func.args_list,
                                                                       offset,
                                                              uppder_name))

    def write_providers_version(self):
        providers = [self.provider_enum[k] for k in self.provider_enum.keys()]
        version_providers = [x for x in providers if 'version' in x]
        if (self.target == 'gl'):
          version_providers.append({
            "api": "gl",
            "enum_name": "OpenGL_Desktop_MIN",
            "version": 0
          })
          version_providers.append({
            "api": "gl",
            "enum_name": "OpenGL_Desktop_MAX",
            "version": self.es_version_start - 1
          })
          version_providers.append({
            "api": "gl",
            "enum_name": "OpenGL_ES_MIN",
            "version": self.es_version_start
          })
          version_providers.append({
            "api": "gl",
            "enum_name": "OpenGL_ES_MAX",
            "version": self.es_version_start + self.es_version_start
          })

        version_providers = sorted(version_providers, key=lambda x: x['version'])
        self.outln('enum {0}_provider_versions {{'.format(self.target))
        for version_provider in version_providers:
            enum_name = version_provider["enum_name"]
            version = version_provider['version']
            self.outln('    {0} = {1},'.format(enum_name, version))
        self.outln('} PACKED;')
        self.outln('')

    def write_providers_extension(self):
        self.extension_offset_map = {}
        extension_providers = sorted(self.supported_extensions)
        extension_count = len(extension_providers)
        self.outln('#define {0}_extensions_count {1}'.format(self.target, extension_count))
        self.outln('')
        self.outln('static khronos_uint32_t {0}_extension_bitmap[{1}];'.format(self.target, ((extension_count - 1) >> 5) + 1))
        self.outln('')
        self.outln('static const char {0}_extension_enum_strings[] ='.format(self.target))
        offset = 0
        for extension_provider in extension_providers:
            self.extension_offset_map[extension_provider] = offset
            self.outln('    "{0}\\0"'.format(extension_provider))
            offset = offset + 1
        self.outln(';')
        self.outln('static const khronos_uint16_t {0}_extension_offsets[] = {{'.format(self.target))
        offset = 0
        for extension_provider in extension_providers:
            self.outln('    {0},'.format(offset))
            offset += len(extension_provider) + 1
        self.outln('};')
        self.outln('')


    def write_entrypoint_strings(self):
        self.entrypoint_string_offset = {}

        self.outln('static const khronos_uint8_t {0}_entrypoint_strings[] = {{'.format(self.target))
        offset = 0
        for func in self.sorted_functions:
            if func.name not in self.entrypoint_string_offset:
                self.entrypoint_string_offset[func.name] = offset
                offset += len(func.name) + 1
                self.out('    ')
                for x in list(func.name):
                    self.out('{0}, '.format(ord(x)))
                self.outln('0, /*{0}*/'.format(func.name))
        self.outln('};')
        self.outln('')

    def write_inc_header(self, file, is_table = False):
        self.out_file = open(file, 'w')

        self.outln('/* GL dispatch code.')
        self.outln(' * This is code-generated from the GL API XML files from Khronos.')
        self.write_copyright_comment_body()
        self.outln(' */')
        if is_table:
            self.outln('#if PLATFORM_HAS_{0}'.format(self.target.upper()))
            self.outln('#include "glproxy/{0}.h"'.format(self.target))
        else:
            self.outln('#include "dispatch_common.h"')
            self.outln('#if PLATFORM_HAS_{0}'.format(self.target.upper()))
        self.outln('')

    def write_table_type_inc(self, file):
        self.write_inc_header(file, True)
        self.outln('struct {0}_dispatch_table {{'.format(self.target))
        for func in self.sorted_functions:
            providers = self.get_function_ptr_providers(func)
            if len(providers) > 0:
              self.outln('    {0} glproxy_{1};'.format(func.ptr_type, func.wrapped_name))
        self.outln('};')
        self.outln('')
        self.write_providers_version()
        self.outln('')
        self.outln('#endif /* PLATFORM_HAS_{0} */'.format(self.target.upper()))

    def write_thunks_inc(self, file):
        self.write_inc_header(file)

        self.write_providers_extension()
        self.write_entrypoint_strings()
        self.outln('static const struct dispatch_resolve_info {0}_resolve_info_table[] = {{'.format(self.target))
        function_number = 0
        self.has_dispatch_direct = 0
        self.has_dispatch_version = 0
        self.function_offsets = {}
        for func in self.sorted_functions:
            providers = self.get_function_ptr_providers(func)
            for provider in providers:
                condition = provider.condition
                name = provider.name
                name_offset = self.entrypoint_string_offset[name]
                identity = function_number % 256
                self.out('    {')
                if ('direct' in condition):
                    self.out('DISPATCH_RESOLVE_DIRECT, {0}, {1}, {2}'.format(identity, condition['enum_name'], name_offset))
                    self.has_dispatch_direct = 1
                elif ('version' in condition):
                    self.out('DISPATCH_RESOLVE_VERSION, {0}, {1}, {2}'.format(identity, condition['enum_name'], name_offset))
                    self.has_dispatch_version = 1
                elif ('extension' in condition):
                    extension_offset = self.extension_offset_map[condition['extension']]
                    self.out('DISPATCH_RESOLVE_EXTENSION, {0}, {1} /* {2} */, {3}'.format(identity, extension_offset, condition['extension'], name_offset))
                else:
                    raise Exception("not valid")
                self.outln('}}, /* {0} */'.format(provider.name))
            if len(providers) > 0:
                self.function_offsets[func.name] = function_number
                function_number = function_number + 1
        identity = function_number % 256
        self.outln('    {{DISPATCH_RESOLVE_TERMINATOR, {0}, 0, 0}}'.format(identity))
        self.outln('};')
        self.outln('')
        self.outln('static khronos_uint16_t {0}_resolve_offsets[{1}] = {{0}};'.format(self.target, function_number));
        self.outln('static khronos_uint32_t {0}_method_name_offsets[{1}] = {{0}};'.format(self.target, function_number));
        self.outln('')
        self.dispatch_generated_inc_list = [
            'resolve',
            'glproxy_resolve_init',
            'glproxy_resolve_direct',
            'glproxy_resolve_version',
            'glproxy_resolve_extension',
            'dispatch_table',
            'metadata',
            'glproxy_resolve_local',
            'glproxy_dispatch_metadata_init',
            'extension_bitmap',
            'extension_offsets',
            'extensions_count',
            'extension_enum_strings',
            'entrypoint_strings',
            'resolve_info_table',
            'resolve_offsets',
            'method_name_offsets',
        ]
        self.outln('#define HAS_DISPATCH_RESOLVE_DIRECT {0}'.format(self.has_dispatch_direct));
        self.outln('#define HAS_DISPATCH_RESOLVE_VERSION {0}'.format(self.has_dispatch_version));
        for suffix in self.dispatch_generated_inc_list:
            self.outln('#define current_{1} {0}_{1}'.format(self.target, suffix))
        self.outln('#include "dispatch_generated.inc"')
        for suffix in self.dispatch_generated_inc_list:
            self.outln('#undef current_{0}'.format(suffix))
        self.outln('#undef HAS_DISPATCH_RESOLVE_DIRECT');
        self.outln('#undef HAS_DISPATCH_RESOLVE_VERSION');

        self.outln('')

        for func in self.sorted_functions:
            if not func.name in self.function_offsets:
                print('Can not resolve `{0}`'.format(func.name))
            else:
                self.write_thunks(func, self.function_offsets[func.name])
        self.outln('')


        self.outln('#endif /* PLATFORM_HAS_{0} */'.format(self.target.upper()))

argparser = argparse.ArgumentParser(description='Generate GL dispatch wrappers.')
argparser.add_argument('files', metavar='file.xml', nargs='+', help='GL API XML files to be parsed')
argparser.add_argument('--dir', metavar='dir', required=True, help='Destination directory')
args = argparser.parse_args()

srcdir = args.dir + '/src/'
incdir = args.dir + '/include/glproxy/'

for file in args.files:
    name = os.path.basename(file).split('.xml')[0]
    generator = Generator(name)
    generator.parse(file)

    generator.drop_weird_glx_functions()

    # This is an ANSI vs Unicode function, handled specially by
    # include/glproxy/wgl.h
    if 'wglUseFontBitmaps' in generator.functions:
        del generator.functions['wglUseFontBitmaps']

    generator.sort_functions()
    generator.resolve_aliases()
    generator.fixup_bootstrap_function('glGetString')
    generator.fixup_bootstrap_function('glGetIntegerv')

    # While this is technically exposed as a GLX extension, it's
    # required to be present as a public symbol by the Linux OpenGL
    # ABI.
    generator.fixup_bootstrap_function('glXGetProcAddress')

    generator.prepare_provider_enum()

    generator.write_header(incdir + name + '_generated.h')
    generator.write_table_type_inc(srcdir + name + '_generated_dispatch_table_type.inc')
    generator.write_thunks_inc(srcdir + name + '_generated_dispatch_thunks.inc')
