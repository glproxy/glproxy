/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#if PLATFORM_HAS_GLX
#include "epoxy/glx.h"

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

enum glx_provider_versions {
    GLX_1_0 = 10,
    GLX_1_1 = 11,
    GLX_1_2 = 12,
    GLX_1_3 = 13,
    GLX_1_4 = 14,
} PACKED;


#endif /* PLATFORM_HAS_GLX */