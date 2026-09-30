#include <iostream>
using namespace std;
class queue{
	public:
	int *arr;
	int front;
	int rear;
	int size;
	queue(int size){
		this->size = size;
		arr = new int[size];
		front = 0;
		rear = 0;
	}
	void enqueue(int element){
		if (rear == size){
			cout << "Queue is full";
		}else{
			arr[rear] = element;
			rear++;
		}
	}
	void dequeue(){
		if (front == rear){
			cout << "Queue is empty";
		}else{
			int key = arr[front];
			arr[front] = -1;
			front++;
			if(front == rear){
				rear = 0;
				front = 0;
			}
			cout << key << endl;
		}
	}
	bool isEmpty(){
		if (front == rear){
			return true;
		}else{
			return false;
		}
	}
	void print(){
		if(front == rear){
			cout << "Queue is empty" << endl;
		}else{
			for(int i = front; i < rear; i++){
				cout << arr[i] << " ";
			}
		}
	}
};
int main(void) {
	queue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.print();
	cout << "\nDequeued\n";
	q.dequeue();
	q.dequeue();
	q.print();
	
  return 0;
}
