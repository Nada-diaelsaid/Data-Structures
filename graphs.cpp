#include <iostream>
using namespace std;

struct Node
{
	int dest;
	int weight;
	Node* next;
};

Node** CreateGraph(int v){
	Node** heads;
	heads = new Node*[v];
	for(int i = 0; i < v; ++i) {
		// heads[i] = new Node;
		heads[i] = nullptr;
	}
	return heads;
}

void AddVertex_Connections(Node** heads, int v, int src, int dest, int weight){
	Node* x = new Node;
	x->dest = dest;
	x->weight = weight;
	x->next = nullptr;
	Node* temp = heads[src];

	if(heads[src] == nullptr){
		heads[src] = x;
		// cout << "ok";
		return;
	}

	while(temp->next!= nullptr){
		// cout << "hello";
		// cout << temp[src]->dest<<" ";
		temp = temp->next;
	}
	temp->next = x;
}

bool BFS(Node** heads, int src, int dest){
	Node* temp = heads[src];
	// cout << temp->dest;
	while(temp != nullptr){
		if(temp->dest == dest){
			// cout <<" " <<temp->dest << " ";
			return true;
		}
		else
			temp = temp->next;
	}
	// cout << "end\n";
	return false;
}


int main(){
	int v;
	cin >> v;
	Node** heads;
	heads = CreateGraph(v);
	int src;
	int dest, weight;
	cin >> src;
	cin >> dest;
	cin >> weight;

	// Node* temp = new Node;
	// Node* temp1 = new Node;
	// temp->dest = dest;
	// temp->weight = weight;
	// temp->next = temp1;
	// heads[src] = temp;
	// temp1->dest = dest;
	// temp1->weight = weight;
	// temp1->next = NULL;
	// temp1 = temp;

	AddVertex_Connections(heads, v, 0, 1, weight);
	AddVertex_Connections(heads, v, 0, 2, weight);
	AddVertex_Connections(heads, v, 0, 3, weight);
	AddVertex_Connections(heads, v, 1, 2, weight);

	cout << "BFS: "<< BFS(heads, 0, 3) << " " << BFS(heads, 0, 5) << endl;
	
	cout << "print\n";
	for(int i=0; i<v;i++){
		while(heads[i]!=NULL){
			// cout << "hello";
			if(heads[i]==NULL)
				cout << "x ";
			cout << heads[i]->dest<<" ";
			heads[i] = heads[i]->next;
		}
		cout << endl;
	}


	return 0;
}		