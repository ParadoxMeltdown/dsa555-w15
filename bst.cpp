#include<iostream>
#include "queue.h"
#include "stack.h"
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
    void insertR(int data, Node*& subtreeroot);
    Node* insertR2(int data, Node*& subtreeroot);
    void remove(int data, Node*& subtreeroot);
    void print(Node* subtreeroot);
public:
	BST();
	void insert(int data);
	Node* search(int data);
	Node* searchR(int data);
	void remove(int data);
	void print();
	void breadthFirstPrint();
	void depthFirstPrint();
	~BST(){}
};

BST::BST(){
	root_=nullptr;
}
void BST::print(){
	print(root_);
}
void BST::print(Node* subtreeroot){
	if(subtreeroot){
		print(subtreeroot->left_);
		cout << subtreeroot->data_ <<endl;
		print(subtreeroot->right_);
	}
}
void BST::breadthFirstPrint(){
    if(root_){
		Queue<Node*> q;
		q.enqueue(root_);
		while(!q.isEmpty()){
			Node* curr=q.front();
			q.dequeue();
			if(curr->left_){
				q.enqueue(curr->left_);
			}
			if(curr->right_){
				q.enqueue(curr->right_);
			}
			cout << curr->data_ << endl;
		}
    }
}
/*this function finds and removes node with data from the tree*/
void BST::remove(int data){
	remove(data,root_);
}
void BST::remove(int data, Node*& subtreeroot){
	if(subtreeroot){
		if(data == subtreeroot->data_){
			/* remove it - unlink, and deallocate*/
			if(subtreeroot->left_ && subtreeroot->right_){
				//two children
				Node* parentofIS=nullptr;
				Node* inorderSuccessor=subtreeroot->right_;
				Node* rm=subtreeroot;
				while(inorderSuccessor->left_){
					parentofIS=inorderSuccessor;
					inorderSuccessor=inorderSuccessor->left_;
				}
				if(parentofIS){
					parentofIS->left_=inorderSuccessor->right_;
					inorderSuccessor->left_=subtreeroot->left_;
					inorderSuccessor->right_=subtreeroot->right_;
					subtreeroot=inorderSuccessor;
				}
				else{
					//this only occurs if the inorder successor is
					//the immediate right child of the node we are removing
					inorderSuccessor->left_=subtreeroot->left_;
					subtreeroot=inorderSuccessor;
				}

			}
			else if(!subtreeroot->left_ && !subtreeroot->right_){
				//no children
				delete subtreeroot;
				subtreeroot=nullptr;
			}
			else{
				//one child
				Node* rm = subtreeroot;
				subtreeroot = (subtreeroot->left_)?
				    (subtreeroot->left_):(subtreeroot->right_);
				delete rm;
			}
		}
		else{
			if(data < subtreeroot->data_){
				remove(data, subtreeroot->left_);
			}
			else { //data > subtreeroot->data_
				remove(data, subtreeroot->right_);
			}
		}
	}
}

/*
void BST::insert(int data){
	root_=insertR2(data,root_);
}
Node* BST::insertR2(int data, Node* subtreeroot){
	Node* rc=subtreeroot;
	if(!subtreeroot){
		rc=new Node(data);
	}
	else{
		if(data < subtreeroot->data){
			subtreeroot->left_=insertR2(data,subtreeroot->left_);
		}
		else{
			subtreeroot->right_=insertR2(data,subtreeroot->right_);			
		}
	}
	return rc;
}
*/
void BST::insert(int data){
	insertR(data,root_);
}
void BST::insertR(int data, Node*& subtreeroot){
	if(!subtreeroot){
		subtreeroot=new Node(data);
	}
	else{
		if(data < subtreeroot->data_){
			insertR(data,subtreeroot->left_);
		}
		else{
			insertR(data,subtreeroot->right_);
		}
	}
}
/*void BST::insert(int data){
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
*/
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
//inorder Depth first print without recursion
void BST::depthFirstPrint(){
    if(root_){
		Stack<Node*> s;
		s.push(root_);
		while(!s.isEmpty()){
			Node* curr=s.top();
			s.pop();
			if(curr->left_){
				s.push(curr->left_);
			}
			cout << curr->data_ << endl;
			if(curr->right_){
				s.push(curr->right_);
			}
		}
    }	
}

int main(void){
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(1);
	tree.insert(12);
	tree.insert(14);
	tree.insert(16);

//	tree.print();

	tree.depthFirstPrint();

}


