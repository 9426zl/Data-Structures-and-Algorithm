//
//   binarysearchtree_test.cpp
//   BinarySearchTree test
//
//   Created by Baldwin Lou on 09/01/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	BSTree<int> bstree;
	TreeNode<int>* ptn;

	bstree.insert(3);
	bstree.insert(3);
	bstree.insert(1);
	bstree.insert(7);
	bstree.insert(5);
	bstree.insert(8);
	
	bstree.print(std::cout);
	
	ptn = bstree.find_min(0);
	std::cout << "\nThe minimum element is " << ptn->element << std::endl;
	
	ptn = bstree.find_max(0);
	std::cout << "\nThe maximum element is "  << ptn->element << std::endl;
	
	bstree.delete_element(3);
	bstree.print(std::cout);

	return 0;
}
