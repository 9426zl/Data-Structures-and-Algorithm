//
//   binaryheap_test.cpp
//   Binary Heap test
//
//   Created by Baldwin Lou on 09/07/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "BinaryHeap.h"

int main()
{
	Binary_heap<int> bh;
	
	std::cout << bh.is_empty() << std::endl;
	
	bh.insert(6);
	bh.insert(1);
	bh.insert(3);
	bh.insert(4);
	
	auto i = bh.delete_min();
	std::cout << i << std::endl;
	
	bh.delete_element(5);
	bh.delete_element(6);
	bh.make_empty();
	
	return 0;	
}
