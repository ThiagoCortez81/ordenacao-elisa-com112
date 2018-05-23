cmake_minimum_required(VERSION 3.3)
project(COM112)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES com112_main.c com112_file.c com112_file.h com112_sort.c com112_sort.h)
add_executable(COM112 ${SOURCE_FILES})