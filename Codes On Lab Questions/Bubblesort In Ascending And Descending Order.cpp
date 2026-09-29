#include <iostream>
using namespace std;
void ascbubblesort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i - 1;j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void desbubblesort(int arr[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i - 1;j++){
			if(arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
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
	ascbubblesort(arr,n);
	cout << "Ascending Order" << endl;
	print(arr,5);
	desbubblesort(arr,n);
	cout << "Descending Order" << endl;
	print(arr,5);
  return 0;
}
