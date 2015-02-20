#include<iostream>
using namespace std;

struct Node{
	int data_;
	Node* left_;
	Node* right_;
};

class BST{
	Node* root_;
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






