#include<iostream>
using namespace std;

class Solution{

public:

	int CountNode(Node* root){
		if(root == NULL){
			return 0;
		}
		return 1 + CountNode(root->left) + CountNode(root->right);
	}


	bool isCBT(Node* root,int index,int count){
		if(!root){
			return true;
		}
		if(index >= count){
			return false;
		}
		
		int left = isCBT(root->left,2*index+1,count);
		int right = isCBT(root->right,2*index+2,count);

		return left && right;

	}

	bool MaxOrder(Node* root){
		if(!root){
			return true;
		}
		if(root->left == NULL && root->right == NULL){
			return true;
		}
		if(root->right == NULL){
			return root->data > root->left->data;
		}
		else{
			bool left = MaxOrder(root->left);
			bool right = MaxOrder(root->right);
			return (left && right && (root->data > root->left->data) && (root->data > root->right->data))
		}
	}


	bool isHeap(Node* root)
};