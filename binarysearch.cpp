int binarySearch(int key,int array[],int low, high){
	int rc;
	int mid=(low+high)/2;
	//base case 1, the array effectively does not exist
	if(low > high){
		rc=-1;
	}
	else if(key == array[mid]){
		rc=mid;
	}
	else{
		if(key < array[mid]){
			rc=binarySearch(key,array,low,mid-1);
		}
		else{
			rc=binarySearch(key,array,mid+1,high);
		}
	}
	return rc;
}


int binarySearch(int key,int array[],int size){
	int high = size-1;
	int mid=high/2;
	int rc;
	//base case 1, the array effectively does not exist
	if(size < 1){
		rc=-1;
	}
	else{
		if(key < array[mid]){
			rc=binarySearch(key,array,mid-1);
		}
		else(key > array[mid]){
			rc=binarySearch(key,array+(mid+1),high-(mid+1))

		}
		else{
			rc=mid;
		}
	}
	return rc;
}


int main(void){
	binarySearch(key,array,size);
}