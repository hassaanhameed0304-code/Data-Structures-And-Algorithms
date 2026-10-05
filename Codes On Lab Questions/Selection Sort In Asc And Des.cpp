#include <iostream>
using namespace std;
void ascselectionsort(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		int minIndex = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}
void desselectionsort(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		int minIndex = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] > arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}
void print(int arr[],int n){
	for(int i = 0; i < n; i++){
		cout <<arr[i] << " ";
	}
	cout << endl;
}
int main(void) {
	int n = 5;
	int arr[] = {4, 1, 5, 3, 2};
	cout << "Original Array" << endl;
	print(arr,n);
	ascselectionsort(arr,n);
	cout << "Ascending Order" << endl;
	print(arr,5);
	desselectionsort(arr,n);
	cout << "Descending Order" << endl;
	print(arr,5);
  return 0;
}
