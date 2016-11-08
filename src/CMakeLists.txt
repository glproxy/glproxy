set (glproxy_APIS gl egl wgl glx)

set (HEADERS "../include/glproxy/_common.h"
             "../include/glproxy/gl.h"
             "../include/glproxy/khrplatform.h"
             "dispatch_common.h")
set (SOURCES
  dispatch_common.c
  dispatch_generated.c
)

if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
  list (APPEND SOURCES "gen_dispatch.py")
endif ()

list (APPEND HEADERS "../include/glproxy/gl_generated.h"
                     "${CMAKE_CURRENT_BINARY_DIR}/../include/glproxy/config.h")

set (glproxy_COMPILE_DEFS PRIVATE glproxy_BUILDING_LIB)
if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
    set (glproxy_COMPILE_DEFS ${glproxy_COMPILE_DEFS} "inline=__inline")
endif ()
set (glproxy_TARGET_CODE ${SOURCES} ${HEADERS})

set (glproxy_TARGETS_BUILT_NAMES "")

if (glproxy_BUILD_SHARED)
    list (APPEND glproxy_TARGETS_BUILT_NAMES "${glproxy_TARGET_NAME}_shared")
    add_library ("${glproxy_TARGET_NAME}_shared" SHARED ${glproxy_TARGET_CODE})
    target_link_libraries ("${glproxy_TARGET_NAME}_shared" ${CMAKE_DL_LIBS})
    if (WIN32 OR ANDROID)
        set_target_properties ("${glproxy_TARGET_NAME}_shared" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}")
    else ()
        set_target_properties ("${glproxy_TARGET_NAME}_shared" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}")
    endif ()
    if (NOT ANDROID)
        set_target_properties("${glproxy_TARGET_NAME}_shared" PROPERTIES
                              VERSION    "${TARGET_VER}"
                              SOVERSION  "${TARGET_ABI_VER}")
    endif ()
    target_include_directories ("${glproxy_TARGET_NAME}_shared" PUBLIC ${glproxy_INCLUDE_DIRS})
    target_compile_definitions ("${glproxy_TARGET_NAME}_shared" PRIVATE ${glproxy_COMPILE_DEFS})
    set_target_properties ("${glproxy_TARGET_NAME}_shared" PROPERTIES C_VISIBILITY_PRESET hidden)
    if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
      target_compile_options ("${glproxy_TARGET_NAME}_shared" PRIVATE "-wd4996")
    endif ()

endif ()

if (glproxy_BUILD_STATIC)
    list (APPEND glproxy_TARGETS_BUILT_NAMES "${glproxy_TARGET_NAME}_static")
    add_library ("${glproxy_TARGET_NAME}_static" STATIC ${glproxy_TARGET_CODE})
    target_link_libraries ("${glproxy_TARGET_NAME}_static" ${CMAKE_DL_LIBS})
    if (WIN32)
        set_target_properties ("${glproxy_TARGET_NAME}_static" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_static_${TARGET_ABI_VER}")
    else ()
        set_target_properties ("${glproxy_TARGET_NAME}_static" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}")
    endif ()
    target_include_directories ("${glproxy_TARGET_NAME}_static" PUBLIC ${glproxy_INCLUDE_DIRS})
    target_compile_definitions ("${glproxy_TARGET_NAME}_static" PRIVATE ${glproxy_COMPILE_DEFS} glproxy_STATIC_LIB)
    if (HONOR_VISIBILITY)
        set_target_properties ("${glproxy_TARGET_NAME}_static" PROPERTIES C_VISIBILITY_PRESET hidden)
    elseif ((CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_GCC) OR (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_CLANG))
        target_compile_options ("${glproxy_TARGET_NAME}_static" PRIVATE "-fvisibility=hidden")
    endif ()
    if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
      target_compile_options ("${glproxy_TARGET_NAME}_static" PRIVATE "-wd4996")
    endif ()
endif ()

install (FILES ${HEADERS} DESTINATION "include/glproxy")
install (TARGETS ${glproxy_TARGETS_BUILT_NAMES}
           RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
           LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
           ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
    install (FILES "${CMAKE_CURRENT_BINARY_DIR}/Debug/${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}.pdb"
             DESTINATION lib  CONFIGURATIONS Debug)
endif ()
