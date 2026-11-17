#include <gtest/gtest.h>

#include "sort.hpp"

TEST(Equal, without_equal_elemens) {
	int actual[] = {1, 8, 2, 5, 3, 11};
	const int actual_size = sizeof(actual) / sizeof(actual[0]);
	int expected[] = {1, 2, 3, 5, 8, 11};
	
	biv::bubble_sort_classic(actual, actual_size);
	
	for (int i = 0; i < actual_size; i++) {
		ASSERT_EQ(expected[i], actual[i]) 
			<< "Массив ожидаемый и отсортировнный отличаются в элементе с индексом "
			<< i << ": "
			<< "есть " << actual[i]
			<< ", а должен быть " << expected[i];
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
