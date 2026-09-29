#include <iostream>
using namespace std;

void ascinsertionsort(int arr[], int n){
	for(int i = 1; i < n; i++){
		int curr = arr[i];
		int prev = i - 1;
		while(prev >= 0 && arr[prev] > curr){
			arr[prev + 1] = arr[prev];
			prev--;
		}
		arr[prev + 1] = curr;
	}
}
void print(int arr[],int n){
	for(int i = 0; i < n; i++){
		cout <<arr[i] << " ";
	}
	cout << endl;
}
void desinsertionsort(int arr[], int n){
	for(int i = 1; i < n; i++){
		int curr = arr[i];
		int prev = i - 1;
		while(prev >= 0 && arr[prev] < curr){
			arr[prev + 1] = arr[prev];
			prev--;
		}
		arr[prev + 1] = curr;
	}
}
int main(void) {
	int n = 5;
	int arr[] = {4, 1, 5, 3, 2};
	ascinsertionsort(arr,n);
	cout << "Ascending Order" << endl;
	print(arr,5);
	desinsertionsort(arr,n);
	cout << "Descending Order" << endl;
	print(arr,5);
  return 0;
}
