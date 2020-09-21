// problem source: https://www.hackerrank.com/challenges/is-binary-search-tree/problem

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    Node* lastNode;

    bool inOrderTraversal(Node* root){
        if(root == nullptr){
            return true;
        }
        
        if(!inOrderTraversal(root->left)){
            return false;
        }

        if(lastNode != nullptr && root->data <= lastNode->data){
            return false;
        }
        
        lastNode = root;
        
        return inOrderTraversal(root->right);
        
    }    

    bool checkBST(Node* root) {
        return inOrderTraversal(root);
        
    }
