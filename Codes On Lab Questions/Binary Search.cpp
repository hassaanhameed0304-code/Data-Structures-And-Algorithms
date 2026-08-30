#include <iostream>
using namespace std;
int binarysearch(int arr[], int size, int target){
	int start = 0;
	int end = size - 1;
	int mp = (start + end) / 2;
	while (start <= end){
		if (arr[mp] == target)
			return mp;
		else if (arr[mp] > target)
			end = mp - 1;
		else{
			start = mp + 1;
		}
		mp = (start + end)/2;
	}
	return -1;
}
int main(void) {
	int arr5[5] = {1,4,6,7,19};
	int arr6[6] = {2,5,11,13,20,31};
	int r1 = binarysearch(arr5,5,6);
	int r2 = binarysearch(arr6,6,20);
	int r3 = binarysearch(arr5,5,2);
	int r4 = binarysearch(arr6,6,3);
	if (r1 == -1) 
  		cout << "Element not found" << endl; 
	else	  
		cout << "Element Found At Index: " << r1 << endl;
  	cout << "Second Array: " << endl;
	if (r2 == -1) 
  		cout << "Element not found"; 
	else	  
		cout << "Element Found At Index: " << r2;
  	return 0;
	
}
