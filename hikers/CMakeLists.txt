include_directories(
        . # top level
        ..
        src
        /usr/local/include/yaml-cpp
)

set(HIKER_FILES
        src/hiker.cpp
        src/hiker.hpp)

add_library(
        hiker ${HIKER_FILES})

target_link_libraries(hiker yaml-cpp)