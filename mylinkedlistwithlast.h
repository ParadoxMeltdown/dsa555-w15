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
	List();
	void insertFront(const T& data);
	void removeFront();
	void insertBack(const T& data);
	void removeBack();
	int search(const T& data);
	void print();
};

template <class T>
List<T>::List(){
	first_=last_=NULL;
}
void insertFront(const T& data){
	Node* d=new Node(data,first_);
	first_=d;
	if(!last_)
		last_=d;
}
void removeFront(){
	if(first_){
		Node* tmp=first_->next_;
		delete first_;
		first_=tmp;
		if(!first_)
			last_=NULL;
	}
}

template <class T>
void insertBack(const T& data){
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

void removeBack(){
	if(first_){
		Node* end=first_;
		Node* secondLast=NULL;
		while(end->next_){
			secondLast=end;
			end=end->next_;
		}
		delete end;
		if(secondLast){
			secondLast->next_=NULL;
		}
		else{
			first_=NULL;	
		}
		last_=secondLast;
	}
}
void print(){
}