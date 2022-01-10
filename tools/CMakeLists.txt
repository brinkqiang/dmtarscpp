cmake_minimum_required(VERSION 3.2)
project(tools)

include_directories(${util_SOURCE_DIR}/include)

link_libraries(tarsutil)

function(tars2language TARGET)
    #set(EXECUTABLE_OUTPUT_PATH "${EXECUTABLE_OUTPUT_PATH}")
    #set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
    #foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        #string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
        #set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${EXECUTABLE_OUTPUT_PATH})
    #endforeach()

    include_directories(${PROJECT_SOURCE_DIR}/tarsparse)

    aux_source_directory(. DIR_SRCS)

    link_libraries(tarsparse)

    add_executable(${TARGET} ${DIR_SRCS})

    install(TARGETS ${TARGET}
            RUNTIME DESTINATION tools)
endfunction()

IF(UNIX)
add_subdirectory(tarsgrammar)
ENDIF(UNIX)

add_subdirectory(tarsparse)
add_subdirectory(tarsmerge)
add_subdirectory(tars2cpp)
add_subdirectory(tars2python)
add_subdirectory(tars2cs)
add_subdirectory(tars2c)
add_subdirectory(tars2oc)
add_subdirectory(tars2php)
add_subdirectory(tars2android)
add_subdirectory(tars2node)
add_subdirectory(tars2case)

IF(TARS_PROTOBUF)
    add_subdirectory(pb2tarscpp)
ENDIF()
