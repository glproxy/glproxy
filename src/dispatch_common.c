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

#include "wgl_generated_dispatch_table_type.inc"
#include "glx_generated_dispatch_table_type.inc"
#include "gl_generated_dispatch_table_type.inc"
#include "egl_generated_dispatch_table_type.inc"

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

enum DISPATCH_OPENGL_TYPE {
    DISPATCH_OPENGL_UNKNOW = 0,
    DISPATCH_OPENGL_DESKTOP = 1,
    DISPATCH_OPENGL_ES = 2
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

    /** dlopen() return value for libGLESv1_CM.so.1 */
    void *gles1_handle;

    /** dlopen() return value for libGLESv2.so.2 */
    void *gles2_handle;

    /**
     * This value gets incremented when any thread is in
     * glBegin()/glEnd() called through epoxy.
     *
     * We're not guaranteed to be called through our wrapper, so the
     * conservative paths also try to handle the failure cases they'll
     * see if begin_count didn't reflect reality.  It's also a bit of
     * a bug that the conservative paths might return success because
     * some other thread was in epoxy glBegin/glEnd while our thread
     * is trying to resolve, but given that it's basically just for
     * informative error messages, we shouldn't need to care.
     */
    long begin_count;
    PFNGLBEGINPROC glBeginSaved;
    PFNGLENDPROC glEndSaved;

    enum DISPATCH_OPENGL_TYPE open_gl_type;
};

typedef struct dispatch_common_tls *tls_ptr;

static void init_dispatch_common_tls(tls_ptr tls);

#if defined(_WIN32)
#define TLS_TYPE DWORD
#else
#define TLS_TYPE pthread_key_t
#endif

/* thread local storage index */
static TLS_TYPE dispatch_common_tls_index = 0;

static inline tls_ptr get_tls_by_index(TLS_TYPE index) {
#if defined(_WIN32)
    return (void*)TlsGetValue(index);
#else
    return (void*)pthread_getspecific(index);
#endif
}

static inline void set_tls_by_index(TLS_TYPE index, tls_ptr value) {
#if defined(_WIN32)
    TlsSetValue(index, (LPVOID)value);
#else
    pthread_setspecific(index, (void*)tls_value);
#endif
}

static tls_ptr get_dispatch_common_tls() {
    tls_ptr tls_value = get_tls_by_index(dispatch_common_tls_index);
    if (tls_value == 0) {
        tls_value = (tls_ptr)malloc(sizeof(tls_value[0]));
        memset(tls_value, 0, sizeof(tls_value[0]));
        set_tls_by_index(dispatch_common_tls_index, tls_value);
        init_dispatch_common_tls(tls_value);
    }
    return tls_value;
}

static bool inited = false;
static void dispatch_init(void) {
    if (inited) {
        return;
    }
    inited = true;
#if defined(_WIN32)
    dispatch_common_tls_index = TlsAlloc();
#else
    pthread_key_create(&dispatch_common_tls_index, NULL);
#endif
}
CONSTRUCT(dispatch_init)

static void dispatch_uninit(void) {
    if (!inited) {
        return;
    }
#if defined(_WIN32)
    TlsFree(dispatch_common_tls_index);
#else
    pthread_key_delete(dispatch_common_tls_index);
#endif
    dispatch_common_tls_index = 0;
    inited = false;
}
DESTRUCT(dispatch_uninit)

static bool get_dlopen_handle(void **handle, const char **lib_names, bool exit_on_fail) {
    const char **lib_name_ptr = lib_names;
    if (*handle)
        return true;

    for (; *lib_name_ptr; ++lib_name_ptr) {
        if (!*handle) {
#ifdef _WIN32
            *handle = LoadLibraryA(*lib_name_ptr);
#else
            *handle = dlopen(*lib_name_ptr, RTLD_LAZY | RTLD_LOCAL);
            if (!*handle && lib_name_ptr[1] == NULL) {
                if (exit_on_fail) {
                    fprintf(stderr, "Couldn't open %s: %s\n", *lib_name_ptr, dlerror());
                    exit(1);
                } else {
                    (void)dlerror();
                }
            }
#endif
        }
    }
    return *handle != NULL;
}

inline static void dlclose_handle(void* handle) {
    if (!handle) {
        return;
    }
#ifdef _WIN32
    FreeLibrary(handle);
#else
    dlclose(*handle);
#endif
}

static void *do_dlsym_by_handle(void*handle, const char* name, const char**error) {
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
    return result;
}

// API required by following functions
static void *do_dlsym(void **handle, const char **lib_names, const char *name, bool exit_on_fail) {
    void *result;
    const char *error = "";

    if (!get_dlopen_handle(handle, lib_names, exit_on_fail))
        return NULL;
    result = do_dlsym_by_handle(*handle, name, &error);
    if (!result && exit_on_fail) {
        fprintf(stderr, "%s() not found in %s: %s\n", name, *lib_names, error);
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
    PFNEGLQUERYAPIPROC eglQueryAPILocal = do_dlsym_by_handle(handle, "eglQueryAPI", NULL);
    PFNEGLGETCURRENTCONTEXTPROC eglGetCurrentContextLocal = do_dlsym_by_handle(handle, "eglGetCurrentContext", NULL);
    PFNEGLBINDAPIPROC eglBindAPILocal = do_dlsym_by_handle(handle, "eglBindAPI", NULL);
    PFNEGLGETERRORPROC eglGetErrorLocal = do_dlsym_by_handle(handle, "eglGetError", NULL);

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

static EGLenum epoxy_egl_get_current_gl_context_api(tls_ptr tls) {
    const char**egl_lib = EGL_LIBS;
    EGLenum result = EGL_NONE;
    int pos = 0;
    const char* gles1_name = NULL;
    const char* gles2_name = NULL;
#if PLATFORM_HAS_GLX
    result = epoxy_egl_get_current_gl_context_api_by_handle(NULL);
    gles1_name = GLES1_LIBS[0];
    gles2_name = GLES2_LIBS[0];
#endif
    if (result == EGL_NONE && tls->egl_handle) {
        result = epoxy_egl_get_current_gl_context_api_by_handle(tls->egl_handle);
    }
    for (; *egl_lib != NULL && result == EGL_NONE; ++egl_lib, ++pos) {
        const char* egl_libs[] = {
            *egl_lib,
            NULL
        };
        tls->egl_handle = NULL;
        get_dlopen_handle(&tls->egl_handle, egl_libs, false);
        if (tls->egl_handle) {
            result = epoxy_egl_get_current_gl_context_api_by_handle(tls->egl_handle);
            if (result != EGL_NONE) {
                gles1_name = GLES1_LIBS[pos];
                gles2_name = GLES2_LIBS[pos];
            }
        }
    }
    switch (result) {
    case EGL_OPENGL_API:
        break;
    case EGL_OPENGL_ES_API: {
        if (!tls->gles2_handle) {
            const char* gles2_libs[] = {
                gles2_name,
                NULL
            };
            get_dlopen_handle(&tls->gles2_handle, gles2_libs, false);
        }
        if (!tls->gles2_handle && !tls->gles1_handle) {
            const char* gles1_libs[] = {
                gles1_name,
                NULL
            };
            get_dlopen_handle(&tls->gles1_handle, gles1_libs, false);
        }
    }
    }
    return result;
}
#endif /* PLATFORM_HAS_EGL */

/**
* Tests whether the currently bound context is EGL or GLX, trying to
* avoid loading libraries unless necessary.
*/
static bool epoxy_current_context_is_gl_desktop(tls_ptr tls) {
#if !PLATFORM_HAS_GLX && !PLATFORM_HAS_WGL
    //TODO: Testing for All OpenGL
    return false;
#else
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

    return false;
#endif /* !PLATFORM_HAS_GLX && !PLATFORM_HAS_WGL */
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
#if defined(__APPLE__)
    return epoxy_gl_dlsym(tls, name);
#else
    if (epoxy_current_context_is_gl_desktop(tls)) {
#ifdef _WIN32
        return wglGetProcAddress(name);
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
#endif
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
    return do_dlsym(&tls->egl_handle, EGL_LIBS, name, true);
}

void *epoxy_gles1_dlsym(tls_ptr tls, const char *name) {
    if (epoxy_current_context_is_gl_desktop(tls)) {
        return epoxy_get_proc_address(tls, name);
    } else {
        return do_dlsym(&tls->gles1_handle, GLES1_LIBS, name, true);
    }
}

void *epoxy_gles2_dlsym(tls_ptr tls, const char *name) {
    if (epoxy_current_context_is_gl_desktop(tls)) {
        return epoxy_get_proc_address(tls, name);
    } else {
        return do_dlsym(&tls->gles2_handle, GLES2_LIBS, name, true);
    }
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
    if (epoxy_current_context_is_gl_desktop(tls)) {
        return epoxy_get_proc_address(tls, name);
    } else {
        void *func = do_dlsym(&tls->gles2_handle, GLES2_LIBS, name, false);

        if (func)
            return func;

        return epoxy_get_proc_address(tls, name);
    }
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
    if (tls->begin_count)
        return 100;

    return epoxy_internal_gl_version(100);
}

bool epoxy_conservative_has_gl_extension(tls_ptr tls, const char *ext) {
    if (tls->begin_count)
        return true;

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
    int ret;

    version_string = glXQueryServerString(dpy, screen, GLX_VERSION);
    ret = sscanf(version_string, "%d.%d", &server_major, &server_minor);
    assert(ret == 2);
    server = server_major * 10 + server_minor;

    version_string = glXGetClientString(dpy, GLX_VERSION);
    ret = sscanf(version_string, "%d.%d", &client_major, &client_minor);
    assert(ret == 2);
    client = client_major * 10 + client_minor;

    if (client < server)
        return client;
    else
        return server;
}

/**
* If we can determine the GLX extension support from the current
* context, then return that, otherwise give the answer that will just
* send us on to get_proc_address().
*/
bool
epoxy_conservative_has_glx_extension(const char *ext)
{
    Display *dpy = glXGetCurrentDisplay();
    GLXContext ctx = glXGetCurrentContext();
    int screen;

    if (!dpy || !ctx)
        return true;

    glXQueryContext(dpy, ctx, GLX_SCREEN, &screen);

    return epoxy_has_glx_extension(dpy, screen, ext);
}

EPOXY_IMPORTEXPORT bool
epoxy_has_glx_extension(Display *dpy, int screen, const char *ext)
{
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

EPOXY_IMPORTEXPORT bool epoxy_has_gl_extension(const char *ext) {
    return epoxy_internal_has_gl_extension(ext, false);
}

EPOXY_IMPORTEXPORT void epoxy_init_tls() {
    dispatch_init();
}

EPOXY_IMPORTEXPORT void epoxy_uninit_tls() {
    dispatch_uninit();
}

EPOXY_IMPORTEXPORT void* epoxy_context_get() {
    if (!inited) {
        fprintf(stderr, "The epoxy are not inited yet");
        return NULL;
    }
    return get_tls_by_index(dispatch_common_tls_index);
}

EPOXY_IMPORTEXPORT void epoxy_context_set(void* new_context) {
    if (!inited) {
        fprintf(stderr, "The epoxy are not inited yet");
        return;
    }
    set_tls_by_index(dispatch_common_tls_index, new_context);
}

EPOXY_IMPORTEXPORT void epoxy_context_clenaup() {
    if (!inited) {
        fprintf(stderr, "The epoxy are not inited yet");
        return;
    }
    tls_ptr exist_context = get_tls_by_index(dispatch_common_tls_index);
    if (exist_context) {
        init_dispatch_common_tls(exist_context);
        free(exist_context);
    }
    set_tls_by_index(dispatch_common_tls_index, 0);
}

static bool epoxy_is_desktop_gl_local(tls_ptr tls) {
    const char *es_prefix = "OpenGL ES";
    const char *version;
    if (tls->begin_count) {
        tls->open_gl_type = DISPATCH_OPENGL_DESKTOP;
    }
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
    tls_ptr tls = get_dispatch_common_tls();
    return epoxy_is_desktop_gl_local(tls);
}

EPOXY_IMPORTEXPORT int epoxy_gl_version(void) {
    return epoxy_internal_gl_version(0);
}

#include "wgl_generated_dispatch_thunks.inc"
#include "glx_generated_dispatch_thunks.inc"
#include "gl_generated_dispatch_thunks.inc"
#include "egl_generated_dispatch_thunks.inc"

static void EPOXY_CALLSPEC epoxy_glBegin_proxy(GLenum mode) {
    tls_ptr tls = get_dispatch_common_tls();
    ++tls->begin_count;
    if (!tls->glBeginSaved) {
        tls->glBeginSaved = epoxy_glBegin_resolver(tls);
    }
    tls->glBeginSaved(mode);
}

static void EPOXY_CALLSPEC epoxy_glEnd_proxy(void) {
    tls_ptr tls = get_dispatch_common_tls();
    if (!tls->glEndSaved) {
        tls->glEndSaved = epoxy_glEnd_resolver(tls);
    }
    tls->glEndSaved();
    --tls->begin_count;
}

static void init_dispatch_common_tls(tls_ptr tls) {
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
    tls->gl_dispatch_table.epoxy_glBegin = epoxy_glBegin_proxy;
    tls->gl_dispatch_table.epoxy_glEnd= epoxy_glEnd_proxy;
    tls->glBeginSaved = NULL;
    tls->glEndSaved = NULL;

#if PLATFORM_HAS_EGL
    tls->egl_dispatch_table = egl_resolver_table;
    dlclose_handle(tls->gles2_handle);
    dlclose_handle(tls->gles1_handle);
    dlclose_handle(tls->egl_handle);
#endif
    tls->open_gl_type = DISPATCH_OPENGL_UNKNOW;
}
