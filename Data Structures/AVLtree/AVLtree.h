//
//   AVLtree.h
//   AVL tree realization
//
//   Created by Baldwin Lou on 09/05/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef AVLTREE_H
#define AVLTREE_H 

#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

template<typename T>
class AVLtree : public BSTree<T> {
public:
	TreeNode<T>* single_rotate_with_left(TreeNode<T>* ptn);
	TreeNode<T>* single_rotate_with_right(TreeNode<T>* ptn);
	TreeNode<T>* double_rotate_with_left(TreeNode<T>* ptn);
	TreeNode<T>* double_rotate_with_right(TreeNode<T>* ptn);
		
	void insert(const T& elem) override;
	void delete_element(const T& elem) override;
	
private:
	TreeNode<T>* insert(const T& elem, TreeNode<T>* ptn);
	TreeNode<T>* delete_element(const T& elem, TreeNode<T>* ptn);	
}; 

template<typename T>
TreeNode<T>* AVLtree<T>::single_rotate_with_left(TreeNode<T>* ptn)
{
	TreeNode<T>* lptn = ptn->lchild;
	ptn->lchild = lptn->rchild;
	lptn->rchild = ptn;
	return lptn;
}

template<typename T>
TreeNode<T>* AVLtree<T>::single_rotate_with_right(TreeNode<T>* ptn)
{
	TreeNode<T>* rptn = ptn->rchild;
	ptn->rchild = rptn->lchild;
	rptn->lchild = ptn;
	return rptn;
}

template<typename T>
TreeNode<T>* AVLtree<T>::double_rotate_with_left(TreeNode<T>* ptn)
{
	ptn = single_rotate_with_right(ptn->lchild);
	return single_rotate_with_left(ptn);
}

template<typename T>
TreeNode<T>* AVLtree<T>::double_rotate_with_right(TreeNode<T>* ptn)
{
	ptn = single_rotate_with_left(ptn->rchild);
	return single_rotate_with_right(ptn);
}

template<typename T>
void AVLtree<T>::insert(const T& elem)
{
	insert(elem, Binary_tree<T>::treeroot);
}

template<typename T>
TreeNode<T>* AVLtree<T>::insert(const T& elem, TreeNode<T>* ptn)
{
	if(Binary_tree<T>::treeroot == nullptr)
	{
		std::cout << "The tree is empty." << std::endl;
		Binary_tree<T>::treeroot = new TreeNode<T>;
		Binary_tree<T>::treeroot->element = elem;
		Binary_tree<T>::treeroot->lchild = nullptr;
		Binary_tree<T>::treeroot->rchild = nullptr;
	}
	else if (ptn == nullptr)
	{
		ptn = new TreeNode<T>;
		ptn->element = elem;
		ptn->lchild = nullptr;
		ptn->rchild = nullptr;
	}
	else if(BSTree<T>::find(elem))
		std::cout << "The element is in the tree." << std::endl;
	else if(elem < ptn->element)
	{
		ptn->lchild = insert(elem, ptn->lchild);
		if (Binary_tree<T>::tree_depth(ptn->lchild) - Binary_tree<T>::tree_depth(ptn->rchild) == 2)
			if(elem < ptn->lchild->element)
				ptn = single_rotate_with_left(ptn);
			else
				ptn = double_rotate_with_left(ptn);
	}
	else if(elem > ptn->element)
	{
		ptn->rchild = insert(elem, ptn->rchild);
		if (Binary_tree<T>::tree_depth(ptn->rchild) - Binary_tree<T>::tree_depth(ptn->lchild) == 2)
			if(elem > ptn->rchild->element)
				ptn = single_rotate_with_right(ptn);
			else
				ptn = double_rotate_with_right(ptn);
	}
	
	return ptn;
}

template<typename T>
void AVLtree<T>::delete_element(const T& elem)
{
	delete_element(elem, Binary_tree<T>::treeroot);
}

template<typename T>
TreeNode<T>* AVLtree<T>::delete_element(const T& elem, TreeNode<T>* ptn)
{
	if (ptn == nullptr)
	{
		std::cerr << "The tree is empty." << std::endl;
	}
	else if (!BSTree<T>::find(elem))
	{
		std::cout << "The element is not in the tree." << std::endl;
		return 0;
	}
	else
	{
		if (elem < ptn->element) 
		{
			ptn->lchild = delete_element(elem, ptn->lchild);
			if (Binary_tree<T>::tree_depth(ptn->rchild) - Binary_tree<T>::tree_depth(ptn->lchild) == 2) 
			{
				if (Binary_tree<T>::tree_depth(ptn->rchild->rchild) > Binary_tree<T>::tree_depth(ptn->rchild->lchild))
					ptn = single_rotate_with_right(ptn);
				else
				{
					ptn = double_rotate_with_right(ptn);
				}	
			}
		}
		else if (elem > ptn->element) 
		{
			ptn->rchild = delete_element(elem, ptn->rchild);
			if (Binary_tree<T>::tree_depth(ptn->lchild) - Binary_tree<T>::tree_depth(ptn->rchild) == 2) {
				if (Binary_tree<T>::tree_depth(ptn->lchild->lchild) > Binary_tree<T>::tree_depth(ptn->lchild->rchild))
					ptn = single_rotate_with_left(ptn);
				else
					ptn = double_rotate_with_left(ptn);
			}
		}
		else{
			BSTree<T>::delete_element(elem);
			return 0;
		}
			
	}
	return ptn;
}

#endif


