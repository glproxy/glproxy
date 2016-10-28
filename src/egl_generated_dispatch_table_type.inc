/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#include "dispatch_common.h"
#if PLATFORM_HAS_EGL

struct egl_dispatch_table {
    PFNEGLBINDAPIPROC epoxy_eglBindAPI;
    PFNEGLBINDTEXIMAGEPROC epoxy_eglBindTexImage;
    PFNEGLCHOOSECONFIGPROC epoxy_eglChooseConfig;
    PFNEGLCLIENTWAITSYNCPROC epoxy_eglClientWaitSync;
    PFNEGLCLIENTWAITSYNCKHRPROC epoxy_eglClientWaitSyncKHR;
    PFNEGLCLIENTWAITSYNCNVPROC epoxy_eglClientWaitSyncNV;
    PFNEGLCOPYBUFFERSPROC epoxy_eglCopyBuffers;
    PFNEGLCREATECONTEXTPROC epoxy_eglCreateContext;
    PFNEGLCREATEDRMIMAGEMESAPROC epoxy_eglCreateDRMImageMESA;
    PFNEGLCREATEFENCESYNCNVPROC epoxy_eglCreateFenceSyncNV;
    PFNEGLCREATEIMAGEPROC epoxy_eglCreateImage;
    PFNEGLCREATEIMAGEKHRPROC epoxy_eglCreateImageKHR;
    PFNEGLCREATENATIVECLIENTBUFFERANDROIDPROC epoxy_eglCreateNativeClientBufferANDROID;
    PFNEGLCREATEPBUFFERFROMCLIENTBUFFERPROC epoxy_eglCreatePbufferFromClientBuffer;
    PFNEGLCREATEPBUFFERSURFACEPROC epoxy_eglCreatePbufferSurface;
    PFNEGLCREATEPIXMAPSURFACEPROC epoxy_eglCreatePixmapSurface;
    PFNEGLCREATEPIXMAPSURFACEHIPROC epoxy_eglCreatePixmapSurfaceHI;
    PFNEGLCREATEPLATFORMPIXMAPSURFACEPROC epoxy_eglCreatePlatformPixmapSurface;
    PFNEGLCREATEPLATFORMPIXMAPSURFACEEXTPROC epoxy_eglCreatePlatformPixmapSurfaceEXT;
    PFNEGLCREATEPLATFORMWINDOWSURFACEPROC epoxy_eglCreatePlatformWindowSurface;
    PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC epoxy_eglCreatePlatformWindowSurfaceEXT;
    PFNEGLCREATESTREAMFROMFILEDESCRIPTORKHRPROC epoxy_eglCreateStreamFromFileDescriptorKHR;
    PFNEGLCREATESTREAMKHRPROC epoxy_eglCreateStreamKHR;
    PFNEGLCREATESTREAMPRODUCERSURFACEKHRPROC epoxy_eglCreateStreamProducerSurfaceKHR;
    PFNEGLCREATESTREAMSYNCNVPROC epoxy_eglCreateStreamSyncNV;
    PFNEGLCREATESYNCPROC epoxy_eglCreateSync;
    PFNEGLCREATESYNC64KHRPROC epoxy_eglCreateSync64KHR;
    PFNEGLCREATESYNCKHRPROC epoxy_eglCreateSyncKHR;
    PFNEGLCREATEWINDOWSURFACEPROC epoxy_eglCreateWindowSurface;
    PFNEGLDEBUGMESSAGECONTROLKHRPROC epoxy_eglDebugMessageControlKHR;
    PFNEGLDESTROYCONTEXTPROC epoxy_eglDestroyContext;
    PFNEGLDESTROYIMAGEPROC epoxy_eglDestroyImage;
    PFNEGLDESTROYIMAGEKHRPROC epoxy_eglDestroyImageKHR;
    PFNEGLDESTROYSTREAMKHRPROC epoxy_eglDestroyStreamKHR;
    PFNEGLDESTROYSURFACEPROC epoxy_eglDestroySurface;
    PFNEGLDESTROYSYNCPROC epoxy_eglDestroySync;
    PFNEGLDESTROYSYNCKHRPROC epoxy_eglDestroySyncKHR;
    PFNEGLDESTROYSYNCNVPROC epoxy_eglDestroySyncNV;
    PFNEGLDUPNATIVEFENCEFDANDROIDPROC epoxy_eglDupNativeFenceFDANDROID;
    PFNEGLEXPORTDMABUFIMAGEMESAPROC epoxy_eglExportDMABUFImageMESA;
    PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC epoxy_eglExportDMABUFImageQueryMESA;
    PFNEGLEXPORTDRMIMAGEMESAPROC epoxy_eglExportDRMImageMESA;
    PFNEGLFENCENVPROC epoxy_eglFenceNV;
    PFNEGLGETCONFIGATTRIBPROC epoxy_eglGetConfigAttrib;
    PFNEGLGETCONFIGSPROC epoxy_eglGetConfigs;
    PFNEGLGETCURRENTCONTEXTPROC epoxy_eglGetCurrentContext;
    PFNEGLGETCURRENTDISPLAYPROC epoxy_eglGetCurrentDisplay;
    PFNEGLGETCURRENTSURFACEPROC epoxy_eglGetCurrentSurface;
    PFNEGLGETDISPLAYPROC epoxy_eglGetDisplay;
    PFNEGLGETERRORPROC epoxy_eglGetError;
    PFNEGLGETOUTPUTLAYERSEXTPROC epoxy_eglGetOutputLayersEXT;
    PFNEGLGETOUTPUTPORTSEXTPROC epoxy_eglGetOutputPortsEXT;
    PFNEGLGETPLATFORMDISPLAYPROC epoxy_eglGetPlatformDisplay;
    PFNEGLGETPLATFORMDISPLAYEXTPROC epoxy_eglGetPlatformDisplayEXT;
    PFNEGLGETPROCADDRESSPROC epoxy_eglGetProcAddress;
    PFNEGLGETSTREAMFILEDESCRIPTORKHRPROC epoxy_eglGetStreamFileDescriptorKHR;
    PFNEGLGETSYNCATTRIBPROC epoxy_eglGetSyncAttrib;
    PFNEGLGETSYNCATTRIBKHRPROC epoxy_eglGetSyncAttribKHR;
    PFNEGLGETSYNCATTRIBNVPROC epoxy_eglGetSyncAttribNV;
    PFNEGLGETSYSTEMTIMEFREQUENCYNVPROC epoxy_eglGetSystemTimeFrequencyNV;
    PFNEGLGETSYSTEMTIMENVPROC epoxy_eglGetSystemTimeNV;
    PFNEGLINITIALIZEPROC epoxy_eglInitialize;
    PFNEGLLABELOBJECTKHRPROC epoxy_eglLabelObjectKHR;
    PFNEGLLOCKSURFACEKHRPROC epoxy_eglLockSurfaceKHR;
    PFNEGLMAKECURRENTPROC epoxy_eglMakeCurrent;
    PFNEGLOUTPUTLAYERATTRIBEXTPROC epoxy_eglOutputLayerAttribEXT;
    PFNEGLOUTPUTPORTATTRIBEXTPROC epoxy_eglOutputPortAttribEXT;
    PFNEGLPOSTSUBBUFFERNVPROC epoxy_eglPostSubBufferNV;
    PFNEGLPRESENTATIONTIMEANDROIDPROC epoxy_eglPresentationTimeANDROID;
    PFNEGLQUERYAPIPROC epoxy_eglQueryAPI;
    PFNEGLQUERYCONTEXTPROC epoxy_eglQueryContext;
    PFNEGLQUERYDEBUGKHRPROC epoxy_eglQueryDebugKHR;
    PFNEGLQUERYDEVICEATTRIBEXTPROC epoxy_eglQueryDeviceAttribEXT;
    PFNEGLQUERYDEVICESTRINGEXTPROC epoxy_eglQueryDeviceStringEXT;
    PFNEGLQUERYDEVICESEXTPROC epoxy_eglQueryDevicesEXT;
    PFNEGLQUERYDISPLAYATTRIBEXTPROC epoxy_eglQueryDisplayAttribEXT;
    PFNEGLQUERYDISPLAYATTRIBNVPROC epoxy_eglQueryDisplayAttribNV;
    PFNEGLQUERYNATIVEDISPLAYNVPROC epoxy_eglQueryNativeDisplayNV;
    PFNEGLQUERYNATIVEPIXMAPNVPROC epoxy_eglQueryNativePixmapNV;
    PFNEGLQUERYNATIVEWINDOWNVPROC epoxy_eglQueryNativeWindowNV;
    PFNEGLQUERYOUTPUTLAYERATTRIBEXTPROC epoxy_eglQueryOutputLayerAttribEXT;
    PFNEGLQUERYOUTPUTLAYERSTRINGEXTPROC epoxy_eglQueryOutputLayerStringEXT;
    PFNEGLQUERYOUTPUTPORTATTRIBEXTPROC epoxy_eglQueryOutputPortAttribEXT;
    PFNEGLQUERYOUTPUTPORTSTRINGEXTPROC epoxy_eglQueryOutputPortStringEXT;
    PFNEGLQUERYSTREAMKHRPROC epoxy_eglQueryStreamKHR;
    PFNEGLQUERYSTREAMMETADATANVPROC epoxy_eglQueryStreamMetadataNV;
    PFNEGLQUERYSTREAMTIMEKHRPROC epoxy_eglQueryStreamTimeKHR;
    PFNEGLQUERYSTREAMU64KHRPROC epoxy_eglQueryStreamu64KHR;
    PFNEGLQUERYSTRINGPROC epoxy_eglQueryString;
    PFNEGLQUERYSURFACEPROC epoxy_eglQuerySurface;
    PFNEGLQUERYSURFACE64KHRPROC epoxy_eglQuerySurface64KHR;
    PFNEGLQUERYSURFACEPOINTERANGLEPROC epoxy_eglQuerySurfacePointerANGLE;
    PFNEGLRELEASETEXIMAGEPROC epoxy_eglReleaseTexImage;
    PFNEGLRELEASETHREADPROC epoxy_eglReleaseThread;
    PFNEGLSETBLOBCACHEFUNCSANDROIDPROC epoxy_eglSetBlobCacheFuncsANDROID;
    PFNEGLSETDAMAGEREGIONKHRPROC epoxy_eglSetDamageRegionKHR;
    PFNEGLSETSTREAMMETADATANVPROC epoxy_eglSetStreamMetadataNV;
    PFNEGLSIGNALSYNCKHRPROC epoxy_eglSignalSyncKHR;
    PFNEGLSIGNALSYNCNVPROC epoxy_eglSignalSyncNV;
    PFNEGLSTREAMATTRIBKHRPROC epoxy_eglStreamAttribKHR;
    PFNEGLSTREAMCONSUMERACQUIREKHRPROC epoxy_eglStreamConsumerAcquireKHR;
    PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALATTRIBSNVPROC epoxy_eglStreamConsumerGLTextureExternalAttribsNV;
    PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALKHRPROC epoxy_eglStreamConsumerGLTextureExternalKHR;
    PFNEGLSTREAMCONSUMEROUTPUTEXTPROC epoxy_eglStreamConsumerOutputEXT;
    PFNEGLSTREAMCONSUMERRELEASEKHRPROC epoxy_eglStreamConsumerReleaseKHR;
    PFNEGLSURFACEATTRIBPROC epoxy_eglSurfaceAttrib;
    PFNEGLSWAPBUFFERSPROC epoxy_eglSwapBuffers;
    PFNEGLSWAPBUFFERSREGION2NOKPROC epoxy_eglSwapBuffersRegion2NOK;
    PFNEGLSWAPBUFFERSREGIONNOKPROC epoxy_eglSwapBuffersRegionNOK;
    PFNEGLSWAPBUFFERSWITHDAMAGEEXTPROC epoxy_eglSwapBuffersWithDamageEXT;
    PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC epoxy_eglSwapBuffersWithDamageKHR;
    PFNEGLSWAPINTERVALPROC epoxy_eglSwapInterval;
    PFNEGLTERMINATEPROC epoxy_eglTerminate;
    PFNEGLUNLOCKSURFACEKHRPROC epoxy_eglUnlockSurfaceKHR;
    PFNEGLWAITCLIENTPROC epoxy_eglWaitClient;
    PFNEGLWAITGLPROC epoxy_eglWaitGL;
    PFNEGLWAITNATIVEPROC epoxy_eglWaitNative;
    PFNEGLWAITSYNCPROC epoxy_eglWaitSync;
    PFNEGLWAITSYNCKHRPROC epoxy_eglWaitSyncKHR;
};

enum egl_provider {
    egl_provider_terminator = 0,
    EGL_10,
    EGL_11,
    EGL_12,
    EGL_14,
    EGL_15,
    EGL_extension_EGL_ANDROID_blob_cache,
    EGL_extension_EGL_ANDROID_create_native_client_buffer,
    EGL_extension_EGL_ANDROID_native_fence_sync,
    EGL_extension_EGL_ANDROID_presentation_time,
    EGL_extension_EGL_ANGLE_query_surface_pointer,
    EGL_extension_EGL_EXT_device_base,
    EGL_extension_EGL_EXT_device_enumeration,
    EGL_extension_EGL_EXT_device_query,
    EGL_extension_EGL_EXT_output_base,
    EGL_extension_EGL_EXT_platform_base,
    EGL_extension_EGL_EXT_stream_consumer_egloutput,
    EGL_extension_EGL_EXT_swap_buffers_with_damage,
    EGL_extension_EGL_HI_clientpixmap,
    EGL_extension_EGL_KHR_cl_event2,
    EGL_extension_EGL_KHR_debug,
    EGL_extension_EGL_KHR_fence_sync,
    EGL_extension_EGL_KHR_image,
    EGL_extension_EGL_KHR_image_base,
    EGL_extension_EGL_KHR_lock_surface3,
    EGL_extension_EGL_KHR_lock_surface,
    EGL_extension_EGL_KHR_partial_update,
    EGL_extension_EGL_KHR_reusable_sync,
    EGL_extension_EGL_KHR_stream,
    EGL_extension_EGL_KHR_stream_consumer_gltexture,
    EGL_extension_EGL_KHR_stream_cross_process_fd,
    EGL_extension_EGL_KHR_stream_fifo,
    EGL_extension_EGL_KHR_stream_producer_eglsurface,
    EGL_extension_EGL_KHR_swap_buffers_with_damage,
    EGL_extension_EGL_KHR_wait_sync,
    EGL_extension_EGL_MESA_drm_image,
    EGL_extension_EGL_MESA_image_dma_buf_export,
    EGL_extension_EGL_NOK_swap_region2,
    EGL_extension_EGL_NOK_swap_region,
    EGL_extension_EGL_NV_native_query,
    EGL_extension_EGL_NV_post_sub_buffer,
    EGL_extension_EGL_NV_stream_consumer_gltexture_yuv,
    EGL_extension_EGL_NV_stream_metadata,
    EGL_extension_EGL_NV_stream_sync,
    EGL_extension_EGL_NV_sync,
    EGL_extension_EGL_NV_system_time,
} PACKED;

static const char *egl_enum_string =
    "EGL 10\0"
    "EGL 11\0"
    "EGL 12\0"
    "EGL 14\0"
    "EGL 15\0"
    "EGL extension \"EGL_ANDROID_blob_cache\"\0"
    "EGL extension \"EGL_ANDROID_create_native_client_buffer\"\0"
    "EGL extension \"EGL_ANDROID_native_fence_sync\"\0"
    "EGL extension \"EGL_ANDROID_presentation_time\"\0"
    "EGL extension \"EGL_ANGLE_query_surface_pointer\"\0"
    "EGL extension \"EGL_EXT_device_base\"\0"
    "EGL extension \"EGL_EXT_device_enumeration\"\0"
    "EGL extension \"EGL_EXT_device_query\"\0"
    "EGL extension \"EGL_EXT_output_base\"\0"
    "EGL extension \"EGL_EXT_platform_base\"\0"
    "EGL extension \"EGL_EXT_stream_consumer_egloutput\"\0"
    "EGL extension \"EGL_EXT_swap_buffers_with_damage\"\0"
    "EGL extension \"EGL_HI_clientpixmap\"\0"
    "EGL extension \"EGL_KHR_cl_event2\"\0"
    "EGL extension \"EGL_KHR_debug\"\0"
    "EGL extension \"EGL_KHR_fence_sync\"\0"
    "EGL extension \"EGL_KHR_image\"\0"
    "EGL extension \"EGL_KHR_image_base\"\0"
    "EGL extension \"EGL_KHR_lock_surface3\"\0"
    "EGL extension \"EGL_KHR_lock_surface\"\0"
    "EGL extension \"EGL_KHR_partial_update\"\0"
    "EGL extension \"EGL_KHR_reusable_sync\"\0"
    "EGL extension \"EGL_KHR_stream\"\0"
    "EGL extension \"EGL_KHR_stream_consumer_gltexture\"\0"
    "EGL extension \"EGL_KHR_stream_cross_process_fd\"\0"
    "EGL extension \"EGL_KHR_stream_fifo\"\0"
    "EGL extension \"EGL_KHR_stream_producer_eglsurface\"\0"
    "EGL extension \"EGL_KHR_swap_buffers_with_damage\"\0"
    "EGL extension \"EGL_KHR_wait_sync\"\0"
    "EGL extension \"EGL_MESA_drm_image\"\0"
    "EGL extension \"EGL_MESA_image_dma_buf_export\"\0"
    "EGL extension \"EGL_NOK_swap_region2\"\0"
    "EGL extension \"EGL_NOK_swap_region\"\0"
    "EGL extension \"EGL_NV_native_query\"\0"
    "EGL extension \"EGL_NV_post_sub_buffer\"\0"
    "EGL extension \"EGL_NV_stream_consumer_gltexture_yuv\"\0"
    "EGL extension \"EGL_NV_stream_metadata\"\0"
    "EGL extension \"EGL_NV_stream_sync\"\0"
    "EGL extension \"EGL_NV_sync\"\0"
    "EGL extension \"EGL_NV_system_time\"\0"
     ;

static const uint32_t egl_enum_string_offsets[] = {
    [EGL_10] = 0,
    [EGL_11] = 7,
    [EGL_12] = 14,
    [EGL_14] = 21,
    [EGL_15] = 28,
    [EGL_extension_EGL_ANDROID_blob_cache] = 35,
    [EGL_extension_EGL_ANDROID_create_native_client_buffer] = 74,
    [EGL_extension_EGL_ANDROID_native_fence_sync] = 130,
    [EGL_extension_EGL_ANDROID_presentation_time] = 176,
    [EGL_extension_EGL_ANGLE_query_surface_pointer] = 222,
    [EGL_extension_EGL_EXT_device_base] = 270,
    [EGL_extension_EGL_EXT_device_enumeration] = 306,
    [EGL_extension_EGL_EXT_device_query] = 349,
    [EGL_extension_EGL_EXT_output_base] = 386,
    [EGL_extension_EGL_EXT_platform_base] = 422,
    [EGL_extension_EGL_EXT_stream_consumer_egloutput] = 460,
    [EGL_extension_EGL_EXT_swap_buffers_with_damage] = 510,
    [EGL_extension_EGL_HI_clientpixmap] = 559,
    [EGL_extension_EGL_KHR_cl_event2] = 595,
    [EGL_extension_EGL_KHR_debug] = 629,
    [EGL_extension_EGL_KHR_fence_sync] = 659,
    [EGL_extension_EGL_KHR_image] = 694,
    [EGL_extension_EGL_KHR_image_base] = 724,
    [EGL_extension_EGL_KHR_lock_surface3] = 759,
    [EGL_extension_EGL_KHR_lock_surface] = 797,
    [EGL_extension_EGL_KHR_partial_update] = 834,
    [EGL_extension_EGL_KHR_reusable_sync] = 873,
    [EGL_extension_EGL_KHR_stream] = 911,
    [EGL_extension_EGL_KHR_stream_consumer_gltexture] = 942,
    [EGL_extension_EGL_KHR_stream_cross_process_fd] = 992,
    [EGL_extension_EGL_KHR_stream_fifo] = 1040,
    [EGL_extension_EGL_KHR_stream_producer_eglsurface] = 1076,
    [EGL_extension_EGL_KHR_swap_buffers_with_damage] = 1127,
    [EGL_extension_EGL_KHR_wait_sync] = 1176,
    [EGL_extension_EGL_MESA_drm_image] = 1210,
    [EGL_extension_EGL_MESA_image_dma_buf_export] = 1245,
    [EGL_extension_EGL_NOK_swap_region2] = 1291,
    [EGL_extension_EGL_NOK_swap_region] = 1328,
    [EGL_extension_EGL_NV_native_query] = 1364,
    [EGL_extension_EGL_NV_post_sub_buffer] = 1400,
    [EGL_extension_EGL_NV_stream_consumer_gltexture_yuv] = 1439,
    [EGL_extension_EGL_NV_stream_metadata] = 1492,
    [EGL_extension_EGL_NV_stream_sync] = 1531,
    [EGL_extension_EGL_NV_sync] = 1566,
    [EGL_extension_EGL_NV_system_time] = 1594,
};

static const char* egl_entrypoint_strings[] = {
   "eglBindAPI",
   "eglBindTexImage",
   "eglChooseConfig",
   "eglClientWaitSync",
   "eglClientWaitSyncKHR",
   "eglClientWaitSyncNV",
   "eglCopyBuffers",
   "eglCreateContext",
   "eglCreateDRMImageMESA",
   "eglCreateFenceSyncNV",
   "eglCreateImage",
   "eglCreateImageKHR",
   "eglCreateNativeClientBufferANDROID",
   "eglCreatePbufferFromClientBuffer",
   "eglCreatePbufferSurface",
   "eglCreatePixmapSurface",
   "eglCreatePixmapSurfaceHI",
   "eglCreatePlatformPixmapSurface",
   "eglCreatePlatformPixmapSurfaceEXT",
   "eglCreatePlatformWindowSurface",
   "eglCreatePlatformWindowSurfaceEXT",
   "eglCreateStreamFromFileDescriptorKHR",
   "eglCreateStreamKHR",
   "eglCreateStreamProducerSurfaceKHR",
   "eglCreateStreamSyncNV",
   "eglCreateSync",
   "eglCreateSync64KHR",
   "eglCreateSyncKHR",
   "eglCreateWindowSurface",
   "eglDebugMessageControlKHR",
   "eglDestroyContext",
   "eglDestroyImage",
   "eglDestroyImageKHR",
   "eglDestroyStreamKHR",
   "eglDestroySurface",
   "eglDestroySync",
   "eglDestroySyncKHR",
   "eglDestroySyncNV",
   "eglDupNativeFenceFDANDROID",
   "eglExportDMABUFImageMESA",
   "eglExportDMABUFImageQueryMESA",
   "eglExportDRMImageMESA",
   "eglFenceNV",
   "eglGetConfigAttrib",
   "eglGetConfigs",
   "eglGetCurrentContext",
   "eglGetCurrentDisplay",
   "eglGetCurrentSurface",
   "eglGetDisplay",
   "eglGetError",
   "eglGetOutputLayersEXT",
   "eglGetOutputPortsEXT",
   "eglGetPlatformDisplay",
   "eglGetPlatformDisplayEXT",
   "eglGetProcAddress",
   "eglGetStreamFileDescriptorKHR",
   "eglGetSyncAttrib",
   "eglGetSyncAttribKHR",
   "eglGetSyncAttribNV",
   "eglGetSystemTimeFrequencyNV",
   "eglGetSystemTimeNV",
   "eglInitialize",
   "eglLabelObjectKHR",
   "eglLockSurfaceKHR",
   "eglMakeCurrent",
   "eglOutputLayerAttribEXT",
   "eglOutputPortAttribEXT",
   "eglPostSubBufferNV",
   "eglPresentationTimeANDROID",
   "eglQueryAPI",
   "eglQueryContext",
   "eglQueryDebugKHR",
   "eglQueryDeviceAttribEXT",
   "eglQueryDeviceStringEXT",
   "eglQueryDevicesEXT",
   "eglQueryDisplayAttribEXT",
   "eglQueryDisplayAttribNV",
   "eglQueryNativeDisplayNV",
   "eglQueryNativePixmapNV",
   "eglQueryNativeWindowNV",
   "eglQueryOutputLayerAttribEXT",
   "eglQueryOutputLayerStringEXT",
   "eglQueryOutputPortAttribEXT",
   "eglQueryOutputPortStringEXT",
   "eglQueryStreamKHR",
   "eglQueryStreamMetadataNV",
   "eglQueryStreamTimeKHR",
   "eglQueryStreamu64KHR",
   "eglQueryString",
   "eglQuerySurface",
   "eglQuerySurface64KHR",
   "eglQuerySurfacePointerANGLE",
   "eglReleaseTexImage",
   "eglReleaseThread",
   "eglSetBlobCacheFuncsANDROID",
   "eglSetDamageRegionKHR",
   "eglSetStreamMetadataNV",
   "eglSignalSyncKHR",
   "eglSignalSyncNV",
   "eglStreamAttribKHR",
   "eglStreamConsumerAcquireKHR",
   "eglStreamConsumerGLTextureExternalAttribsNV",
   "eglStreamConsumerGLTextureExternalKHR",
   "eglStreamConsumerOutputEXT",
   "eglStreamConsumerReleaseKHR",
   "eglSurfaceAttrib",
   "eglSwapBuffers",
   "eglSwapBuffersRegion2NOK",
   "eglSwapBuffersRegionNOK",
   "eglSwapBuffersWithDamageEXT",
   "eglSwapBuffersWithDamageKHR",
   "eglSwapInterval",
   "eglTerminate",
   "eglUnlockSurfaceKHR",
   "eglWaitClient",
   "eglWaitGL",
   "eglWaitNative",
   "eglWaitSync",
   "eglWaitSyncKHR",
};

#endif /* PLATFORM_HAS_EGL */
