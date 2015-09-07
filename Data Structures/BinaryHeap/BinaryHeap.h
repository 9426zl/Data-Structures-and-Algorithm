//
//   BinaryHeap.h
//   Binary heap realization
//
//   Created by Baldwin Lou on 09/07/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <vector>

template<typename T>
class Binary_heap {
public:
	Binary_heap(): heapsize(0) { }
	~Binary_heap() { }
	
	bool is_empty() { return (heapsize ? false: true);}
	
	void make_empty();
	void insert(const T& elem);
	void delete_element(const T& elem);
	
	T delete_min();

private:
	std::vector<T> 	bheap;
	int heapsize = 0;
};

template<typename T>
void Binary_heap<T>::make_empty()
{
	bheap.clear();
	heapsize = 0;
}

template<typename T>
void Binary_heap<T>::insert(const T& elem)
{
	auto result = find(bheap.cbegin(), bheap.cend(), elem);
	if (result != bheap.end())
	{
		std::cout << "The element is in the heap already." << std::endl;
		return;
	}	
		
	bheap.push_back(elem);
	++heapsize; 
	auto i = bheap.size();
	T tmp;
	
	while ((i-1) != 0)
	{
		if (bheap[i-1] < bheap[i/2-1])
		{
			tmp = bheap[i/2-1];
			bheap[i/2-1] = bheap[i-1];
			bheap[i-1] = tmp;
		}
		i = i/2;		
	}
}

template<typename T>
void Binary_heap<T>::delete_element(const T& elem)
{
	typename std::vector<T>::iterator iter = find(bheap.begin(), bheap.end(), elem);
	typename std::vector<T>::iterator iterc = bheap.begin();
	int i = 1;
	
	if (iter == bheap.end())
		{
			std::cout << "The element is not in the heap." << std::endl;
			return;
		}
	
	while (iterc++ != iter)
		++i;
	
	while (heapsize >= 2*i && heapsize >= 2*i+1)
	{
		if (bheap[2*i-1] < bheap[2*i])
		{
			bheap[i-1] = bheap[2*i-1];
			i = 2*i;
		}	
		else
		{
			bheap[i-1] = bheap[2*i];
			i = 2*i + 1;
		}			
	}
	
	bheap[i] = bheap.back();
	bheap.pop_back();
	--heapsize;	
}

template<typename T>
T Binary_heap<T>::delete_min()
{
	int i = 1;
	T tmp = bheap[0];

	if (heapsize == 0)
	{
		std::cerr << "The heap is empty." << std::endl;
	}	
	
	tmp = bheap[0];
		
	while (heapsize >= 2*i && heapsize >= 2*i+1)
	{
		if (bheap[2*i-1] < bheap[2*i])
		{
			bheap[i-1] = bheap[2*i-1];
			i = 2*i;
		}	
		else
		{
			bheap[i-1] = bheap[2*i];
			i = 2*i + 1;
		}			
	}
	
	bheap[i] = bheap.back();
	bheap.pop_back();
	--heapsize;
	
	return tmp;
}

#endif
