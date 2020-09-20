// problem source: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        stack<Node*> sta1;
        stack<Node*> sta2;
        Node* current = root;
        sta1.push(root);
        sta2.push(root);
        while(current->data != v1){
            if(current->data > v1){
                current = current->left;
            }else{
                current = current->right;
            }
            sta1.push(current);
        }
        current = root;
        while(current->data != v2){
            if(current->data > v2){
                current = current->left;
            }else{
                current = current->right;
            }
            sta2.push(current);
        }

        while(sta1.size() != sta2.size()){
            if(sta1.size() > sta2.size()){
                sta1.pop();
            }else if(sta1.size() < sta2.size()){
                sta2.pop();
            }
        }

        while(true){
            if(sta1.top() == sta2.top()){
                break;
            }else{
                sta1.pop();
                sta2.pop();
            }
        }
        return sta1.top();

    }


}; //End of Solution

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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
