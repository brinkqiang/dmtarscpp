cmake_minimum_required(VERSION 3.2)

project(tars-cpp)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
#-------------------------------------------------------------------

if("${TARS_CPP_COMMON}" STREQUAL "")

    set(TARS_CPP_COMMON "1")

    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/GenVersion.cmake")

    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Common.cmake")

    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/BuildTarsCpp.cmake")

    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Thirdparty.cmake")

    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/ParseAsm.cmake")

endif()

# set(major "")
# set(minor "")
# set(patch "")
# get_version(major minor patch)

# set(TARS_VERSION ${major}.${minor}.${patch})

add_definitions(-DTARS_VERSION="${TARS_VERSION}")

message("TARS_VERSION:              ${TARS_VERSION}")

set(CLEAR_INCLUDE "clear-install.cmake")
FILE(WRITE ${CLEAR_INCLUDE} "EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_PREFIX}/include)\n")
install(SCRIPT ${CLEAR_INCLUDE})

#-------------------------------------------------------------------

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/util/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/servant)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/servant/protocol)

IF(WIN32)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/util/src/epoll_windows)
ENDIF()

add_subdirectory(util)
add_subdirectory(tools)
add_subdirectory(servant)

IF (NOT ${ONLY_LIB})
add_subdirectory(examples)
add_subdirectory(unit-test)
ENDIF()


