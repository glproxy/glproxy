/*
 * Copyright © 2014 Intel Corporation
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
 * @file egl_without_glx.c
 *
 * Tries to test operation of the library on a GL stack with EGL and
 * GLES but no GLX or desktop GL (such as Arm's Mali GLES3 drivers).
 * This test is varied by the GLES_VERSION defined at compile time to
 * test either a GLES1-only or a GLES2-only system.
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "glproxy/gl.h"
#include "glproxy/egl.h"

#include "egl_common.h"

#ifndef _WIN32
#include <dlfcn.h>
#endif

static EGLenum last_api;
static EGLenum extra_error = EGL_SUCCESS;

#ifdef _WIN32
void* loadAPI(const char* name) {
    void *egl = LoadLibraryA("libEGL.dll");
    return GetProcAddress(egl, name);
}
#else
void* loadAPI(const char* name) {
    void *egl = dlopen("libEGL.so.1", RTLD_LAZY | RTLD_LOCAL);
    return dlsym(egl, name);
}
#endif
/**
* Override of the real libEGL's eglBindAPI to simulate the target
* system's eglBindAPI.
*/
static EGLBoolean GLAPIENTRY
override_eglBindAPI(EGLenum api)
{
    PFNEGLBINDAPIPROC real_eglBindAPI = loadAPI("eglBindAPI");

    last_api = api;

    if (api == EGL_OPENGL_API) {
        extra_error = EGL_BAD_PARAMETER;
        return EGL_FALSE;
    }

    assert(real_eglBindAPI);
    return real_eglBindAPI(api);
}

/**
* Override of the real libEGL's eglGetError() to feed back the error
* that might have been generated by override_eglBindAPI().
*/
static EGLint GLAPIENTRY
override_eglGetError(void)
{
    PFNEGLGETERRORPROC real_eglGetError = loadAPI("eglGetError");

    if (extra_error != EGL_SUCCESS) {
        EGLenum error = extra_error;
        extra_error = EGL_SUCCESS;
        return error;
    }

    assert(real_eglGetError);
    return real_eglGetError();
}

int main(void)
{
    bool pass = true;
    void* nativeWindow = NULL;
    int mRedBits = -1;
    int mGreenBits = -1;
    int mBlueBits = -1;
    int mAlphaBits = -1;
    int mDepthBits = -1;
    int mStencilBits = -1;
    bool mMultisample = false;
    EGLint configCount;
    EGLDisplay dpy = get_egl_display_or_skip(&nativeWindow);
    const char *displayExtensions = eglQueryString(dpy, EGL_EXTENSIONS);

    EGLint surfaceAttributes[128];
    int attributesCount = 0;
    const EGLint configAttributes[] =
    {
        EGL_RED_SIZE,       (mRedBits >= 0) ? mRedBits : EGL_DONT_CARE,
        EGL_GREEN_SIZE,     (mGreenBits >= 0) ? mGreenBits : EGL_DONT_CARE,
        EGL_BLUE_SIZE,      (mBlueBits >= 0) ? mBlueBits : EGL_DONT_CARE,
        EGL_ALPHA_SIZE,     (mAlphaBits >= 0) ? mAlphaBits : EGL_DONT_CARE,
        EGL_DEPTH_SIZE,     (mDepthBits >= 0) ? mDepthBits : EGL_DONT_CARE,
        EGL_STENCIL_SIZE,   (mStencilBits >= 0) ? mStencilBits : EGL_DONT_CARE,
        EGL_SAMPLE_BUFFERS, mMultisample ? 1 : 0,
        EGL_NONE
    };
    EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, GLES_VERSION,
        EGL_NONE
    };
    EGLConfig cfg;
    EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 1,
        EGL_GREEN_SIZE, 1,
        EGL_BLUE_SIZE, 1,
#if GLES_VERSION == 2
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
#else
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
#endif
        EGL_NONE
    };
    EGLint count;
    EGLContext ctx;
    const unsigned char *string;

    *glproxy_context_get_function_pointer("egl", "eglBindAPI") = override_eglBindAPI;
    *glproxy_context_get_function_pointer("egl", "eglGetError") = override_eglGetError;

    if (!glproxy_has_egl_extension(dpy, "EGL_KHR_surfaceless_context"))
        fprintf(stderr, "Test requires EGL_KHR_surfaceless_context\n");

    eglBindAPI(EGL_OPENGL_ES_API);

    if (!eglChooseConfig(dpy, config_attribs, &cfg, 1, &count))
        fprintf(stderr, "Couldn't get an EGLConfig\n");

    if (!eglChooseConfig(dpy, configAttributes, &cfg, 1, &configCount) || (configCount != 1))
    {
        return false;
    }

    if (strstr(displayExtensions, "EGL_NV_post_sub_buffer") != NULL) {
        surfaceAttributes[attributesCount++] = EGL_POST_SUB_BUFFER_SUPPORTED_NV;
        surfaceAttributes[attributesCount++] = EGL_TRUE;
    }
    surfaceAttributes[attributesCount++] = EGL_NONE;
    EGLSurface surface = eglCreateWindowSurface(dpy, cfg, nativeWindow, &surfaceAttributes[0]);
    ctx = eglCreateContext(dpy, cfg, NULL, context_attribs);
    if (!ctx)
        fprintf(stderr, "Couldn't create a GLES%d context\n", GLES_VERSION);

    eglMakeCurrent(dpy, surface, surface, ctx);

    string = glGetString(GL_VERSION);
    printf("GL_VERSION: %s\n", string);

    assert(eglGetError() == EGL_SUCCESS);

    return pass != true;
}
