#include <iostream>
using namespace std;

int main(void) {
	int matrix[3][3];
	int oned[9];
	int x = 0;
	cout << "Input 9 Numbers: ";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> matrix[i][j];
		}
	}
	for(int j = 0; j < 3; j++){
		for(int i = 0; i < 3; i++){
			oned[x] = matrix[i][j];
			x++;
		}	
	}
	cout << "This is the 2D array representing a Matrix" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << matrix[i][j];
			cout<<" ";
		}
		cout << " " << endl;
	}
	cout << "This is the transformed One Dimensional Array" << endl;
	 for (int i = 0; i < 9; i++)
    {
        cout << oned[i] << " ";
    }
		
  return 0;
}
