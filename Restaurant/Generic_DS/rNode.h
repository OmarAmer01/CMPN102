#pragma once
#include<iostream>
using namespace std;
#include "Node.h"
template<typename T>
class rNode :public Node<T> // rNode Means : ranked node
							// as you can see, rNode is a child of Node
{
	float priority;
	rNode* next;

public:
	rNode(const T& data, float priority = 0) :Node<T>(data) { // This CTOR intializes the priority of the node with ZERO, its default Value,
													// While assigning data to the node.
		this->priority = priority;
		next = nullptr;
		Node<T>::setItem(data);
	}

	rNode() { // This is the defualt CTOR of the RankedNode , doesnt assign data, and gives the node priority of zero.
		next = nullptr;
		priority = 0;
	}

	rNode(const T& data, rNode<T>* nextNodePtr, float priority = 0) { // This CTOR assigns data to the node, it's next node in the chain,
																	// and its priority.
		Node<T>::setItem(data);
		this->priority = priority;
		next = nextNodePtr;
	}

	rNode<T>* getNext() const
	{
		return next;
	}

	void setNext(rNode<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	float getPriority() {
		return priority;
	}

	void setPriority(float priority) {
		this->priority = priority;
	}

	void printNodeInfo() { // Only for testing / debugging purposes.
		cout << "Node Item: " << this->getItem() << endl;
		cout << "Node Priority: " << priority << endl;
		if (next) {
			cout << "Item Of Next Node In The Chain: " << next->getItem() << endl;
			cout << "Priority Of Next Node: " << next->getPriority() << endl;
		}
		else {
			cout << "Item Of Next Node In The Chain: NULL" << endl;
		}
		cout << "**************" << endl;
		

	}
};

