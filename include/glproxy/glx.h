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

/** @file glx.h
 *
 * Provides an implementation of a GLX dispatch layer using global
 * function pointers.
 */

#ifndef GLPROXY_GLX_H
#define GLPROXY_GLX_H

#if defined(GLX_H) || defined(__glx_h__) || defined(__glxext_h_)
#error "glproxy/glx.h" must be included before (or in place of) "GL/glx.h".
#endif

#define GLX_H
#define __glx_h__
#define __glxext_h_

#include "glproxy/gl.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "glproxy/glx_generated.h"

GLPROXY_IMPORTEXPORT bool glproxy_has_glx_extension(Display *dpy, int screen, const char *extension);
GLPROXY_IMPORTEXPORT int glproxy_glx_version(Display *dpy, int screen);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GLPROXY_GLX_H */
