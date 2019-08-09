include_directories(
        .# top level
        ..
        src
        /usr/local/include/yaml-cpp
)

add_executable(hikers_program src/main.cpp)

target_link_libraries(hikers_program hiker bridge yaml-cpp)