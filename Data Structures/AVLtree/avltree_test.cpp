//
//   avltree_test.cpp
//   AVLTree test
//
//   Created by Baldwin Lou on 09/05/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "AVLtree.h"

int main()
{
	AVLtree<int> avltree;
	
	avltree.insert(3);
	avltree.insert(3);
	avltree.insert(1);
	avltree.insert(7);
	avltree.insert(5);
	avltree.insert(4);
	
	avltree.print(std::cout);
	std::cout << "\nThe tree depth is " 
			  << avltree.tree_depth() << std::endl;
	
	avltree.delete_element(3);
	
	avltree.print(std::cout);
	std::cout << "\nThe tree depth is " 
			  << avltree.tree_depth() << std::endl;
	
	return 0;
}
