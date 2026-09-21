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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    Node* merge(Node* left, Node* right) {
        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        }
        else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = slow->next;
        slow->next = NULL;

        Node* left = mergeSort(head);
        Node* right = mergeSort(second);

        return merge(left, right);
    }

    void sort() {
        head = mergeSort(head);
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(4);
    list.insert(2);
    list.insert(1);
    list.insert(3);

    list.sort();

    list.display();

    return 0;
}