//
//   Stack.h
//   Stack realization
//
//   Created by Baldwin Lou on 08/30/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>

template<typename T>
struct Stack_node{
	T          element;
	Stack_node *next;
	
	Stack_node():element(), next(0) {}
	~Stack_node() {}
};

template<typename T>
class Stack {
typedef Stack_node<T> *PtrToNode;

public:
	Stack(): top(new Stack_node<T>),stacksize(0){};
	~Stack();
	
	bool is_empty() const {return stacksize ? false : true; }
	int  stack_size() const { return stacksize; }
	
	void push(const T& elem);
	T    pop();
	
	void delete_element();
	void delete_stack();
	
private:
	int stacksize = 0;
	PtrToNode top ;
};

template<typename T>
Stack<T>::~Stack()
{
	delete_stack();
	delete top;
}

template<typename T>
void Stack<T>::delete_stack()
{
	while(stacksize != 0)
		delete_element();
}

template<typename T>
void Stack<T>::delete_element()
{
	if (stacksize != 1){
		PtrToNode oldtop = top;
		top = oldtop->next;
		delete oldtop;
		--stacksize;
	}
	else {
		--stacksize;
	}
	
}

template<typename T>
void Stack<T>::push(const T& elem)
{
	if (stacksize == 0){
		top->element = elem;
		++stacksize;
	}
	else {
		PtrToNode newtop = new Stack_node<T>;
		PtrToNode oldtop = top;
		top = newtop;
		top->next = oldtop;
		top->element = elem;
		++stacksize;		
	}
	
}

template<typename T>
T Stack<T>::pop()
{
	T elem = top->element;
	if (stacksize == 0) {
		std::cerr << "The stack is empty" << std::endl;
		return -1;
	}
	else {
		delete_element();
	}
		
	return elem;
}

#endif
