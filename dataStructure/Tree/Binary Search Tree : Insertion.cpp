// problem source: https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node* root, int data) {
        Node* newNode = new Node(data);
        Node* current = root;
        
        if(current == nullptr){
            return newNode;
        }
        while(current != nullptr){
            if(data <= current->data){
                if(current->left == nullptr){
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }else{
                if(current->right == nullptr){
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }

        }
        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
