#include <iostream>
using namespace std;
//Column Major
int main(void) {
    int arr[3][4] = { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12} };
    int size = 3 * 4; 
	int D1[size];
    int k;
    
	for(int j = 0; j < 4; j++){
    	for(int i = 0; i < 3; i++){
			D1[k] = arr[i][j];
			k++;
		}
	}
    for(int i = 0; i < size; i++){
    	cout << D1[i] << " ";
	}
  return 0;
}
