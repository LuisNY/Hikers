include_directories(
        . # top level
        ..
        src
        /usr/local/include/yaml-cpp
)

set(FOREST_FILES
        src/forest.cpp
        src/forest.h)

add_library(
        forest ${FOREST_FILES})

target_link_libraries(forest bridge hiker)