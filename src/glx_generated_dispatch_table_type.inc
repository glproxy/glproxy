/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#include "dispatch_common.h"
#if PLATFORM_HAS_GLX

struct glx_dispatch_table {
    PFNGLXBINDCHANNELTOWINDOWSGIXPROC epoxy_glXBindChannelToWindowSGIX;
    PFNGLXBINDHYPERPIPESGIXPROC epoxy_glXBindHyperpipeSGIX;
    PFNGLXBINDSWAPBARRIERNVPROC epoxy_glXBindSwapBarrierNV;
    PFNGLXBINDSWAPBARRIERSGIXPROC epoxy_glXBindSwapBarrierSGIX;
    PFNGLXBINDTEXIMAGEEXTPROC epoxy_glXBindTexImageEXT;
    PFNGLXBINDVIDEOCAPTUREDEVICENVPROC epoxy_glXBindVideoCaptureDeviceNV;
    PFNGLXBINDVIDEODEVICENVPROC epoxy_glXBindVideoDeviceNV;
    PFNGLXBINDVIDEOIMAGENVPROC epoxy_glXBindVideoImageNV;
    PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC epoxy_glXBlitContextFramebufferAMD;
    PFNGLXCHANNELRECTSGIXPROC epoxy_glXChannelRectSGIX;
    PFNGLXCHANNELRECTSYNCSGIXPROC epoxy_glXChannelRectSyncSGIX;
    PFNGLXCHOOSEFBCONFIGPROC epoxy_glXChooseFBConfig;
    PFNGLXCHOOSEFBCONFIGSGIXPROC epoxy_glXChooseFBConfigSGIX;
    PFNGLXCHOOSEVISUALPROC epoxy_glXChooseVisual;
    PFNGLXCOPYBUFFERSUBDATANVPROC epoxy_glXCopyBufferSubDataNV;
    PFNGLXCOPYCONTEXTPROC epoxy_glXCopyContext;
    PFNGLXCOPYIMAGESUBDATANVPROC epoxy_glXCopyImageSubDataNV;
    PFNGLXCOPYSUBBUFFERMESAPROC epoxy_glXCopySubBufferMESA;
    PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC epoxy_glXCreateAssociatedContextAMD;
    PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC epoxy_glXCreateAssociatedContextAttribsAMD;
    PFNGLXCREATECONTEXTPROC epoxy_glXCreateContext;
    PFNGLXCREATECONTEXTATTRIBSARBPROC epoxy_glXCreateContextAttribsARB;
    PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC epoxy_glXCreateContextWithConfigSGIX;
    PFNGLXCREATEGLXPBUFFERSGIXPROC epoxy_glXCreateGLXPbufferSGIX;
    PFNGLXCREATEGLXPIXMAPPROC epoxy_glXCreateGLXPixmap;
    PFNGLXCREATEGLXPIXMAPMESAPROC epoxy_glXCreateGLXPixmapMESA;
    PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC epoxy_glXCreateGLXPixmapWithConfigSGIX;
    PFNGLXCREATENEWCONTEXTPROC epoxy_glXCreateNewContext;
    PFNGLXCREATEPBUFFERPROC epoxy_glXCreatePbuffer;
    PFNGLXCREATEPIXMAPPROC epoxy_glXCreatePixmap;
    PFNGLXCREATEWINDOWPROC epoxy_glXCreateWindow;
    PFNGLXCUSHIONSGIPROC epoxy_glXCushionSGI;
    PFNGLXDELAYBEFORESWAPNVPROC epoxy_glXDelayBeforeSwapNV;
    PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC epoxy_glXDeleteAssociatedContextAMD;
    PFNGLXDESTROYCONTEXTPROC epoxy_glXDestroyContext;
    PFNGLXDESTROYGLXPBUFFERSGIXPROC epoxy_glXDestroyGLXPbufferSGIX;
    PFNGLXDESTROYGLXPIXMAPPROC epoxy_glXDestroyGLXPixmap;
    PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC epoxy_glXDestroyGLXVideoSourceSGIX;
    PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC epoxy_glXDestroyHyperpipeConfigSGIX;
    PFNGLXDESTROYPBUFFERPROC epoxy_glXDestroyPbuffer;
    PFNGLXDESTROYPIXMAPPROC epoxy_glXDestroyPixmap;
    PFNGLXDESTROYWINDOWPROC epoxy_glXDestroyWindow;
    PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC epoxy_glXEnumerateVideoCaptureDevicesNV;
    PFNGLXENUMERATEVIDEODEVICESNVPROC epoxy_glXEnumerateVideoDevicesNV;
    PFNGLXFREECONTEXTEXTPROC epoxy_glXFreeContextEXT;
    PFNGLXGETAGPOFFSETMESAPROC epoxy_glXGetAGPOffsetMESA;
    PFNGLXGETCLIENTSTRINGPROC epoxy_glXGetClientString;
    PFNGLXGETCONFIGPROC epoxy_glXGetConfig;
    PFNGLXGETCONTEXTGPUIDAMDPROC epoxy_glXGetContextGPUIDAMD;
    PFNGLXGETCONTEXTIDEXTPROC epoxy_glXGetContextIDEXT;
    PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC epoxy_glXGetCurrentAssociatedContextAMD;
    PFNGLXGETCURRENTCONTEXTPROC epoxy_glXGetCurrentContext;
    PFNGLXGETCURRENTDISPLAYPROC epoxy_glXGetCurrentDisplay;
    PFNGLXGETCURRENTDISPLAYEXTPROC epoxy_glXGetCurrentDisplayEXT;
    PFNGLXGETCURRENTDRAWABLEPROC epoxy_glXGetCurrentDrawable;
    PFNGLXGETCURRENTREADDRAWABLEPROC epoxy_glXGetCurrentReadDrawable;
    PFNGLXGETCURRENTREADDRAWABLESGIPROC epoxy_glXGetCurrentReadDrawableSGI;
    PFNGLXGETFBCONFIGATTRIBPROC epoxy_glXGetFBConfigAttrib;
    PFNGLXGETFBCONFIGATTRIBSGIXPROC epoxy_glXGetFBConfigAttribSGIX;
    PFNGLXGETFBCONFIGFROMVISUALSGIXPROC epoxy_glXGetFBConfigFromVisualSGIX;
    PFNGLXGETFBCONFIGSPROC epoxy_glXGetFBConfigs;
    PFNGLXGETGPUIDSAMDPROC epoxy_glXGetGPUIDsAMD;
    PFNGLXGETGPUINFOAMDPROC epoxy_glXGetGPUInfoAMD;
    PFNGLXGETMSCRATEOMLPROC epoxy_glXGetMscRateOML;
    PFNGLXGETPROCADDRESSPROC epoxy_glXGetProcAddress;
    PFNGLXGETPROCADDRESSARBPROC epoxy_glXGetProcAddressARB;
    PFNGLXGETSELECTEDEVENTPROC epoxy_glXGetSelectedEvent;
    PFNGLXGETSELECTEDEVENTSGIXPROC epoxy_glXGetSelectedEventSGIX;
    PFNGLXGETSYNCVALUESOMLPROC epoxy_glXGetSyncValuesOML;
    PFNGLXGETTRANSPARENTINDEXSUNPROC epoxy_glXGetTransparentIndexSUN;
    PFNGLXGETVIDEODEVICENVPROC epoxy_glXGetVideoDeviceNV;
    PFNGLXGETVIDEOINFONVPROC epoxy_glXGetVideoInfoNV;
    PFNGLXGETVIDEOSYNCSGIPROC epoxy_glXGetVideoSyncSGI;
    PFNGLXGETVISUALFROMFBCONFIGPROC epoxy_glXGetVisualFromFBConfig;
    PFNGLXGETVISUALFROMFBCONFIGSGIXPROC epoxy_glXGetVisualFromFBConfigSGIX;
    PFNGLXHYPERPIPEATTRIBSGIXPROC epoxy_glXHyperpipeAttribSGIX;
    PFNGLXHYPERPIPECONFIGSGIXPROC epoxy_glXHyperpipeConfigSGIX;
    PFNGLXIMPORTCONTEXTEXTPROC epoxy_glXImportContextEXT;
    PFNGLXISDIRECTPROC epoxy_glXIsDirect;
    PFNGLXJOINSWAPGROUPNVPROC epoxy_glXJoinSwapGroupNV;
    PFNGLXJOINSWAPGROUPSGIXPROC epoxy_glXJoinSwapGroupSGIX;
    PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC epoxy_glXLockVideoCaptureDeviceNV;
    PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC epoxy_glXMakeAssociatedContextCurrentAMD;
    PFNGLXMAKECONTEXTCURRENTPROC epoxy_glXMakeContextCurrent;
    PFNGLXMAKECURRENTPROC epoxy_glXMakeCurrent;
    PFNGLXMAKECURRENTREADSGIPROC epoxy_glXMakeCurrentReadSGI;
    PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC epoxy_glXNamedCopyBufferSubDataNV;
    PFNGLXQUERYCHANNELDELTASSGIXPROC epoxy_glXQueryChannelDeltasSGIX;
    PFNGLXQUERYCHANNELRECTSGIXPROC epoxy_glXQueryChannelRectSGIX;
    PFNGLXQUERYCONTEXTPROC epoxy_glXQueryContext;
    PFNGLXQUERYCONTEXTINFOEXTPROC epoxy_glXQueryContextInfoEXT;
    PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC epoxy_glXQueryCurrentRendererIntegerMESA;
    PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC epoxy_glXQueryCurrentRendererStringMESA;
    PFNGLXQUERYDRAWABLEPROC epoxy_glXQueryDrawable;
    PFNGLXQUERYEXTENSIONPROC epoxy_glXQueryExtension;
    PFNGLXQUERYEXTENSIONSSTRINGPROC epoxy_glXQueryExtensionsString;
    PFNGLXQUERYFRAMECOUNTNVPROC epoxy_glXQueryFrameCountNV;
    PFNGLXQUERYGLXPBUFFERSGIXPROC epoxy_glXQueryGLXPbufferSGIX;
    PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC epoxy_glXQueryHyperpipeAttribSGIX;
    PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC epoxy_glXQueryHyperpipeBestAttribSGIX;
    PFNGLXQUERYHYPERPIPECONFIGSGIXPROC epoxy_glXQueryHyperpipeConfigSGIX;
    PFNGLXQUERYHYPERPIPENETWORKSGIXPROC epoxy_glXQueryHyperpipeNetworkSGIX;
    PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC epoxy_glXQueryMaxSwapBarriersSGIX;
    PFNGLXQUERYMAXSWAPGROUPSNVPROC epoxy_glXQueryMaxSwapGroupsNV;
    PFNGLXQUERYRENDERERINTEGERMESAPROC epoxy_glXQueryRendererIntegerMESA;
    PFNGLXQUERYRENDERERSTRINGMESAPROC epoxy_glXQueryRendererStringMESA;
    PFNGLXQUERYSERVERSTRINGPROC epoxy_glXQueryServerString;
    PFNGLXQUERYSWAPGROUPNVPROC epoxy_glXQuerySwapGroupNV;
    PFNGLXQUERYVERSIONPROC epoxy_glXQueryVersion;
    PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC epoxy_glXQueryVideoCaptureDeviceNV;
    PFNGLXRELEASEBUFFERSMESAPROC epoxy_glXReleaseBuffersMESA;
    PFNGLXRELEASETEXIMAGEEXTPROC epoxy_glXReleaseTexImageEXT;
    PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC epoxy_glXReleaseVideoCaptureDeviceNV;
    PFNGLXRELEASEVIDEODEVICENVPROC epoxy_glXReleaseVideoDeviceNV;
    PFNGLXRELEASEVIDEOIMAGENVPROC epoxy_glXReleaseVideoImageNV;
    PFNGLXRESETFRAMECOUNTNVPROC epoxy_glXResetFrameCountNV;
    PFNGLXSELECTEVENTPROC epoxy_glXSelectEvent;
    PFNGLXSELECTEVENTSGIXPROC epoxy_glXSelectEventSGIX;
    PFNGLXSENDPBUFFERTOVIDEONVPROC epoxy_glXSendPbufferToVideoNV;
    PFNGLXSET3DFXMODEMESAPROC epoxy_glXSet3DfxModeMESA;
    PFNGLXSWAPBUFFERSPROC epoxy_glXSwapBuffers;
    PFNGLXSWAPBUFFERSMSCOMLPROC epoxy_glXSwapBuffersMscOML;
    PFNGLXSWAPINTERVALEXTPROC epoxy_glXSwapIntervalEXT;
    PFNGLXSWAPINTERVALSGIPROC epoxy_glXSwapIntervalSGI;
    PFNGLXUSEXFONTPROC epoxy_glXUseXFont;
    PFNGLXWAITFORMSCOMLPROC epoxy_glXWaitForMscOML;
    PFNGLXWAITFORSBCOMLPROC epoxy_glXWaitForSbcOML;
    PFNGLXWAITGLPROC epoxy_glXWaitGL;
    PFNGLXWAITVIDEOSYNCSGIPROC epoxy_glXWaitVideoSyncSGI;
    PFNGLXWAITXPROC epoxy_glXWaitX;
};

enum glx_provider {
    glx_provider_terminator = 0,
    GLX_10,
    GLX_11,
    GLX_12,
    GLX_13,
    GLX_extension_GLX_AMD_gpu_association,
    GLX_extension_GLX_ARB_create_context,
    GLX_extension_GLX_ARB_get_proc_address,
    GLX_extension_GLX_EXT_import_context,
    GLX_extension_GLX_EXT_swap_control,
    GLX_extension_GLX_EXT_texture_from_pixmap,
    GLX_extension_GLX_MESA_agp_offset,
    GLX_extension_GLX_MESA_copy_sub_buffer,
    GLX_extension_GLX_MESA_pixmap_colormap,
    GLX_extension_GLX_MESA_query_renderer,
    GLX_extension_GLX_MESA_release_buffers,
    GLX_extension_GLX_MESA_set_3dfx_mode,
    GLX_extension_GLX_NV_copy_buffer,
    GLX_extension_GLX_NV_copy_image,
    GLX_extension_GLX_NV_delay_before_swap,
    GLX_extension_GLX_NV_present_video,
    GLX_extension_GLX_NV_swap_group,
    GLX_extension_GLX_NV_video_capture,
    GLX_extension_GLX_NV_video_out,
    GLX_extension_GLX_OML_sync_control,
    GLX_extension_GLX_SGIX_fbconfig,
    GLX_extension_GLX_SGIX_hyperpipe,
    GLX_extension_GLX_SGIX_pbuffer,
    GLX_extension_GLX_SGIX_swap_barrier,
    GLX_extension_GLX_SGIX_swap_group,
    GLX_extension_GLX_SGIX_video_resize,
    GLX_extension_GLX_SGIX_video_source,
    GLX_extension_GLX_SGI_cushion,
    GLX_extension_GLX_SGI_make_current_read,
    GLX_extension_GLX_SGI_swap_control,
    GLX_extension_GLX_SGI_video_sync,
    GLX_extension_GLX_SUN_get_transparent_index,
    always_present,
} PACKED;

static const char *glx_enum_string =
    "GLX 10\0"
    "GLX 11\0"
    "GLX 12\0"
    "GLX 13\0"
    "GLX extension \"GLX_AMD_gpu_association\"\0"
    "GLX extension \"GLX_ARB_create_context\"\0"
    "GLX extension \"GLX_ARB_get_proc_address\"\0"
    "GLX extension \"GLX_EXT_import_context\"\0"
    "GLX extension \"GLX_EXT_swap_control\"\0"
    "GLX extension \"GLX_EXT_texture_from_pixmap\"\0"
    "GLX extension \"GLX_MESA_agp_offset\"\0"
    "GLX extension \"GLX_MESA_copy_sub_buffer\"\0"
    "GLX extension \"GLX_MESA_pixmap_colormap\"\0"
    "GLX extension \"GLX_MESA_query_renderer\"\0"
    "GLX extension \"GLX_MESA_release_buffers\"\0"
    "GLX extension \"GLX_MESA_set_3dfx_mode\"\0"
    "GLX extension \"GLX_NV_copy_buffer\"\0"
    "GLX extension \"GLX_NV_copy_image\"\0"
    "GLX extension \"GLX_NV_delay_before_swap\"\0"
    "GLX extension \"GLX_NV_present_video\"\0"
    "GLX extension \"GLX_NV_swap_group\"\0"
    "GLX extension \"GLX_NV_video_capture\"\0"
    "GLX extension \"GLX_NV_video_out\"\0"
    "GLX extension \"GLX_OML_sync_control\"\0"
    "GLX extension \"GLX_SGIX_fbconfig\"\0"
    "GLX extension \"GLX_SGIX_hyperpipe\"\0"
    "GLX extension \"GLX_SGIX_pbuffer\"\0"
    "GLX extension \"GLX_SGIX_swap_barrier\"\0"
    "GLX extension \"GLX_SGIX_swap_group\"\0"
    "GLX extension \"GLX_SGIX_video_resize\"\0"
    "GLX extension \"GLX_SGIX_video_source\"\0"
    "GLX extension \"GLX_SGI_cushion\"\0"
    "GLX extension \"GLX_SGI_make_current_read\"\0"
    "GLX extension \"GLX_SGI_swap_control\"\0"
    "GLX extension \"GLX_SGI_video_sync\"\0"
    "GLX extension \"GLX_SUN_get_transparent_index\"\0"
    "always present\0"
     ;

static const uint32_t glx_enum_string_offsets[] = {
    [GLX_10] = 0,
    [GLX_11] = 7,
    [GLX_12] = 14,
    [GLX_13] = 21,
    [GLX_extension_GLX_AMD_gpu_association] = 28,
    [GLX_extension_GLX_ARB_create_context] = 68,
    [GLX_extension_GLX_ARB_get_proc_address] = 107,
    [GLX_extension_GLX_EXT_import_context] = 148,
    [GLX_extension_GLX_EXT_swap_control] = 187,
    [GLX_extension_GLX_EXT_texture_from_pixmap] = 224,
    [GLX_extension_GLX_MESA_agp_offset] = 268,
    [GLX_extension_GLX_MESA_copy_sub_buffer] = 304,
    [GLX_extension_GLX_MESA_pixmap_colormap] = 345,
    [GLX_extension_GLX_MESA_query_renderer] = 386,
    [GLX_extension_GLX_MESA_release_buffers] = 426,
    [GLX_extension_GLX_MESA_set_3dfx_mode] = 467,
    [GLX_extension_GLX_NV_copy_buffer] = 506,
    [GLX_extension_GLX_NV_copy_image] = 541,
    [GLX_extension_GLX_NV_delay_before_swap] = 575,
    [GLX_extension_GLX_NV_present_video] = 616,
    [GLX_extension_GLX_NV_swap_group] = 653,
    [GLX_extension_GLX_NV_video_capture] = 687,
    [GLX_extension_GLX_NV_video_out] = 724,
    [GLX_extension_GLX_OML_sync_control] = 757,
    [GLX_extension_GLX_SGIX_fbconfig] = 794,
    [GLX_extension_GLX_SGIX_hyperpipe] = 828,
    [GLX_extension_GLX_SGIX_pbuffer] = 863,
    [GLX_extension_GLX_SGIX_swap_barrier] = 896,
    [GLX_extension_GLX_SGIX_swap_group] = 934,
    [GLX_extension_GLX_SGIX_video_resize] = 970,
    [GLX_extension_GLX_SGIX_video_source] = 1008,
    [GLX_extension_GLX_SGI_cushion] = 1046,
    [GLX_extension_GLX_SGI_make_current_read] = 1078,
    [GLX_extension_GLX_SGI_swap_control] = 1120,
    [GLX_extension_GLX_SGI_video_sync] = 1157,
    [GLX_extension_GLX_SUN_get_transparent_index] = 1192,
    [always_present] = 1238,
};

static const char* glx_entrypoint_strings[] = {
   "glXBindChannelToWindowSGIX",
   "glXBindHyperpipeSGIX",
   "glXBindSwapBarrierNV",
   "glXBindSwapBarrierSGIX",
   "glXBindTexImageEXT",
   "glXBindVideoCaptureDeviceNV",
   "glXBindVideoDeviceNV",
   "glXBindVideoImageNV",
   "glXBlitContextFramebufferAMD",
   "glXChannelRectSGIX",
   "glXChannelRectSyncSGIX",
   "glXChooseFBConfig",
   "glXChooseFBConfigSGIX",
   "glXChooseVisual",
   "glXCopyBufferSubDataNV",
   "glXCopyContext",
   "glXCopyImageSubDataNV",
   "glXCopySubBufferMESA",
   "glXCreateAssociatedContextAMD",
   "glXCreateAssociatedContextAttribsAMD",
   "glXCreateContext",
   "glXCreateContextAttribsARB",
   "glXCreateContextWithConfigSGIX",
   "glXCreateGLXPbufferSGIX",
   "glXCreateGLXPixmap",
   "glXCreateGLXPixmapMESA",
   "glXCreateGLXPixmapWithConfigSGIX",
   "glXCreateNewContext",
   "glXCreatePbuffer",
   "glXCreatePixmap",
   "glXCreateWindow",
   "glXCushionSGI",
   "glXDelayBeforeSwapNV",
   "glXDeleteAssociatedContextAMD",
   "glXDestroyContext",
   "glXDestroyGLXPbufferSGIX",
   "glXDestroyGLXPixmap",
   "glXDestroyGLXVideoSourceSGIX",
   "glXDestroyHyperpipeConfigSGIX",
   "glXDestroyPbuffer",
   "glXDestroyPixmap",
   "glXDestroyWindow",
   "glXEnumerateVideoCaptureDevicesNV",
   "glXEnumerateVideoDevicesNV",
   "glXFreeContextEXT",
   "glXGetAGPOffsetMESA",
   "glXGetClientString",
   "glXGetConfig",
   "glXGetContextGPUIDAMD",
   "glXGetContextIDEXT",
   "glXGetCurrentAssociatedContextAMD",
   "glXGetCurrentContext",
   "glXGetCurrentDisplay",
   "glXGetCurrentDisplayEXT",
   "glXGetCurrentDrawable",
   "glXGetCurrentReadDrawable",
   "glXGetCurrentReadDrawableSGI",
   "glXGetFBConfigAttrib",
   "glXGetFBConfigAttribSGIX",
   "glXGetFBConfigFromVisualSGIX",
   "glXGetFBConfigs",
   "glXGetGPUIDsAMD",
   "glXGetGPUInfoAMD",
   "glXGetMscRateOML",
   "glXGetProcAddress",
   "glXGetProcAddressARB",
   "glXGetSelectedEvent",
   "glXGetSelectedEventSGIX",
   "glXGetSyncValuesOML",
   "glXGetTransparentIndexSUN",
   "glXGetVideoDeviceNV",
   "glXGetVideoInfoNV",
   "glXGetVideoSyncSGI",
   "glXGetVisualFromFBConfig",
   "glXGetVisualFromFBConfigSGIX",
   "glXHyperpipeAttribSGIX",
   "glXHyperpipeConfigSGIX",
   "glXImportContextEXT",
   "glXIsDirect",
   "glXJoinSwapGroupNV",
   "glXJoinSwapGroupSGIX",
   "glXLockVideoCaptureDeviceNV",
   "glXMakeAssociatedContextCurrentAMD",
   "glXMakeContextCurrent",
   "glXMakeCurrent",
   "glXMakeCurrentReadSGI",
   "glXNamedCopyBufferSubDataNV",
   "glXQueryChannelDeltasSGIX",
   "glXQueryChannelRectSGIX",
   "glXQueryContext",
   "glXQueryContextInfoEXT",
   "glXQueryCurrentRendererIntegerMESA",
   "glXQueryCurrentRendererStringMESA",
   "glXQueryDrawable",
   "glXQueryExtension",
   "glXQueryExtensionsString",
   "glXQueryFrameCountNV",
   "glXQueryGLXPbufferSGIX",
   "glXQueryHyperpipeAttribSGIX",
   "glXQueryHyperpipeBestAttribSGIX",
   "glXQueryHyperpipeConfigSGIX",
   "glXQueryHyperpipeNetworkSGIX",
   "glXQueryMaxSwapBarriersSGIX",
   "glXQueryMaxSwapGroupsNV",
   "glXQueryRendererIntegerMESA",
   "glXQueryRendererStringMESA",
   "glXQueryServerString",
   "glXQuerySwapGroupNV",
   "glXQueryVersion",
   "glXQueryVideoCaptureDeviceNV",
   "glXReleaseBuffersMESA",
   "glXReleaseTexImageEXT",
   "glXReleaseVideoCaptureDeviceNV",
   "glXReleaseVideoDeviceNV",
   "glXReleaseVideoImageNV",
   "glXResetFrameCountNV",
   "glXSelectEvent",
   "glXSelectEventSGIX",
   "glXSendPbufferToVideoNV",
   "glXSet3DfxModeMESA",
   "glXSwapBuffers",
   "glXSwapBuffersMscOML",
   "glXSwapIntervalEXT",
   "glXSwapIntervalSGI",
   "glXUseXFont",
   "glXWaitForMscOML",
   "glXWaitForSbcOML",
   "glXWaitGL",
   "glXWaitVideoSyncSGI",
   "glXWaitX",
};

#endif /* PLATFORM_HAS_GLX */
