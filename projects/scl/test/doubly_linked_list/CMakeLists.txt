add_executable(doubly_linked_list_tests test_doubly_linked_list.cpp templates.cpp)

target_link_libraries(doubly_linked_list_tests
	gtest_main 
	scl_lib
)

add_test(doubly_linked_list_tests doubly_linked_list_tests)
