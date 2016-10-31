
#include "dispatch_common.h"

#include "wgl_generated_dispatch_thunks.inc"
#include "glx_generated_dispatch_thunks.inc"
#include "gl_generated_dispatch_thunks.inc"
#include "egl_generated_dispatch_thunks.inc"


void reset_dispatch_common_tls(tls_ptr tls) {
#if PLATFORM_HAS_WGL
    dlclose_handle(tls->wgl_handle);
#endif
#if PLATFORM_HAS_GLX
    dlclose_handle(tls->glx_handle);
#endif

    dlclose_handle(tls->gl_handle);

#if PLATFORM_HAS_EGL
    tls->egl_context_api = 0;

    dlclose_handle(tls->gles2_handle);
    dlclose_handle(tls->gles1_handle);
    dlclose_handle(tls->egl_handle);
#endif
    tls->open_gl_type = DISPATCH_OPENGL_UNKNOW;
    memset(tls, 0, sizeof(tls[0]));
}
