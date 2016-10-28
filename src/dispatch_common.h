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

#if defined(EPOXY_IMPORTEXPORT)
#define EPOXY_STATIC_LIB
#undef EPOXY_IMPORTEXPORT
#endif

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

#ifdef __GNUC__
#define CONSTRUCT(_func) static void _func (void) __attribute__((constructor));
#define DESTRUCT(_func) static void _func (void) __attribute__((destructor));
#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
#define CONSTRUCT(_func) \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _wrapper;

#define DESTRUCT(_func) \
  static void _func(void); \
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

#define GEN_REWRITE_PTR(target, table, name, args, passthrough)            \
    static void EPOXY_CALLSPEC                                             \
    name##_dispatch_table_rewrite_ptr args                                 \
    {                                                                      \
        tls_ptr tls = get_dispatch_common_tls();                           \
        tls->table.name = name##_resolver(tls);                            \
        tls->table.name passthrough;                                       \
    }

#define GEN_REWRITE_PTR_RET(target, table, ret, name, args, passthrough)   \
    static ret EPOXY_CALLSPEC                                              \
    name##_dispatch_table_rewrite_ptr args                                 \
    {                                                                      \
        tls_ptr tls = get_dispatch_common_tls();                           \
        tls->table.name = name##_resolver(tls);                            \
        return tls->target##_dispatch_table.name passthrough;              \
    }

#define GEN_THUNK(target, table, name, args, passthrough)                  \
    EPOXY_IMPORTEXPORT void EPOXY_CALLSPEC                                 \
    name args                                                              \
    {                                                                      \
        tls_ptr tls = get_dispatch_common_tls();                           \
        tls->table.name passthrough;                                       \
    }

#define GEN_THUNK_RET(target, table, ret, name, args, passthrough)         \
    EPOXY_IMPORTEXPORT ret EPOXY_CALLSPEC                                  \
    name args                                                              \
    {                                                                      \
        tls_ptr tls = get_dispatch_common_tls();                           \
        return tls->table.name passthrough;                                \
    }

#define GEN_THUNKS(target, name, args, passthrough)                                     \
    GEN_REWRITE_PTR(target, target##_dispatch_table, name, args, passthrough)           \
    GEN_THUNK(target, target##_dispatch_table, name, args, passthrough)

#define GEN_THUNKS_RET(target, ret, name, args, passthrough)                            \
    GEN_REWRITE_PTR_RET(target, target##_dispatch_table, ret, name, args, passthrough)  \
    GEN_THUNK_RET(target, target##_dispatch_table, ret, name, args, passthrough)


#endif /* _DISPATCH_COMMON_H */