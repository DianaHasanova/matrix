cmake_minimum_required(VERSION 3.20)
project(untitled4 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled4 main.c)

add_subdirectory(libs)
target_link_libraries(untitled4 algorithms)
target_link_libraries(untitled4 data_structures)