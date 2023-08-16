#include<bits/stdc++.h>
using namespace std;




struct node{
	int data;
	node * parent;
	node * left_child;
	node * right_child;
};


void maketree(node* &root){

	cout<<"enter the value of current node: ";
	cin>>root->data;

	cout<<endl<<"does this "<<root->data<<" node have a left child(y/n): ";
	char ans;
	cin>>ans;

	node * leftchild = new node[sizeof(node)];
	node * rightchild = new node[sizeof(node)];

	root->left_child = leftchild;
	root->right_child = rightchild;


	if(ans=='y'){
		maketree(leftchild);
	}
	else{
		root->left_child = NULL;
	}

	cout<<endl<<"does this "<<root->data<<" node have a right child(y/n): ";
	cin>>ans;
	if(ans=='y'){
		maketree(rightchild);
	}
	else{
		root->right_child= NULL;
	}
	return;
}



void printer(node * root){
	cout<<"current node is "<<root->data<<endl;
	
	if(root->left_child == NULL){
		cout<<root->data<<" has no left child"<<endl;
	}
	else{
		node * leftchild= root->left_child;
		cout<<"its left child is "<<leftchild->data<<endl;
	}

	if(root->right_child == NULL){
		cout<<root->data<<" has no right child"<<endl;
	}
	else{
		node * rightchild = root->right_child;
		cout<<"its right child is "<<rightchild->data<<endl;
	}

	if(root->left_child == NULL){
	}
	else{
		printer(root->left_child);
	}

	if(root->right_child == NULL){
	}
	else{
		printer(root->left_child);
	}	

	return;
}





int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node * root = new node[sizeof(node)];

	maketree(root);

	cout<<"the tree has been made"<<endl;
	cout<<"now the printing begins"<<endl<<endl;

	printer(root);
}