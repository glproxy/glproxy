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

/** @file egl.h
 *
 * Provides an implementation of an EGL dispatch layer using global
 * function pointers
 */

#ifndef glproxy_EGL_H
#define glproxy_EGL_H

#if defined(__egl_h_) || defined(__eglext_h_)
#error "glproxy/egl.h" must be included before (or in place of) "EGL/egl.h"
#endif

#define __egl_h_
#define __eglext_h_

#include "glproxy/gl.h"
#include "glproxy/eglplatform.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "glproxy/egl_generated.h"

glproxy_IMPORTEXPORT bool glproxy_has_egl_extension(EGLDisplay dpy, const char *extension);
glproxy_IMPORTEXPORT int glproxy_egl_version(EGLDisplay dpy);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* glproxy_EGL_H */
