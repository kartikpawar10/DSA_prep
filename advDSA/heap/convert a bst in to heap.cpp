#include<iostream>
#include<vector>
using namespae std;


void solve(Node* root,vector<int>save,vector<int>&ans,int &index){
	if(!root) return;
	ans.push_back(save[index]);
	index++;
	solve(root->left,save,ans,index);
	solve(root->right,save,ans,index);
}
void inorder(Node* root,vector<int>&save){
	if(!root) return;
	inorder(root->left);
	save.push_back(root->data);
	inorder(root->right);
}

void bstToHeap(Node* root,vector<int>&ans){
	vector<int>save;
	int index = 0;
	inorder(root,save);
	solve(root,save,ans,index);
}

int main(){
	return 0;
}