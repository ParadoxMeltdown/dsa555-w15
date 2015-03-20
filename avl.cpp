#include<iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

struct Node{
	int data_;
	Node* left_;
	Node* right_;
	int heightBalance_;//height of right subtree-height
	                   //of left subtree
	Node(int data,Node* left=nullptr,Node*right=nullptr){
		data_=data;
		left_=left;
		right_=right;
		heightBalance_=0;
	}
};

class AVL{
	Node* root_;
	/*this function inserts data into the subtree
	  with root at subtreeroot.  It returns a 1 if
	  the tree got taller as a result of the insertion*/
    int insertR(int data, Node*& subtreeroot);
    void print(Node* subtreeroot);
    void rotateLeft(Node*& root);
    void rotateRight(Node*& root);
public:
	AVL();
	void insert(int data);
	Node* search(int data);
    void print();
	void breadthFirstPrint();
	void depthFirstPrint();
	~AVL(){}
};

void AVL::rotateLeft(Node*& root){
	Node* A=root;
	Node* B=root->right_;
	Node* Y=B->left_;
	B->left_=A;
	A->right_=Y;
	root_=B;
}
void AVL::rotateRight(Node*& root){
}
AVL::AVL(){
	root_=nullptr;
}
void AVL::print(){
	print(root_);
}
void AVL::print(Node* subtreeroot){
	if(subtreeroot){
		print(subtreeroot->left_);
		cout << subtreeroot->data_ <<endl;
		print(subtreeroot->right_);
	}
}
void AVL::breadthFirstPrint(){
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


void AVL::insert(int data){
	insertR(data,root_);
}
void AVL::insertR(int data, Node*& subtreeroot){
	int rc;
	if(!subtreeroot){
		subtreeroot=new Node(data);
		rc=1;
	}
	else{
		int result;
		if(data < subtreeroot->data_){
			result=insertR(data,subtreeroot->left_);
			if(result==1){
				subtreeroot->heightBalance_-=1;
				if(subtreeroot->heightBalance==-2){
					if(subtreeroot->left_->heightBalance_ < 0){
						rotateRight(subtreeroot);
					}
				}
				else if(subtreeroot->heightBalance==-1)
					rc=1;
				}
				else{
					rc=0;
				}
			}

		}
		else{
			result=insertR(data,subtreeroot->right_);
		}
	}
}

Node* AVL::search(int data){
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


int main(void){
	AVL tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(1);
	tree.insert(12);
	tree.insert(14);
	tree.insert(16);

	tree.print();

//	tree.depthFirstPrint();

}


