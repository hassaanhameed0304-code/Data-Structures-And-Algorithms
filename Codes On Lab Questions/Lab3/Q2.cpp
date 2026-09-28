#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class Dequeue {
private:
    Node* front;
    Node* rear;

public:
    Dequeue() {
        front = NULL;
        rear = NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (front == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (front == NULL) {
            cout << "Dequeue is empty" << endl;
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
            front->prev = NULL;
            delete temp;
        }
    }

    void deleteRear() {
        if (rear == NULL) {
            cout << "Dequeue is empty" << endl;
            return;
        }

        if (front == rear) {
            delete rear;
            front = NULL;
            rear = NULL;
        }
        else {
            Node* temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
    }

    void display() {
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main(){
    Dequeue d;

    d.insertFront(20);
    d.insertFront(10);
    d.insertRear(30);
    d.insertRear(40);

    cout << "Dequeue: ";
    d.display();

    d.deleteFront();

    cout << "After deleting front: ";
    d.display();

    d.deleteRear();

    cout << "After deleting rear: ";
    d.display();

    return 0;
}