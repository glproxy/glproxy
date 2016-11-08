/* GL dispatch header.
 * This is code-generated from the GL API XML files from Khronos.
 */

#pragma once
#include <inttypes.h>
#include <stddef.h>

typedef XID GLXFBConfigID;
typedef struct __GLXFBConfigRec *GLXFBConfig;
typedef XID GLXContextID;
typedef struct __GLXcontextRec *GLXContext;
typedef XID GLXPixmap;
typedef XID GLXDrawable;
typedef XID GLXWindow;
typedef XID GLXPbuffer;
typedef void (APIENTRY *__GLXextFuncPtr)(void);
typedef XID GLXVideoCaptureDeviceNV;
typedef unsigned int GLXVideoDeviceNV;
typedef XID GLXVideoSourceSGIX;
typedef XID GLXFBConfigIDSGIX;
typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;
typedef XID GLXPbufferSGIX;
typedef struct {
    int event_type;             /* GLX_DAMAGED or GLX_SAVED */
    int draw_type;              /* GLX_WINDOW or GLX_PBUFFER */
    unsigned long serial;       /* # of last request processed by server */
    Bool send_event;            /* true if this came for SendEvent request */
    Display *display;           /* display the event was read from */
    GLXDrawable drawable;       /* XID of Drawable */
    unsigned int buffer_mask;   /* mask indicating which buffers are affected */
    unsigned int aux_buffer;    /* which aux buffer was affected */
    int x, y;
    int width, height;
    int count;                  /* if nonzero, at least this many more */
} GLXPbufferClobberEvent;
typedef struct {
    int type;
    unsigned long serial;       /* # of last request processed by server */
    Bool send_event;            /* true if this came from a SendEvent request */
    Display *display;           /* Display the event was read from */
    GLXDrawable drawable;       /* drawable on which event was requested in event mask */
    int event_type;
    int64_t ust;
    int64_t msc;
    int64_t sbc;
} GLXBufferSwapComplete;
typedef union __GLXEvent {
    GLXPbufferClobberEvent glxpbufferclobber;
    GLXBufferSwapComplete glxbufferswapcomplete;
    long pad[24];
} GLXEvent;
typedef struct {
    int type;
    unsigned long serial;
    Bool send_event;
    Display *display;
    int extension;
    int evtype;
    GLXDrawable window;
    Bool stereo_tree;
} GLXStereoNotifyEventEXT;
typedef struct {
    int type;
    unsigned long serial;   /* # of last request processed by server */
    Bool send_event;        /* true if this came for SendEvent request */
    Display *display;       /* display the event was read from */
    GLXDrawable drawable;   /* i.d. of Drawable */
    int event_type;         /* GLX_DAMAGED_SGIX or GLX_SAVED_SGIX */
    int draw_type;          /* GLX_WINDOW_SGIX or GLX_PBUFFER_SGIX */
    unsigned int mask;      /* mask indicating which buffers are affected*/
    int x, y;
    int width, height;
    int count;              /* if nonzero, at least this many more */
} GLXBufferClobberEventSGIX;
typedef struct {
    char    pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int     networkId;
} GLXHyperpipeNetworkSGIX;
typedef struct {
    char    pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int     channel;
    unsigned int participationType;
    int     timeSlice;
} GLXHyperpipeConfigSGIX;
typedef struct {
    char pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int srcXOrigin, srcYOrigin, srcWidth, srcHeight;
    int destXOrigin, destYOrigin, destWidth, destHeight;
} GLXPipeRect;
typedef struct {
    char pipeName[80]; /* Should be [GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX] */
    int XOrigin, YOrigin, maxHeight, maxWidth;
} GLXPipeRectLimits;

#define GLX_VERSION_1_0 1
#define GLX_VERSION_1_1 1
#define GLX_VERSION_1_2 1
#define GLX_VERSION_1_3 1
#define GLX_VERSION_1_4 1

#define GLX_3DFX_multisample 1
#define GLX_AMD_gpu_association 1
#define GLX_ARB_context_flush_control 1
#define GLX_ARB_create_context 1
#define GLX_ARB_create_context_profile 1
#define GLX_ARB_create_context_robustness 1
#define GLX_ARB_fbconfig_float 1
#define GLX_ARB_framebuffer_sRGB 1
#define GLX_ARB_get_proc_address 1
#define GLX_ARB_multisample 1
#define GLX_ARB_robustness_application_isolation 1
#define GLX_ARB_robustness_share_group_isolation 1
#define GLX_ARB_vertex_buffer_object 1
#define GLX_EXT_buffer_age 1
#define GLX_EXT_create_context_es2_profile 1
#define GLX_EXT_create_context_es_profile 1
#define GLX_EXT_fbconfig_packed_float 1
#define GLX_EXT_framebuffer_sRGB 1
#define GLX_EXT_import_context 1
#define GLX_EXT_libglvnd 1
#define GLX_EXT_stereo_tree 1
#define GLX_EXT_swap_control 1
#define GLX_EXT_swap_control_tear 1
#define GLX_EXT_texture_from_pixmap 1
#define GLX_EXT_visual_info 1
#define GLX_EXT_visual_rating 1
#define GLX_INTEL_swap_event 1
#define GLX_MESA_agp_offset 1
#define GLX_MESA_copy_sub_buffer 1
#define GLX_MESA_pixmap_colormap 1
#define GLX_MESA_query_renderer 1
#define GLX_MESA_release_buffers 1
#define GLX_MESA_set_3dfx_mode 1
#define GLX_NV_copy_buffer 1
#define GLX_NV_copy_image 1
#define GLX_NV_delay_before_swap 1
#define GLX_NV_float_buffer 1
#define GLX_NV_multisample_coverage 1
#define GLX_NV_present_video 1
#define GLX_NV_robustness_video_memory_purge 1
#define GLX_NV_swap_group 1
#define GLX_NV_video_capture 1
#define GLX_NV_video_out 1
#define GLX_OML_swap_method 1
#define GLX_OML_sync_control 1
#define GLX_SGIS_blended_overlay 1
#define GLX_SGIS_multisample 1
#define GLX_SGIS_shared_multisample 1
#define GLX_SGIX_dmbuffer 1
#define GLX_SGIX_fbconfig 1
#define GLX_SGIX_hyperpipe 1
#define GLX_SGIX_pbuffer 1
#define GLX_SGIX_swap_barrier 1
#define GLX_SGIX_swap_group 1
#define GLX_SGIX_video_resize 1
#define GLX_SGIX_video_source 1
#define GLX_SGIX_visual_select_group 1
#define GLX_SGI_cushion 1
#define GLX_SGI_make_current_read 1
#define GLX_SGI_swap_control 1
#define GLX_SGI_video_sync 1
#define GLX_SUN_get_transparent_index 1

#define GLX_EXTENSION_NAME                                       "GLX"
#define GLX_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB                    0
#define GLX_PbufferClobber                                       0
#define GLX_STEREO_NOTIFY_EXT                                    0x00000000
#define GLX_SYNC_FRAME_SGIX                                      0x00000000
#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB                         0x00000001
#define GLX_CONTEXT_DEBUG_BIT_ARB                                0x00000001
#define GLX_FRONT_LEFT_BUFFER_BIT                                0x00000001
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX                           0x00000001
#define GLX_HYPERPIPE_DISPLAY_PIPE_SGIX                          0x00000001
#define GLX_PIPE_RECT_SGIX                                       0x00000001
#define GLX_RGBA_BIT                                             0x00000001
#define GLX_RGBA_BIT_SGIX                                        0x00000001
#define GLX_STEREO_NOTIFY_MASK_EXT                               0x00000001
#define GLX_SYNC_SWAP_SGIX                                       0x00000001
#define GLX_TEXTURE_1D_BIT_EXT                                   0x00000001
#define GLX_WINDOW_BIT                                           0x00000001
#define GLX_WINDOW_BIT_SGIX                                      0x00000001
#define GLX_COLOR_INDEX_BIT                                      0x00000002
#define GLX_COLOR_INDEX_BIT_SGIX                                 0x00000002
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB                0x00000002
#define GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB                   0x00000002
#define GLX_FRONT_RIGHT_BUFFER_BIT                               0x00000002
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX                          0x00000002
#define GLX_HYPERPIPE_RENDER_PIPE_SGIX                           0x00000002
#define GLX_PIPE_RECT_LIMITS_SGIX                                0x00000002
#define GLX_PIXMAP_BIT                                           0x00000002
#define GLX_PIXMAP_BIT_SGIX                                      0x00000002
#define GLX_TEXTURE_2D_BIT_EXT                                   0x00000002
#define GLX_HYPERPIPE_STEREO_SGIX                                0x00000003
#define GLX_BACK_LEFT_BUFFER_BIT                                 0x00000004
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX                            0x00000004
#define GLX_CONTEXT_ES2_PROFILE_BIT_EXT                          0x00000004
#define GLX_CONTEXT_ES_PROFILE_BIT_EXT                           0x00000004
#define GLX_CONTEXT_ROBUST_ACCESS_BIT_ARB                        0x00000004
#define GLX_HYPERPIPE_PIXEL_AVERAGE_SGIX                         0x00000004
#define GLX_PBUFFER_BIT                                          0x00000004
#define GLX_PBUFFER_BIT_SGIX                                     0x00000004
#define GLX_RGBA_FLOAT_BIT_ARB                                   0x00000004
#define GLX_TEXTURE_RECTANGLE_BIT_EXT                            0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT                                0x00000008
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX                           0x00000008
#define GLX_CONTEXT_RESET_ISOLATION_BIT_ARB                      0x00000008
#define GLX_RGBA_UNSIGNED_FLOAT_BIT_EXT                          0x00000008
#define GLX_AUX_BUFFERS_BIT                                      0x00000010
#define GLX_AUX_BUFFERS_BIT_SGIX                                 0x00000010
#define GLX_DEPTH_BUFFER_BIT                                     0x00000020
#define GLX_DEPTH_BUFFER_BIT_SGIX                                0x00000020
#define GLX_STENCIL_BUFFER_BIT                                   0x00000040
#define GLX_STENCIL_BUFFER_BIT_SGIX                              0x00000040
#define GLX_ACCUM_BUFFER_BIT                                     0x00000080
#define GLX_ACCUM_BUFFER_BIT_SGIX                                0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX                              0x00000100
#define GLX_BUFFER_SWAP_COMPLETE_INTEL_MASK                      0x04000000
#define GLX_BUFFER_CLOBBER_MASK_SGIX                             0x08000000
#define GLX_PBUFFER_CLOBBER_MASK                                 0x08000000
#define GLX_3DFX_WINDOW_MODE_MESA                                0x1
#define GLX_VENDOR                                               0x1
#define GLX_GPU_VENDOR_AMD                                       0x1F00
#define GLX_GPU_RENDERER_STRING_AMD                              0x1F01
#define GLX_GPU_OPENGL_VERSION_STRING_AMD                        0x1F02
#define GLX_3DFX_FULLSCREEN_MODE_MESA                            0x2
#define GLX_VERSION                                              0x2
#define GLX_CONFIG_CAVEAT                                        0x20
#define GLX_VISUAL_CAVEAT_EXT                                    0x20
#define GLX_CONTEXT_MAJOR_VERSION_ARB                            0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB                            0x2092
#define GLX_CONTEXT_FLAGS_ARB                                    0x2094
#define GLX_CONTEXT_ALLOW_BUFFER_BYTE_ORDER_MISMATCH_ARB         0x2095
#define GLX_CONTEXT_RELEASE_BEHAVIOR_ARB                         0x2097
#define GLX_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB                   0x2098
#define GLX_FLOAT_COMPONENTS_NV                                  0x20B0
#define GLX_RGBA_UNSIGNED_FLOAT_TYPE_EXT                         0x20B1
#define GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB                         0x20B2
#define GLX_FRAMEBUFFER_SRGB_CAPABLE_EXT                         0x20B2
#define GLX_COLOR_SAMPLES_NV                                     0x20B3
#define GLX_RGBA_FLOAT_TYPE_ARB                                  0x20B9
#define GLX_VIDEO_OUT_COLOR_NV                                   0x20C3
#define GLX_VIDEO_OUT_ALPHA_NV                                   0x20C4
#define GLX_VIDEO_OUT_DEPTH_NV                                   0x20C5
#define GLX_VIDEO_OUT_COLOR_AND_ALPHA_NV                         0x20C6
#define GLX_VIDEO_OUT_COLOR_AND_DEPTH_NV                         0x20C7
#define GLX_VIDEO_OUT_FRAME_NV                                   0x20C8
#define GLX_VIDEO_OUT_FIELD_1_NV                                 0x20C9
#define GLX_VIDEO_OUT_FIELD_2_NV                                 0x20CA
#define GLX_VIDEO_OUT_STACKED_FIELDS_1_2_NV                      0x20CB
#define GLX_VIDEO_OUT_STACKED_FIELDS_2_1_NV                      0x20CC
#define GLX_DEVICE_ID_NV                                         0x20CD
#define GLX_UNIQUE_ID_NV                                         0x20CE
#define GLX_NUM_VIDEO_CAPTURE_SLOTS_NV                           0x20CF
#define GLX_BIND_TO_TEXTURE_RGB_EXT                              0x20D0
#define GLX_BIND_TO_TEXTURE_RGBA_EXT                             0x20D1
#define GLX_BIND_TO_MIPMAP_TEXTURE_EXT                           0x20D2
#define GLX_BIND_TO_TEXTURE_TARGETS_EXT                          0x20D3
#define GLX_Y_INVERTED_EXT                                       0x20D4
#define GLX_TEXTURE_FORMAT_EXT                                   0x20D5
#define GLX_TEXTURE_TARGET_EXT                                   0x20D6
#define GLX_MIPMAP_TEXTURE_EXT                                   0x20D7
#define GLX_TEXTURE_FORMAT_NONE_EXT                              0x20D8
#define GLX_TEXTURE_FORMAT_RGB_EXT                               0x20D9
#define GLX_TEXTURE_FORMAT_RGBA_EXT                              0x20DA
#define GLX_TEXTURE_1D_EXT                                       0x20DB
#define GLX_TEXTURE_2D_EXT                                       0x20DC
#define GLX_TEXTURE_RECTANGLE_EXT                                0x20DD
#define GLX_FRONT_EXT                                            0x20DE
#define GLX_FRONT_LEFT_EXT                                       0x20DE
#define GLX_FRONT_RIGHT_EXT                                      0x20DF
#define GLX_BACK_EXT                                             0x20E0
#define GLX_BACK_LEFT_EXT                                        0x20E0
#define GLX_BACK_RIGHT_EXT                                       0x20E1
#define GLX_AUX0_EXT                                             0x20E2
#define GLX_AUX1_EXT                                             0x20E3
#define GLX_AUX2_EXT                                             0x20E4
#define GLX_AUX3_EXT                                             0x20E5
#define GLX_AUX4_EXT                                             0x20E6
#define GLX_AUX5_EXT                                             0x20E7
#define GLX_AUX6_EXT                                             0x20E8
#define GLX_AUX7_EXT                                             0x20E9
#define GLX_AUX8_EXT                                             0x20EA
#define GLX_AUX9_EXT                                             0x20EB
#define GLX_NUM_VIDEO_SLOTS_NV                                   0x20F0
#define GLX_SWAP_INTERVAL_EXT                                    0x20F1
#define GLX_MAX_SWAP_INTERVAL_EXT                                0x20F2
#define GLX_LATE_SWAPS_TEAR_EXT                                  0x20F3
#define GLX_BACK_BUFFER_AGE_EXT                                  0x20F4
#define GLX_STEREO_TREE_EXT                                      0x20F5
#define GLX_VENDOR_NAMES_EXT                                     0x20F6
#define GLX_GENERATE_RESET_ON_VIDEO_MEMORY_PURGE_NV              0x20F7
#define GLX_GPU_FASTEST_TARGET_GPUS_AMD                          0x21A2
#define GLX_GPU_RAM_AMD                                          0x21A3
#define GLX_GPU_CLOCK_AMD                                        0x21A4
#define GLX_GPU_NUM_PIPES_AMD                                    0x21A5
#define GLX_GPU_NUM_SIMD_AMD                                     0x21A6
#define GLX_GPU_NUM_RB_AMD                                       0x21A7
#define GLX_GPU_NUM_SPI_AMD                                      0x21A8
#define GLX_X_VISUAL_TYPE                                        0x22
#define GLX_X_VISUAL_TYPE_EXT                                    0x22
#define GLX_TRANSPARENT_TYPE                                     0x23
#define GLX_TRANSPARENT_TYPE_EXT                                 0x23
#define GLX_TRANSPARENT_INDEX_VALUE                              0x24
#define GLX_TRANSPARENT_INDEX_VALUE_EXT                          0x24
#define GLX_TRANSPARENT_RED_VALUE                                0x25
#define GLX_TRANSPARENT_RED_VALUE_EXT                            0x25
#define GLX_TRANSPARENT_GREEN_VALUE                              0x26
#define GLX_TRANSPARENT_GREEN_VALUE_EXT                          0x26
#define GLX_TRANSPARENT_BLUE_VALUE                               0x27
#define GLX_TRANSPARENT_BLUE_VALUE_EXT                           0x27
#define GLX_TRANSPARENT_ALPHA_VALUE                              0x28
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT                          0x28
#define GLX_EXTENSIONS                                           0x3
#define GLX_NONE                                                 0x8000
#define GLX_NONE_EXT                                             0x8000
#define GLX_SLOW_CONFIG                                          0x8001
#define GLX_SLOW_VISUAL_EXT                                      0x8001
#define GLX_TRUE_COLOR                                           0x8002
#define GLX_TRUE_COLOR_EXT                                       0x8002
#define GLX_DIRECT_COLOR                                         0x8003
#define GLX_DIRECT_COLOR_EXT                                     0x8003
#define GLX_PSEUDO_COLOR                                         0x8004
#define GLX_PSEUDO_COLOR_EXT                                     0x8004
#define GLX_STATIC_COLOR                                         0x8005
#define GLX_STATIC_COLOR_EXT                                     0x8005
#define GLX_GRAY_SCALE                                           0x8006
#define GLX_GRAY_SCALE_EXT                                       0x8006
#define GLX_STATIC_GRAY                                          0x8007
#define GLX_STATIC_GRAY_EXT                                      0x8007
#define GLX_TRANSPARENT_RGB                                      0x8008
#define GLX_TRANSPARENT_RGB_EXT                                  0x8008
#define GLX_TRANSPARENT_INDEX                                    0x8009
#define GLX_TRANSPARENT_INDEX_EXT                                0x8009
#define GLX_SHARE_CONTEXT_EXT                                    0x800A
#define GLX_VISUAL_ID                                            0x800B
#define GLX_VISUAL_ID_EXT                                        0x800B
#define GLX_SCREEN                                               0x800C
#define GLX_SCREEN_EXT                                           0x800C
#define GLX_NON_CONFORMANT_CONFIG                                0x800D
#define GLX_NON_CONFORMANT_VISUAL_EXT                            0x800D
#define GLX_DRAWABLE_TYPE                                        0x8010
#define GLX_DRAWABLE_TYPE_SGIX                                   0x8010
#define GLX_RENDER_TYPE                                          0x8011
#define GLX_RENDER_TYPE_SGIX                                     0x8011
#define GLX_X_RENDERABLE                                         0x8012
#define GLX_X_RENDERABLE_SGIX                                    0x8012
#define GLX_FBCONFIG_ID                                          0x8013
#define GLX_FBCONFIG_ID_SGIX                                     0x8013
#define GLX_RGBA_TYPE                                            0x8014
#define GLX_RGBA_TYPE_SGIX                                       0x8014
#define GLX_COLOR_INDEX_TYPE                                     0x8015
#define GLX_COLOR_INDEX_TYPE_SGIX                                0x8015
#define GLX_MAX_PBUFFER_WIDTH                                    0x8016
#define GLX_MAX_PBUFFER_WIDTH_SGIX                               0x8016
#define GLX_MAX_PBUFFER_HEIGHT                                   0x8017
#define GLX_MAX_PBUFFER_HEIGHT_SGIX                              0x8017
#define GLX_MAX_PBUFFER_PIXELS                                   0x8018
#define GLX_MAX_PBUFFER_PIXELS_SGIX                              0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX                           0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX                          0x801A
#define GLX_PRESERVED_CONTENTS                                   0x801B
#define GLX_PRESERVED_CONTENTS_SGIX                              0x801B
#define GLX_LARGEST_PBUFFER                                      0x801C
#define GLX_LARGEST_PBUFFER_SGIX                                 0x801C
#define GLX_WIDTH                                                0x801D
#define GLX_WIDTH_SGIX                                           0x801D
#define GLX_HEIGHT                                               0x801E
#define GLX_HEIGHT_SGIX                                          0x801E
#define GLX_EVENT_MASK                                           0x801F
#define GLX_EVENT_MASK_SGIX                                      0x801F
#define GLX_DAMAGED                                              0x8020
#define GLX_DAMAGED_SGIX                                         0x8020
#define GLX_SAVED                                                0x8021
#define GLX_SAVED_SGIX                                           0x8021
#define GLX_WINDOW                                               0x8022
#define GLX_WINDOW_SGIX                                          0x8022
#define GLX_PBUFFER                                              0x8023
#define GLX_PBUFFER_SGIX                                         0x8023
#define GLX_DIGITAL_MEDIA_PBUFFER_SGIX                           0x8024
#define GLX_BLENDED_RGBA_SGIS                                    0x8025
#define GLX_MULTISAMPLE_SUB_RECT_WIDTH_SGIS                      0x8026
#define GLX_MULTISAMPLE_SUB_RECT_HEIGHT_SGIS                     0x8027
#define GLX_VISUAL_SELECT_GROUP_SGIX                             0x8028
#define GLX_HYPERPIPE_ID_SGIX                                    0x8030
#define GLX_PBUFFER_HEIGHT                                       0x8040
#define GLX_PBUFFER_WIDTH                                        0x8041
#define GLX_SAMPLE_BUFFERS_3DFX                                  0x8050
#define GLX_SAMPLES_3DFX                                         0x8051
#define GLX_SWAP_METHOD_OML                                      0x8060
#define GLX_SWAP_EXCHANGE_OML                                    0x8061
#define GLX_SWAP_COPY_OML                                        0x8062
#define GLX_SWAP_UNDEFINED_OML                                   0x8063
#define GLX_EXCHANGE_COMPLETE_INTEL                              0x8180
#define GLX_COPY_COMPLETE_INTEL                                  0x8181
#define GLX_FLIP_COMPLETE_INTEL                                  0x8182
#define GLX_RENDERER_VENDOR_ID_MESA                              0x8183
#define GLX_RENDERER_DEVICE_ID_MESA                              0x8184
#define GLX_RENDERER_VERSION_MESA                                0x8185
#define GLX_RENDERER_ACCELERATED_MESA                            0x8186
#define GLX_RENDERER_VIDEO_MEMORY_MESA                           0x8187
#define GLX_RENDERER_UNIFIED_MEMORY_ARCHITECTURE_MESA            0x8188
#define GLX_RENDERER_PREFERRED_PROFILE_MESA                      0x8189
#define GLX_RENDERER_OPENGL_CORE_PROFILE_VERSION_MESA            0x818A
#define GLX_RENDERER_OPENGL_COMPATIBILITY_PROFILE_VERSION_MESA   0x818B
#define GLX_RENDERER_OPENGL_ES_PROFILE_VERSION_MESA              0x818C
#define GLX_RENDERER_OPENGL_ES2_PROFILE_VERSION_MESA             0x818D
#define GLX_RENDERER_ID_MESA                                     0x818E
#define GLX_LOSE_CONTEXT_ON_RESET_ARB                            0x8252
#define GLX_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB              0x8256
#define GLX_NO_RESET_NOTIFICATION_ARB                            0x8261
#define GLX_CONTEXT_PROFILE_MASK_ARB                             0x9126
#define GLX_DONT_CARE                                            0xFFFFFFFF
#define GLX_BAD_SCREEN                                           1
#define GLX_BufferSwapComplete                                   1
#define GLX_USE_GL                                               1
#define GLX_BLUE_SIZE                                            10
#define GLX_SAMPLE_BUFFERS                                       100000
#define GLX_SAMPLE_BUFFERS_ARB                                   100000
#define GLX_SAMPLE_BUFFERS_SGIS                                  100000
#define GLX_COVERAGE_SAMPLES_NV                                  100001
#define GLX_SAMPLES                                              100001
#define GLX_SAMPLES_ARB                                          100001
#define GLX_SAMPLES_SGIS                                         100001
#define GLX_ALPHA_SIZE                                           11
#define GLX_DEPTH_SIZE                                           12
#define GLX_STENCIL_SIZE                                         13
#define GLX_ACCUM_RED_SIZE                                       14
#define GLX_ACCUM_GREEN_SIZE                                     15
#define GLX_ACCUM_BLUE_SIZE                                      16
#define GLX_ACCUM_ALPHA_SIZE                                     17
#define __GLX_NUMBER_EVENTS                                      17
#define GLX_BAD_ATTRIBUTE                                        2
#define GLX_BUFFER_SIZE                                          2
#define GLX_LEVEL                                                3
#define GLX_NO_EXTENSION                                         3
#define GLX_BAD_VISUAL                                           4
#define GLX_RGBA                                                 4
#define GLX_BAD_CONTEXT                                          5
#define GLX_DOUBLEBUFFER                                         5
#define GLX_BAD_VALUE                                            6
#define GLX_STEREO                                               6
#define GLX_AUX_BUFFERS                                          7
#define GLX_BAD_ENUM                                             7
#define GLX_RED_SIZE                                             8
#define GLX_HYPERPIPE_PIPE_NAME_LENGTH_SGIX                      80
#define GLX_GREEN_SIZE                                           9
#define GLX_BAD_HYPERPIPE_CONFIG_SGIX                            91
#define GLX_BAD_HYPERPIPE_SGIX                                   92

typedef int (GLAPIENTRY *PFNGLXBINDCHANNELTOWINDOWSGIXPROC)(Display * display, int screen, int channel, Window window);
typedef int (GLAPIENTRY *PFNGLXBINDHYPERPIPESGIXPROC)(Display * dpy, int hpId);
typedef Bool (GLAPIENTRY *PFNGLXBINDSWAPBARRIERNVPROC)(Display * dpy, GLuint group, GLuint barrier);
typedef void (GLAPIENTRY *PFNGLXBINDSWAPBARRIERSGIXPROC)(Display * dpy, GLXDrawable drawable, int barrier);
typedef void (GLAPIENTRY *PFNGLXBINDTEXIMAGEEXTPROC)(Display * dpy, GLXDrawable drawable, int buffer, const int * attrib_list);
typedef int (GLAPIENTRY *PFNGLXBINDVIDEOCAPTUREDEVICENVPROC)(Display * dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
typedef int (GLAPIENTRY *PFNGLXBINDVIDEODEVICENVPROC)(Display * dpy, unsigned int video_slot, unsigned int video_device, const int * attrib_list);
typedef int (GLAPIENTRY *PFNGLXBINDVIDEOIMAGENVPROC)(Display * dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
typedef void (GLAPIENTRY *PFNGLXBLITCONTEXTFRAMEBUFFERAMDPROC)(GLXContext dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef int (GLAPIENTRY *PFNGLXCHANNELRECTSGIXPROC)(Display * display, int screen, int channel, int x, int y, int w, int h);
typedef int (GLAPIENTRY *PFNGLXCHANNELRECTSYNCSGIXPROC)(Display * display, int screen, int channel, GLenum synctype);
typedef GLXFBConfig * (GLAPIENTRY *PFNGLXCHOOSEFBCONFIGPROC)(Display * dpy, int screen, const int * attrib_list, int * nelements);
typedef GLXFBConfigSGIX * (GLAPIENTRY *PFNGLXCHOOSEFBCONFIGSGIXPROC)(Display * dpy, int screen, int * attrib_list, int * nelements);
typedef XVisualInfo * (GLAPIENTRY *PFNGLXCHOOSEVISUALPROC)(Display * dpy, int screen, int * attribList);
typedef void (GLAPIENTRY *PFNGLXCOPYBUFFERSUBDATANVPROC)(Display * dpy, GLXContext readCtx, GLXContext writeCtx, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAPIENTRY *PFNGLXCOPYCONTEXTPROC)(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask);
typedef void (GLAPIENTRY *PFNGLXCOPYIMAGESUBDATANVPROC)(Display * dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRY *PFNGLXCOPYSUBBUFFERMESAPROC)(Display * dpy, GLXDrawable drawable, int x, int y, int width, int height);
typedef GLXContext (GLAPIENTRY *PFNGLXCREATEASSOCIATEDCONTEXTAMDPROC)(unsigned int id, GLXContext share_list);
typedef GLXContext (GLAPIENTRY *PFNGLXCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)(unsigned int id, GLXContext share_context, const int * attribList);
typedef GLXContext (GLAPIENTRY *PFNGLXCREATECONTEXTPROC)(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct);
typedef GLXContext (GLAPIENTRY *PFNGLXCREATECONTEXTATTRIBSARBPROC)(Display * dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int * attrib_list);
typedef GLXContext (GLAPIENTRY *PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC)(Display * dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
typedef GLXPbufferSGIX (GLAPIENTRY *PFNGLXCREATEGLXPBUFFERSGIXPROC)(Display * dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int * attrib_list);
typedef GLXPixmap (GLAPIENTRY *PFNGLXCREATEGLXPIXMAPPROC)(Display * dpy, XVisualInfo * visual, Pixmap pixmap);
typedef GLXPixmap (GLAPIENTRY *PFNGLXCREATEGLXPIXMAPMESAPROC)(Display * dpy, XVisualInfo * visual, Pixmap pixmap, Colormap cmap);
typedef GLXPixmap (GLAPIENTRY *PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC)(Display * dpy, GLXFBConfigSGIX config, Pixmap pixmap);
typedef GLXContext (GLAPIENTRY *PFNGLXCREATENEWCONTEXTPROC)(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef GLXPbuffer (GLAPIENTRY *PFNGLXCREATEPBUFFERPROC)(Display * dpy, GLXFBConfig config, const int * attrib_list);
typedef GLXPixmap (GLAPIENTRY *PFNGLXCREATEPIXMAPPROC)(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);
typedef GLXWindow (GLAPIENTRY *PFNGLXCREATEWINDOWPROC)(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);
typedef void (GLAPIENTRY *PFNGLXCUSHIONSGIPROC)(Display * dpy, Window window, float cushion);
typedef Bool (GLAPIENTRY *PFNGLXDELAYBEFORESWAPNVPROC)(Display * dpy, GLXDrawable drawable, GLfloat seconds);
typedef Bool (GLAPIENTRY *PFNGLXDELETEASSOCIATEDCONTEXTAMDPROC)(GLXContext ctx);
typedef void (GLAPIENTRY *PFNGLXDESTROYCONTEXTPROC)(Display * dpy, GLXContext ctx);
typedef void (GLAPIENTRY *PFNGLXDESTROYGLXPBUFFERSGIXPROC)(Display * dpy, GLXPbufferSGIX pbuf);
typedef void (GLAPIENTRY *PFNGLXDESTROYGLXPIXMAPPROC)(Display * dpy, GLXPixmap pixmap);
typedef void (GLAPIENTRY *PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC)(Display * dpy, GLXVideoSourceSGIX glxvideosource);
typedef int (GLAPIENTRY *PFNGLXDESTROYHYPERPIPECONFIGSGIXPROC)(Display * dpy, int hpId);
typedef void (GLAPIENTRY *PFNGLXDESTROYPBUFFERPROC)(Display * dpy, GLXPbuffer pbuf);
typedef void (GLAPIENTRY *PFNGLXDESTROYPIXMAPPROC)(Display * dpy, GLXPixmap pixmap);
typedef void (GLAPIENTRY *PFNGLXDESTROYWINDOWPROC)(Display * dpy, GLXWindow win);
typedef GLXVideoCaptureDeviceNV * (GLAPIENTRY *PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC)(Display * dpy, int screen, int * nelements);
typedef unsigned int * (GLAPIENTRY *PFNGLXENUMERATEVIDEODEVICESNVPROC)(Display * dpy, int screen, int * nelements);
typedef void (GLAPIENTRY *PFNGLXFREECONTEXTEXTPROC)(Display * dpy, GLXContext context);
typedef unsigned int (GLAPIENTRY *PFNGLXGETAGPOFFSETMESAPROC)(const void * pointer);
typedef const char * (GLAPIENTRY *PFNGLXGETCLIENTSTRINGPROC)(Display * dpy, int name);
typedef int (GLAPIENTRY *PFNGLXGETCONFIGPROC)(Display * dpy, XVisualInfo * visual, int attrib, int * value);
typedef unsigned int (GLAPIENTRY *PFNGLXGETCONTEXTGPUIDAMDPROC)(GLXContext ctx);
typedef GLXContextID (GLAPIENTRY *PFNGLXGETCONTEXTIDEXTPROC)(const GLXContext context);
typedef GLXContext (GLAPIENTRY *PFNGLXGETCURRENTASSOCIATEDCONTEXTAMDPROC)(void);
typedef GLXContext (GLAPIENTRY *PFNGLXGETCURRENTCONTEXTPROC)(void);
typedef Display * (GLAPIENTRY *PFNGLXGETCURRENTDISPLAYPROC)(void);
typedef Display * (GLAPIENTRY *PFNGLXGETCURRENTDISPLAYEXTPROC)(void);
typedef GLXDrawable (GLAPIENTRY *PFNGLXGETCURRENTDRAWABLEPROC)(void);
typedef GLXDrawable (GLAPIENTRY *PFNGLXGETCURRENTREADDRAWABLEPROC)(void);
typedef GLXDrawable (GLAPIENTRY *PFNGLXGETCURRENTREADDRAWABLESGIPROC)(void);
typedef int (GLAPIENTRY *PFNGLXGETFBCONFIGATTRIBPROC)(Display * dpy, GLXFBConfig config, int attribute, int * value);
typedef int (GLAPIENTRY *PFNGLXGETFBCONFIGATTRIBSGIXPROC)(Display * dpy, GLXFBConfigSGIX config, int attribute, int * value);
typedef GLXFBConfigSGIX (GLAPIENTRY *PFNGLXGETFBCONFIGFROMVISUALSGIXPROC)(Display * dpy, XVisualInfo * vis);
typedef GLXFBConfig * (GLAPIENTRY *PFNGLXGETFBCONFIGSPROC)(Display * dpy, int screen, int * nelements);
typedef unsigned int (GLAPIENTRY *PFNGLXGETGPUIDSAMDPROC)(unsigned int maxCount, unsigned int * ids);
typedef int (GLAPIENTRY *PFNGLXGETGPUINFOAMDPROC)(unsigned int id, int property, GLenum dataType, unsigned int size, void * data);
typedef Bool (GLAPIENTRY *PFNGLXGETMSCRATEOMLPROC)(Display * dpy, GLXDrawable drawable, int32_t * numerator, int32_t * denominator);
typedef __GLXextFuncPtr (GLAPIENTRY *PFNGLXGETPROCADDRESSPROC)(const GLubyte * procName);
typedef __GLXextFuncPtr (GLAPIENTRY *PFNGLXGETPROCADDRESSARBPROC)(const GLubyte * procName);
typedef void (GLAPIENTRY *PFNGLXGETSELECTEDEVENTPROC)(Display * dpy, GLXDrawable draw, unsigned long * event_mask);
typedef void (GLAPIENTRY *PFNGLXGETSELECTEDEVENTSGIXPROC)(Display * dpy, GLXDrawable drawable, unsigned long * mask);
typedef Bool (GLAPIENTRY *PFNGLXGETSYNCVALUESOMLPROC)(Display * dpy, GLXDrawable drawable, int64_t * ust, int64_t * msc, int64_t * sbc);
typedef Status (GLAPIENTRY *PFNGLXGETTRANSPARENTINDEXSUNPROC)(Display * dpy, Window overlay, Window underlay, long * pTransparentIndex);
typedef int (GLAPIENTRY *PFNGLXGETVIDEODEVICENVPROC)(Display * dpy, int screen, int numVideoDevices, GLXVideoDeviceNV * pVideoDevice);
typedef int (GLAPIENTRY *PFNGLXGETVIDEOINFONVPROC)(Display * dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo);
typedef int (GLAPIENTRY *PFNGLXGETVIDEOSYNCSGIPROC)(unsigned int * count);
typedef XVisualInfo * (GLAPIENTRY *PFNGLXGETVISUALFROMFBCONFIGPROC)(Display * dpy, GLXFBConfig config);
typedef XVisualInfo * (GLAPIENTRY *PFNGLXGETVISUALFROMFBCONFIGSGIXPROC)(Display * dpy, GLXFBConfigSGIX config);
typedef int (GLAPIENTRY *PFNGLXHYPERPIPEATTRIBSGIXPROC)(Display * dpy, int timeSlice, int attrib, int size, void * attribList);
typedef int (GLAPIENTRY *PFNGLXHYPERPIPECONFIGSGIXPROC)(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX * cfg, int * hpId);
typedef GLXContext (GLAPIENTRY *PFNGLXIMPORTCONTEXTEXTPROC)(Display * dpy, GLXContextID contextID);
typedef Bool (GLAPIENTRY *PFNGLXISDIRECTPROC)(Display * dpy, GLXContext ctx);
typedef Bool (GLAPIENTRY *PFNGLXJOINSWAPGROUPNVPROC)(Display * dpy, GLXDrawable drawable, GLuint group);
typedef void (GLAPIENTRY *PFNGLXJOINSWAPGROUPSGIXPROC)(Display * dpy, GLXDrawable drawable, GLXDrawable member);
typedef void (GLAPIENTRY *PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC)(Display * dpy, GLXVideoCaptureDeviceNV device);
typedef Bool (GLAPIENTRY *PFNGLXMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)(GLXContext ctx);
typedef Bool (GLAPIENTRY *PFNGLXMAKECONTEXTCURRENTPROC)(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef Bool (GLAPIENTRY *PFNGLXMAKECURRENTPROC)(Display * dpy, GLXDrawable drawable, GLXContext ctx);
typedef Bool (GLAPIENTRY *PFNGLXMAKECURRENTREADSGIPROC)(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef void (GLAPIENTRY *PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC)(Display * dpy, GLXContext readCtx, GLXContext writeCtx, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef int (GLAPIENTRY *PFNGLXQUERYCHANNELDELTASSGIXPROC)(Display * display, int screen, int channel, int * x, int * y, int * w, int * h);
typedef int (GLAPIENTRY *PFNGLXQUERYCHANNELRECTSGIXPROC)(Display * display, int screen, int channel, int * dx, int * dy, int * dw, int * dh);
typedef int (GLAPIENTRY *PFNGLXQUERYCONTEXTPROC)(Display * dpy, GLXContext ctx, int attribute, int * value);
typedef int (GLAPIENTRY *PFNGLXQUERYCONTEXTINFOEXTPROC)(Display * dpy, GLXContext context, int attribute, int * value);
typedef Bool (GLAPIENTRY *PFNGLXQUERYCURRENTRENDERERINTEGERMESAPROC)(int attribute, unsigned int * value);
typedef const char * (GLAPIENTRY *PFNGLXQUERYCURRENTRENDERERSTRINGMESAPROC)(int attribute);
typedef void (GLAPIENTRY *PFNGLXQUERYDRAWABLEPROC)(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);
typedef Bool (GLAPIENTRY *PFNGLXQUERYEXTENSIONPROC)(Display * dpy, int * errorb, int * event);
typedef const char * (GLAPIENTRY *PFNGLXQUERYEXTENSIONSSTRINGPROC)(Display * dpy, int screen);
typedef Bool (GLAPIENTRY *PFNGLXQUERYFRAMECOUNTNVPROC)(Display * dpy, int screen, GLuint * count);
typedef int (GLAPIENTRY *PFNGLXQUERYGLXPBUFFERSGIXPROC)(Display * dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int * value);
typedef int (GLAPIENTRY *PFNGLXQUERYHYPERPIPEATTRIBSGIXPROC)(Display * dpy, int timeSlice, int attrib, int size, void * returnAttribList);
typedef int (GLAPIENTRY *PFNGLXQUERYHYPERPIPEBESTATTRIBSGIXPROC)(Display * dpy, int timeSlice, int attrib, int size, void * attribList, void * returnAttribList);
typedef GLXHyperpipeConfigSGIX * (GLAPIENTRY *PFNGLXQUERYHYPERPIPECONFIGSGIXPROC)(Display * dpy, int hpId, int * npipes);
typedef GLXHyperpipeNetworkSGIX * (GLAPIENTRY *PFNGLXQUERYHYPERPIPENETWORKSGIXPROC)(Display * dpy, int * npipes);
typedef Bool (GLAPIENTRY *PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC)(Display * dpy, int screen, int * max);
typedef Bool (GLAPIENTRY *PFNGLXQUERYMAXSWAPGROUPSNVPROC)(Display * dpy, int screen, GLuint * maxGroups, GLuint * maxBarriers);
typedef Bool (GLAPIENTRY *PFNGLXQUERYRENDERERINTEGERMESAPROC)(Display * dpy, int screen, int renderer, int attribute, unsigned int * value);
typedef const char * (GLAPIENTRY *PFNGLXQUERYRENDERERSTRINGMESAPROC)(Display * dpy, int screen, int renderer, int attribute);
typedef const char * (GLAPIENTRY *PFNGLXQUERYSERVERSTRINGPROC)(Display * dpy, int screen, int name);
typedef Bool (GLAPIENTRY *PFNGLXQUERYSWAPGROUPNVPROC)(Display * dpy, GLXDrawable drawable, GLuint * group, GLuint * barrier);
typedef Bool (GLAPIENTRY *PFNGLXQUERYVERSIONPROC)(Display * dpy, int * maj, int * min);
typedef int (GLAPIENTRY *PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC)(Display * dpy, GLXVideoCaptureDeviceNV device, int attribute, int * value);
typedef Bool (GLAPIENTRY *PFNGLXRELEASEBUFFERSMESAPROC)(Display * dpy, GLXDrawable drawable);
typedef void (GLAPIENTRY *PFNGLXRELEASETEXIMAGEEXTPROC)(Display * dpy, GLXDrawable drawable, int buffer);
typedef void (GLAPIENTRY *PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC)(Display * dpy, GLXVideoCaptureDeviceNV device);
typedef int (GLAPIENTRY *PFNGLXRELEASEVIDEODEVICENVPROC)(Display * dpy, int screen, GLXVideoDeviceNV VideoDevice);
typedef int (GLAPIENTRY *PFNGLXRELEASEVIDEOIMAGENVPROC)(Display * dpy, GLXPbuffer pbuf);
typedef Bool (GLAPIENTRY *PFNGLXRESETFRAMECOUNTNVPROC)(Display * dpy, int screen);
typedef void (GLAPIENTRY *PFNGLXSELECTEVENTPROC)(Display * dpy, GLXDrawable draw, unsigned long event_mask);
typedef void (GLAPIENTRY *PFNGLXSELECTEVENTSGIXPROC)(Display * dpy, GLXDrawable drawable, unsigned long mask);
typedef int (GLAPIENTRY *PFNGLXSENDPBUFFERTOVIDEONVPROC)(Display * dpy, GLXPbuffer pbuf, int iBufferType, unsigned long * pulCounterPbuffer, GLboolean bBlock);
typedef Bool (GLAPIENTRY *PFNGLXSET3DFXMODEMESAPROC)(int mode);
typedef void (GLAPIENTRY *PFNGLXSWAPBUFFERSPROC)(Display * dpy, GLXDrawable drawable);
typedef int64_t (GLAPIENTRY *PFNGLXSWAPBUFFERSMSCOMLPROC)(Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
typedef void (GLAPIENTRY *PFNGLXSWAPINTERVALEXTPROC)(Display * dpy, GLXDrawable drawable, int interval);
typedef int (GLAPIENTRY *PFNGLXSWAPINTERVALSGIPROC)(int interval);
typedef void (GLAPIENTRY *PFNGLXUSEXFONTPROC)(Font font, int first, int count, int list);
typedef Bool (GLAPIENTRY *PFNGLXWAITFORMSCOMLPROC)(Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t * ust, int64_t * msc, int64_t * sbc);
typedef Bool (GLAPIENTRY *PFNGLXWAITFORSBCOMLPROC)(Display * dpy, GLXDrawable drawable, int64_t target_sbc, int64_t * ust, int64_t * msc, int64_t * sbc);
typedef void (GLAPIENTRY *PFNGLXWAITGLPROC)(void);
typedef int (GLAPIENTRY *PFNGLXWAITVIDEOSYNCSGIPROC)(int divisor, int remainder, unsigned int * count);
typedef void (GLAPIENTRY *PFNGLXWAITXPROC)(void);
GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXBindChannelToWindowSGIX(Display * display, int screen, int channel, Window window);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXBindHyperpipeSGIX(Display * dpy, int hpId);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXBindSwapBarrierNV(Display * dpy, GLuint group, GLuint barrier);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXBindSwapBarrierSGIX(Display * dpy, GLXDrawable drawable, int barrier);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXBindTexImageEXT(Display * dpy, GLXDrawable drawable, int buffer, const int * attrib_list);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXBindVideoCaptureDeviceNV(Display * dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXBindVideoDeviceNV(Display * dpy, unsigned int video_slot, unsigned int video_device, const int * attrib_list);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXBindVideoImageNV(Display * dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXBlitContextFramebufferAMD(GLXContext dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXChannelRectSGIX(Display * display, int screen, int channel, int x, int y, int w, int h);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXChannelRectSyncSGIX(Display * display, int screen, int channel, GLenum synctype);

GLPROXY_IMPORTEXPORT GLXFBConfig * GLPROXY_CALLSPEC glproxy_glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements);

GLPROXY_IMPORTEXPORT GLXFBConfigSGIX * GLPROXY_CALLSPEC glproxy_glXChooseFBConfigSGIX(Display * dpy, int screen, int * attrib_list, int * nelements);

GLPROXY_IMPORTEXPORT XVisualInfo * GLPROXY_CALLSPEC glproxy_glXChooseVisual(Display * dpy, int screen, int * attribList);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXCopyBufferSubDataNV(Display * dpy, GLXContext readCtx, GLXContext writeCtx, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXCopyImageSubDataNV(Display * dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXCopySubBufferMESA(Display * dpy, GLXDrawable drawable, int x, int y, int width, int height);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXCreateAssociatedContextAMD(unsigned int id, GLXContext share_list);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXCreateAssociatedContextAttribsAMD(unsigned int id, GLXContext share_context, const int * attribList);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXCreateContextAttribsARB(Display * dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int * attrib_list);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXCreateContextWithConfigSGIX(Display * dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);

GLPROXY_IMPORTEXPORT GLXPbufferSGIX GLPROXY_CALLSPEC glproxy_glXCreateGLXPbufferSGIX(Display * dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int * attrib_list);

GLPROXY_IMPORTEXPORT GLXPixmap GLPROXY_CALLSPEC glproxy_glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap);

GLPROXY_IMPORTEXPORT GLXPixmap GLPROXY_CALLSPEC glproxy_glXCreateGLXPixmapMESA(Display * dpy, XVisualInfo * visual, Pixmap pixmap, Colormap cmap);

GLPROXY_IMPORTEXPORT GLXPixmap GLPROXY_CALLSPEC glproxy_glXCreateGLXPixmapWithConfigSGIX(Display * dpy, GLXFBConfigSGIX config, Pixmap pixmap);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);

GLPROXY_IMPORTEXPORT GLXPbuffer GLPROXY_CALLSPEC glproxy_glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list);

GLPROXY_IMPORTEXPORT GLXPixmap GLPROXY_CALLSPEC glproxy_glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);

GLPROXY_IMPORTEXPORT GLXWindow GLPROXY_CALLSPEC glproxy_glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXCushionSGI(Display * dpy, Window window, float cushion);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXDelayBeforeSwapNV(Display * dpy, GLXDrawable drawable, GLfloat seconds);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXDeleteAssociatedContextAMD(GLXContext ctx);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyContext(Display * dpy, GLXContext ctx);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyGLXPbufferSGIX(Display * dpy, GLXPbufferSGIX pbuf);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyGLXVideoSourceSGIX(Display * dpy, GLXVideoSourceSGIX glxvideosource);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyPixmap(Display * dpy, GLXPixmap pixmap);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXDestroyWindow(Display * dpy, GLXWindow win);

GLPROXY_IMPORTEXPORT GLXVideoCaptureDeviceNV * GLPROXY_CALLSPEC glproxy_glXEnumerateVideoCaptureDevicesNV(Display * dpy, int screen, int * nelements);

GLPROXY_IMPORTEXPORT unsigned int * GLPROXY_CALLSPEC glproxy_glXEnumerateVideoDevicesNV(Display * dpy, int screen, int * nelements);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXFreeContextEXT(Display * dpy, GLXContext context);

GLPROXY_IMPORTEXPORT unsigned int GLPROXY_CALLSPEC glproxy_glXGetAGPOffsetMESA(const void * pointer);

GLPROXY_IMPORTEXPORT const char * GLPROXY_CALLSPEC glproxy_glXGetClientString(Display * dpy, int name);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetConfig(Display * dpy, XVisualInfo * visual, int attrib, int * value);

GLPROXY_IMPORTEXPORT unsigned int GLPROXY_CALLSPEC glproxy_glXGetContextGPUIDAMD(GLXContext ctx);

GLPROXY_IMPORTEXPORT GLXContextID GLPROXY_CALLSPEC glproxy_glXGetContextIDEXT(const GLXContext context);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXGetCurrentAssociatedContextAMD(void);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXGetCurrentContext(void);

GLPROXY_IMPORTEXPORT Display * GLPROXY_CALLSPEC glproxy_glXGetCurrentDisplay(void);

GLPROXY_IMPORTEXPORT Display * GLPROXY_CALLSPEC glproxy_glXGetCurrentDisplayEXT(void);

GLPROXY_IMPORTEXPORT GLXDrawable GLPROXY_CALLSPEC glproxy_glXGetCurrentDrawable(void);

GLPROXY_IMPORTEXPORT GLXDrawable GLPROXY_CALLSPEC glproxy_glXGetCurrentReadDrawable(void);

GLPROXY_IMPORTEXPORT GLXDrawable GLPROXY_CALLSPEC glproxy_glXGetCurrentReadDrawableSGI(void);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetFBConfigAttribSGIX(Display * dpy, GLXFBConfigSGIX config, int attribute, int * value);

GLPROXY_IMPORTEXPORT GLXFBConfigSGIX GLPROXY_CALLSPEC glproxy_glXGetFBConfigFromVisualSGIX(Display * dpy, XVisualInfo * vis);

GLPROXY_IMPORTEXPORT GLXFBConfig * GLPROXY_CALLSPEC glproxy_glXGetFBConfigs(Display * dpy, int screen, int * nelements);

GLPROXY_IMPORTEXPORT unsigned int GLPROXY_CALLSPEC glproxy_glXGetGPUIDsAMD(unsigned int maxCount, unsigned int * ids);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetGPUInfoAMD(unsigned int id, int property, GLenum dataType, unsigned int size, void * data);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXGetMscRateOML(Display * dpy, GLXDrawable drawable, int32_t * numerator, int32_t * denominator);

GLPROXY_IMPORTEXPORT __GLXextFuncPtr GLPROXY_CALLSPEC glproxy_glXGetProcAddress(const GLubyte * procName);

GLPROXY_IMPORTEXPORT __GLXextFuncPtr GLPROXY_CALLSPEC glproxy_glXGetProcAddressARB(const GLubyte * procName);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXGetSelectedEventSGIX(Display * dpy, GLXDrawable drawable, unsigned long * mask);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXGetSyncValuesOML(Display * dpy, GLXDrawable drawable, int64_t * ust, int64_t * msc, int64_t * sbc);

GLPROXY_IMPORTEXPORT Status GLPROXY_CALLSPEC glproxy_glXGetTransparentIndexSUN(Display * dpy, Window overlay, Window underlay, long * pTransparentIndex);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetVideoDeviceNV(Display * dpy, int screen, int numVideoDevices, GLXVideoDeviceNV * pVideoDevice);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetVideoInfoNV(Display * dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXGetVideoSyncSGI(unsigned int * count);

GLPROXY_IMPORTEXPORT XVisualInfo * GLPROXY_CALLSPEC glproxy_glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config);

GLPROXY_IMPORTEXPORT XVisualInfo * GLPROXY_CALLSPEC glproxy_glXGetVisualFromFBConfigSGIX(Display * dpy, GLXFBConfigSGIX config);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, void * attribList);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX * cfg, int * hpId);

GLPROXY_IMPORTEXPORT GLXContext GLPROXY_CALLSPEC glproxy_glXImportContextEXT(Display * dpy, GLXContextID contextID);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXIsDirect(Display * dpy, GLXContext ctx);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXJoinSwapGroupNV(Display * dpy, GLXDrawable drawable, GLuint group);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXJoinSwapGroupSGIX(Display * dpy, GLXDrawable drawable, GLXDrawable member);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXLockVideoCaptureDeviceNV(Display * dpy, GLXVideoCaptureDeviceNV device);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXMakeAssociatedContextCurrentAMD(GLXContext ctx);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXMakeCurrentReadSGI(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXNamedCopyBufferSubDataNV(Display * dpy, GLXContext readCtx, GLXContext writeCtx, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryChannelDeltasSGIX(Display * display, int screen, int channel, int * x, int * y, int * w, int * h);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryChannelRectSGIX(Display * display, int screen, int channel, int * dx, int * dy, int * dw, int * dh);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryContextInfoEXT(Display * dpy, GLXContext context, int attribute, int * value);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryCurrentRendererIntegerMESA(int attribute, unsigned int * value);

GLPROXY_IMPORTEXPORT const char * GLPROXY_CALLSPEC glproxy_glXQueryCurrentRendererStringMESA(int attribute);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryExtension(Display * dpy, int * errorb, int * event);

GLPROXY_IMPORTEXPORT const char * GLPROXY_CALLSPEC glproxy_glXQueryExtensionsString(Display * dpy, int screen);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryFrameCountNV(Display * dpy, int screen, GLuint * count);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryGLXPbufferSGIX(Display * dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int * value);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, void * returnAttribList);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, void * attribList, void * returnAttribList);

GLPROXY_IMPORTEXPORT GLXHyperpipeConfigSGIX * GLPROXY_CALLSPEC glproxy_glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes);

GLPROXY_IMPORTEXPORT GLXHyperpipeNetworkSGIX * GLPROXY_CALLSPEC glproxy_glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryMaxSwapBarriersSGIX(Display * dpy, int screen, int * max);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryMaxSwapGroupsNV(Display * dpy, int screen, GLuint * maxGroups, GLuint * maxBarriers);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryRendererIntegerMESA(Display * dpy, int screen, int renderer, int attribute, unsigned int * value);

GLPROXY_IMPORTEXPORT const char * GLPROXY_CALLSPEC glproxy_glXQueryRendererStringMESA(Display * dpy, int screen, int renderer, int attribute);

GLPROXY_IMPORTEXPORT const char * GLPROXY_CALLSPEC glproxy_glXQueryServerString(Display * dpy, int screen, int name);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQuerySwapGroupNV(Display * dpy, GLXDrawable drawable, GLuint * group, GLuint * barrier);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXQueryVersion(Display * dpy, int * maj, int * min);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXQueryVideoCaptureDeviceNV(Display * dpy, GLXVideoCaptureDeviceNV device, int attribute, int * value);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXReleaseBuffersMESA(Display * dpy, GLXDrawable drawable);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXReleaseTexImageEXT(Display * dpy, GLXDrawable drawable, int buffer);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXReleaseVideoCaptureDeviceNV(Display * dpy, GLXVideoCaptureDeviceNV device);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXReleaseVideoDeviceNV(Display * dpy, int screen, GLXVideoDeviceNV VideoDevice);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXReleaseVideoImageNV(Display * dpy, GLXPbuffer pbuf);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXResetFrameCountNV(Display * dpy, int screen);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXSelectEventSGIX(Display * dpy, GLXDrawable drawable, unsigned long mask);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXSendPbufferToVideoNV(Display * dpy, GLXPbuffer pbuf, int iBufferType, unsigned long * pulCounterPbuffer, GLboolean bBlock);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXSet3DfxModeMESA(int mode);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXSwapBuffers(Display * dpy, GLXDrawable drawable);

GLPROXY_IMPORTEXPORT int64_t GLPROXY_CALLSPEC glproxy_glXSwapBuffersMscOML(Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXSwapIntervalEXT(Display * dpy, GLXDrawable drawable, int interval);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXSwapIntervalSGI(int interval);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXUseXFont(Font font, int first, int count, int list);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXWaitForMscOML(Display * dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t * ust, int64_t * msc, int64_t * sbc);

GLPROXY_IMPORTEXPORT Bool GLPROXY_CALLSPEC glproxy_glXWaitForSbcOML(Display * dpy, GLXDrawable drawable, int64_t target_sbc, int64_t * ust, int64_t * msc, int64_t * sbc);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXWaitGL(void);

GLPROXY_IMPORTEXPORT int GLPROXY_CALLSPEC glproxy_glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int * count);

GLPROXY_IMPORTEXPORT void GLPROXY_CALLSPEC glproxy_glXWaitX(void);

#define glXBindChannelToWindowSGIX glproxy_glXBindChannelToWindowSGIX
#define glXBindHyperpipeSGIX glproxy_glXBindHyperpipeSGIX
#define glXBindSwapBarrierNV glproxy_glXBindSwapBarrierNV
#define glXBindSwapBarrierSGIX glproxy_glXBindSwapBarrierSGIX
#define glXBindTexImageEXT glproxy_glXBindTexImageEXT
#define glXBindVideoCaptureDeviceNV glproxy_glXBindVideoCaptureDeviceNV
#define glXBindVideoDeviceNV glproxy_glXBindVideoDeviceNV
#define glXBindVideoImageNV glproxy_glXBindVideoImageNV
#define glXBlitContextFramebufferAMD glproxy_glXBlitContextFramebufferAMD
#define glXChannelRectSGIX glproxy_glXChannelRectSGIX
#define glXChannelRectSyncSGIX glproxy_glXChannelRectSyncSGIX
#define glXChooseFBConfig glproxy_glXChooseFBConfig
#define glXChooseFBConfigSGIX glproxy_glXChooseFBConfigSGIX
#define glXChooseVisual glproxy_glXChooseVisual
#define glXCopyBufferSubDataNV glproxy_glXCopyBufferSubDataNV
#define glXCopyContext glproxy_glXCopyContext
#define glXCopyImageSubDataNV glproxy_glXCopyImageSubDataNV
#define glXCopySubBufferMESA glproxy_glXCopySubBufferMESA
#define glXCreateAssociatedContextAMD glproxy_glXCreateAssociatedContextAMD
#define glXCreateAssociatedContextAttribsAMD glproxy_glXCreateAssociatedContextAttribsAMD
#define glXCreateContext glproxy_glXCreateContext
#define glXCreateContextAttribsARB glproxy_glXCreateContextAttribsARB
#define glXCreateContextWithConfigSGIX glproxy_glXCreateContextWithConfigSGIX
#define glXCreateGLXPbufferSGIX glproxy_glXCreateGLXPbufferSGIX
#define glXCreateGLXPixmap glproxy_glXCreateGLXPixmap
#define glXCreateGLXPixmapMESA glproxy_glXCreateGLXPixmapMESA
#define glXCreateGLXPixmapWithConfigSGIX glproxy_glXCreateGLXPixmapWithConfigSGIX
#define glXCreateNewContext glproxy_glXCreateNewContext
#define glXCreatePbuffer glproxy_glXCreatePbuffer
#define glXCreatePixmap glproxy_glXCreatePixmap
#define glXCreateWindow glproxy_glXCreateWindow
#define glXCushionSGI glproxy_glXCushionSGI
#define glXDelayBeforeSwapNV glproxy_glXDelayBeforeSwapNV
#define glXDeleteAssociatedContextAMD glproxy_glXDeleteAssociatedContextAMD
#define glXDestroyContext glproxy_glXDestroyContext
#define glXDestroyGLXPbufferSGIX glproxy_glXDestroyGLXPbufferSGIX
#define glXDestroyGLXPixmap glproxy_glXDestroyGLXPixmap
#define glXDestroyGLXVideoSourceSGIX glproxy_glXDestroyGLXVideoSourceSGIX
#define glXDestroyHyperpipeConfigSGIX glproxy_glXDestroyHyperpipeConfigSGIX
#define glXDestroyPbuffer glproxy_glXDestroyPbuffer
#define glXDestroyPixmap glproxy_glXDestroyPixmap
#define glXDestroyWindow glproxy_glXDestroyWindow
#define glXEnumerateVideoCaptureDevicesNV glproxy_glXEnumerateVideoCaptureDevicesNV
#define glXEnumerateVideoDevicesNV glproxy_glXEnumerateVideoDevicesNV
#define glXFreeContextEXT glproxy_glXFreeContextEXT
#define glXGetAGPOffsetMESA glproxy_glXGetAGPOffsetMESA
#define glXGetClientString glproxy_glXGetClientString
#define glXGetConfig glproxy_glXGetConfig
#define glXGetContextGPUIDAMD glproxy_glXGetContextGPUIDAMD
#define glXGetContextIDEXT glproxy_glXGetContextIDEXT
#define glXGetCurrentAssociatedContextAMD glproxy_glXGetCurrentAssociatedContextAMD
#define glXGetCurrentContext glproxy_glXGetCurrentContext
#define glXGetCurrentDisplay glproxy_glXGetCurrentDisplay
#define glXGetCurrentDisplayEXT glproxy_glXGetCurrentDisplayEXT
#define glXGetCurrentDrawable glproxy_glXGetCurrentDrawable
#define glXGetCurrentReadDrawable glproxy_glXGetCurrentReadDrawable
#define glXGetCurrentReadDrawableSGI glproxy_glXGetCurrentReadDrawableSGI
#define glXGetFBConfigAttrib glproxy_glXGetFBConfigAttrib
#define glXGetFBConfigAttribSGIX glproxy_glXGetFBConfigAttribSGIX
#define glXGetFBConfigFromVisualSGIX glproxy_glXGetFBConfigFromVisualSGIX
#define glXGetFBConfigs glproxy_glXGetFBConfigs
#define glXGetGPUIDsAMD glproxy_glXGetGPUIDsAMD
#define glXGetGPUInfoAMD glproxy_glXGetGPUInfoAMD
#define glXGetMscRateOML glproxy_glXGetMscRateOML
#define glXGetProcAddress glproxy_glXGetProcAddress
#define glXGetProcAddressARB glproxy_glXGetProcAddressARB
#define glXGetSelectedEvent glproxy_glXGetSelectedEvent
#define glXGetSelectedEventSGIX glproxy_glXGetSelectedEventSGIX
#define glXGetSyncValuesOML glproxy_glXGetSyncValuesOML
#define glXGetTransparentIndexSUN glproxy_glXGetTransparentIndexSUN
#define glXGetVideoDeviceNV glproxy_glXGetVideoDeviceNV
#define glXGetVideoInfoNV glproxy_glXGetVideoInfoNV
#define glXGetVideoSyncSGI glproxy_glXGetVideoSyncSGI
#define glXGetVisualFromFBConfig glproxy_glXGetVisualFromFBConfig
#define glXGetVisualFromFBConfigSGIX glproxy_glXGetVisualFromFBConfigSGIX
#define glXHyperpipeAttribSGIX glproxy_glXHyperpipeAttribSGIX
#define glXHyperpipeConfigSGIX glproxy_glXHyperpipeConfigSGIX
#define glXImportContextEXT glproxy_glXImportContextEXT
#define glXIsDirect glproxy_glXIsDirect
#define glXJoinSwapGroupNV glproxy_glXJoinSwapGroupNV
#define glXJoinSwapGroupSGIX glproxy_glXJoinSwapGroupSGIX
#define glXLockVideoCaptureDeviceNV glproxy_glXLockVideoCaptureDeviceNV
#define glXMakeAssociatedContextCurrentAMD glproxy_glXMakeAssociatedContextCurrentAMD
#define glXMakeContextCurrent glproxy_glXMakeContextCurrent
#define glXMakeCurrent glproxy_glXMakeCurrent
#define glXMakeCurrentReadSGI glproxy_glXMakeCurrentReadSGI
#define glXNamedCopyBufferSubDataNV glproxy_glXNamedCopyBufferSubDataNV
#define glXQueryChannelDeltasSGIX glproxy_glXQueryChannelDeltasSGIX
#define glXQueryChannelRectSGIX glproxy_glXQueryChannelRectSGIX
#define glXQueryContext glproxy_glXQueryContext
#define glXQueryContextInfoEXT glproxy_glXQueryContextInfoEXT
#define glXQueryCurrentRendererIntegerMESA glproxy_glXQueryCurrentRendererIntegerMESA
#define glXQueryCurrentRendererStringMESA glproxy_glXQueryCurrentRendererStringMESA
#define glXQueryDrawable glproxy_glXQueryDrawable
#define glXQueryExtension glproxy_glXQueryExtension
#define glXQueryExtensionsString glproxy_glXQueryExtensionsString
#define glXQueryFrameCountNV glproxy_glXQueryFrameCountNV
#define glXQueryGLXPbufferSGIX glproxy_glXQueryGLXPbufferSGIX
#define glXQueryHyperpipeAttribSGIX glproxy_glXQueryHyperpipeAttribSGIX
#define glXQueryHyperpipeBestAttribSGIX glproxy_glXQueryHyperpipeBestAttribSGIX
#define glXQueryHyperpipeConfigSGIX glproxy_glXQueryHyperpipeConfigSGIX
#define glXQueryHyperpipeNetworkSGIX glproxy_glXQueryHyperpipeNetworkSGIX
#define glXQueryMaxSwapBarriersSGIX glproxy_glXQueryMaxSwapBarriersSGIX
#define glXQueryMaxSwapGroupsNV glproxy_glXQueryMaxSwapGroupsNV
#define glXQueryRendererIntegerMESA glproxy_glXQueryRendererIntegerMESA
#define glXQueryRendererStringMESA glproxy_glXQueryRendererStringMESA
#define glXQueryServerString glproxy_glXQueryServerString
#define glXQuerySwapGroupNV glproxy_glXQuerySwapGroupNV
#define glXQueryVersion glproxy_glXQueryVersion
#define glXQueryVideoCaptureDeviceNV glproxy_glXQueryVideoCaptureDeviceNV
#define glXReleaseBuffersMESA glproxy_glXReleaseBuffersMESA
#define glXReleaseTexImageEXT glproxy_glXReleaseTexImageEXT
#define glXReleaseVideoCaptureDeviceNV glproxy_glXReleaseVideoCaptureDeviceNV
#define glXReleaseVideoDeviceNV glproxy_glXReleaseVideoDeviceNV
#define glXReleaseVideoImageNV glproxy_glXReleaseVideoImageNV
#define glXResetFrameCountNV glproxy_glXResetFrameCountNV
#define glXSelectEvent glproxy_glXSelectEvent
#define glXSelectEventSGIX glproxy_glXSelectEventSGIX
#define glXSendPbufferToVideoNV glproxy_glXSendPbufferToVideoNV
#define glXSet3DfxModeMESA glproxy_glXSet3DfxModeMESA
#define glXSwapBuffers glproxy_glXSwapBuffers
#define glXSwapBuffersMscOML glproxy_glXSwapBuffersMscOML
#define glXSwapIntervalEXT glproxy_glXSwapIntervalEXT
#define glXSwapIntervalSGI glproxy_glXSwapIntervalSGI
#define glXUseXFont glproxy_glXUseXFont
#define glXWaitForMscOML glproxy_glXWaitForMscOML
#define glXWaitForSbcOML glproxy_glXWaitForSbcOML
#define glXWaitGL glproxy_glXWaitGL
#define glXWaitVideoSyncSGI glproxy_glXWaitVideoSyncSGI
#define glXWaitX glproxy_glXWaitX
