cmake_minimum_required(VERSION 3.8)
project(hikers_program)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++17 -O0 -ggdb")

find_package(yaml-cpp REQUIRED)

add_subdirectory(main)
add_subdirectory(hikers)
add_subdirectory(bridges)

install(PROGRAMS bin/hikers_program DESTINATION bin)