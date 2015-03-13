#include <iostream>
using namespace std;
template <class T>
class Queue{
    T* data_;
    int max_;
    int count_;
    int front_;
    int back_;
    void grow();
public:
	Queue(int cap=50);
	void enqueue(const T& data);  //insertion
	void dequeue();               //removal
	T front() const;
	int search(const T& data);
	void print();
	bool isEmpty(){return count_==0;}
};

template <class T>
void Queue<T>::grow(){
	T* newBiggerArray=new T[max_*2];
	for(int i=0;i<count_;i++){
		newBiggerArray[i]=data_[front_];
		front_=(front_+1)%max_;
	}
	front_=0;
	back_=count_;
	delete [] data_;
	data_=newBiggerArray;
}
template <class T>
Queue<T>::Queue(int cap){
	data_=new T[cap];
	max_=cap;
	count_=0;
	front_=0; //where we remove things from
	back_=0;  //where we put things in
}

template <class T>
T Queue<T>::front() const{
	T rc;
	if(count_>0){
		rc= data_[front_];
	}
	return rc;
}

template <class T>
void Queue<T>::enqueue(const T& data){
	if(count_>= max_){
		grow();
	}
	data_[back_]=data;
	back_=(back_+1==max_)?0:back_+1;
	//back_=(back+1)%max_;
	count_++;
}

template <class T>
void Queue<T>::dequeue(){
	if(count_>0){
		front_=(front_+1)%max_;
		count_--;
	}
}

template <class T>
void Queue<T>::print(){
	for(int i=0;i<count_;i++){
		cout << data_[i] << " ";
	}
	cout << endl;
}