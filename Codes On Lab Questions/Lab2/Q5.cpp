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
public:
    Node* front;
    Node* rear;

    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (front == NULL) {
            front = rear = newNode;
            rear->next = front;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty";
            return;
        }

        if (front == rear) {
            delete front;
            front = rear = NULL;
            return;
        }

        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }

    void display() {
        if (front == NULL)
            return;

        Node* temp = front;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();

    q.display();

    return 0;
}