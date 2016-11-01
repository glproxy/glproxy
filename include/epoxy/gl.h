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

/** @file gl.h
 *
 * Provides an implementation of a GL dispatch layer using either
 * global function pointers or a hidden vtable.
 */

#ifndef EPOXY_GL_H
#define EPOXY_GL_H

#if    defined(__glplatform_h_)  || defined(__gl_h_)  || defined(__glext_h_)  \
    || defined(__gl2platform_h_) || defined(__gl2_h_) || defined(__gl2ext_h_) \
    || defined(__gl3platform_h_) || defined(__gl3_h_) || defined(__gl31_h_)

#error "epoxy/gl.h" must be included before (or in place of) the desktop OpenGL / OpenGL ES headers.
#endif

#define __glplatform_h_
#define __gl_h_
#define __glext_h_
#define __gl2platform_h_
#define __gl2_h_ 1
#define __gl2ext_h_ 1
#define __gl3platform_h_
#define __gl3_h_ 1
#define __gl31_h_ 1

#include "epoxy/_common.h"
#include "epoxy/khrplatform.h"
#ifdef _WIN32
#   include <Windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER) && _MSC_VER < 1900
#ifndef __cplusplus
#ifndef bool
typedef khronos_boolean_enum_t bool;
#endif
#ifndef true
#define true KHRONOS_TRUE
#endif
#ifndef false
#define false KHRONOS_FALSE
#endif
#endif
#else
#include <stdbool.h>
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY KHRONOS_APIENTRY
#endif

#ifndef APIENTRY
#define APIENTRY GLAPIENTRY
#endif

#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifndef GLAPIENTRYP
#define GLAPIENTRYP GLAPIENTRY *
#endif

#define EPOXY_CALLSPEC KHRONOS_APIENTRY

#if (defined(__GNUC__) && __GNUC__ >= 4) || (defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590))
#   define GLAPI __attribute__((visibility("default")))
#else
#   define GLAPI extern
#endif

#include "epoxy/gl_generated.h"

struct epoxy_gles_names {
    const char* egl;
    const char* gles1;
    const char* gles2;
};

struct epoxy_gl_handles {
    /**
    * dlopen() return value for OS X's GL library.
    */
    void *cgl;

    /* LoadLibraryA return value for opengl32.dll */
    void *wgl;

    /** dlopen() return value for libGL.so.1. in other works, glx */
    void *glx;

    /** dlopen() return value for libEGL.so.1 */
    void *egl;
    /** dlopen() return value for libGLESv1_CM.so.1 */
    void *gles1;
    /** dlopen() return value for libGLESv2.so.2 */
    void *gles2;
};

struct epoxy_gl_context {
    const char *cgl_name;
    const char *wgl_name;
    const char *glx_name;
    struct epoxy_gles_names gles_names;
    struct epoxy_gl_handles handles;
};

/*
* By default, the TLS are inited by global constructor and destructor, if the compiler doesn't support that,
then calling to the following API to do that.
*/
EPOXY_IMPORTEXPORT void epoxy_init_tls(void);
EPOXY_IMPORTEXPORT void epoxy_uninit_tls(void);

EPOXY_IMPORTEXPORT void* epoxy_context_create(struct epoxy_gl_context *params);
EPOXY_IMPORTEXPORT void* epoxy_context_get();
EPOXY_IMPORTEXPORT void epoxy_context_set(void* new_contex);
EPOXY_IMPORTEXPORT void epoxy_context_destroy(void*);

/* target: (wgl, glx, egl, gl) */
EPOXY_IMPORTEXPORT void** epoxy_context_get_function_pointer(const char* target, const char* membername);

/**
* Returns true if the given GL extension is supported in the current context.
*
* Note that this function can't be called from within glBegin()/glEnd().
*
* \sa epoxy_has_wgl_extension()
* \sa epoxy_has_glx_extension()
* \sa epoxy_has_egl_extension()
*/
EPOXY_IMPORTEXPORT bool epoxy_has_gl_extension(const char *extension);
EPOXY_IMPORTEXPORT bool epoxy_is_desktop_gl(void);
EPOXY_IMPORTEXPORT int epoxy_gl_version(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* EPOXY_GL_H */
