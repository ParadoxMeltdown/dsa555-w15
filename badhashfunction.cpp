#include <iostream>
using namespace std;
int badHashFunction(const char* key){
	int rc=0;
	for(int i=0;key[i]!='\0';i++){
		rc+=key[i];
	}
	return rc;
}
int main(int argc, char* argv[]){
	if(argc < 2){
		cout << "need a key" << endl;
	}
	else{
		int hashvalue=badHashFunction(argv[1]);
		cout << argv[1] << " " << hashvalue << endl;
		if(argc == 3){
			int tablesize=atoi(argv[2]);
			cout << "index: " << hashvalue % tablesize << endl;
		}
	}
	return 0;
}