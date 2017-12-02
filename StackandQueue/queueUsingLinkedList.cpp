#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    Node* next;
};
class Queue
{
    Node* front;
    Node* rear;
    public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    //////////// ALL operations are at constant time O(1)
    void enqueue(int); 
    void dequeue();
    void print();
    bool isEmpty();
};

void Queue::enqueue(int value){
	Node* x = new Node;
	x->data = value;
	x->next = NULL;
	if(front==NULL && rear==NULL){
		front = rear = x;
		// cout <<"tmam";
		return;
	}
	rear->next = x;
	rear = x;
	// cout <<"hmm";
}
void Queue::dequeue(){
	if(front==NULL)// List is empty
	{
		return;
	}
	if(front==rear)// One node in the queue
	{
		front = rear = NULL;
	}
	Node* temp = front;
	front = front->next;
	delete temp;
}

bool Queue::isEmpty(){
	if(front == NULL && rear == NULL)
		return true;
	else
		return false;
}

void Queue::print()
{
    Node *temp=front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

int main()
{
    Queue* queue = new Queue;
    int in;

    cout << "Queue is "<< (queue->isEmpty() ? "Empty":"Not Empty") << endl;
    cout << "enter number"<< endl;
    cin>>in;
   	queue->enqueue(in);
    queue->print();

    cout << "enter number"<< endl;
	cin>>in;
   	queue->enqueue(in);
    queue->print();

    cout << "enter number" << endl;
   	cin>>in;
   	queue->enqueue(in);
    queue->print();

    cout << "Queue is "<< (queue->isEmpty() ? "Empty":"Not Empty") << endl;

   	queue->dequeue();
    queue->print();
    return 0;
}