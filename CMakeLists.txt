cmake_minimum_required(VERSION 2.8.4)
project(data_structure_and_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(data_structure_and_algorithm ${SOURCE_FILES})
add_subdirectory(list_stack_queue tests)