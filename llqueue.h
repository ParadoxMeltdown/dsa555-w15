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
class List{
	Node<T>* first_;
	Node<T>* last_;
public:
	Queue();
	void enqueue(const T& data);
	void dequeue();
	void print();
};

template <class T>
Queue<T>::Queue(){
	first_=last_=NULL;
}

void Queue<T>::dequeue(){
	if(first_){
		Node* tmp=first_->next_;
		delete first_;
		first_=tmp;
		if(!first_)
			last_=NULL;
	}
}

template <class T>
void Queue<T>::enqueue(const T& data){
	if(first_){
		Node* d=new Node(data);
		last_->next_=d;
		last_=d;
	}
	else{
		Node* d=new Node(data,first_);
		last_=first_=d;		
	}
}
