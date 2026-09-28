#include <iostream>
using namespace std;

class Node {
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

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void concatenate(DoublyList& other) {
        if (other.head == NULL)
            return;

        if (head == NULL) {
            head = other.head;
            tail = other.tail;
        }
        else {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
    }

    void sortDescending() {
        Node* current = head;

        while (current != NULL) {
            Node* temp = current->next;

            while (temp != NULL) {
                if (current->data < temp->data) {
                    int value = current->data;
                    current->data = temp->data;
                    temp->data = value;
                }

                temp = temp->next;
            }

            current = current->next;
        }
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyList L;
    DoublyList M;
    DoublyList N;

    L.insert(2);
    L.insert(4);
    L.insert(6);
    L.insert(8);
    L.insert(10);

    M.insert(1);
    M.insert(3);
    M.insert(5);
    M.insert(7);
    M.insert(9);

    N.concatenate(L);
    N.concatenate(M);

    cout << "Before sorting: ";
    N.display();

    N.sortDescending();

    cout << "After sorting: ";
    N.display();

    return 0;
}