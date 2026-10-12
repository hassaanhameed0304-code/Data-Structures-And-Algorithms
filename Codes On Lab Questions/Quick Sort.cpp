#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int start, int end){
	int index = start - 1;
	int pivot = arr[end];
	for(int j = start; j <end;j++){
		if(arr[j] <= pivot){
			index++;
			swap(arr[j],arr[index]);
		}
	}
	index++;
	swap(arr[end], arr[index]);
	return index;
}

void quicksort(vector<int> &arr, int start, int end){
	if (start < end){
		int pivotindex = partition(arr,start,end);
		quicksort(arr, start, pivotindex-1);
		quicksort(arr,pivotindex+1, end);
	}
}
int main(void) {
	vector<int> arr = {12,31,35,8,32,18};
	quicksort(arr,0,arr.size()-1);
	for(int val = 0; val < arr.size();val++){
		cout<<arr[val] << " ";
	}
	cout << endl;

  return 0;
}
