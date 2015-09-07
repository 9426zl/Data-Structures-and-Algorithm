//
//   List.h
//   Doubly linked list realization
//
//   Created by Baldwin Lou on 08/28/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//


#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T>
struct List_node {
	T element;
	List_node *prev;
	List_node *next;
	
	List_node():element(), prev(0), next(0) {}
	~List_node(){ next = prev = 0;}
};


template <typename T>
class List {	
typedef List_node<T> *PtrToNode;
typedef PtrToNode    Position;

public:
	List();
	~List();
	
	bool is_empty() const { return theSize ? false : true;}
	int  list_size() const { return theSize;}
	
	Position find_value(const T& elem);
	Position find(int pos) const;
	
	void insert_after(const T& elem, int pos);
	void push_front(const T& elem);
	T    pop_front();
	void push_back(const T& elem);
	T    pop_back(); 
	
	void delete_element(PtrToNode ptr);
	void delete_element(int pos);
	void delete_element(int beg, int end);
	void delete_list();
		
private:
	PtrToNode head;
	PtrToNode tail;
	int theSize ;
};

template<typename T>
List<T>::List() : head(new List_node<T>),
				  tail(new List_node<T>), theSize(0)
{
	head->next = tail;
	head->prev = 0;
	tail->prev = head;
	tail->next = 0;
}

template<typename T>
List<T>::~List()
{
	delete_list();
	delete head;
	delete tail;
}

template<typename T>
void List<T>::delete_list()
{
	if(theSize != 0)
		delete_element(1, theSize);
}

template<typename T>
List_node<T>* List<T>::find_value(const T& elem)
{
	PtrToNode elemPosi = head;
	PtrToNode cursor = head;
	
	while(cursor->element != elem)
	{
		if(cursor == tail)
			std::cout << "The element is not in the list" 
			          << std::endl;
		else
			cursor = cursor->next;
	}
	return cursor;
}

template<typename T>
List_node<T>* List<T>::find(int pos) const
{
	PtrToNode cursor = head;
	int i = 0;
	while (i != pos){
		cursor = cursor->next;
		++i;
	}
	
	return cursor;
}

template<typename T>
void List<T>::insert_after(const T& elem, int pos)
{
	PtrToNode cursor = find(pos);
	if(cursor == 0){
		return;
	}
	PtrToNode temptr = cursor->next;
	PtrToNode insptr = new List_node<T>;
	insptr->element = elem;
	cursor->next = insptr;
	insptr->prev = cursor;
	insptr->next = temptr;
	temptr->prev = insptr;
	++theSize;	
}

template<typename T>
void List<T>::push_front(const T& elem)
{
	insert_after(elem, 0);
}

template<typename T>
void List<T>::push_back(const T& elem)
{
	insert_after(elem, theSize);
}

template<typename T>
void List<T>::delete_element(List_node<T> *ptr)
{
	PtrToNode temptr = ptr;
	ptr->prev->next = temptr->next;
	ptr->next->prev = temptr->prev;
	T elem = ptr->element;
	delete ptr;
	--theSize;
}

template<typename T>
void List<T>::delete_element(int pos)
{
	PtrToNode cursor = find(pos);
	return delete_element(cursor);
}

template<typename T>
void List<T>::delete_element(int beg, int end)
{
	PtrToNode pbeg = find(beg);
	PtrToNode pend = find(end);
	PtrToNode temptr = pbeg;
	PtrToNode cursor = pbeg;
	PtrToNode pstop = pend->next;
	
	while(cursor != pstop){
		temptr = temptr->next;
		delete_element(cursor);
		cursor = temptr;
		--theSize;
	}
}

template<typename T>
T List<T>::pop_front()
{
	PtrToNode temp = find(1);
	T elem = temp->element;
	delete_element(1);
	
	return elem;
}

template<typename T>
T List<T>::pop_back()
{
	PtrToNode temp = find(theSize);
	T elem = temp->element;
	delete_element(theSize);
	
	return elem;
}

#endif
