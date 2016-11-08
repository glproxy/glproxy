set (GLPROXY_APIS gl egl wgl glx)

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

list (APPEND HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/../include/glproxy/gl_generated.h")
list (APPEND HEADERS "${CMAKE_CURRENT_BINARY_DIR}/../include/glproxy/config.h")

set (GLPROXY_COMPILE_DEFS PRIVATE GLPROXY_BUILDING_LIB)
if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
    set (GLPROXY_COMPILE_DEFS ${GLPROXY_COMPILE_DEFS} "inline=__inline")
endif ()
set (GLPROXY_TARGET_CODE ${SOURCES} ${HEADERS})

set (GLPROXY_TARGETS_BUILT_NAMES "")

if (GLPROXY_BUILD_SHARED)
    list (APPEND GLPROXY_TARGETS_BUILT_NAMES "${GLPROXY_TARGET_NAME}_shared")
    add_library ("${GLPROXY_TARGET_NAME}_shared" SHARED ${GLPROXY_TARGET_CODE})
    target_link_libraries ("${GLPROXY_TARGET_NAME}_shared" ${CMAKE_DL_LIBS})
    if (WIN32 OR ANDROID)
        set_target_properties ("${GLPROXY_TARGET_NAME}_shared" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}")
    else ()
        set_target_properties ("${GLPROXY_TARGET_NAME}_shared" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}")
    endif ()
    if (NOT ANDROID)
        set_target_properties("${GLPROXY_TARGET_NAME}_shared" PROPERTIES
                              VERSION    "${TARGET_VER}"
                              SOVERSION  "${TARGET_ABI_VER}")
    endif ()
    target_include_directories ("${GLPROXY_TARGET_NAME}_shared" PUBLIC ${GLPROXY_INCLUDE_DIRS})
    target_compile_definitions ("${GLPROXY_TARGET_NAME}_shared" PRIVATE ${GLPROXY_COMPILE_DEFS})
    set_target_properties ("${GLPROXY_TARGET_NAME}_shared" PROPERTIES C_VISIBILITY_PRESET hidden)
    if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
      target_compile_options ("${GLPROXY_TARGET_NAME}_shared" PRIVATE "-wd4996")
    endif ()

endif ()

if (GLPROXY_BUILD_STATIC)
    list (APPEND GLPROXY_TARGETS_BUILT_NAMES "${GLPROXY_TARGET_NAME}_static")
    add_library ("${GLPROXY_TARGET_NAME}_static" STATIC ${GLPROXY_TARGET_CODE})
    target_link_libraries ("${GLPROXY_TARGET_NAME}_static" ${CMAKE_DL_LIBS})
    if (WIN32)
        set_target_properties ("${GLPROXY_TARGET_NAME}_static" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_static_${TARGET_ABI_VER}")
    else ()
        set_target_properties ("${GLPROXY_TARGET_NAME}_static" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}")
    endif ()
    target_include_directories ("${GLPROXY_TARGET_NAME}_static" PUBLIC ${GLPROXY_INCLUDE_DIRS})
    target_compile_definitions ("${GLPROXY_TARGET_NAME}_static" PRIVATE ${GLPROXY_COMPILE_DEFS} GLPROXY_STATIC_LIB)
    if (HONOR_VISIBILITY)
        set_target_properties ("${GLPROXY_TARGET_NAME}_static" PROPERTIES C_VISIBILITY_PRESET hidden)
    elseif ((CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_GCC) OR (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_CLANG))
        target_compile_options ("${GLPROXY_TARGET_NAME}_static" PRIVATE "-fvisibility=hidden")
    endif ()
    if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
      target_compile_options ("${GLPROXY_TARGET_NAME}_static" PRIVATE "-wd4996")
    endif ()
endif ()

install (FILES ${HEADERS} DESTINATION "include/glproxy")
install (TARGETS ${GLPROXY_TARGETS_BUILT_NAMES}
           RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
           LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
           ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
    install (FILES "${CMAKE_CURRENT_BINARY_DIR}/Debug/${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}.pdb"
             DESTINATION lib  CONFIGURATIONS Debug)
endif ()
