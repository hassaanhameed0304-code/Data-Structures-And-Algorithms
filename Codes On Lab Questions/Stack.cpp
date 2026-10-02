#include <iostream>
using namespace std;

class stack{
	public:
		int *arr;
		int top;
		int size;
		stack(int size){
			this->size = size;
			top = -1;
			arr = new int[size];
		}
		void push(int element){
			if(size - top > 1){
				top++;
				arr[top] = element;
			}else{
				cout << "Stack Overflow" << endl;
			}
		}
		void pop(){
			if(top >= 0){
				top--;
			}else
				cout << "Stack Underflow" << endl;
		}
		bool isEmpty(){
			if(top == -1){
				return true;
			}else
				return false;
		}
		int peek(){
			if (top >= 0){
				return arr[top];
			}else{
				cout << "Array is Empty";
				return -1;
			}
		}
		void printstack(){
			for(int i = top; i>= 0; i--){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};
int main(void) {
	stack st(5);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.printstack();
	st.pop();
	st.printstack();
	cout << st.peek();
	
	
  return 0;
}
