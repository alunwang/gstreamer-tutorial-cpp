set(SRC_LIST basic1.cpp)

add_executable(basic1 ${SRC_LIST})
target_link_libraries(basic1 PkgConfig::GSTREAMER)