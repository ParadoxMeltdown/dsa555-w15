template <class T>
class Stack{
    T* data_;
    int max_;
    int count_;
    void grow();
public:
	Stack(int cap=50);
	void push(const T& data);//add to stack
	void pop();  //remove from stack
	int search(const T& data);
	void print();
	bool isEmpty(){return count_==0;}
	T top(){return data_[count_-1];}
};

template <class T>
Stack<T>::Stack(int cap){
	data_=new T[cap];
	max_=cap;
	count_=0;
}

template <class T>
void Stack<T>::grow(){
	T* newBiggerArray=new T[max_*2];
	for(int i=0;i<count_;i++){
		newBiggerArray[i]=data_[i];
	}
	delete [] data_;
	data_=newBiggerArray;
}


template <class T>
void Stack<T>::push(const T& data){
	if(count_>= max_){
		grow();
	}
	data_[count_++]=data;
}

template <class T>
void Stack<T>::pop(){
	if(count_>0)
		count_--;
}

template <class T>
void Stack<T>::print(){
	for(int i=0;i<count_;i++){
		cout << data_[i] << " ";
	}
	cout << endl;
}