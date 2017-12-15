#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
	Node* left;
	int key;
	Node* right;
};
class BST {

public:
	Node* root;
    BST()
    {
        root = NULL;
    }
    Node* insert(Node*, int);
    void inorder(Node*);
    int depthOfTree(Node*);

};
 
  
void BST::inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
  

int BST::depthOfTree(Node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       int left = depthOfTree(node->left);
       int right = depthOfTree(node->right);
 
        // use the larger one 
       if (left > right) 
           return(++left);
       else return(++right);
   }
} 

Node* BST::insert(Node* node, int key)
{
    if (node == NULL){
    	Node *temp = new Node;
	    temp->key = key;
	    temp->left = temp->right = NULL;
	    return temp;
    }
 
    if (key <= node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}
  
int main()
{
	BST* bst = new BST;
    bst->root = bst->insert(bst->root, 50);
    bst->insert(bst->root, 30);
    bst->insert(bst->root, 20);
    bst->insert(bst->root, 40);
    bst->insert(bst->root, 70);
    bst->insert(bst->root, 60);
    bst->insert(bst->root, 80);
    // print inoder traversal of the BST
    bst->inorder(bst->root);
    cout << "\n";
    cout << "depth is " << bst->depthOfTree(bst->root) << endl;
    return 0;
}