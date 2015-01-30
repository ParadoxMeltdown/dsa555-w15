template <class T>
struct Node{
	T data_;
	Node<T>* next_;
	Node(const T& data,Node<T>* next=NULL){
		data_=data;
		next_=next;
	}
};


template <class T>
class Stack{
	Node<T>* first_;
public:
	Stack();
	void push(const T& data);
	void pop();

	int search(const T& data);
	void print();
};

template <class T>
Stack<T>::Stack(){
	first_=NULL;
}
void Stack<T>::push(const T& data){
	Node* d=new Node(data,first_);
	first_=d;

}
void Stack<T>::pop(){
	if(first_){
		Node* tmp=first_->next_;
		delete first_;
		first_=tmp;
	}
}


void print(){
}