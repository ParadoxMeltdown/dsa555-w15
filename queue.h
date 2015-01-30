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
};

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
Queue<T>::Queue(int cap=50){
	data_=new T[cap];
	max_=cap;
	count_=0;
	front_=0; //where we remove things from
	back_=0;  //where we put things in
}

T Queue<T>::front() const{
	if(count_>0){
		return data_[front_];
	}
}

template <class T>
void enqueue(const T& data){
	if(count_>= max_){
		grow();
	}
	data_[back_]=data;
	back_=(back_+1==max_)?0:back+1;
	//back_=(back+1)%max_;
	count++;
}

void dequeue(){
	if(count>0){
		front_=(front_+1)%max_;
		count_--;
	}
}
void print(){
	for(int i=0;i<count_;i++){
		cout << data_[i] << " ";
	}
	cout << endl;
}