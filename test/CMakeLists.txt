# for each test add 2 lines, add_executable and target_link_libraries
# add_executable(test_name file_test.c)
# target_link_libraries(test_name library_name)
add_executable(create_queue queue/create_queue.c)
target_link_libraries(create_queue queue)
add_executable(push_pop_queue queue/push_pop_queue.c)
target_link_libraries(push_pop_queue queue)
