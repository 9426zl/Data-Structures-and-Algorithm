//
//   BinaryTree.h
//   BinaryTree realization
//
//   Created by Baldwin Lou on 09/01/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <ostream>

template<typename T>
struct TreeNode {
	T element;
	TreeNode *lchild;
	TreeNode *rchild;
	
	TreeNode():element(), lchild(nullptr), rchild(nullptr){}
	~TreeNode(){ lchild = rchild = nullptr; }
};

template<typename T>
class Binary_tree {
typedef TreeNode<T> *PtrToNode;

public:
	Binary_tree():treeroot(nullptr),treesize(0) { }
	virtual ~Binary_tree();
	
	bool is_empty() const { return treesize ? false : true;}
	int tree_size() const { return treesize;}
	int tree_depth() const;
	
	virtual PtrToNode find(const T& elem) const=0;	
	virtual void insert(const T& elem)=0;	
	virtual void delete_element(const T& elem)=0;
	virtual void print(std::ostream& output) const=0;
	void print_tree(std::ostream& output) const;
	
protected:
	int tree_depth(const TreeNode<T>* ptn) const;
	void delete_tree(PtrToNode ptn);
	
	PtrToNode treeroot;
	int treesize;
	
private:
	void print_tree(std::ostream& output, PtrToNode ptn, int depth) const;
};


template<typename T>
Binary_tree<T>::~Binary_tree()
{
	delete_tree(treeroot);
}

template<typename T>
void Binary_tree<T>::delete_tree(TreeNode<T>* ptn)
{
	if (ptn == nullptr)
		return;
	
	PtrToNode tmpl = ptn->lchild;
	PtrToNode tmpr = ptn->rchild;
	
	delete ptn;
	delete_tree(tmpl);
	delete_tree(tmpr);	 
}

template<typename T>
int Binary_tree<T>::tree_depth() const
{
	return tree_depth(treeroot);
}

template<typename T>
int Binary_tree<T>::tree_depth(const TreeNode<T>* ptn) const
{
	int ldepth, rdepth;
	if(ptn == nullptr)
		return 0;
	else
	{
		ldepth = tree_depth(ptn->lchild);
		rdepth = tree_depth(ptn->rchild);
	}
	return 1+(ldepth > rdepth ? ldepth: rdepth);
}

template<typename T>
void Binary_tree<T>::print_tree(std::ostream& output) const
{
	print_tree(output, treeroot, 1);
}

template<typename T>
void Binary_tree<T>::print_tree(std::ostream& output, 
							    TreeNode<T>* ptn, int depth) const
{
	if (ptn == nullptr)
		return;
	
	print_tree(output,ptn->lchild,depth+1);
	for (int i=0; i!=depth; ++i)
		output<<"    ";
	output<<ptn->element<<'\n';
	print_tree(output,ptn->rchild,depth+1);	
}

#endif
