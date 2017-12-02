#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void Insert_begining(Node** headPtr, int x) {
	// Insert at the begining when the list is empty
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (*headPtr != NULL) {
		temp->next = *headPtr;
		*headPtr = temp;
	}
	*headPtr = temp; // head will point to temp so this is insertion at the beginning
	//return head;
}

Node*  Insert_ending(Node* head, int x) {
	Node* temp = new Node();
	temp->data = x;
	// use n to traverse
	//Node* head = head;
	while (head->next != NULL) {
		head = head->next;
		cout << "here" << endl;
	}
	head->next = temp;
	return head;
}

void Print(Node* head) {
	//Node* temp = head;
	cout << "List is: " << endl;
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

void Insert_pos(Node** head, int pos, int data) {
	Node* x = new Node();
	x->data = data;
	x->next = NULL;
	if (pos == 1) {
		x->next = *head;
		*head = x;
		return;
	}
	for (int i = 0; i < pos - 2; i++) {
		(*head) = (*head)->next;
	}
	x->next = (*head)->next;
	(*head)->next = x;
}

void Delete(int pos, Node** head) {
	Node* prev = *head;
	// handle case when I want to delete head
	if (pos == 1) {
		*head = prev->next;
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
	Node* head = NULL; //empty
	/*Node* temp = new Node();
	temp->data = 1;
	temp->next = NULL;
	head = temp;*/
	int y, x;
	cin >> x;
	Insert_begining(&head, x);
	cin >> x;
	Insert_begining(&head, x);
	cin >> y;
	Insert_ending(head, y);
	Print(head);
	Insert_pos(&head, 2, 6);
	Print(head);
	Delete(2, &head);
	Print(head);
	return 0;
}