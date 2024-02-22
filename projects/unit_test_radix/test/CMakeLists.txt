set(SOURCES 
	test_radix.cpp
)

add_executable(test_radix ${SOURCES})
target_link_libraries(test_radix 
	gtest_main 
	gmock_main 
	radix_sort_lib
)

add_test(test_radix test_radix)
