set(PROJECT_NAME "Better Dynamic Libraries")
set(PROJECT_DESCRIPTION "project" )
set(PROJECT_VERSION 0.1.0)

# setup Docme project
cmake_minimum_required(VERSION 3.31)
project(
    ${PROJECT_NAME} 
    VERSION ${PROJECT_VERSION}
    DESCRIPTION ${PROJECT_DESCRIPTION}
    LANGUAGES CXX 
)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")

add_library(BetterDynamicLibraries STATIC
    "${ROOT_DIR}/better dynamic libraries/source/dynamicLibraries.cpp"
)
target_include_directories(BetterDynamicLibraries PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/better dynamic libraries/source"
    "${ROOT_DIR}/better dynamic libraries/header"
    "${ROOT_DIR}/better dynamic libraries"
)
set_target_properties(BetterDynamicLibraries PROPERTIES
    OUTPUT_NAME "dynamicLibraries"
    PREFIX ""
    SUFFIX ".lib"
    ARCHIVE_OUTPUT_DIRECTORY "${ROOT_DIR}/binary"
)