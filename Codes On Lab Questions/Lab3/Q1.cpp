#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == NULL) {
            front = newNode;
            rear = newNode;
            rear->next = front;
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            delete front;
            front = NULL;
            rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main(){
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue: ";
    q.display();

    q.dequeue();

    cout << "After dequeue: ";
    q.display();

    return 0;
}