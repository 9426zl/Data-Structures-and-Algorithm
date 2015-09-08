//
//   BinomialQueue.h
//   Binomial queue realization
//
//   Created by Baldwin Lou on 09/08/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef BINOMIALQUEUE_H
#define BINOMIALQUEUE_H

#include <iostream>
#include <vector>

template<typename T>
struct Bin_node {
	T element;
	Bin_node<T>* leftchild;
	Bin_node<T>* nextsibling;
	
	Bin_node(): element(), leftchild(nullptr)
					,nextsibling(nullptr) { }
};


template<typename T>
class Bin_queue {
public:
	Bin_queue(int queuecap);
	~Bin_queue();
	
	int queue_size();
	void clear();
	
	void merge(Bin_queue<T>* h2);
	void insert(const T& elem);
	Bin_node<T>* find_min();
	void delete_min();
	
private:
	int cursize;    // element amount
	int bqsize;     // node amount
	int cap;        // vector capicity
	std::vector<Bin_node<T>*> binqueue;
	
	Bin_node<T>* combine_tree(Bin_node<T>* t1, Bin_node<T>* t2);
};

template<typename T>
Bin_queue<T>::Bin_queue(int queuecap) : cap(queuecap), bqsize(0), cursize(0)
{
	binqueue.resize(cap, 0);
}

template<typename T>
Bin_queue<T>::~Bin_queue()
{
	binqueue.clear();
	cursize = bqsize = 0;
}

template<typename T>
int Bin_queue<T>::queue_size()
{
	return cursize;
}

template<typename T>
void Bin_queue<T>::clear()
{
	binqueue.clear();
	cursize = bqsize = 0;	
}

template<typename T>
void Bin_queue<T>::merge(Bin_queue<T>* h2)
{
	int i, j;
	Bin_node<T>* t1 = 0;
	Bin_node<T>* t2 = 0;
	Bin_node<T>* carry = 0;
		
	if (h2->cap > cap)
		std::cerr << "Merge would exceed capacity."
				  << std::endl;

	cursize += h2->cursize;
	bqsize += h2->bqsize;
	for(i=0, j=1; j <= bqsize; ++i, j*=2)
	{
		t1 = binqueue[i];
		t2 = h2->binqueue[i];
		
		switch(!!t1 + (!!t2<<1) + (!!carry<<2))
		{
			case 0:
				break;
			case 1:
				break;
			case 2:
				binqueue[i] = h2->binqueue[i];
				h2->binqueue[i] = 0;
				break;
			case 4:
				binqueue[i] = carry;
				carry = 0;
				break;
			case 3:
				carry = combine_tree(binqueue[i], h2->binqueue[i]);
				binqueue[i] = h2->binqueue[i] = 0;
				break;
			case 5:
				carry = combine_tree(binqueue[i], carry);
				binqueue[i] = 0;
				break;
			case 6:
				carry = combine_tree(h2->binqueue[i], carry);
				h2->binqueue[i] = 0;
				break;
			case 7:
				binqueue[i] = carry;
				carry = combine_tree(binqueue[i], h2->binqueue[i]);
				break;
		}
	}	
}

template<typename T>
Bin_node<T>* Bin_queue<T>::combine_tree(Bin_node<T>* t1, Bin_node<T>* t2)
{
	if (t1->element > t2->element)
		return combine_tree(t2, t1);
	
	t2->nextsibling = t1->leftchild;
	t1->leftchild = t2;
	
	return t1; 
}

template<typename T>
void Bin_queue<T>::insert(const T& elem)
{
	Bin_queue<T> bq2(Bin_queue<T>::cap);
	Bin_queue<T>* h2 = &bq2;
	Bin_node<T>* t1 = new Bin_node<T>;
	t1->element = elem;
	bq2.binqueue[0] = t1;
	bq2.bqsize = 1;
	bq2.cursize = 1;
	
	merge(h2);
}

template<typename T>
Bin_node<T>* Bin_queue<T>::find_min()
{
	if (cursize == 0)
	{
		std::cerr << "The queue is empty." << std::endl;
		return 0;
	}	
	
	Bin_node<T>* minTree = binqueue[0];
	Bin_node<T>* tmp = nullptr;
	
	typename std::vector<Bin_node<T>*>::iterator iter = binqueue.begin();
	while (iter != binqueue.end())
	{
		tmp = *iter;
		if (tmp != 0)
		{
			if (minTree != 0)
			{
				if ( tmp->element < minTree->element)
					minTree = tmp;
			}		
			else
				minTree = tmp;								
		}
		++iter;
	}

	return minTree;
}

template<typename T>
void Bin_queue<T>::delete_min()
{
	if (cursize == 0)
		std::cerr << "The queue is empty." << std::endl;	
	
	Bin_node<T>* oldroot = find_min();
	Bin_node<T>* renode = oldroot->leftchild;
	Bin_queue<T> bq2(Bin_queue<T>::cap);
	Bin_queue<T>* bq2ptr = &bq2;
	std::vector<Bin_node<T>*> tmpstore;
	int cnt = 0;
	int i = 0;
	int j = 0;
	
	while(renode != nullptr)
	{
		tmpstore.push_back(renode);
		renode = renode->nextsibling;
		++cnt;
	}
	bq2.bqsize = cnt + 1;
	
	j = cnt;
	while(i < cnt)
	{
		bq2.binqueue[j] = tmpstore[i];
		--j;
		++i;
	}
	
	merge(bq2ptr);
	
	std::cout << "The min element is " << oldroot->element
			  << std::endl;
	delete oldroot;
	--cursize;
	
}

#endif
