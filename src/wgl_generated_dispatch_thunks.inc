/* GL dispatch code.
 * This is code-generated from the GL API XML files from Khronos.
 */
#if PLATFORM_HAS_WGL
#include "dispatch_common.h"

static const char *wgl_extensions_enum_string =
    "WGL_3DL_stereo_control\0"
    "WGL_AMD_gpu_association\0"
    "WGL_ARB_buffer_region\0"
    "WGL_ARB_create_context\0"
    "WGL_ARB_extensions_string\0"
    "WGL_ARB_make_current_read\0"
    "WGL_ARB_pbuffer\0"
    "WGL_ARB_pixel_format\0"
    "WGL_ARB_render_texture\0"
    "WGL_EXT_display_color_table\0"
    "WGL_EXT_extensions_string\0"
    "WGL_EXT_make_current_read\0"
    "WGL_EXT_pbuffer\0"
    "WGL_EXT_pixel_format\0"
    "WGL_EXT_swap_control\0"
    "WGL_I3D_digital_video_control\0"
    "WGL_I3D_gamma\0"
    "WGL_I3D_genlock\0"
    "WGL_I3D_image_buffer\0"
    "WGL_I3D_swap_frame_lock\0"
    "WGL_I3D_swap_frame_usage\0"
    "WGL_NV_DX_interop\0"
    "WGL_NV_copy_image\0"
    "WGL_NV_delay_before_swap\0"
    "WGL_NV_gpu_affinity\0"
    "WGL_NV_present_video\0"
    "WGL_NV_swap_group\0"
    "WGL_NV_vertex_array_range\0"
    "WGL_NV_video_capture\0"
    "WGL_NV_video_output\0"
    "WGL_OML_sync_control\0"
;

enum wgl_provider_extensions {
    WGL_extension_WGL_3DL_stereo_control = 0,
    WGL_extension_WGL_AMD_gpu_association = 23,
    WGL_extension_WGL_ARB_buffer_region = 47,
    WGL_extension_WGL_ARB_create_context = 69,
    WGL_extension_WGL_ARB_extensions_string = 92,
    WGL_extension_WGL_ARB_make_current_read = 118,
    WGL_extension_WGL_ARB_pbuffer = 144,
    WGL_extension_WGL_ARB_pixel_format = 160,
    WGL_extension_WGL_ARB_render_texture = 181,
    WGL_extension_WGL_EXT_display_color_table = 204,
    WGL_extension_WGL_EXT_extensions_string = 232,
    WGL_extension_WGL_EXT_make_current_read = 258,
    WGL_extension_WGL_EXT_pbuffer = 284,
    WGL_extension_WGL_EXT_pixel_format = 300,
    WGL_extension_WGL_EXT_swap_control = 321,
    WGL_extension_WGL_I3D_digital_video_control = 342,
    WGL_extension_WGL_I3D_gamma = 372,
    WGL_extension_WGL_I3D_genlock = 386,
    WGL_extension_WGL_I3D_image_buffer = 402,
    WGL_extension_WGL_I3D_swap_frame_lock = 423,
    WGL_extension_WGL_I3D_swap_frame_usage = 447,
    WGL_extension_WGL_NV_DX_interop = 472,
    WGL_extension_WGL_NV_copy_image = 490,
    WGL_extension_WGL_NV_delay_before_swap = 508,
    WGL_extension_WGL_NV_gpu_affinity = 533,
    WGL_extension_WGL_NV_present_video = 553,
    WGL_extension_WGL_NV_swap_group = 574,
    WGL_extension_WGL_NV_vertex_array_range = 592,
    WGL_extension_WGL_NV_video_capture = 618,
    WGL_extension_WGL_NV_video_output = 639,
    WGL_extension_WGL_OML_sync_control = 659,
} PACKED;

static const khronos_uint8_t wgl_entrypoint_strings[] = {
    119, 103, 108, 65, 108, 108, 111, 99, 97, 116, 101, 77, 101, 109, 111, 114, 121, 78, 86, 0, /*wglAllocateMemoryNV*/
    119, 103, 108, 65, 115, 115, 111, 99, 105, 97, 116, 101, 73, 109, 97, 103, 101, 66, 117, 102, 102, 101, 114, 69, 118, 101, 110, 116, 115, 73, 51, 68, 0, /*wglAssociateImageBufferEventsI3D*/
    119, 103, 108, 66, 101, 103, 105, 110, 70, 114, 97, 109, 101, 84, 114, 97, 99, 107, 105, 110, 103, 73, 51, 68, 0, /*wglBeginFrameTrackingI3D*/
    119, 103, 108, 66, 105, 110, 100, 68, 105, 115, 112, 108, 97, 121, 67, 111, 108, 111, 114, 84, 97, 98, 108, 101, 69, 88, 84, 0, /*wglBindDisplayColorTableEXT*/
    119, 103, 108, 66, 105, 110, 100, 83, 119, 97, 112, 66, 97, 114, 114, 105, 101, 114, 78, 86, 0, /*wglBindSwapBarrierNV*/
    119, 103, 108, 66, 105, 110, 100, 84, 101, 120, 73, 109, 97, 103, 101, 65, 82, 66, 0, /*wglBindTexImageARB*/
    119, 103, 108, 66, 105, 110, 100, 86, 105, 100, 101, 111, 67, 97, 112, 116, 117, 114, 101, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglBindVideoCaptureDeviceNV*/
    119, 103, 108, 66, 105, 110, 100, 86, 105, 100, 101, 111, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglBindVideoDeviceNV*/
    119, 103, 108, 66, 105, 110, 100, 86, 105, 100, 101, 111, 73, 109, 97, 103, 101, 78, 86, 0, /*wglBindVideoImageNV*/
    119, 103, 108, 66, 108, 105, 116, 67, 111, 110, 116, 101, 120, 116, 70, 114, 97, 109, 101, 98, 117, 102, 102, 101, 114, 65, 77, 68, 0, /*wglBlitContextFramebufferAMD*/
    119, 103, 108, 67, 104, 111, 111, 115, 101, 80, 105, 120, 101, 108, 70, 111, 114, 109, 97, 116, 65, 82, 66, 0, /*wglChoosePixelFormatARB*/
    119, 103, 108, 67, 104, 111, 111, 115, 101, 80, 105, 120, 101, 108, 70, 111, 114, 109, 97, 116, 69, 88, 84, 0, /*wglChoosePixelFormatEXT*/
    119, 103, 108, 67, 111, 112, 121, 67, 111, 110, 116, 101, 120, 116, 0, /*wglCopyContext*/
    119, 103, 108, 67, 111, 112, 121, 73, 109, 97, 103, 101, 83, 117, 98, 68, 97, 116, 97, 78, 86, 0, /*wglCopyImageSubDataNV*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 65, 102, 102, 105, 110, 105, 116, 121, 68, 67, 78, 86, 0, /*wglCreateAffinityDCNV*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 65, 115, 115, 111, 99, 105, 97, 116, 101, 100, 67, 111, 110, 116, 101, 120, 116, 65, 77, 68, 0, /*wglCreateAssociatedContextAMD*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 65, 115, 115, 111, 99, 105, 97, 116, 101, 100, 67, 111, 110, 116, 101, 120, 116, 65, 116, 116, 114, 105, 98, 115, 65, 77, 68, 0, /*wglCreateAssociatedContextAttribsAMD*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 66, 117, 102, 102, 101, 114, 82, 101, 103, 105, 111, 110, 65, 82, 66, 0, /*wglCreateBufferRegionARB*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 67, 111, 110, 116, 101, 120, 116, 0, /*wglCreateContext*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 67, 111, 110, 116, 101, 120, 116, 65, 116, 116, 114, 105, 98, 115, 65, 82, 66, 0, /*wglCreateContextAttribsARB*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 68, 105, 115, 112, 108, 97, 121, 67, 111, 108, 111, 114, 84, 97, 98, 108, 101, 69, 88, 84, 0, /*wglCreateDisplayColorTableEXT*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 73, 109, 97, 103, 101, 66, 117, 102, 102, 101, 114, 73, 51, 68, 0, /*wglCreateImageBufferI3D*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 76, 97, 121, 101, 114, 67, 111, 110, 116, 101, 120, 116, 0, /*wglCreateLayerContext*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 80, 98, 117, 102, 102, 101, 114, 65, 82, 66, 0, /*wglCreatePbufferARB*/
    119, 103, 108, 67, 114, 101, 97, 116, 101, 80, 98, 117, 102, 102, 101, 114, 69, 88, 84, 0, /*wglCreatePbufferEXT*/
    119, 103, 108, 68, 88, 67, 108, 111, 115, 101, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglDXCloseDeviceNV*/
    119, 103, 108, 68, 88, 76, 111, 99, 107, 79, 98, 106, 101, 99, 116, 115, 78, 86, 0, /*wglDXLockObjectsNV*/
    119, 103, 108, 68, 88, 79, 98, 106, 101, 99, 116, 65, 99, 99, 101, 115, 115, 78, 86, 0, /*wglDXObjectAccessNV*/
    119, 103, 108, 68, 88, 79, 112, 101, 110, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglDXOpenDeviceNV*/
    119, 103, 108, 68, 88, 82, 101, 103, 105, 115, 116, 101, 114, 79, 98, 106, 101, 99, 116, 78, 86, 0, /*wglDXRegisterObjectNV*/
    119, 103, 108, 68, 88, 83, 101, 116, 82, 101, 115, 111, 117, 114, 99, 101, 83, 104, 97, 114, 101, 72, 97, 110, 100, 108, 101, 78, 86, 0, /*wglDXSetResourceShareHandleNV*/
    119, 103, 108, 68, 88, 85, 110, 108, 111, 99, 107, 79, 98, 106, 101, 99, 116, 115, 78, 86, 0, /*wglDXUnlockObjectsNV*/
    119, 103, 108, 68, 88, 85, 110, 114, 101, 103, 105, 115, 116, 101, 114, 79, 98, 106, 101, 99, 116, 78, 86, 0, /*wglDXUnregisterObjectNV*/
    119, 103, 108, 68, 101, 108, 97, 121, 66, 101, 102, 111, 114, 101, 83, 119, 97, 112, 78, 86, 0, /*wglDelayBeforeSwapNV*/
    119, 103, 108, 68, 101, 108, 101, 116, 101, 65, 115, 115, 111, 99, 105, 97, 116, 101, 100, 67, 111, 110, 116, 101, 120, 116, 65, 77, 68, 0, /*wglDeleteAssociatedContextAMD*/
    119, 103, 108, 68, 101, 108, 101, 116, 101, 66, 117, 102, 102, 101, 114, 82, 101, 103, 105, 111, 110, 65, 82, 66, 0, /*wglDeleteBufferRegionARB*/
    119, 103, 108, 68, 101, 108, 101, 116, 101, 67, 111, 110, 116, 101, 120, 116, 0, /*wglDeleteContext*/
    119, 103, 108, 68, 101, 108, 101, 116, 101, 68, 67, 78, 86, 0, /*wglDeleteDCNV*/
    119, 103, 108, 68, 101, 115, 99, 114, 105, 98, 101, 76, 97, 121, 101, 114, 80, 108, 97, 110, 101, 0, /*wglDescribeLayerPlane*/
    119, 103, 108, 68, 101, 115, 116, 114, 111, 121, 68, 105, 115, 112, 108, 97, 121, 67, 111, 108, 111, 114, 84, 97, 98, 108, 101, 69, 88, 84, 0, /*wglDestroyDisplayColorTableEXT*/
    119, 103, 108, 68, 101, 115, 116, 114, 111, 121, 73, 109, 97, 103, 101, 66, 117, 102, 102, 101, 114, 73, 51, 68, 0, /*wglDestroyImageBufferI3D*/
    119, 103, 108, 68, 101, 115, 116, 114, 111, 121, 80, 98, 117, 102, 102, 101, 114, 65, 82, 66, 0, /*wglDestroyPbufferARB*/
    119, 103, 108, 68, 101, 115, 116, 114, 111, 121, 80, 98, 117, 102, 102, 101, 114, 69, 88, 84, 0, /*wglDestroyPbufferEXT*/
    119, 103, 108, 68, 105, 115, 97, 98, 108, 101, 70, 114, 97, 109, 101, 76, 111, 99, 107, 73, 51, 68, 0, /*wglDisableFrameLockI3D*/
    119, 103, 108, 68, 105, 115, 97, 98, 108, 101, 71, 101, 110, 108, 111, 99, 107, 73, 51, 68, 0, /*wglDisableGenlockI3D*/
    119, 103, 108, 69, 110, 97, 98, 108, 101, 70, 114, 97, 109, 101, 76, 111, 99, 107, 73, 51, 68, 0, /*wglEnableFrameLockI3D*/
    119, 103, 108, 69, 110, 97, 98, 108, 101, 71, 101, 110, 108, 111, 99, 107, 73, 51, 68, 0, /*wglEnableGenlockI3D*/
    119, 103, 108, 69, 110, 100, 70, 114, 97, 109, 101, 84, 114, 97, 99, 107, 105, 110, 103, 73, 51, 68, 0, /*wglEndFrameTrackingI3D*/
    119, 103, 108, 69, 110, 117, 109, 71, 112, 117, 68, 101, 118, 105, 99, 101, 115, 78, 86, 0, /*wglEnumGpuDevicesNV*/
    119, 103, 108, 69, 110, 117, 109, 71, 112, 117, 115, 70, 114, 111, 109, 65, 102, 102, 105, 110, 105, 116, 121, 68, 67, 78, 86, 0, /*wglEnumGpusFromAffinityDCNV*/
    119, 103, 108, 69, 110, 117, 109, 71, 112, 117, 115, 78, 86, 0, /*wglEnumGpusNV*/
    119, 103, 108, 69, 110, 117, 109, 101, 114, 97, 116, 101, 86, 105, 100, 101, 111, 67, 97, 112, 116, 117, 114, 101, 68, 101, 118, 105, 99, 101, 115, 78, 86, 0, /*wglEnumerateVideoCaptureDevicesNV*/
    119, 103, 108, 69, 110, 117, 109, 101, 114, 97, 116, 101, 86, 105, 100, 101, 111, 68, 101, 118, 105, 99, 101, 115, 78, 86, 0, /*wglEnumerateVideoDevicesNV*/
    119, 103, 108, 70, 114, 101, 101, 77, 101, 109, 111, 114, 121, 78, 86, 0, /*wglFreeMemoryNV*/
    119, 103, 108, 71, 101, 110, 108, 111, 99, 107, 83, 97, 109, 112, 108, 101, 82, 97, 116, 101, 73, 51, 68, 0, /*wglGenlockSampleRateI3D*/
    119, 103, 108, 71, 101, 110, 108, 111, 99, 107, 83, 111, 117, 114, 99, 101, 68, 101, 108, 97, 121, 73, 51, 68, 0, /*wglGenlockSourceDelayI3D*/
    119, 103, 108, 71, 101, 110, 108, 111, 99, 107, 83, 111, 117, 114, 99, 101, 69, 100, 103, 101, 73, 51, 68, 0, /*wglGenlockSourceEdgeI3D*/
    119, 103, 108, 71, 101, 110, 108, 111, 99, 107, 83, 111, 117, 114, 99, 101, 73, 51, 68, 0, /*wglGenlockSourceI3D*/
    119, 103, 108, 71, 101, 116, 67, 111, 110, 116, 101, 120, 116, 71, 80, 85, 73, 68, 65, 77, 68, 0, /*wglGetContextGPUIDAMD*/
    119, 103, 108, 71, 101, 116, 67, 117, 114, 114, 101, 110, 116, 65, 115, 115, 111, 99, 105, 97, 116, 101, 100, 67, 111, 110, 116, 101, 120, 116, 65, 77, 68, 0, /*wglGetCurrentAssociatedContextAMD*/
    119, 103, 108, 71, 101, 116, 67, 117, 114, 114, 101, 110, 116, 67, 111, 110, 116, 101, 120, 116, 0, /*wglGetCurrentContext*/
    119, 103, 108, 71, 101, 116, 67, 117, 114, 114, 101, 110, 116, 68, 67, 0, /*wglGetCurrentDC*/
    119, 103, 108, 71, 101, 116, 67, 117, 114, 114, 101, 110, 116, 82, 101, 97, 100, 68, 67, 65, 82, 66, 0, /*wglGetCurrentReadDCARB*/
    119, 103, 108, 71, 101, 116, 67, 117, 114, 114, 101, 110, 116, 82, 101, 97, 100, 68, 67, 69, 88, 84, 0, /*wglGetCurrentReadDCEXT*/
    119, 103, 108, 71, 101, 116, 68, 101, 102, 97, 117, 108, 116, 80, 114, 111, 99, 65, 100, 100, 114, 101, 115, 115, 0, /*wglGetDefaultProcAddress*/
    119, 103, 108, 71, 101, 116, 68, 105, 103, 105, 116, 97, 108, 86, 105, 100, 101, 111, 80, 97, 114, 97, 109, 101, 116, 101, 114, 115, 73, 51, 68, 0, /*wglGetDigitalVideoParametersI3D*/
    119, 103, 108, 71, 101, 116, 69, 120, 116, 101, 110, 115, 105, 111, 110, 115, 83, 116, 114, 105, 110, 103, 65, 82, 66, 0, /*wglGetExtensionsStringARB*/
    119, 103, 108, 71, 101, 116, 69, 120, 116, 101, 110, 115, 105, 111, 110, 115, 83, 116, 114, 105, 110, 103, 69, 88, 84, 0, /*wglGetExtensionsStringEXT*/
    119, 103, 108, 71, 101, 116, 70, 114, 97, 109, 101, 85, 115, 97, 103, 101, 73, 51, 68, 0, /*wglGetFrameUsageI3D*/
    119, 103, 108, 71, 101, 116, 71, 80, 85, 73, 68, 115, 65, 77, 68, 0, /*wglGetGPUIDsAMD*/
    119, 103, 108, 71, 101, 116, 71, 80, 85, 73, 110, 102, 111, 65, 77, 68, 0, /*wglGetGPUInfoAMD*/
    119, 103, 108, 71, 101, 116, 71, 97, 109, 109, 97, 84, 97, 98, 108, 101, 73, 51, 68, 0, /*wglGetGammaTableI3D*/
    119, 103, 108, 71, 101, 116, 71, 97, 109, 109, 97, 84, 97, 98, 108, 101, 80, 97, 114, 97, 109, 101, 116, 101, 114, 115, 73, 51, 68, 0, /*wglGetGammaTableParametersI3D*/
    119, 103, 108, 71, 101, 116, 71, 101, 110, 108, 111, 99, 107, 83, 97, 109, 112, 108, 101, 82, 97, 116, 101, 73, 51, 68, 0, /*wglGetGenlockSampleRateI3D*/
    119, 103, 108, 71, 101, 116, 71, 101, 110, 108, 111, 99, 107, 83, 111, 117, 114, 99, 101, 68, 101, 108, 97, 121, 73, 51, 68, 0, /*wglGetGenlockSourceDelayI3D*/
    119, 103, 108, 71, 101, 116, 71, 101, 110, 108, 111, 99, 107, 83, 111, 117, 114, 99, 101, 69, 100, 103, 101, 73, 51, 68, 0, /*wglGetGenlockSourceEdgeI3D*/
    119, 103, 108, 71, 101, 116, 71, 101, 110, 108, 111, 99, 107, 83, 111, 117, 114, 99, 101, 73, 51, 68, 0, /*wglGetGenlockSourceI3D*/
    119, 103, 108, 71, 101, 116, 76, 97, 121, 101, 114, 80, 97, 108, 101, 116, 116, 101, 69, 110, 116, 114, 105, 101, 115, 0, /*wglGetLayerPaletteEntries*/
    119, 103, 108, 71, 101, 116, 77, 115, 99, 82, 97, 116, 101, 79, 77, 76, 0, /*wglGetMscRateOML*/
    119, 103, 108, 71, 101, 116, 80, 98, 117, 102, 102, 101, 114, 68, 67, 65, 82, 66, 0, /*wglGetPbufferDCARB*/
    119, 103, 108, 71, 101, 116, 80, 98, 117, 102, 102, 101, 114, 68, 67, 69, 88, 84, 0, /*wglGetPbufferDCEXT*/
    119, 103, 108, 71, 101, 116, 80, 105, 120, 101, 108, 70, 111, 114, 109, 97, 116, 65, 116, 116, 114, 105, 98, 102, 118, 65, 82, 66, 0, /*wglGetPixelFormatAttribfvARB*/
    119, 103, 108, 71, 101, 116, 80, 105, 120, 101, 108, 70, 111, 114, 109, 97, 116, 65, 116, 116, 114, 105, 98, 102, 118, 69, 88, 84, 0, /*wglGetPixelFormatAttribfvEXT*/
    119, 103, 108, 71, 101, 116, 80, 105, 120, 101, 108, 70, 111, 114, 109, 97, 116, 65, 116, 116, 114, 105, 98, 105, 118, 65, 82, 66, 0, /*wglGetPixelFormatAttribivARB*/
    119, 103, 108, 71, 101, 116, 80, 105, 120, 101, 108, 70, 111, 114, 109, 97, 116, 65, 116, 116, 114, 105, 98, 105, 118, 69, 88, 84, 0, /*wglGetPixelFormatAttribivEXT*/
    119, 103, 108, 71, 101, 116, 80, 114, 111, 99, 65, 100, 100, 114, 101, 115, 115, 0, /*wglGetProcAddress*/
    119, 103, 108, 71, 101, 116, 83, 119, 97, 112, 73, 110, 116, 101, 114, 118, 97, 108, 69, 88, 84, 0, /*wglGetSwapIntervalEXT*/
    119, 103, 108, 71, 101, 116, 83, 121, 110, 99, 86, 97, 108, 117, 101, 115, 79, 77, 76, 0, /*wglGetSyncValuesOML*/
    119, 103, 108, 71, 101, 116, 86, 105, 100, 101, 111, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglGetVideoDeviceNV*/
    119, 103, 108, 71, 101, 116, 86, 105, 100, 101, 111, 73, 110, 102, 111, 78, 86, 0, /*wglGetVideoInfoNV*/
    119, 103, 108, 73, 115, 69, 110, 97, 98, 108, 101, 100, 70, 114, 97, 109, 101, 76, 111, 99, 107, 73, 51, 68, 0, /*wglIsEnabledFrameLockI3D*/
    119, 103, 108, 73, 115, 69, 110, 97, 98, 108, 101, 100, 71, 101, 110, 108, 111, 99, 107, 73, 51, 68, 0, /*wglIsEnabledGenlockI3D*/
    119, 103, 108, 74, 111, 105, 110, 83, 119, 97, 112, 71, 114, 111, 117, 112, 78, 86, 0, /*wglJoinSwapGroupNV*/
    119, 103, 108, 76, 111, 97, 100, 68, 105, 115, 112, 108, 97, 121, 67, 111, 108, 111, 114, 84, 97, 98, 108, 101, 69, 88, 84, 0, /*wglLoadDisplayColorTableEXT*/
    119, 103, 108, 76, 111, 99, 107, 86, 105, 100, 101, 111, 67, 97, 112, 116, 117, 114, 101, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglLockVideoCaptureDeviceNV*/
    119, 103, 108, 77, 97, 107, 101, 65, 115, 115, 111, 99, 105, 97, 116, 101, 100, 67, 111, 110, 116, 101, 120, 116, 67, 117, 114, 114, 101, 110, 116, 65, 77, 68, 0, /*wglMakeAssociatedContextCurrentAMD*/
    119, 103, 108, 77, 97, 107, 101, 67, 111, 110, 116, 101, 120, 116, 67, 117, 114, 114, 101, 110, 116, 65, 82, 66, 0, /*wglMakeContextCurrentARB*/
    119, 103, 108, 77, 97, 107, 101, 67, 111, 110, 116, 101, 120, 116, 67, 117, 114, 114, 101, 110, 116, 69, 88, 84, 0, /*wglMakeContextCurrentEXT*/
    119, 103, 108, 77, 97, 107, 101, 67, 117, 114, 114, 101, 110, 116, 0, /*wglMakeCurrent*/
    119, 103, 108, 81, 117, 101, 114, 121, 67, 117, 114, 114, 101, 110, 116, 67, 111, 110, 116, 101, 120, 116, 78, 86, 0, /*wglQueryCurrentContextNV*/
    119, 103, 108, 81, 117, 101, 114, 121, 70, 114, 97, 109, 101, 67, 111, 117, 110, 116, 78, 86, 0, /*wglQueryFrameCountNV*/
    119, 103, 108, 81, 117, 101, 114, 121, 70, 114, 97, 109, 101, 76, 111, 99, 107, 77, 97, 115, 116, 101, 114, 73, 51, 68, 0, /*wglQueryFrameLockMasterI3D*/
    119, 103, 108, 81, 117, 101, 114, 121, 70, 114, 97, 109, 101, 84, 114, 97, 99, 107, 105, 110, 103, 73, 51, 68, 0, /*wglQueryFrameTrackingI3D*/
    119, 103, 108, 81, 117, 101, 114, 121, 71, 101, 110, 108, 111, 99, 107, 77, 97, 120, 83, 111, 117, 114, 99, 101, 68, 101, 108, 97, 121, 73, 51, 68, 0, /*wglQueryGenlockMaxSourceDelayI3D*/
    119, 103, 108, 81, 117, 101, 114, 121, 77, 97, 120, 83, 119, 97, 112, 71, 114, 111, 117, 112, 115, 78, 86, 0, /*wglQueryMaxSwapGroupsNV*/
    119, 103, 108, 81, 117, 101, 114, 121, 80, 98, 117, 102, 102, 101, 114, 65, 82, 66, 0, /*wglQueryPbufferARB*/
    119, 103, 108, 81, 117, 101, 114, 121, 80, 98, 117, 102, 102, 101, 114, 69, 88, 84, 0, /*wglQueryPbufferEXT*/
    119, 103, 108, 81, 117, 101, 114, 121, 83, 119, 97, 112, 71, 114, 111, 117, 112, 78, 86, 0, /*wglQuerySwapGroupNV*/
    119, 103, 108, 81, 117, 101, 114, 121, 86, 105, 100, 101, 111, 67, 97, 112, 116, 117, 114, 101, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglQueryVideoCaptureDeviceNV*/
    119, 103, 108, 82, 101, 97, 108, 105, 122, 101, 76, 97, 121, 101, 114, 80, 97, 108, 101, 116, 116, 101, 0, /*wglRealizeLayerPalette*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 73, 109, 97, 103, 101, 66, 117, 102, 102, 101, 114, 69, 118, 101, 110, 116, 115, 73, 51, 68, 0, /*wglReleaseImageBufferEventsI3D*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 80, 98, 117, 102, 102, 101, 114, 68, 67, 65, 82, 66, 0, /*wglReleasePbufferDCARB*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 80, 98, 117, 102, 102, 101, 114, 68, 67, 69, 88, 84, 0, /*wglReleasePbufferDCEXT*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 84, 101, 120, 73, 109, 97, 103, 101, 65, 82, 66, 0, /*wglReleaseTexImageARB*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 86, 105, 100, 101, 111, 67, 97, 112, 116, 117, 114, 101, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglReleaseVideoCaptureDeviceNV*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 86, 105, 100, 101, 111, 68, 101, 118, 105, 99, 101, 78, 86, 0, /*wglReleaseVideoDeviceNV*/
    119, 103, 108, 82, 101, 108, 101, 97, 115, 101, 86, 105, 100, 101, 111, 73, 109, 97, 103, 101, 78, 86, 0, /*wglReleaseVideoImageNV*/
    119, 103, 108, 82, 101, 115, 101, 116, 70, 114, 97, 109, 101, 67, 111, 117, 110, 116, 78, 86, 0, /*wglResetFrameCountNV*/
    119, 103, 108, 82, 101, 115, 116, 111, 114, 101, 66, 117, 102, 102, 101, 114, 82, 101, 103, 105, 111, 110, 65, 82, 66, 0, /*wglRestoreBufferRegionARB*/
    119, 103, 108, 83, 97, 118, 101, 66, 117, 102, 102, 101, 114, 82, 101, 103, 105, 111, 110, 65, 82, 66, 0, /*wglSaveBufferRegionARB*/
    119, 103, 108, 83, 101, 110, 100, 80, 98, 117, 102, 102, 101, 114, 84, 111, 86, 105, 100, 101, 111, 78, 86, 0, /*wglSendPbufferToVideoNV*/
    119, 103, 108, 83, 101, 116, 68, 105, 103, 105, 116, 97, 108, 86, 105, 100, 101, 111, 80, 97, 114, 97, 109, 101, 116, 101, 114, 115, 73, 51, 68, 0, /*wglSetDigitalVideoParametersI3D*/
    119, 103, 108, 83, 101, 116, 71, 97, 109, 109, 97, 84, 97, 98, 108, 101, 73, 51, 68, 0, /*wglSetGammaTableI3D*/
    119, 103, 108, 83, 101, 116, 71, 97, 109, 109, 97, 84, 97, 98, 108, 101, 80, 97, 114, 97, 109, 101, 116, 101, 114, 115, 73, 51, 68, 0, /*wglSetGammaTableParametersI3D*/
    119, 103, 108, 83, 101, 116, 76, 97, 121, 101, 114, 80, 97, 108, 101, 116, 116, 101, 69, 110, 116, 114, 105, 101, 115, 0, /*wglSetLayerPaletteEntries*/
    119, 103, 108, 83, 101, 116, 80, 98, 117, 102, 102, 101, 114, 65, 116, 116, 114, 105, 98, 65, 82, 66, 0, /*wglSetPbufferAttribARB*/
    119, 103, 108, 83, 101, 116, 83, 116, 101, 114, 101, 111, 69, 109, 105, 116, 116, 101, 114, 83, 116, 97, 116, 101, 51, 68, 76, 0, /*wglSetStereoEmitterState3DL*/
    119, 103, 108, 83, 104, 97, 114, 101, 76, 105, 115, 116, 115, 0, /*wglShareLists*/
    119, 103, 108, 83, 119, 97, 112, 66, 117, 102, 102, 101, 114, 115, 77, 115, 99, 79, 77, 76, 0, /*wglSwapBuffersMscOML*/
    119, 103, 108, 83, 119, 97, 112, 73, 110, 116, 101, 114, 118, 97, 108, 69, 88, 84, 0, /*wglSwapIntervalEXT*/
    119, 103, 108, 83, 119, 97, 112, 76, 97, 121, 101, 114, 66, 117, 102, 102, 101, 114, 115, 0, /*wglSwapLayerBuffers*/
    119, 103, 108, 83, 119, 97, 112, 76, 97, 121, 101, 114, 66, 117, 102, 102, 101, 114, 115, 77, 115, 99, 79, 77, 76, 0, /*wglSwapLayerBuffersMscOML*/
    119, 103, 108, 85, 115, 101, 70, 111, 110, 116, 66, 105, 116, 109, 97, 112, 115, 65, 0, /*wglUseFontBitmapsA*/
    119, 103, 108, 85, 115, 101, 70, 111, 110, 116, 66, 105, 116, 109, 97, 112, 115, 87, 0, /*wglUseFontBitmapsW*/
    119, 103, 108, 85, 115, 101, 70, 111, 110, 116, 79, 117, 116, 108, 105, 110, 101, 115, 0, /*wglUseFontOutlines*/
    119, 103, 108, 85, 115, 101, 70, 111, 110, 116, 79, 117, 116, 108, 105, 110, 101, 115, 65, 0, /*wglUseFontOutlinesA*/
    119, 103, 108, 85, 115, 101, 70, 111, 110, 116, 79, 117, 116, 108, 105, 110, 101, 115, 87, 0, /*wglUseFontOutlinesW*/
    119, 103, 108, 87, 97, 105, 116, 70, 111, 114, 77, 115, 99, 79, 77, 76, 0, /*wglWaitForMscOML*/
    119, 103, 108, 87, 97, 105, 116, 70, 111, 114, 83, 98, 99, 79, 77, 76, 0, /*wglWaitForSbcOML*/
};

static const struct dispatch_resolve_info wgl_dispatch_resolve_info_table[] = {
    {DISPATCH_RESOLVE_EXTENSION, 0, WGL_extension_WGL_NV_vertex_array_range, 0}, /* wglAllocateMemoryNV */
    {DISPATCH_RESOLVE_EXTENSION, 1, WGL_extension_WGL_I3D_image_buffer, 20}, /* wglAssociateImageBufferEventsI3D */
    {DISPATCH_RESOLVE_EXTENSION, 2, WGL_extension_WGL_I3D_swap_frame_usage, 53}, /* wglBeginFrameTrackingI3D */
    {DISPATCH_RESOLVE_EXTENSION, 3, WGL_extension_WGL_EXT_display_color_table, 78}, /* wglBindDisplayColorTableEXT */
    {DISPATCH_RESOLVE_EXTENSION, 4, WGL_extension_WGL_NV_swap_group, 106}, /* wglBindSwapBarrierNV */
    {DISPATCH_RESOLVE_EXTENSION, 5, WGL_extension_WGL_ARB_render_texture, 127}, /* wglBindTexImageARB */
    {DISPATCH_RESOLVE_EXTENSION, 6, WGL_extension_WGL_NV_video_capture, 146}, /* wglBindVideoCaptureDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 7, WGL_extension_WGL_NV_present_video, 174}, /* wglBindVideoDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 8, WGL_extension_WGL_NV_video_output, 195}, /* wglBindVideoImageNV */
    {DISPATCH_RESOLVE_EXTENSION, 9, WGL_extension_WGL_AMD_gpu_association, 215}, /* wglBlitContextFramebufferAMD */
    {DISPATCH_RESOLVE_EXTENSION, 10, WGL_extension_WGL_ARB_pixel_format, 244}, /* wglChoosePixelFormatARB */
    {DISPATCH_RESOLVE_EXTENSION, 11, WGL_extension_WGL_EXT_pixel_format, 268}, /* wglChoosePixelFormatEXT */
    {DISPATCH_RESOLVE_VERSION, 12, WGL_1_0, 292}, /* wglCopyContext */
    {DISPATCH_RESOLVE_EXTENSION, 13, WGL_extension_WGL_NV_copy_image, 307}, /* wglCopyImageSubDataNV */
    {DISPATCH_RESOLVE_EXTENSION, 14, WGL_extension_WGL_NV_gpu_affinity, 329}, /* wglCreateAffinityDCNV */
    {DISPATCH_RESOLVE_EXTENSION, 15, WGL_extension_WGL_AMD_gpu_association, 351}, /* wglCreateAssociatedContextAMD */
    {DISPATCH_RESOLVE_EXTENSION, 16, WGL_extension_WGL_AMD_gpu_association, 381}, /* wglCreateAssociatedContextAttribsAMD */
    {DISPATCH_RESOLVE_EXTENSION, 17, WGL_extension_WGL_ARB_buffer_region, 418}, /* wglCreateBufferRegionARB */
    {DISPATCH_RESOLVE_VERSION, 18, WGL_1_0, 443}, /* wglCreateContext */
    {DISPATCH_RESOLVE_EXTENSION, 19, WGL_extension_WGL_ARB_create_context, 460}, /* wglCreateContextAttribsARB */
    {DISPATCH_RESOLVE_EXTENSION, 20, WGL_extension_WGL_EXT_display_color_table, 487}, /* wglCreateDisplayColorTableEXT */
    {DISPATCH_RESOLVE_EXTENSION, 21, WGL_extension_WGL_I3D_image_buffer, 517}, /* wglCreateImageBufferI3D */
    {DISPATCH_RESOLVE_VERSION, 22, WGL_1_0, 541}, /* wglCreateLayerContext */
    {DISPATCH_RESOLVE_EXTENSION, 23, WGL_extension_WGL_ARB_pbuffer, 563}, /* wglCreatePbufferARB */
    {DISPATCH_RESOLVE_EXTENSION, 24, WGL_extension_WGL_EXT_pbuffer, 583}, /* wglCreatePbufferEXT */
    {DISPATCH_RESOLVE_EXTENSION, 25, WGL_extension_WGL_NV_DX_interop, 603}, /* wglDXCloseDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 26, WGL_extension_WGL_NV_DX_interop, 622}, /* wglDXLockObjectsNV */
    {DISPATCH_RESOLVE_EXTENSION, 27, WGL_extension_WGL_NV_DX_interop, 641}, /* wglDXObjectAccessNV */
    {DISPATCH_RESOLVE_EXTENSION, 28, WGL_extension_WGL_NV_DX_interop, 661}, /* wglDXOpenDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 29, WGL_extension_WGL_NV_DX_interop, 679}, /* wglDXRegisterObjectNV */
    {DISPATCH_RESOLVE_EXTENSION, 30, WGL_extension_WGL_NV_DX_interop, 701}, /* wglDXSetResourceShareHandleNV */
    {DISPATCH_RESOLVE_EXTENSION, 31, WGL_extension_WGL_NV_DX_interop, 731}, /* wglDXUnlockObjectsNV */
    {DISPATCH_RESOLVE_EXTENSION, 32, WGL_extension_WGL_NV_DX_interop, 752}, /* wglDXUnregisterObjectNV */
    {DISPATCH_RESOLVE_EXTENSION, 33, WGL_extension_WGL_NV_delay_before_swap, 776}, /* wglDelayBeforeSwapNV */
    {DISPATCH_RESOLVE_EXTENSION, 34, WGL_extension_WGL_AMD_gpu_association, 797}, /* wglDeleteAssociatedContextAMD */
    {DISPATCH_RESOLVE_EXTENSION, 35, WGL_extension_WGL_ARB_buffer_region, 827}, /* wglDeleteBufferRegionARB */
    {DISPATCH_RESOLVE_VERSION, 36, WGL_1_0, 852}, /* wglDeleteContext */
    {DISPATCH_RESOLVE_EXTENSION, 37, WGL_extension_WGL_NV_gpu_affinity, 869}, /* wglDeleteDCNV */
    {DISPATCH_RESOLVE_VERSION, 38, WGL_1_0, 883}, /* wglDescribeLayerPlane */
    {DISPATCH_RESOLVE_EXTENSION, 39, WGL_extension_WGL_EXT_display_color_table, 905}, /* wglDestroyDisplayColorTableEXT */
    {DISPATCH_RESOLVE_EXTENSION, 40, WGL_extension_WGL_I3D_image_buffer, 936}, /* wglDestroyImageBufferI3D */
    {DISPATCH_RESOLVE_EXTENSION, 41, WGL_extension_WGL_ARB_pbuffer, 961}, /* wglDestroyPbufferARB */
    {DISPATCH_RESOLVE_EXTENSION, 42, WGL_extension_WGL_EXT_pbuffer, 982}, /* wglDestroyPbufferEXT */
    {DISPATCH_RESOLVE_EXTENSION, 43, WGL_extension_WGL_I3D_swap_frame_lock, 1003}, /* wglDisableFrameLockI3D */
    {DISPATCH_RESOLVE_EXTENSION, 44, WGL_extension_WGL_I3D_genlock, 1026}, /* wglDisableGenlockI3D */
    {DISPATCH_RESOLVE_EXTENSION, 45, WGL_extension_WGL_I3D_swap_frame_lock, 1047}, /* wglEnableFrameLockI3D */
    {DISPATCH_RESOLVE_EXTENSION, 46, WGL_extension_WGL_I3D_genlock, 1069}, /* wglEnableGenlockI3D */
    {DISPATCH_RESOLVE_EXTENSION, 47, WGL_extension_WGL_I3D_swap_frame_usage, 1089}, /* wglEndFrameTrackingI3D */
    {DISPATCH_RESOLVE_EXTENSION, 48, WGL_extension_WGL_NV_gpu_affinity, 1112}, /* wglEnumGpuDevicesNV */
    {DISPATCH_RESOLVE_EXTENSION, 49, WGL_extension_WGL_NV_gpu_affinity, 1132}, /* wglEnumGpusFromAffinityDCNV */
    {DISPATCH_RESOLVE_EXTENSION, 50, WGL_extension_WGL_NV_gpu_affinity, 1160}, /* wglEnumGpusNV */
    {DISPATCH_RESOLVE_EXTENSION, 51, WGL_extension_WGL_NV_video_capture, 1174}, /* wglEnumerateVideoCaptureDevicesNV */
    {DISPATCH_RESOLVE_EXTENSION, 52, WGL_extension_WGL_NV_present_video, 1208}, /* wglEnumerateVideoDevicesNV */
    {DISPATCH_RESOLVE_EXTENSION, 53, WGL_extension_WGL_NV_vertex_array_range, 1235}, /* wglFreeMemoryNV */
    {DISPATCH_RESOLVE_EXTENSION, 54, WGL_extension_WGL_I3D_genlock, 1251}, /* wglGenlockSampleRateI3D */
    {DISPATCH_RESOLVE_EXTENSION, 55, WGL_extension_WGL_I3D_genlock, 1275}, /* wglGenlockSourceDelayI3D */
    {DISPATCH_RESOLVE_EXTENSION, 56, WGL_extension_WGL_I3D_genlock, 1300}, /* wglGenlockSourceEdgeI3D */
    {DISPATCH_RESOLVE_EXTENSION, 57, WGL_extension_WGL_I3D_genlock, 1324}, /* wglGenlockSourceI3D */
    {DISPATCH_RESOLVE_EXTENSION, 58, WGL_extension_WGL_AMD_gpu_association, 1344}, /* wglGetContextGPUIDAMD */
    {DISPATCH_RESOLVE_EXTENSION, 59, WGL_extension_WGL_AMD_gpu_association, 1366}, /* wglGetCurrentAssociatedContextAMD */
    {DISPATCH_RESOLVE_VERSION, 60, WGL_1_0, 1400}, /* wglGetCurrentContext */
    {DISPATCH_RESOLVE_VERSION, 61, WGL_1_0, 1421}, /* wglGetCurrentDC */
    {DISPATCH_RESOLVE_EXTENSION, 62, WGL_extension_WGL_ARB_make_current_read, 1437}, /* wglGetCurrentReadDCARB */
    {DISPATCH_RESOLVE_EXTENSION, 63, WGL_extension_WGL_EXT_make_current_read, 1460}, /* wglGetCurrentReadDCEXT */
    {DISPATCH_RESOLVE_EXTENSION, 65, WGL_extension_WGL_I3D_digital_video_control, 1508}, /* wglGetDigitalVideoParametersI3D */
    {DISPATCH_RESOLVE_EXTENSION, 66, WGL_extension_WGL_ARB_extensions_string, 1540}, /* wglGetExtensionsStringARB */
    {DISPATCH_RESOLVE_EXTENSION, 67, WGL_extension_WGL_EXT_extensions_string, 1566}, /* wglGetExtensionsStringEXT */
    {DISPATCH_RESOLVE_EXTENSION, 68, WGL_extension_WGL_I3D_swap_frame_usage, 1592}, /* wglGetFrameUsageI3D */
    {DISPATCH_RESOLVE_EXTENSION, 69, WGL_extension_WGL_AMD_gpu_association, 1612}, /* wglGetGPUIDsAMD */
    {DISPATCH_RESOLVE_EXTENSION, 70, WGL_extension_WGL_AMD_gpu_association, 1628}, /* wglGetGPUInfoAMD */
    {DISPATCH_RESOLVE_EXTENSION, 71, WGL_extension_WGL_I3D_gamma, 1645}, /* wglGetGammaTableI3D */
    {DISPATCH_RESOLVE_EXTENSION, 72, WGL_extension_WGL_I3D_gamma, 1665}, /* wglGetGammaTableParametersI3D */
    {DISPATCH_RESOLVE_EXTENSION, 73, WGL_extension_WGL_I3D_genlock, 1695}, /* wglGetGenlockSampleRateI3D */
    {DISPATCH_RESOLVE_EXTENSION, 74, WGL_extension_WGL_I3D_genlock, 1722}, /* wglGetGenlockSourceDelayI3D */
    {DISPATCH_RESOLVE_EXTENSION, 75, WGL_extension_WGL_I3D_genlock, 1750}, /* wglGetGenlockSourceEdgeI3D */
    {DISPATCH_RESOLVE_EXTENSION, 76, WGL_extension_WGL_I3D_genlock, 1777}, /* wglGetGenlockSourceI3D */
    {DISPATCH_RESOLVE_VERSION, 77, WGL_1_0, 1800}, /* wglGetLayerPaletteEntries */
    {DISPATCH_RESOLVE_EXTENSION, 78, WGL_extension_WGL_OML_sync_control, 1826}, /* wglGetMscRateOML */
    {DISPATCH_RESOLVE_EXTENSION, 79, WGL_extension_WGL_ARB_pbuffer, 1843}, /* wglGetPbufferDCARB */
    {DISPATCH_RESOLVE_EXTENSION, 80, WGL_extension_WGL_EXT_pbuffer, 1862}, /* wglGetPbufferDCEXT */
    {DISPATCH_RESOLVE_EXTENSION, 81, WGL_extension_WGL_ARB_pixel_format, 1881}, /* wglGetPixelFormatAttribfvARB */
    {DISPATCH_RESOLVE_EXTENSION, 82, WGL_extension_WGL_EXT_pixel_format, 1910}, /* wglGetPixelFormatAttribfvEXT */
    {DISPATCH_RESOLVE_EXTENSION, 83, WGL_extension_WGL_ARB_pixel_format, 1939}, /* wglGetPixelFormatAttribivARB */
    {DISPATCH_RESOLVE_EXTENSION, 84, WGL_extension_WGL_EXT_pixel_format, 1968}, /* wglGetPixelFormatAttribivEXT */
    {DISPATCH_RESOLVE_VERSION, 85, WGL_1_0, 1997}, /* wglGetProcAddress */
    {DISPATCH_RESOLVE_EXTENSION, 86, WGL_extension_WGL_EXT_swap_control, 2015}, /* wglGetSwapIntervalEXT */
    {DISPATCH_RESOLVE_EXTENSION, 87, WGL_extension_WGL_OML_sync_control, 2037}, /* wglGetSyncValuesOML */
    {DISPATCH_RESOLVE_EXTENSION, 88, WGL_extension_WGL_NV_video_output, 2057}, /* wglGetVideoDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 89, WGL_extension_WGL_NV_video_output, 2077}, /* wglGetVideoInfoNV */
    {DISPATCH_RESOLVE_EXTENSION, 90, WGL_extension_WGL_I3D_swap_frame_lock, 2095}, /* wglIsEnabledFrameLockI3D */
    {DISPATCH_RESOLVE_EXTENSION, 91, WGL_extension_WGL_I3D_genlock, 2120}, /* wglIsEnabledGenlockI3D */
    {DISPATCH_RESOLVE_EXTENSION, 92, WGL_extension_WGL_NV_swap_group, 2143}, /* wglJoinSwapGroupNV */
    {DISPATCH_RESOLVE_EXTENSION, 93, WGL_extension_WGL_EXT_display_color_table, 2162}, /* wglLoadDisplayColorTableEXT */
    {DISPATCH_RESOLVE_EXTENSION, 94, WGL_extension_WGL_NV_video_capture, 2190}, /* wglLockVideoCaptureDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 95, WGL_extension_WGL_AMD_gpu_association, 2218}, /* wglMakeAssociatedContextCurrentAMD */
    {DISPATCH_RESOLVE_EXTENSION, 96, WGL_extension_WGL_ARB_make_current_read, 2253}, /* wglMakeContextCurrentARB */
    {DISPATCH_RESOLVE_EXTENSION, 97, WGL_extension_WGL_EXT_make_current_read, 2278}, /* wglMakeContextCurrentEXT */
    {DISPATCH_RESOLVE_VERSION, 98, WGL_1_0, 2303}, /* wglMakeCurrent */
    {DISPATCH_RESOLVE_EXTENSION, 99, WGL_extension_WGL_NV_present_video, 2318}, /* wglQueryCurrentContextNV */
    {DISPATCH_RESOLVE_EXTENSION, 100, WGL_extension_WGL_NV_swap_group, 2343}, /* wglQueryFrameCountNV */
    {DISPATCH_RESOLVE_EXTENSION, 101, WGL_extension_WGL_I3D_swap_frame_lock, 2364}, /* wglQueryFrameLockMasterI3D */
    {DISPATCH_RESOLVE_EXTENSION, 102, WGL_extension_WGL_I3D_swap_frame_usage, 2391}, /* wglQueryFrameTrackingI3D */
    {DISPATCH_RESOLVE_EXTENSION, 103, WGL_extension_WGL_I3D_genlock, 2416}, /* wglQueryGenlockMaxSourceDelayI3D */
    {DISPATCH_RESOLVE_EXTENSION, 104, WGL_extension_WGL_NV_swap_group, 2449}, /* wglQueryMaxSwapGroupsNV */
    {DISPATCH_RESOLVE_EXTENSION, 105, WGL_extension_WGL_ARB_pbuffer, 2473}, /* wglQueryPbufferARB */
    {DISPATCH_RESOLVE_EXTENSION, 106, WGL_extension_WGL_EXT_pbuffer, 2492}, /* wglQueryPbufferEXT */
    {DISPATCH_RESOLVE_EXTENSION, 107, WGL_extension_WGL_NV_swap_group, 2511}, /* wglQuerySwapGroupNV */
    {DISPATCH_RESOLVE_EXTENSION, 108, WGL_extension_WGL_NV_video_capture, 2531}, /* wglQueryVideoCaptureDeviceNV */
    {DISPATCH_RESOLVE_VERSION, 109, WGL_1_0, 2560}, /* wglRealizeLayerPalette */
    {DISPATCH_RESOLVE_EXTENSION, 110, WGL_extension_WGL_I3D_image_buffer, 2583}, /* wglReleaseImageBufferEventsI3D */
    {DISPATCH_RESOLVE_EXTENSION, 111, WGL_extension_WGL_ARB_pbuffer, 2614}, /* wglReleasePbufferDCARB */
    {DISPATCH_RESOLVE_EXTENSION, 112, WGL_extension_WGL_EXT_pbuffer, 2637}, /* wglReleasePbufferDCEXT */
    {DISPATCH_RESOLVE_EXTENSION, 113, WGL_extension_WGL_ARB_render_texture, 2660}, /* wglReleaseTexImageARB */
    {DISPATCH_RESOLVE_EXTENSION, 114, WGL_extension_WGL_NV_video_capture, 2682}, /* wglReleaseVideoCaptureDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 115, WGL_extension_WGL_NV_video_output, 2713}, /* wglReleaseVideoDeviceNV */
    {DISPATCH_RESOLVE_EXTENSION, 116, WGL_extension_WGL_NV_video_output, 2737}, /* wglReleaseVideoImageNV */
    {DISPATCH_RESOLVE_EXTENSION, 117, WGL_extension_WGL_NV_swap_group, 2760}, /* wglResetFrameCountNV */
    {DISPATCH_RESOLVE_EXTENSION, 118, WGL_extension_WGL_ARB_buffer_region, 2781}, /* wglRestoreBufferRegionARB */
    {DISPATCH_RESOLVE_EXTENSION, 119, WGL_extension_WGL_ARB_buffer_region, 2807}, /* wglSaveBufferRegionARB */
    {DISPATCH_RESOLVE_EXTENSION, 120, WGL_extension_WGL_NV_video_output, 2830}, /* wglSendPbufferToVideoNV */
    {DISPATCH_RESOLVE_EXTENSION, 121, WGL_extension_WGL_I3D_digital_video_control, 2854}, /* wglSetDigitalVideoParametersI3D */
    {DISPATCH_RESOLVE_EXTENSION, 122, WGL_extension_WGL_I3D_gamma, 2886}, /* wglSetGammaTableI3D */
    {DISPATCH_RESOLVE_EXTENSION, 123, WGL_extension_WGL_I3D_gamma, 2906}, /* wglSetGammaTableParametersI3D */
    {DISPATCH_RESOLVE_VERSION, 124, WGL_1_0, 2936}, /* wglSetLayerPaletteEntries */
    {DISPATCH_RESOLVE_EXTENSION, 125, WGL_extension_WGL_ARB_render_texture, 2962}, /* wglSetPbufferAttribARB */
    {DISPATCH_RESOLVE_EXTENSION, 126, WGL_extension_WGL_3DL_stereo_control, 2985}, /* wglSetStereoEmitterState3DL */
    {DISPATCH_RESOLVE_VERSION, 127, WGL_1_0, 3013}, /* wglShareLists */
    {DISPATCH_RESOLVE_EXTENSION, 128, WGL_extension_WGL_OML_sync_control, 3027}, /* wglSwapBuffersMscOML */
    {DISPATCH_RESOLVE_EXTENSION, 129, WGL_extension_WGL_EXT_swap_control, 3048}, /* wglSwapIntervalEXT */
    {DISPATCH_RESOLVE_VERSION, 130, WGL_1_0, 3067}, /* wglSwapLayerBuffers */
    {DISPATCH_RESOLVE_EXTENSION, 131, WGL_extension_WGL_OML_sync_control, 3087}, /* wglSwapLayerBuffersMscOML */
    {DISPATCH_RESOLVE_VERSION, 132, WGL_1_0, 3113}, /* wglUseFontBitmapsA */
    {DISPATCH_RESOLVE_VERSION, 133, WGL_1_0, 3132}, /* wglUseFontBitmapsW */
    {DISPATCH_RESOLVE_VERSION, 134, WGL_1_0, 3151}, /* wglUseFontOutlines */
    {DISPATCH_RESOLVE_VERSION, 135, WGL_1_0, 3170}, /* wglUseFontOutlinesA */
    {DISPATCH_RESOLVE_VERSION, 136, WGL_1_0, 3190}, /* wglUseFontOutlinesW */
    {DISPATCH_RESOLVE_EXTENSION, 137, WGL_extension_WGL_OML_sync_control, 3210}, /* wglWaitForMscOML */
    {DISPATCH_RESOLVE_EXTENSION, 138, WGL_extension_WGL_OML_sync_control, 3227}, /* wglWaitForSbcOML */
    {DISPATCH_RESOLVE_TERMINATOR, 0, 0, 0}
};

static const khronos_uint16_t wgl_dispatch_resolve_offset[139] = {0};

GEN_THUNKS_RET(wgl, void *, wglAllocateMemoryNV, (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority), (size, readfreq, writefreq, priority), 0, PFNWGLALLOCATEMEMORYNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglAssociateImageBufferEventsI3D, (HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count), (hDC, pEvent, pAddress, pSize, count), 1, PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglBeginFrameTrackingI3D, (void), (), 2, PFNWGLBEGINFRAMETRACKINGI3DPROC)
GEN_THUNKS_RET(wgl, GLboolean, wglBindDisplayColorTableEXT, (GLushort id), (id), 3, PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglBindSwapBarrierNV, (GLuint group, GLuint barrier), (group, barrier), 4, PFNWGLBINDSWAPBARRIERNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglBindTexImageARB, (HPBUFFERARB hPbuffer, int iBuffer), (hPbuffer, iBuffer), 5, PFNWGLBINDTEXIMAGEARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglBindVideoCaptureDeviceNV, (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice), (uVideoSlot, hDevice), 6, PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglBindVideoDeviceNV, (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList), (hDC, uVideoSlot, hVideoDevice, piAttribList), 7, PFNWGLBINDVIDEODEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglBindVideoImageNV, (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer), (hVideoDevice, hPbuffer, iVideoBuffer), 8, PFNWGLBINDVIDEOIMAGENVPROC)
GEN_THUNKS(wgl, wglBlitContextFramebufferAMD, (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), (dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter), 9, PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)
GEN_THUNKS_RET(wgl, BOOL, wglChoosePixelFormatARB, (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats), (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats), 10, PFNWGLCHOOSEPIXELFORMATARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglChoosePixelFormatEXT, (HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats), (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats), 11, PFNWGLCHOOSEPIXELFORMATEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglCopyContext, (HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask), (hglrcSrc, hglrcDst, mask), 12, PFNWGLCOPYCONTEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglCopyImageSubDataNV, (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth), (hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth), 13, PFNWGLCOPYIMAGESUBDATANVPROC)
GEN_THUNKS_RET(wgl, HDC, wglCreateAffinityDCNV, (const HGPUNV * phGpuList), (phGpuList), 14, PFNWGLCREATEAFFINITYDCNVPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglCreateAssociatedContextAMD, (UINT id), (id), 15, PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglCreateAssociatedContextAttribsAMD, (UINT id, HGLRC hShareContext, const int * attribList), (id, hShareContext, attribList), 16, PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)
GEN_THUNKS_RET(wgl, HANDLE, wglCreateBufferRegionARB, (HDC hDC, int iLayerPlane, UINT uType), (hDC, iLayerPlane, uType), 17, PFNWGLCREATEBUFFERREGIONARBPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglCreateContext, (HDC hDc), (hDc), 18, PFNWGLCREATECONTEXTPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglCreateContextAttribsARB, (HDC hDC, HGLRC hShareContext, const int * attribList), (hDC, hShareContext, attribList), 19, PFNWGLCREATECONTEXTATTRIBSARBPROC)
GEN_THUNKS_RET(wgl, GLboolean, wglCreateDisplayColorTableEXT, (GLushort id), (id), 20, PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)
GEN_THUNKS_RET(wgl, LPVOID, wglCreateImageBufferI3D, (HDC hDC, DWORD dwSize, UINT uFlags), (hDC, dwSize, uFlags), 21, PFNWGLCREATEIMAGEBUFFERI3DPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglCreateLayerContext, (HDC hDc, int level), (hDc, level), 22, PFNWGLCREATELAYERCONTEXTPROC)
GEN_THUNKS_RET(wgl, HPBUFFERARB, wglCreatePbufferARB, (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList), (hDC, iPixelFormat, iWidth, iHeight, piAttribList), 23, PFNWGLCREATEPBUFFERARBPROC)
GEN_THUNKS_RET(wgl, HPBUFFEREXT, wglCreatePbufferEXT, (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList), (hDC, iPixelFormat, iWidth, iHeight, piAttribList), 24, PFNWGLCREATEPBUFFEREXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDXCloseDeviceNV, (HANDLE hDevice), (hDevice), 25, PFNWGLDXCLOSEDEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDXLockObjectsNV, (HANDLE hDevice, GLint count, HANDLE * hObjects), (hDevice, count, hObjects), 26, PFNWGLDXLOCKOBJECTSNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDXObjectAccessNV, (HANDLE hObject, GLenum access), (hObject, access), 27, PFNWGLDXOBJECTACCESSNVPROC)
GEN_THUNKS_RET(wgl, HANDLE, wglDXOpenDeviceNV, (void * dxDevice), (dxDevice), 28, PFNWGLDXOPENDEVICENVPROC)
GEN_THUNKS_RET(wgl, HANDLE, wglDXRegisterObjectNV, (HANDLE hDevice, void * dxObject, GLuint name, GLenum type, GLenum access), (hDevice, dxObject, name, type, access), 29, PFNWGLDXREGISTEROBJECTNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDXSetResourceShareHandleNV, (void * dxObject, HANDLE shareHandle), (dxObject, shareHandle), 30, PFNWGLDXSETRESOURCESHAREHANDLENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDXUnlockObjectsNV, (HANDLE hDevice, GLint count, HANDLE * hObjects), (hDevice, count, hObjects), 31, PFNWGLDXUNLOCKOBJECTSNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDXUnregisterObjectNV, (HANDLE hDevice, HANDLE hObject), (hDevice, hObject), 32, PFNWGLDXUNREGISTEROBJECTNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDelayBeforeSwapNV, (HDC hDC, GLfloat seconds), (hDC, seconds), 33, PFNWGLDELAYBEFORESWAPNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDeleteAssociatedContextAMD, (HGLRC hglrc), (hglrc), 34, PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)
GEN_THUNKS(wgl, wglDeleteBufferRegionARB, (HANDLE hRegion), (hRegion), 35, PFNWGLDELETEBUFFERREGIONARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDeleteContext, (HGLRC oldContext), (oldContext), 36, PFNWGLDELETECONTEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDeleteDCNV, (HDC hdc), (hdc), 37, PFNWGLDELETEDCNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDescribeLayerPlane, (HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd), (hDc, pixelFormat, layerPlane, nBytes, plpd), 38, PFNWGLDESCRIBELAYERPLANEPROC)
GEN_THUNKS(wgl, wglDestroyDisplayColorTableEXT, (GLushort id), (id), 39, PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDestroyImageBufferI3D, (HDC hDC, LPVOID pAddress), (hDC, pAddress), 40, PFNWGLDESTROYIMAGEBUFFERI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDestroyPbufferARB, (HPBUFFERARB hPbuffer), (hPbuffer), 41, PFNWGLDESTROYPBUFFERARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDestroyPbufferEXT, (HPBUFFEREXT hPbuffer), (hPbuffer), 42, PFNWGLDESTROYPBUFFEREXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDisableFrameLockI3D, (void), (), 43, PFNWGLDISABLEFRAMELOCKI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglDisableGenlockI3D, (HDC hDC), (hDC), 44, PFNWGLDISABLEGENLOCKI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglEnableFrameLockI3D, (void), (), 45, PFNWGLENABLEFRAMELOCKI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglEnableGenlockI3D, (HDC hDC), (hDC), 46, PFNWGLENABLEGENLOCKI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglEndFrameTrackingI3D, (void), (), 47, PFNWGLENDFRAMETRACKINGI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglEnumGpuDevicesNV, (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice), (hGpu, iDeviceIndex, lpGpuDevice), 48, PFNWGLENUMGPUDEVICESNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglEnumGpusFromAffinityDCNV, (HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu), (hAffinityDC, iGpuIndex, hGpu), 49, PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglEnumGpusNV, (UINT iGpuIndex, HGPUNV * phGpu), (iGpuIndex, phGpu), 50, PFNWGLENUMGPUSNVPROC)
GEN_THUNKS_RET(wgl, UINT, wglEnumerateVideoCaptureDevicesNV, (HDC hDc, HVIDEOINPUTDEVICENV * phDeviceList), (hDc, phDeviceList), 51, PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)
GEN_THUNKS_RET(wgl, int, wglEnumerateVideoDevicesNV, (HDC hDC, HVIDEOOUTPUTDEVICENV * phDeviceList), (hDC, phDeviceList), 52, PFNWGLENUMERATEVIDEODEVICESNVPROC)
GEN_THUNKS(wgl, wglFreeMemoryNV, (void * pointer), (pointer), 53, PFNWGLFREEMEMORYNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSampleRateI3D, (HDC hDC, UINT uRate), (hDC, uRate), 54, PFNWGLGENLOCKSAMPLERATEI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSourceDelayI3D, (HDC hDC, UINT uDelay), (hDC, uDelay), 55, PFNWGLGENLOCKSOURCEDELAYI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSourceEdgeI3D, (HDC hDC, UINT uEdge), (hDC, uEdge), 56, PFNWGLGENLOCKSOURCEEDGEI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGenlockSourceI3D, (HDC hDC, UINT uSource), (hDC, uSource), 57, PFNWGLGENLOCKSOURCEI3DPROC)
GEN_THUNKS_RET(wgl, UINT, wglGetContextGPUIDAMD, (HGLRC hglrc), (hglrc), 58, PFNWGLGETCONTEXTGPUIDAMDPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglGetCurrentAssociatedContextAMD, (void), (), 59, PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)
GEN_THUNKS_RET(wgl, HGLRC, wglGetCurrentContext, (void), (), 60, PFNWGLGETCURRENTCONTEXTPROC)
GEN_THUNKS_RET(wgl, HDC, wglGetCurrentDC, (void), (), 61, PFNWGLGETCURRENTDCPROC)
GEN_THUNKS_RET(wgl, HDC, wglGetCurrentReadDCARB, (void), (), 62, PFNWGLGETCURRENTREADDCARBPROC)
GEN_THUNKS_RET(wgl, HDC, wglGetCurrentReadDCEXT, (void), (), 63, PFNWGLGETCURRENTREADDCEXTPROC)
GEN_THUNKS_RET(wgl, PROC, wglGetDefaultProcAddress, (LPCSTR lpszProc), (lpszProc), 64, PFNWGLGETDEFAULTPROCADDRESSPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetDigitalVideoParametersI3D, (HDC hDC, int iAttribute, int * piValue), (hDC, iAttribute, piValue), 65, PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)
GEN_THUNKS_RET(wgl, const char *, wglGetExtensionsStringARB, (HDC hdc), (hdc), 66, PFNWGLGETEXTENSIONSSTRINGARBPROC)
GEN_THUNKS_RET(wgl, const char *, wglGetExtensionsStringEXT, (void), (), 67, PFNWGLGETEXTENSIONSSTRINGEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetFrameUsageI3D, (float * pUsage), (pUsage), 68, PFNWGLGETFRAMEUSAGEI3DPROC)
GEN_THUNKS_RET(wgl, UINT, wglGetGPUIDsAMD, (UINT maxCount, UINT * ids), (maxCount, ids), 69, PFNWGLGETGPUIDSAMDPROC)
GEN_THUNKS_RET(wgl, INT, wglGetGPUInfoAMD, (UINT id, int property, GLenum dataType, UINT size, void * data), (id, property, dataType, size, data), 70, PFNWGLGETGPUINFOAMDPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetGammaTableI3D, (HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue), (hDC, iEntries, puRed, puGreen, puBlue), 71, PFNWGLGETGAMMATABLEI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetGammaTableParametersI3D, (HDC hDC, int iAttribute, int * piValue), (hDC, iAttribute, piValue), 72, PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSampleRateI3D, (HDC hDC, UINT * uRate), (hDC, uRate), 73, PFNWGLGETGENLOCKSAMPLERATEI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSourceDelayI3D, (HDC hDC, UINT * uDelay), (hDC, uDelay), 74, PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSourceEdgeI3D, (HDC hDC, UINT * uEdge), (hDC, uEdge), 75, PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetGenlockSourceI3D, (HDC hDC, UINT * uSource), (hDC, uSource), 76, PFNWGLGETGENLOCKSOURCEI3DPROC)
GEN_THUNKS_RET(wgl, int, wglGetLayerPaletteEntries, (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr), (hdc, iLayerPlane, iStart, cEntries, pcr), 77, PFNWGLGETLAYERPALETTEENTRIESPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetMscRateOML, (HDC hdc, INT32 * numerator, INT32 * denominator), (hdc, numerator, denominator), 78, PFNWGLGETMSCRATEOMLPROC)
GEN_THUNKS_RET(wgl, HDC, wglGetPbufferDCARB, (HPBUFFERARB hPbuffer), (hPbuffer), 79, PFNWGLGETPBUFFERDCARBPROC)
GEN_THUNKS_RET(wgl, HDC, wglGetPbufferDCEXT, (HPBUFFEREXT hPbuffer), (hPbuffer), 80, PFNWGLGETPBUFFERDCEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribfvARB, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues), 81, PFNWGLGETPIXELFORMATATTRIBFVARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribfvEXT, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues), 82, PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribivARB, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues), 83, PFNWGLGETPIXELFORMATATTRIBIVARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetPixelFormatAttribivEXT, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues), 84, PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)
GEN_THUNKS_RET(wgl, PROC, wglGetProcAddress, (LPCSTR lpszProc), (lpszProc), 85, PFNWGLGETPROCADDRESSPROC)
GEN_THUNKS_RET(wgl, int, wglGetSwapIntervalEXT, (void), (), 86, PFNWGLGETSWAPINTERVALEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetSyncValuesOML, (HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc), (hdc, ust, msc, sbc), 87, PFNWGLGETSYNCVALUESOMLPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetVideoDeviceNV, (HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice), (hDC, numDevices, hVideoDevice), 88, PFNWGLGETVIDEODEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglGetVideoInfoNV, (HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo), (hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo), 89, PFNWGLGETVIDEOINFONVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglIsEnabledFrameLockI3D, (BOOL * pFlag), (pFlag), 90, PFNWGLISENABLEDFRAMELOCKI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglIsEnabledGenlockI3D, (HDC hDC, BOOL * pFlag), (hDC, pFlag), 91, PFNWGLISENABLEDGENLOCKI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglJoinSwapGroupNV, (HDC hDC, GLuint group), (hDC, group), 92, PFNWGLJOINSWAPGROUPNVPROC)
GEN_THUNKS_RET(wgl, GLboolean, wglLoadDisplayColorTableEXT, (const GLushort * table, GLuint length), (table, length), 93, PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglLockVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice), (hDc, hDevice), 94, PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglMakeAssociatedContextCurrentAMD, (HGLRC hglrc), (hglrc), 95, PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)
GEN_THUNKS_RET(wgl, BOOL, wglMakeContextCurrentARB, (HDC hDrawDC, HDC hReadDC, HGLRC hglrc), (hDrawDC, hReadDC, hglrc), 96, PFNWGLMAKECONTEXTCURRENTARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglMakeContextCurrentEXT, (HDC hDrawDC, HDC hReadDC, HGLRC hglrc), (hDrawDC, hReadDC, hglrc), 97, PFNWGLMAKECONTEXTCURRENTEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglMakeCurrent, (HDC hDc, HGLRC newContext), (hDc, newContext), 98, PFNWGLMAKECURRENTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryCurrentContextNV, (int iAttribute, int * piValue), (iAttribute, piValue), 99, PFNWGLQUERYCURRENTCONTEXTNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryFrameCountNV, (HDC hDC, GLuint * count), (hDC, count), 100, PFNWGLQUERYFRAMECOUNTNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryFrameLockMasterI3D, (BOOL * pFlag), (pFlag), 101, PFNWGLQUERYFRAMELOCKMASTERI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryFrameTrackingI3D, (DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage), (pFrameCount, pMissedFrames, pLastMissedUsage), 102, PFNWGLQUERYFRAMETRACKINGI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryGenlockMaxSourceDelayI3D, (HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay), (hDC, uMaxLineDelay, uMaxPixelDelay), 103, PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryMaxSwapGroupsNV, (HDC hDC, GLuint * maxGroups, GLuint * maxBarriers), (hDC, maxGroups, maxBarriers), 104, PFNWGLQUERYMAXSWAPGROUPSNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryPbufferARB, (HPBUFFERARB hPbuffer, int iAttribute, int * piValue), (hPbuffer, iAttribute, piValue), 105, PFNWGLQUERYPBUFFERARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryPbufferEXT, (HPBUFFEREXT hPbuffer, int iAttribute, int * piValue), (hPbuffer, iAttribute, piValue), 106, PFNWGLQUERYPBUFFEREXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQuerySwapGroupNV, (HDC hDC, GLuint * group, GLuint * barrier), (hDC, group, barrier), 107, PFNWGLQUERYSWAPGROUPNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglQueryVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int * piValue), (hDc, hDevice, iAttribute, piValue), 108, PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglRealizeLayerPalette, (HDC hdc, int iLayerPlane, BOOL bRealize), (hdc, iLayerPlane, bRealize), 109, PFNWGLREALIZELAYERPALETTEPROC)
GEN_THUNKS_RET(wgl, BOOL, wglReleaseImageBufferEventsI3D, (HDC hDC, const LPVOID * pAddress, UINT count), (hDC, pAddress, count), 110, PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)
GEN_THUNKS_RET(wgl, int, wglReleasePbufferDCARB, (HPBUFFERARB hPbuffer, HDC hDC), (hPbuffer, hDC), 111, PFNWGLRELEASEPBUFFERDCARBPROC)
GEN_THUNKS_RET(wgl, int, wglReleasePbufferDCEXT, (HPBUFFEREXT hPbuffer, HDC hDC), (hPbuffer, hDC), 112, PFNWGLRELEASEPBUFFERDCEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglReleaseTexImageARB, (HPBUFFERARB hPbuffer, int iBuffer), (hPbuffer, iBuffer), 113, PFNWGLRELEASETEXIMAGEARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglReleaseVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice), (hDc, hDevice), 114, PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglReleaseVideoDeviceNV, (HPVIDEODEV hVideoDevice), (hVideoDevice), 115, PFNWGLRELEASEVIDEODEVICENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglReleaseVideoImageNV, (HPBUFFERARB hPbuffer, int iVideoBuffer), (hPbuffer, iVideoBuffer), 116, PFNWGLRELEASEVIDEOIMAGENVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglResetFrameCountNV, (HDC hDC), (hDC), 117, PFNWGLRESETFRAMECOUNTNVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglRestoreBufferRegionARB, (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc), (hRegion, x, y, width, height, xSrc, ySrc), 118, PFNWGLRESTOREBUFFERREGIONARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSaveBufferRegionARB, (HANDLE hRegion, int x, int y, int width, int height), (hRegion, x, y, width, height), 119, PFNWGLSAVEBUFFERREGIONARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSendPbufferToVideoNV, (HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock), (hPbuffer, iBufferType, pulCounterPbuffer, bBlock), 120, PFNWGLSENDPBUFFERTOVIDEONVPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSetDigitalVideoParametersI3D, (HDC hDC, int iAttribute, const int * piValue), (hDC, iAttribute, piValue), 121, PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSetGammaTableI3D, (HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue), (hDC, iEntries, puRed, puGreen, puBlue), 122, PFNWGLSETGAMMATABLEI3DPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSetGammaTableParametersI3D, (HDC hDC, int iAttribute, const int * piValue), (hDC, iAttribute, piValue), 123, PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)
GEN_THUNKS_RET(wgl, int, wglSetLayerPaletteEntries, (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr), (hdc, iLayerPlane, iStart, cEntries, pcr), 124, PFNWGLSETLAYERPALETTEENTRIESPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSetPbufferAttribARB, (HPBUFFERARB hPbuffer, const int * piAttribList), (hPbuffer, piAttribList), 125, PFNWGLSETPBUFFERATTRIBARBPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSetStereoEmitterState3DL, (HDC hDC, UINT uState), (hDC, uState), 126, PFNWGLSETSTEREOEMITTERSTATE3DLPROC)
GEN_THUNKS_RET(wgl, BOOL, wglShareLists, (HGLRC hrcSrvShare, HGLRC hrcSrvSource), (hrcSrvShare, hrcSrvSource), 127, PFNWGLSHARELISTSPROC)
GEN_THUNKS_RET(wgl, INT64, wglSwapBuffersMscOML, (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder), (hdc, target_msc, divisor, remainder), 128, PFNWGLSWAPBUFFERSMSCOMLPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSwapIntervalEXT, (int interval), (interval), 129, PFNWGLSWAPINTERVALEXTPROC)
GEN_THUNKS_RET(wgl, BOOL, wglSwapLayerBuffers, (HDC hdc, UINT fuFlags), (hdc, fuFlags), 130, PFNWGLSWAPLAYERBUFFERSPROC)
GEN_THUNKS_RET(wgl, INT64, wglSwapLayerBuffersMscOML, (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder), (hdc, fuPlanes, target_msc, divisor, remainder), 131, PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)
GEN_THUNKS_RET(wgl, BOOL, wglUseFontBitmapsA, (HDC hDC, DWORD first, DWORD count, DWORD listBase), (hDC, first, count, listBase), 132, PFNWGLUSEFONTBITMAPSAPROC)
GEN_THUNKS_RET(wgl, BOOL, wglUseFontBitmapsW, (HDC hDC, DWORD first, DWORD count, DWORD listBase), (hDC, first, count, listBase), 133, PFNWGLUSEFONTBITMAPSWPROC)
GEN_THUNKS_RET(wgl, BOOL, wglUseFontOutlines, (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf), (hDC, first, count, listBase, deviation, extrusion, format, lpgmf), 134, PFNWGLUSEFONTOUTLINESPROC)
GEN_THUNKS_RET(wgl, BOOL, wglUseFontOutlinesA, (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf), (hDC, first, count, listBase, deviation, extrusion, format, lpgmf), 135, PFNWGLUSEFONTOUTLINESAPROC)
GEN_THUNKS_RET(wgl, BOOL, wglUseFontOutlinesW, (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf), (hDC, first, count, listBase, deviation, extrusion, format, lpgmf), 136, PFNWGLUSEFONTOUTLINESWPROC)
GEN_THUNKS_RET(wgl, BOOL, wglWaitForMscOML, (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc), (hdc, target_msc, divisor, remainder, ust, msc, sbc), 137, PFNWGLWAITFORMSCOMLPROC)
GEN_THUNKS_RET(wgl, BOOL, wglWaitForSbcOML, (HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc), (hdc, target_sbc, ust, msc, sbc), 138, PFNWGLWAITFORSBCOMLPROC)

#endif /* PLATFORM_HAS_WGL */
