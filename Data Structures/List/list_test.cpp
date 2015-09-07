//
//   list_test.cpp
//   Doubly linked list test
//
//   Created by Baldwin Lou on 08/28/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "List.h"

int main()
{
	List<int> ilist;
	int size_beg = ilist.list_size();
	int cursor = 1;
	int tmp ;
	
	std::cout << size_beg << "\n";
	while(cursor < 10){
		ilist.push_back(cursor);
		std::cout << cursor << " ";
		++cursor;	
	}
	std::cout << "\n" << std::endl;
	
	cursor = 9;
	while(cursor > 0 ){
		ilist.push_front(cursor);
		std::cout << cursor << " ";
		--cursor;
	}	
	int size_end = ilist.list_size();
	std::cout << "\n" << size_end << "\n" << std::endl;
	
	while(cursor < 9){
		tmp = ilist.pop_back();
		std::cout << tmp << " ";
		++cursor;	
	}
	
	while(cursor > 0 ){
		tmp = ilist.pop_front();
		std::cout << tmp << " ";
		--cursor;
	}
	
	std::cout << std::endl;
	
	ilist.delete_list();
	
	return 0;	
}
/*
	
	
*/
