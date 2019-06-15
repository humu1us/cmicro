# for each test add 2 lines, add_executable and target_link_libraries
# add_executable(test_name file_test.cc)
# target_link_libraries(test_name library_name)
add_executable(create_buffer buffer/create_buffer.cc)
target_link_libraries(create_buffer buffer)
target_link_libraries(create_buffer message)
add_executable(push_pop buffer/push_pop.cc)
target_link_libraries(push_pop buffer)
target_link_libraries(push_pop message)
