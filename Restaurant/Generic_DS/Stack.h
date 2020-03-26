#pragma once
#include<iostream>
using namespace std;
#include"LinkedList.h"
template <typename T>
class Stack {

	Node<T>* top;
	LinkedList<T> data;

public:
	Stack() {// Instantiates an empty stack.
		top = nullptr;
		data.setHead(top);
	}

	~Stack() { 
		top = nullptr;
		data.DeleteAll();
	}

	void printStack() {
		cout << "Printing Whole Stack, starting from top:" << endl;
		Node<T>* trav = top;
		while (trav) {
			cout << trav->getItem() << "  ";
			trav = trav->getNext();
		}
	}

	void push(T item) { // Adds item to the beginning of the Linkedlist, and thus to the top of the stack.
		data.InsertBeg(item);
		top = data.getHead();
	}

	bool pop(T& popped) { // Gets the data we want to extract from the Linkedlist, deletes the first node of the Linkedlist and returns the data.
		if (isEmpty() == true) {
			return false;
		}
		T poppedData;
		poppedData = data.getHead()->getItem();
		data.DeleteFirst();
		
		top = data.getHead();
		popped = poppedData;
		return true;
	}

	T peek() { // Just makes a pointer to the top of the stack and returns it.
		T toBeReturned = top->getItem();
		return toBeReturned;
	}

	LinkedList<T>* getFullLinkedList() { // incase we mess something up real bad, we can directly access the linkedlist that makes up the stack by a pointer.
										 // the head of the list is the top of the stack, so if you push 1, 2, 3 and you print the linked list you get 3-->2-->1-->NULL
		LinkedList<T>* pData = &data;
		return pData;
	}

	bool isEmpty() { // if empty then yes, do i have to explain this one too?
		if (top == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
};