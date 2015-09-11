//
//   sorting_test.cpp
//   Sorting algoithm test
//
//   Created by Baldwin Lou on 09/09/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//


#include <iostream>
#include "Sorting.h"

int main()
{
	int A[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
	
	//insertion_sort<int>(A, 10);
	//shellsort(A, 10);
	//heapsort(A, 10);
	//mergesort(A, 10);
	quicksort(A, 10);

	for (auto i : A)
		std::cout << i << " ";
	
	std::cout <<std::endl;
}
