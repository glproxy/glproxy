set (EPOXY_APIS gl egl wgl glx)

set (HEADERS "../include/epoxy/_common.h"
             "../include/epoxy/gl.h"
             "../include/epoxy/khrplatform.h"
             "dispatch_common.h")
set (SOURCES dispatch_common.c
 dispatch_generated.c)

list (APPEND HEADERS "../include/epoxy/gl_generated.h"
                     "${CMAKE_CURRENT_BINARY_DIR}/../include/epoxy/config.h")

set (EPOXY_COMPILE_DEFS PRIVATE EPOXY_BUILDING_LIB)
if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
    set (EPOXY_COMPILE_DEFS ${EPOXY_COMPILE_DEFS} "inline=__inline")
endif ()
set (EPOXY_TARGET_CODE ${SOURCES} ${HEADERS})

set (EPOXY_TARGETS_BUILT_NAMES "")

if (EPOXY_BUILD_SHARED)
    list (APPEND EPOXY_TARGETS_BUILT_NAMES "${EPOXY_TARGET_NAME}_shared")
    add_library ("${EPOXY_TARGET_NAME}_shared" SHARED ${EPOXY_TARGET_CODE})
    target_link_libraries ("${EPOXY_TARGET_NAME}_shared" ${CMAKE_DL_LIBS})
    if (WIN32 OR ANDROID)
        set_target_properties ("${EPOXY_TARGET_NAME}_shared" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}")
    else ()
        set_target_properties ("${EPOXY_TARGET_NAME}_shared" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}")
    endif ()
    if (NOT ANDROID)
        set_target_properties("${EPOXY_TARGET_NAME}_shared" PROPERTIES
                              VERSION    "${TARGET_VER}"
                              SOVERSION  "${TARGET_ABI_VER}")
    endif ()
    target_include_directories ("${EPOXY_TARGET_NAME}_shared" PUBLIC ${EPOXY_INCLUDE_DIRS})
    target_compile_definitions ("${EPOXY_TARGET_NAME}_shared" PRIVATE ${EPOXY_COMPILE_DEFS})
    set_target_properties ("${EPOXY_TARGET_NAME}_shared" PROPERTIES C_VISIBILITY_PRESET hidden)
endif ()

if (EPOXY_BUILD_STATIC)
    list (APPEND EPOXY_TARGETS_BUILT_NAMES "${EPOXY_TARGET_NAME}_static")
    add_library ("${EPOXY_TARGET_NAME}_static" STATIC ${EPOXY_TARGET_CODE})
    target_link_libraries ("${EPOXY_TARGET_NAME}_static" ${CMAKE_DL_LIBS})
    if (WIN32)
        set_target_properties ("${EPOXY_TARGET_NAME}_static" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_static_${TARGET_ABI_VER}")
    else ()
        set_target_properties ("${EPOXY_TARGET_NAME}_static" PROPERTIES
                               OUTPUT_NAME "${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}")
    endif ()
    target_include_directories ("${EPOXY_TARGET_NAME}_static" PUBLIC ${EPOXY_INCLUDE_DIRS})
    target_compile_definitions ("${EPOXY_TARGET_NAME}_static" PRIVATE ${EPOXY_COMPILE_DEFS} EPOXY_STATIC_LIB)
    if (HONOR_VISIBILITY)
        set_target_properties ("${EPOXY_TARGET_NAME}_static" PROPERTIES C_VISIBILITY_PRESET hidden)
    elseif ((CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_GCC) OR (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_CLANG))
        target_compile_options ("${EPOXY_TARGET_NAME}_static" PRIVATE "-fvisibility=hidden")
    endif ()
endif ()

install (FILES ${HEADERS} DESTINATION "include/epoxy")
install (TARGETS ${EPOXY_TARGETS_BUILT_NAMES}
           RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
           LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
           ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
if (CMAKE_C_COMPILER_ID STREQUAL COMPILER_ID_MSVC)
    install (FILES "${CMAKE_CURRENT_BINARY_DIR}/Debug/${TARGET_OUTPUT_NAME}_${TARGET_ABI_VER}.pdb"
             DESTINATION lib  CONFIGURATIONS Debug)
endif ()
