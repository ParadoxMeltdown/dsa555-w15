SortedList::merge(const SortedList& other){
	Node* a=start_;
	Node* preva=NULL;
	Node* b=other.start_;
	while(a && b){
		if(a->data_ < b->data_){
			preva=a;
			a=a->next_;
		}
		else{
			Node* nn=new Node;
			nn->data_=b->data_;
			nn->next_=a;
			if(!preva){
				start_=nn;
			}
			else{
				preva->next_=nn;
			}
			preva=nn;
			b=b->next_;
		}
	}
	while(b){
		Node* nn=new Node;
		nn->data_=b->data_;
		nn->next_=NULL;
		preva->next_=nn;
		preva=nn;
		b=b->next_;
	}
}