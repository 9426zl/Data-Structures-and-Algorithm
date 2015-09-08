//
//   binomialqueue_test.cpp
//   Binary Queue test
//
//   Created by Baldwin Lou on 09/07/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "BinomialQueue.h"

int main()
{
	Bin_queue<int> bqueue(19);
	Bin_queue<int> bqueue2(19);
	Bin_queue<int> *bq2 = &bqueue2;
	Bin_node<int>* tmp;
	
	
	bqueue.insert(19);
	bqueue.insert(20);
	bqueue.insert(11);
	
	bqueue2.insert(18);
	bqueue2.insert(1);
	bqueue2.insert(5);
	
	bqueue.merge(bq2);
	
	tmp = bqueue.find_min();
	bqueue.delete_min();
	
	return 0;
}
