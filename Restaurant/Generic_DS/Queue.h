#ifndef __QUEUE_H_
#define __QUEUE_H_
#include"../Rest/Order.h"
/*This code is an updated version from "Data Abstraction & Problem Solving with C++,WALLS AND MIRRORS ,SIXTH EDITION"*/

/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers,
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					-------------
					| item| next | --->
					-------------
General Queue case:

				 frontPtr																backPtr
					\											   						/
					 \											  					   /
					------------- 	  ------------- 	  ------------- 	  -------------
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------

Empty Case:

				 frontptr	 backptr
						\	 /
						 \	/
					---- NULL ------


Single Node Case:
				 frontPtr	 backPtr
					\		/
					 \	   /
					--------
					|	|nxt -->NULL
					--------

*/

#include "Node.h"
#include<iostream>
using namespace std;
template <typename T>
class Queue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	Queue();
	Queue( const Queue<T>&);
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool dequeueWithOrderID(int ID, Order& removed);
	bool peekFront(T& frntEntry)  const; // Returns false if queue is empty, true if peeking was successful.
	Node<T>* getPtrToFront();
	bool dequeueWithOrderID(int ID, Order& removed);
	void printQueueData();
	T* toArray(int& count);	//returns array of T (array if items)
	~Queue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
Queue<T>::Queue()	//CTOR makes an empty queue
{
	backPtr = nullptr;
	frontPtr = nullptr;

}


template<typename T>
Queue<T>::Queue(const Queue<T>& src ) {
	frontPtr = nullptr;
	backPtr = nullptr;
	Node<T>* pNode = src.frontPtr;
	while (pNode) {
		enqueue(pNode->getItem());
		pNode = pNode->getNext();
	}

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool Queue<T>::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty
	backPtr = newNodePtr; // New node is at back
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Queue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr;

	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;


	return true;

}
template <typename T>


bool Queue<T>::dequeueWithOrderID(int ID, Order& removed) { // bta5od el id w pass by refernce variable esmo removed dh ele hyt7t

												// feh el order el mal8y
	if (isEmpty()) {
		return false; // OPERATION FAILED!!
	}


	if (getPtrToFront()->getItem()->GetID() == ID) {
		if (!dequeue(removed)) {
			return false;
		}
		dequeue(removed);
		return true;

	}

	Node<T>* trav = getPtrToFront();
	Node<T>* trav2 = trav->getNext();
	while (trav2->getNext() != NULL) {
		if (trav2->getItem()->GetID() == ID) {
			trav->setNext(trav2->getNext());
			removed = trav2->getItem();
			delete trav2;

			return true;
		}
		else {
			trav2 = trav2->getNext();
			trav = trav->getNext();
		}


	}
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
gets the front of this queue. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
return: false if Queue is empty
*/
template <typename T>
bool Queue<T>::peekFront(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
template <typename T>
Node<T>* Queue<T>::getPtrToFront() {
	return frontPtr;
}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
Queue<T>::~Queue()
{
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: toArray
returns an array of "T"
Output: count: the length of the returned array (zero if Queue is empty)
returns: The array of T. (nullptr if Queue is empty)
*/

template <typename T>
T* Queue<T>::toArray(int& count)
{
	count = 0;

	if (!frontPtr)
		return nullptr;
	//counting the no. of items in the Queue
	Node<T>* p = frontPtr;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T* Arr = new T[count];
	p = frontPtr;
	for (int i = 0; i < count; i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;
}


template <typename T>
void Queue<T>::printQueueData() {
	Node<T>* trav = frontPtr;
	while (trav) {
		trav->printNodeInfo();
		trav = trav->getNext();
	}
}


#endif
