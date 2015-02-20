#include "recentlist.h"
class ChainingTable{
	RecentList* table_;

public:
	ChainingTable(int max){
		table_=new RecentList[max];
	}
	void insert(key, value){
		Record r(key,value);
		int idx=hashfunction(key);
		table_[idx].insert(r);
	}
	void remove(key){
		int idx;
		table_[idx].remove(key);

	}	
};