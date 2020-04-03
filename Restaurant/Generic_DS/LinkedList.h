#pragma once
#include<iostream>
using namespace std;
#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	/*bool isEmpty(){// added by hamzawy
	if (Head==nullptr){
		return true ;
		}else{
		return false;
		}
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}


	Node<T>* getHead() {
		return Head;
	}
	void setHead(Node<T>* node) {
		Head = node;
	}


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data) {
		Node<T>* R = new Node<T>(data);
		if (Head == nullptr) {
			Head = R;
			return;
		}
		Node<T>* trav = Head;
		while (trav->getNext()) {
			trav = trav->getNext();
		}
		trav->setNext(R);

	}

	//[2]Find 
	//searches for a given value in the list, returns the node if found; null otherwise.
	Node<T>* Find(T Key) {
		Node<T>* ptr = Head;
		while (ptr) {
			if (ptr->getItem() == Key) {
				return true;
			}
			ptr = ptr->getNext();
		}
		return false;

	};

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value) {
		int count = 0;
		Node<T>* ptr = Head;
		while (ptr) {
			if (ptr->getItem() == value)
			{
				count++;
			}
			ptr = ptr->getNext();
		}
		return count;
	};

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst() {
		if (Head == nullptr)
			return;
		Node<T>* ptrTMP = Head;
		Head = Head->getNext();
		delete ptrTMP;

	};


	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast() {
		Node<T>* ptr = Head;
		Node<T>* beforePtr = Head;
		if (Head == nullptr)
			return;
		while (ptr->getNext()) {
			ptr = ptr->getNext();
		}
		while (beforePtr->getNext() != ptr) {
			beforePtr = beforePtr->getNext();
		}
		if (ptr == nullptr)
			return;
		beforePtr->setNext(nullptr);
		delete ptr;
		ptr = nullptr;
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value) {
		if (this->Find(value) == false) {
			return false;
		}
		Node<T>* ptr = Head;
		Node<T>* beforePtr = Head;
		while (ptr->getItem() != value) { //ptr = el pointer ele 3ayz al8eeh
			ptr = ptr->getNext();
		}

		if (ptr == Head) {
			this->DeleteFirst();
			return true;
		}
		if (ptr->getNext() == nullptr) {
			this->DeleteLast();
			return true;
		}
		while (beforePtr->getNext() != ptr) { // ymkn asheel el negative?
			beforePtr = beforePtr->getNext(); // beforePtr = el pointer ele ablo
		}
		beforePtr->setNext(ptr->getNext());
		delete ptr;
		ptr = nullptr;
		return true;
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value) {
		if (this->Find(value) == false) {
			return false;
		}
		int count_ = 0;
		count_ = this->CountOccurance(value);
		for (int i = 0; i < count_; i++) {
			if (this->Find(value) == false) {
				return false;
			}
			this->DeleteNode(value);
		}
		return true;
	}



};


