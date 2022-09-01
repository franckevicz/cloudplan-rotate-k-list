cmake_minimum_required(VERSION 3.10)

project(Reverse_list VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp src/RotateKList.cpp)
set(CMAKE_BINARY_DIR ./binaries)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}) 

add_executable(reverse_nsection_list ${SOURCE_FILES})