#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;
template <typename Type>
class LinkedList

{
public:

	LinkedList();
	~LinkedList();
	int getLength();
	void print();
	void add(Type);
	void remove(Type);
	int length;
	struct Node

	{

		Type val;

		Node* next;

	};

	Node* head, *tail;

};


/**
* Sets head and tail to null, sets length to be empty.
*/

template <typename Type>
LinkedList<Type>::LinkedList()

{
	head = tail = NULL;
	length = 0;
}

/**
* Destructor for the Linked List.
*/

template <typename Type>
LinkedList<Type>::~LinkedList()

{
	Node* prev = NULL;
	Node* it = head;
	while (it != NULL)

	{
		prev = it;
		it = it->next;
		delete prev;

	}

}

/**
* Prints the whole linked list.
*/

template <typename Type>
void LinkedList<Type>::print()

{
	int index = 0;
	Node* it = head;
	while (it != NULL)

	{
		//if (it == NULL) return;
		std::cout << "{" << index << ":" << it->val << "}";
		if (it->next != NULL)

		{
			std::cout << "->";
		}

		it = it->next;
		index++;
	}
}

/**
* @return the number of nodes in the linked list.
*/

template <typename Type>
int LinkedList<Type>::getLength()

{
	return length;
}

template <typename Type>
void LinkedList<Type>::add(Type value)

{
	Node* newNode = new Node;
	newNode->val = value;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = tail = newNode;
	}

	else

	{
		tail->next = newNode;
		tail = newNode;
	}

	length++;

}

/**
* Removes all nodes that have the value passed in.
* @param value The value you want to remove.
*/

template <typename Type>
void LinkedList<Type>::remove(Type value)

{
	Node* it = head;
	Node* prev = NULL;
	while (it->next != NULL)

	{
		if (it->val == value)
		{
			if (prev == NULL)
			{
				head = it->next;
				delete it;
			}

			else

			{
				prev->next = it->next;
				delete it;
			}

		}

		prev = it;
		it = it->next;
	}
	length--;
}
