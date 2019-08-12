include_directories(
        . # top level
        ..
        src
        /usr/local/include/yaml-cpp
)

set(BRIDGE_FILES
        src/bridge.cpp
        src/bridge.hpp)

add_library(
        bridge ${BRIDGE_FILES})

target_link_libraries(bridge hiker)