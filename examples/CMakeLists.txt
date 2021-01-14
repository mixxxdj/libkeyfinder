cmake_minimum_required(VERSION 3.1.0)
project(KeyFinderBasicExample)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

find_package(KeyFinder CONFIG REQUIRED)
add_executable(basic basic.cpp)
target_link_libraries(basic PRIVATE KeyFinder::keyfinder)
