cmake_minimum_required (VERSION 3.0)
if (NOT CMAKE_VERSION VERSION_LESS "3.1")
    cmake_policy (SET CMP0054 OLD)
endif ()
if (WIN32 AND DEFINED GLPROXY_SHARED_LIB)
    get_filename_component (GLPROXY_SHARED_LIB_DIR "${GLPROXY_SHARED_LIB}" DIRECTORY)
    file (TO_NATIVE_PATH "${GLPROXY_SHARED_LIB_DIR}" GLPROXY_SHARED_LIB_DIR)
    if (NOT DEFINED ENV{PATH} OR ENV{PATH} STREQUAL "")
        set (ENV{PATH} "${GLPROXY_SHARED_LIB_DIR}")
    else ()
        set (ENV{PATH} "${GLPROXY_SHARED_LIB_DIR};$ENV{PATH}")
    endif ()
endif ()
execute_process (COMMAND "${GLPROXY_TEST_CMD}"
  RESULT_VARIABLE TEST_RETURN_VAL
  OUTPUT_VARIABLE TEST_OUTPUT_TEXT
  ERROR_VARIABLE TEST_ERROR_TEXT)
if (NOT TEST_RETURN_VAL EQUAL 0 AND NOT TEST_RETURN_VAL EQUAL 77)
    message (FATAL_ERROR "Test has failed with: stdout:${TEST_OUTPUT_TEXT} stderr:${TEST_ERROR_TEXT} retval:${TEST_RETURN_VAL}")
endif ()
