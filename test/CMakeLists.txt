if (glproxy_BUILD_TESTS)

    if (glproxy_BUILD_SHARED)
        set (TESTS_TARGET_NAME "${glproxy_TARGET_NAME}_shared")
    else ()
        set (TESTS_TARGET_NAME "${glproxy_TARGET_NAME}_static")
    endif ()

    if (glproxy_SUPPORT_EGL)
        if (EGL_FOUND)
            set (glproxy_BUILD_EGL_TESTS TRUE)
            set (glproxy_EGL_TESTS_COMMON egl_common.c egl_common.h)
        else ()
            set (glproxy_BUILD_EGL_TESTS FALSE)
            message (WARNING "EGL not found - EGL tests will not be built!")
        endif ()
    endif ()
    if (glproxy_SUPPORT_GLX)
        set (glproxy_GLX_TESTS_COMMON glx_common.c glx_common.h)
    endif ()
    if (glproxy_SUPPORT_WGL)
        set (glproxy_WGL_TESTS_COMMON wgl_common.c wgl_common.h)
    endif ()

    set (glproxy_LINKAGE_TYPE_SHARED SHARED)
    set (glproxy_LINKAGE_TYPE_STATIC STATIC)
    
    function (glproxy_add_test glproxy_TEST_NAME glproxy_TEST_CODE)
      # Additional optional arguments: "glproxy_TEST_DEPS glproxy_TEST_COMPILE_DEFS glproxy_TEST_LINK_FLAGS"
      #                                "glproxy_LINKAGE_TYPE"
      
        if (ARGC GREATER 2)
            set (glproxy_TEST_DEPS "${ARGV2}")
        else ()
            set (glproxy_TEST_DEPS "")
        endif ()
        if (ARGC GREATER 3)
            set (glproxy_TEST_COMPILE_DEFS "${ARGV3}")
        else ()
            set (glproxy_TEST_COMPILE_DEFS "")
        endif ()
        if (ARGC GREATER 4)
            set (glproxy_TEST_LINK_FLAGS "${ARGV4}")
        else ()
            set (glproxy_TEST_LINK_FLAGS "")
        endif ()
        if (ARGC GREATER 5)
            set (glproxy_TEST_LINKAGE_TYPE "${ARGV5}")
        else ()
            set (glproxy_TEST_LINKAGE_TYPE BOTH)
        endif ()
        
        if (glproxy_BUILD_SHARED AND NOT glproxy_TEST_LINKAGE_TYPE STREQUAL glproxy_LINKAGE_TYPE_STATIC)
            set (glproxy_TEST_TARGET_NAME "test_shared_${glproxy_TEST_NAME}")
            add_executable (${glproxy_TEST_TARGET_NAME} ${glproxy_TEST_CODE})
            target_link_libraries (${glproxy_TEST_TARGET_NAME} "${glproxy_TARGET_NAME}_shared" ${glproxy_TEST_DEPS})
            target_compile_definitions (${glproxy_TEST_TARGET_NAME} PRIVATE
                                        ${glproxy_TEST_COMPILE_DEFS})
            target_include_directories (${glproxy_TEST_TARGET_NAME} PRIVATE ${glproxy_INCLUDE_DIRS})
            set_target_properties (${glproxy_TEST_TARGET_NAME} PROPERTIES
                                   LINK_FLAGS "${glproxy_TEST_LINK_FLAGS}")
            add_test (NAME "${glproxy_TEST_TARGET_NAME}"
                      COMMAND "${CMAKE_COMMAND}"
                          "-Dglproxy_TEST_CMD=$<TARGET_FILE:${glproxy_TEST_TARGET_NAME}>"
                          "-Dglproxy_SHARED_LIB=$<TARGET_FILE:${glproxy_TARGET_NAME}_shared>"
                          "-P" "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/glproxy_run_test_wrapper.cmake")
        endif ()
        
        if (glproxy_BUILD_STATIC AND NOT glproxy_TEST_LINKAGE_TYPE STREQUAL glproxy_LINKAGE_TYPE_SHARED)
            set (glproxy_TEST_TARGET_NAME "test_static_${glproxy_TEST_NAME}")
            add_executable (${glproxy_TEST_TARGET_NAME} ${glproxy_TEST_CODE})
            target_link_libraries (${glproxy_TEST_TARGET_NAME} "${glproxy_TARGET_NAME}_static" ${glproxy_TEST_DEPS})
            target_compile_definitions (${glproxy_TEST_TARGET_NAME} PRIVATE
                                        ${glproxy_TEST_COMPILE_DEFS} glproxy_STATIC_LIB)
            target_include_directories (${glproxy_TEST_TARGET_NAME} PRIVATE ${glproxy_INCLUDE_DIRS})
            set_target_properties (${glproxy_TEST_TARGET_NAME} PROPERTIES
                                   LINK_FLAGS "${glproxy_TEST_LINK_FLAGS}")
            add_test (NAME "${glproxy_TEST_TARGET_NAME}"
                      COMMAND "${CMAKE_COMMAND}"
                          "-Dglproxy_TEST_CMD=$<TARGET_FILE:${glproxy_TEST_TARGET_NAME}>"
                          "-P" "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/glproxy_run_test_wrapper.cmake")
        endif ()
        
    endfunction ()

    if (glproxy_BUILD_EGL_TESTS AND X11_FOUND)

        glproxy_add_test (egl_has_extension_nocontext "${glproxy_EGL_TESTS_COMMON};egl_has_extension_nocontext.c"
                        "${X11_LIBRARIES}")
        glproxy_add_test (egl_gl "${glproxy_EGL_TESTS_COMMON};egl_gl.c" "${X11_LIBRARIES}")
        if (GLES_V1_FOUND)
            glproxy_add_test (egl_gles1_without_glx "${glproxy_EGL_TESTS_COMMON};egl_without_glx.c" "${X11_LIBRARIES}"
                            "GLES_VERSION=1")
        endif ()
        if (GLES_V2_FOUND)
            glproxy_add_test (egl_gles2_without_glx "${glproxy_EGL_TESTS_COMMON};egl_without_glx.c" "${X11_LIBRARIES}"
                            "GLES_VERSION=2")
        endif ()
    endif()
    if (glproxy_BUILD_EGL_TESTS AND WIN32)
        glproxy_add_test (egl_has_extension_nocontext "${glproxy_EGL_TESTS_COMMON};egl_has_extension_nocontext.c"
                        "${X11_LIBRARIES}")
        glproxy_add_test (egl_gles2_without_glx "${glproxy_EGL_TESTS_COMMON};egl_without_glx.c" "${X11_LIBRARIES}"
                "GLES_VERSION=2")
    endif()
    
    if (glproxy_BUILD_EGL_TESTS AND glproxy_SUPPORT_GLX AND NOT APPLE)
    
        #glproxy_add_test (egl_and_glx_different_pointers "${glproxy_EGL_TESTS_COMMON};${glproxy_GLX_TESTS_COMMON};egl_and_glx_different_pointers.c;dlwrap.c;dlwrap.h" "${X11_LIBRARIES}" "USE_EGL;USE_GLX" "-rdynamic")
        glproxy_add_test (egl_different_pointers
          "${glproxy_EGL_TESTS_COMMON};${glproxy_GLX_TESTS_COMMON};egl_and_glx_different_pointers.c;dlwrap.c;dlwrap.h"
          "${X11_LIBRARIES}" "USE_EGL" "-rdynamic")
        glproxy_add_test (glx_different_pointers
          "${glproxy_EGL_TESTS_COMMON};${glproxy_GLX_TESTS_COMMON};egl_and_glx_different_pointers.c;dlwrap.c;dlwrap.h"
          "${X11_LIBRARIES}" "USE_GLX" "-rdynamic")
    endif ()

    if (glproxy_SUPPORT_GLX)
    
        if (NOT APPLE)
            glproxy_add_test (glx_alias_prefer_same_name
              "${glproxy_GLX_TESTS_COMMON};glx_alias_prefer_same_name.c;dlwrap.c;dlwrap.h" "${X11_LIBRARIES}"
              "" "-rdynamic")
            if (GLES_V2_FOUND)
                glproxy_add_test (test_glx_gles2
                  "${glproxy_GLX_TESTS_COMMON};glx_gles2.c;dlwrap.c;dlwrap.h" "${X11_LIBRARIES}" "" "-rdynamic")
            endif ()
        endif ()
        
        glproxy_add_test (test_glx_beginend "${glproxy_GLX_TESTS_COMMON};glx_beginend.c"
                        "${OPENGL_gl_LIBRARY};${X11_LIBRARIES}")
        glproxy_add_test (glx_public_api "${glproxy_GLX_TESTS_COMMON};glx_public_api.c" "${X11_LIBRARIES}")
        glproxy_add_test (glx_public_api_core "${glproxy_GLX_TESTS_COMMON};glx_public_api_core.c" "${X11_LIBRARIES}")
        glproxy_add_test (glx_getprocaddress_nocontext
          "${glproxy_GLX_TESTS_COMMON};glx_glxgetprocaddress_nocontext.c" "${X11_LIBRARIES}")
        glproxy_add_test (glx_has_extension_nocontext "${glproxy_GLX_TESTS_COMMON};glx_has_extension_nocontext.c"
                        "${X11_LIBRARIES}")

        glproxy_add_test (glx_shared_znow "${glproxy_GLX_TESTS_COMMON};glx_static.c"
                        "${X11_LIBRARIES}" "" "-Wl,-z,now" SHARED)
        glproxy_add_test (glx_static "${glproxy_GLX_TESTS_COMMON};glx_static.c"
                        "${X11_LIBRARIES}" "NEEDS_TO_BE_STATIC" "" STATIC)
    endif ()

	glproxy_add_test (headerguards headerguards.c)
	glproxy_add_test (miscdefines miscdefines.c)

    if (glproxy_SUPPORT_WGL)
        glproxy_add_test (wgl_core_and_exts "${glproxy_WGL_TESTS_COMMON};wgl_core_and_exts.c")
		glproxy_add_test (wgl_per_context_funcptrs "${glproxy_WGL_TESTS_COMMON};wgl_per_context_funcptrs.c")
		glproxy_add_test (wgl_usefontbitmaps_ascii "${glproxy_WGL_TESTS_COMMON};wgl_usefontbitmaps.c")
		glproxy_add_test (wgl_usefontbitmaps_unicode "${glproxy_WGL_TESTS_COMMON};wgl_usefontbitmaps.c"
                                "" "_UNICODE;UNICODE")
	endif ()

endif ()
