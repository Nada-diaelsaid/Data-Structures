#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    Node* next;
};
 
class Stack
{
    Node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    //////////// ALL operations are at constant time O(1)
    void push(int); 
    void pop();
    void print();
    bool isEmpty();
};

void Stack::push(int value)
{
	// At the begining
    Node *x = new Node;
    x->data=value;
    x->next=NULL;
    if(top!=NULL)
        x->next=top;
    top=x;
}
 

void Stack::pop()
{
	Node *temp;
    if(top==NULL)
    {
        return;
    }
    temp=top;
    top=top->next;
    delete temp;
}

void Stack::print()
{
    Node *temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

bool Stack::isEmpty(){
	if(top == NULL)
		return true;
	return false;
}

int main()
{
    Stack* s = new Stack;
    int in;

    cout << "Stack is "<< (s->isEmpty() ? "Empty":"Not Empty") << endl;
    cout << "enter number"<< endl;
    cin>>in;
   	s->push(in);
    s->print();

    cout << "enter number"<< endl;
	cin>>in;
   	s->push(in);
    s->print();

    cout << "enter number" << endl;
   	cin>>in;
   	s->push(in);
    s->print();

    cout << "Stack is "<< (s->isEmpty() ? "Empty":"Not Empty") << endl;

   	s->pop();
    s->print();
    return 0;
}