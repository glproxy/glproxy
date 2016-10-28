/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#include "dispatch_common.h"
#if PLATFORM_HAS_WGL

struct wgl_dispatch_table {
    PFNWGLALLOCATEMEMORYNVPROC epoxy_wglAllocateMemoryNV;
    PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC epoxy_wglAssociateImageBufferEventsI3D;
    PFNWGLBEGINFRAMETRACKINGI3DPROC epoxy_wglBeginFrameTrackingI3D;
    PFNWGLBINDDISPLAYCOLORTABLEEXTPROC epoxy_wglBindDisplayColorTableEXT;
    PFNWGLBINDSWAPBARRIERNVPROC epoxy_wglBindSwapBarrierNV;
    PFNWGLBINDTEXIMAGEARBPROC epoxy_wglBindTexImageARB;
    PFNWGLBINDVIDEOCAPTUREDEVICENVPROC epoxy_wglBindVideoCaptureDeviceNV;
    PFNWGLBINDVIDEODEVICENVPROC epoxy_wglBindVideoDeviceNV;
    PFNWGLBINDVIDEOIMAGENVPROC epoxy_wglBindVideoImageNV;
    PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC epoxy_wglBlitContextFramebufferAMD;
    PFNWGLCHOOSEPIXELFORMATARBPROC epoxy_wglChoosePixelFormatARB;
    PFNWGLCHOOSEPIXELFORMATEXTPROC epoxy_wglChoosePixelFormatEXT;
    PFNWGLCOPYCONTEXTPROC epoxy_wglCopyContext;
    PFNWGLCOPYIMAGESUBDATANVPROC epoxy_wglCopyImageSubDataNV;
    PFNWGLCREATEAFFINITYDCNVPROC epoxy_wglCreateAffinityDCNV;
    PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC epoxy_wglCreateAssociatedContextAMD;
    PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC epoxy_wglCreateAssociatedContextAttribsAMD;
    PFNWGLCREATEBUFFERREGIONARBPROC epoxy_wglCreateBufferRegionARB;
    PFNWGLCREATECONTEXTPROC epoxy_wglCreateContext;
    PFNWGLCREATECONTEXTATTRIBSARBPROC epoxy_wglCreateContextAttribsARB;
    PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC epoxy_wglCreateDisplayColorTableEXT;
    PFNWGLCREATEIMAGEBUFFERI3DPROC epoxy_wglCreateImageBufferI3D;
    PFNWGLCREATELAYERCONTEXTPROC epoxy_wglCreateLayerContext;
    PFNWGLCREATEPBUFFERARBPROC epoxy_wglCreatePbufferARB;
    PFNWGLCREATEPBUFFEREXTPROC epoxy_wglCreatePbufferEXT;
    PFNWGLDXCLOSEDEVICENVPROC epoxy_wglDXCloseDeviceNV;
    PFNWGLDXLOCKOBJECTSNVPROC epoxy_wglDXLockObjectsNV;
    PFNWGLDXOBJECTACCESSNVPROC epoxy_wglDXObjectAccessNV;
    PFNWGLDXOPENDEVICENVPROC epoxy_wglDXOpenDeviceNV;
    PFNWGLDXREGISTEROBJECTNVPROC epoxy_wglDXRegisterObjectNV;
    PFNWGLDXSETRESOURCESHAREHANDLENVPROC epoxy_wglDXSetResourceShareHandleNV;
    PFNWGLDXUNLOCKOBJECTSNVPROC epoxy_wglDXUnlockObjectsNV;
    PFNWGLDXUNREGISTEROBJECTNVPROC epoxy_wglDXUnregisterObjectNV;
    PFNWGLDELAYBEFORESWAPNVPROC epoxy_wglDelayBeforeSwapNV;
    PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC epoxy_wglDeleteAssociatedContextAMD;
    PFNWGLDELETEBUFFERREGIONARBPROC epoxy_wglDeleteBufferRegionARB;
    PFNWGLDELETECONTEXTPROC epoxy_wglDeleteContext;
    PFNWGLDELETEDCNVPROC epoxy_wglDeleteDCNV;
    PFNWGLDESCRIBELAYERPLANEPROC epoxy_wglDescribeLayerPlane;
    PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC epoxy_wglDestroyDisplayColorTableEXT;
    PFNWGLDESTROYIMAGEBUFFERI3DPROC epoxy_wglDestroyImageBufferI3D;
    PFNWGLDESTROYPBUFFERARBPROC epoxy_wglDestroyPbufferARB;
    PFNWGLDESTROYPBUFFEREXTPROC epoxy_wglDestroyPbufferEXT;
    PFNWGLDISABLEFRAMELOCKI3DPROC epoxy_wglDisableFrameLockI3D;
    PFNWGLDISABLEGENLOCKI3DPROC epoxy_wglDisableGenlockI3D;
    PFNWGLENABLEFRAMELOCKI3DPROC epoxy_wglEnableFrameLockI3D;
    PFNWGLENABLEGENLOCKI3DPROC epoxy_wglEnableGenlockI3D;
    PFNWGLENDFRAMETRACKINGI3DPROC epoxy_wglEndFrameTrackingI3D;
    PFNWGLENUMGPUDEVICESNVPROC epoxy_wglEnumGpuDevicesNV;
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC epoxy_wglEnumGpusFromAffinityDCNV;
    PFNWGLENUMGPUSNVPROC epoxy_wglEnumGpusNV;
    PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC epoxy_wglEnumerateVideoCaptureDevicesNV;
    PFNWGLENUMERATEVIDEODEVICESNVPROC epoxy_wglEnumerateVideoDevicesNV;
    PFNWGLFREEMEMORYNVPROC epoxy_wglFreeMemoryNV;
    PFNWGLGENLOCKSAMPLERATEI3DPROC epoxy_wglGenlockSampleRateI3D;
    PFNWGLGENLOCKSOURCEDELAYI3DPROC epoxy_wglGenlockSourceDelayI3D;
    PFNWGLGENLOCKSOURCEEDGEI3DPROC epoxy_wglGenlockSourceEdgeI3D;
    PFNWGLGENLOCKSOURCEI3DPROC epoxy_wglGenlockSourceI3D;
    PFNWGLGETCONTEXTGPUIDAMDPROC epoxy_wglGetContextGPUIDAMD;
    PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC epoxy_wglGetCurrentAssociatedContextAMD;
    PFNWGLGETCURRENTCONTEXTPROC epoxy_wglGetCurrentContext;
    PFNWGLGETCURRENTDCPROC epoxy_wglGetCurrentDC;
    PFNWGLGETCURRENTREADDCARBPROC epoxy_wglGetCurrentReadDCARB;
    PFNWGLGETCURRENTREADDCEXTPROC epoxy_wglGetCurrentReadDCEXT;
    PFNWGLGETDEFAULTPROCADDRESSPROC epoxy_wglGetDefaultProcAddress;
    PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC epoxy_wglGetDigitalVideoParametersI3D;
    PFNWGLGETEXTENSIONSSTRINGARBPROC epoxy_wglGetExtensionsStringARB;
    PFNWGLGETEXTENSIONSSTRINGEXTPROC epoxy_wglGetExtensionsStringEXT;
    PFNWGLGETFRAMEUSAGEI3DPROC epoxy_wglGetFrameUsageI3D;
    PFNWGLGETGPUIDSAMDPROC epoxy_wglGetGPUIDsAMD;
    PFNWGLGETGPUINFOAMDPROC epoxy_wglGetGPUInfoAMD;
    PFNWGLGETGAMMATABLEI3DPROC epoxy_wglGetGammaTableI3D;
    PFNWGLGETGAMMATABLEPARAMETERSI3DPROC epoxy_wglGetGammaTableParametersI3D;
    PFNWGLGETGENLOCKSAMPLERATEI3DPROC epoxy_wglGetGenlockSampleRateI3D;
    PFNWGLGETGENLOCKSOURCEDELAYI3DPROC epoxy_wglGetGenlockSourceDelayI3D;
    PFNWGLGETGENLOCKSOURCEEDGEI3DPROC epoxy_wglGetGenlockSourceEdgeI3D;
    PFNWGLGETGENLOCKSOURCEI3DPROC epoxy_wglGetGenlockSourceI3D;
    PFNWGLGETLAYERPALETTEENTRIESPROC epoxy_wglGetLayerPaletteEntries;
    PFNWGLGETMSCRATEOMLPROC epoxy_wglGetMscRateOML;
    PFNWGLGETPBUFFERDCARBPROC epoxy_wglGetPbufferDCARB;
    PFNWGLGETPBUFFERDCEXTPROC epoxy_wglGetPbufferDCEXT;
    PFNWGLGETPIXELFORMATATTRIBFVARBPROC epoxy_wglGetPixelFormatAttribfvARB;
    PFNWGLGETPIXELFORMATATTRIBFVEXTPROC epoxy_wglGetPixelFormatAttribfvEXT;
    PFNWGLGETPIXELFORMATATTRIBIVARBPROC epoxy_wglGetPixelFormatAttribivARB;
    PFNWGLGETPIXELFORMATATTRIBIVEXTPROC epoxy_wglGetPixelFormatAttribivEXT;
    PFNWGLGETPROCADDRESSPROC epoxy_wglGetProcAddress;
    PFNWGLGETSWAPINTERVALEXTPROC epoxy_wglGetSwapIntervalEXT;
    PFNWGLGETSYNCVALUESOMLPROC epoxy_wglGetSyncValuesOML;
    PFNWGLGETVIDEODEVICENVPROC epoxy_wglGetVideoDeviceNV;
    PFNWGLGETVIDEOINFONVPROC epoxy_wglGetVideoInfoNV;
    PFNWGLISENABLEDFRAMELOCKI3DPROC epoxy_wglIsEnabledFrameLockI3D;
    PFNWGLISENABLEDGENLOCKI3DPROC epoxy_wglIsEnabledGenlockI3D;
    PFNWGLJOINSWAPGROUPNVPROC epoxy_wglJoinSwapGroupNV;
    PFNWGLLOADDISPLAYCOLORTABLEEXTPROC epoxy_wglLoadDisplayColorTableEXT;
    PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC epoxy_wglLockVideoCaptureDeviceNV;
    PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC epoxy_wglMakeAssociatedContextCurrentAMD;
    PFNWGLMAKECONTEXTCURRENTARBPROC epoxy_wglMakeContextCurrentARB;
    PFNWGLMAKECONTEXTCURRENTEXTPROC epoxy_wglMakeContextCurrentEXT;
    PFNWGLMAKECURRENTPROC epoxy_wglMakeCurrent;
    PFNWGLQUERYCURRENTCONTEXTNVPROC epoxy_wglQueryCurrentContextNV;
    PFNWGLQUERYFRAMECOUNTNVPROC epoxy_wglQueryFrameCountNV;
    PFNWGLQUERYFRAMELOCKMASTERI3DPROC epoxy_wglQueryFrameLockMasterI3D;
    PFNWGLQUERYFRAMETRACKINGI3DPROC epoxy_wglQueryFrameTrackingI3D;
    PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC epoxy_wglQueryGenlockMaxSourceDelayI3D;
    PFNWGLQUERYMAXSWAPGROUPSNVPROC epoxy_wglQueryMaxSwapGroupsNV;
    PFNWGLQUERYPBUFFERARBPROC epoxy_wglQueryPbufferARB;
    PFNWGLQUERYPBUFFEREXTPROC epoxy_wglQueryPbufferEXT;
    PFNWGLQUERYSWAPGROUPNVPROC epoxy_wglQuerySwapGroupNV;
    PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC epoxy_wglQueryVideoCaptureDeviceNV;
    PFNWGLREALIZELAYERPALETTEPROC epoxy_wglRealizeLayerPalette;
    PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC epoxy_wglReleaseImageBufferEventsI3D;
    PFNWGLRELEASEPBUFFERDCARBPROC epoxy_wglReleasePbufferDCARB;
    PFNWGLRELEASEPBUFFERDCEXTPROC epoxy_wglReleasePbufferDCEXT;
    PFNWGLRELEASETEXIMAGEARBPROC epoxy_wglReleaseTexImageARB;
    PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC epoxy_wglReleaseVideoCaptureDeviceNV;
    PFNWGLRELEASEVIDEODEVICENVPROC epoxy_wglReleaseVideoDeviceNV;
    PFNWGLRELEASEVIDEOIMAGENVPROC epoxy_wglReleaseVideoImageNV;
    PFNWGLRESETFRAMECOUNTNVPROC epoxy_wglResetFrameCountNV;
    PFNWGLRESTOREBUFFERREGIONARBPROC epoxy_wglRestoreBufferRegionARB;
    PFNWGLSAVEBUFFERREGIONARBPROC epoxy_wglSaveBufferRegionARB;
    PFNWGLSENDPBUFFERTOVIDEONVPROC epoxy_wglSendPbufferToVideoNV;
    PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC epoxy_wglSetDigitalVideoParametersI3D;
    PFNWGLSETGAMMATABLEI3DPROC epoxy_wglSetGammaTableI3D;
    PFNWGLSETGAMMATABLEPARAMETERSI3DPROC epoxy_wglSetGammaTableParametersI3D;
    PFNWGLSETLAYERPALETTEENTRIESPROC epoxy_wglSetLayerPaletteEntries;
    PFNWGLSETPBUFFERATTRIBARBPROC epoxy_wglSetPbufferAttribARB;
    PFNWGLSETSTEREOEMITTERSTATE3DLPROC epoxy_wglSetStereoEmitterState3DL;
    PFNWGLSHARELISTSPROC epoxy_wglShareLists;
    PFNWGLSWAPBUFFERSMSCOMLPROC epoxy_wglSwapBuffersMscOML;
    PFNWGLSWAPINTERVALEXTPROC epoxy_wglSwapIntervalEXT;
    PFNWGLSWAPLAYERBUFFERSPROC epoxy_wglSwapLayerBuffers;
    PFNWGLSWAPLAYERBUFFERSMSCOMLPROC epoxy_wglSwapLayerBuffersMscOML;
    PFNWGLUSEFONTBITMAPSAPROC epoxy_wglUseFontBitmapsA;
    PFNWGLUSEFONTBITMAPSWPROC epoxy_wglUseFontBitmapsW;
    PFNWGLUSEFONTOUTLINESPROC epoxy_wglUseFontOutlines;
    PFNWGLUSEFONTOUTLINESAPROC epoxy_wglUseFontOutlinesA;
    PFNWGLUSEFONTOUTLINESWPROC epoxy_wglUseFontOutlinesW;
    PFNWGLWAITFORMSCOMLPROC epoxy_wglWaitForMscOML;
    PFNWGLWAITFORSBCOMLPROC epoxy_wglWaitForSbcOML;
};

enum wgl_provider {
    wgl_provider_terminator = 0,
    WGL_10,
    WGL_extension_WGL_3DL_stereo_control,
    WGL_extension_WGL_AMD_gpu_association,
    WGL_extension_WGL_ARB_buffer_region,
    WGL_extension_WGL_ARB_create_context,
    WGL_extension_WGL_ARB_extensions_string,
    WGL_extension_WGL_ARB_make_current_read,
    WGL_extension_WGL_ARB_pbuffer,
    WGL_extension_WGL_ARB_pixel_format,
    WGL_extension_WGL_ARB_render_texture,
    WGL_extension_WGL_EXT_display_color_table,
    WGL_extension_WGL_EXT_extensions_string,
    WGL_extension_WGL_EXT_make_current_read,
    WGL_extension_WGL_EXT_pbuffer,
    WGL_extension_WGL_EXT_pixel_format,
    WGL_extension_WGL_EXT_swap_control,
    WGL_extension_WGL_I3D_digital_video_control,
    WGL_extension_WGL_I3D_gamma,
    WGL_extension_WGL_I3D_genlock,
    WGL_extension_WGL_I3D_image_buffer,
    WGL_extension_WGL_I3D_swap_frame_lock,
    WGL_extension_WGL_I3D_swap_frame_usage,
    WGL_extension_WGL_NV_DX_interop,
    WGL_extension_WGL_NV_copy_image,
    WGL_extension_WGL_NV_delay_before_swap,
    WGL_extension_WGL_NV_gpu_affinity,
    WGL_extension_WGL_NV_present_video,
    WGL_extension_WGL_NV_swap_group,
    WGL_extension_WGL_NV_vertex_array_range,
    WGL_extension_WGL_NV_video_capture,
    WGL_extension_WGL_NV_video_output,
    WGL_extension_WGL_OML_sync_control,
} PACKED;

static const char *wgl_enum_string =
    "WGL 10\0"
    "WGL extension \"WGL_3DL_stereo_control\"\0"
    "WGL extension \"WGL_AMD_gpu_association\"\0"
    "WGL extension \"WGL_ARB_buffer_region\"\0"
    "WGL extension \"WGL_ARB_create_context\"\0"
    "WGL extension \"WGL_ARB_extensions_string\"\0"
    "WGL extension \"WGL_ARB_make_current_read\"\0"
    "WGL extension \"WGL_ARB_pbuffer\"\0"
    "WGL extension \"WGL_ARB_pixel_format\"\0"
    "WGL extension \"WGL_ARB_render_texture\"\0"
    "WGL extension \"WGL_EXT_display_color_table\"\0"
    "WGL extension \"WGL_EXT_extensions_string\"\0"
    "WGL extension \"WGL_EXT_make_current_read\"\0"
    "WGL extension \"WGL_EXT_pbuffer\"\0"
    "WGL extension \"WGL_EXT_pixel_format\"\0"
    "WGL extension \"WGL_EXT_swap_control\"\0"
    "WGL extension \"WGL_I3D_digital_video_control\"\0"
    "WGL extension \"WGL_I3D_gamma\"\0"
    "WGL extension \"WGL_I3D_genlock\"\0"
    "WGL extension \"WGL_I3D_image_buffer\"\0"
    "WGL extension \"WGL_I3D_swap_frame_lock\"\0"
    "WGL extension \"WGL_I3D_swap_frame_usage\"\0"
    "WGL extension \"WGL_NV_DX_interop\"\0"
    "WGL extension \"WGL_NV_copy_image\"\0"
    "WGL extension \"WGL_NV_delay_before_swap\"\0"
    "WGL extension \"WGL_NV_gpu_affinity\"\0"
    "WGL extension \"WGL_NV_present_video\"\0"
    "WGL extension \"WGL_NV_swap_group\"\0"
    "WGL extension \"WGL_NV_vertex_array_range\"\0"
    "WGL extension \"WGL_NV_video_capture\"\0"
    "WGL extension \"WGL_NV_video_output\"\0"
    "WGL extension \"WGL_OML_sync_control\"\0"
     ;

static const uint32_t wgl_enum_string_offsets[] = {
    [WGL_10] = 0,
    [WGL_extension_WGL_3DL_stereo_control] = 7,
    [WGL_extension_WGL_AMD_gpu_association] = 46,
    [WGL_extension_WGL_ARB_buffer_region] = 86,
    [WGL_extension_WGL_ARB_create_context] = 124,
    [WGL_extension_WGL_ARB_extensions_string] = 163,
    [WGL_extension_WGL_ARB_make_current_read] = 205,
    [WGL_extension_WGL_ARB_pbuffer] = 247,
    [WGL_extension_WGL_ARB_pixel_format] = 279,
    [WGL_extension_WGL_ARB_render_texture] = 316,
    [WGL_extension_WGL_EXT_display_color_table] = 355,
    [WGL_extension_WGL_EXT_extensions_string] = 399,
    [WGL_extension_WGL_EXT_make_current_read] = 441,
    [WGL_extension_WGL_EXT_pbuffer] = 483,
    [WGL_extension_WGL_EXT_pixel_format] = 515,
    [WGL_extension_WGL_EXT_swap_control] = 552,
    [WGL_extension_WGL_I3D_digital_video_control] = 589,
    [WGL_extension_WGL_I3D_gamma] = 635,
    [WGL_extension_WGL_I3D_genlock] = 665,
    [WGL_extension_WGL_I3D_image_buffer] = 697,
    [WGL_extension_WGL_I3D_swap_frame_lock] = 734,
    [WGL_extension_WGL_I3D_swap_frame_usage] = 774,
    [WGL_extension_WGL_NV_DX_interop] = 815,
    [WGL_extension_WGL_NV_copy_image] = 849,
    [WGL_extension_WGL_NV_delay_before_swap] = 883,
    [WGL_extension_WGL_NV_gpu_affinity] = 924,
    [WGL_extension_WGL_NV_present_video] = 960,
    [WGL_extension_WGL_NV_swap_group] = 997,
    [WGL_extension_WGL_NV_vertex_array_range] = 1031,
    [WGL_extension_WGL_NV_video_capture] = 1073,
    [WGL_extension_WGL_NV_video_output] = 1110,
    [WGL_extension_WGL_OML_sync_control] = 1146,
};

static const char* wgl_entrypoint_strings[] = {
   "wglAllocateMemoryNV",
   "wglAssociateImageBufferEventsI3D",
   "wglBeginFrameTrackingI3D",
   "wglBindDisplayColorTableEXT",
   "wglBindSwapBarrierNV",
   "wglBindTexImageARB",
   "wglBindVideoCaptureDeviceNV",
   "wglBindVideoDeviceNV",
   "wglBindVideoImageNV",
   "wglBlitContextFramebufferAMD",
   "wglChoosePixelFormatARB",
   "wglChoosePixelFormatEXT",
   "wglCopyContext",
   "wglCopyImageSubDataNV",
   "wglCreateAffinityDCNV",
   "wglCreateAssociatedContextAMD",
   "wglCreateAssociatedContextAttribsAMD",
   "wglCreateBufferRegionARB",
   "wglCreateContext",
   "wglCreateContextAttribsARB",
   "wglCreateDisplayColorTableEXT",
   "wglCreateImageBufferI3D",
   "wglCreateLayerContext",
   "wglCreatePbufferARB",
   "wglCreatePbufferEXT",
   "wglDXCloseDeviceNV",
   "wglDXLockObjectsNV",
   "wglDXObjectAccessNV",
   "wglDXOpenDeviceNV",
   "wglDXRegisterObjectNV",
   "wglDXSetResourceShareHandleNV",
   "wglDXUnlockObjectsNV",
   "wglDXUnregisterObjectNV",
   "wglDelayBeforeSwapNV",
   "wglDeleteAssociatedContextAMD",
   "wglDeleteBufferRegionARB",
   "wglDeleteContext",
   "wglDeleteDCNV",
   "wglDescribeLayerPlane",
   "wglDestroyDisplayColorTableEXT",
   "wglDestroyImageBufferI3D",
   "wglDestroyPbufferARB",
   "wglDestroyPbufferEXT",
   "wglDisableFrameLockI3D",
   "wglDisableGenlockI3D",
   "wglEnableFrameLockI3D",
   "wglEnableGenlockI3D",
   "wglEndFrameTrackingI3D",
   "wglEnumGpuDevicesNV",
   "wglEnumGpusFromAffinityDCNV",
   "wglEnumGpusNV",
   "wglEnumerateVideoCaptureDevicesNV",
   "wglEnumerateVideoDevicesNV",
   "wglFreeMemoryNV",
   "wglGenlockSampleRateI3D",
   "wglGenlockSourceDelayI3D",
   "wglGenlockSourceEdgeI3D",
   "wglGenlockSourceI3D",
   "wglGetContextGPUIDAMD",
   "wglGetCurrentAssociatedContextAMD",
   "wglGetCurrentContext",
   "wglGetCurrentDC",
   "wglGetCurrentReadDCARB",
   "wglGetCurrentReadDCEXT",
   "wglGetDefaultProcAddress",
   "wglGetDigitalVideoParametersI3D",
   "wglGetExtensionsStringARB",
   "wglGetExtensionsStringEXT",
   "wglGetFrameUsageI3D",
   "wglGetGPUIDsAMD",
   "wglGetGPUInfoAMD",
   "wglGetGammaTableI3D",
   "wglGetGammaTableParametersI3D",
   "wglGetGenlockSampleRateI3D",
   "wglGetGenlockSourceDelayI3D",
   "wglGetGenlockSourceEdgeI3D",
   "wglGetGenlockSourceI3D",
   "wglGetLayerPaletteEntries",
   "wglGetMscRateOML",
   "wglGetPbufferDCARB",
   "wglGetPbufferDCEXT",
   "wglGetPixelFormatAttribfvARB",
   "wglGetPixelFormatAttribfvEXT",
   "wglGetPixelFormatAttribivARB",
   "wglGetPixelFormatAttribivEXT",
   "wglGetProcAddress",
   "wglGetSwapIntervalEXT",
   "wglGetSyncValuesOML",
   "wglGetVideoDeviceNV",
   "wglGetVideoInfoNV",
   "wglIsEnabledFrameLockI3D",
   "wglIsEnabledGenlockI3D",
   "wglJoinSwapGroupNV",
   "wglLoadDisplayColorTableEXT",
   "wglLockVideoCaptureDeviceNV",
   "wglMakeAssociatedContextCurrentAMD",
   "wglMakeContextCurrentARB",
   "wglMakeContextCurrentEXT",
   "wglMakeCurrent",
   "wglQueryCurrentContextNV",
   "wglQueryFrameCountNV",
   "wglQueryFrameLockMasterI3D",
   "wglQueryFrameTrackingI3D",
   "wglQueryGenlockMaxSourceDelayI3D",
   "wglQueryMaxSwapGroupsNV",
   "wglQueryPbufferARB",
   "wglQueryPbufferEXT",
   "wglQuerySwapGroupNV",
   "wglQueryVideoCaptureDeviceNV",
   "wglRealizeLayerPalette",
   "wglReleaseImageBufferEventsI3D",
   "wglReleasePbufferDCARB",
   "wglReleasePbufferDCEXT",
   "wglReleaseTexImageARB",
   "wglReleaseVideoCaptureDeviceNV",
   "wglReleaseVideoDeviceNV",
   "wglReleaseVideoImageNV",
   "wglResetFrameCountNV",
   "wglRestoreBufferRegionARB",
   "wglSaveBufferRegionARB",
   "wglSendPbufferToVideoNV",
   "wglSetDigitalVideoParametersI3D",
   "wglSetGammaTableI3D",
   "wglSetGammaTableParametersI3D",
   "wglSetLayerPaletteEntries",
   "wglSetPbufferAttribARB",
   "wglSetStereoEmitterState3DL",
   "wglShareLists",
   "wglSwapBuffersMscOML",
   "wglSwapIntervalEXT",
   "wglSwapLayerBuffers",
   "wglSwapLayerBuffersMscOML",
   "wglUseFontBitmapsA",
   "wglUseFontBitmapsW",
   "wglUseFontOutlines",
   "wglUseFontOutlinesA",
   "wglUseFontOutlinesW",
   "wglWaitForMscOML",
   "wglWaitForSbcOML",
};

#endif /* PLATFORM_HAS_WGL */
