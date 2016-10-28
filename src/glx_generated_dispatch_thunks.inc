/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#include "dispatch_common.h"
#if PLATFORM_HAS_GLX

static void *glx_provider_resolver(tls_ptr tls, const char *name,
                                   const enum glx_provider *providers,
                                   const uint16_t *entrypoints)
{
    int i;
    for (i = 0; providers[i] != glx_provider_terminator; i++) {
        switch (providers[i]) {
        case GLX_10:
            if (true)
                return epoxy_glx_dlsym(tls, glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_11:
            if (true)
                return epoxy_glx_dlsym(tls, glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_12:
            if (true)
                return epoxy_glx_dlsym(tls, glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_13:
            if (true)
                return epoxy_glx_dlsym(tls, glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_AMD_gpu_association:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_AMD_gpu_association"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_ARB_create_context:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_ARB_create_context"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_ARB_get_proc_address:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_ARB_get_proc_address"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_EXT_import_context:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_EXT_import_context"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_EXT_swap_control:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_EXT_swap_control"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_EXT_texture_from_pixmap:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_EXT_texture_from_pixmap"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_MESA_agp_offset:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_MESA_agp_offset"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_MESA_copy_sub_buffer:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_MESA_copy_sub_buffer"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_MESA_pixmap_colormap:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_MESA_pixmap_colormap"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_MESA_query_renderer:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_MESA_query_renderer"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_MESA_release_buffers:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_MESA_release_buffers"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_MESA_set_3dfx_mode:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_MESA_set_3dfx_mode"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_copy_buffer:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_copy_buffer"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_copy_image:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_copy_image"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_delay_before_swap:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_delay_before_swap"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_present_video:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_present_video"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_swap_group:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_swap_group"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_video_capture:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_video_capture"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_NV_video_out:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_NV_video_out"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_OML_sync_control:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_OML_sync_control"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_fbconfig:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_fbconfig"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_hyperpipe:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_hyperpipe"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_pbuffer:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_pbuffer"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_swap_barrier:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_swap_barrier"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_swap_group:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_swap_group"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_video_resize:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_video_resize"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGIX_video_source:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGIX_video_source"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGI_cushion:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGI_cushion"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGI_make_current_read:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGI_make_current_read"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGI_swap_control:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGI_swap_control"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SGI_video_sync:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SGI_video_sync"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case GLX_extension_GLX_SUN_get_transparent_index:
            if (epoxy_conservative_has_glx_extension(tls, "GLX_SUN_get_transparent_index"))
                return glXGetProcAddress((const GLubyte *)glx_entrypoint_strings[entrypoints[i]]);
            break;
        case always_present:
            if (true)
                return epoxy_glx_dlsym(tls, glx_entrypoint_strings[entrypoints[i]]);
            break;
        case glx_provider_terminator:
            abort(); /* Not reached */
        }
    }

    fprintf(stderr, "No provider of %s found.  Requires one of:\n", name);
    for (i = 0; providers[i] != glx_provider_terminator; i++) {
        fprintf(stderr, "    %s\n", glx_enum_string + glx_enum_string_offsets[providers[i]]);
    }
    if (providers[0] == glx_provider_terminator) {
        fprintf(stderr, "    No known providers.  This is likely a bug "
                        "in libepoxy code generation\n");
    }
    abort();
}

EPOXY_NOINLINE static void *
glx_single_resolver(tls_ptr tls, enum glx_provider provider, uint16_t entrypoint_offset);

static void *
glx_single_resolver(tls_ptr tls, enum glx_provider provider, uint16_t entrypoint_offset)
{
    enum glx_provider providers[] = {
        provider,
        glx_provider_terminator
    };
    return glx_provider_resolver(tls, glx_entrypoint_strings[entrypoint_offset],
                                providers, &entrypoint_offset);
}

static PFNGLXBINDCHANNELTOWINDOWSGIXPROC
epoxy_glXBindChannelToWindowSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_video_resize, 0 /* glXBindChannelToWindowSGIX */);
}

static PFNGLXBINDHYPERPIPESGIXPROC
epoxy_glXBindHyperpipeSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 1 /* glXBindHyperpipeSGIX */);
}

static PFNGLXBINDSWAPBARRIERNVPROC
epoxy_glXBindSwapBarrierNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_swap_group, 2 /* glXBindSwapBarrierNV */);
}

static PFNGLXBINDSWAPBARRIERSGIXPROC
epoxy_glXBindSwapBarrierSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_swap_barrier, 3 /* glXBindSwapBarrierSGIX */);
}

static PFNGLXBINDTEXIMAGEEXTPROC
epoxy_glXBindTexImageEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_texture_from_pixmap, 4 /* glXBindTexImageEXT */);
}

static PFNGLXBINDVIDEOCAPTUREDEVICENVPROC
epoxy_glXBindVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_capture, 5 /* glXBindVideoCaptureDeviceNV */);
}

static PFNGLXBINDVIDEODEVICENVPROC
epoxy_glXBindVideoDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_present_video, 6 /* glXBindVideoDeviceNV */);
}

static PFNGLXBINDVIDEOIMAGENVPROC
epoxy_glXBindVideoImageNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_out, 7 /* glXBindVideoImageNV */);
}

static PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC
epoxy_glXBlitContextFramebufferAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 8 /* glXBlitContextFramebufferAMD */);
}

static PFNGLXCHANNELRECTSGIXPROC
epoxy_glXChannelRectSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_video_resize, 9 /* glXChannelRectSGIX */);
}

static PFNGLXCHANNELRECTSYNCSGIXPROC
epoxy_glXChannelRectSyncSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_video_resize, 10 /* glXChannelRectSyncSGIX */);
}

static PFNGLXCHOOSEFBCONFIGPROC
epoxy_glXChooseFBConfig_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 11 /* glXChooseFBConfig */);
}

static PFNGLXCHOOSEFBCONFIGSGIXPROC
epoxy_glXChooseFBConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_fbconfig, 12 /* glXChooseFBConfigSGIX */);
}

static PFNGLXCHOOSEVISUALPROC
epoxy_glXChooseVisual_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 13 /* glXChooseVisual */);
}

static PFNGLXCOPYBUFFERSUBDATANVPROC
epoxy_glXCopyBufferSubDataNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_copy_buffer, 14 /* glXCopyBufferSubDataNV */);
}

static PFNGLXCOPYCONTEXTPROC
epoxy_glXCopyContext_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 15 /* glXCopyContext */);
}

static PFNGLXCOPYIMAGESUBDATANVPROC
epoxy_glXCopyImageSubDataNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_copy_image, 16 /* glXCopyImageSubDataNV */);
}

static PFNGLXCOPYSUBBUFFERMESAPROC
epoxy_glXCopySubBufferMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_copy_sub_buffer, 17 /* glXCopySubBufferMESA */);
}

static PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC
epoxy_glXCreateAssociatedContextAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 18 /* glXCreateAssociatedContextAMD */);
}

static PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC
epoxy_glXCreateAssociatedContextAttribsAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 19 /* glXCreateAssociatedContextAttribsAMD */);
}

static PFNGLXCREATECONTEXTPROC
epoxy_glXCreateContext_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 20 /* glXCreateContext */);
}

static PFNGLXCREATECONTEXTATTRIBSARBPROC
epoxy_glXCreateContextAttribsARB_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_ARB_create_context, 21 /* glXCreateContextAttribsARB */);
}

static PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC
epoxy_glXCreateContextWithConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_fbconfig, 22 /* glXCreateContextWithConfigSGIX */);
}

static PFNGLXCREATEGLXPBUFFERSGIXPROC
epoxy_glXCreateGLXPbufferSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_pbuffer, 23 /* glXCreateGLXPbufferSGIX */);
}

static PFNGLXCREATEGLXPIXMAPPROC
epoxy_glXCreateGLXPixmap_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 24 /* glXCreateGLXPixmap */);
}

static PFNGLXCREATEGLXPIXMAPMESAPROC
epoxy_glXCreateGLXPixmapMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_pixmap_colormap, 25 /* glXCreateGLXPixmapMESA */);
}

static PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC
epoxy_glXCreateGLXPixmapWithConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_fbconfig, 26 /* glXCreateGLXPixmapWithConfigSGIX */);
}

static PFNGLXCREATENEWCONTEXTPROC
epoxy_glXCreateNewContext_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 27 /* glXCreateNewContext */);
}

static PFNGLXCREATEPBUFFERPROC
epoxy_glXCreatePbuffer_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 28 /* glXCreatePbuffer */);
}

static PFNGLXCREATEPIXMAPPROC
epoxy_glXCreatePixmap_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 29 /* glXCreatePixmap */);
}

static PFNGLXCREATEWINDOWPROC
epoxy_glXCreateWindow_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 30 /* glXCreateWindow */);
}

static PFNGLXCUSHIONSGIPROC
epoxy_glXCushionSGI_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGI_cushion, 31 /* glXCushionSGI */);
}

static PFNGLXDELAYBEFORESWAPNVPROC
epoxy_glXDelayBeforeSwapNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_delay_before_swap, 32 /* glXDelayBeforeSwapNV */);
}

static PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC
epoxy_glXDeleteAssociatedContextAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 33 /* glXDeleteAssociatedContextAMD */);
}

static PFNGLXDESTROYCONTEXTPROC
epoxy_glXDestroyContext_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 34 /* glXDestroyContext */);
}

static PFNGLXDESTROYGLXPBUFFERSGIXPROC
epoxy_glXDestroyGLXPbufferSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_pbuffer, 35 /* glXDestroyGLXPbufferSGIX */);
}

static PFNGLXDESTROYGLXPIXMAPPROC
epoxy_glXDestroyGLXPixmap_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 36 /* glXDestroyGLXPixmap */);
}

static PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC
epoxy_glXDestroyGLXVideoSourceSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_video_source, 37 /* glXDestroyGLXVideoSourceSGIX */);
}

static PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC
epoxy_glXDestroyHyperpipeConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 38 /* glXDestroyHyperpipeConfigSGIX */);
}

static PFNGLXDESTROYPBUFFERPROC
epoxy_glXDestroyPbuffer_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 39 /* glXDestroyPbuffer */);
}

static PFNGLXDESTROYPIXMAPPROC
epoxy_glXDestroyPixmap_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 40 /* glXDestroyPixmap */);
}

static PFNGLXDESTROYWINDOWPROC
epoxy_glXDestroyWindow_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 41 /* glXDestroyWindow */);
}

static PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC
epoxy_glXEnumerateVideoCaptureDevicesNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_capture, 42 /* glXEnumerateVideoCaptureDevicesNV */);
}

static PFNGLXENUMERATEVIDEODEVICESNVPROC
epoxy_glXEnumerateVideoDevicesNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_present_video, 43 /* glXEnumerateVideoDevicesNV */);
}

static PFNGLXFREECONTEXTEXTPROC
epoxy_glXFreeContextEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_import_context, 44 /* glXFreeContextEXT */);
}

static PFNGLXGETAGPOFFSETMESAPROC
epoxy_glXGetAGPOffsetMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_agp_offset, 45 /* glXGetAGPOffsetMESA */);
}

static PFNGLXGETCLIENTSTRINGPROC
epoxy_glXGetClientString_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_11, 46 /* glXGetClientString */);
}

static PFNGLXGETCONFIGPROC
epoxy_glXGetConfig_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 47 /* glXGetConfig */);
}

static PFNGLXGETCONTEXTGPUIDAMDPROC
epoxy_glXGetContextGPUIDAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 48 /* glXGetContextGPUIDAMD */);
}

static PFNGLXGETCONTEXTIDEXTPROC
epoxy_glXGetContextIDEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_import_context, 49 /* glXGetContextIDEXT */);
}

static PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC
epoxy_glXGetCurrentAssociatedContextAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 50 /* glXGetCurrentAssociatedContextAMD */);
}

static PFNGLXGETCURRENTCONTEXTPROC
epoxy_glXGetCurrentContext_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 51 /* glXGetCurrentContext */);
}

static PFNGLXGETCURRENTDISPLAYPROC
epoxy_glXGetCurrentDisplay_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_12, 52 /* glXGetCurrentDisplay */);
}

static PFNGLXGETCURRENTDISPLAYEXTPROC
epoxy_glXGetCurrentDisplayEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_import_context, 53 /* glXGetCurrentDisplayEXT */);
}

static PFNGLXGETCURRENTDRAWABLEPROC
epoxy_glXGetCurrentDrawable_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 54 /* glXGetCurrentDrawable */);
}

static PFNGLXGETCURRENTREADDRAWABLEPROC
epoxy_glXGetCurrentReadDrawable_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 55 /* glXGetCurrentReadDrawable */);
}

static PFNGLXGETCURRENTREADDRAWABLESGIPROC
epoxy_glXGetCurrentReadDrawableSGI_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGI_make_current_read, 56 /* glXGetCurrentReadDrawableSGI */);
}

static PFNGLXGETFBCONFIGATTRIBPROC
epoxy_glXGetFBConfigAttrib_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 57 /* glXGetFBConfigAttrib */);
}

static PFNGLXGETFBCONFIGATTRIBSGIXPROC
epoxy_glXGetFBConfigAttribSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_fbconfig, 58 /* glXGetFBConfigAttribSGIX */);
}

static PFNGLXGETFBCONFIGFROMVISUALSGIXPROC
epoxy_glXGetFBConfigFromVisualSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_fbconfig, 59 /* glXGetFBConfigFromVisualSGIX */);
}

static PFNGLXGETFBCONFIGSPROC
epoxy_glXGetFBConfigs_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 60 /* glXGetFBConfigs */);
}

static PFNGLXGETGPUIDSAMDPROC
epoxy_glXGetGPUIDsAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 61 /* glXGetGPUIDsAMD */);
}

static PFNGLXGETGPUINFOAMDPROC
epoxy_glXGetGPUInfoAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 62 /* glXGetGPUInfoAMD */);
}

static PFNGLXGETMSCRATEOMLPROC
epoxy_glXGetMscRateOML_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_OML_sync_control, 63 /* glXGetMscRateOML */);
}

static PFNGLXGETPROCADDRESSPROC
epoxy_glXGetProcAddress_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, always_present, 64 /* glXGetProcAddress */);
}

static PFNGLXGETPROCADDRESSARBPROC
epoxy_glXGetProcAddressARB_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_ARB_get_proc_address, 65 /* glXGetProcAddressARB */);
}

static PFNGLXGETSELECTEDEVENTPROC
epoxy_glXGetSelectedEvent_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 66 /* glXGetSelectedEvent */);
}

static PFNGLXGETSELECTEDEVENTSGIXPROC
epoxy_glXGetSelectedEventSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_pbuffer, 67 /* glXGetSelectedEventSGIX */);
}

static PFNGLXGETSYNCVALUESOMLPROC
epoxy_glXGetSyncValuesOML_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_OML_sync_control, 68 /* glXGetSyncValuesOML */);
}

static PFNGLXGETTRANSPARENTINDEXSUNPROC
epoxy_glXGetTransparentIndexSUN_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SUN_get_transparent_index, 69 /* glXGetTransparentIndexSUN */);
}

static PFNGLXGETVIDEODEVICENVPROC
epoxy_glXGetVideoDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_out, 70 /* glXGetVideoDeviceNV */);
}

static PFNGLXGETVIDEOINFONVPROC
epoxy_glXGetVideoInfoNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_out, 71 /* glXGetVideoInfoNV */);
}

static PFNGLXGETVIDEOSYNCSGIPROC
epoxy_glXGetVideoSyncSGI_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGI_video_sync, 72 /* glXGetVideoSyncSGI */);
}

static PFNGLXGETVISUALFROMFBCONFIGPROC
epoxy_glXGetVisualFromFBConfig_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 73 /* glXGetVisualFromFBConfig */);
}

static PFNGLXGETVISUALFROMFBCONFIGSGIXPROC
epoxy_glXGetVisualFromFBConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_fbconfig, 74 /* glXGetVisualFromFBConfigSGIX */);
}

static PFNGLXHYPERPIPEATTRIBSGIXPROC
epoxy_glXHyperpipeAttribSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 75 /* glXHyperpipeAttribSGIX */);
}

static PFNGLXHYPERPIPECONFIGSGIXPROC
epoxy_glXHyperpipeConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 76 /* glXHyperpipeConfigSGIX */);
}

static PFNGLXIMPORTCONTEXTEXTPROC
epoxy_glXImportContextEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_import_context, 77 /* glXImportContextEXT */);
}

static PFNGLXISDIRECTPROC
epoxy_glXIsDirect_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 78 /* glXIsDirect */);
}

static PFNGLXJOINSWAPGROUPNVPROC
epoxy_glXJoinSwapGroupNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_swap_group, 79 /* glXJoinSwapGroupNV */);
}

static PFNGLXJOINSWAPGROUPSGIXPROC
epoxy_glXJoinSwapGroupSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_swap_group, 80 /* glXJoinSwapGroupSGIX */);
}

static PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC
epoxy_glXLockVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_capture, 81 /* glXLockVideoCaptureDeviceNV */);
}

static PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC
epoxy_glXMakeAssociatedContextCurrentAMD_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_AMD_gpu_association, 82 /* glXMakeAssociatedContextCurrentAMD */);
}

static PFNGLXMAKECONTEXTCURRENTPROC
epoxy_glXMakeContextCurrent_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 83 /* glXMakeContextCurrent */);
}

static PFNGLXMAKECURRENTPROC
epoxy_glXMakeCurrent_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 84 /* glXMakeCurrent */);
}

static PFNGLXMAKECURRENTREADSGIPROC
epoxy_glXMakeCurrentReadSGI_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGI_make_current_read, 85 /* glXMakeCurrentReadSGI */);
}

static PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC
epoxy_glXNamedCopyBufferSubDataNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_copy_buffer, 86 /* glXNamedCopyBufferSubDataNV */);
}

static PFNGLXQUERYCHANNELDELTASSGIXPROC
epoxy_glXQueryChannelDeltasSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_video_resize, 87 /* glXQueryChannelDeltasSGIX */);
}

static PFNGLXQUERYCHANNELRECTSGIXPROC
epoxy_glXQueryChannelRectSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_video_resize, 88 /* glXQueryChannelRectSGIX */);
}

static PFNGLXQUERYCONTEXTPROC
epoxy_glXQueryContext_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 89 /* glXQueryContext */);
}

static PFNGLXQUERYCONTEXTINFOEXTPROC
epoxy_glXQueryContextInfoEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_import_context, 90 /* glXQueryContextInfoEXT */);
}

static PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC
epoxy_glXQueryCurrentRendererIntegerMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_query_renderer, 91 /* glXQueryCurrentRendererIntegerMESA */);
}

static PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC
epoxy_glXQueryCurrentRendererStringMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_query_renderer, 92 /* glXQueryCurrentRendererStringMESA */);
}

static PFNGLXQUERYDRAWABLEPROC
epoxy_glXQueryDrawable_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 93 /* glXQueryDrawable */);
}

static PFNGLXQUERYEXTENSIONPROC
epoxy_glXQueryExtension_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 94 /* glXQueryExtension */);
}

static PFNGLXQUERYEXTENSIONSSTRINGPROC
epoxy_glXQueryExtensionsString_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_11, 95 /* glXQueryExtensionsString */);
}

static PFNGLXQUERYFRAMECOUNTNVPROC
epoxy_glXQueryFrameCountNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_swap_group, 96 /* glXQueryFrameCountNV */);
}

static PFNGLXQUERYGLXPBUFFERSGIXPROC
epoxy_glXQueryGLXPbufferSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_pbuffer, 97 /* glXQueryGLXPbufferSGIX */);
}

static PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC
epoxy_glXQueryHyperpipeAttribSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 98 /* glXQueryHyperpipeAttribSGIX */);
}

static PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC
epoxy_glXQueryHyperpipeBestAttribSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 99 /* glXQueryHyperpipeBestAttribSGIX */);
}

static PFNGLXQUERYHYPERPIPECONFIGSGIXPROC
epoxy_glXQueryHyperpipeConfigSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 100 /* glXQueryHyperpipeConfigSGIX */);
}

static PFNGLXQUERYHYPERPIPENETWORKSGIXPROC
epoxy_glXQueryHyperpipeNetworkSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_hyperpipe, 101 /* glXQueryHyperpipeNetworkSGIX */);
}

static PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC
epoxy_glXQueryMaxSwapBarriersSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_swap_barrier, 102 /* glXQueryMaxSwapBarriersSGIX */);
}

static PFNGLXQUERYMAXSWAPGROUPSNVPROC
epoxy_glXQueryMaxSwapGroupsNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_swap_group, 103 /* glXQueryMaxSwapGroupsNV */);
}

static PFNGLXQUERYRENDERERINTEGERMESAPROC
epoxy_glXQueryRendererIntegerMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_query_renderer, 104 /* glXQueryRendererIntegerMESA */);
}

static PFNGLXQUERYRENDERERSTRINGMESAPROC
epoxy_glXQueryRendererStringMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_query_renderer, 105 /* glXQueryRendererStringMESA */);
}

static PFNGLXQUERYSERVERSTRINGPROC
epoxy_glXQueryServerString_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_11, 106 /* glXQueryServerString */);
}

static PFNGLXQUERYSWAPGROUPNVPROC
epoxy_glXQuerySwapGroupNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_swap_group, 107 /* glXQuerySwapGroupNV */);
}

static PFNGLXQUERYVERSIONPROC
epoxy_glXQueryVersion_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 108 /* glXQueryVersion */);
}

static PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC
epoxy_glXQueryVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_capture, 109 /* glXQueryVideoCaptureDeviceNV */);
}

static PFNGLXRELEASEBUFFERSMESAPROC
epoxy_glXReleaseBuffersMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_release_buffers, 110 /* glXReleaseBuffersMESA */);
}

static PFNGLXRELEASETEXIMAGEEXTPROC
epoxy_glXReleaseTexImageEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_texture_from_pixmap, 111 /* glXReleaseTexImageEXT */);
}

static PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC
epoxy_glXReleaseVideoCaptureDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_capture, 112 /* glXReleaseVideoCaptureDeviceNV */);
}

static PFNGLXRELEASEVIDEODEVICENVPROC
epoxy_glXReleaseVideoDeviceNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_out, 113 /* glXReleaseVideoDeviceNV */);
}

static PFNGLXRELEASEVIDEOIMAGENVPROC
epoxy_glXReleaseVideoImageNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_out, 114 /* glXReleaseVideoImageNV */);
}

static PFNGLXRESETFRAMECOUNTNVPROC
epoxy_glXResetFrameCountNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_swap_group, 115 /* glXResetFrameCountNV */);
}

static PFNGLXSELECTEVENTPROC
epoxy_glXSelectEvent_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_13, 116 /* glXSelectEvent */);
}

static PFNGLXSELECTEVENTSGIXPROC
epoxy_glXSelectEventSGIX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGIX_pbuffer, 117 /* glXSelectEventSGIX */);
}

static PFNGLXSENDPBUFFERTOVIDEONVPROC
epoxy_glXSendPbufferToVideoNV_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_NV_video_out, 118 /* glXSendPbufferToVideoNV */);
}

static PFNGLXSET3DFXMODEMESAPROC
epoxy_glXSet3DfxModeMESA_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_MESA_set_3dfx_mode, 119 /* glXSet3DfxModeMESA */);
}

static PFNGLXSWAPBUFFERSPROC
epoxy_glXSwapBuffers_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 120 /* glXSwapBuffers */);
}

static PFNGLXSWAPBUFFERSMSCOMLPROC
epoxy_glXSwapBuffersMscOML_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_OML_sync_control, 121 /* glXSwapBuffersMscOML */);
}

static PFNGLXSWAPINTERVALEXTPROC
epoxy_glXSwapIntervalEXT_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_EXT_swap_control, 122 /* glXSwapIntervalEXT */);
}

static PFNGLXSWAPINTERVALSGIPROC
epoxy_glXSwapIntervalSGI_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGI_swap_control, 123 /* glXSwapIntervalSGI */);
}

static PFNGLXUSEXFONTPROC
epoxy_glXUseXFont_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 124 /* glXUseXFont */);
}

static PFNGLXWAITFORMSCOMLPROC
epoxy_glXWaitForMscOML_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_OML_sync_control, 125 /* glXWaitForMscOML */);
}

static PFNGLXWAITFORSBCOMLPROC
epoxy_glXWaitForSbcOML_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_OML_sync_control, 126 /* glXWaitForSbcOML */);
}

static PFNGLXWAITGLPROC
epoxy_glXWaitGL_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 127 /* glXWaitGL */);
}

static PFNGLXWAITVIDEOSYNCSGIPROC
epoxy_glXWaitVideoSyncSGI_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_extension_GLX_SGI_video_sync, 128 /* glXWaitVideoSyncSGI */);
}

static PFNGLXWAITXPROC
epoxy_glXWaitX_resolver(tls_ptr tls)
{
    return glx_single_resolver(tls, GLX_10, 129 /* glXWaitX */);
}

GEN_THUNKS_RET(glx, int, glXBindChannelToWindowSGIX, (Display * display, int screen, int channel, Window window), (display, screen, channel, window))
GEN_THUNKS_RET(glx, int, glXBindHyperpipeSGIX, (Display * dpy, int hpId), (dpy, hpId))
GEN_THUNKS_RET(glx, Bool, glXBindSwapBarrierNV, (Display * dpy, GLuint group, GLuint barrier), (dpy, group, barrier))
GEN_THUNKS(glx, glXBindSwapBarrierSGIX, (Display * dpy, GLXDrawable drawable, int barrier), (dpy, drawable, barrier))
GEN_THUNKS(glx, glXBindTexImageEXT, (Display * dpy, GLXDrawable drawable, int buffer, const int * attrib_list), (dpy, drawable, buffer, attrib_list))
GEN_THUNKS_RET(glx, int, glXBindVideoCaptureDeviceNV, (Display * dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device), (dpy, video_capture_slot, device))
GEN_THUNKS_RET(glx, int, glXBindVideoDeviceNV, (Display * dpy, unsigned int video_slot, unsigned int video_device, const int * attrib_list), (dpy, video_slot, video_device, attrib_list))
GEN_THUNKS_RET(glx, int, glXBindVideoImageNV, (Display * dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer), (dpy, VideoDevice, pbuf, iVideoBuffer))
GEN_THUNKS(glx, glXBlitContextFramebufferAMD, (GLXContext dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), (dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter))
GEN_THUNKS_RET(glx, int, glXChannelRectSGIX, (Display * display, int screen, int channel, int x, int y, int w, int h), (display, screen, channel, x, y, w, h))
GEN_THUNKS_RET(glx, int, glXChannelRectSyncSGIX, (Display * display, int screen, int channel, GLenum synctype), (display, screen, channel, synctype))
GEN_THUNKS_RET(glx, GLXFBConfig *, glXChooseFBConfig, (Display * dpy, int screen, const int * attrib_list, int * nelements), (dpy, screen, attrib_list, nelements))
GEN_THUNKS_RET(glx, GLXFBConfigSGIX *, glXChooseFBConfigSGIX, (Display * dpy, int screen, int * attrib_list, int * nelements), (dpy, screen, attrib_list, nelements))
GEN_THUNKS_RET(glx, XVisualInfo *, glXChooseVisual, (Display * dpy, int screen, int * attribList), (dpy, screen, attribList))
GEN_THUNKS(glx, glXCopyBufferSubDataNV, (Display * dpy, GLXContext readCtx, GLXContext writeCtx, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size), (dpy, readCtx, writeCtx, readTarget, writeTarget, readOffset, writeOffset, size))
GEN_THUNKS(glx, glXCopyContext, (Display * dpy, GLXContext src, GLXContext dst, unsigned long mask), (dpy, src, dst, mask))
GEN_THUNKS(glx, glXCopyImageSubDataNV, (Display * dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth), (dpy, srcCtx, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstCtx, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth))
GEN_THUNKS(glx, glXCopySubBufferMESA, (Display * dpy, GLXDrawable drawable, int x, int y, int width, int height), (dpy, drawable, x, y, width, height))
GEN_THUNKS_RET(glx, GLXContext, glXCreateAssociatedContextAMD, (unsigned int id, GLXContext share_list), (id, share_list))
GEN_THUNKS_RET(glx, GLXContext, glXCreateAssociatedContextAttribsAMD, (unsigned int id, GLXContext share_context, const int * attribList), (id, share_context, attribList))
GEN_THUNKS_RET(glx, GLXContext, glXCreateContext, (Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct), (dpy, vis, shareList, direct))
GEN_THUNKS_RET(glx, GLXContext, glXCreateContextAttribsARB, (Display * dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int * attrib_list), (dpy, config, share_context, direct, attrib_list))
GEN_THUNKS_RET(glx, GLXContext, glXCreateContextWithConfigSGIX, (Display * dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct), (dpy, config, render_type, share_list, direct))
GEN_THUNKS_RET(glx, GLXPbufferSGIX, glXCreateGLXPbufferSGIX, (Display * dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int * attrib_list), (dpy, config, width, height, attrib_list))
GEN_THUNKS_RET(glx, GLXPixmap, glXCreateGLXPixmap, (Display * dpy, XVisualInfo * visual, Pixmap pixmap), (dpy, visual, pixmap))
GEN_THUNKS_RET(glx, GLXPixmap, glXCreateGLXPixmapMESA, (Display * dpy, XVisualInfo * visual, Pixmap pixmap, Colormap cmap), (dpy, visual, pixmap, cmap))
GEN_THUNKS_RET(glx, GLXPixmap, glXCreateGLXPixmapWithConfigSGIX, (Display * dpy, GLXFBConfigSGIX config, Pixmap pixmap), (dpy, config, pixmap))
GEN_THUNKS_RET(glx, GLXContext, glXCreateNewContext, (Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct), (dpy, config, render_type, share_list, direct))
GEN_THUNKS_RET(glx, GLXPbuffer, glXCreatePbuffer, (Display * dpy, GLXFBConfig config, const int * attrib_list), (dpy, config, attrib_list))
GEN_THUNKS_RET(glx, GLXPixmap, glXCreatePixmap, (Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list), (dpy, config, pixmap, attrib_list))
GEN_THUNKS_RET(glx, GLXWindow, glXCreateWindow, (Display * dpy, GLXFBConfig config, Window win, const int * attrib_list), (dpy, config, win, attrib_list))
GEN_THUNKS(glx, glXCushionSGI, (Display * dpy, Window window, float cushion), (dpy, window, cushion))
GEN_THUNKS_RET(glx, Bool, glXDelayBeforeSwapNV, (Display * dpy, GLXDrawable drawable, GLfloat seconds), (dpy, drawable, seconds))
GEN_THUNKS_RET(glx, Bool, glXDeleteAssociatedContextAMD, (GLXContext ctx), (ctx))
GEN_THUNKS(glx, glXDestroyContext, (Display * dpy, GLXContext ctx), (dpy, ctx))
GEN_THUNKS(glx, glXDestroyGLXPbufferSGIX, (Display * dpy, GLXPbufferSGIX pbuf), (dpy, pbuf))
GEN_THUNKS(glx, glXDestroyGLXPixmap, (Display * dpy, GLXPixmap pixmap), (dpy, pixmap))
GEN_THUNKS(glx, glXDestroyGLXVideoSourceSGIX, (Display * dpy, GLXVideoSourceSGIX glxvideosource), (dpy, glxvideosource))
GEN_THUNKS_RET(glx, int, glXDestroyHyperpipeConfigSGIX, (Display * dpy, int hpId), (dpy, hpId))
GEN_THUNKS(glx, glXDestroyPbuffer, (Display * dpy, GLXPbuffer pbuf), (dpy, pbuf))
GEN_THUNKS(glx, glXDestroyPixmap, (Display * dpy, GLXPixmap pixmap), (dpy, pixmap))
GEN_THUNKS(glx, glXDestroyWindow, (Display * dpy, GLXWindow win), (dpy, win))
GEN_THUNKS_RET(glx, GLXVideoCaptureDeviceNV *, glXEnumerateVideoCaptureDevicesNV, (Display * dpy, int screen, int * nelements), (dpy, screen, nelements))
GEN_THUNKS_RET(glx, unsigned int *, glXEnumerateVideoDevicesNV, (Display * dpy, int screen, int * nelements), (dpy, screen, nelements))
GEN_THUNKS(glx, glXFreeContextEXT, (Display * dpy, GLXContext context), (dpy, context))
GEN_THUNKS_RET(glx, unsigned int, glXGetAGPOffsetMESA, (const void * pointer), (pointer))
GEN_THUNKS_RET(glx, const char *, glXGetClientString, (Display * dpy, int name), (dpy, name))
GEN_THUNKS_RET(glx, int, glXGetConfig, (Display * dpy, XVisualInfo * visual, int attrib, int * value), (dpy, visual, attrib, value))
GEN_THUNKS_RET(glx, unsigned int, glXGetContextGPUIDAMD, (GLXContext ctx), (ctx))
GEN_THUNKS_RET(glx, GLXContextID, glXGetContextIDEXT, (const GLXContext context), (context))
GEN_THUNKS_RET(glx, GLXContext, glXGetCurrentAssociatedContextAMD, (void), ())
GEN_THUNKS_RET(glx, GLXContext, glXGetCurrentContext, (void), ())
GEN_THUNKS_RET(glx, Display *, glXGetCurrentDisplay, (void), ())
GEN_THUNKS_RET(glx, Display *, glXGetCurrentDisplayEXT, (void), ())
GEN_THUNKS_RET(glx, GLXDrawable, glXGetCurrentDrawable, (void), ())
GEN_THUNKS_RET(glx, GLXDrawable, glXGetCurrentReadDrawable, (void), ())
GEN_THUNKS_RET(glx, GLXDrawable, glXGetCurrentReadDrawableSGI, (void), ())
GEN_THUNKS_RET(glx, int, glXGetFBConfigAttrib, (Display * dpy, GLXFBConfig config, int attribute, int * value), (dpy, config, attribute, value))
GEN_THUNKS_RET(glx, int, glXGetFBConfigAttribSGIX, (Display * dpy, GLXFBConfigSGIX config, int attribute, int * value), (dpy, config, attribute, value))
GEN_THUNKS_RET(glx, GLXFBConfigSGIX, glXGetFBConfigFromVisualSGIX, (Display * dpy, XVisualInfo * vis), (dpy, vis))
GEN_THUNKS_RET(glx, GLXFBConfig *, glXGetFBConfigs, (Display * dpy, int screen, int * nelements), (dpy, screen, nelements))
GEN_THUNKS_RET(glx, unsigned int, glXGetGPUIDsAMD, (unsigned int maxCount, unsigned int * ids), (maxCount, ids))
GEN_THUNKS_RET(glx, int, glXGetGPUInfoAMD, (unsigned int id, int property, GLenum dataType, unsigned int size, void * data), (id, property, dataType, size, data))
GEN_THUNKS_RET(glx, Bool, glXGetMscRateOML, (Display * dpy, GLXDrawable drawable, int32_t * numerator, int32_t * denominator), (dpy, drawable, numerator, denominator))
GEN_THUNKS_RET(glx, __GLXextFuncPtr, glXGetProcAddress, (const GLubyte * procName), (procName))
GEN_THUNKS_RET(glx, __GLXextFuncPtr, glXGetProcAddressARB, (const GLubyte * procName), (procName))
GEN_THUNKS(glx, glXGetSelectedEvent, (Display * dpy, GLXDrawable draw, unsigned long * event_mask), (dpy, draw, event_mask))
GEN_THUNKS(glx, glXGetSelectedEventSGIX, (Display * dpy, GLXDrawable drawable, unsigned long * mask), (dpy, drawable, mask))
GEN_THUNKS_RET(glx, Bool, glXGetSyncValuesOML, (Display * dpy, GLXDrawable drawable, int64_t * ust, int64_t * msc, int64_t * sbc), (dpy, drawable, ust, msc, sbc))
GEN_THUNKS_RET(glx, Status, glXGetTransparentIndexSUN, (Display * dpy, Window overlay, Window underlay, long * pTransparentIndex), (dpy, overlay, underlay, pTransparentIndex))
GEN_THUNKS_RET(glx, int, glXGetVideoDeviceNV, (Display * dpy, int screen, int numVideoDevices, GLXVideoDeviceNV * pVideoDevice), (dpy, screen, numVideoDevices, pVideoDevice))
GEN_THUNKS_RET(glx, int, glXGetVideoInfoNV, (Display * dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo), (dpy, screen, VideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo))
GEN_THUNKS_RET(glx, int, glXGetVideoSyncSGI, (unsigned int * count), (count))
GEN_THUNKS_RET(glx, XVisualInfo *, glXGetVisualFromFBConfig, (Display * dpy, GLXFBConfig config), (dpy, config))
GEN_THUNKS_RET(glx, XVisualInfo *, glXGetVisualFromFBConfigSGIX, (Display * dpy, GLXFBConfigSGIX config), (dpy, config))
GEN_THUNKS_RET(glx, int, glXHyperpipeAttribSGIX, (Display * dpy, int timeSlice, int attrib, int size, void * attribList), (dpy, timeSlice, attrib, size, attribList))
GEN_THUNKS_RET(glx, int, glXHyperpipeConfigSGIX, (Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX * cfg, int * hpId), (dpy, networkId, npipes, cfg, hpId))
GEN_THUNKS_RET(glx, GLXContext, glXImportContextEXT, (Display * dpy, GLXContextID contextID), (dpy, contextID))
GEN_THUNKS_RET(glx, Bool, glXIsDirect, (Display * dpy, GLXContext ctx), (dpy, ctx))
GEN_THUNKS_RET(glx, Bool, glXJoinSwapGroupNV, (Display * dpy, GLXDrawable drawable, GLuint group), (dpy, drawable, group))
GEN_THUNKS(glx, glXJoinSwapGroupSGIX, (Display * dpy, GLXDrawable drawable, GLXDrawable member), (dpy, drawable, member))
GEN_THUNKS(glx, glXLockVideoCaptureDeviceNV, (Display * dpy, GLXVideoCaptureDeviceNV device), (dpy, device))
GEN_THUNKS_RET(glx, Bool, glXMakeAssociatedContextCurrentAMD, (GLXContext ctx), (ctx))
GEN_THUNKS_RET(glx, Bool, glXMakeContextCurrent, (Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx), (dpy, draw, read, ctx))
GEN_THUNKS_RET(glx, Bool, glXMakeCurrent, (Display * dpy, GLXDrawable drawable, GLXContext ctx), (dpy, drawable, ctx))
GEN_THUNKS_RET(glx, Bool, glXMakeCurrentReadSGI, (Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx), (dpy, draw, read, ctx))
GEN_THUNKS(glx, glXNamedCopyBufferSubDataNV, (Display * dpy, GLXContext readCtx, GLXContext writeCtx, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size), (dpy, readCtx, writeCtx, readBuffer, writeBuffer, readOffset, writeOffset, size))
GEN_THUNKS_RET(glx, int, glXQueryChannelDeltasSGIX, (Display * display, int screen, int channel, int * x, int * y, int * w, int * h), (display, screen, channel, x, y, w, h))
GEN_THUNKS_RET(glx, int, glXQueryChannelRectSGIX, (Display * display, int screen, int channel, int * dx, int * dy, int * dw, int * dh), (display, screen, channel, dx, dy, dw, dh))
GEN_THUNKS_RET(glx, int, glXQueryContext, (Display * dpy, GLXContext ctx, int attribute, int * value), (dpy, ctx, attribute, value))
GEN_THUNKS_RET(glx, int, glXQueryContextInfoEXT, (Display * dpy, GLXContext context, int attribute, int * value), (dpy, context, attribute, value))
GEN_THUNKS_RET(glx, Bool, glXQueryCurrentRendererIntegerMESA, (int attribute, unsigned int * value), (attribute, value))
GEN_THUNKS_RET(glx, const char *, glXQueryCurrentRendererStringMESA, (int attribute), (attribute))
GEN_THUNKS(glx, glXQueryDrawable, (Display * dpy, GLXDrawable draw, int attribute, unsigned int * value), (dpy, draw, attribute, value))
GEN_THUNKS_RET(glx, Bool, glXQueryExtension, (Display * dpy, int * errorb, int * event), (dpy, errorb, event))
GEN_THUNKS_RET(glx, const char *, glXQueryExtensionsString, (Display * dpy, int screen), (dpy, screen))
GEN_THUNKS_RET(glx, Bool, glXQueryFrameCountNV, (Display * dpy, int screen, GLuint * count), (dpy, screen, count))
GEN_THUNKS_RET(glx, int, glXQueryGLXPbufferSGIX, (Display * dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int * value), (dpy, pbuf, attribute, value))
GEN_THUNKS_RET(glx, int, glXQueryHyperpipeAttribSGIX, (Display * dpy, int timeSlice, int attrib, int size, void * returnAttribList), (dpy, timeSlice, attrib, size, returnAttribList))
GEN_THUNKS_RET(glx, int, glXQueryHyperpipeBestAttribSGIX, (Display * dpy, int timeSlice, int attrib, int size, void * attribList, void * returnAttribList), (dpy, timeSlice, attrib, size, attribList, returnAttribList))
GEN_THUNKS_RET(glx, GLXHyperpipeConfigSGIX *, glXQueryHyperpipeConfigSGIX, (Display * dpy, int hpId, int * npipes), (dpy, hpId, npipes))
GEN_THUNKS_RET(glx, GLXHyperpipeNetworkSGIX *, glXQueryHyperpipeNetworkSGIX, (Display * dpy, int * npipes), (dpy, npipes))
GEN_THUNKS_RET(glx, Bool, glXQueryMaxSwapBarriersSGIX, (Display * dpy, int screen, int * max), (dpy, screen, max))
GEN_THUNKS_RET(glx, Bool, glXQueryMaxSwapGroupsNV, (Display * dpy, int screen, GLuint * maxGroups, GLuint * maxBarriers), (dpy, screen, maxGroups, maxBarriers))
GEN_THUNKS_RET(glx, Bool, glXQueryRendererIntegerMESA, (Display * dpy, int screen, int renderer, int attribute, unsigned int * value), (dpy, screen, renderer, attribute, value))
GEN_THUNKS_RET(glx, const char *, glXQueryRendererStringMESA, (Display * dpy, int screen, int renderer, int attribute), (dpy, screen, renderer, attribute))
GEN_THUNKS_RET(glx, const char *, glXQueryServerString, (Display * dpy, int screen, int name), (dpy, screen, name))
GEN_THUNKS_RET(glx, Bool, glXQuerySwapGroupNV, (Display * dpy, GLXDrawable drawable, GLuint * group, GLuint * barrier), (dpy, drawable, group, barrier))
GEN_THUNKS_RET(glx, Bool, glXQueryVersion, (Display * dpy, int * maj, int * min), (dpy, maj, min))
GEN_THUNKS_RET(glx, int, glXQueryVideoCaptureDeviceNV, (Display * dpy, GLXVideoCaptureDeviceNV device, int attribute, int * value), (dpy, device, attribute, value))
GEN_THUNKS_RET(glx, Bool, glXReleaseBuffersMESA, (Display * dpy, GLXDrawable drawable), (dpy, drawable))
GEN_THUNKS(glx, glXReleaseTexImageEXT, (Display * dpy, GLXDrawable drawable, int buffer), (dpy, drawable, buffer))
GEN_THUNKS(glx, glXReleaseVideoCaptureDeviceNV, (Display * dpy, GLXVideoCaptureDeviceNV device), (dpy, device))
GEN_THUNKS_RET(glx, int, glXReleaseVideoDeviceNV, (Display * dpy, int screen, GLXVideoDeviceNV VideoDevice), (dpy, screen, VideoDevice))
GEN_THUNKS_RET(glx, int, glXReleaseVideoImageNV, (Display * dpy, GLXPbuffer pbuf), (dpy, pbuf))
GEN_THUNKS_RET(glx, Bool, glXResetFrameCountNV, (Display * dpy, int screen), (dpy, screen))
GEN_THUNKS(glx, glXSelectEvent, (Display * dpy, GLXDrawable draw, unsigned long event_mask), (dpy, draw, event_mask))
GEN_THUNKS(glx, glXSelectEventSGIX, (Display * dpy, GLXDrawable drawable, unsigned long mask), (dpy, drawable, mask))
GEN_THUNKS_RET(glx, int, glXSendPbufferToVideoNV, (Display * dpy, GLXPbuffer pbuf, int iBufferType, unsigned long * pulCounterPbuffer, GLboolean bBlock), (dpy, pbuf, iBufferType, pulCounterPbuffer, bBlock))
GEN_THUNKS_RET(glx, Bool, glXSet3DfxModeMESA, (int mode), (mode))
GEN_THUNKS(glx, glXSwapBuffers, (Display * dpy, GLXDrawable drawable), (dpy, drawable))
GEN_THUNKS_RET(glx, int64_t, glXSwapBuffersMscOML, (Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder), (dpy, drawable, target_msc, divisor, remainder))
GEN_THUNKS(glx, glXSwapIntervalEXT, (Display * dpy, GLXDrawable drawable, int interval), (dpy, drawable, interval))
GEN_THUNKS_RET(glx, int, glXSwapIntervalSGI, (int interval), (interval))
GEN_THUNKS(glx, glXUseXFont, (Font font, int first, int count, int list), (font, first, count, list))
GEN_THUNKS_RET(glx, Bool, glXWaitForMscOML, (Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t * ust, int64_t * msc, int64_t * sbc), (dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc))
GEN_THUNKS_RET(glx, Bool, glXWaitForSbcOML, (Display * dpy, GLXDrawable drawable, int64_t target_sbc, int64_t * ust, int64_t * msc, int64_t * sbc), (dpy, drawable, target_sbc, ust, msc, sbc))
GEN_THUNKS(glx, glXWaitGL, (void), ())
GEN_THUNKS_RET(glx, int, glXWaitVideoSyncSGI, (int divisor, int remainder, unsigned int * count), (divisor, remainder, count))
GEN_THUNKS(glx, glXWaitX, (void), ())

static struct glx_dispatch_table glx_resolver_table = {
    .glXBindChannelToWindowSGIX = epoxy_glXBindChannelToWindowSGIX_dispatch_table_rewrite_ptr,
    .glXBindHyperpipeSGIX = epoxy_glXBindHyperpipeSGIX_dispatch_table_rewrite_ptr,
    .glXBindSwapBarrierNV = epoxy_glXBindSwapBarrierNV_dispatch_table_rewrite_ptr,
    .glXBindSwapBarrierSGIX = epoxy_glXBindSwapBarrierSGIX_dispatch_table_rewrite_ptr,
    .glXBindTexImageEXT = epoxy_glXBindTexImageEXT_dispatch_table_rewrite_ptr,
    .glXBindVideoCaptureDeviceNV = epoxy_glXBindVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .glXBindVideoDeviceNV = epoxy_glXBindVideoDeviceNV_dispatch_table_rewrite_ptr,
    .glXBindVideoImageNV = epoxy_glXBindVideoImageNV_dispatch_table_rewrite_ptr,
    .glXBlitContextFramebufferAMD = epoxy_glXBlitContextFramebufferAMD_dispatch_table_rewrite_ptr,
    .glXChannelRectSGIX = epoxy_glXChannelRectSGIX_dispatch_table_rewrite_ptr,
    .glXChannelRectSyncSGIX = epoxy_glXChannelRectSyncSGIX_dispatch_table_rewrite_ptr,
    .glXChooseFBConfig = epoxy_glXChooseFBConfig_dispatch_table_rewrite_ptr,
    .glXChooseFBConfigSGIX = epoxy_glXChooseFBConfigSGIX_dispatch_table_rewrite_ptr,
    .glXChooseVisual = epoxy_glXChooseVisual_dispatch_table_rewrite_ptr,
    .glXCopyBufferSubDataNV = epoxy_glXCopyBufferSubDataNV_dispatch_table_rewrite_ptr,
    .glXCopyContext = epoxy_glXCopyContext_dispatch_table_rewrite_ptr,
    .glXCopyImageSubDataNV = epoxy_glXCopyImageSubDataNV_dispatch_table_rewrite_ptr,
    .glXCopySubBufferMESA = epoxy_glXCopySubBufferMESA_dispatch_table_rewrite_ptr,
    .glXCreateAssociatedContextAMD = epoxy_glXCreateAssociatedContextAMD_dispatch_table_rewrite_ptr,
    .glXCreateAssociatedContextAttribsAMD = epoxy_glXCreateAssociatedContextAttribsAMD_dispatch_table_rewrite_ptr,
    .glXCreateContext = epoxy_glXCreateContext_dispatch_table_rewrite_ptr,
    .glXCreateContextAttribsARB = epoxy_glXCreateContextAttribsARB_dispatch_table_rewrite_ptr,
    .glXCreateContextWithConfigSGIX = epoxy_glXCreateContextWithConfigSGIX_dispatch_table_rewrite_ptr,
    .glXCreateGLXPbufferSGIX = epoxy_glXCreateGLXPbufferSGIX_dispatch_table_rewrite_ptr,
    .glXCreateGLXPixmap = epoxy_glXCreateGLXPixmap_dispatch_table_rewrite_ptr,
    .glXCreateGLXPixmapMESA = epoxy_glXCreateGLXPixmapMESA_dispatch_table_rewrite_ptr,
    .glXCreateGLXPixmapWithConfigSGIX = epoxy_glXCreateGLXPixmapWithConfigSGIX_dispatch_table_rewrite_ptr,
    .glXCreateNewContext = epoxy_glXCreateNewContext_dispatch_table_rewrite_ptr,
    .glXCreatePbuffer = epoxy_glXCreatePbuffer_dispatch_table_rewrite_ptr,
    .glXCreatePixmap = epoxy_glXCreatePixmap_dispatch_table_rewrite_ptr,
    .glXCreateWindow = epoxy_glXCreateWindow_dispatch_table_rewrite_ptr,
    .glXCushionSGI = epoxy_glXCushionSGI_dispatch_table_rewrite_ptr,
    .glXDelayBeforeSwapNV = epoxy_glXDelayBeforeSwapNV_dispatch_table_rewrite_ptr,
    .glXDeleteAssociatedContextAMD = epoxy_glXDeleteAssociatedContextAMD_dispatch_table_rewrite_ptr,
    .glXDestroyContext = epoxy_glXDestroyContext_dispatch_table_rewrite_ptr,
    .glXDestroyGLXPbufferSGIX = epoxy_glXDestroyGLXPbufferSGIX_dispatch_table_rewrite_ptr,
    .glXDestroyGLXPixmap = epoxy_glXDestroyGLXPixmap_dispatch_table_rewrite_ptr,
    .glXDestroyGLXVideoSourceSGIX = epoxy_glXDestroyGLXVideoSourceSGIX_dispatch_table_rewrite_ptr,
    .glXDestroyHyperpipeConfigSGIX = epoxy_glXDestroyHyperpipeConfigSGIX_dispatch_table_rewrite_ptr,
    .glXDestroyPbuffer = epoxy_glXDestroyPbuffer_dispatch_table_rewrite_ptr,
    .glXDestroyPixmap = epoxy_glXDestroyPixmap_dispatch_table_rewrite_ptr,
    .glXDestroyWindow = epoxy_glXDestroyWindow_dispatch_table_rewrite_ptr,
    .glXEnumerateVideoCaptureDevicesNV = epoxy_glXEnumerateVideoCaptureDevicesNV_dispatch_table_rewrite_ptr,
    .glXEnumerateVideoDevicesNV = epoxy_glXEnumerateVideoDevicesNV_dispatch_table_rewrite_ptr,
    .glXFreeContextEXT = epoxy_glXFreeContextEXT_dispatch_table_rewrite_ptr,
    .glXGetAGPOffsetMESA = epoxy_glXGetAGPOffsetMESA_dispatch_table_rewrite_ptr,
    .glXGetClientString = epoxy_glXGetClientString_dispatch_table_rewrite_ptr,
    .glXGetConfig = epoxy_glXGetConfig_dispatch_table_rewrite_ptr,
    .glXGetContextGPUIDAMD = epoxy_glXGetContextGPUIDAMD_dispatch_table_rewrite_ptr,
    .glXGetContextIDEXT = epoxy_glXGetContextIDEXT_dispatch_table_rewrite_ptr,
    .glXGetCurrentAssociatedContextAMD = epoxy_glXGetCurrentAssociatedContextAMD_dispatch_table_rewrite_ptr,
    .glXGetCurrentContext = epoxy_glXGetCurrentContext_dispatch_table_rewrite_ptr,
    .glXGetCurrentDisplay = epoxy_glXGetCurrentDisplay_dispatch_table_rewrite_ptr,
    .glXGetCurrentDisplayEXT = epoxy_glXGetCurrentDisplayEXT_dispatch_table_rewrite_ptr,
    .glXGetCurrentDrawable = epoxy_glXGetCurrentDrawable_dispatch_table_rewrite_ptr,
    .glXGetCurrentReadDrawable = epoxy_glXGetCurrentReadDrawable_dispatch_table_rewrite_ptr,
    .glXGetCurrentReadDrawableSGI = epoxy_glXGetCurrentReadDrawableSGI_dispatch_table_rewrite_ptr,
    .glXGetFBConfigAttrib = epoxy_glXGetFBConfigAttrib_dispatch_table_rewrite_ptr,
    .glXGetFBConfigAttribSGIX = epoxy_glXGetFBConfigAttribSGIX_dispatch_table_rewrite_ptr,
    .glXGetFBConfigFromVisualSGIX = epoxy_glXGetFBConfigFromVisualSGIX_dispatch_table_rewrite_ptr,
    .glXGetFBConfigs = epoxy_glXGetFBConfigs_dispatch_table_rewrite_ptr,
    .glXGetGPUIDsAMD = epoxy_glXGetGPUIDsAMD_dispatch_table_rewrite_ptr,
    .glXGetGPUInfoAMD = epoxy_glXGetGPUInfoAMD_dispatch_table_rewrite_ptr,
    .glXGetMscRateOML = epoxy_glXGetMscRateOML_dispatch_table_rewrite_ptr,
    .glXGetProcAddress = epoxy_glXGetProcAddress_dispatch_table_rewrite_ptr,
    .glXGetProcAddressARB = epoxy_glXGetProcAddressARB_dispatch_table_rewrite_ptr,
    .glXGetSelectedEvent = epoxy_glXGetSelectedEvent_dispatch_table_rewrite_ptr,
    .glXGetSelectedEventSGIX = epoxy_glXGetSelectedEventSGIX_dispatch_table_rewrite_ptr,
    .glXGetSyncValuesOML = epoxy_glXGetSyncValuesOML_dispatch_table_rewrite_ptr,
    .glXGetTransparentIndexSUN = epoxy_glXGetTransparentIndexSUN_dispatch_table_rewrite_ptr,
    .glXGetVideoDeviceNV = epoxy_glXGetVideoDeviceNV_dispatch_table_rewrite_ptr,
    .glXGetVideoInfoNV = epoxy_glXGetVideoInfoNV_dispatch_table_rewrite_ptr,
    .glXGetVideoSyncSGI = epoxy_glXGetVideoSyncSGI_dispatch_table_rewrite_ptr,
    .glXGetVisualFromFBConfig = epoxy_glXGetVisualFromFBConfig_dispatch_table_rewrite_ptr,
    .glXGetVisualFromFBConfigSGIX = epoxy_glXGetVisualFromFBConfigSGIX_dispatch_table_rewrite_ptr,
    .glXHyperpipeAttribSGIX = epoxy_glXHyperpipeAttribSGIX_dispatch_table_rewrite_ptr,
    .glXHyperpipeConfigSGIX = epoxy_glXHyperpipeConfigSGIX_dispatch_table_rewrite_ptr,
    .glXImportContextEXT = epoxy_glXImportContextEXT_dispatch_table_rewrite_ptr,
    .glXIsDirect = epoxy_glXIsDirect_dispatch_table_rewrite_ptr,
    .glXJoinSwapGroupNV = epoxy_glXJoinSwapGroupNV_dispatch_table_rewrite_ptr,
    .glXJoinSwapGroupSGIX = epoxy_glXJoinSwapGroupSGIX_dispatch_table_rewrite_ptr,
    .glXLockVideoCaptureDeviceNV = epoxy_glXLockVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .glXMakeAssociatedContextCurrentAMD = epoxy_glXMakeAssociatedContextCurrentAMD_dispatch_table_rewrite_ptr,
    .glXMakeContextCurrent = epoxy_glXMakeContextCurrent_dispatch_table_rewrite_ptr,
    .glXMakeCurrent = epoxy_glXMakeCurrent_dispatch_table_rewrite_ptr,
    .glXMakeCurrentReadSGI = epoxy_glXMakeCurrentReadSGI_dispatch_table_rewrite_ptr,
    .glXNamedCopyBufferSubDataNV = epoxy_glXNamedCopyBufferSubDataNV_dispatch_table_rewrite_ptr,
    .glXQueryChannelDeltasSGIX = epoxy_glXQueryChannelDeltasSGIX_dispatch_table_rewrite_ptr,
    .glXQueryChannelRectSGIX = epoxy_glXQueryChannelRectSGIX_dispatch_table_rewrite_ptr,
    .glXQueryContext = epoxy_glXQueryContext_dispatch_table_rewrite_ptr,
    .glXQueryContextInfoEXT = epoxy_glXQueryContextInfoEXT_dispatch_table_rewrite_ptr,
    .glXQueryCurrentRendererIntegerMESA = epoxy_glXQueryCurrentRendererIntegerMESA_dispatch_table_rewrite_ptr,
    .glXQueryCurrentRendererStringMESA = epoxy_glXQueryCurrentRendererStringMESA_dispatch_table_rewrite_ptr,
    .glXQueryDrawable = epoxy_glXQueryDrawable_dispatch_table_rewrite_ptr,
    .glXQueryExtension = epoxy_glXQueryExtension_dispatch_table_rewrite_ptr,
    .glXQueryExtensionsString = epoxy_glXQueryExtensionsString_dispatch_table_rewrite_ptr,
    .glXQueryFrameCountNV = epoxy_glXQueryFrameCountNV_dispatch_table_rewrite_ptr,
    .glXQueryGLXPbufferSGIX = epoxy_glXQueryGLXPbufferSGIX_dispatch_table_rewrite_ptr,
    .glXQueryHyperpipeAttribSGIX = epoxy_glXQueryHyperpipeAttribSGIX_dispatch_table_rewrite_ptr,
    .glXQueryHyperpipeBestAttribSGIX = epoxy_glXQueryHyperpipeBestAttribSGIX_dispatch_table_rewrite_ptr,
    .glXQueryHyperpipeConfigSGIX = epoxy_glXQueryHyperpipeConfigSGIX_dispatch_table_rewrite_ptr,
    .glXQueryHyperpipeNetworkSGIX = epoxy_glXQueryHyperpipeNetworkSGIX_dispatch_table_rewrite_ptr,
    .glXQueryMaxSwapBarriersSGIX = epoxy_glXQueryMaxSwapBarriersSGIX_dispatch_table_rewrite_ptr,
    .glXQueryMaxSwapGroupsNV = epoxy_glXQueryMaxSwapGroupsNV_dispatch_table_rewrite_ptr,
    .glXQueryRendererIntegerMESA = epoxy_glXQueryRendererIntegerMESA_dispatch_table_rewrite_ptr,
    .glXQueryRendererStringMESA = epoxy_glXQueryRendererStringMESA_dispatch_table_rewrite_ptr,
    .glXQueryServerString = epoxy_glXQueryServerString_dispatch_table_rewrite_ptr,
    .glXQuerySwapGroupNV = epoxy_glXQuerySwapGroupNV_dispatch_table_rewrite_ptr,
    .glXQueryVersion = epoxy_glXQueryVersion_dispatch_table_rewrite_ptr,
    .glXQueryVideoCaptureDeviceNV = epoxy_glXQueryVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .glXReleaseBuffersMESA = epoxy_glXReleaseBuffersMESA_dispatch_table_rewrite_ptr,
    .glXReleaseTexImageEXT = epoxy_glXReleaseTexImageEXT_dispatch_table_rewrite_ptr,
    .glXReleaseVideoCaptureDeviceNV = epoxy_glXReleaseVideoCaptureDeviceNV_dispatch_table_rewrite_ptr,
    .glXReleaseVideoDeviceNV = epoxy_glXReleaseVideoDeviceNV_dispatch_table_rewrite_ptr,
    .glXReleaseVideoImageNV = epoxy_glXReleaseVideoImageNV_dispatch_table_rewrite_ptr,
    .glXResetFrameCountNV = epoxy_glXResetFrameCountNV_dispatch_table_rewrite_ptr,
    .glXSelectEvent = epoxy_glXSelectEvent_dispatch_table_rewrite_ptr,
    .glXSelectEventSGIX = epoxy_glXSelectEventSGIX_dispatch_table_rewrite_ptr,
    .glXSendPbufferToVideoNV = epoxy_glXSendPbufferToVideoNV_dispatch_table_rewrite_ptr,
    .glXSet3DfxModeMESA = epoxy_glXSet3DfxModeMESA_dispatch_table_rewrite_ptr,
    .glXSwapBuffers = epoxy_glXSwapBuffers_dispatch_table_rewrite_ptr,
    .glXSwapBuffersMscOML = epoxy_glXSwapBuffersMscOML_dispatch_table_rewrite_ptr,
    .glXSwapIntervalEXT = epoxy_glXSwapIntervalEXT_dispatch_table_rewrite_ptr,
    .glXSwapIntervalSGI = epoxy_glXSwapIntervalSGI_dispatch_table_rewrite_ptr,
    .glXUseXFont = epoxy_glXUseXFont_dispatch_table_rewrite_ptr,
    .glXWaitForMscOML = epoxy_glXWaitForMscOML_dispatch_table_rewrite_ptr,
    .glXWaitForSbcOML = epoxy_glXWaitForSbcOML_dispatch_table_rewrite_ptr,
    .glXWaitGL = epoxy_glXWaitGL_dispatch_table_rewrite_ptr,
    .glXWaitVideoSyncSGI = epoxy_glXWaitVideoSyncSGI_dispatch_table_rewrite_ptr,
    .glXWaitX = epoxy_glXWaitX_dispatch_table_rewrite_ptr,
};
#endif /* PLATFORM_HAS_GLX */
