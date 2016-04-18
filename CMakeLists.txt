cmake_minimum_required(VERSION 3.5)
project(cpp_bht_sose16_a02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp fixed_point.cpp fixed_point.h)
add_executable(cpp_bht_sose16_a02 ${SOURCE_FILES})