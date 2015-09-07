//
//   Splay_tree.h
//   Splay tree realization
//
//   Created by Baldwin Lou on 09/06/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef SPALY_TREE_H
#define SPLAT_TREE_H

#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"


template<typename T>
class Splay_tree : BSTree<T> {
public:
	TreeNode<T>* zig_zag_with_left(TreeNode<T>* ptn, TreeNode<T>* pptn, TreeNode<T>* gptn);
	TreeNode<T>* zig_zag_with_right(TreeNode<T>* ptn, TreeNode<T>* pptn, TreeNode<T>* gptn);
	TreeNode<T>* zig_zig_with_left(TreeNode<T>* ptn, TreeNode<T>* pptn, TreeNode<T>* gptn);
	TreeNode<T>* zig_zig_with_right(TreeNode<T>* ptn, TreeNode<T>* pptn, TreeNode<T>* gptn);
	
	void access(const T& elem);
	void access(const T& elem, TreeNode<T>* ptn);
	void delete_element(const T& elem) override;
};

template<typename T>
TreeNode<T>* Splay_tree<T>::zig_zag_with_left(TreeNode<T>* xptn,TreeNode<T>* pptn,
											  TreeNode<T>* gptn)
{
	pptn->rchild = xptn->lchild;
	gptn->lchild = xptn->rchild;
	xptn->lchild = pptn;
	xptn->rchild = gptn;
	
	return xptn;
}

template<typename T>
TreeNode<T>* Splay_tree<T>::zig_zag_with_right(TreeNode<T>* xptn,TreeNode<T>* pptn,
											  TreeNode<T>* gptn)
{
	pptn->lchild = xptn->rchild;
	gptn->rchild = xptn->lchild;
	xptn->rchild = pptn;
	xptn->lchild = gptn;
	
	return xptn;
}

template<typename T>
TreeNode<T>* Splay_tree<T>::zig_zig_with_left(TreeNode<T>* xptn,TreeNode<T>* pptn,
											  TreeNode<T>* gptn)
{
	pptn->lchild = xptn->rchild;
	xptn->rchild = pptn;
	gptn->lchild = pptn->rchild;
	pptn->rchild = gptn;
	
	return xptn;
}

template<typename T>
TreeNode<T>* Splay_tree<T>::zig_zig_with_right(TreeNode<T>* xptn,TreeNode<T>* pptn,
											  TreeNode<T>* gptn)
{
	pptn->rchild = xptn->lchild;
	xptn->lchild = pptn;
	gptn->rchild = pptn->lchild;
	pptn->lchild = gptn;
	
	return xptn;
}

template<typename T>
void Splay_tree<T>::access(const T& elem)
{
	TreeNode<T>* xptn = BSTree<T>::find(elem);
	
	if (xptn == nullptr)
		std::cerr << "The element is not in the tree."
				  << std::endl;
	
	TreeNode<T>* pptn = BSTree<T>::find_parent(elem);
	if (pptn == nullptr)
	{
		std::cout << "The element is on the root."
				  << std::endl;
		return;
	}
	
	while(xptn != Binary_tree<T>::treeroot)
	{
		TreeNode<T>* pptn = BSTree<T>::find_parent(elem);
		TreeNode<T>* gptn = BSTree<T>::find_parent(pptn->element);
		if (gptn == nullptr)
			if (pptn->lchild == xptn)
			{
				pptn->lchild = xptn->rchild;
				xptn->rchild = pptn;
				Binary_tree<T>::treeroot = xptn;
			}
			else
			{
				pptn->rchild = xptn->lchild;
				xptn->lchild = pptn;
				Binary_tree<T>::treeroot = xptn;
			}
		else if(gptn->lchild == pptn && pptn->rchild == xptn)
			gptn = zig_zag_with_left(xptn, pptn, gptn);
		else if(gptn->rchild == pptn && pptn->lchild == xptn)
			gptn = zig_zag_with_right(xptn, pptn, gptn);
		else if(gptn->lchild == pptn && pptn->lchild = xptn)
			gptn = zig_zig_with_left(xptn, pptn, gptn);
		else
			gptn = zig_zig_with_right(xptn, pptn, gptn);	
	}		
}

template<typename T>
void Splay_tree<T>::access(const T& elem, TreeNode<T>* ptn)
{
	TreeNode<T>* xptn = BSTree<T>::find(elem);
	
	if (xptn == nullptr)
		std::cerr << "The element is not in the tree."
				  << std::endl;
	else if (Binary_tree<T>::tree_depth(xptn) > Binary_tree<T>::tree_depth(ptn))
		std::cerr << "The element is not in the subtree."
				  << std::endl;
	
	
	if (xptn == ptn)
	{
		std::cout << "The element is on the subtree root."
				  << std::endl;
		return;
	}
	
	TreeNode<T>* pptn = BSTree<T>::find_parent(elem);
	while(xptn != ptn)
	{
		TreeNode<T>* pptn = BSTree<T>::find_parent(elem);
		TreeNode<T>* gptn = BSTree<T>::find_parent(pptn->element);
		if (pptn == ptn)
			if (pptn->lchild == xptn)
			{
				pptn->lchild = xptn->rchild;
				xptn->rchild = pptn;
				ptn = xptn;
			}
			else
			{
				pptn->rchild = xptn->lchild;
				xptn->lchild = pptn;
				ptn = xptn;
			}
		else if(gptn->lchild == pptn && pptn->rchild == xptn)
			gptn = zig_zag_with_left(xptn, pptn, gptn);
		else if(gptn->rchild == pptn && pptn->lchild == xptn)
			gptn = zig_zag_with_right(xptn, pptn, gptn);
		else if(gptn->lchild == pptn && pptn->lchild = xptn)
			gptn = zig_zig_with_left(xptn, pptn, gptn);
		else
			gptn = zig_zig_with_right(xptn, pptn, gptn);	
	}		
}

template<typename T>
void Splay_tree<T>::delete_element(const T& elem)
{
	TreeNode<T>* ptn = Binary_tree<T>::treeroot;
	TreeNode<T>* cptn = find_min(ptn->lchild);
	
	access(elem);
	access(cptn->element, ptn->lchild);
	
	ptn = Binary_tree<T>::treeroot;
	ptn->lchild->lchild = ptn->rchild;
	Binary_tree<T>::treeroot = ptn->lchild;
	
	delete ptn;	
}
#endif
