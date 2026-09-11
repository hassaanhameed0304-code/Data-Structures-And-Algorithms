#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {} 
};

class LinkedList {
private:
    Node* head; 

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
    }

    void deleteNode(int key) { 
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) { 
            head = temp->next; 
            delete temp;       
            return;
        }

        while (temp != nullptr && temp->data != key) { 
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return; 

        prev->next = temp->next; 
        
        delete temp; 
    }

    bool search(int key) { 
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true; 
            }
            temp = temp->next;
        }
        return false; 
    }

    void display() { 
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    
    list.insert(10); 
    list.insert(20);
    list.insert(30);
    list.insert(40);
    
    cout << "Linked List: ";
    list.display();
    
    int key = 20; 
    if (list.search(key)) {
        cout << key << " found in the list." << endl;
    } else {
        cout << key << " not found in the list." << endl;
    }
    
    list.deleteNode(20); 
    cout << "After deleting 20: ";
    list.display();
    
    return 0;
}