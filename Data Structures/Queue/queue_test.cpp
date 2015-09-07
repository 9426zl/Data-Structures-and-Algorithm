//
//   Queue_test.cpp
//   Queue test
//
//   Created by Baldwin Lou on 08/30/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> iqueue;
	int cursor = 1;
	
	while(cursor < 10){
		iqueue.enqueue(cursor);
		++cursor;
	}
	std::cout << "Enqueue operation is done, queue size is "
	          << iqueue.queue_size() << std::endl;
				
	while(cursor > 1){
		std::cout << iqueue.dequeue() << " ";
		--cursor;
	}
	std::cout << "\nDequeue operation is done, queue size is "
	          << iqueue.queue_size() << std::endl;

	return 0;
}
