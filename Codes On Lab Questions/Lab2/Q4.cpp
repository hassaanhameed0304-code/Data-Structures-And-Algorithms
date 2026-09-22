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

    bool isPalindrome() {
        int arr[100];
        int i = 0;

        Node* temp = head;

        while (temp != NULL) {
            arr[i] = temp->data;
            i++;
            temp = temp->next;
        }

        int start = 0;
        int end = i - 1;

        while (start < end) {
            if (arr[start] != arr[end])
                return false;

            start++;
            end--;
        }

        return true;
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);

    if (list.isPalindrome())
        cout << "true";
    else
        cout << "false";

    return 0;
}