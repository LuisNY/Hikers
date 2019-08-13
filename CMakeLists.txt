cmake_minimum_required(VERSION 3.8)
project(hikers_program)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++17 -O0 -ggdb")

find_package(yaml-cpp REQUIRED)

# For 'make check' testing
set(CMAKE_CTEST_COMMAND ctest)
enable_testing()

add_subdirectory(main)
add_subdirectory(forest)
add_subdirectory(hikers)
add_subdirectory(bridges)

# Add dependencies for all tests
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS
        forest_test
        )


install(PROGRAMS bin/hikers_program DESTINATION bin)