//
//   splay_tree_test.cpp
//   Splay_tree test
//
//   Created by Baldwin Lou on 09/05/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "Splay_tree.h"

int main()
{
	Splay_tree<int> splaytree;
	
	splaytree.insert(3);
	splaytree.insert(1);
	splaytree.insert(7);
	splaytree.insert(5);
	splaytree.insert(4);
	
	splaytree.print(std::cout);
	std::cout << "\nThe tree depth is " 
			  << splaytree.tree_depth() << std::endl;
	
	avltree.delete_element(3);
	
	splaytree.print(std::cout);
	std::cout << "\nThe tree depth is " 
			  << splaytree.tree_depth() << std::endl;
	
	return 0;
}
