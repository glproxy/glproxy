/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#include "dispatch_common.h"
#if PLATFORM_HAS_WGL

static void *wgl_provider_resolver(tls_ptr tls, const char *name,
                                   const enum wgl_provider *providers,
                                   const uint16_t *entrypoints)
{
    int i;
    for (i = 0; providers[i] != wgl_provider_terminator; i++) {
        switch (providers[i]) {
        case WGL_10:
            if (true)
                return epoxy_wgl_dlsym(tls, wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_3DL_stereo_control:
            if (epoxy_conservative_has_wgl_extension("WGL_3DL_stereo_control"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_AMD_gpu_association:
            if (epoxy_conservative_has_wgl_extension("WGL_AMD_gpu_association"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_buffer_region:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_buffer_region"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_create_context:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_create_context"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_extensions_string:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_extensions_string"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_make_current_read:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_make_current_read"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_pbuffer:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_pbuffer"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_pixel_format:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_pixel_format"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_ARB_render_texture:
            if (epoxy_conservative_has_wgl_extension("WGL_ARB_render_texture"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_EXT_display_color_table:
            if (epoxy_conservative_has_wgl_extension("WGL_EXT_display_color_table"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_EXT_extensions_string:
            if (epoxy_conservative_has_wgl_extension("WGL_EXT_extensions_string"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_EXT_make_current_read:
            if (epoxy_conservative_has_wgl_extension("WGL_EXT_make_current_read"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_EXT_pbuffer:
            if (epoxy_conservative_has_wgl_extension("WGL_EXT_pbuffer"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_EXT_pixel_format:
            if (epoxy_conservative_has_wgl_extension("WGL_EXT_pixel_format"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_EXT_swap_control:
            if (epoxy_conservative_has_wgl_extension("WGL_EXT_swap_control"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_I3D_digital_video_control:
            if (epoxy_conservative_has_wgl_extension("WGL_I3D_digital_video_control"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_I3D_gamma:
            if (epoxy_conservative_has_wgl_extension("WGL_I3D_gamma"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_I3D_genlock:
            if (epoxy_conservative_has_wgl_extension("WGL_I3D_genlock"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_I3D_image_buffer:
            if (epoxy_conservative_has_wgl_extension("WGL_I3D_image_buffer"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_I3D_swap_frame_lock:
            if (epoxy_conservative_has_wgl_extension("WGL_I3D_swap_frame_lock"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_I3D_swap_frame_usage:
            if (epoxy_conservative_has_wgl_extension("WGL_I3D_swap_frame_usage"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_DX_interop:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_DX_interop"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_copy_image:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_copy_image"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_delay_before_swap:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_delay_before_swap"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_gpu_affinity:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_gpu_affinity"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_present_video:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_present_video"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_swap_group:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_swap_group"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_vertex_array_range:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_vertex_array_range"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_video_capture:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_video_capture"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_NV_video_output:
            if (epoxy_conservative_has_wgl_extension("WGL_NV_video_output"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case WGL_extension_WGL_OML_sync_control:
            if (epoxy_conservative_has_wgl_extension("WGL_OML_sync_control"))
                return wglGetProcAddress(wgl_entrypoint_strings[entrypoints[i]]);
            break;
        case wgl_provider_terminator:
            abort(); /* Not reached */
        }
    }

    fprintf(stderr, "No provider of %s found.  Requires one of:\n", name);
    for (i = 0; providers[i] != wgl_provider_terminator; i++) {
        fprintf(stderr, "    %s\n", wgl_enum_string + wgl_enum_string_offsets[providers[i]]);
    }
    if (providers[0] == wgl_provider_terminator) {
        fprintf(stderr, "    No known providers.  This is likely a bug "
                        "in libepoxy code generation\n");
    }
    abort();
}

EPOXY_NOINLINE static void *
wgl_single_resolver(tls_ptr tls, enum wgl_provider provider, uint16_t entrypoint_offset);

static void *
wgl_single_resolver(tls_ptr tls, enum wgl_provider provider, uint16_t entrypoint_offset)
{
    enum wgl_provider providers[] = {
        provider,
        wgl_provider_terminator
    };
    return wgl_provider_resolver(tls, wgl_entrypoint_strings[entrypoint_offset],
                                providers, &entrypoint_offset);
}

static PFNWGLALLOCATEMEMORYNVPROC
epoxy_wglAllocateMemoryNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_vertex_array_range, 0 /* wglAllocateMemoryNV */);
}

static PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC
epoxy_wglAssociateImageBufferEventsI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_image_buffer, 1 /* wglAssociateImageBufferEventsI3D */);
}

static PFNWGLBEGINFRAMETRACKINGI3DPROC
epoxy_wglBeginFrameTrackingI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_usage, 2 /* wglBeginFrameTrackingI3D */);
}

static PFNWGLBINDDISPLAYCOLORTABLEEXTPROC
epoxy_wglBindDisplayColorTableEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_display_color_table, 3 /* wglBindDisplayColorTableEXT */);
}

static PFNWGLBINDSWAPBARRIERNVPROC
epoxy_wglBindSwapBarrierNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_swap_group, 4 /* wglBindSwapBarrierNV */);
}

static PFNWGLBINDTEXIMAGEARBPROC
epoxy_wglBindTexImageARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_render_texture, 5 /* wglBindTexImageARB */);
}

static PFNWGLBINDVIDEOCAPTUREDEVICENVPROC
epoxy_wglBindVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_capture, 6 /* wglBindVideoCaptureDeviceNV */);
}

static PFNWGLBINDVIDEODEVICENVPROC
epoxy_wglBindVideoDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_present_video, 7 /* wglBindVideoDeviceNV */);
}

static PFNWGLBINDVIDEOIMAGENVPROC
epoxy_wglBindVideoImageNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_output, 8 /* wglBindVideoImageNV */);
}

static PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC
epoxy_wglBlitContextFramebufferAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 9 /* wglBlitContextFramebufferAMD */);
}

static PFNWGLCHOOSEPIXELFORMATARBPROC
epoxy_wglChoosePixelFormatARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pixel_format, 10 /* wglChoosePixelFormatARB */);
}

static PFNWGLCHOOSEPIXELFORMATEXTPROC
epoxy_wglChoosePixelFormatEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pixel_format, 11 /* wglChoosePixelFormatEXT */);
}

static PFNWGLCOPYCONTEXTPROC
epoxy_wglCopyContext_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 12 /* wglCopyContext */);
}

static PFNWGLCOPYIMAGESUBDATANVPROC
epoxy_wglCopyImageSubDataNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_copy_image, 13 /* wglCopyImageSubDataNV */);
}

static PFNWGLCREATEAFFINITYDCNVPROC
epoxy_wglCreateAffinityDCNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_gpu_affinity, 14 /* wglCreateAffinityDCNV */);
}

static PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC
epoxy_wglCreateAssociatedContextAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 15 /* wglCreateAssociatedContextAMD */);
}

static PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC
epoxy_wglCreateAssociatedContextAttribsAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 16 /* wglCreateAssociatedContextAttribsAMD */);
}

static PFNWGLCREATEBUFFERREGIONARBPROC
epoxy_wglCreateBufferRegionARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_buffer_region, 17 /* wglCreateBufferRegionARB */);
}

static PFNWGLCREATECONTEXTPROC
epoxy_wglCreateContext_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 18 /* wglCreateContext */);
}

static PFNWGLCREATECONTEXTATTRIBSARBPROC
epoxy_wglCreateContextAttribsARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_create_context, 19 /* wglCreateContextAttribsARB */);
}

static PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC
epoxy_wglCreateDisplayColorTableEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_display_color_table, 20 /* wglCreateDisplayColorTableEXT */);
}

static PFNWGLCREATEIMAGEBUFFERI3DPROC
epoxy_wglCreateImageBufferI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_image_buffer, 21 /* wglCreateImageBufferI3D */);
}

static PFNWGLCREATELAYERCONTEXTPROC
epoxy_wglCreateLayerContext_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 22 /* wglCreateLayerContext */);
}

static PFNWGLCREATEPBUFFERARBPROC
epoxy_wglCreatePbufferARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pbuffer, 23 /* wglCreatePbufferARB */);
}

static PFNWGLCREATEPBUFFEREXTPROC
epoxy_wglCreatePbufferEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pbuffer, 24 /* wglCreatePbufferEXT */);
}

static PFNWGLDXCLOSEDEVICENVPROC
epoxy_wglDXCloseDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 25 /* wglDXCloseDeviceNV */);
}

static PFNWGLDXLOCKOBJECTSNVPROC
epoxy_wglDXLockObjectsNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 26 /* wglDXLockObjectsNV */);
}

static PFNWGLDXOBJECTACCESSNVPROC
epoxy_wglDXObjectAccessNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 27 /* wglDXObjectAccessNV */);
}

static PFNWGLDXOPENDEVICENVPROC
epoxy_wglDXOpenDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 28 /* wglDXOpenDeviceNV */);
}

static PFNWGLDXREGISTEROBJECTNVPROC
epoxy_wglDXRegisterObjectNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 29 /* wglDXRegisterObjectNV */);
}

static PFNWGLDXSETRESOURCESHAREHANDLENVPROC
epoxy_wglDXSetResourceShareHandleNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 30 /* wglDXSetResourceShareHandleNV */);
}

static PFNWGLDXUNLOCKOBJECTSNVPROC
epoxy_wglDXUnlockObjectsNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 31 /* wglDXUnlockObjectsNV */);
}

static PFNWGLDXUNREGISTEROBJECTNVPROC
epoxy_wglDXUnregisterObjectNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_DX_interop, 32 /* wglDXUnregisterObjectNV */);
}

static PFNWGLDELAYBEFORESWAPNVPROC
epoxy_wglDelayBeforeSwapNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_delay_before_swap, 33 /* wglDelayBeforeSwapNV */);
}

static PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC
epoxy_wglDeleteAssociatedContextAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 34 /* wglDeleteAssociatedContextAMD */);
}

static PFNWGLDELETEBUFFERREGIONARBPROC
epoxy_wglDeleteBufferRegionARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_buffer_region, 35 /* wglDeleteBufferRegionARB */);
}

static PFNWGLDELETECONTEXTPROC
epoxy_wglDeleteContext_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 36 /* wglDeleteContext */);
}

static PFNWGLDELETEDCNVPROC
epoxy_wglDeleteDCNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_gpu_affinity, 37 /* wglDeleteDCNV */);
}

static PFNWGLDESCRIBELAYERPLANEPROC
epoxy_wglDescribeLayerPlane_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 38 /* wglDescribeLayerPlane */);
}

static PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC
epoxy_wglDestroyDisplayColorTableEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_display_color_table, 39 /* wglDestroyDisplayColorTableEXT */);
}

static PFNWGLDESTROYIMAGEBUFFERI3DPROC
epoxy_wglDestroyImageBufferI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_image_buffer, 40 /* wglDestroyImageBufferI3D */);
}

static PFNWGLDESTROYPBUFFERARBPROC
epoxy_wglDestroyPbufferARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pbuffer, 41 /* wglDestroyPbufferARB */);
}

static PFNWGLDESTROYPBUFFEREXTPROC
epoxy_wglDestroyPbufferEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pbuffer, 42 /* wglDestroyPbufferEXT */);
}

static PFNWGLDISABLEFRAMELOCKI3DPROC
epoxy_wglDisableFrameLockI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_lock, 43 /* wglDisableFrameLockI3D */);
}

static PFNWGLDISABLEGENLOCKI3DPROC
epoxy_wglDisableGenlockI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 44 /* wglDisableGenlockI3D */);
}

static PFNWGLENABLEFRAMELOCKI3DPROC
epoxy_wglEnableFrameLockI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_lock, 45 /* wglEnableFrameLockI3D */);
}

static PFNWGLENABLEGENLOCKI3DPROC
epoxy_wglEnableGenlockI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 46 /* wglEnableGenlockI3D */);
}

static PFNWGLENDFRAMETRACKINGI3DPROC
epoxy_wglEndFrameTrackingI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_usage, 47 /* wglEndFrameTrackingI3D */);
}

static PFNWGLENUMGPUDEVICESNVPROC
epoxy_wglEnumGpuDevicesNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_gpu_affinity, 48 /* wglEnumGpuDevicesNV */);
}

static PFNWGLENUMGPUSFROMAFFINITYDCNVPROC
epoxy_wglEnumGpusFromAffinityDCNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_gpu_affinity, 49 /* wglEnumGpusFromAffinityDCNV */);
}

static PFNWGLENUMGPUSNVPROC
epoxy_wglEnumGpusNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_gpu_affinity, 50 /* wglEnumGpusNV */);
}

static PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC
epoxy_wglEnumerateVideoCaptureDevicesNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_capture, 51 /* wglEnumerateVideoCaptureDevicesNV */);
}

static PFNWGLENUMERATEVIDEODEVICESNVPROC
epoxy_wglEnumerateVideoDevicesNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_present_video, 52 /* wglEnumerateVideoDevicesNV */);
}

static PFNWGLFREEMEMORYNVPROC
epoxy_wglFreeMemoryNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_vertex_array_range, 53 /* wglFreeMemoryNV */);
}

static PFNWGLGENLOCKSAMPLERATEI3DPROC
epoxy_wglGenlockSampleRateI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 54 /* wglGenlockSampleRateI3D */);
}

static PFNWGLGENLOCKSOURCEDELAYI3DPROC
epoxy_wglGenlockSourceDelayI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 55 /* wglGenlockSourceDelayI3D */);
}

static PFNWGLGENLOCKSOURCEEDGEI3DPROC
epoxy_wglGenlockSourceEdgeI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 56 /* wglGenlockSourceEdgeI3D */);
}

static PFNWGLGENLOCKSOURCEI3DPROC
epoxy_wglGenlockSourceI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 57 /* wglGenlockSourceI3D */);
}

static PFNWGLGETCONTEXTGPUIDAMDPROC
epoxy_wglGetContextGPUIDAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 58 /* wglGetContextGPUIDAMD */);
}

static PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC
epoxy_wglGetCurrentAssociatedContextAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 59 /* wglGetCurrentAssociatedContextAMD */);
}

static PFNWGLGETCURRENTCONTEXTPROC
epoxy_wglGetCurrentContext_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 60 /* wglGetCurrentContext */);
}

static PFNWGLGETCURRENTDCPROC
epoxy_wglGetCurrentDC_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 61 /* wglGetCurrentDC */);
}

static PFNWGLGETCURRENTREADDCARBPROC
epoxy_wglGetCurrentReadDCARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_make_current_read, 62 /* wglGetCurrentReadDCARB */);
}

static PFNWGLGETCURRENTREADDCEXTPROC
epoxy_wglGetCurrentReadDCEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_make_current_read, 63 /* wglGetCurrentReadDCEXT */);
}

static PFNWGLGETDEFAULTPROCADDRESSPROC
epoxy_wglGetDefaultProcAddress_resolver(tls_ptr tls)
{
    static const enum wgl_provider providers[] = {
        wgl_provider_terminator
    };
    static const uint16_t entrypoints[] = {
        0 /* None */,
    };
    return wgl_provider_resolver(tls, wgl_entrypoint_strings[64] /* "wglGetDefaultProcAddress" */,
                                providers, entrypoints);
}

static PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC
epoxy_wglGetDigitalVideoParametersI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_digital_video_control, 65 /* wglGetDigitalVideoParametersI3D */);
}

static PFNWGLGETEXTENSIONSSTRINGARBPROC
epoxy_wglGetExtensionsStringARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_extensions_string, 66 /* wglGetExtensionsStringARB */);
}

static PFNWGLGETEXTENSIONSSTRINGEXTPROC
epoxy_wglGetExtensionsStringEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_extensions_string, 67 /* wglGetExtensionsStringEXT */);
}

static PFNWGLGETFRAMEUSAGEI3DPROC
epoxy_wglGetFrameUsageI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_usage, 68 /* wglGetFrameUsageI3D */);
}

static PFNWGLGETGPUIDSAMDPROC
epoxy_wglGetGPUIDsAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 69 /* wglGetGPUIDsAMD */);
}

static PFNWGLGETGPUINFOAMDPROC
epoxy_wglGetGPUInfoAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 70 /* wglGetGPUInfoAMD */);
}

static PFNWGLGETGAMMATABLEI3DPROC
epoxy_wglGetGammaTableI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_gamma, 71 /* wglGetGammaTableI3D */);
}

static PFNWGLGETGAMMATABLEPARAMETERSI3DPROC
epoxy_wglGetGammaTableParametersI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_gamma, 72 /* wglGetGammaTableParametersI3D */);
}

static PFNWGLGETGENLOCKSAMPLERATEI3DPROC
epoxy_wglGetGenlockSampleRateI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 73 /* wglGetGenlockSampleRateI3D */);
}

static PFNWGLGETGENLOCKSOURCEDELAYI3DPROC
epoxy_wglGetGenlockSourceDelayI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 74 /* wglGetGenlockSourceDelayI3D */);
}

static PFNWGLGETGENLOCKSOURCEEDGEI3DPROC
epoxy_wglGetGenlockSourceEdgeI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 75 /* wglGetGenlockSourceEdgeI3D */);
}

static PFNWGLGETGENLOCKSOURCEI3DPROC
epoxy_wglGetGenlockSourceI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 76 /* wglGetGenlockSourceI3D */);
}

static PFNWGLGETLAYERPALETTEENTRIESPROC
epoxy_wglGetLayerPaletteEntries_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 77 /* wglGetLayerPaletteEntries */);
}

static PFNWGLGETMSCRATEOMLPROC
epoxy_wglGetMscRateOML_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_OML_sync_control, 78 /* wglGetMscRateOML */);
}

static PFNWGLGETPBUFFERDCARBPROC
epoxy_wglGetPbufferDCARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pbuffer, 79 /* wglGetPbufferDCARB */);
}

static PFNWGLGETPBUFFERDCEXTPROC
epoxy_wglGetPbufferDCEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pbuffer, 80 /* wglGetPbufferDCEXT */);
}

static PFNWGLGETPIXELFORMATATTRIBFVARBPROC
epoxy_wglGetPixelFormatAttribfvARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pixel_format, 81 /* wglGetPixelFormatAttribfvARB */);
}

static PFNWGLGETPIXELFORMATATTRIBFVEXTPROC
epoxy_wglGetPixelFormatAttribfvEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pixel_format, 82 /* wglGetPixelFormatAttribfvEXT */);
}

static PFNWGLGETPIXELFORMATATTRIBIVARBPROC
epoxy_wglGetPixelFormatAttribivARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pixel_format, 83 /* wglGetPixelFormatAttribivARB */);
}

static PFNWGLGETPIXELFORMATATTRIBIVEXTPROC
epoxy_wglGetPixelFormatAttribivEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pixel_format, 84 /* wglGetPixelFormatAttribivEXT */);
}

static PFNWGLGETPROCADDRESSPROC
epoxy_wglGetProcAddress_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 85 /* wglGetProcAddress */);
}

static PFNWGLGETSWAPINTERVALEXTPROC
epoxy_wglGetSwapIntervalEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_swap_control, 86 /* wglGetSwapIntervalEXT */);
}

static PFNWGLGETSYNCVALUESOMLPROC
epoxy_wglGetSyncValuesOML_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_OML_sync_control, 87 /* wglGetSyncValuesOML */);
}

static PFNWGLGETVIDEODEVICENVPROC
epoxy_wglGetVideoDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_output, 88 /* wglGetVideoDeviceNV */);
}

static PFNWGLGETVIDEOINFONVPROC
epoxy_wglGetVideoInfoNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_output, 89 /* wglGetVideoInfoNV */);
}

static PFNWGLISENABLEDFRAMELOCKI3DPROC
epoxy_wglIsEnabledFrameLockI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_lock, 90 /* wglIsEnabledFrameLockI3D */);
}

static PFNWGLISENABLEDGENLOCKI3DPROC
epoxy_wglIsEnabledGenlockI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 91 /* wglIsEnabledGenlockI3D */);
}

static PFNWGLJOINSWAPGROUPNVPROC
epoxy_wglJoinSwapGroupNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_swap_group, 92 /* wglJoinSwapGroupNV */);
}

static PFNWGLLOADDISPLAYCOLORTABLEEXTPROC
epoxy_wglLoadDisplayColorTableEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_display_color_table, 93 /* wglLoadDisplayColorTableEXT */);
}

static PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC
epoxy_wglLockVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_capture, 94 /* wglLockVideoCaptureDeviceNV */);
}

static PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC
epoxy_wglMakeAssociatedContextCurrentAMD_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_AMD_gpu_association, 95 /* wglMakeAssociatedContextCurrentAMD */);
}

static PFNWGLMAKECONTEXTCURRENTARBPROC
epoxy_wglMakeContextCurrentARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_make_current_read, 96 /* wglMakeContextCurrentARB */);
}

static PFNWGLMAKECONTEXTCURRENTEXTPROC
epoxy_wglMakeContextCurrentEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_make_current_read, 97 /* wglMakeContextCurrentEXT */);
}

static PFNWGLMAKECURRENTPROC
epoxy_wglMakeCurrent_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 98 /* wglMakeCurrent */);
}

static PFNWGLQUERYCURRENTCONTEXTNVPROC
epoxy_wglQueryCurrentContextNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_present_video, 99 /* wglQueryCurrentContextNV */);
}

static PFNWGLQUERYFRAMECOUNTNVPROC
epoxy_wglQueryFrameCountNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_swap_group, 100 /* wglQueryFrameCountNV */);
}

static PFNWGLQUERYFRAMELOCKMASTERI3DPROC
epoxy_wglQueryFrameLockMasterI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_lock, 101 /* wglQueryFrameLockMasterI3D */);
}

static PFNWGLQUERYFRAMETRACKINGI3DPROC
epoxy_wglQueryFrameTrackingI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_swap_frame_usage, 102 /* wglQueryFrameTrackingI3D */);
}

static PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC
epoxy_wglQueryGenlockMaxSourceDelayI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_genlock, 103 /* wglQueryGenlockMaxSourceDelayI3D */);
}

static PFNWGLQUERYMAXSWAPGROUPSNVPROC
epoxy_wglQueryMaxSwapGroupsNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_swap_group, 104 /* wglQueryMaxSwapGroupsNV */);
}

static PFNWGLQUERYPBUFFERARBPROC
epoxy_wglQueryPbufferARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pbuffer, 105 /* wglQueryPbufferARB */);
}

static PFNWGLQUERYPBUFFEREXTPROC
epoxy_wglQueryPbufferEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pbuffer, 106 /* wglQueryPbufferEXT */);
}

static PFNWGLQUERYSWAPGROUPNVPROC
epoxy_wglQuerySwapGroupNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_swap_group, 107 /* wglQuerySwapGroupNV */);
}

static PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC
epoxy_wglQueryVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_capture, 108 /* wglQueryVideoCaptureDeviceNV */);
}

static PFNWGLREALIZELAYERPALETTEPROC
epoxy_wglRealizeLayerPalette_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 109 /* wglRealizeLayerPalette */);
}

static PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC
epoxy_wglReleaseImageBufferEventsI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_image_buffer, 110 /* wglReleaseImageBufferEventsI3D */);
}

static PFNWGLRELEASEPBUFFERDCARBPROC
epoxy_wglReleasePbufferDCARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_pbuffer, 111 /* wglReleasePbufferDCARB */);
}

static PFNWGLRELEASEPBUFFERDCEXTPROC
epoxy_wglReleasePbufferDCEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_pbuffer, 112 /* wglReleasePbufferDCEXT */);
}

static PFNWGLRELEASETEXIMAGEARBPROC
epoxy_wglReleaseTexImageARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_render_texture, 113 /* wglReleaseTexImageARB */);
}

static PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC
epoxy_wglReleaseVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_capture, 114 /* wglReleaseVideoCaptureDeviceNV */);
}

static PFNWGLRELEASEVIDEODEVICENVPROC
epoxy_wglReleaseVideoDeviceNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_output, 115 /* wglReleaseVideoDeviceNV */);
}

static PFNWGLRELEASEVIDEOIMAGENVPROC
epoxy_wglReleaseVideoImageNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_output, 116 /* wglReleaseVideoImageNV */);
}

static PFNWGLRESETFRAMECOUNTNVPROC
epoxy_wglResetFrameCountNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_swap_group, 117 /* wglResetFrameCountNV */);
}

static PFNWGLRESTOREBUFFERREGIONARBPROC
epoxy_wglRestoreBufferRegionARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_buffer_region, 118 /* wglRestoreBufferRegionARB */);
}

static PFNWGLSAVEBUFFERREGIONARBPROC
epoxy_wglSaveBufferRegionARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_buffer_region, 119 /* wglSaveBufferRegionARB */);
}

static PFNWGLSENDPBUFFERTOVIDEONVPROC
epoxy_wglSendPbufferToVideoNV_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_NV_video_output, 120 /* wglSendPbufferToVideoNV */);
}

static PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC
epoxy_wglSetDigitalVideoParametersI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_digital_video_control, 121 /* wglSetDigitalVideoParametersI3D */);
}

static PFNWGLSETGAMMATABLEI3DPROC
epoxy_wglSetGammaTableI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_gamma, 122 /* wglSetGammaTableI3D */);
}

static PFNWGLSETGAMMATABLEPARAMETERSI3DPROC
epoxy_wglSetGammaTableParametersI3D_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_I3D_gamma, 123 /* wglSetGammaTableParametersI3D */);
}

static PFNWGLSETLAYERPALETTEENTRIESPROC
epoxy_wglSetLayerPaletteEntries_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 124 /* wglSetLayerPaletteEntries */);
}

static PFNWGLSETPBUFFERATTRIBARBPROC
epoxy_wglSetPbufferAttribARB_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_ARB_render_texture, 125 /* wglSetPbufferAttribARB */);
}

static PFNWGLSETSTEREOEMITTERSTATE3DLPROC
epoxy_wglSetStereoEmitterState3DL_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_3DL_stereo_control, 126 /* wglSetStereoEmitterState3DL */);
}

static PFNWGLSHARELISTSPROC
epoxy_wglShareLists_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 127 /* wglShareLists */);
}

static PFNWGLSWAPBUFFERSMSCOMLPROC
epoxy_wglSwapBuffersMscOML_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_OML_sync_control, 128 /* wglSwapBuffersMscOML */);
}

static PFNWGLSWAPINTERVALEXTPROC
epoxy_wglSwapIntervalEXT_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_EXT_swap_control, 129 /* wglSwapIntervalEXT */);
}

static PFNWGLSWAPLAYERBUFFERSPROC
epoxy_wglSwapLayerBuffers_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 130 /* wglSwapLayerBuffers */);
}

static PFNWGLSWAPLAYERBUFFERSMSCOMLPROC
epoxy_wglSwapLayerBuffersMscOML_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_OML_sync_control, 131 /* wglSwapLayerBuffersMscOML */);
}

static PFNWGLUSEFONTBITMAPSAPROC
epoxy_wglUseFontBitmapsA_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 132 /* wglUseFontBitmapsA */);
}

static PFNWGLUSEFONTBITMAPSWPROC
epoxy_wglUseFontBitmapsW_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 133 /* wglUseFontBitmapsW */);
}

static PFNWGLUSEFONTOUTLINESPROC
epoxy_wglUseFontOutlines_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 134 /* wglUseFontOutlines */);
}

static PFNWGLUSEFONTOUTLINESAPROC
epoxy_wglUseFontOutlinesA_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 135 /* wglUseFontOutlinesA */);
}

static PFNWGLUSEFONTOUTLINESWPROC
epoxy_wglUseFontOutlinesW_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_10, 136 /* wglUseFontOutlinesW */);
}

static PFNWGLWAITFORMSCOMLPROC
epoxy_wglWaitForMscOML_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_OML_sync_control, 137 /* wglWaitForMscOML */);
}

static PFNWGLWAITFORSBCOMLPROC
epoxy_wglWaitForSbcOML_resolver(tls_ptr tls)
{
    return wgl_single_resolver(tls, WGL_extension_WGL_OML_sync_control, 138 /* wglWaitForSbcOML */);
}

GEN_THUNKS_RET(wgl, void *, wglAllocateMemoryNV, (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority), (size, readfreq, writefreq, priority))
GEN_THUNKS_RET(wgl, BOOL, wglAssociateImageBufferEventsI3D, (HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count), (hDC, pEvent, pAddress, pSize, count))
GEN_THUNKS_RET(wgl, BOOL, wglBeginFrameTrackingI3D, (void), ())
GEN_THUNKS_RET(wgl, GLboolean, wglBindDisplayColorTableEXT, (GLushort id), (id))
GEN_THUNKS_RET(wgl, BOOL, wglBindSwapBarrierNV, (GLuint group, GLuint barrier), (group, barrier))
GEN_THUNKS_RET(wgl, BOOL, wglBindTexImageARB, (HPBUFFERARB hPbuffer, int iBuffer), (hPbuffer, iBuffer))
GEN_THUNKS_RET(wgl, BOOL, wglBindVideoCaptureDeviceNV, (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice), (uVideoSlot, hDevice))
GEN_THUNKS_RET(wgl, BOOL, wglBindVideoDeviceNV, (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList), (hDC, uVideoSlot, hVideoDevice, piAttribList))
GEN_THUNKS_RET(wgl, BOOL, wglBindVideoImageNV, (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer), (hVideoDevice, hPbuffer, iVideoBuffer))
GEN_THUNKS(wgl, wglBlitContextFramebufferAMD, (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), (dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter))
GEN_THUNKS_RET(wgl, BOOL, wglChoosePixelFormatARB, (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats), (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))
GEN_THUNKS_RET(wgl, BOOL, wglChoosePixelFormatEXT, (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats), (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))
GEN_THUNKS_RET(wgl, BOOL, wglCopyContext, (HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask), (hglrcSrc, hglrcDst, mask))
GEN_THUNKS_RET(wgl, BOOL, wglCopyImageSubDataNV, (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth), (hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth))
GEN_THUNKS_RET(wgl, HDC, wglCreateAffinityDCNV, (const HGPUNV * phGpuList), (phGpuList))
GEN_THUNKS_RET(wgl, HGLRC, wglCreateAssociatedContextAMD, (UINT id), (id))
GEN_THUNKS_RET(wgl, HGLRC, wglCreateAssociatedContextAttribsAMD, (UINT id, HGLRC hShareContext, const int * attribList), (id, hShareContext, attribList))
GEN_THUNKS_RET(wgl, HANDLE, wglCreateBufferRegionARB, (HDC hDC, int iLayerPlane, UINT uType), (hDC, iLayerPlane, uType))
GEN_THUNKS_RET(wgl, HGLRC, wglCreateContext, (HDC hDc), (hDc))
GEN_THUNKS_RET(wgl, HGLRC, wglCreateContextAttribsARB, (HDC hDC, HGLRC hShareContext, const int * attribList), (hDC, hShareContext, attribList))
GEN_THUNKS_RET(wgl, GLboolean, wglCreateDisplayColorTableEXT, (GLushort id), (id))
GEN_THUNKS_RET(wgl, LPVOID, wglCreateImageBufferI3D, (HDC hDC, DWORD dwSize, UINT uFlags), (hDC, dwSize, uFlags))
GEN_THUNKS_RET(wgl, HGLRC, wglCreateLayerContext, (HDC hDc, int level), (hDc, level))
GEN_THUNKS_RET(wgl, HPBUFFERARB, wglCreatePbufferARB, (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList), (hDC, iPixelFormat, iWidth, iHeight, piAttribList))
GEN_THUNKS_RET(wgl, HPBUFFEREXT, wglCreatePbufferEXT, (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList), (hDC, iPixelFormat, iWidth, iHeight, piAttribList))
GEN_THUNKS_RET(wgl, BOOL, wglDXCloseDeviceNV, (HANDLE hDevice), (hDevice))
GEN_THUNKS_RET(wgl, BOOL, wglDXLockObjectsNV, (HANDLE hDevice, GLint count, HANDLE * hObjects), (hDevice, count, hObjects))
GEN_THUNKS_RET(wgl, BOOL, wglDXObjectAccessNV, (HANDLE hObject, GLenum access), (hObject, access))
GEN_THUNKS_RET(wgl, HANDLE, wglDXOpenDeviceNV, (void * dxDevice), (dxDevice))
GEN_THUNKS_RET(wgl, HANDLE, wglDXRegisterObjectNV, (HANDLE hDevice, void * dxObject, GLuint name, GLenum type, GLenum access), (hDevice, dxObject, name, type, access))
GEN_THUNKS_RET(wgl, BOOL, wglDXSetResourceShareHandleNV, (void * dxObject, HANDLE shareHandle), (dxObject, shareHandle))
GEN_THUNKS_RET(wgl, BOOL, wglDXUnlockObjectsNV, (HANDLE hDevice, GLint count, HANDLE * hObjects), (hDevice, count, hObjects))
GEN_THUNKS_RET(wgl, BOOL, wglDXUnregisterObjectNV, (HANDLE hDevice, HANDLE hObject), (hDevice, hObject))
GEN_THUNKS_RET(wgl, BOOL, wglDelayBeforeSwapNV, (HDC hDC, GLfloat seconds), (hDC, seconds))
GEN_THUNKS_RET(wgl, BOOL, wglDeleteAssociatedContextAMD, (HGLRC hglrc), (hglrc))
GEN_THUNKS(wgl, wglDeleteBufferRegionARB, (HANDLE hRegion), (hRegion))
GEN_THUNKS_RET(wgl, BOOL, wglDeleteContext, (HGLRC oldContext), (oldContext))
GEN_THUNKS_RET(wgl, BOOL, wglDeleteDCNV, (HDC hdc), (hdc))
GEN_THUNKS_RET(wgl, BOOL, wglDescribeLayerPlane, (HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd), (hDc, pixelFormat, layerPlane, nBytes, plpd))
GEN_THUNKS(wgl, wglDestroyDisplayColorTableEXT, (GLushort id), (id))
GEN_THUNKS_RET(wgl, BOOL, wglDestroyImageBufferI3D, (HDC hDC, LPVOID pAddress), (hDC, pAddress))
GEN_THUNKS_RET(wgl, BOOL, wglDestroyPbufferARB, (HPBUFFERARB hPbuffer), (hPbuffer))
GEN_THUNKS_RET(wgl, BOOL, wglDestroyPbufferEXT, (HPBUFFEREXT hPbuffer), (hPbuffer))
GEN_THUNKS_RET(wgl, BOOL, wglDisableFrameLockI3D, (void), ())
GEN_THUNKS_RET(wgl, BOOL, wglDisableGenlockI3D, (HDC hDC), (hDC))
GEN_THUNKS_RET(wgl, BOOL, wglEnableFrameLockI3D, (void), ())
GEN_THUNKS_RET(wgl, BOOL, wglEnableGenlockI3D, (HDC hDC), (hDC))
GEN_THUNKS_RET(wgl, BOOL, wglEndFrameTrackingI3D, (void), ())
GEN_THUNKS_RET(wgl, BOOL, wglEnumGpuDevicesNV, (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice), (hGpu, iDeviceIndex, lpGpuDevice))
GEN_THUNKS_RET(wgl, BOOL, wglEnumGpusFromAffinityDCNV, (HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu), (hAffinityDC, iGpuIndex, hGpu))
GEN_THUNKS_RET(wgl, BOOL, wglEnumGpusNV, (UINT iGpuIndex, HGPUNV * phGpu), (iGpuIndex, phGpu))
GEN_THUNKS_RET(wgl, UINT, wglEnumerateVideoCaptureDevicesNV, (HDC hDc, HVIDEOINPUTDEVICENV * phDeviceList), (hDc, phDeviceList))
GEN_THUNKS_RET(wgl, int, wglEnumerateVideoDevicesNV, (HDC hDC, HVIDEOOUTPUTDEVICENV * phDeviceList), (hDC, phDeviceList))
GEN_THUNKS(wgl, wglFreeMemoryNV, (void * pointer), (pointer))
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSampleRateI3D, (HDC hDC, UINT uRate), (hDC, uRate))
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSourceDelayI3D, (HDC hDC, UINT uDelay), (hDC, uDelay))
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSourceEdgeI3D, (HDC hDC, UINT uEdge), (hDC, uEdge))
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSourceI3D, (HDC hDC, UINT uSource), (hDC, uSource))
GEN_THUNKS_RET(wgl, UINT, wglGetContextGPUIDAMD, (HGLRC hglrc), (hglrc))
GEN_THUNKS_RET(wgl, HGLRC, wglGetCurrentAssociatedContextAMD, (void), ())
GEN_THUNKS_RET(wgl, HGLRC, wglGetCurrentContext, (void), ())
GEN_THUNKS_RET(wgl, HDC, wglGetCurrentDC, (void), ())
GEN_THUNKS_RET(wgl, HDC, wglGetCurrentReadDCARB, (void), ())
GEN_THUNKS_RET(wgl, HDC, wglGetCurrentReadDCEXT, (void), ())
GEN_THUNKS_RET(wgl, PROC, wglGetDefaultProcAddress, (LPCSTR lpszProc), (lpszProc))
GEN_THUNKS_RET(wgl, BOOL, wglGetDigitalVideoParametersI3D, (HDC hDC, int iAttribute, int * piValue), (hDC, iAttribute, piValue))
GEN_THUNKS_RET(wgl, const char *, wglGetExtensionsStringARB, (HDC hdc), (hdc))
GEN_THUNKS_RET(wgl, const char *, wglGetExtensionsStringEXT, (void), ())
GEN_THUNKS_RET(wgl, BOOL, wglGetFrameUsageI3D, (float * pUsage), (pUsage))
GEN_THUNKS_RET(wgl, UINT, wglGetGPUIDsAMD, (UINT maxCount, UINT * ids), (maxCount, ids))
GEN_THUNKS_RET(wgl, INT, wglGetGPUInfoAMD, (UINT id, int property, GLenum dataType, UINT size, void * data), (id, property, dataType, size, data))
GEN_THUNKS_RET(wgl, BOOL, wglGetGammaTableI3D, (HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue), (hDC, iEntries, puRed, puGreen, puBlue))
GEN_THUNKS_RET(wgl, BOOL, wglGetGammaTableParametersI3D, (HDC hDC, int iAttribute, int * piValue), (hDC, iAttribute, piValue))
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSampleRateI3D, (HDC hDC, UINT * uRate), (hDC, uRate))
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSourceDelayI3D, (HDC hDC, UINT * uDelay), (hDC, uDelay))
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSourceEdgeI3D, (HDC hDC, UINT * uEdge), (hDC, uEdge))
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSourceI3D, (HDC hDC, UINT * uSource), (hDC, uSource))
GEN_THUNKS_RET(wgl, int, wglGetLayerPaletteEntries, (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr), (hdc, iLayerPlane, iStart, cEntries, pcr))
GEN_THUNKS_RET(wgl, BOOL, wglGetMscRateOML, (HDC hdc, INT32 * numerator, INT32 * denominator), (hdc, numerator, denominator))
GEN_THUNKS_RET(wgl, HDC, wglGetPbufferDCARB, (HPBUFFERARB hPbuffer), (hPbuffer))
GEN_THUNKS_RET(wgl, HDC, wglGetPbufferDCEXT, (HPBUFFEREXT hPbuffer), (hPbuffer))
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribfvARB, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribfvEXT, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribivARB, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribivEXT, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))
GEN_THUNKS_RET(wgl, PROC, wglGetProcAddress, (LPCSTR lpszProc), (lpszProc))
GEN_THUNKS_RET(wgl, int, wglGetSwapIntervalEXT, (void), ())
GEN_THUNKS_RET(wgl, BOOL, wglGetSyncValuesOML, (HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc), (hdc, ust, msc, sbc))
GEN_THUNKS_RET(wgl, BOOL, wglGetVideoDeviceNV, (HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice), (hDC, numDevices, hVideoDevice))
GEN_THUNKS_RET(wgl, BOOL, wglGetVideoInfoNV, (HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo), (hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo))
GEN_THUNKS_RET(wgl, BOOL, wglIsEnabledFrameLockI3D, (BOOL * pFlag), (pFlag))
GEN_THUNKS_RET(wgl, BOOL, wglIsEnabledGenlockI3D, (HDC hDC, BOOL * pFlag), (hDC, pFlag))
GEN_THUNKS_RET(wgl, BOOL, wglJoinSwapGroupNV, (HDC hDC, GLuint group), (hDC, group))
GEN_THUNKS_RET(wgl, GLboolean, wglLoadDisplayColorTableEXT, (const GLushort * table, GLuint length), (table, length))
GEN_THUNKS_RET(wgl, BOOL, wglLockVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice), (hDc, hDevice))
GEN_THUNKS_RET(wgl, BOOL, wglMakeAssociatedContextCurrentAMD, (HGLRC hglrc), (hglrc))
GEN_THUNKS_RET(wgl, BOOL, wglMakeContextCurrentARB, (HDC hDrawDC, HDC hReadDC, HGLRC hglrc), (hDrawDC, hReadDC, hglrc))
GEN_THUNKS_RET(wgl, BOOL, wglMakeContextCurrentEXT, (HDC hDrawDC, HDC hReadDC, HGLRC hglrc), (hDrawDC, hReadDC, hglrc))
GEN_THUNKS_RET(wgl, BOOL, wglMakeCurrent, (HDC hDc, HGLRC newContext), (hDc, newContext))
GEN_THUNKS_RET(wgl, BOOL, wglQueryCurrentContextNV, (int iAttribute, int * piValue), (iAttribute, piValue))
GEN_THUNKS_RET(wgl, BOOL, wglQueryFrameCountNV, (HDC hDC, GLuint * count), (hDC, count))
GEN_THUNKS_RET(wgl, BOOL, wglQueryFrameLockMasterI3D, (BOOL * pFlag), (pFlag))
GEN_THUNKS_RET(wgl, BOOL, wglQueryFrameTrackingI3D, (DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage), (pFrameCount, pMissedFrames, pLastMissedUsage))
GEN_THUNKS_RET(wgl, BOOL, wglQueryGenlockMaxSourceDelayI3D, (HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay), (hDC, uMaxLineDelay, uMaxPixelDelay))
GEN_THUNKS_RET(wgl, BOOL, wglQueryMaxSwapGroupsNV, (HDC hDC, GLuint * maxGroups, GLuint * maxBarriers), (hDC, maxGroups, maxBarriers))
GEN_THUNKS_RET(wgl, BOOL, wglQueryPbufferARB, (HPBUFFERARB hPbuffer, int iAttribute, int * piValue), (hPbuffer, iAttribute, piValue))
GEN_THUNKS_RET(wgl, BOOL, wglQueryPbufferEXT, (HPBUFFEREXT hPbuffer, int iAttribute, int * piValue), (hPbuffer, iAttribute, piValue))
GEN_THUNKS_RET(wgl, BOOL, wglQuerySwapGroupNV, (HDC hDC, GLuint * group, GLuint * barrier), (hDC, group, barrier))
GEN_THUNKS_RET(wgl, BOOL, wglQueryVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int * piValue), (hDc, hDevice, iAttribute, piValue))
GEN_THUNKS_RET(wgl, BOOL, wglRealizeLayerPalette, (HDC hdc, int iLayerPlane, BOOL bRealize), (hdc, iLayerPlane, bRealize))
GEN_THUNKS_RET(wgl, BOOL, wglReleaseImageBufferEventsI3D, (HDC hDC, const LPVOID * pAddress, UINT count), (hDC, pAddress, count))
GEN_THUNKS_RET(wgl, int, wglReleasePbufferDCARB, (HPBUFFERARB hPbuffer, HDC hDC), (hPbuffer, hDC))
GEN_THUNKS_RET(wgl, int, wglReleasePbufferDCEXT, (HPBUFFEREXT hPbuffer, HDC hDC), (hPbuffer, hDC))
GEN_THUNKS_RET(wgl, BOOL, wglReleaseTexImageARB, (HPBUFFERARB hPbuffer, int iBuffer), (hPbuffer, iBuffer))
GEN_THUNKS_RET(wgl, BOOL, wglReleaseVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice), (hDc, hDevice))
GEN_THUNKS_RET(wgl, BOOL, wglReleaseVideoDeviceNV, (HPVIDEODEV hVideoDevice), (hVideoDevice))
GEN_THUNKS_RET(wgl, BOOL, wglReleaseVideoImageNV, (HPBUFFERARB hPbuffer, int iVideoBuffer), (hPbuffer, iVideoBuffer))
GEN_THUNKS_RET(wgl, BOOL, wglResetFrameCountNV, (HDC hDC), (hDC))
GEN_THUNKS_RET(wgl, BOOL, wglRestoreBufferRegionARB, (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc), (hRegion, x, y, width, height, xSrc, ySrc))
GEN_THUNKS_RET(wgl, BOOL, wglSaveBufferRegionARB, (HANDLE hRegion, int x, int y, int width, int height), (hRegion, x, y, width, height))
GEN_THUNKS_RET(wgl, BOOL, wglSendPbufferToVideoNV, (HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock), (hPbuffer, iBufferType, pulCounterPbuffer, bBlock))
GEN_THUNKS_RET(wgl, BOOL, wglSetDigitalVideoParametersI3D, (HDC hDC, int iAttribute, const int * piValue), (hDC, iAttribute, piValue))
GEN_THUNKS_RET(wgl, BOOL, wglSetGammaTableI3D, (HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue), (hDC, iEntries, puRed, puGreen, puBlue))
GEN_THUNKS_RET(wgl, BOOL, wglSetGammaTableParametersI3D, (HDC hDC, int iAttribute, const int * piValue), (hDC, iAttribute, piValue))
GEN_THUNKS_RET(wgl, int, wglSetLayerPaletteEntries, (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr), (hdc, iLayerPlane, iStart, cEntries, pcr))
GEN_THUNKS_RET(wgl, BOOL, wglSetPbufferAttribARB, (HPBUFFERARB hPbuffer, const int * piAttribList), (hPbuffer, piAttribList))
GEN_THUNKS_RET(wgl, BOOL, wglSetStereoEmitterState3DL, (HDC hDC, UINT uState), (hDC, uState))
GEN_THUNKS_RET(wgl, BOOL, wglShareLists, (HGLRC hrcSrvShare, HGLRC hrcSrvSource), (hrcSrvShare, hrcSrvSource))
GEN_THUNKS_RET(wgl, INT64, wglSwapBuffersMscOML, (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder), (hdc, target_msc, divisor, remainder))
GEN_THUNKS_RET(wgl, BOOL, wglSwapIntervalEXT, (int interval), (interval))
GEN_THUNKS_RET(wgl, BOOL, wglSwapLayerBuffers, (HDC hdc, UINT fuFlags), (hdc, fuFlags))
GEN_THUNKS_RET(wgl, INT64, wglSwapLayerBuffersMscOML, (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder), (hdc, fuPlanes, target_msc, divisor, remainder))
GEN_THUNKS_RET(wgl, BOOL, wglUseFontBitmapsA, (HDC hDC, DWORD first, DWORD count, DWORD listBase), (hDC, first, count, listBase))
GEN_THUNKS_RET(wgl, BOOL, wglUseFontBitmapsW, (HDC hDC, DWORD first, DWORD count, DWORD listBase), (hDC, first, count, listBase))
GEN_THUNKS_RET(wgl, BOOL, wglUseFontOutlines, (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf), (hDC, first, count, listBase, deviation, extrusion, format, lpgmf))
GEN_THUNKS_RET(wgl, BOOL, wglUseFontOutlinesA, (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf), (hDC, first, count, listBase, deviation, extrusion, format, lpgmf))
GEN_THUNKS_RET(wgl, BOOL, wglUseFontOutlinesW, (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf), (hDC, first, count, listBase, deviation, extrusion, format, lpgmf))
GEN_THUNKS_RET(wgl, BOOL, wglWaitForMscOML, (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc), (hdc, target_msc, divisor, remainder, ust, msc, sbc))
GEN_THUNKS_RET(wgl, BOOL, wglWaitForSbcOML, (HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc), (hdc, target_sbc, ust, msc, sbc))

static struct wgl_dispatch_table wgl_resolver_table = {
    .wglAllocateMemoryNV = epoxy_wglAllocateMemoryNV_dispatch_table_rewrite_ptr,
    .wglAssociateImageBufferEventsI3D = epoxy_wglAssociateImageBufferEventsI3D_dispatch_table_rewrite_ptr,
    .wglBeginFrameTrackingI3D = epoxy_wglBeginFrameTrackingI3D_dispatch_table_rewrite_ptr,
    .wglBindDisplayColorTableEXT = epoxy_wglBindDisplayColorTableEXT_dispatch_table_rewrite_ptr,
    .wglBindSwapBarrierNV = epoxy_wglBindSwapBarrierNV_dispatch_table_rewrite_ptr,
    .wglBindTexImageARB = epoxy_wglBindTexImageARB_dispatch_table_rewrite_ptr,
    .wglBindVideoCaptureDeviceNV = epoxy_wglBindVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .wglBindVideoDeviceNV = epoxy_wglBindVideoDeviceNV_dispatch_table_rewrite_ptr,
    .wglBindVideoImageNV = epoxy_wglBindVideoImageNV_dispatch_table_rewrite_ptr,
    .wglBlitContextFramebufferAMD = epoxy_wglBlitContextFramebufferAMD_dispatch_table_rewrite_ptr,
    .wglChoosePixelFormatARB = epoxy_wglChoosePixelFormatARB_dispatch_table_rewrite_ptr,
    .wglChoosePixelFormatEXT = epoxy_wglChoosePixelFormatEXT_dispatch_table_rewrite_ptr,
    .wglCopyContext = epoxy_wglCopyContext_dispatch_table_rewrite_ptr,
    .wglCopyImageSubDataNV = epoxy_wglCopyImageSubDataNV_dispatch_table_rewrite_ptr,
    .wglCreateAffinityDCNV = epoxy_wglCreateAffinityDCNV_dispatch_table_rewrite_ptr,
    .wglCreateAssociatedContextAMD = epoxy_wglCreateAssociatedContextAMD_dispatch_table_rewrite_ptr,
    .wglCreateAssociatedContextAttribsAMD = epoxy_wglCreateAssociatedContextAttribsAMD_dispatch_table_rewrite_ptr,
    .wglCreateBufferRegionARB = epoxy_wglCreateBufferRegionARB_dispatch_table_rewrite_ptr,
    .wglCreateContext = epoxy_wglCreateContext_dispatch_table_rewrite_ptr,
    .wglCreateContextAttribsARB = epoxy_wglCreateContextAttribsARB_dispatch_table_rewrite_ptr,
    .wglCreateDisplayColorTableEXT = epoxy_wglCreateDisplayColorTableEXT_dispatch_table_rewrite_ptr,
    .wglCreateImageBufferI3D = epoxy_wglCreateImageBufferI3D_dispatch_table_rewrite_ptr,
    .wglCreateLayerContext = epoxy_wglCreateLayerContext_dispatch_table_rewrite_ptr,
    .wglCreatePbufferARB = epoxy_wglCreatePbufferARB_dispatch_table_rewrite_ptr,
    .wglCreatePbufferEXT = epoxy_wglCreatePbufferEXT_dispatch_table_rewrite_ptr,
    .wglDXCloseDeviceNV = epoxy_wglDXCloseDeviceNV_dispatch_table_rewrite_ptr,
    .wglDXLockObjectsNV = epoxy_wglDXLockObjectsNV_dispatch_table_rewrite_ptr,
    .wglDXObjectAccessNV = epoxy_wglDXObjectAccessNV_dispatch_table_rewrite_ptr,
    .wglDXOpenDeviceNV = epoxy_wglDXOpenDeviceNV_dispatch_table_rewrite_ptr,
    .wglDXRegisterObjectNV = epoxy_wglDXRegisterObjectNV_dispatch_table_rewrite_ptr,
    .wglDXSetResourceShareHandleNV = epoxy_wglDXSetResourceShareHandleNV_dispatch_table_rewrite_ptr,
    .wglDXUnlockObjectsNV = epoxy_wglDXUnlockObjectsNV_dispatch_table_rewrite_ptr,
    .wglDXUnregisterObjectNV = epoxy_wglDXUnregisterObjectNV_dispatch_table_rewrite_ptr,
    .wglDelayBeforeSwapNV = epoxy_wglDelayBeforeSwapNV_dispatch_table_rewrite_ptr,
    .wglDeleteAssociatedContextAMD = epoxy_wglDeleteAssociatedContextAMD_dispatch_table_rewrite_ptr,
    .wglDeleteBufferRegionARB = epoxy_wglDeleteBufferRegionARB_dispatch_table_rewrite_ptr,
    .wglDeleteContext = epoxy_wglDeleteContext_dispatch_table_rewrite_ptr,
    .wglDeleteDCNV = epoxy_wglDeleteDCNV_dispatch_table_rewrite_ptr,
    .wglDescribeLayerPlane = epoxy_wglDescribeLayerPlane_dispatch_table_rewrite_ptr,
    .wglDestroyDisplayColorTableEXT = epoxy_wglDestroyDisplayColorTableEXT_dispatch_table_rewrite_ptr,
    .wglDestroyImageBufferI3D = epoxy_wglDestroyImageBufferI3D_dispatch_table_rewrite_ptr,
    .wglDestroyPbufferARB = epoxy_wglDestroyPbufferARB_dispatch_table_rewrite_ptr,
    .wglDestroyPbufferEXT = epoxy_wglDestroyPbufferEXT_dispatch_table_rewrite_ptr,
    .wglDisableFrameLockI3D = epoxy_wglDisableFrameLockI3D_dispatch_table_rewrite_ptr,
    .wglDisableGenlockI3D = epoxy_wglDisableGenlockI3D_dispatch_table_rewrite_ptr,
    .wglEnableFrameLockI3D = epoxy_wglEnableFrameLockI3D_dispatch_table_rewrite_ptr,
    .wglEnableGenlockI3D = epoxy_wglEnableGenlockI3D_dispatch_table_rewrite_ptr,
    .wglEndFrameTrackingI3D = epoxy_wglEndFrameTrackingI3D_dispatch_table_rewrite_ptr,
    .wglEnumGpuDevicesNV = epoxy_wglEnumGpuDevicesNV_dispatch_table_rewrite_ptr,
    .wglEnumGpusFromAffinityDCNV = epoxy_wglEnumGpusFromAffinityDCNV_dispatch_table_rewrite_ptr,
    .wglEnumGpusNV = epoxy_wglEnumGpusNV_dispatch_table_rewrite_ptr,
    .wglEnumerateVideoCaptureDevicesNV = epoxy_wglEnumerateVideoCaptureDevicesNV_dispatch_table_rewrite_ptr,
    .wglEnumerateVideoDevicesNV = epoxy_wglEnumerateVideoDevicesNV_dispatch_table_rewrite_ptr,
    .wglFreeMemoryNV = epoxy_wglFreeMemoryNV_dispatch_table_rewrite_ptr,
    .wglGenlockSampleRateI3D = epoxy_wglGenlockSampleRateI3D_dispatch_table_rewrite_ptr,
    .wglGenlockSourceDelayI3D = epoxy_wglGenlockSourceDelayI3D_dispatch_table_rewrite_ptr,
    .wglGenlockSourceEdgeI3D = epoxy_wglGenlockSourceEdgeI3D_dispatch_table_rewrite_ptr,
    .wglGenlockSourceI3D = epoxy_wglGenlockSourceI3D_dispatch_table_rewrite_ptr,
    .wglGetContextGPUIDAMD = epoxy_wglGetContextGPUIDAMD_dispatch_table_rewrite_ptr,
    .wglGetCurrentAssociatedContextAMD = epoxy_wglGetCurrentAssociatedContextAMD_dispatch_table_rewrite_ptr,
    .wglGetCurrentContext = epoxy_wglGetCurrentContext_dispatch_table_rewrite_ptr,
    .wglGetCurrentDC = epoxy_wglGetCurrentDC_dispatch_table_rewrite_ptr,
    .wglGetCurrentReadDCARB = epoxy_wglGetCurrentReadDCARB_dispatch_table_rewrite_ptr,
    .wglGetCurrentReadDCEXT = epoxy_wglGetCurrentReadDCEXT_dispatch_table_rewrite_ptr,
    .wglGetDefaultProcAddress = epoxy_wglGetDefaultProcAddress_dispatch_table_rewrite_ptr,
    .wglGetDigitalVideoParametersI3D = epoxy_wglGetDigitalVideoParametersI3D_dispatch_table_rewrite_ptr,
    .wglGetExtensionsStringARB = epoxy_wglGetExtensionsStringARB_dispatch_table_rewrite_ptr,
    .wglGetExtensionsStringEXT = epoxy_wglGetExtensionsStringEXT_dispatch_table_rewrite_ptr,
    .wglGetFrameUsageI3D = epoxy_wglGetFrameUsageI3D_dispatch_table_rewrite_ptr,
    .wglGetGPUIDsAMD = epoxy_wglGetGPUIDsAMD_dispatch_table_rewrite_ptr,
    .wglGetGPUInfoAMD = epoxy_wglGetGPUInfoAMD_dispatch_table_rewrite_ptr,
    .wglGetGammaTableI3D = epoxy_wglGetGammaTableI3D_dispatch_table_rewrite_ptr,
    .wglGetGammaTableParametersI3D = epoxy_wglGetGammaTableParametersI3D_dispatch_table_rewrite_ptr,
    .wglGetGenlockSampleRateI3D = epoxy_wglGetGenlockSampleRateI3D_dispatch_table_rewrite_ptr,
    .wglGetGenlockSourceDelayI3D = epoxy_wglGetGenlockSourceDelayI3D_dispatch_table_rewrite_ptr,
    .wglGetGenlockSourceEdgeI3D = epoxy_wglGetGenlockSourceEdgeI3D_dispatch_table_rewrite_ptr,
    .wglGetGenlockSourceI3D = epoxy_wglGetGenlockSourceI3D_dispatch_table_rewrite_ptr,
    .wglGetLayerPaletteEntries = epoxy_wglGetLayerPaletteEntries_dispatch_table_rewrite_ptr,
    .wglGetMscRateOML = epoxy_wglGetMscRateOML_dispatch_table_rewrite_ptr,
    .wglGetPbufferDCARB = epoxy_wglGetPbufferDCARB_dispatch_table_rewrite_ptr,
    .wglGetPbufferDCEXT = epoxy_wglGetPbufferDCEXT_dispatch_table_rewrite_ptr,
    .wglGetPixelFormatAttribfvARB = epoxy_wglGetPixelFormatAttribfvARB_dispatch_table_rewrite_ptr,
    .wglGetPixelFormatAttribfvEXT = epoxy_wglGetPixelFormatAttribfvEXT_dispatch_table_rewrite_ptr,
    .wglGetPixelFormatAttribivARB = epoxy_wglGetPixelFormatAttribivARB_dispatch_table_rewrite_ptr,
    .wglGetPixelFormatAttribivEXT = epoxy_wglGetPixelFormatAttribivEXT_dispatch_table_rewrite_ptr,
    .wglGetProcAddress = epoxy_wglGetProcAddress_dispatch_table_rewrite_ptr,
    .wglGetSwapIntervalEXT = epoxy_wglGetSwapIntervalEXT_dispatch_table_rewrite_ptr,
    .wglGetSyncValuesOML = epoxy_wglGetSyncValuesOML_dispatch_table_rewrite_ptr,
    .wglGetVideoDeviceNV = epoxy_wglGetVideoDeviceNV_dispatch_table_rewrite_ptr,
    .wglGetVideoInfoNV = epoxy_wglGetVideoInfoNV_dispatch_table_rewrite_ptr,
    .wglIsEnabledFrameLockI3D = epoxy_wglIsEnabledFrameLockI3D_dispatch_table_rewrite_ptr,
    .wglIsEnabledGenlockI3D = epoxy_wglIsEnabledGenlockI3D_dispatch_table_rewrite_ptr,
    .wglJoinSwapGroupNV = epoxy_wglJoinSwapGroupNV_dispatch_table_rewrite_ptr,
    .wglLoadDisplayColorTableEXT = epoxy_wglLoadDisplayColorTableEXT_dispatch_table_rewrite_ptr,
    .wglLockVideoCaptureDeviceNV = epoxy_wglLockVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .wglMakeAssociatedContextCurrentAMD = epoxy_wglMakeAssociatedContextCurrentAMD_dispatch_table_rewrite_ptr,
    .wglMakeContextCurrentARB = epoxy_wglMakeContextCurrentARB_dispatch_table_rewrite_ptr,
    .wglMakeContextCurrentEXT = epoxy_wglMakeContextCurrentEXT_dispatch_table_rewrite_ptr,
    .wglMakeCurrent = epoxy_wglMakeCurrent_dispatch_table_rewrite_ptr,
    .wglQueryCurrentContextNV = epoxy_wglQueryCurrentContextNV_dispatch_table_rewrite_ptr,
    .wglQueryFrameCountNV = epoxy_wglQueryFrameCountNV_dispatch_table_rewrite_ptr,
    .wglQueryFrameLockMasterI3D = epoxy_wglQueryFrameLockMasterI3D_dispatch_table_rewrite_ptr,
    .wglQueryFrameTrackingI3D = epoxy_wglQueryFrameTrackingI3D_dispatch_table_rewrite_ptr,
    .wglQueryGenlockMaxSourceDelayI3D = epoxy_wglQueryGenlockMaxSourceDelayI3D_dispatch_table_rewrite_ptr,
    .wglQueryMaxSwapGroupsNV = epoxy_wglQueryMaxSwapGroupsNV_dispatch_table_rewrite_ptr,
    .wglQueryPbufferARB = epoxy_wglQueryPbufferARB_dispatch_table_rewrite_ptr,
    .wglQueryPbufferEXT = epoxy_wglQueryPbufferEXT_dispatch_table_rewrite_ptr,
    .wglQuerySwapGroupNV = epoxy_wglQuerySwapGroupNV_dispatch_table_rewrite_ptr,
    .wglQueryVideoCaptureDeviceNV = epoxy_wglQueryVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .wglRealizeLayerPalette = epoxy_wglRealizeLayerPalette_dispatch_table_rewrite_ptr,
    .wglReleaseImageBufferEventsI3D = epoxy_wglReleaseImageBufferEventsI3D_dispatch_table_rewrite_ptr,
    .wglReleasePbufferDCARB = epoxy_wglReleasePbufferDCARB_dispatch_table_rewrite_ptr,
    .wglReleasePbufferDCEXT = epoxy_wglReleasePbufferDCEXT_dispatch_table_rewrite_ptr,
    .wglReleaseTexImageARB = epoxy_wglReleaseTexImageARB_dispatch_table_rewrite_ptr,
    .wglReleaseVideoCaptureDeviceNV = epoxy_wglReleaseVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .wglReleaseVideoDeviceNV = epoxy_wglReleaseVideoDeviceNV_dispatch_table_rewrite_ptr,
    .wglReleaseVideoImageNV = epoxy_wglReleaseVideoImageNV_dispatch_table_rewrite_ptr,
    .wglResetFrameCountNV = epoxy_wglResetFrameCountNV_dispatch_table_rewrite_ptr,
    .wglRestoreBufferRegionARB = epoxy_wglRestoreBufferRegionARB_dispatch_table_rewrite_ptr,
    .wglSaveBufferRegionARB = epoxy_wglSaveBufferRegionARB_dispatch_table_rewrite_ptr,
    .wglSendPbufferToVideoNV = epoxy_wglSendPbufferToVideoNV_dispatch_table_rewrite_ptr,
    .wglSetDigitalVideoParametersI3D = epoxy_wglSetDigitalVideoParametersI3D_dispatch_table_rewrite_ptr,
    .wglSetGammaTableI3D = epoxy_wglSetGammaTableI3D_dispatch_table_rewrite_ptr,
    .wglSetGammaTableParametersI3D = epoxy_wglSetGammaTableParametersI3D_dispatch_table_rewrite_ptr,
    .wglSetLayerPaletteEntries = epoxy_wglSetLayerPaletteEntries_dispatch_table_rewrite_ptr,
    .wglSetPbufferAttribARB = epoxy_wglSetPbufferAttribARB_dispatch_table_rewrite_ptr,
    .wglSetStereoEmitterState3DL = epoxy_wglSetStereoEmitterState3DL_dispatch_table_rewrite_ptr,
    .wglShareLists = epoxy_wglShareLists_dispatch_table_rewrite_ptr,
    .wglSwapBuffersMscOML = epoxy_wglSwapBuffersMscOML_dispatch_table_rewrite_ptr,
    .wglSwapIntervalEXT = epoxy_wglSwapIntervalEXT_dispatch_table_rewrite_ptr,
    .wglSwapLayerBuffers = epoxy_wglSwapLayerBuffers_dispatch_table_rewrite_ptr,
    .wglSwapLayerBuffersMscOML = epoxy_wglSwapLayerBuffersMscOML_dispatch_table_rewrite_ptr,
    .wglUseFontBitmapsA = epoxy_wglUseFontBitmapsA_dispatch_table_rewrite_ptr,
    .wglUseFontBitmapsW = epoxy_wglUseFontBitmapsW_dispatch_table_rewrite_ptr,
    .wglUseFontOutlines = epoxy_wglUseFontOutlines_dispatch_table_rewrite_ptr,
    .wglUseFontOutlinesA = epoxy_wglUseFontOutlinesA_dispatch_table_rewrite_ptr,
    .wglUseFontOutlinesW = epoxy_wglUseFontOutlinesW_dispatch_table_rewrite_ptr,
    .wglWaitForMscOML = epoxy_wglWaitForMscOML_dispatch_table_rewrite_ptr,
    .wglWaitForSbcOML = epoxy_wglWaitForSbcOML_dispatch_table_rewrite_ptr,
};
#endif /* PLATFORM_HAS_WGL */
