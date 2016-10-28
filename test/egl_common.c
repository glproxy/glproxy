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

#include <epoxy/egl.h>
#include <stdio.h>
#include "egl_common.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <err.h>
#include <X11/Xlib.h>
#endif

#ifdef _WIN32

static finished = false;
static LRESULT CALLBACK
window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    int ret;

    switch (message) {
    case WM_CREATE:
        finished = true;
        return 0;
    default:
        return DefWindowProc(hwnd, message, wparam, lparam);
    }
}

HDC
make_window_and_test()
{
    LPCTSTR class_name = TEXT("epoxy");
    LPCTSTR window_name = TEXT("epoxy");
    int width = 150;
    int height = 150;
    HWND hwnd;
    HINSTANCE hcurrentinst = NULL;
    WNDCLASS window_class;
    MSG msg;


    memset(&window_class, 0, sizeof(window_class));
    window_class.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    window_class.cbClsExtra = 0;
    window_class.cbWndExtra = 0;
    window_class.lpfnWndProc = window_proc;
    window_class.hInstance = hcurrentinst;
    window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    window_class.lpszMenuName = NULL;
    window_class.lpszClassName = class_name;
    if (!RegisterClass(&window_class)) {
        fprintf(stderr, "Failed to register window class\n");
        exit(1);
    }

    /* create window */
    hwnd = CreateWindow(class_name, window_name,
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
        0, 0, width, height,
        NULL, NULL, hcurrentinst, NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (finished) {
            break;
        }
    }
    HDC hdc = GetDC(hwnd);
    return hdc;
}

#endif

/**
 * Do whatever it takes to get us an EGL display for the system.
 *
 * This needs to be ported to other window systems.
 */
EGLDisplay 
get_egl_display_or_skip(void)
{
#ifdef _WIN32
    HDC dpy = make_window_and_test();
#else
    Display *dpy = XOpenDisplay(NULL);
#endif
    EGLint major, minor;
    EGLDisplay edpy;
    bool ok;

    if (!dpy)
        fprintf(stderr, "couldn't open display\n");
    edpy = eglGetDisplay((EGLNativeDisplayType)dpy);
    if (edpy == EGL_NO_DISPLAY)
        fprintf(stderr, "Couldn't get EGL display for X11 Display.\n");

    ok = eglInitialize(edpy, &major, &minor);
    if (!ok)
        fprintf(stderr, "eglInitialize() failed\n");

    return edpy;
}
