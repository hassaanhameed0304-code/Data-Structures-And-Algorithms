#include <iostream>
using namespace std;

int main(void) {
	int rows,columns;
	int arr[100][100];
	cout << "Size of the array you want: "<<endl;
	cout << "Enter Rows: ";
	cin >> rows;
	cout << "Enter Columns: ";
	cin >> columns;
	
	for (int i = 0; i < rows;i++){
		for (int j = 0; j < columns;j++){
			cout << "Enter Numbers You Want To Store: " <<endl;
			cin >> arr[i][j];
		}
	}
	cout << "Your Data: " <<endl;
	for (int i = 0; i < rows;i++){
		for (int j = 0; j < columns;j++){
			cout << arr[i][j] ;
			cout << " ";
		}
		cout << endl;
	}

  return 0;
}
