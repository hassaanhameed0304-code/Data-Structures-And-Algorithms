#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};
void insert(Node* &head, Node* &tail, int pos, int d){
	//creation of node and head
	Node* temp = head;
	Node* nodetoinsert = new Node(d);
	int cnt = 1;
	if (pos == 1){
		nodetoinsert->next = head;
		head = nodetoinsert;
		//is temp the last node or not?, insert at the end if list is empty
		if (temp->next == NULL){
			tail = nodetoinsert;
		}
		return;
	}
	//transversing
	while(cnt < pos - 1){
		temp = temp->next;
		cnt++;
	}
	// if position doesnt even exists in the first place. like position 6
	if(temp == NULL){
		return;
	}
	//add in the end of the existing list 
	if(temp->next == NULL){
		temp->next = nodetoinsert;
		tail = nodetoinsert;
		return;
	}
	// insert in the middle
	nodetoinsert->next = temp->next;
	temp->next = nodetoinsert;
}
int main(void){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insert(head, tail, 2, 20);
    insert(head, tail, 3, 30);
    insert(head, tail, 4, 40);

    cout << "Linked List: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    insert(head, tail, 3, 25);

    cout << "After inserting 25 at position 3: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
