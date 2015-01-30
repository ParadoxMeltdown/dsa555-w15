template <class T>
class List{
    T* data_;
    int max_;
    int count_;
public:
	List(int cap=50);
	void insertFront(const T& data);
	void removeFront();
	void insertBack(const T& data);
	void removeBack();
	int search(const T& data);
	void print();
};

template <class T>
List<T>::List(int cap=50){
	data_=new T[cap];
	max_=cap;
	count_=0;
}
void insertFront(const T& data){
	if(count_>= max_){
		grow();
	}
	for(int i=count_;i>0 ;i--){
		data_[i]=data_[i-1];
	}
	data_[0]=data;
}
void removeFront(){
	if(count > 0){
		for(int i=0;i<count_-1;i++){
			data[i]=data[i+1];
		}
	count_--;
	}
}

template <class T>
void insertBack(const T& data){
	if(count_>= max_){
		grow();
	}
	data_[count_++]=data;
}

void removeBack(){
	if(count>0)
		count_--;
}
void print(){
	for(int i=0;i<count_;i++){
		cout << data_[i] << " ";
	}
	cout << endl;
}