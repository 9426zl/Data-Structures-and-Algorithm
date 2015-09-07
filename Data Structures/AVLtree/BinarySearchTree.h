//
//   BinarySearchTree.h
//   BinarySearchTree realization
//
//   Created by Baldwin Lou on 09/01/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEATCHTREE_H

#include <iostream>
#include "BinaryTree.h"

template<typename T>
class BSTree : public Binary_tree<T> {
typedef TreeNode<T>* PtrToNode;

public:	
	TreeNode<T>* find(const T& elem) const;
	TreeNode<T>* find_parent(const T& elem) const;
	TreeNode<T>* find_min(TreeNode<T>* ptn=Binary_tree<T>::treeroot) const;
	TreeNode<T>* find_max(TreeNode<T>* ptn=Binary_tree<T>::treeroot) const;
	
	virtual void insert(const T& elem) override;	
	virtual void delete_element(const T& elem) override;
	virtual void print(std::ostream& output) const override;

protected:
	virtual void print(std::ostream& output, const TreeNode<T>* ptn) const;	
};


template<typename T>
TreeNode<T>* BSTree<T>::find(const T& elem) const
{
	TreeNode<T>* ptn = Binary_tree<T>::treeroot;
	
	if(ptn == nullptr)
	{
		std::cout << "The tree is empty.";
		return ptn;
	}
	else
	{
		T cur = ptn->element;
		while (cur != elem && ptn != nullptr)
		{
			if (cur > elem)
				ptn = ptn->lchild;
			else
				ptn = ptn->rchild;
			
			if (ptn !=nullptr)
				cur = ptn->element;
		}
	
		if (cur == elem)
		{
			return ptn;
		}	
		else
		{
			return 0;
		}
	}	
}

template<typename T>
TreeNode<T>* BSTree<T>::find_parent(const T& elem) const
{
	TreeNode<T>* ptn = Binary_tree<T>::treeroot;
	TreeNode<T>* parptn = nullptr;
	
	if(ptn == nullptr)
	{
		std::cout << "The tree is empty.";
		return ptn;
	}
	else
	{
		T cur = ptn->element;
		while (cur != elem && ptn != nullptr)
		{
			if (cur > elem)
			{
				parptn = ptn;
				ptn = ptn->lchild;
			}	
			else
			{
				parptn = ptn;
				ptn = ptn->rchild;
			}
			
			if (ptn != nullptr)
				cur = ptn->element;
		}
	
		if (cur == elem)
		{
			return parptn;
		}	
		else
		{
			std::cout << "The element is not in the tree." << std::endl;
			return 0;
		}
	}	
}

template<typename T>
TreeNode<T>* BSTree<T>::find_min(TreeNode<T>* ptn) const
{
	
	if (ptn == 0)
		ptn = Binary_tree<T>::treeroot;
	
	if (ptn == nullptr)
	{
		std::cerr << "The tree is empty. " 
				  << std::endl;
		return 0;
	}

	while(ptn->lchild != nullptr)
	{
		ptn = ptn->lchild;
	}	
	
	return ptn;
}

template<typename T>
TreeNode<T>* BSTree<T>::find_max(TreeNode<T>* ptn) const
{

	if (ptn == 0)
		ptn = Binary_tree<T>::treeroot;
		
	if (ptn == nullptr)
	{
		std::cerr << "The tree is empty. " 
				  << std::endl;
		return 0;
	}	
	
	while(ptn->rchild != nullptr)
		ptn = ptn->rchild;
	
	return ptn;
}

template<typename T>
void BSTree<T>::insert(const T& elem)
{
	if (Binary_tree<T>::treeroot == nullptr)
	{
		std::cout << "The tree is empty, insert the first element." << std::endl;
		Binary_tree<T>::treeroot = new TreeNode<T>;
		Binary_tree<T>::treeroot->element = elem;
		return;
	}
	else
	{
		PtrToNode ptn = Binary_tree<T>::treeroot;
		T cur;
		int flag = 0;
		
		if (find(elem))
		{	
			std::cerr << "The element is already in the tree."
					  << std::endl;
   		}	
		else
		{   
			std::cout << "Now insert the element." << std::endl;
			cur = ptn->element;
			while(flag == 0)
			{
				if(elem > cur)
				{
					//ptn = ptn->rchild;
					if (ptn->rchild == nullptr)
					{
						ptn->rchild = new TreeNode<T>;
						ptn->rchild->element = elem;
						ptn = ptn->rchild;
						flag = 1;
					}
					else
					{
						ptn = ptn->rchild;
						cur = ptn->element;
					}		
				}
				else
				{
					if (ptn->lchild == nullptr)
					{
						ptn->lchild = new TreeNode<T>;
						ptn->lchild->element = elem;
						ptn = ptn->lchild;
						flag = 1;
					}
					else
					{
						ptn = ptn->lchild;
						cur = ptn->element;	
					}						
				}
			}
		}
	}
}

template<typename T>
void BSTree<T>::delete_element(const T& elem)
{
	TreeNode<T>* ptn = find(elem);
	TreeNode<T>* lptn = nullptr;
	TreeNode<T>* rptn = nullptr;
	TreeNode<T>* minptn = nullptr;
	TreeNode<T>* tmpptn = nullptr;
	T            tmp;
	
	if (!ptn)
		std::cerr << "The element isn't in the tree."
				  << std::endl;
	else
	{
		if (ptn->lchild == nullptr && ptn->rchild == nullptr)
		{
			tmpptn = find_parent(ptn->element);
			if (tmpptn->lchild == nullptr)
			{
				delete ptn;
				tmpptn->rchild = nullptr;
			}
			else if (tmpptn->rchild == nullptr)
			{
				delete ptn;
				tmpptn->lchild = nullptr;
			}
			else if (tmpptn->lchild->element == elem)
			{
				delete ptn;
				tmpptn->lchild = nullptr;
			}
			else
			{
				delete ptn;
				tmpptn->rchild = nullptr;
			}
		}   
		else if (ptn->lchild == nullptr && ptn->rchild != nullptr)
		{
			rptn = ptn->rchild;
			ptn->element = rptn->element;
			delete rptn;
			ptn->rchild = nullptr;
		}
		else if (ptn->lchild != nullptr && ptn->rchild == nullptr)
		{
			lptn = ptn->lchild;
			ptn->element = lptn->element;
			delete lptn;
			ptn->lchild = nullptr;
		}
		else
		{
			rptn = ptn->rchild;
			minptn = find_min(rptn);
			tmp = minptn->element;
			delete_element(minptn->element);
			ptn->element = tmp;
		}
	}
}

template<typename T>
void BSTree<T>::print(std::ostream& output) const
{
	print(output, Binary_tree<T>::treeroot);
}

template<typename T>
void BSTree<T>::print(std::ostream& output, const TreeNode<T>* ptn) const
{
	if (ptn == nullptr)
		return;
	else
	{
		print(output, ptn->lchild);
		output << ptn->element << " ";	
		print(output, ptn->rchild);	
	}
	
}

#endif
