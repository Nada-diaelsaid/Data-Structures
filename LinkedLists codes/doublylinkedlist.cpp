
//#include "stdafx.h"
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

	void insert(int a) {
		Node* x = new Node(); /// Node to be inserted
		x->value = a;
		x->next = NULL;
		x->prev = NULL;
		Node* temp = head;
		if (head == NULL) {
			x->next = head;
			head = x;
			last = x;
			return;
		}
		while (temp != NULL) {
			// cout << temp->next->value;
			if (x->value > temp->next->value) {
				
			temp = temp->next;
			}
			// cout << "here";
				x->next = temp->next;
				x->prev = temp;
				temp->next->prev = x;
				temp->next = x;
				temp = x;
				x = temp->next;
			// else if(){

			// }
			return;

		}
	}
void insert_pos(int n,int data)
{
	Node *temp;
	Node *d = new Node();
	d->value = data;
	temp = head;
	for (int i=0; i < n-2 ;i++)
	{
		temp=temp->next;
	}
	d->next = temp->next;
	temp->next->prev = d;
	d->prev = temp;
	temp->next = d;	
}
void add( int value)
{
	Node *x = new Node();
	x->value = value;
	x->next = NULL;
		Node* temp ;
		temp = head;
		if (head == NULL)
		{
			head = x;
			x -> prev = NULL;
		}
		else 
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = x;
			x->prev = temp;
		}
	
}
	void print()
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
};
int main()
{
	SortedDoublyLinkedList* s = new SortedDoublyLinkedList();
	s->insert(-1);
	// s->print();
	s->add(3);
	// s->print();
	//s->add(4);
	s->add(6);
	s->insert_pos(2, 9);
	s->insert_pos(3, 5);
	s->print();
	s->insert_pos(5, 11);
	s->print();
	
	// s->insert(2);
	// s->print();
	// // s->print();
	// s->insert(5);
	// s->print();
	// s->insert(4);
	// s->print();
	return 0;
}