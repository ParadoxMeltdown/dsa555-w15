#include<iostream>
using namespace std;

struct Node{
	int data_;
	Node* left_;
	Node* right_;
	Node(int data,Node* left=nullptr,Node*right=nullptr){
		data_=data;
		left_=left;
		right_=right;
	}
};

class BST{
	Node* root_;
	Node* searchR(int data,Node* subtreeroot);
public:
	BST();
	void insert(int data);
	Node* search(int data);
	void remove(int data);
	~BST();
};

BST::BST(){
	root_=nullptr;
}
void BST::insert(int data){
	if(root_){
		Node* curr=root_;
		bool found=false;
		while(!found){
			if(data < curr->data_){
				if(curr->left_){
					curr=curr->left_;
				}
				else{
					curr->left_=new Node(data);
					found=true;
				}
			}
			else{
				if(curr->right_){
					curr=curr->right_;
				}
				else{
					curr->right_=new Node(data);
					found=true;
				}
			}
		}
	}
	else{
		root_=new Node(data);
	}
}

Node* BST::search(int data){
	Node* curr=root_;
	while(curr && curr->data_ != data){
		if(data < curr->data_){
			curr=curr->left_;
		}
		else{
			curr=curr->right_;
		}
	}
	return curr;
}
Node* BST::searchR(int data){
	return searchR(data,root_);
}
Node* BST::searchR(int data,Node* subtreeroot){
	Node* rc=nullptr;
	if(subtreeroot){
		if(data == subtreeroot->data_){
			rc=subtreeroot;
		}
		else if(data < subtreeroot->data_){
			rc=searchR(data,subtreeroot->left_);
		}
		else{
			rc=searchR(data,subtreeroot->right_);
		}
	}
	return rc;
}




