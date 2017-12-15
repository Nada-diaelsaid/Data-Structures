#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	int data;
	Node* next;
};
// Declare has as global variable
Node* head = NULL;

void Insert_begining(int x) {
	// Insert at the begining when the list is empty
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (head != NULL) {
		temp->next = head;
		head = temp; 
	}
	head = temp; // head will point to temp so this is insertion at the beginning
}

void Insert_ending(int x) {
	Node* temp = new Node();
	temp->data = x;

	// use n to traverse
	Node* n = head;
	while (n->next != NULL) {
		n = n->next;
		cout << "here" << endl;
	}
	n->next = temp;
}

void Insert_pos(int data, int pos) {
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	// Handle to insert at head (when pos = 1)
	if (pos == 1) {
		temp1->next = head; // temp points to whatever head points
		head = temp1; // head points to new node
		return;
	}
	Node* temp2 = head; // to traverse until we reach n-1 node 
	for (int i = 0; i < pos - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1 ;
}

void Print() {
	Node* temp = head;
	cout << "List is: " << endl;
	while (temp != NULL) {
		cout << temp->data << " ";	
		temp = temp->next;
	}
}

void Delete(int pos) {
	Node* prev = head;
	// handle case when I want to delete head
	if (pos == 1) {
		head = prev->next;
		delete prev;
		return;
	}
	// handle case that the node has a node before it
	for (int i = 0; i < pos - 2; i++) {
		prev = prev->next;
	}
	Node* currNode = prev->next; // nth node
	prev->next = currNode->next; // n+1 th node
	delete currNode; // don't forget to free the memory

}

int main() {
	head = NULL; //empty
	/*Node* temp = new Node();
	temp->data = 1;
	temp->next = NULL;
	head = temp;*/
	int y, x;
	cin >> x;
	Insert_begining(x); // 1 for ex
	/*cin >> x;
	Insert_begining(x);*/
	cin >> y;
	Insert_ending(y); // 2 for ex 
	Print(); // List is: 1 2 
	cin >> x; // let it 2 for ex 
	Insert_pos(4, x); 
	int n;
	Print();// List is: 1 4 2
	cout << "Insert pos to be deleted \n" ;
	cin >> n;
	Delete(
		n);
	Print(); // List is: 1 2 
	return 0;
}
