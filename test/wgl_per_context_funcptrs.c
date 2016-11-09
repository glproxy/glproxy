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

/**
 * @file wgl_per_context_funcptrs.c
 *
 * Tests that glproxy works correctly when wglGetProcAddress() returns
 * different function pointers for different contexts.
 *
 * wgl allows that to be the case when the device or pixel format are
 * different.  We don't know if the underlying implementation actually
 * *will* return different function pointers, so force the issue by
 * overriding wglGetProcAddress() to return our function pointers with
 * magic behavior.  This way we can test glproxy's implementation
 * regardless.
 */

#include <stdio.h>
#include <assert.h>

#include "wgl_common.h"
#include <glproxy/gl.h>

#define CREATESHADER_CTX1_VAL 1001
#define CREATESHADER_CTX2_VAL 1002

static HGLRC ctx1, ctx2, current_context;
static bool pass = true;

#define OVERRIDE_API(type) __declspec(dllexport) type __stdcall

OVERRIDE_API (GLuint) override_glCreateShader_ctx1(GLenum target);
OVERRIDE_API (GLuint) override_glCreateShader_ctx2(GLenum target);
OVERRIDE_API (PROC) override_wglGetProcAddress(LPCSTR name);

OVERRIDE_API (GLuint)
override_glCreateShader_ctx1(GLenum target)
{
    GLPROXY_UNUSED(target);
    if (current_context != ctx1) {
        fprintf(stderr, "ctx1 called while other context current\n");
        pass = false;
    }
    return CREATESHADER_CTX1_VAL;
}

OVERRIDE_API (GLuint)
override_glCreateShader_ctx2(GLenum target)
{
    GLPROXY_UNUSED(target);
    if (current_context != ctx2) {
        fprintf(stderr, "ctx2 called while other context current\n");
        pass = false;
    }
    return CREATESHADER_CTX2_VAL;
}

OVERRIDE_API (PROC)
override_wglGetProcAddress(LPCSTR name)
{
    assert(strcmp(name, "glCreateShader") == 0);

    if (current_context == ctx1) {
        return (PROC)override_glCreateShader_ctx1;
    } else {
        assert(current_context == ctx2);
        return (PROC)override_glCreateShader_ctx2;
    }
}

static void
test_createshader(HDC hdc, HGLRC ctx, void *glproxy_ctx)
{
    GLuint shader, expected;
    int ctxnum;
    glproxy_context_set(glproxy_ctx);

    wglMakeCurrent(hdc, ctx);
    current_context = ctx;

    /* Install our GPA override so we can force per-context function
     * pointers.
     */
    *glproxy_context_get_function_pointer("wgl", "wglGetProcAddress") = override_wglGetProcAddress;

    if (ctx == ctx1) {
        expected = CREATESHADER_CTX1_VAL;
        ctxnum = 1;
    } else {
        assert(ctx == ctx2);
        expected = CREATESHADER_CTX2_VAL;
        ctxnum = 2;
    }

    shader = glCreateShader(GL_FRAGMENT_SHADER);
    printf("ctx%d: Returned %d\n", ctxnum, shader);
    if (shader != expected) {
        fprintf(stderr, "  expected %d\n", expected);
        pass = false;
    }
}

static int
test_function(HDC hdc)
{
    void *glproxy_ctx1 = glproxy_context_create(NULL);
    void *glproxy_ctx2 = glproxy_context_create(NULL);

    glproxy_context_set(glproxy_ctx1);
    ctx1 = wglCreateContext(hdc);

    glproxy_context_set(glproxy_ctx2);
    ctx2 = wglCreateContext(hdc);

    if (!ctx1 || !ctx2) {
        fprintf(stderr, "Failed to create wgl contexts\n");
        return 1;
    }
    if (!glproxy_ctx1 || !glproxy_ctx2) {
        fprintf(stderr, "Failed to create glproxy contexts\n");
        return 1;
    }

    glproxy_context_set(glproxy_ctx1);
    if (!wglMakeCurrent(hdc, ctx1)) {
        fprintf(stderr, "Failed to make context current\n");
        return 1;
    }

    if (glproxy_gl_version() < 20) {
        /* We could possibly do a 1.3 entrypoint or something instead. */
        fprintf(stderr, "Test relies on overriding a GL 2.0 entrypoint\n");
        return 77;
    }

    {
        /* Force resolving glproxy_wglGetProcAddress. */
        void* x = wglGetProcAddress("glCreateShader");
    }

    test_createshader(hdc, ctx1, glproxy_ctx1);
    test_createshader(hdc, ctx1, glproxy_ctx1);
    test_createshader(hdc, ctx2, glproxy_ctx2);
    test_createshader(hdc, ctx2, glproxy_ctx2);
    test_createshader(hdc, ctx1, glproxy_ctx1);
    test_createshader(hdc, ctx2, glproxy_ctx2);

    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(ctx1);
    wglDeleteContext(ctx2);
    glproxy_context_destroy(glproxy_ctx1);
    glproxy_context_destroy(glproxy_ctx2);

    return !pass;
}

int main()
{
    make_window_and_test(test_function);

    /* UNREACHED */
    return 1;
}
