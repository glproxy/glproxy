/*
 * Copyright © 2013 Intel Corporation
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
#pragma once
#ifndef _DISPATCH_COMMON_H
#define _DISPATCH_COMMON_H

#define PLATFORM_HAS_GL 1

#ifdef _WIN32
#define PLATFORM_HAS_EGL 1
#define PLATFORM_HAS_GLX 0
#define PLATFORM_HAS_WGL 1
#elif defined(__APPLE__)
#define PLATFORM_HAS_EGL 0
#define PLATFORM_HAS_GLX 1
#define PLATFORM_HAS_WGL 0
#elif defined(ANDROID)
#define PLATFORM_HAS_EGL 1
#define PLATFORM_HAS_GLX 0
#define PLATFORM_HAS_WGL 0
#else
#define PLATFORM_HAS_EGL 1
#define PLATFORM_HAS_GLX 1
#define PLATFORM_HAS_WGL 0
#endif

#if PLATFORM_HAS_WGL
#include "epoxy/wgl.h"
#endif
#if PLATFORM_HAS_GLX
#include "epoxy/glx.h"
#endif
#if PLATFORM_HAS_EGL
#include "epoxy/egl.h"
#endif

#include "epoxy/gl.h"

#include "wgl_generated_dispatch_table_type.inc"
#include "glx_generated_dispatch_table_type.inc"
#include "gl_generated_dispatch_table_type.inc"
#include "egl_generated_dispatch_table_type.inc"

#ifdef __GNUC__
#define CONSTRUCT(_func) static void _func (void) __attribute__((constructor));
#define DESTRUCT(_func) static void _func (void) __attribute__((destructor));
#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
#define CONSTRUCT(_func) \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _wrapper;

#define DESTRUCT(_func) \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#else
#error "You will need constructor support for your compiler"
#endif

#if defined(__GNUC__)
#define PACKED __attribute__((__packed__))
#else
#define PACKED
#endif

#ifdef __GNUC__
#define EPOXY_NOINLINE __attribute__((noinline))
#elif defined (_MSC_VER)
#define EPOXY_NOINLINE __declspec(noinline)
#endif

#define GEN_THUNKS(target, name, args, passthrough, offset, func_type)         \
    EPOXY_IMPORTEXPORT void EPOXY_CALLSPEC                                     \
    name args                                                                  \
    {                                                                          \
        func_type func_symbol = target##_resolve(offset);                      \
        func_symbol passthrough;                                               \
    }

#define GEN_THUNKS_RET(target, ret, name, args, passthrough, offset, func_type)\
    EPOXY_IMPORTEXPORT ret EPOXY_CALLSPEC                                      \
    name args                                                                  \
    {                                                                          \
        func_type func_symbol = target##_resolve(offset);                      \
        return func_symbol passthrough;                                        \
    }

enum DISPATCH_OPENGL_TYPE {
    DISPATCH_OPENGL_UNKNOW = 0,
    DISPATCH_OPENGL_DESKTOP = 1,
    DISPATCH_OPENGL_ES = 2,
    DISPATCH_OPENGL_EGL_DESKTOP = 3,
    DISPATCH_OPENGL_EGL_ES = 4,
} PACKED;

enum DISPATCH_RESOLVE_TYPE {
    DISPATCH_RESOLVE_DIRECT = 0,
    DISPATCH_RESOLVE_VERSION = 1,
    DISPATCH_RESOLVE_EXTENSION = 2,
    DISPATCH_RESOLVE_TERMINATOR = 3,
} PACKED;

struct dispatch_resolve_info {
    khronos_uint8_t resolve_type;
    khronos_uint8_t identity;
    khronos_uint16_t condition;
    khronos_uint32_t name_offset;
};

struct dispatch_common_tls {
#if PLATFORM_HAS_WGL
    struct wgl_dispatch_table wgl_dispatch_table;
#endif

#if PLATFORM_HAS_GLX
    struct glx_dispatch_table glx_dispatch_table;
#endif

    struct gl_dispatch_table gl_dispatch_table;

#if PLATFORM_HAS_EGL
    struct egl_dispatch_table egl_dispatch_table;
#endif

    /* LoadLibraryA return value for opengl32.dll */
    void *wgl_handle;

    /** dlopen() return value for libGL.so.1. */
    void *glx_handle;

    /**
    * dlopen() return value for OS X's GL library.
    *
    * On linux, glx_handle is used instead.
    */
    void *gl_handle;

    /** dlopen() return value for libEGL.so.1 */
    void *egl_handle;
    unsigned int egl_context_api;
    const char *gles1_name;
    const char *gles2_name;

    /** dlopen() return value for libGLESv1_CM.so.1 */
    void *gles1_handle;

    /** dlopen() return value for libGLESv2.so.2 */
    void *gles2_handle;

    enum DISPATCH_OPENGL_TYPE open_gl_type;
};


typedef struct dispatch_common_tls *tls_ptr;
EPOXY_NOINLINE void* wgl_resolve(uint16_t offset);
EPOXY_NOINLINE void* glx_resolve(uint16_t offset);
EPOXY_NOINLINE void* gl_resolve(uint16_t offset);
EPOXY_NOINLINE void* egl_resolve(uint16_t offset);

void reset_dispatch_common_tls(tls_ptr tls);

static inline void *dlopen_handle(const char *lib_name, const char** error) {
    void *handle;
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
    if (!handle) {
        return;
    }
#ifdef _WIN32
    FreeLibrary(handle);
#else
    dlclose(*handle);
#endif
}


#endif /* _DISPATCH_COMMON_H */