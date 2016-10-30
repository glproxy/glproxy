/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#include "dispatch_common.h"
#if PLATFORM_HAS_EGL

EPOXY_NOINLINE static void *
egl_provider_resolver(tls_ptr tls, const char *name,
                                   const enum egl_provider *providers,
                                   const uint16_t *entrypoints)
{
    int i;
    for (i = 0; providers[i] != egl_provider_terminator; i++) {
        switch (providers[i]) {
        case EGL_10:
            if (true)
                return epoxy_egl_dlsym(tls, egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_11:
            if (epoxy_conservative_egl_version() >= 11)
                return epoxy_egl_dlsym(tls, egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_12:
            if (epoxy_conservative_egl_version() >= 12)
                return epoxy_egl_dlsym(tls, egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_14:
            if (epoxy_conservative_egl_version() >= 14)
                return epoxy_egl_dlsym(tls, egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_15:
            if (epoxy_conservative_egl_version() >= 15)
                return epoxy_egl_dlsym(tls, egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_ANDROID_blob_cache:
            if (epoxy_conservative_has_egl_extension("EGL_ANDROID_blob_cache"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_ANDROID_create_native_client_buffer:
            if (epoxy_conservative_has_egl_extension("EGL_ANDROID_create_native_client_buffer"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_ANDROID_native_fence_sync:
            if (epoxy_conservative_has_egl_extension("EGL_ANDROID_native_fence_sync"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_ANDROID_presentation_time:
            if (epoxy_conservative_has_egl_extension("EGL_ANDROID_presentation_time"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_ANGLE_query_surface_pointer:
            if (epoxy_conservative_has_egl_extension("EGL_ANGLE_query_surface_pointer"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_device_base:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_device_base"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_device_enumeration:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_device_enumeration"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_device_query:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_device_query"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_output_base:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_output_base"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_platform_base:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_platform_base"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_stream_consumer_egloutput:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_stream_consumer_egloutput"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_EXT_swap_buffers_with_damage:
            if (epoxy_conservative_has_egl_extension("EGL_EXT_swap_buffers_with_damage"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_HI_clientpixmap:
            if (epoxy_conservative_has_egl_extension("EGL_HI_clientpixmap"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_cl_event2:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_cl_event2"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_debug:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_debug"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_fence_sync:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_fence_sync"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_image:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_image"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_image_base:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_image_base"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_lock_surface3:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_lock_surface3"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_lock_surface:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_lock_surface"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_partial_update:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_partial_update"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_reusable_sync:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_reusable_sync"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_stream:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_stream"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_stream_consumer_gltexture:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_stream_consumer_gltexture"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_stream_cross_process_fd:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_stream_cross_process_fd"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_stream_fifo:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_stream_fifo"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_stream_producer_eglsurface:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_stream_producer_eglsurface"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_swap_buffers_with_damage:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_swap_buffers_with_damage"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_KHR_wait_sync:
            if (epoxy_conservative_has_egl_extension("EGL_KHR_wait_sync"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_MESA_drm_image:
            if (epoxy_conservative_has_egl_extension("EGL_MESA_drm_image"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_MESA_image_dma_buf_export:
            if (epoxy_conservative_has_egl_extension("EGL_MESA_image_dma_buf_export"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NOK_swap_region2:
            if (epoxy_conservative_has_egl_extension("EGL_NOK_swap_region2"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NOK_swap_region:
            if (epoxy_conservative_has_egl_extension("EGL_NOK_swap_region"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_native_query:
            if (epoxy_conservative_has_egl_extension("EGL_NV_native_query"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_post_sub_buffer:
            if (epoxy_conservative_has_egl_extension("EGL_NV_post_sub_buffer"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_stream_consumer_gltexture_yuv:
            if (epoxy_conservative_has_egl_extension("EGL_NV_stream_consumer_gltexture_yuv"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_stream_metadata:
            if (epoxy_conservative_has_egl_extension("EGL_NV_stream_metadata"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_stream_sync:
            if (epoxy_conservative_has_egl_extension("EGL_NV_stream_sync"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_sync:
            if (epoxy_conservative_has_egl_extension("EGL_NV_sync"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case EGL_extension_EGL_NV_system_time:
            if (epoxy_conservative_has_egl_extension("EGL_NV_system_time"))
                return eglGetProcAddress(egl_entrypoint_strings[entrypoints[i]]);
            break;
        case egl_provider_terminator:
            abort(); /* Not reached */
        }
    }

    fprintf(stderr, "No provider of %s found.  Requires one of:\n", name);
    for (i = 0; providers[i] != egl_provider_terminator; i++) {
        fprintf(stderr, "    %s\n", egl_enum_string + egl_enum_string_offsets[providers[i]]);
    }
    if (providers[0] == egl_provider_terminator) {
        fprintf(stderr, "    No known providers.  This is likely a bug "
                        "in libepoxy code generation\n");
    }
    abort();
}

EPOXY_NOINLINE static void *
egl_single_resolver(tls_ptr tls, enum egl_provider provider, uint16_t entrypoint_offset)
{
    enum egl_provider providers[] = {
        provider,
        egl_provider_terminator
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[entrypoint_offset],
                                providers, &entrypoint_offset);
}

static PFNEGLBINDAPIPROC
epoxy_eglBindAPI_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_12, 0 /* eglBindAPI */);
}

static PFNEGLBINDTEXIMAGEPROC
epoxy_eglBindTexImage_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_11, 1 /* eglBindTexImage */);
}

static PFNEGLCHOOSECONFIGPROC
epoxy_eglChooseConfig_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 2 /* eglChooseConfig */);
}

static PFNEGLCLIENTWAITSYNCPROC
epoxy_eglClientWaitSync_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_15,
        EGL_extension_EGL_KHR_fence_sync,
        EGL_extension_EGL_KHR_reusable_sync,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        3 /* "eglClientWaitSync" */,
        4 /* "eglClientWaitSyncKHR" */,
        4 /* "eglClientWaitSyncKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[3] /* "eglClientWaitSync" */,
                                providers, entrypoints);
}

static PFNEGLCLIENTWAITSYNCKHRPROC
epoxy_eglClientWaitSyncKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_fence_sync,
        EGL_extension_EGL_KHR_reusable_sync,
        EGL_15,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        4 /* "eglClientWaitSyncKHR" */,
        4 /* "eglClientWaitSyncKHR" */,
        3 /* "eglClientWaitSync" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[4] /* "eglClientWaitSyncKHR" */,
                                providers, entrypoints);
}

static PFNEGLCLIENTWAITSYNCNVPROC
epoxy_eglClientWaitSyncNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_sync, 5 /* eglClientWaitSyncNV */);
}

static PFNEGLCOPYBUFFERSPROC
epoxy_eglCopyBuffers_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 6 /* eglCopyBuffers */);
}

static PFNEGLCREATECONTEXTPROC
epoxy_eglCreateContext_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 7 /* eglCreateContext */);
}

static PFNEGLCREATEDRMIMAGEMESAPROC
epoxy_eglCreateDRMImageMESA_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_MESA_drm_image, 8 /* eglCreateDRMImageMESA */);
}

static PFNEGLCREATEFENCESYNCNVPROC
epoxy_eglCreateFenceSyncNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_sync, 9 /* eglCreateFenceSyncNV */);
}

static PFNEGLCREATEIMAGEPROC
epoxy_eglCreateImage_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_15, 10 /* eglCreateImage */);
}

static PFNEGLCREATEIMAGEKHRPROC
epoxy_eglCreateImageKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_image,
        EGL_extension_EGL_KHR_image_base,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        11 /* "eglCreateImageKHR" */,
        11 /* "eglCreateImageKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[11] /* "eglCreateImageKHR" */,
                                providers, entrypoints);
}

static PFNEGLCREATENATIVECLIENTBUFFERANDROIDPROC
epoxy_eglCreateNativeClientBufferANDROID_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_ANDROID_create_native_client_buffer, 12 /* eglCreateNativeClientBufferANDROID */);
}

static PFNEGLCREATEPBUFFERFROMCLIENTBUFFERPROC
epoxy_eglCreatePbufferFromClientBuffer_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_12, 13 /* eglCreatePbufferFromClientBuffer */);
}

static PFNEGLCREATEPBUFFERSURFACEPROC
epoxy_eglCreatePbufferSurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 14 /* eglCreatePbufferSurface */);
}

static PFNEGLCREATEPIXMAPSURFACEPROC
epoxy_eglCreatePixmapSurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 15 /* eglCreatePixmapSurface */);
}

static PFNEGLCREATEPIXMAPSURFACEHIPROC
epoxy_eglCreatePixmapSurfaceHI_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_HI_clientpixmap, 16 /* eglCreatePixmapSurfaceHI */);
}

static PFNEGLCREATEPLATFORMPIXMAPSURFACEPROC
epoxy_eglCreatePlatformPixmapSurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_15, 17 /* eglCreatePlatformPixmapSurface */);
}

static PFNEGLCREATEPLATFORMPIXMAPSURFACEEXTPROC
epoxy_eglCreatePlatformPixmapSurfaceEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_platform_base, 18 /* eglCreatePlatformPixmapSurfaceEXT */);
}

static PFNEGLCREATEPLATFORMWINDOWSURFACEPROC
epoxy_eglCreatePlatformWindowSurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_15, 19 /* eglCreatePlatformWindowSurface */);
}

static PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC
epoxy_eglCreatePlatformWindowSurfaceEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_platform_base, 20 /* eglCreatePlatformWindowSurfaceEXT */);
}

static PFNEGLCREATESTREAMFROMFILEDESCRIPTORKHRPROC
epoxy_eglCreateStreamFromFileDescriptorKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_cross_process_fd, 21 /* eglCreateStreamFromFileDescriptorKHR */);
}

static PFNEGLCREATESTREAMKHRPROC
epoxy_eglCreateStreamKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream, 22 /* eglCreateStreamKHR */);
}

static PFNEGLCREATESTREAMPRODUCERSURFACEKHRPROC
epoxy_eglCreateStreamProducerSurfaceKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_producer_eglsurface, 23 /* eglCreateStreamProducerSurfaceKHR */);
}

static PFNEGLCREATESTREAMSYNCNVPROC
epoxy_eglCreateStreamSyncNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_stream_sync, 24 /* eglCreateStreamSyncNV */);
}

static PFNEGLCREATESYNCPROC
epoxy_eglCreateSync_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_15,
        EGL_extension_EGL_KHR_cl_event2,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        25 /* "eglCreateSync" */,
        26 /* "eglCreateSync64KHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[25] /* "eglCreateSync" */,
                                providers, entrypoints);
}

static PFNEGLCREATESYNC64KHRPROC
epoxy_eglCreateSync64KHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_cl_event2,
        EGL_15,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        26 /* "eglCreateSync64KHR" */,
        25 /* "eglCreateSync" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[26] /* "eglCreateSync64KHR" */,
                                providers, entrypoints);
}

static PFNEGLCREATESYNCKHRPROC
epoxy_eglCreateSyncKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_fence_sync,
        EGL_extension_EGL_KHR_reusable_sync,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        27 /* "eglCreateSyncKHR" */,
        27 /* "eglCreateSyncKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[27] /* "eglCreateSyncKHR" */,
                                providers, entrypoints);
}

static PFNEGLCREATEWINDOWSURFACEPROC
epoxy_eglCreateWindowSurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 28 /* eglCreateWindowSurface */);
}

static PFNEGLDEBUGMESSAGECONTROLKHRPROC
epoxy_eglDebugMessageControlKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_debug, 29 /* eglDebugMessageControlKHR */);
}

static PFNEGLDESTROYCONTEXTPROC
epoxy_eglDestroyContext_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 30 /* eglDestroyContext */);
}

static PFNEGLDESTROYIMAGEPROC
epoxy_eglDestroyImage_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_15,
        EGL_extension_EGL_KHR_image,
        EGL_extension_EGL_KHR_image_base,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        31 /* "eglDestroyImage" */,
        32 /* "eglDestroyImageKHR" */,
        32 /* "eglDestroyImageKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[31] /* "eglDestroyImage" */,
                                providers, entrypoints);
}

static PFNEGLDESTROYIMAGEKHRPROC
epoxy_eglDestroyImageKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_image,
        EGL_extension_EGL_KHR_image_base,
        EGL_15,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        32 /* "eglDestroyImageKHR" */,
        32 /* "eglDestroyImageKHR" */,
        31 /* "eglDestroyImage" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[32] /* "eglDestroyImageKHR" */,
                                providers, entrypoints);
}

static PFNEGLDESTROYSTREAMKHRPROC
epoxy_eglDestroyStreamKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream, 33 /* eglDestroyStreamKHR */);
}

static PFNEGLDESTROYSURFACEPROC
epoxy_eglDestroySurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 34 /* eglDestroySurface */);
}

static PFNEGLDESTROYSYNCPROC
epoxy_eglDestroySync_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_15,
        EGL_extension_EGL_KHR_fence_sync,
        EGL_extension_EGL_KHR_reusable_sync,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        35 /* "eglDestroySync" */,
        36 /* "eglDestroySyncKHR" */,
        36 /* "eglDestroySyncKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[35] /* "eglDestroySync" */,
                                providers, entrypoints);
}

static PFNEGLDESTROYSYNCKHRPROC
epoxy_eglDestroySyncKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_fence_sync,
        EGL_extension_EGL_KHR_reusable_sync,
        EGL_15,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        36 /* "eglDestroySyncKHR" */,
        36 /* "eglDestroySyncKHR" */,
        35 /* "eglDestroySync" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[36] /* "eglDestroySyncKHR" */,
                                providers, entrypoints);
}

static PFNEGLDESTROYSYNCNVPROC
epoxy_eglDestroySyncNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_sync, 37 /* eglDestroySyncNV */);
}

static PFNEGLDUPNATIVEFENCEFDANDROIDPROC
epoxy_eglDupNativeFenceFDANDROID_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_ANDROID_native_fence_sync, 38 /* eglDupNativeFenceFDANDROID */);
}

static PFNEGLEXPORTDMABUFIMAGEMESAPROC
epoxy_eglExportDMABUFImageMESA_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_MESA_image_dma_buf_export, 39 /* eglExportDMABUFImageMESA */);
}

static PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC
epoxy_eglExportDMABUFImageQueryMESA_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_MESA_image_dma_buf_export, 40 /* eglExportDMABUFImageQueryMESA */);
}

static PFNEGLEXPORTDRMIMAGEMESAPROC
epoxy_eglExportDRMImageMESA_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_MESA_drm_image, 41 /* eglExportDRMImageMESA */);
}

static PFNEGLFENCENVPROC
epoxy_eglFenceNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_sync, 42 /* eglFenceNV */);
}

static PFNEGLGETCONFIGATTRIBPROC
epoxy_eglGetConfigAttrib_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 43 /* eglGetConfigAttrib */);
}

static PFNEGLGETCONFIGSPROC
epoxy_eglGetConfigs_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 44 /* eglGetConfigs */);
}

static PFNEGLGETCURRENTCONTEXTPROC
epoxy_eglGetCurrentContext_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_14, 45 /* eglGetCurrentContext */);
}

static PFNEGLGETCURRENTDISPLAYPROC
epoxy_eglGetCurrentDisplay_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 46 /* eglGetCurrentDisplay */);
}

static PFNEGLGETCURRENTSURFACEPROC
epoxy_eglGetCurrentSurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 47 /* eglGetCurrentSurface */);
}

static PFNEGLGETDISPLAYPROC
epoxy_eglGetDisplay_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 48 /* eglGetDisplay */);
}

static PFNEGLGETERRORPROC
epoxy_eglGetError_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 49 /* eglGetError */);
}

static PFNEGLGETOUTPUTLAYERSEXTPROC
epoxy_eglGetOutputLayersEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 50 /* eglGetOutputLayersEXT */);
}

static PFNEGLGETOUTPUTPORTSEXTPROC
epoxy_eglGetOutputPortsEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 51 /* eglGetOutputPortsEXT */);
}

static PFNEGLGETPLATFORMDISPLAYPROC
epoxy_eglGetPlatformDisplay_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_15, 52 /* eglGetPlatformDisplay */);
}

static PFNEGLGETPLATFORMDISPLAYEXTPROC
epoxy_eglGetPlatformDisplayEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_platform_base, 53 /* eglGetPlatformDisplayEXT */);
}

static PFNEGLGETPROCADDRESSPROC
epoxy_eglGetProcAddress_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 54 /* eglGetProcAddress */);
}

static PFNEGLGETSTREAMFILEDESCRIPTORKHRPROC
epoxy_eglGetStreamFileDescriptorKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_cross_process_fd, 55 /* eglGetStreamFileDescriptorKHR */);
}

static PFNEGLGETSYNCATTRIBPROC
epoxy_eglGetSyncAttrib_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_15, 56 /* eglGetSyncAttrib */);
}

static PFNEGLGETSYNCATTRIBKHRPROC
epoxy_eglGetSyncAttribKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_fence_sync,
        EGL_extension_EGL_KHR_reusable_sync,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        57 /* "eglGetSyncAttribKHR" */,
        57 /* "eglGetSyncAttribKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[57] /* "eglGetSyncAttribKHR" */,
                                providers, entrypoints);
}

static PFNEGLGETSYNCATTRIBNVPROC
epoxy_eglGetSyncAttribNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_sync, 58 /* eglGetSyncAttribNV */);
}

static PFNEGLGETSYSTEMTIMEFREQUENCYNVPROC
epoxy_eglGetSystemTimeFrequencyNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_system_time, 59 /* eglGetSystemTimeFrequencyNV */);
}

static PFNEGLGETSYSTEMTIMENVPROC
epoxy_eglGetSystemTimeNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_system_time, 60 /* eglGetSystemTimeNV */);
}

static PFNEGLINITIALIZEPROC
epoxy_eglInitialize_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 61 /* eglInitialize */);
}

static PFNEGLLABELOBJECTKHRPROC
epoxy_eglLabelObjectKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_debug, 62 /* eglLabelObjectKHR */);
}

static PFNEGLLOCKSURFACEKHRPROC
epoxy_eglLockSurfaceKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_lock_surface,
        EGL_extension_EGL_KHR_lock_surface3,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        63 /* "eglLockSurfaceKHR" */,
        63 /* "eglLockSurfaceKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[63] /* "eglLockSurfaceKHR" */,
                                providers, entrypoints);
}

static PFNEGLMAKECURRENTPROC
epoxy_eglMakeCurrent_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 64 /* eglMakeCurrent */);
}

static PFNEGLOUTPUTLAYERATTRIBEXTPROC
epoxy_eglOutputLayerAttribEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 65 /* eglOutputLayerAttribEXT */);
}

static PFNEGLOUTPUTPORTATTRIBEXTPROC
epoxy_eglOutputPortAttribEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 66 /* eglOutputPortAttribEXT */);
}

static PFNEGLPOSTSUBBUFFERNVPROC
epoxy_eglPostSubBufferNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_post_sub_buffer, 67 /* eglPostSubBufferNV */);
}

static PFNEGLPRESENTATIONTIMEANDROIDPROC
epoxy_eglPresentationTimeANDROID_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_ANDROID_presentation_time, 68 /* eglPresentationTimeANDROID */);
}

static PFNEGLQUERYAPIPROC
epoxy_eglQueryAPI_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_12, 69 /* eglQueryAPI */);
}

static PFNEGLQUERYCONTEXTPROC
epoxy_eglQueryContext_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 70 /* eglQueryContext */);
}

static PFNEGLQUERYDEBUGKHRPROC
epoxy_eglQueryDebugKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_debug, 71 /* eglQueryDebugKHR */);
}

static PFNEGLQUERYDEVICEATTRIBEXTPROC
epoxy_eglQueryDeviceAttribEXT_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_EXT_device_base,
        EGL_extension_EGL_EXT_device_query,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        72 /* "eglQueryDeviceAttribEXT" */,
        72 /* "eglQueryDeviceAttribEXT" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[72] /* "eglQueryDeviceAttribEXT" */,
                                providers, entrypoints);
}

static PFNEGLQUERYDEVICESTRINGEXTPROC
epoxy_eglQueryDeviceStringEXT_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_EXT_device_base,
        EGL_extension_EGL_EXT_device_query,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        73 /* "eglQueryDeviceStringEXT" */,
        73 /* "eglQueryDeviceStringEXT" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[73] /* "eglQueryDeviceStringEXT" */,
                                providers, entrypoints);
}

static PFNEGLQUERYDEVICESEXTPROC
epoxy_eglQueryDevicesEXT_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_EXT_device_base,
        EGL_extension_EGL_EXT_device_enumeration,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        74 /* "eglQueryDevicesEXT" */,
        74 /* "eglQueryDevicesEXT" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[74] /* "eglQueryDevicesEXT" */,
                                providers, entrypoints);
}

static PFNEGLQUERYDISPLAYATTRIBEXTPROC
epoxy_eglQueryDisplayAttribEXT_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_EXT_device_base,
        EGL_extension_EGL_EXT_device_query,
        EGL_extension_EGL_NV_stream_metadata,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        75 /* "eglQueryDisplayAttribEXT" */,
        75 /* "eglQueryDisplayAttribEXT" */,
        76 /* "eglQueryDisplayAttribNV" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[75] /* "eglQueryDisplayAttribEXT" */,
                                providers, entrypoints);
}

static PFNEGLQUERYDISPLAYATTRIBNVPROC
epoxy_eglQueryDisplayAttribNV_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_NV_stream_metadata,
        EGL_extension_EGL_EXT_device_base,
        EGL_extension_EGL_EXT_device_query,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        76 /* "eglQueryDisplayAttribNV" */,
        75 /* "eglQueryDisplayAttribEXT" */,
        75 /* "eglQueryDisplayAttribEXT" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[76] /* "eglQueryDisplayAttribNV" */,
                                providers, entrypoints);
}

static PFNEGLQUERYNATIVEDISPLAYNVPROC
epoxy_eglQueryNativeDisplayNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_native_query, 77 /* eglQueryNativeDisplayNV */);
}

static PFNEGLQUERYNATIVEPIXMAPNVPROC
epoxy_eglQueryNativePixmapNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_native_query, 78 /* eglQueryNativePixmapNV */);
}

static PFNEGLQUERYNATIVEWINDOWNVPROC
epoxy_eglQueryNativeWindowNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_native_query, 79 /* eglQueryNativeWindowNV */);
}

static PFNEGLQUERYOUTPUTLAYERATTRIBEXTPROC
epoxy_eglQueryOutputLayerAttribEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 80 /* eglQueryOutputLayerAttribEXT */);
}

static PFNEGLQUERYOUTPUTLAYERSTRINGEXTPROC
epoxy_eglQueryOutputLayerStringEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 81 /* eglQueryOutputLayerStringEXT */);
}

static PFNEGLQUERYOUTPUTPORTATTRIBEXTPROC
epoxy_eglQueryOutputPortAttribEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 82 /* eglQueryOutputPortAttribEXT */);
}

static PFNEGLQUERYOUTPUTPORTSTRINGEXTPROC
epoxy_eglQueryOutputPortStringEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_output_base, 83 /* eglQueryOutputPortStringEXT */);
}

static PFNEGLQUERYSTREAMKHRPROC
epoxy_eglQueryStreamKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream, 84 /* eglQueryStreamKHR */);
}

static PFNEGLQUERYSTREAMMETADATANVPROC
epoxy_eglQueryStreamMetadataNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_stream_metadata, 85 /* eglQueryStreamMetadataNV */);
}

static PFNEGLQUERYSTREAMTIMEKHRPROC
epoxy_eglQueryStreamTimeKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_fifo, 86 /* eglQueryStreamTimeKHR */);
}

static PFNEGLQUERYSTREAMU64KHRPROC
epoxy_eglQueryStreamu64KHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream, 87 /* eglQueryStreamu64KHR */);
}

static PFNEGLQUERYSTRINGPROC
epoxy_eglQueryString_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 88 /* eglQueryString */);
}

static PFNEGLQUERYSURFACEPROC
epoxy_eglQuerySurface_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 89 /* eglQuerySurface */);
}

static PFNEGLQUERYSURFACE64KHRPROC
epoxy_eglQuerySurface64KHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_lock_surface3, 90 /* eglQuerySurface64KHR */);
}

static PFNEGLQUERYSURFACEPOINTERANGLEPROC
epoxy_eglQuerySurfacePointerANGLE_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_ANGLE_query_surface_pointer, 91 /* eglQuerySurfacePointerANGLE */);
}

static PFNEGLRELEASETEXIMAGEPROC
epoxy_eglReleaseTexImage_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_11, 92 /* eglReleaseTexImage */);
}

static PFNEGLRELEASETHREADPROC
epoxy_eglReleaseThread_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_12, 93 /* eglReleaseThread */);
}

static PFNEGLSETBLOBCACHEFUNCSANDROIDPROC
epoxy_eglSetBlobCacheFuncsANDROID_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_ANDROID_blob_cache, 94 /* eglSetBlobCacheFuncsANDROID */);
}

static PFNEGLSETDAMAGEREGIONKHRPROC
epoxy_eglSetDamageRegionKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_partial_update, 95 /* eglSetDamageRegionKHR */);
}

static PFNEGLSETSTREAMMETADATANVPROC
epoxy_eglSetStreamMetadataNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_stream_metadata, 96 /* eglSetStreamMetadataNV */);
}

static PFNEGLSIGNALSYNCKHRPROC
epoxy_eglSignalSyncKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_reusable_sync, 97 /* eglSignalSyncKHR */);
}

static PFNEGLSIGNALSYNCNVPROC
epoxy_eglSignalSyncNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_sync, 98 /* eglSignalSyncNV */);
}

static PFNEGLSTREAMATTRIBKHRPROC
epoxy_eglStreamAttribKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream, 99 /* eglStreamAttribKHR */);
}

static PFNEGLSTREAMCONSUMERACQUIREKHRPROC
epoxy_eglStreamConsumerAcquireKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_consumer_gltexture, 100 /* eglStreamConsumerAcquireKHR */);
}

static PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALATTRIBSNVPROC
epoxy_eglStreamConsumerGLTextureExternalAttribsNV_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NV_stream_consumer_gltexture_yuv, 101 /* eglStreamConsumerGLTextureExternalAttribsNV */);
}

static PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALKHRPROC
epoxy_eglStreamConsumerGLTextureExternalKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_consumer_gltexture, 102 /* eglStreamConsumerGLTextureExternalKHR */);
}

static PFNEGLSTREAMCONSUMEROUTPUTEXTPROC
epoxy_eglStreamConsumerOutputEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_stream_consumer_egloutput, 103 /* eglStreamConsumerOutputEXT */);
}

static PFNEGLSTREAMCONSUMERRELEASEKHRPROC
epoxy_eglStreamConsumerReleaseKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_stream_consumer_gltexture, 104 /* eglStreamConsumerReleaseKHR */);
}

static PFNEGLSURFACEATTRIBPROC
epoxy_eglSurfaceAttrib_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_11, 105 /* eglSurfaceAttrib */);
}

static PFNEGLSWAPBUFFERSPROC
epoxy_eglSwapBuffers_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 106 /* eglSwapBuffers */);
}

static PFNEGLSWAPBUFFERSREGION2NOKPROC
epoxy_eglSwapBuffersRegion2NOK_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NOK_swap_region2, 107 /* eglSwapBuffersRegion2NOK */);
}

static PFNEGLSWAPBUFFERSREGIONNOKPROC
epoxy_eglSwapBuffersRegionNOK_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_NOK_swap_region, 108 /* eglSwapBuffersRegionNOK */);
}

static PFNEGLSWAPBUFFERSWITHDAMAGEEXTPROC
epoxy_eglSwapBuffersWithDamageEXT_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_EXT_swap_buffers_with_damage, 109 /* eglSwapBuffersWithDamageEXT */);
}

static PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC
epoxy_eglSwapBuffersWithDamageKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_swap_buffers_with_damage, 110 /* eglSwapBuffersWithDamageKHR */);
}

static PFNEGLSWAPINTERVALPROC
epoxy_eglSwapInterval_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_11, 111 /* eglSwapInterval */);
}

static PFNEGLTERMINATEPROC
epoxy_eglTerminate_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 112 /* eglTerminate */);
}

static PFNEGLUNLOCKSURFACEKHRPROC
epoxy_eglUnlockSurfaceKHR_resolver(tls_ptr tls)
{
    static const enum egl_provider providers[] = {
        EGL_extension_EGL_KHR_lock_surface,
        EGL_extension_EGL_KHR_lock_surface3,
        egl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        113 /* "eglUnlockSurfaceKHR" */,
        113 /* "eglUnlockSurfaceKHR" */,
    };
    return egl_provider_resolver(tls, egl_entrypoint_strings[113] /* "eglUnlockSurfaceKHR" */,
                                providers, entrypoints);
}

static PFNEGLWAITCLIENTPROC
epoxy_eglWaitClient_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_12, 114 /* eglWaitClient */);
}

static PFNEGLWAITGLPROC
epoxy_eglWaitGL_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 115 /* eglWaitGL */);
}

static PFNEGLWAITNATIVEPROC
epoxy_eglWaitNative_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_10, 116 /* eglWaitNative */);
}

static PFNEGLWAITSYNCPROC
epoxy_eglWaitSync_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_15, 117 /* eglWaitSync */);
}

static PFNEGLWAITSYNCKHRPROC
epoxy_eglWaitSyncKHR_resolver(tls_ptr tls)
{
    return egl_single_resolver(tls, EGL_extension_EGL_KHR_wait_sync, 118 /* eglWaitSyncKHR */);
}

GEN_THUNKS_RET(egl, EGLBoolean, eglBindAPI, (EGLenum api), (api))
GEN_THUNKS_RET(egl, EGLBoolean, eglBindTexImage, (EGLDisplay dpy, EGLSurface surface, EGLint buffer), (dpy, surface, buffer))
GEN_THUNKS_RET(egl, EGLBoolean, eglChooseConfig, (EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config), (dpy, attrib_list, configs, config_size, num_config))
GEN_THUNKS_RET(egl, EGLint, eglClientWaitSync, (EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout), (dpy, sync, flags, timeout))
GEN_THUNKS_RET(egl, EGLint, eglClientWaitSyncKHR, (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags, EGLTimeKHR timeout), (dpy, sync, flags, timeout))
GEN_THUNKS_RET(egl, EGLint, eglClientWaitSyncNV, (EGLSyncNV sync, EGLint flags, EGLTimeNV timeout), (sync, flags, timeout))
GEN_THUNKS_RET(egl, EGLBoolean, eglCopyBuffers, (EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target), (dpy, surface, target))
GEN_THUNKS_RET(egl, EGLContext, eglCreateContext, (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list), (dpy, config, share_context, attrib_list))
GEN_THUNKS_RET(egl, EGLImageKHR, eglCreateDRMImageMESA, (EGLDisplay dpy, const EGLint * attrib_list), (dpy, attrib_list))
GEN_THUNKS_RET(egl, EGLSyncNV, eglCreateFenceSyncNV, (EGLDisplay dpy, EGLenum condition, const EGLint * attrib_list), (dpy, condition, attrib_list))
GEN_THUNKS_RET(egl, EGLImage, eglCreateImage, (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLAttrib * attrib_list), (dpy, ctx, target, buffer, attrib_list))
GEN_THUNKS_RET(egl, EGLImageKHR, eglCreateImageKHR, (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint * attrib_list), (dpy, ctx, target, buffer, attrib_list))
GEN_THUNKS_RET(egl, EGLClientBuffer, eglCreateNativeClientBufferANDROID, (const EGLint * attrib_list), (attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePbufferFromClientBuffer, (EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list), (dpy, buftype, buffer, config, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePbufferSurface, (EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list), (dpy, config, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePixmapSurface, (EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list), (dpy, config, pixmap, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePixmapSurfaceHI, (EGLDisplay dpy, EGLConfig config, struct EGLClientPixmapHI * pixmap), (dpy, config, pixmap))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePlatformPixmapSurface, (EGLDisplay dpy, EGLConfig config, void * native_pixmap, const EGLAttrib * attrib_list), (dpy, config, native_pixmap, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePlatformPixmapSurfaceEXT, (EGLDisplay dpy, EGLConfig config, void * native_pixmap, const EGLint * attrib_list), (dpy, config, native_pixmap, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePlatformWindowSurface, (EGLDisplay dpy, EGLConfig config, void * native_window, const EGLAttrib * attrib_list), (dpy, config, native_window, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreatePlatformWindowSurfaceEXT, (EGLDisplay dpy, EGLConfig config, void * native_window, const EGLint * attrib_list), (dpy, config, native_window, attrib_list))
GEN_THUNKS_RET(egl, EGLStreamKHR, eglCreateStreamFromFileDescriptorKHR, (EGLDisplay dpy, EGLNativeFileDescriptorKHR file_descriptor), (dpy, file_descriptor))
GEN_THUNKS_RET(egl, EGLStreamKHR, eglCreateStreamKHR, (EGLDisplay dpy, const EGLint * attrib_list), (dpy, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreateStreamProducerSurfaceKHR, (EGLDisplay dpy, EGLConfig config, EGLStreamKHR stream, const EGLint * attrib_list), (dpy, config, stream, attrib_list))
GEN_THUNKS_RET(egl, EGLSyncKHR, eglCreateStreamSyncNV, (EGLDisplay dpy, EGLStreamKHR stream, EGLenum type, const EGLint * attrib_list), (dpy, stream, type, attrib_list))
GEN_THUNKS_RET(egl, EGLSync, eglCreateSync, (EGLDisplay dpy, EGLenum type, const EGLAttrib * attrib_list), (dpy, type, attrib_list))
GEN_THUNKS_RET(egl, EGLSyncKHR, eglCreateSync64KHR, (EGLDisplay dpy, EGLenum type, const EGLAttribKHR * attrib_list), (dpy, type, attrib_list))
GEN_THUNKS_RET(egl, EGLSyncKHR, eglCreateSyncKHR, (EGLDisplay dpy, EGLenum type, const EGLint * attrib_list), (dpy, type, attrib_list))
GEN_THUNKS_RET(egl, EGLSurface, eglCreateWindowSurface, (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list), (dpy, config, win, attrib_list))
GEN_THUNKS_RET(egl, EGLint, eglDebugMessageControlKHR, (EGLDEBUGPROCKHR callback, const EGLAttrib * attrib_list), (callback, attrib_list))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroyContext, (EGLDisplay dpy, EGLContext ctx), (dpy, ctx))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroyImage, (EGLDisplay dpy, EGLImage image), (dpy, image))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroyImageKHR, (EGLDisplay dpy, EGLImageKHR image), (dpy, image))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroyStreamKHR, (EGLDisplay dpy, EGLStreamKHR stream), (dpy, stream))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroySurface, (EGLDisplay dpy, EGLSurface surface), (dpy, surface))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroySync, (EGLDisplay dpy, EGLSync sync), (dpy, sync))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroySyncKHR, (EGLDisplay dpy, EGLSyncKHR sync), (dpy, sync))
GEN_THUNKS_RET(egl, EGLBoolean, eglDestroySyncNV, (EGLSyncNV sync), (sync))
GEN_THUNKS_RET(egl, EGLint, eglDupNativeFenceFDANDROID, (EGLDisplay dpy, EGLSyncKHR sync), (dpy, sync))
GEN_THUNKS_RET(egl, EGLBoolean, eglExportDMABUFImageMESA, (EGLDisplay dpy, EGLImageKHR image, int * fds, EGLint * strides, EGLint * offsets), (dpy, image, fds, strides, offsets))
GEN_THUNKS_RET(egl, EGLBoolean, eglExportDMABUFImageQueryMESA, (EGLDisplay dpy, EGLImageKHR image, int * fourcc, int * num_planes, EGLuint64KHR * modifiers), (dpy, image, fourcc, num_planes, modifiers))
GEN_THUNKS_RET(egl, EGLBoolean, eglExportDRMImageMESA, (EGLDisplay dpy, EGLImageKHR image, EGLint * name, EGLint * handle, EGLint * stride), (dpy, image, name, handle, stride))
GEN_THUNKS_RET(egl, EGLBoolean, eglFenceNV, (EGLSyncNV sync), (sync))
GEN_THUNKS_RET(egl, EGLBoolean, eglGetConfigAttrib, (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value), (dpy, config, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglGetConfigs, (EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config), (dpy, configs, config_size, num_config))
GEN_THUNKS_RET(egl, EGLContext, eglGetCurrentContext, (void), ())
GEN_THUNKS_RET(egl, EGLDisplay, eglGetCurrentDisplay, (void), ())
GEN_THUNKS_RET(egl, EGLSurface, eglGetCurrentSurface, (EGLint readdraw), (readdraw))
GEN_THUNKS_RET(egl, EGLDisplay, eglGetDisplay, (EGLNativeDisplayType display_id), (display_id))
GEN_THUNKS_RET(egl, EGLint, eglGetError, (void), ())
GEN_THUNKS_RET(egl, EGLBoolean, eglGetOutputLayersEXT, (EGLDisplay dpy, const EGLAttrib * attrib_list, EGLOutputLayerEXT * layers, EGLint max_layers, EGLint * num_layers), (dpy, attrib_list, layers, max_layers, num_layers))
GEN_THUNKS_RET(egl, EGLBoolean, eglGetOutputPortsEXT, (EGLDisplay dpy, const EGLAttrib * attrib_list, EGLOutputPortEXT * ports, EGLint max_ports, EGLint * num_ports), (dpy, attrib_list, ports, max_ports, num_ports))
GEN_THUNKS_RET(egl, EGLDisplay, eglGetPlatformDisplay, (EGLenum platform, void * native_display, const EGLAttrib * attrib_list), (platform, native_display, attrib_list))
GEN_THUNKS_RET(egl, EGLDisplay, eglGetPlatformDisplayEXT, (EGLenum platform, void * native_display, const EGLint * attrib_list), (platform, native_display, attrib_list))
GEN_THUNKS_RET(egl, __eglMustCastToProperFunctionPointerType, eglGetProcAddress, (const char * procname), (procname))
GEN_THUNKS_RET(egl, EGLNativeFileDescriptorKHR, eglGetStreamFileDescriptorKHR, (EGLDisplay dpy, EGLStreamKHR stream), (dpy, stream))
GEN_THUNKS_RET(egl, EGLBoolean, eglGetSyncAttrib, (EGLDisplay dpy, EGLSync sync, EGLint attribute, EGLAttrib * value), (dpy, sync, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglGetSyncAttribKHR, (EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint * value), (dpy, sync, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglGetSyncAttribNV, (EGLSyncNV sync, EGLint attribute, EGLint * value), (sync, attribute, value))
GEN_THUNKS_RET(egl, EGLuint64NV, eglGetSystemTimeFrequencyNV, (void), ())
GEN_THUNKS_RET(egl, EGLuint64NV, eglGetSystemTimeNV, (void), ())
GEN_THUNKS_RET(egl, EGLBoolean, eglInitialize, (EGLDisplay dpy, EGLint * major, EGLint * minor), (dpy, major, minor))
GEN_THUNKS_RET(egl, EGLint, eglLabelObjectKHR, (EGLDisplay display, EGLenum objectType, EGLObjectKHR object, EGLLabelKHR label), (display, objectType, object, label))
GEN_THUNKS_RET(egl, EGLBoolean, eglLockSurfaceKHR, (EGLDisplay dpy, EGLSurface surface, const EGLint * attrib_list), (dpy, surface, attrib_list))
GEN_THUNKS_RET(egl, EGLBoolean, eglMakeCurrent, (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx), (dpy, draw, read, ctx))
GEN_THUNKS_RET(egl, EGLBoolean, eglOutputLayerAttribEXT, (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib value), (dpy, layer, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglOutputPortAttribEXT, (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib value), (dpy, port, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglPostSubBufferNV, (EGLDisplay dpy, EGLSurface surface, EGLint x, EGLint y, EGLint width, EGLint height), (dpy, surface, x, y, width, height))
GEN_THUNKS_RET(egl, EGLBoolean, eglPresentationTimeANDROID, (EGLDisplay dpy, EGLSurface surface, EGLnsecsANDROID time), (dpy, surface, time))
GEN_THUNKS_RET(egl, EGLenum, eglQueryAPI, (void), ())
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryContext, (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value), (dpy, ctx, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryDebugKHR, (EGLint attribute, EGLAttrib * value), (attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryDeviceAttribEXT, (EGLDeviceEXT device, EGLint attribute, EGLAttrib * value), (device, attribute, value))
GEN_THUNKS_RET(egl, const char *, eglQueryDeviceStringEXT, (EGLDeviceEXT device, EGLint name), (device, name))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryDevicesEXT, (EGLint max_devices, EGLDeviceEXT * devices, EGLint * num_devices), (max_devices, devices, num_devices))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryDisplayAttribEXT, (EGLDisplay dpy, EGLint attribute, EGLAttrib * value), (dpy, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryDisplayAttribNV, (EGLDisplay dpy, EGLint attribute, EGLAttrib * value), (dpy, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryNativeDisplayNV, (EGLDisplay dpy, EGLNativeDisplayType * display_id), (dpy, display_id))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryNativePixmapNV, (EGLDisplay dpy, EGLSurface surf, EGLNativePixmapType * pixmap), (dpy, surf, pixmap))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryNativeWindowNV, (EGLDisplay dpy, EGLSurface surf, EGLNativeWindowType * window), (dpy, surf, window))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryOutputLayerAttribEXT, (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib * value), (dpy, layer, attribute, value))
GEN_THUNKS_RET(egl, const char *, eglQueryOutputLayerStringEXT, (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint name), (dpy, layer, name))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryOutputPortAttribEXT, (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib * value), (dpy, port, attribute, value))
GEN_THUNKS_RET(egl, const char *, eglQueryOutputPortStringEXT, (EGLDisplay dpy, EGLOutputPortEXT port, EGLint name), (dpy, port, name))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryStreamKHR, (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint * value), (dpy, stream, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryStreamMetadataNV, (EGLDisplay dpy, EGLStreamKHR stream, EGLenum name, EGLint n, EGLint offset, EGLint size, void * data), (dpy, stream, name, n, offset, size, data))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryStreamTimeKHR, (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR * value), (dpy, stream, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQueryStreamu64KHR, (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLuint64KHR * value), (dpy, stream, attribute, value))
GEN_THUNKS_RET(egl, const char *, eglQueryString, (EGLDisplay dpy, EGLint name), (dpy, name))
GEN_THUNKS_RET(egl, EGLBoolean, eglQuerySurface, (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value), (dpy, surface, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQuerySurface64KHR, (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLAttribKHR * value), (dpy, surface, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglQuerySurfacePointerANGLE, (EGLDisplay dpy, EGLSurface surface, EGLint attribute, void ** value), (dpy, surface, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglReleaseTexImage, (EGLDisplay dpy, EGLSurface surface, EGLint buffer), (dpy, surface, buffer))
GEN_THUNKS_RET(egl, EGLBoolean, eglReleaseThread, (void), ())
GEN_THUNKS(egl, eglSetBlobCacheFuncsANDROID, (EGLDisplay dpy, EGLSetBlobFuncANDROID set, EGLGetBlobFuncANDROID get), (dpy, set, get))
GEN_THUNKS_RET(egl, EGLBoolean, eglSetDamageRegionKHR, (EGLDisplay dpy, EGLSurface surface, EGLint * rects, EGLint n_rects), (dpy, surface, rects, n_rects))
GEN_THUNKS_RET(egl, EGLBoolean, eglSetStreamMetadataNV, (EGLDisplay dpy, EGLStreamKHR stream, EGLint n, EGLint offset, EGLint size, const void * data), (dpy, stream, n, offset, size, data))
GEN_THUNKS_RET(egl, EGLBoolean, eglSignalSyncKHR, (EGLDisplay dpy, EGLSyncKHR sync, EGLenum mode), (dpy, sync, mode))
GEN_THUNKS_RET(egl, EGLBoolean, eglSignalSyncNV, (EGLSyncNV sync, EGLenum mode), (sync, mode))
GEN_THUNKS_RET(egl, EGLBoolean, eglStreamAttribKHR, (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint value), (dpy, stream, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglStreamConsumerAcquireKHR, (EGLDisplay dpy, EGLStreamKHR stream), (dpy, stream))
GEN_THUNKS_RET(egl, EGLBoolean, eglStreamConsumerGLTextureExternalAttribsNV, (EGLDisplay dpy, EGLStreamKHR stream, EGLAttrib * attrib_list), (dpy, stream, attrib_list))
GEN_THUNKS_RET(egl, EGLBoolean, eglStreamConsumerGLTextureExternalKHR, (EGLDisplay dpy, EGLStreamKHR stream), (dpy, stream))
GEN_THUNKS_RET(egl, EGLBoolean, eglStreamConsumerOutputEXT, (EGLDisplay dpy, EGLStreamKHR stream, EGLOutputLayerEXT layer), (dpy, stream, layer))
GEN_THUNKS_RET(egl, EGLBoolean, eglStreamConsumerReleaseKHR, (EGLDisplay dpy, EGLStreamKHR stream), (dpy, stream))
GEN_THUNKS_RET(egl, EGLBoolean, eglSurfaceAttrib, (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value), (dpy, surface, attribute, value))
GEN_THUNKS_RET(egl, EGLBoolean, eglSwapBuffers, (EGLDisplay dpy, EGLSurface surface), (dpy, surface))
GEN_THUNKS_RET(egl, EGLBoolean, eglSwapBuffersRegion2NOK, (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint * rects), (dpy, surface, numRects, rects))
GEN_THUNKS_RET(egl, EGLBoolean, eglSwapBuffersRegionNOK, (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint * rects), (dpy, surface, numRects, rects))
GEN_THUNKS_RET(egl, EGLBoolean, eglSwapBuffersWithDamageEXT, (EGLDisplay dpy, EGLSurface surface, EGLint * rects, EGLint n_rects), (dpy, surface, rects, n_rects))
GEN_THUNKS_RET(egl, EGLBoolean, eglSwapBuffersWithDamageKHR, (EGLDisplay dpy, EGLSurface surface, EGLint * rects, EGLint n_rects), (dpy, surface, rects, n_rects))
GEN_THUNKS_RET(egl, EGLBoolean, eglSwapInterval, (EGLDisplay dpy, EGLint interval), (dpy, interval))
GEN_THUNKS_RET(egl, EGLBoolean, eglTerminate, (EGLDisplay dpy), (dpy))
GEN_THUNKS_RET(egl, EGLBoolean, eglUnlockSurfaceKHR, (EGLDisplay dpy, EGLSurface surface), (dpy, surface))
GEN_THUNKS_RET(egl, EGLBoolean, eglWaitClient, (void), ())
GEN_THUNKS_RET(egl, EGLBoolean, eglWaitGL, (void), ())
GEN_THUNKS_RET(egl, EGLBoolean, eglWaitNative, (EGLint engine), (engine))
GEN_THUNKS_RET(egl, EGLBoolean, eglWaitSync, (EGLDisplay dpy, EGLSync sync, EGLint flags), (dpy, sync, flags))
GEN_THUNKS_RET(egl, EGLint, eglWaitSyncKHR, (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags), (dpy, sync, flags))

static struct egl_dispatch_table egl_resolver_table = {
    .eglBindAPI = epoxy_eglBindAPI_dispatch_table_rewrite_ptr,
    .eglBindTexImage = epoxy_eglBindTexImage_dispatch_table_rewrite_ptr,
    .eglChooseConfig = epoxy_eglChooseConfig_dispatch_table_rewrite_ptr,
    .eglClientWaitSync = epoxy_eglClientWaitSync_dispatch_table_rewrite_ptr,
    .eglClientWaitSyncKHR = epoxy_eglClientWaitSyncKHR_dispatch_table_rewrite_ptr,
    .eglClientWaitSyncNV = epoxy_eglClientWaitSyncNV_dispatch_table_rewrite_ptr,
    .eglCopyBuffers = epoxy_eglCopyBuffers_dispatch_table_rewrite_ptr,
    .eglCreateContext = epoxy_eglCreateContext_dispatch_table_rewrite_ptr,
    .eglCreateDRMImageMESA = epoxy_eglCreateDRMImageMESA_dispatch_table_rewrite_ptr,
    .eglCreateFenceSyncNV = epoxy_eglCreateFenceSyncNV_dispatch_table_rewrite_ptr,
    .eglCreateImage = epoxy_eglCreateImage_dispatch_table_rewrite_ptr,
    .eglCreateImageKHR = epoxy_eglCreateImageKHR_dispatch_table_rewrite_ptr,
    .eglCreateNativeClientBufferANDROID = epoxy_eglCreateNativeClientBufferANDROID_dispatch_table_rewrite_ptr,
    .eglCreatePbufferFromClientBuffer = epoxy_eglCreatePbufferFromClientBuffer_dispatch_table_rewrite_ptr,
    .eglCreatePbufferSurface = epoxy_eglCreatePbufferSurface_dispatch_table_rewrite_ptr,
    .eglCreatePixmapSurface = epoxy_eglCreatePixmapSurface_dispatch_table_rewrite_ptr,
    .eglCreatePixmapSurfaceHI = epoxy_eglCreatePixmapSurfaceHI_dispatch_table_rewrite_ptr,
    .eglCreatePlatformPixmapSurface = epoxy_eglCreatePlatformPixmapSurface_dispatch_table_rewrite_ptr,
    .eglCreatePlatformPixmapSurfaceEXT = epoxy_eglCreatePlatformPixmapSurfaceEXT_dispatch_table_rewrite_ptr,
    .eglCreatePlatformWindowSurface = epoxy_eglCreatePlatformWindowSurface_dispatch_table_rewrite_ptr,
    .eglCreatePlatformWindowSurfaceEXT = epoxy_eglCreatePlatformWindowSurfaceEXT_dispatch_table_rewrite_ptr,
    .eglCreateStreamFromFileDescriptorKHR = epoxy_eglCreateStreamFromFileDescriptorKHR_dispatch_table_rewrite_ptr,
    .eglCreateStreamKHR = epoxy_eglCreateStreamKHR_dispatch_table_rewrite_ptr,
    .eglCreateStreamProducerSurfaceKHR = epoxy_eglCreateStreamProducerSurfaceKHR_dispatch_table_rewrite_ptr,
    .eglCreateStreamSyncNV = epoxy_eglCreateStreamSyncNV_dispatch_table_rewrite_ptr,
    .eglCreateSync = epoxy_eglCreateSync_dispatch_table_rewrite_ptr,
    .eglCreateSync64KHR = epoxy_eglCreateSync64KHR_dispatch_table_rewrite_ptr,
    .eglCreateSyncKHR = epoxy_eglCreateSyncKHR_dispatch_table_rewrite_ptr,
    .eglCreateWindowSurface = epoxy_eglCreateWindowSurface_dispatch_table_rewrite_ptr,
    .eglDebugMessageControlKHR = epoxy_eglDebugMessageControlKHR_dispatch_table_rewrite_ptr,
    .eglDestroyContext = epoxy_eglDestroyContext_dispatch_table_rewrite_ptr,
    .eglDestroyImage = epoxy_eglDestroyImage_dispatch_table_rewrite_ptr,
    .eglDestroyImageKHR = epoxy_eglDestroyImageKHR_dispatch_table_rewrite_ptr,
    .eglDestroyStreamKHR = epoxy_eglDestroyStreamKHR_dispatch_table_rewrite_ptr,
    .eglDestroySurface = epoxy_eglDestroySurface_dispatch_table_rewrite_ptr,
    .eglDestroySync = epoxy_eglDestroySync_dispatch_table_rewrite_ptr,
    .eglDestroySyncKHR = epoxy_eglDestroySyncKHR_dispatch_table_rewrite_ptr,
    .eglDestroySyncNV = epoxy_eglDestroySyncNV_dispatch_table_rewrite_ptr,
    .eglDupNativeFenceFDANDROID = epoxy_eglDupNativeFenceFDANDROID_dispatch_table_rewrite_ptr,
    .eglExportDMABUFImageMESA = epoxy_eglExportDMABUFImageMESA_dispatch_table_rewrite_ptr,
    .eglExportDMABUFImageQueryMESA = epoxy_eglExportDMABUFImageQueryMESA_dispatch_table_rewrite_ptr,
    .eglExportDRMImageMESA = epoxy_eglExportDRMImageMESA_dispatch_table_rewrite_ptr,
    .eglFenceNV = epoxy_eglFenceNV_dispatch_table_rewrite_ptr,
    .eglGetConfigAttrib = epoxy_eglGetConfigAttrib_dispatch_table_rewrite_ptr,
    .eglGetConfigs = epoxy_eglGetConfigs_dispatch_table_rewrite_ptr,
    .eglGetCurrentContext = epoxy_eglGetCurrentContext_dispatch_table_rewrite_ptr,
    .eglGetCurrentDisplay = epoxy_eglGetCurrentDisplay_dispatch_table_rewrite_ptr,
    .eglGetCurrentSurface = epoxy_eglGetCurrentSurface_dispatch_table_rewrite_ptr,
    .eglGetDisplay = epoxy_eglGetDisplay_dispatch_table_rewrite_ptr,
    .eglGetError = epoxy_eglGetError_dispatch_table_rewrite_ptr,
    .eglGetOutputLayersEXT = epoxy_eglGetOutputLayersEXT_dispatch_table_rewrite_ptr,
    .eglGetOutputPortsEXT = epoxy_eglGetOutputPortsEXT_dispatch_table_rewrite_ptr,
    .eglGetPlatformDisplay = epoxy_eglGetPlatformDisplay_dispatch_table_rewrite_ptr,
    .eglGetPlatformDisplayEXT = epoxy_eglGetPlatformDisplayEXT_dispatch_table_rewrite_ptr,
    .eglGetProcAddress = epoxy_eglGetProcAddress_dispatch_table_rewrite_ptr,
    .eglGetStreamFileDescriptorKHR = epoxy_eglGetStreamFileDescriptorKHR_dispatch_table_rewrite_ptr,
    .eglGetSyncAttrib = epoxy_eglGetSyncAttrib_dispatch_table_rewrite_ptr,
    .eglGetSyncAttribKHR = epoxy_eglGetSyncAttribKHR_dispatch_table_rewrite_ptr,
    .eglGetSyncAttribNV = epoxy_eglGetSyncAttribNV_dispatch_table_rewrite_ptr,
    .eglGetSystemTimeFrequencyNV = epoxy_eglGetSystemTimeFrequencyNV_dispatch_table_rewrite_ptr,
    .eglGetSystemTimeNV = epoxy_eglGetSystemTimeNV_dispatch_table_rewrite_ptr,
    .eglInitialize = epoxy_eglInitialize_dispatch_table_rewrite_ptr,
    .eglLabelObjectKHR = epoxy_eglLabelObjectKHR_dispatch_table_rewrite_ptr,
    .eglLockSurfaceKHR = epoxy_eglLockSurfaceKHR_dispatch_table_rewrite_ptr,
    .eglMakeCurrent = epoxy_eglMakeCurrent_dispatch_table_rewrite_ptr,
    .eglOutputLayerAttribEXT = epoxy_eglOutputLayerAttribEXT_dispatch_table_rewrite_ptr,
    .eglOutputPortAttribEXT = epoxy_eglOutputPortAttribEXT_dispatch_table_rewrite_ptr,
    .eglPostSubBufferNV = epoxy_eglPostSubBufferNV_dispatch_table_rewrite_ptr,
    .eglPresentationTimeANDROID = epoxy_eglPresentationTimeANDROID_dispatch_table_rewrite_ptr,
    .eglQueryAPI = epoxy_eglQueryAPI_dispatch_table_rewrite_ptr,
    .eglQueryContext = epoxy_eglQueryContext_dispatch_table_rewrite_ptr,
    .eglQueryDebugKHR = epoxy_eglQueryDebugKHR_dispatch_table_rewrite_ptr,
    .eglQueryDeviceAttribEXT = epoxy_eglQueryDeviceAttribEXT_dispatch_table_rewrite_ptr,
    .eglQueryDeviceStringEXT = epoxy_eglQueryDeviceStringEXT_dispatch_table_rewrite_ptr,
    .eglQueryDevicesEXT = epoxy_eglQueryDevicesEXT_dispatch_table_rewrite_ptr,
    .eglQueryDisplayAttribEXT = epoxy_eglQueryDisplayAttribEXT_dispatch_table_rewrite_ptr,
    .eglQueryDisplayAttribNV = epoxy_eglQueryDisplayAttribNV_dispatch_table_rewrite_ptr,
    .eglQueryNativeDisplayNV = epoxy_eglQueryNativeDisplayNV_dispatch_table_rewrite_ptr,
    .eglQueryNativePixmapNV = epoxy_eglQueryNativePixmapNV_dispatch_table_rewrite_ptr,
    .eglQueryNativeWindowNV = epoxy_eglQueryNativeWindowNV_dispatch_table_rewrite_ptr,
    .eglQueryOutputLayerAttribEXT = epoxy_eglQueryOutputLayerAttribEXT_dispatch_table_rewrite_ptr,
    .eglQueryOutputLayerStringEXT = epoxy_eglQueryOutputLayerStringEXT_dispatch_table_rewrite_ptr,
    .eglQueryOutputPortAttribEXT = epoxy_eglQueryOutputPortAttribEXT_dispatch_table_rewrite_ptr,
    .eglQueryOutputPortStringEXT = epoxy_eglQueryOutputPortStringEXT_dispatch_table_rewrite_ptr,
    .eglQueryStreamKHR = epoxy_eglQueryStreamKHR_dispatch_table_rewrite_ptr,
    .eglQueryStreamMetadataNV = epoxy_eglQueryStreamMetadataNV_dispatch_table_rewrite_ptr,
    .eglQueryStreamTimeKHR = epoxy_eglQueryStreamTimeKHR_dispatch_table_rewrite_ptr,
    .eglQueryStreamu64KHR = epoxy_eglQueryStreamu64KHR_dispatch_table_rewrite_ptr,
    .eglQueryString = epoxy_eglQueryString_dispatch_table_rewrite_ptr,
    .eglQuerySurface = epoxy_eglQuerySurface_dispatch_table_rewrite_ptr,
    .eglQuerySurface64KHR = epoxy_eglQuerySurface64KHR_dispatch_table_rewrite_ptr,
    .eglQuerySurfacePointerANGLE = epoxy_eglQuerySurfacePointerANGLE_dispatch_table_rewrite_ptr,
    .eglReleaseTexImage = epoxy_eglReleaseTexImage_dispatch_table_rewrite_ptr,
    .eglReleaseThread = epoxy_eglReleaseThread_dispatch_table_rewrite_ptr,
    .eglSetBlobCacheFuncsANDROID = epoxy_eglSetBlobCacheFuncsANDROID_dispatch_table_rewrite_ptr,
    .eglSetDamageRegionKHR = epoxy_eglSetDamageRegionKHR_dispatch_table_rewrite_ptr,
    .eglSetStreamMetadataNV = epoxy_eglSetStreamMetadataNV_dispatch_table_rewrite_ptr,
    .eglSignalSyncKHR = epoxy_eglSignalSyncKHR_dispatch_table_rewrite_ptr,
    .eglSignalSyncNV = epoxy_eglSignalSyncNV_dispatch_table_rewrite_ptr,
    .eglStreamAttribKHR = epoxy_eglStreamAttribKHR_dispatch_table_rewrite_ptr,
    .eglStreamConsumerAcquireKHR = epoxy_eglStreamConsumerAcquireKHR_dispatch_table_rewrite_ptr,
    .eglStreamConsumerGLTextureExternalAttribsNV = epoxy_eglStreamConsumerGLTextureExternalAttribsNV_dispatch_table_rewrite_ptr,
    .eglStreamConsumerGLTextureExternalKHR = epoxy_eglStreamConsumerGLTextureExternalKHR_dispatch_table_rewrite_ptr,
    .eglStreamConsumerOutputEXT = epoxy_eglStreamConsumerOutputEXT_dispatch_table_rewrite_ptr,
    .eglStreamConsumerReleaseKHR = epoxy_eglStreamConsumerReleaseKHR_dispatch_table_rewrite_ptr,
    .eglSurfaceAttrib = epoxy_eglSurfaceAttrib_dispatch_table_rewrite_ptr,
    .eglSwapBuffers = epoxy_eglSwapBuffers_dispatch_table_rewrite_ptr,
    .eglSwapBuffersRegion2NOK = epoxy_eglSwapBuffersRegion2NOK_dispatch_table_rewrite_ptr,
    .eglSwapBuffersRegionNOK = epoxy_eglSwapBuffersRegionNOK_dispatch_table_rewrite_ptr,
    .eglSwapBuffersWithDamageEXT = epoxy_eglSwapBuffersWithDamageEXT_dispatch_table_rewrite_ptr,
    .eglSwapBuffersWithDamageKHR = epoxy_eglSwapBuffersWithDamageKHR_dispatch_table_rewrite_ptr,
    .eglSwapInterval = epoxy_eglSwapInterval_dispatch_table_rewrite_ptr,
    .eglTerminate = epoxy_eglTerminate_dispatch_table_rewrite_ptr,
    .eglUnlockSurfaceKHR = epoxy_eglUnlockSurfaceKHR_dispatch_table_rewrite_ptr,
    .eglWaitClient = epoxy_eglWaitClient_dispatch_table_rewrite_ptr,
    .eglWaitGL = epoxy_eglWaitGL_dispatch_table_rewrite_ptr,
    .eglWaitNative = epoxy_eglWaitNative_dispatch_table_rewrite_ptr,
    .eglWaitSync = epoxy_eglWaitSync_dispatch_table_rewrite_ptr,
    .eglWaitSyncKHR = epoxy_eglWaitSyncKHR_dispatch_table_rewrite_ptr,
};
#endif /* PLATFORM_HAS_EGL */
