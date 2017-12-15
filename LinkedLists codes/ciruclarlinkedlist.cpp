#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};
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
bool circular(struct Node *head)
{
	struct Node *temp = head->next;
	if (head == NULL) // if empty linked list then it is circular 
		return true;	

	while (temp != NULL && temp != head)
		temp = temp->next;

	if(temp == head) 	return true;
	return false;
}

int main()
{
	/* code */
	Insert_begining(3);
	Insert_begining(5);

	cout << circular(head);
	return 0;
}