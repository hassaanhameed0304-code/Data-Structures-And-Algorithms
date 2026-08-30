#include <iostream>
using namespace std;
int linearsearch(int arr[],int size ,int target){
	for(int i = 0; i < size; i++){
		if (arr[i] == target){
			return i;
		}
	} 	
	return -1;
}
int main(void) {
	int nums[6] = {1,10,3,15,9,12};
  	int valuetobefound;
	cout << "Enter value to be found: ";
	cin >> valuetobefound; 
	int r1 = linearsearch(nums,6,valuetobefound);
	if (r1 == -1) 
  		cout << "-1" << endl; 
	else	  
		cout << "Element Found At Index: " << r1 << endl;
  return 0;
}
