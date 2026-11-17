set(SOURCES 
	test_bubble_sort_classic.cpp
)

add_executable(test_bubble_sort_classic ${SOURCES})

target_link_libraries(test_bubble_sort_classic 
	gtest
	${SORT_LIB}
)

add_test(test_bubble_sort_classic test_bubble_sort_classic)
