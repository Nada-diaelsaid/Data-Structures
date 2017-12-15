#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;	
};

struct Node* head;

void InsertAtHead(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;

}

void insertEnd( int value)
{
	Node *x = new Node();
	x->data = value;
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
void insert_pos(int n,int data)
{
	Node *temp;
	Node *d = new Node();
	d->data = data;
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
void ReversePrirnt() {
	Node* node = head;
	if (node == NULL) // empty list
	{
		return;
	}
	while (node->next!=NULL) {
		node = node->next;

	}
	while (node != NULL) {
		cout << node->data << " ";
		node = node->prev;
	}
}

void print()
{
	Node *temp = head;
	if (head != NULL) {
		while (temp->next != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}
int main() {
	InsertAtHead(3);
	InsertAtHead(4);
	InsertAtHead(6);
	insert_pos(2,5);
	insertEnd(10);
	print();
	ReversePrirnt();

	return 0;
}