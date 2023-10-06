cmake_minimum_required(VERSION 3.22.1)

project(gstreamer-tutorial-cpp)

include_directories(inc)

# Gstreamer library
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED IMPORTED_TARGET
    gstreamer-1.0
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/obj) # All objects are put here

add_subdirectory(src)