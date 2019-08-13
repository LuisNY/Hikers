set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(forest_test EXCLUDE_FROM_ALL forest_test.cpp)
target_link_libraries(forest_test forest stdc++fs)
add_test(NAME forest_test COMMAND forest_test)