/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#if PLATFORM_HAS_WGL
#include "epoxy/wgl.h"

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

enum wgl_provider_versions {
    WGL_1_0 = 10,
} PACKED;


#endif /* PLATFORM_HAS_WGL */