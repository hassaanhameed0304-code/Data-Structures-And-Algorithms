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
	int nums[6] = {-1,0,3,5,9,12};
	int r1 = binarysearch(nums,6,1);
	int r2 = binarysearch(nums,6,12);
	cout << "First Failed Output" << endl;
	if (r1 == -1) 
  		cout << "-1" << endl; 
	else	  
		cout << "Element Found At Index: " << r1 << endl;
  	cout << "Second Successful Output" << endl;
	if (r2 == -1) 
  		cout << "-1"; 
	else	  
		cout << "Element Found At Index: " << r2;
  	return 0;
	
}
