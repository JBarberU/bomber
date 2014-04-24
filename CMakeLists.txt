cmake_minimum_required(VERSION 2.8)

project(bomber)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules)

find_package(SFML REQUIRED COMPONENTS graphics window system)

add_subdirectory(src)
