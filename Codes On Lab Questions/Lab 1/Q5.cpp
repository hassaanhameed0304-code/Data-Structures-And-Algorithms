#include <iostream>
using namespace std;
int binarysearchmatrix(int matrix[][4],int m, int n, int target){
	int size = m * n;
	int start = 0;
	int end = size - 1;
	int mid;
	while (start <= end){
		mid = (start + end) / 2;
		int row = mid / n;
		int column = mid % n; 
		if(matrix[row][column] == target){
			return mid;
		}
		else if(matrix[row][column] > target){
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return -1;
}
int main(void){
	int mat[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    int result = binarysearchmatrix(mat, 3, 4, target);

    if (result == -1)
        cout << "Element not found";
    else
        cout << "Target: "<< target << "," << " \nfound at index: " << result;


  return 0;
}
