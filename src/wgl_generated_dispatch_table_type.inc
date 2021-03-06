/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#if PLATFORM_HAS_WGL
#include "glproxy/wgl.h"

struct wgl_dispatch_table {
    PFNWGLALLOCATEMEMORYNVPROC glproxy_wglAllocateMemoryNV;
    PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC glproxy_wglAssociateImageBufferEventsI3D;
    PFNWGLBEGINFRAMETRACKINGI3DPROC glproxy_wglBeginFrameTrackingI3D;
    PFNWGLBINDDISPLAYCOLORTABLEEXTPROC glproxy_wglBindDisplayColorTableEXT;
    PFNWGLBINDSWAPBARRIERNVPROC glproxy_wglBindSwapBarrierNV;
    PFNWGLBINDTEXIMAGEARBPROC glproxy_wglBindTexImageARB;
    PFNWGLBINDVIDEOCAPTUREDEVICENVPROC glproxy_wglBindVideoCaptureDeviceNV;
    PFNWGLBINDVIDEODEVICENVPROC glproxy_wglBindVideoDeviceNV;
    PFNWGLBINDVIDEOIMAGENVPROC glproxy_wglBindVideoImageNV;
    PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC glproxy_wglBlitContextFramebufferAMD;
    PFNWGLCHOOSEPIXELFORMATPROC glproxy_wglChoosePixelFormat;
    PFNWGLCHOOSEPIXELFORMATARBPROC glproxy_wglChoosePixelFormatARB;
    PFNWGLCHOOSEPIXELFORMATEXTPROC glproxy_wglChoosePixelFormatEXT;
    PFNWGLCOPYCONTEXTPROC glproxy_wglCopyContext;
    PFNWGLCOPYIMAGESUBDATANVPROC glproxy_wglCopyImageSubDataNV;
    PFNWGLCREATEAFFINITYDCNVPROC glproxy_wglCreateAffinityDCNV;
    PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC glproxy_wglCreateAssociatedContextAMD;
    PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC glproxy_wglCreateAssociatedContextAttribsAMD;
    PFNWGLCREATEBUFFERREGIONARBPROC glproxy_wglCreateBufferRegionARB;
    PFNWGLCREATECONTEXTPROC glproxy_wglCreateContext;
    PFNWGLCREATECONTEXTATTRIBSARBPROC glproxy_wglCreateContextAttribsARB;
    PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC glproxy_wglCreateDisplayColorTableEXT;
    PFNWGLCREATEIMAGEBUFFERI3DPROC glproxy_wglCreateImageBufferI3D;
    PFNWGLCREATELAYERCONTEXTPROC glproxy_wglCreateLayerContext;
    PFNWGLCREATEPBUFFERARBPROC glproxy_wglCreatePbufferARB;
    PFNWGLCREATEPBUFFEREXTPROC glproxy_wglCreatePbufferEXT;
    PFNWGLDXCLOSEDEVICENVPROC glproxy_wglDXCloseDeviceNV;
    PFNWGLDXLOCKOBJECTSNVPROC glproxy_wglDXLockObjectsNV;
    PFNWGLDXOBJECTACCESSNVPROC glproxy_wglDXObjectAccessNV;
    PFNWGLDXOPENDEVICENVPROC glproxy_wglDXOpenDeviceNV;
    PFNWGLDXREGISTEROBJECTNVPROC glproxy_wglDXRegisterObjectNV;
    PFNWGLDXSETRESOURCESHAREHANDLENVPROC glproxy_wglDXSetResourceShareHandleNV;
    PFNWGLDXUNLOCKOBJECTSNVPROC glproxy_wglDXUnlockObjectsNV;
    PFNWGLDXUNREGISTEROBJECTNVPROC glproxy_wglDXUnregisterObjectNV;
    PFNWGLDELAYBEFORESWAPNVPROC glproxy_wglDelayBeforeSwapNV;
    PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC glproxy_wglDeleteAssociatedContextAMD;
    PFNWGLDELETEBUFFERREGIONARBPROC glproxy_wglDeleteBufferRegionARB;
    PFNWGLDELETECONTEXTPROC glproxy_wglDeleteContext;
    PFNWGLDELETEDCNVPROC glproxy_wglDeleteDCNV;
    PFNWGLDESCRIBELAYERPLANEPROC glproxy_wglDescribeLayerPlane;
    PFNWGLDESCRIBEPIXELFORMATPROC glproxy_wglDescribePixelFormat;
    PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC glproxy_wglDestroyDisplayColorTableEXT;
    PFNWGLDESTROYIMAGEBUFFERI3DPROC glproxy_wglDestroyImageBufferI3D;
    PFNWGLDESTROYPBUFFERARBPROC glproxy_wglDestroyPbufferARB;
    PFNWGLDESTROYPBUFFEREXTPROC glproxy_wglDestroyPbufferEXT;
    PFNWGLDISABLEFRAMELOCKI3DPROC glproxy_wglDisableFrameLockI3D;
    PFNWGLDISABLEGENLOCKI3DPROC glproxy_wglDisableGenlockI3D;
    PFNWGLENABLEFRAMELOCKI3DPROC glproxy_wglEnableFrameLockI3D;
    PFNWGLENABLEGENLOCKI3DPROC glproxy_wglEnableGenlockI3D;
    PFNWGLENDFRAMETRACKINGI3DPROC glproxy_wglEndFrameTrackingI3D;
    PFNWGLENUMGPUDEVICESNVPROC glproxy_wglEnumGpuDevicesNV;
    PFNWGLENUMGPUSFROMAFFINITYDCNVPROC glproxy_wglEnumGpusFromAffinityDCNV;
    PFNWGLENUMGPUSNVPROC glproxy_wglEnumGpusNV;
    PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC glproxy_wglEnumerateVideoCaptureDevicesNV;
    PFNWGLENUMERATEVIDEODEVICESNVPROC glproxy_wglEnumerateVideoDevicesNV;
    PFNWGLFREEMEMORYNVPROC glproxy_wglFreeMemoryNV;
    PFNWGLGENLOCKSAMPLERATEI3DPROC glproxy_wglGenlockSampleRateI3D;
    PFNWGLGENLOCKSOURCEDELAYI3DPROC glproxy_wglGenlockSourceDelayI3D;
    PFNWGLGENLOCKSOURCEEDGEI3DPROC glproxy_wglGenlockSourceEdgeI3D;
    PFNWGLGENLOCKSOURCEI3DPROC glproxy_wglGenlockSourceI3D;
    PFNWGLGETCONTEXTGPUIDAMDPROC glproxy_wglGetContextGPUIDAMD;
    PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC glproxy_wglGetCurrentAssociatedContextAMD;
    PFNWGLGETCURRENTCONTEXTPROC glproxy_wglGetCurrentContext;
    PFNWGLGETCURRENTDCPROC glproxy_wglGetCurrentDC;
    PFNWGLGETCURRENTREADDCARBPROC glproxy_wglGetCurrentReadDCARB;
    PFNWGLGETCURRENTREADDCEXTPROC glproxy_wglGetCurrentReadDCEXT;
    PFNWGLGETDEFAULTPROCADDRESSPROC glproxy_wglGetDefaultProcAddress;
    PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC glproxy_wglGetDigitalVideoParametersI3D;
    PFNWGLGETENHMETAFILEPIXELFORMATPROC glproxy_wglGetEnhMetaFilePixelFormat;
    PFNWGLGETEXTENSIONSSTRINGARBPROC glproxy_wglGetExtensionsStringARB;
    PFNWGLGETEXTENSIONSSTRINGEXTPROC glproxy_wglGetExtensionsStringEXT;
    PFNWGLGETFRAMEUSAGEI3DPROC glproxy_wglGetFrameUsageI3D;
    PFNWGLGETGPUIDSAMDPROC glproxy_wglGetGPUIDsAMD;
    PFNWGLGETGPUINFOAMDPROC glproxy_wglGetGPUInfoAMD;
    PFNWGLGETGAMMATABLEI3DPROC glproxy_wglGetGammaTableI3D;
    PFNWGLGETGAMMATABLEPARAMETERSI3DPROC glproxy_wglGetGammaTableParametersI3D;
    PFNWGLGETGENLOCKSAMPLERATEI3DPROC glproxy_wglGetGenlockSampleRateI3D;
    PFNWGLGETGENLOCKSOURCEDELAYI3DPROC glproxy_wglGetGenlockSourceDelayI3D;
    PFNWGLGETGENLOCKSOURCEEDGEI3DPROC glproxy_wglGetGenlockSourceEdgeI3D;
    PFNWGLGETGENLOCKSOURCEI3DPROC glproxy_wglGetGenlockSourceI3D;
    PFNWGLGETLAYERPALETTEENTRIESPROC glproxy_wglGetLayerPaletteEntries;
    PFNWGLGETMSCRATEOMLPROC glproxy_wglGetMscRateOML;
    PFNWGLGETPBUFFERDCARBPROC glproxy_wglGetPbufferDCARB;
    PFNWGLGETPBUFFERDCEXTPROC glproxy_wglGetPbufferDCEXT;
    PFNWGLGETPIXELFORMATPROC glproxy_wglGetPixelFormat;
    PFNWGLGETPIXELFORMATATTRIBFVARBPROC glproxy_wglGetPixelFormatAttribfvARB;
    PFNWGLGETPIXELFORMATATTRIBFVEXTPROC glproxy_wglGetPixelFormatAttribfvEXT;
    PFNWGLGETPIXELFORMATATTRIBIVARBPROC glproxy_wglGetPixelFormatAttribivARB;
    PFNWGLGETPIXELFORMATATTRIBIVEXTPROC glproxy_wglGetPixelFormatAttribivEXT;
    PFNWGLGETPROCADDRESSPROC glproxy_wglGetProcAddress;
    PFNWGLGETSWAPINTERVALEXTPROC glproxy_wglGetSwapIntervalEXT;
    PFNWGLGETSYNCVALUESOMLPROC glproxy_wglGetSyncValuesOML;
    PFNWGLGETVIDEODEVICENVPROC glproxy_wglGetVideoDeviceNV;
    PFNWGLGETVIDEOINFONVPROC glproxy_wglGetVideoInfoNV;
    PFNWGLISENABLEDFRAMELOCKI3DPROC glproxy_wglIsEnabledFrameLockI3D;
    PFNWGLISENABLEDGENLOCKI3DPROC glproxy_wglIsEnabledGenlockI3D;
    PFNWGLJOINSWAPGROUPNVPROC glproxy_wglJoinSwapGroupNV;
    PFNWGLLOADDISPLAYCOLORTABLEEXTPROC glproxy_wglLoadDisplayColorTableEXT;
    PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC glproxy_wglLockVideoCaptureDeviceNV;
    PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC glproxy_wglMakeAssociatedContextCurrentAMD;
    PFNWGLMAKECONTEXTCURRENTARBPROC glproxy_wglMakeContextCurrentARB;
    PFNWGLMAKECONTEXTCURRENTEXTPROC glproxy_wglMakeContextCurrentEXT;
    PFNWGLMAKECURRENTPROC glproxy_wglMakeCurrent;
    PFNWGLQUERYCURRENTCONTEXTNVPROC glproxy_wglQueryCurrentContextNV;
    PFNWGLQUERYFRAMECOUNTNVPROC glproxy_wglQueryFrameCountNV;
    PFNWGLQUERYFRAMELOCKMASTERI3DPROC glproxy_wglQueryFrameLockMasterI3D;
    PFNWGLQUERYFRAMETRACKINGI3DPROC glproxy_wglQueryFrameTrackingI3D;
    PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC glproxy_wglQueryGenlockMaxSourceDelayI3D;
    PFNWGLQUERYMAXSWAPGROUPSNVPROC glproxy_wglQueryMaxSwapGroupsNV;
    PFNWGLQUERYPBUFFERARBPROC glproxy_wglQueryPbufferARB;
    PFNWGLQUERYPBUFFEREXTPROC glproxy_wglQueryPbufferEXT;
    PFNWGLQUERYSWAPGROUPNVPROC glproxy_wglQuerySwapGroupNV;
    PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC glproxy_wglQueryVideoCaptureDeviceNV;
    PFNWGLREALIZELAYERPALETTEPROC glproxy_wglRealizeLayerPalette;
    PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC glproxy_wglReleaseImageBufferEventsI3D;
    PFNWGLRELEASEPBUFFERDCARBPROC glproxy_wglReleasePbufferDCARB;
    PFNWGLRELEASEPBUFFERDCEXTPROC glproxy_wglReleasePbufferDCEXT;
    PFNWGLRELEASETEXIMAGEARBPROC glproxy_wglReleaseTexImageARB;
    PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC glproxy_wglReleaseVideoCaptureDeviceNV;
    PFNWGLRELEASEVIDEODEVICENVPROC glproxy_wglReleaseVideoDeviceNV;
    PFNWGLRELEASEVIDEOIMAGENVPROC glproxy_wglReleaseVideoImageNV;
    PFNWGLRESETFRAMECOUNTNVPROC glproxy_wglResetFrameCountNV;
    PFNWGLRESTOREBUFFERREGIONARBPROC glproxy_wglRestoreBufferRegionARB;
    PFNWGLSAVEBUFFERREGIONARBPROC glproxy_wglSaveBufferRegionARB;
    PFNWGLSENDPBUFFERTOVIDEONVPROC glproxy_wglSendPbufferToVideoNV;
    PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC glproxy_wglSetDigitalVideoParametersI3D;
    PFNWGLSETGAMMATABLEI3DPROC glproxy_wglSetGammaTableI3D;
    PFNWGLSETGAMMATABLEPARAMETERSI3DPROC glproxy_wglSetGammaTableParametersI3D;
    PFNWGLSETLAYERPALETTEENTRIESPROC glproxy_wglSetLayerPaletteEntries;
    PFNWGLSETPBUFFERATTRIBARBPROC glproxy_wglSetPbufferAttribARB;
    PFNWGLSETPIXELFORMATPROC glproxy_wglSetPixelFormat;
    PFNWGLSETSTEREOEMITTERSTATE3DLPROC glproxy_wglSetStereoEmitterState3DL;
    PFNWGLSHARELISTSPROC glproxy_wglShareLists;
    PFNWGLSWAPBUFFERSPROC glproxy_wglSwapBuffers;
    PFNWGLSWAPBUFFERSMSCOMLPROC glproxy_wglSwapBuffersMscOML;
    PFNWGLSWAPINTERVALEXTPROC glproxy_wglSwapIntervalEXT;
    PFNWGLSWAPLAYERBUFFERSPROC glproxy_wglSwapLayerBuffers;
    PFNWGLSWAPLAYERBUFFERSMSCOMLPROC glproxy_wglSwapLayerBuffersMscOML;
    PFNWGLUSEFONTBITMAPSAPROC glproxy_wglUseFontBitmapsA;
    PFNWGLUSEFONTBITMAPSWPROC glproxy_wglUseFontBitmapsW;
    PFNWGLUSEFONTOUTLINESPROC glproxy_wglUseFontOutlines;
    PFNWGLUSEFONTOUTLINESAPROC glproxy_wglUseFontOutlinesA;
    PFNWGLUSEFONTOUTLINESWPROC glproxy_wglUseFontOutlinesW;
    PFNWGLWAITFORMSCOMLPROC glproxy_wglWaitForMscOML;
    PFNWGLWAITFORSBCOMLPROC glproxy_wglWaitForSbcOML;
};

#define WGL_EXTENSIONS_BITMAP_COUNT 2

enum wgl_provider_versions {
    WGL_1_0 = 10,
} PACKED;


#endif /* PLATFORM_HAS_WGL */
