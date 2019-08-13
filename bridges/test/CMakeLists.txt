set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(bridge_test EXCLUDE_FROM_ALL bridge_test.cpp)
target_link_libraries(bridge_test bridge)
add_test(NAME bridge_test COMMAND bridge_test)