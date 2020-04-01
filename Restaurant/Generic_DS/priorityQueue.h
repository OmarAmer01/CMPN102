#pragma once
#include"rNode.h"
template <typename T>
class priorityQueue
{
	rNode<T>* frontPtr;
	rNode<T>* backPtr;
public:

	priorityQueue() {
		frontPtr = nullptr;
		backPtr = nullptr;
	}
	//hhhhhhhhhhhhhhhhhhhhhh


	priorityQueue<T>(const priorityQueue<T>& src) {
		frontPtr = nullptr;
		backPtr = nullptr;
		rNode<T>* pNode = src.frontPtr;
		
		while (pNode) {
			enqueue(pNode->getItem(),pNode->getPriority());
			pNode = pNode->getNext();
			
		}

	}

	//T getHighestPriority() {
	//	rNode<T>* trav = frontPtr;
	//	rNode<T>* maxPriority = trav;

	//	//int currentMaxNodePriority = trav->getPriority();


	//	while (trav) { // while trav isn't NULL
	//		if (trav->getPriority() > maxPriority->getPriority()) {
	//			//assign trav's priortiy to maxPriority.
	//			maxPriority->setPriority(trav->getPriority());
	//			maxPriority = trav;
	//		}

	//		trav = trav->getNext(); // move trav to the next rNode
	//	}

	//	return maxPriority->getItem();
	//}

	//rNode<T>* getPtrToNodeOfHighestPriority() {
	//	rNode<T>* trav = frontPtr;
	//	rNode<T>* maxPriority = trav;

	//	//int currentMaxNodePriority = trav->getPriority();


	//	while (trav) { // while trav isn't NULL
	//		if (trav->getPriority() > maxPriority->getPriority()) {
	//			//assign trav's priortiy to maxPriority.
	//			maxPriority->setPriority(trav->getPriority());
	//			maxPriority = trav;
	//		}

	//		trav = trav->getNext(); // move trav to the next rNode
	//	}

	//	return maxPriority;
	//}

	void enqueue(const T& newEntry, float priority) {
		rNode<T>* newNodePtr = new rNode<T>(newEntry, priority);

		if (isEmpty()) { // The queue is empty
			frontPtr = newNodePtr;
			backPtr = newNodePtr;
			return;
		}
		else {
			rNode<T>* trav = frontPtr;

			while (trav) {
				if (newNodePtr->getPriority() > trav->getPriority()) {
					/*if (trav = frontPtr) {
						newNodePtr->setNext(trav->getNext());
						trav->setNext(newNodePtr);
						return;
					}
					else {
						

					}*/

					if (trav == frontPtr) {
						newNodePtr->setNext(trav);
						frontPtr = newNodePtr;
						return;
					}
					else {
						newNodePtr->setNext(trav->getNext());
						trav->setNext(newNodePtr);
						return;

					}
				}
				else if (trav->getNext() == nullptr) {
					trav->setNext(newNodePtr);
					backPtr = newNodePtr;
					return;
				}
				else if (trav->getNext()->getPriority() < newNodePtr->getPriority()) {
					newNodePtr->setNext(trav->getNext());
					trav->setNext(newNodePtr);
					return;
				}
				else {
					trav = trav->getNext();

				}

			}
		}


	}



	bool isEmpty() const
	{
		if (frontPtr == nullptr)
			return true;
		else
			return false;
	}

	bool dequeue(T& frntEntry)
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

	//template <typename T>


	bool priorityQueue<T>::dequeueWithOrderID(int ID, Order removed) { // bta5od el id w pass by refernce variable esmo removed dh ele hyt7t
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

		rNode<T>* trav = getPtrToFront();
		rNode<T>* trav2 = trav->getNext();
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

	bool peekFrontItem(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;

	}
	
	rNode<T>* getPtrToFront() {
		return frontPtr;
	}

	void printQueueData() {
		rNode<T>* trav = frontPtr;
		while (trav) {
			trav->printNodeInfo();
			trav = trav->getNext();
		}
		if (frontPtr == nullptr) {
			cout << "The Queue Is Empty";
		}
	}


	T* toArray(int& count)
	{
		count = 0;

		if (!frontPtr)
			return nullptr;
		//counting the no. of items in the Queue
		rNode<T>* p = frontPtr;
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
};

