include_directories(
        . # top level
        ..
        src
        /usr/local/include/yaml-cpp
)

set(BRIDGE_FILES
        src/bridges.cpp
        src/bridges.hpp)

add_library(
        bridge ${BRIDGE_FILES})

target_link_libraries(bridge hiker)