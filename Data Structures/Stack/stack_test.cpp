//
//   stack_test.cpp
//   Stack test
//
//   Created by Baldwin Lou on 08/30/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> istack;
	std::cout << "Is the stack empty " << istack.is_empty() << std::endl;
	
	int i = 1;
	while (i < 10)
	{
		istack.push(i);
		++i; 
	}
	
	//--i;
	while (i > 0)
	{
		std::cout << istack.pop() << " ";
		--i;
	}
	std::cout << "\n" << "Done" << std::endl;
	
	istack.delete_stack();
	
	return 0;
}
