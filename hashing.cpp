#include <iostream> 
using namespace std;
#define SIZE 20
/// Hashs array based implementation
struct Cell {
   int data;   
   int key;
};

Cell* hashArray[SIZE]; 
// Get hash using linear probing in closed hash
int hashFunction(int key){
   return key % SIZE;
}
void deleteCell(Cell* item) {
	Cell* temp = new Cell;
	int key = item->key;

	//get the hash 
	int hashIndex = hashFunction(key);

	//move in array until an empty
	while(hashArray[hashIndex] != NULL) {

		if(hashArray[hashIndex]->key == key) {
	    // Cell* temp = hashArray[hashIndex]; 
			
	    	hashArray[hashIndex] = temp; 
	}
		
	  //go to next cell
	++hashIndex;
		
	  //wrap around the table
	hashIndex %= SIZE;
	}      
}

void insert(int key,int data) {
	Cell* item = new Cell;
	item->data = data;  
	item->key = key;     

	int hashIndex = hashFunction(key);

	//move in array until an empty
	while(hashArray[hashIndex] != NULL) {
	  //go to next cell
	  hashIndex++;
		
	  //wrap around the table
	  hashIndex =hashFunction(hashIndex);
	}

	hashArray[hashIndex] = item;        
}
Cell *search(int key) {
	int hashIndex = hashFunction(key);  

	//move in array until an empty 
	while(hashArray[hashIndex] != NULL) {

		if(hashArray[hashIndex]->key == key)
	    	return hashArray[hashIndex]; 
			
		//go to next cell
		hashIndex++;

		//wrap around the table
		hashIndex %= SIZE;
	}        

return NULL;        
}

void display() {
	for(int i = 0; i<SIZE; i++) {

	  if(hashArray[i] != NULL)
	     cout << "(" << hashArray[i]->key << ","<<hashArray[i]->data << ")" << ",";
	  else
	     cout << "--" << ",";
	}

	cout << endl;
}

int main() {
	Cell* temp = new Cell;
	temp->data = -1;  
	temp->key = -1; 

	insert(1, 20);
	insert(2, 70);
	insert(42, 80);
	insert(4, 25);
	insert(12, 44);
	insert(14, 32);
	insert(17, 11);
	insert(13, 78);
	insert(37, 97);


	display();
	Cell* item = new Cell;
	item = search(37);

	if(item != NULL) {
	  cout << "Element found " << item->data << endl;
	} else {
	  cout << "Element not found\n";
	}

	deleteCell(item);
	item = search(37);

	if(item != NULL) {
	  cout << "Element found: " <<  item->data << endl;
	} else {
	  cout << "Element not found\n";
	}
}