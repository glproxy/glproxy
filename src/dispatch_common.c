﻿/*
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

const char *WGL_LIBS[] = {
    "opengl32.dll",
    NULL
};

const char* GLX_LIBS[] = {
#if defined(__APPLE__)
    "/opt/X11/lib/libGL.1.dylib",
#elif defined(ANDROID)
    "libGLESv2.so",
#elif defined(_WIN32)
    // Win32 do not contains GLX LIBS
#else
    "libGL.so.1",
#endif
    NULL,
};

const char *GL_LIBS[] = {
#if defined(__APPLE__)
    "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL",
#endif
    NULL
};

const char* EGL_LIBS[] = {
#if defined(ANDROID)
    "libEGL.so",
#elif defined(_WIN32)
    "libEGL.dll",
    "libEGLd.dll", // For Qt
#else
    "libEGL.so.1",
#endif
    NULL
};

const char* GLES1_LIBS[] = {
#if defined(ANDROID)
    "libGLESv1_CM.so",
#elif defined(_WIN32)
    "libGLESv1_CM.dll",
    "libGLESv1_CMd.dll",
#else
    "libGLESv1_CM.so.1",
#endif
    NULL
};

const char* GLES2_LIBS[] = {
#if defined(ANDROID)
    "libGLESv2.so",
#elif defined(_WIN32)
    "libGLESv2.dll",
    "libGLESv2d.dll",
#else
    "libGLESv2.so.2",
#endif
    NULL
};

static void *do_dlsym_by_handle(void*handle, const char* name, const char**error, bool show_error) {
    void *result = NULL;
#ifdef _WIN32
    if (!handle) {
        return result;
    }
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

// API required by following functions
static void *do_dlsym(void **handle, const char **lib_names, const char *name, bool exit_on_fail) {
    void *result = NULL;
    const char *error = "unknow";

    const char** lib_name = lib_names;
    if (*handle) {
        result = do_dlsym_by_handle(*handle, name, &error, false);
    } else {
        while (*lib_name) {
            void *tmp_handle = dlopen_handle(*lib_name, &error);
            if (tmp_handle) {
                result = do_dlsym_by_handle(tmp_handle, name, &error, false);
                if (result) {
                    *handle = tmp_handle;
                    return result;
                }
            }
            ++lib_name;
        }
    }

    if (!result && exit_on_fail) {
        fprintf(stderr, "%s() not found in %s: %s\n", name, lib_names[0], error);
        exit(1);
    }

    return result;
}

static int epoxy_internal_gl_version(int error_version) {
    const char *version = (const char *)glGetString(GL_VERSION);
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

#if PLATFORM_HAS_EGL
static EGLenum epoxy_egl_get_current_gl_context_api_by_handle(void* handle) {
    const char *error = "unknow";
    PFNEGLQUERYAPIPROC eglQueryAPILocal = do_dlsym_by_handle(handle, "eglQueryAPI", &error, true);
    PFNEGLGETCURRENTCONTEXTPROC eglGetCurrentContextLocal = do_dlsym_by_handle(handle, "eglGetCurrentContext", &error, true);
    PFNEGLBINDAPIPROC eglBindAPILocal = do_dlsym_by_handle(handle, "eglBindAPI", &error, true);
    PFNEGLGETERRORPROC eglGetErrorLocal = do_dlsym_by_handle(handle, "eglGetError", &error, true);

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

static void epoxy_egl_open_handle(tls_ptr tls, bool need_context, EGLenum *result) {
    const char **egl_lib;
    const char **egl_libs_begin = EGL_LIBS - 1;
    const char **egl_libs_end = EGL_LIBS + (sizeof(EGL_LIBS) / sizeof(EGL_LIBS[0]));
    int pos = 0;
    bool is_first = true;
    if (need_context) {
        *result = EGL_NONE;
    }
    for (egl_lib = egl_libs_begin; egl_lib < egl_libs_end; ++pos) {
        if (tls->egl_handle) {
            if (need_context) {
                *result = epoxy_egl_get_current_gl_context_api_by_handle(tls->egl_handle);
                if (*result != EGL_NONE) {
                    return;
                }
                if (is_first) {
                    return;
                }
            } else {
                return;
            }
        }
        ++egl_lib;
        is_first = false;
        if (tls->egl_handle) {
            dlclose_handle(tls->egl_handle);
        }
        if (!*egl_lib) {
            break;
        }
        tls->egl_handle = dlopen_handle(*egl_lib, NULL);
        tls->gles1_name = GLES1_LIBS[pos];
        tls->gles2_name = GLES2_LIBS[pos];
    }
}

static EGLenum epoxy_egl_get_current_gl_context_api(tls_ptr tls) {
    if (tls->egl_context_api != 0) {
        return tls->egl_context_api;
    }
#if PLATFORM_HAS_GLX
    tls->egl_context_api = epoxy_egl_get_current_gl_context_api_by_handle(NULL);
    if (tls->egl_context_api != EGL_NONE) {
        return tls->egl_context_api;
    }
#endif
    epoxy_egl_open_handle(tls, true, &tls->egl_context_api);
    switch (tls->egl_context_api) {
    case EGL_OPENGL_API:
        break;
    case EGL_OPENGL_ES_API: {
        if (!tls->gles2_handle && tls->gles2_name) {
            tls->gles2_handle = dlopen_handle(tls->gles2_name, NULL);
        }
        if (!tls->gles2_handle && !tls->gles1_handle && tls->gles1_name) {
            tls->gles1_handle = dlopen_handle(tls->gles1_name, NULL);
        }
        break;
    }
    default:
        break;
    }
    return tls->egl_context_api;
}
#endif /* PLATFORM_HAS_EGL */

/**
* Tests whether the currently bound context is EGL or GLX, trying to
* avoid loading libraries unless necessary.
*/
static bool epoxy_current_context_is_gl_desktop(tls_ptr tls) {
    /* If the application hasn't explicitly called some of our GLX
    * or EGL code but has presumably set up a context on its own,
    * then we need to figure out how to getprocaddress anyway.
    *
    * If there's a public GetProcAddress loaded in the
    * application's namespace, then use that.
    */
    void *sym;

#if PLATFORM_HAS_GLX
    sym = dlsym(NULL, "glXGetCurrentContext");
    if (sym) {
        if (glXGetCurrentContext())
            return true;
    } else {
        (void)dlerror();
    }

    /* OK, couldn't find anything in the app's address space.
    * Presumably they dlopened with RTLD_LOCAL, which hides it
    * from us.  Just go dlopen()ing likely libraries and try them.
    */
    sym = do_dlsym(&tls->glx_handle, GLX_LIBS, "glXGetCurrentContext", false);
    if (sym && glXGetCurrentContext())
        return true;
#endif /* PLATFORM_HAS_GLX */

#if PLATFORM_HAS_WGL
    sym = do_dlsym(&tls->wgl_handle, WGL_LIBS, "wglGetCurrentContext",
        false);
    if (sym && wglGetCurrentContext()) {
        return true;
    }
#endif
#if PLATFORM_HAS_EGL
    if (epoxy_egl_get_current_gl_context_api(tls) != EGL_NONE)
        return false;
#endif /* PLATFORM_HAS_EGL */

    return true;
}

bool epoxy_extension_in_string(const char *extension_list, const char *ext) {
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

static bool epoxy_internal_has_gl_extension(const char *ext, bool invalid_op_mode) {
    if (epoxy_gl_version() < 30) {
        const char *exts = (const char *)glGetString(GL_EXTENSIONS);
        if (!exts)
            return invalid_op_mode;
        return epoxy_extension_in_string(exts, ext);
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

void *epoxy_wgl_dlsym(tls_ptr tls, const char *name) {
    return do_dlsym(&tls->wgl_handle, WGL_LIBS, name, true);
}

void *epoxy_glx_dlsym(tls_ptr tls, const char *name) {
    return do_dlsym(&tls->glx_handle, GLX_LIBS, name, true);
}

void *epoxy_gl_dlsym(tls_ptr tls, const char *name) {
#if defined(__APPLE__)
    return do_dlsym(&tls->gl_handle, GL_LIBS, name, true);
#elif defined(_WIN32)
    return epoxy_wgl_dlsym(tls, name);
#else
    return epoxy_glx_dlsym(tls, name);
#endif
}

static void *epoxy_get_proc_address(tls_ptr tls, const char *name) {
    if (epoxy_current_context_is_gl_desktop(tls)) {
#ifdef _WIN32
        return wglGetProcAddress(name);
#elif defined (__APPLE__)
        epoxy_gl_dlsym(tls, name)
#else
        return glXGetProcAddressARB((const GLubyte *)name);
#endif
    }
#if PLATFORM_HAS_EGL
    else
    {
        GLenum egl_api = epoxy_egl_get_current_gl_context_api(tls);

        switch (egl_api) {
        case EGL_OPENGL_API:
        case EGL_OPENGL_ES_API:
            return eglGetProcAddress(name);
        case EGL_NONE:
            break;
        }
    }
#endif
    fprintf(stderr, "Couldn't find current GLX or EGL context.\n");
    return NULL;
}

/**
* Performs either the dlsym or glXGetProcAddress()-equivalent for
* core functions in desktop GL.
*/
void *epoxy_get_core_proc_address(tls_ptr tls, const char *name, int core_version) {
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
        return epoxy_gl_dlsym(tls, name);
    } else {
        return epoxy_get_proc_address(tls, name);
    }
}

void *epoxy_egl_dlsym(tls_ptr tls, const char *name) {
    void* result = NULL;
#if PLATFORM_HAS_EGL
    epoxy_egl_open_handle(tls, false, NULL);
    char *error = "unknow";
    result = do_dlsym_by_handle(tls->egl_handle, name, &error, true);
#endif
    return result;
}

void *epoxy_gles1_dlsym(tls_ptr tls, const char *name) {
    void* result = NULL;
#if PLATFORM_HAS_EGL
    epoxy_egl_get_current_gl_context_api(tls);
    if (tls->gles1_handle) {
        char *error = "unknow";
        result = do_dlsym_by_handle(tls->gles1_handle, name, &error, true);
    } else {
        result = epoxy_get_proc_address(tls, name);
    }
#endif
    return result;
}

void *epoxy_gles2_dlsym(tls_ptr tls, const char *name) {
    void* result = NULL;
#if PLATFORM_HAS_EGL
    epoxy_egl_get_current_gl_context_api(tls);
    if (tls->gles2_handle) {
        char *error = "unknow";
        result = do_dlsym_by_handle(tls->gles2_handle, name, &error, true);
    } else {
        result = epoxy_get_proc_address(tls, name);
    }
#endif
    return result;
}

/**
* Does the appropriate dlsym() or eglGetProcAddress() for GLES3
* functions.
*
* Mesa interpreted GLES as intending that the GLES3 functions were
* available only through eglGetProcAddress() and not dlsym(), while
* ARM's Mali drivers interpreted GLES as intending that GLES3
* functions were available only through dlsym() and not
* eglGetProcAddress().  Thanks, Khronos.
*/
void *epoxy_gles3_dlsym(tls_ptr tls, const char *name) {
    void* result = NULL;
#if PLATFORM_HAS_EGL
    epoxy_egl_get_current_gl_context_api(tls);
    if (tls->gles2_handle) {
        char *error = "unknow";
        result = do_dlsym_by_handle(tls->gles2_handle, name, &error, true);
        if (!result) {
            result = epoxy_get_proc_address(tls, name);
        }
    } else {
        result = epoxy_get_proc_address(tls, name);
    }
#endif
    return result;
}

/**
* Performs the dlsym() for the core GL 1.0 functions that we use for
* determining version and extension support for deciding on dlsym
* versus glXGetProcAddress() for all other functions.
*
* This needs to succeed on implementations without GLX (since
* glGetString() and glGetIntegerv() are both in GLES1/2 as well, and
* at call time we don't know for sure what API they're trying to use
* without inspecting contexts ourselves).
*/
void *epoxy_get_bootstrap_proc_address(tls_ptr tls, const char *name) {
    /* If we already have a library that links to libglapi loaded,
    * use that.
    */
#if PLATFORM_HAS_GLX
    if (tls->glx_handle && glXGetCurrentContext())
        return epoxy_glx_dlsym(name);
#endif

    /* If epoxy hasn't loaded any API-specific library yet, try to
    * figure out what API the context is using and use that library,
    * since future calls will also use that API (this prevents a
    * non-X11 ES2 context from loading a bunch of X11 junk).
    */
#if PLATFORM_HAS_EGL
    switch (epoxy_egl_get_current_gl_context_api(tls)) {
    default: break;
    case EGL_OPENGL_API:
        return epoxy_gl_dlsym(tls, name);
    case EGL_OPENGL_ES_API:
        /* We can't resolve the GL version, because
        * epoxy_glGetString() is one of the two things calling
        * us.  Try the GLES2 implementation first, and fall back
        * to GLES1 otherwise.
        */
        if (tls->gles2_handle)
            return epoxy_gles2_dlsym(tls, name);
        else
            return epoxy_gles1_dlsym(tls, name);
    }
#endif /* PLATFORM_HAS_EGL */

    /* Fall back to the platform default */
    return epoxy_gl_dlsym(tls, name);
}

int epoxy_conservative_gl_version(tls_ptr tls) {
    return epoxy_internal_gl_version(100);
}

bool epoxy_conservative_has_gl_extension(tls_ptr tls, const char *ext) {
    return epoxy_internal_has_gl_extension(ext, true);
}

#if PLATFORM_HAS_WGL

EPOXY_IMPORTEXPORT bool epoxy_has_wgl_extension(HDC hdc, const char *ext) {
    PFNWGLGETEXTENSIONSSTRINGARBPROC getext;

    getext = (void *)wglGetProcAddress("wglGetExtensionsStringARB");
    if (!getext) {
        fprintf(stderr,
            "Implementation unexpectedly missing "
            "WGL_ARB_extensions_string.  Probably a libepoxy bug.\n");
        return false;
    }

    return epoxy_extension_in_string(getext(hdc), ext);
}

/**
* If we can determine the WGL extension support from the current
* context, then return that, otherwise give the answer that will just
* send us on to get_proc_address().
*/
bool epoxy_conservative_has_wgl_extension(const char *ext)
{
    HDC hdc = wglGetCurrentDC();

    if (!hdc)
        return true;

    return epoxy_has_wgl_extension(hdc, ext);
}

#endif /* PLATFORM_HAS_WGL */

#if PLATFORM_HAS_GLX
/**
* If we can determine the GLX version from the current context, then
* return that, otherwise return a version that will just send us on
* to dlsym() or get_proc_address().
*/
int epoxy_conservative_glx_version(void) {
    Display *dpy = glXGetCurrentDisplay();
    GLXContext ctx = glXGetCurrentContext();
    int screen;

    if (!dpy || !ctx)
        return 14;

    glXQueryContext(dpy, ctx, GLX_SCREEN, &screen);

    return epoxy_glx_version(dpy, screen);
}

EPOXY_IMPORTEXPORT int epoxy_glx_version(Display *dpy, int screen) {
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
bool epoxy_conservative_has_glx_extension(const char *ext) {
    Display *dpy = glXGetCurrentDisplay();
    GLXContext ctx = glXGetCurrentContext();
    int screen;

    if (!dpy || !ctx)
        return true;

    glXQueryContext(dpy, ctx, GLX_SCREEN, &screen);

    return epoxy_has_glx_extension(dpy, screen, ext);
}

EPOXY_IMPORTEXPORT bool epoxy_has_glx_extension(Display *dpy, int screen, const char *ext) {
    /* No, you can't just use glXGetClientString or
    * glXGetServerString() here.  Those each tell you about one half
    * of what's needed for an extension to be supported, and
    * glXQueryExtensionsString() is what gives you the intersection
    * of the two.
    */
    return epoxy_extension_in_string(glXQueryExtensionsString(dpy, screen), ext);
}

#endif /* PLATFORM_HAS_GLX */

#if PLATFORM_HAS_EGL

EPOXY_IMPORTEXPORT int epoxy_egl_version(EGLDisplay dpy) {
    int major, minor;
    const char *version_string;
    int ret;

    version_string = eglQueryString(dpy, EGL_VERSION);
    ret = sscanf(version_string, "%d.%d", &major, &minor);
    assert(ret == 2);
    return major * 10 + minor;
}

int epoxy_conservative_egl_version(void) {
    EGLDisplay dpy = eglGetCurrentDisplay();

    if (!dpy)
        return 14;

    return epoxy_egl_version(dpy);
}

EPOXY_IMPORTEXPORT bool epoxy_has_egl_extension(EGLDisplay dpy, const char *ext)
{
    return epoxy_extension_in_string(eglQueryString(dpy, EGL_EXTENSIONS), ext);
}

bool epoxy_conservative_has_egl_extension(const char *ext)
{
    EGLDisplay dpy = eglGetCurrentDisplay();

    if (!dpy)
        return true;

    return epoxy_has_egl_extension(dpy, ext);
}

#endif /* PLATFORM_HAS_EGL */

static void reset_dispatch_common_tls(tls_ptr tls);

EPOXY_IMPORTEXPORT bool epoxy_has_gl_extension(const char *ext) {
    return epoxy_internal_has_gl_extension(ext, false);
}

static bool inited = false;
/* The context for main thread */
static tls_ptr global_context = NULL;
/* thread local storage index */
static TLS_TYPE dispatch_common_tls_index = 0;

EPOXY_IMPORTEXPORT void epoxy_init_tls(void) {
    if (inited) {
        return;
    }
    inited = true;
#if defined(_WIN32)
    dispatch_common_tls_index = TlsAlloc();
#else
    pthread_key_create(&dispatch_common_tls_index, NULL);
#endif
    global_context = epoxy_context_create();
    epoxy_context_set(global_context);
}
CONSTRUCT(epoxy_init_tls)

EPOXY_IMPORTEXPORT void epoxy_uninit_tls(void) {
    if (!inited) {
        return;
    }
    if (!global_context) {
        fprintf(stderr, "Should calling to epoxy_uninit_tls to destroy epoxy global context.\n");
    }
    epoxy_context_destroy(global_context);
    global_context = NULL;
#if defined(_WIN32)
    TlsFree(dispatch_common_tls_index);
#else
    pthread_key_delete(dispatch_common_tls_index);
#endif
    dispatch_common_tls_index = 0;
    inited = false;
}
DESTRUCT(epoxy_uninit_tls)

EPOXY_IMPORTEXPORT void* epoxy_context_create() {
    tls_ptr tls_value = (tls_ptr)malloc(sizeof(tls_value[0]));
    memset(tls_value, 0, sizeof(tls_value[0]));
    reset_dispatch_common_tls(tls_value);
    return tls_value;
}

EPOXY_IMPORTEXPORT void* epoxy_context_get() {
    return (void*)get_tls_by_index(dispatch_common_tls_index);
}

EPOXY_IMPORTEXPORT void epoxy_context_set(void* new_context) {
    if (!inited) {
        fprintf(stderr, "The epoxy are not inited yet");
        return;
    }
    set_tls_by_index(dispatch_common_tls_index, new_context);
}

EPOXY_IMPORTEXPORT void epoxy_context_destroy(void* context) {
    if (!inited) {
        fprintf(stderr, "The epoxy are not inited yet");
        return;
    }
    if (!context) {
        fprintf(stderr, "The epoxy conext are NULL");
        return;
    }
    tls_ptr exist_context = epoxy_context_get();
    if ((void*)exist_context == context) {
        epoxy_context_set(0);
    }
    reset_dispatch_common_tls(context);
    free(context);
}

static size_t find_str_pos(const char** strList, char*expected, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        if (strcmp(strList[i], expected) == 0) {
            return i;
        }
    }
    return 0;
}

EPOXY_IMPORTEXPORT void** epoxy_context_get_function_pointer(char* target, char* membername) {
    tls_ptr exist_context = epoxy_context_get();
#if PLATFORM_HAS_WGL
    if (strcmp(target, "wgl") == 0) {
        size_t pos = find_str_pos(wgl_entrypoint_strings, membername, sizeof(wgl_entrypoint_strings) / sizeof(wgl_entrypoint_strings[0]));
        return (void**)(&exist_context->wgl_dispatch_table) + pos;
    }
#endif
#if PLATFORM_HAS_GLX
    if (strcmp(target, "glx") == 0) {
        size_t pos = find_str_pos(glx_entrypoint_strings, membername, sizeof(glx_entrypoint_strings) / sizeof(glx_entrypoint_strings[0]));
        return (void**)(&exist_context->glx_dispatch_table) + pos;
    }
#endif
    if (strcmp(target, "gl") == 0) {
        size_t pos = find_str_pos(gl_entrypoint_strings, membername, sizeof(gl_entrypoint_strings) / sizeof(gl_entrypoint_strings[0]));
        return (void**)(&exist_context->gl_dispatch_table) + pos;
    }
#if PLATFORM_HAS_EGL
    if (strcmp(target, "egl") == 0) {
        size_t pos = find_str_pos(egl_entrypoint_strings, membername, sizeof(egl_entrypoint_strings) / sizeof(egl_entrypoint_strings[0]));
        return (void**)(&exist_context->egl_dispatch_table) + pos;
    }
#endif
    return NULL;
}

static bool epoxy_is_desktop_gl_local(tls_ptr tls) {
    const char *es_prefix = "OpenGL ES";
    const char *version;
    if (tls->open_gl_type != DISPATCH_OPENGL_UNKNOW) {
        return tls->open_gl_type == DISPATCH_OPENGL_DESKTOP;
    }

#if PLATFORM_HAS_EGL
    /* PowerVR's OpenGL ES implementation (and perhaps other) don't
    * comply with the standard, which states that
    * "glGetString(GL_VERSION)" should return a string starting with
    * "OpenGL ES". Therefore, to distinguish desktop OpenGL from
    * OpenGL ES, we must also check the context type through EGL (we
    * can do that as PowerVR is only usable through EGL).
    */
    if (!epoxy_current_context_is_gl_desktop(tls)) {
        switch (epoxy_egl_get_current_gl_context_api(tls)) {
        case EGL_OPENGL_API:
            tls->open_gl_type = DISPATCH_OPENGL_DESKTOP;
            break;
        case EGL_OPENGL_ES_API:
            tls->open_gl_type = DISPATCH_OPENGL_ES;
            break;
        case EGL_NONE:
        default:  break;
        }
    } else {
        tls->open_gl_type = DISPATCH_OPENGL_DESKTOP;
    }
#endif
    if (tls->open_gl_type == DISPATCH_OPENGL_UNKNOW) {
        version = (const char *)glGetString(GL_VERSION);

        /* If we didn't get a version back, there are only two things that
        * could have happened: either malloc failure (which basically
        * doesn't exist), or we were called within a glBegin()/glEnd().
        * Assume the second, which only exists for desktop GL.
        */
        if (version && strncmp(es_prefix, version, strlen(es_prefix)) == 0) {
            tls->open_gl_type = DISPATCH_OPENGL_ES;
        }
    } 
    return tls->open_gl_type == DISPATCH_OPENGL_DESKTOP;
}

EPOXY_IMPORTEXPORT bool epoxy_is_desktop_gl(void) {
    tls_ptr tls = epoxy_context_get();
    return epoxy_is_desktop_gl_local(tls);
}

EPOXY_IMPORTEXPORT int epoxy_gl_version(void) {
    return epoxy_internal_gl_version(0);
}

#include "wgl_generated_dispatch_thunks.inc"
#include "glx_generated_dispatch_thunks.inc"
#include "gl_generated_dispatch_thunks.inc"
#include "egl_generated_dispatch_thunks.inc"

static void reset_dispatch_common_tls(tls_ptr tls) {
#if PLATFORM_HAS_WGL
    tls->wgl_dispatch_table = wgl_resolver_table;
    dlclose_handle(tls->wgl_handle);
#endif
#if PLATFORM_HAS_GLX
    tls->glx_dispatch_table = glx_resolver_table;
    dlclose_handle(tls->glx_handle);
#endif

    tls->gl_dispatch_table = gl_resolver_table;
    dlclose_handle(tls->gl_handle);

#if PLATFORM_HAS_EGL
    tls->egl_dispatch_table = egl_resolver_table;
    tls->egl_context_api = 0;

    dlclose_handle(tls->gles2_handle);
    dlclose_handle(tls->gles1_handle);
    dlclose_handle(tls->egl_handle);
#endif
    tls->open_gl_type = DISPATCH_OPENGL_UNKNOW;
}
