// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct Node {
int value;
Node* next;
Node* prev;
};

class SortedDoublyLinkedList {
	Node* head;
	Node* last;

public:
	SortedDoublyLinkedList() {
		head = NULL;
		last = NULL;
	}
	void insert(int a);
	void print();
};

void SortedDoublyLinkedList::insert(int a) {
		Node* x = new Node(); // Node to be inserted
		x->value = a;
		x->next = NULL;
		x->prev = NULL;
		Node* temp = head;
		if (head == NULL) // Empty linked list
		{
			x->next = head;
			head = x;
			last = x;
			return;
		}
		// Insert at head
		else if (x->value < temp->value) {
			temp->prev = x;
			x->next = temp;
			head = x;
			return;
		}
		// Insert in the middle
		while (temp->next != NULL) {
			if (x->value > temp->next->value)
				temp = temp->next;
			else {
				x->next = temp->next;
				x->prev = temp;
				temp->next->prev = x;
				temp->next = x;
				temp = x;
				x = temp->next;
				return;
			}
		}
		// Insert at the end
		x->prev = temp->next;
		temp->next = x;
		last = x;
	}
void SortedDoublyLinkedList::print()
{
	Node *temp = head;
	if (head != NULL) {
		while (temp->next != NULL) {
			cout << temp->value << "  ";
			temp = temp->next;
		}
		cout << temp->value << endl;
	}
}


int main()
{
	SortedDoublyLinkedList* s = new SortedDoublyLinkedList();

	s->insert(14);
	s->print();
	
	s->insert(5);
	s->print();
	
	s->insert(0);
	s->print();
	
	s->insert(2);
	s->print();
	
	s->insert(6);
	s->print();

	s->insert(3);
	s->print();

	s->insert(16);
	s->print();

	return 0;
}
