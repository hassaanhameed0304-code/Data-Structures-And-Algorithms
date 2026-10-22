#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int winner(int n, int k) {
    Node* head = new Node{1, NULL};
    Node* tail = head;

    for (int i = 2; i <= n; i++) {
        tail->next = new Node{i, NULL};
        tail = tail->next;
    }

    tail->next = head;

    Node* curr = tail;

    while (curr->next != curr) {
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        Node* temp = curr->next;
        curr->next = temp->next;

        if (temp == head) {
            head = temp->next;
        }

        delete temp;
    }

    int ans = curr->data;
    delete curr;
    return ans;
}

int main(void) {
    int n = 5, k = 2;

    cout << winner(n, k);

    return 0;
}
