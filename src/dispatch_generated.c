
#include "dispatch_common.h"
#include <stdio.h>

static init_dispatch_metadata_metadata(struct dispatch_metadata *data) {
    const struct dispatch_resolve_info *iter = NULL;
    khronos_uint16_t offset = 0;
    khronos_uint16_t pos = 0;
    khronos_uint8_t prev_identity = -1;
    for (iter = data->resolve_info_table; iter->resolve_type != DISPATCH_RESOLVE_TERMINATOR; ++iter,++offset) {
        if (iter->identity != prev_identity) {
            prev_identity = iter->identity;
            data->resolve_offsets[pos] = offset;
            data->method_name_offsets[pos] = iter->name_offset;
            ++pos;
        }
    }
}

#include "wgl_generated_dispatch_thunks.inc"
#include "glx_generated_dispatch_thunks.inc"
#include "gl_generated_dispatch_thunks.inc"
#include "egl_generated_dispatch_thunks.inc"

void epoxy_dispatch_common_tls_init(tls_ptr tls, bool inited) {
    tls->open_gl_type = DISPATCH_OPENGL_UNKNOW;
    fprintf(stderr, "sizeof dispatch_resolve_info :%d", sizeof(struct dispatch_resolve_info));

#if PLATFORM_HAS_WGL
    wgl_epoxy_dispatch_metadata_init(&(tls->wgl_metadata), inited);
#endif
#if PLATFORM_HAS_GLX
    glx_epoxy_dispatch_metadata_init(&(tls->glx_metadata), inited);
#endif

    gl_epoxy_dispatch_metadata_init(&(tls->gl_metadata), inited);

#if PLATFORM_HAS_EGL
    egl_epoxy_dispatch_metadata_init(&(tls->egl_metadata), inited);
#endif
}
