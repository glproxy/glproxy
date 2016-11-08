/*
 * Copyright © 2013-2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/**
 * @file dispatch_common.c
 *
 * Implements common code shared by the generated GL/EGL/GLX dispatch code.
 *
 * A collection of some important specs on getting GL function pointers.
 *
 * From the linux GL ABI (http://www.opengl.org/registry/ABI/):
 *
 *     "3.4. The libraries must export all OpenGL 1.2, GLU 1.3, GLX 1.3, and
 *           ARB_multitexture entry points statically.
 *
 *      3.5. Because non-ARB extensions vary so widely and are constantly
 *           increasing in number, it's infeasible to require that they all be
 *           supported, and extensions can always be added to hardware drivers
 *           after the base link libraries are released. These drivers are
 *           dynamically loaded by libGL, so extensions not in the base
 *           library must also be obtained dynamically.
 *
 *      3.6. To perform the dynamic query, libGL also must export an entry
 *           point called
 *
 *           void (*glXGetProcAddressARB(const GLubyte *))(); 
 *
 *      The full specification of this function is available separately. It
 *      takes the string name of a GL or GLX entry point and returns a pointer
 *      to a function implementing that entry point. It is functionally
 *      identical to the wglGetProcAddress query defined by the Windows OpenGL
 *      library, except that the function pointers returned are context
 *      independent, unlike the WGL query."
 *
 * From the EGL 1.4 spec:
 *
 *    "Client API function pointers returned by eglGetProcAddress are
 *     independent of the display and the currently bound client API context,
 *     and may be used by any client API context which supports the extension.
 *
 *     eglGetProcAddress may be queried for all of the following functions:
 *
 *     • All EGL and client API extension functions supported by the
 *       implementation (whether those extensions are supported by the current
 *       client API context or not). This includes any mandatory OpenGL ES
 *       extensions.
 *
 *     eglGetProcAddress may not be queried for core (non-extension) functions
 *     in EGL or client APIs 20 .
 *
 *     For functions that are queryable with eglGetProcAddress,
 *     implementations may choose to also export those functions statically
 *     from the object libraries im- plementing those functions. However,
 *     portable clients cannot rely on this behavior.
 *
 * From the GLX 1.4 spec:
 *
 *     "glXGetProcAddress may be queried for all of the following functions:
 *
 *      • All GL and GLX extension functions supported by the implementation
 *        (whether those extensions are supported by the current context or
 *        not).
 *
 *      • All core (non-extension) functions in GL and GLX from version 1.0 up
 *        to and including the versions of those specifications supported by
 *        the implementation, as determined by glGetString(GL VERSION) and
 *        glXQueryVersion queries."
 */

#include <assert.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#include <err.h>
#include <pthread.h>
#endif
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "dispatch_common.h"

#if defined(_WIN32)
static const char *WGL_NAME = "opengl32.dll";
#else
static const char *WGL_NAME = NULL;
#endif

#if defined(__APPLE__)
static const char *CGL_NAME = "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL";
#else
static const char *CGL_NAME = NULL;
#endif

#if defined(__APPLE__)
static const char *GLX_NAME = "/opt/X11/lib/libGL.1.dylib";
#elif defined(ANDROID)
static const char *GLX_NAME = "libGLESv2.so";
#elif defined(_WIN32)
static const char *GLX_NAME = NULL;
#else
static const char *GLX_NAME = "libGL.so.1";
#endif

#if defined(ANDROID)
const struct glproxy_gles_names GLES_NAMES = { "libEGL.so" , "libGLESv1_CM.so", "libGLESv2.so" };
#elif defined(_WIN32)
const struct glproxy_gles_names GLES_NAMES = { "libEGL.dll", "libGLESv1_CM.dll", "libGLESv2.dll" };
#else
const struct glproxy_gles_names GLES_NAMES =  { "libEGL.so.1", "libGLESv1_CM.so.1", "libGLESv2.1" };
#endif

static inline void *dlopen_handle(const char *lib_name, const char** error) {
    void *handle = NULL;
    if (!lib_name) {
        return NULL;
    }
#ifdef _WIN32
    handle = (void *)LoadLibraryA(lib_name);
#else
    handle = (void *)dlopen(lib_name, RTLD_LAZY | RTLD_LOCAL);
    if (!handle) {
        if (error) {
            *error = dlerror();
        } else {
            (void)dlerror();
        }
    }
#endif
    return handle;
}

static inline void dlclose_handle(void* handle) {
#ifdef _WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
}

void try_close_handle(void** handle) {
    if (*handle) {
        dlclose_handle(*handle);
        *handle = NULL;
    }
}

static void *do_dlsym_by_handle(void*handle, const char* name, const char**error, bool show_error) {
    void *result = NULL;
#ifdef _WIN32
    result = GetProcAddress(handle, name);
#else
    result = dlsym(handle, name);
    if (!result) {
        if (error) {
            *error = dlerror();
        } else {
            (void)dlerror();
        }
    }
#endif
    if (show_error && result == NULL) {
        if (!*error) {
            *error = "unknow";
        }
        fprintf(stderr, "%s() not found in 0x%x %s\n", name, (intptr_t)handle, *error);
    }
    return result;
}

static int glproxy_internal_gl_version(const char *version, int error_version) {
    GLint major, minor;
    int scanf_count;

    if (!version)
        return error_version;

    /* skip to version number */
    while (!isdigit(*version) && *version != '\0')
        version++;

    /* Interpret version number */
    scanf_count = sscanf(version, "%i.%i", &major, &minor);
    if (scanf_count != 2) {
        fprintf(stderr, "Unable to interpret GL_VERSION string: %s\n",
            version);
        exit(1);
    }
    return 10 * major + minor;
}

static EGLenum glproxy_egl_get_current_context_type_by_handle(void* handle) {
    const char *error = "unknow";
    PFNEGLQUERYAPIPROC eglQueryAPILocal = do_dlsym_by_handle(handle, "eglQueryAPI", &error, true);
    PFNEGLGETCURRENTCONTEXTPROC eglGetCurrentContextLocal = do_dlsym_by_handle(handle, "eglGetCurrentContext", &error, true);
    PFNEGLBINDAPIPROC eglBindAPILocal = do_dlsym_by_handle(handle, "eglBindAPI", &error, true);
    PFNEGLGETERRORPROC eglGetErrorLocal = do_dlsym_by_handle(handle, "eglGetError", &error, true);
    if (!eglQueryAPILocal) {
        return EGL_NONE;
    }

    EGLenum save_api = eglQueryAPILocal();
    EGLContext ctx;

    if (eglBindAPILocal(EGL_OPENGL_API)) {
        ctx = eglGetCurrentContextLocal();
        if (ctx) {
            eglBindAPILocal(save_api);
            return EGL_OPENGL_API;
        }
    } else {
        (void)eglGetErrorLocal();
    }

    if (eglBindAPILocal(EGL_OPENGL_ES_API)) {
        ctx = eglGetCurrentContextLocal();
        eglBindAPILocal(save_api);
        if (ctx) {
            eglBindAPILocal(save_api);
            return EGL_OPENGL_ES_API;
        }
    } else {
        (void)eglGetErrorLocal();
    }

    return EGL_NONE;
}

bool glproxy_extension_in_string(const char *extension_list, const char *ext) {
    const char *ptr = extension_list;
    size_t len = strlen(ext);

    /* Make sure that don't just find an extension with our name as a prefix. */
    while (true) {
        ptr = strstr(ptr, ext);
        if (!ptr)
            return false;

        if (ptr[len] == ' ' || ptr[len] == 0)
            return true;
        ptr += len;
    }
}

static bool glproxy_internal_has_gl_extension(const char *ext, bool invalid_op_mode) {
    if (glproxy_gl_version() < 30) {
        const char *exts = (const char *)glGetString(GL_EXTENSIONS);
        if (!exts)
            return invalid_op_mode;
        return glproxy_extension_in_string(exts, ext);
    } else {
        int num_extensions;
        int i;

        glGetIntegerv(GL_NUM_EXTENSIONS, &num_extensions);
        if (num_extensions == 0)
            return invalid_op_mode;

        for (i = 0; i < num_extensions; i++) {
            const char *gl_ext = (const char *)glGetStringi(GL_EXTENSIONS, i);
            if (strcmp(ext, gl_ext) == 0)
                return true;
        }

        return false;
    }
}

// APIs required by resolvers


#if PLATFORM_HAS_WGL

glproxy_IMPORTEXPORT bool glproxy_has_wgl_extension(HDC hdc, const char *ext) {
    PFNWGLGETEXTENSIONSSTRINGARBPROC getext;

    getext = (void *)wglGetProcAddress("wglGetExtensionsStringARB");
    if (!getext) {
        fprintf(stderr,
            "Implementation unexpectedly missing "
            "WGL_ARB_extensions_string.  Probably a libglproxy bug.\n");
        return false;
    }

    return glproxy_extension_in_string(getext(hdc), ext);
}

/**
* If we can determine the WGL extension support from the current
* context, then return that, otherwise give the answer that will just
* send us on to get_proc_address().
*/
bool glproxy_conservative_has_wgl_extension(const char *ext)
{
    tls_ptr tls = glproxy_context_get();
    HDC hdc = wglGetCurrentDC();

    if (!hdc)
        return true;

    return glproxy_has_wgl_extension(hdc, ext);
}

#endif /* PLATFORM_HAS_WGL */

#if PLATFORM_HAS_GLX
/**
* If we can determine the GLX version from the current context, then
* return that, otherwise return a version that will just send us on
* to dlsym() or get_proc_address().
*/
int glproxy_conservative_glx_version(void) {
    Display *dpy = glXGetCurrentDisplay();
    GLXContext ctx = glXGetCurrentContext();
    int screen;

    if (!dpy || !ctx)
        return 14;

    glXQueryContext(dpy, ctx, GLX_SCREEN, &screen);

    return glproxy_glx_version(dpy, screen);
}

glproxy_IMPORTEXPORT int glproxy_glx_version(Display *dpy, int screen) {
    int server_major, server_minor;
    int client_major, client_minor;
    int server, client;
    const char *version_string;
    int ret = 0, sscanf_ret;

    if ((version_string = glXQueryServerString(dpy, screen, GLX_VERSION)))
    {
        sscanf_ret = sscanf(version_string, "%d.%d", &server_major, &server_minor);
        assert(sscanf_ret == 2);
        server = server_major * 10 + server_minor;
        if ((version_string = glXGetClientString(dpy, GLX_VERSION)))
        {
            sscanf_ret = sscanf(version_string, "%d.%d", &client_major, &client_minor);
            assert(sscanf_ret == 2);
            client = client_major * 10 + client_minor;
            ret = client <= server ? client : server;
        }
    }

    return ret;
}

/**
* If we can determine the GLX extension support from the current
* context, then return that, otherwise give the answer that will just
* send us on to get_proc_address().
*/
bool glproxy_conservative_has_glx_extension(const char *ext) {
    Display *dpy = glXGetCurrentDisplay();
    GLXContext ctx = glXGetCurrentContext();
    int screen;

    if (!dpy || !ctx)
        return true;

    glXQueryContext(dpy, ctx, GLX_SCREEN, &screen);

    return glproxy_has_glx_extension(dpy, screen, ext);
}

glproxy_IMPORTEXPORT bool glproxy_has_glx_extension(Display *dpy, int screen, const char *ext) {
    /* No, you can't just use glXGetClientString or
    * glXGetServerString() here.  Those each tell you about one half
    * of what's needed for an extension to be supported, and
    * glXQueryExtensionsString() is what gives you the intersection
    * of the two.
    */
    return glproxy_extension_in_string(glXQueryExtensionsString(dpy, screen), ext);
}

#endif /* PLATFORM_HAS_GLX */

glproxy_IMPORTEXPORT int glproxy_egl_version(EGLDisplay dpy) {
    int major, minor;
    const char *version_string;
    int ret;

    version_string = eglQueryString(dpy, EGL_VERSION);
    ret = sscanf(version_string, "%d.%d", &major, &minor);
    assert(ret == 2);
    return major * 10 + minor;
}

int glproxy_conservative_egl_version(void) {
    EGLDisplay dpy = eglGetCurrentDisplay();

    if (!dpy)
        return 14;

    return glproxy_egl_version(dpy);
}

glproxy_IMPORTEXPORT bool glproxy_has_egl_extension(EGLDisplay dpy, const char *ext)
{
    return glproxy_extension_in_string(eglQueryString(dpy, EGL_EXTENSIONS), ext);
}

bool glproxy_conservative_has_egl_extension(const char *ext)
{
    EGLDisplay dpy = eglGetCurrentDisplay();

    if (!dpy)
        return true;

    return glproxy_has_egl_extension(dpy, ext);
}


glproxy_IMPORTEXPORT bool glproxy_has_gl_extension(const char *ext) {
    return glproxy_internal_has_gl_extension(ext, false);
}

static bool inited = false;
/* The context for main thread */
static tls_ptr global_context = NULL;
/* thread local storage index */
TLS_TYPE glproxy_dispatch_common_tls_index = 0;

glproxy_IMPORTEXPORT void glproxy_init_tls(void) {
    if (inited) {
        return;
    }
#if defined(_WIN32)
    glproxy_dispatch_common_tls_index = TlsAlloc();
#else
    pthread_key_create(&glproxy_dispatch_common_tls_index, NULL);
#endif
    global_context = glproxy_context_create(NULL);
    inited = true;
    glproxy_context_set(global_context);
}
CONSTRUCT(glproxy_init_tls)

glproxy_IMPORTEXPORT void glproxy_uninit_tls(void) {
    if (!inited) {
        return;
    }
    if (!global_context) {
        fprintf(stderr, "Should calling to glproxy_uninit_tls to destroy glproxy global context.\n");
    }
    glproxy_context_destroy(global_context);
    global_context = NULL;
#if defined(_WIN32)
    TlsFree(glproxy_dispatch_common_tls_index);
#else
    pthread_key_delete(glproxy_dispatch_common_tls_index);
#endif
    glproxy_dispatch_common_tls_index = 0;
    inited = false;
}
DESTRUCT(glproxy_uninit_tls)

static void glproxy_context_handles_open(tls_ptr tls) {
    tls->context.handles.cgl = dlopen_handle(tls->context.cgl_name, NULL);
    tls->context.handles.wgl = dlopen_handle(tls->context.wgl_name, NULL);
    tls->context.handles.glx = dlopen_handle(tls->context.glx_name, NULL);
    tls->context.handles.egl = dlopen_handle(tls->context.gles_names.egl, NULL);
    tls->context.handles.gles1 = dlopen_handle(tls->context.gles_names.gles1, NULL);
    tls->context.handles.gles2 = dlopen_handle(tls->context.gles_names.gles2, NULL);
}

static void glproxy_context_handles_close(tls_ptr tls) {
    void** handles = (void**)&tls->context.handles;
    void** param_handles = (void**)&tls->param_context.handles;
    size_t count = sizeof(tls->context.handles) / sizeof(void*);
    size_t i = 0;
    for (; i < count; ++i) {
        if (handles[i] != param_handles[i] && handles[i]) {
            dlclose_handle(handles[i]);
        }
    }
}

glproxy_IMPORTEXPORT void* glproxy_context_create(struct glproxy_gl_context *params) {
    tls_ptr tls = (tls_ptr)malloc(sizeof(tls[0]));
    memset(tls, 0, sizeof(tls[0]));
    if (params != NULL) {
        tls->has_parameters = true;
        memcpy((void*)&tls->param_context, (void*)params, sizeof(params[0]));
        memcpy((void*)&tls->context, (void*)params, sizeof(params[0]));
    } else {
        tls->context.cgl_name = CGL_NAME;
        tls->context.wgl_name = WGL_NAME;
        tls->context.glx_name = GLX_NAME;
        tls->context.gles_names = GLES_NAMES;
    }
    glproxy_context_handles_open(tls);
    glproxy_dispatch_common_tls_init(tls, inited);
    return tls;
}

glproxy_IMPORTEXPORT void* glproxy_context_get() {
    return (void*)get_tls_by_index(glproxy_dispatch_common_tls_index);
}

glproxy_IMPORTEXPORT void glproxy_context_set(void* new_context) {
    if (!inited) {
        fprintf(stderr, "The glproxy are not inited yet");
        return;
    }
    set_tls_by_index(glproxy_dispatch_common_tls_index, new_context);
}

glproxy_IMPORTEXPORT void glproxy_context_destroy(void* context) {
    tls_ptr tls = context;
    tls_ptr exist_context = NULL;
    if (!inited) {
        fprintf(stderr, "The glproxy are not inited yet");
        return;
    }
    if (!tls) {
        fprintf(stderr, "The glproxy context are NULL");
        return;
    }
    exist_context = glproxy_context_get();
    if (exist_context == tls) {
        glproxy_context_set(0);
    }

    glproxy_context_handles_close(tls);
    free(tls);
}

static void* find_function_pointer_pos(void** table_start, const struct dispatch_metadata *metadata, const char*expected) {
    for (size_t i = 0; i < metadata->method_count; ++i) {
        const char* current_name = metadata->entrypoint_strings + metadata->method_name_offsets[i];
        if (strcmp(current_name, expected) == 0) {
            return table_start + i;
        }
    }
    return 0;
}

glproxy_IMPORTEXPORT void** glproxy_context_get_function_pointer(const char* target, const char* membername) {
    tls_ptr tls = glproxy_context_get();
#if PLATFORM_HAS_WGL
    if (strcmp(target, "wgl") == 0) {
        return find_function_pointer_pos((void**)&tls->wgl_dispatch_table, &tls->wgl_metadata, membername);
    }
#endif
#if PLATFORM_HAS_GLX
    if (strcmp(target, "glx") == 0) {
        return find_function_pointer_pos((void**)&tls->glx_dispatch_table, &tls->glx_metadata, membername);
    }
#endif
    if (strcmp(target, "gl") == 0) {
        return find_function_pointer_pos((void**)&tls->gl_dispatch_table, &tls->gl_metadata, membername);
    }
    if (strcmp(target, "egl") == 0) {
        return find_function_pointer_pos((void**)&tls->egl_dispatch_table, &tls->egl_metadata, membername);
    }
    return NULL;
}

glproxy_IMPORTEXPORT bool glproxy_is_desktop_gl(void) {
    tls_ptr tls = glproxy_context_get();
    if (tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        gl_glproxy_resolve_init(tls);
    }
    return tls->open_gl_type != DISPATCH_OPENGL_ES;
}

glproxy_IMPORTEXPORT int glproxy_gl_version(void) {
    tls_ptr tls = glproxy_context_get();
    if (tls->open_gl_type == DISPATCH_OPENGL_UNKNOW || tls->gl_version == 0) {
        gl_glproxy_resolve_init(tls);
    }
    return tls->gl_version;
}

void cgl_glproxy_resolve_init(tls_ptr tls) {
#if PLATFORM_HAS_CGL
#error Implement it for apple cgl
#endif
}

void wgl_glproxy_resolve_init(tls_ptr tls) {
#if PLATFORM_HAS_WGL
    tls->wgl_metadata.inited = true;
    if (tls->gl_called && tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        PFNWGLGETCURRENTCONTEXTPROC sym = do_dlsym_by_handle(tls->context.handles.wgl, "wglGetCurrentContext", NULL, false);
        if (sym && sym()) {
            tls->gl_handle = tls->context.handles.wgl;
            tls->open_gl_type = DISPATCH_OPENGL_WGL_DESKTOP;
        }
    }
    tls->wgl_get_proc = do_dlsym_by_handle(tls->context.handles.wgl, "wglGetProcAddress", NULL, false);
#endif
}

enum DISPATCH_RESOLVE_RESULT wgl_glproxy_resolve_direct(tls_ptr tls, const char* name, void**ptr) {
    *ptr = do_dlsym_by_handle(tls->context.handles.wgl, name, NULL, false);
    return DISPATCH_RESOLVE_RESULT_OK;
}

enum DISPATCH_RESOLVE_RESULT wgl_glproxy_resolve_extension(tls_ptr tls, const char* name, void**ptr, const char *extension) {
#if PLATFORM_HAS_WGL
    if (glproxy_conservative_has_wgl_extension(extension)) {
        *ptr = tls->wgl_get_proc(name);
        return DISPATCH_RESOLVE_RESULT_OK;
    }
#endif
    return DISPATCH_RESOLVE_RESULT_IGNORE;
}

void glx_glproxy_resolve_init(tls_ptr tls) {
#if PLATFORM_HAS_GLX
    if (!tls->gl_called) {
        if (!tls->glx_metadata.inited) {
            if (!tls->has_parameters) {
                /* If nothing in glx, then close it and using in memory version*/
                void* sym = do_dlsym_by_handle(tls->context.handles.glx, "glXGetCurrentContext", NULL, false);
                if (!sym) {
                    try_close_handle(&(tls->context.handles.glx));
                }
            }
        }
    }
    if (tls->gl_called && tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        PFNGLXGETCURRENTCONTEXTPROC sym = do_dlsym_by_handle(tls->context.handles.glx, "glXGetCurrentContext", NULL, false);
        if (sym && sym()) {
            tls->gl_handle = tls->context.handles.glx;
            tls->open_gl_type = DISPATCH_OPENGL_GLX_DESKTOP;
        } else if (!tls->has_parameters && tls->context.handles.glx) {
            PFNGLXGETCURRENTCONTEXTPROC sym = do_dlsym_by_handle(NULL, "glXGetCurrentContext", NULL, false);
            if (sym && sym()) {
                /* TODO: Test it*/
                try_close_handle(&(tls->context.handles.glx));
                tls->open_gl_type = DISPATCH_OPENGL_GLX_DESKTOP;
                tls->gl_handle = NULL;
            }
        }
    }
    tls->glx_metadata.inited = true;
#endif /* PLATFORM_HAS_GLX */
}

enum DISPATCH_RESOLVE_RESULT glx_glproxy_resolve_direct(tls_ptr tls, const char* name, void**ptr) {
    *ptr = do_dlsym_by_handle(tls->context.handles.glx, name, NULL, false);
    return DISPATCH_RESOLVE_RESULT_OK;
}

enum DISPATCH_RESOLVE_RESULT glx_glproxy_resolve_extension(tls_ptr tls, const char* name, void**ptr, const char *extension) {
#if PLATFORM_HAS_GLX
    if (glproxy_conservative_has_glx_extension(tls, extension)) {
        *ptr = glXGetProcAddress((const GLubyte *)name);
        return DISPATCH_RESOLVE_RESULT_OK;
    }
#endif
    return DISPATCH_RESOLVE_RESULT_IGNORE;
}

void gl_glproxy_resolve_init(tls_ptr tls) {
    tls->gl_called = true;
    if (tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        cgl_glproxy_resolve_init(tls);
        wgl_glproxy_resolve_init(tls);
        glx_glproxy_resolve_init(tls);
        egl_glproxy_resolve_init(tls);
    }
    if (tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        fprintf(stderr, "Did not found the current context\n");
    } else if (tls->gl_version == 0){
        PFNGLGETSTRINGPROC get_string = NULL;
        gl_glproxy_resolve_direct(tls, "glGetString", (void**)&get_string);
        if (!get_string) {
            fprintf(stderr, "Can not resolve glGetString even though we have already found the current context\n");
        } else {
            tls->gl_version = glproxy_internal_gl_version(get_string(GL_VERSION), 0);
        }
    } else {
        tls->gl_metadata.inited = true;
    }
}

enum DISPATCH_RESOLVE_RESULT gl_glproxy_resolve_direct(tls_ptr tls, const char* name, void**ptr) {
    switch (tls->open_gl_type) {
    case DISPATCH_OPENGL_ES:
        *ptr = do_dlsym_by_handle(tls->gles_handle, name, NULL, false);
        break;
    default:
        *ptr = do_dlsym_by_handle(tls->gl_handle, name, NULL, false);
        break;
    }

    return DISPATCH_RESOLVE_RESULT_OK;
}

static void glproxy_get_proc_address(tls_ptr tls, const char *name, void**ptr) {
    switch (tls->open_gl_type) {
    case DISPATCH_OPENGL_EGL_DESKTOP:
    case DISPATCH_OPENGL_ES:
        *ptr = eglGetProcAddress(name);
        break;
    case DISPATCH_OPENGL_WGL_DESKTOP:
#if PLATFORM_HAS_WGL
        *ptr = wglGetProcAddress(name);
#endif
        break;
    case DISPATCH_OPENGL_GLX_DESKTOP:
#if PLATFORM_HAS_GLX
        *ptr = glXGetProcAddressARB((const GLubyte *)name);
#endif
        break;
    case DISPATCH_OPENGL_CGL_DESKTOP:
#if PLATFORM_HAS_CGL
#error TODO: Implement this
        *ptr = cglGetProcAddressARB？((const GLubyte *)name);
#endif
        break;
    default:
        fprintf(stderr, "Invaid openg type:%d", tls->open_gl_type);
        break;
    }
}


/**
* Performs either the dlsym or glXGetProcAddress()-equivalent for
* core functions in desktop GL.
*/
static void glproxy_get_core_proc_address(tls_ptr tls, const char *name, int core_version, void **ptr) {
#ifdef _WIN32
    int core_symbol_support = 11;
#elif defined(ANDROID)
    /**
    * All symbols must be resolved through eglGetProcAddress
    * on Android
    */
    int core_symbol_support = 0;
#else
    int core_symbol_support = 12;
#endif

    if (core_version <= core_symbol_support) {
        gl_glproxy_resolve_direct(tls, name, ptr);
    } else {
        glproxy_get_proc_address(tls, name, ptr);
    }
}
enum DISPATCH_RESOLVE_RESULT gl_glproxy_resolve_version(tls_ptr tls, const char* name, void**ptr, khronos_uint16_t version) {
    if (version <= OpenGL_Desktop_MAX) {
        if (tls->open_gl_type != DISPATCH_OPENGL_ES) {
            if (tls->gl_version == 0 ||  tls->gl_version >= version) {
                glproxy_get_core_proc_address(tls, name, version, ptr);
                return DISPATCH_RESOLVE_RESULT_OK;
            }
        }
        return DISPATCH_RESOLVE_RESULT_IGNORE;
    } else { /* OpenGL ES version*/
        version = version - OpenGL_ES_MIN;
    }
    return DISPATCH_RESOLVE_RESULT_IGNORE;
}

enum DISPATCH_RESOLVE_RESULT gl_glproxy_resolve_extension(tls_ptr tls, const char* name, void**ptr, const char *extension) {
    if (glproxy_internal_has_gl_extension(extension, true)) {
        return DISPATCH_RESOLVE_RESULT_OK;
    }
    return DISPATCH_RESOLVE_RESULT_IGNORE;
}

static const char* glproxy_get_string_by_handle(void*handle) {
    PFNGLGETSTRINGPROC get_string = do_dlsym_by_handle(handle, "glGetString", NULL, false);
    if (get_string) {
        return get_string(GL_VERSION);
    }
    return NULL;
}

void egl_glproxy_resolve_init(tls_ptr tls) {
	if (!tls->gl_called) {
        if (!tls->egl_metadata.inited) {
            if (!tls->has_parameters) {
                /* If nothing in egl, then close it and using in memory version*/
                void* sym = do_dlsym_by_handle(tls->context.handles.egl, "eglGetProcAddress", NULL, false);
                if (!sym) {
                    try_close_handle(&(tls->context.handles.egl));
                }
            }
        }
    } else if (tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        EGLenum egl_context_api = glproxy_egl_get_current_context_type_by_handle(tls->context.handles.egl);
        /* If has parameter, then using the paramter directly, do not try the NULL */
        if (egl_context_api == EGL_NONE && !tls->has_parameters && tls->context.handles.egl) {
            /* Try NULL */
            egl_context_api = glproxy_egl_get_current_context_type_by_handle(NULL);
            /* If NULL works, then setting tls->context.handles.egl to NULL */
            if (egl_context_api != EGL_NONE) {
                try_close_handle(&(tls->context.handles.egl));
            }
        }
        if (egl_context_api != EGL_NONE) {
            if (!tls->has_parameters) {
                if (tls->context.handles.gles2 && glproxy_get_string_by_handle(tls->context.handles.gles2)) {
                    try_close_handle(&(tls->context.handles.gles1));
                } else if (tls->context.handles.gles1 && glproxy_get_string_by_handle(tls->context.handles.gles1)) {
                    try_close_handle(&(tls->context.handles.gles2));
                } else if (glproxy_get_string_by_handle(NULL)) {
                    /* Means the gles1 & gles2 handle are NULL */
                    try_close_handle(&(tls->context.handles.gles1));
                    try_close_handle(&(tls->context.handles.gles2));
                } else {
                    fprintf(stderr, "Something is wrong, may be between glBegin, glEnd, anyway, ignore it\n");
                }
            }
            if (tls->context.handles.gles2) {
                tls->gles_handle = tls->context.handles.gles2;
            } else {
                tls->gles_handle = tls->context.handles.gles1;
            }
            switch (egl_context_api) {
            case EGL_OPENGL_API:
                tls->gl_handle = tls->gles_handle;
                tls->gles_handle = NULL;
                tls->open_gl_type = DISPATCH_OPENGL_EGL_DESKTOP;
                break;
            case EGL_OPENGL_ES_API:
                tls->open_gl_type = DISPATCH_OPENGL_ES;
                break;
            }
        } /* Otherwise, doesn't found the opgnel context with egl */
    }
    tls->egl_get_proc = do_dlsym_by_handle(tls->context.handles.egl, "eglGetProcAddress", NULL, false);
    tls->egl_metadata.inited = true;
}

enum DISPATCH_RESOLVE_RESULT egl_glproxy_resolve_direct(tls_ptr tls, const char* name, void**ptr) {
    *ptr = do_dlsym_by_handle(tls->context.handles.egl, name, NULL, false);
    return DISPATCH_RESOLVE_RESULT_OK;
}

enum DISPATCH_RESOLVE_RESULT egl_glproxy_resolve_version(tls_ptr tls, const char* name, void**ptr, khronos_uint16_t version) {
    if (glproxy_conservative_egl_version() >= version) {
        *ptr = do_dlsym_by_handle(tls->context.handles.egl, name, NULL, false);
        return DISPATCH_RESOLVE_RESULT_OK;
    }
    return DISPATCH_RESOLVE_RESULT_IGNORE;
}

enum DISPATCH_RESOLVE_RESULT egl_glproxy_resolve_extension(tls_ptr tls, const char* name, void**ptr, const char *extension) {
    if (glproxy_conservative_has_egl_extension(extension)) {
        *ptr = tls->egl_get_proc(name);
    }
    return DISPATCH_RESOLVE_RESULT_IGNORE;
}
