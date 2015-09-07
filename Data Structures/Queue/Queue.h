//
//   Queue.h
//   Queue realization
//
//   Created by Baldwin Lou on 08/30/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<typename T>
struct Queue_node {
	T element;
    Queue_node *next;
	
	Queue_node():element(),next(0) {}
	~Queue_node(){ next = 0;}
};


template<typename T>
class Queue {
typedef Queue_node<T> *PtrToNode;

public:
	Queue();
	~Queue();
	
	bool is_empty() const { return queuesize ? false : true;}
	int  queue_size() const { return queuesize;}
	
	void enqueue(const T& elem);
	T    dequeue();
	
	void delete_queue();
	
private:
	PtrToNode head = 0;
	int queuesize = 0;
};

template<typename T>
Queue<T>::Queue(): head(new Queue_node<T>), queuesize(0)
{
	head->next = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	delete_queue();
	delete head;
}

template<typename T>
void Queue<T>::delete_queue()
{
	if(queuesize != 0)
		dequeue();
}

template<typename T>
T Queue<T>::dequeue()
{
	T elem = head->element;
	if(queuesize != 1){
		PtrToNode oldhead = head;
		head = head->next;
		delete oldhead;
		--queuesize;	
	} 
	else {
		//std::cout << "Queue is empty." << std::endl;
		--queuesize;
	}

	return elem;
}

template<typename T>
void Queue<T>::enqueue(const T&elem)
{
	PtrToNode cursor = head;
	PtrToNode tail = new Queue_node<T>;
	tail->element = elem;
	int pos = 0;
	
	if (queuesize == 0){
		head->element = elem;
		++queuesize;
		delete tail;
	}
	else{
		while(pos != (queuesize -1)){
			cursor = cursor->next;
			++pos;
		}
		cursor->next = tail;
		++queuesize;
	}
}

#endif
