#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* prev;
		node* next;
		node(int d){
			this->data = d;
			this->prev = NULL;
			this->next = NULL;
		}


};

void insertathead(node* &head,int d){
	node* temp = new node(d);
	if(head == NULL){	
		head = temp;
	}else{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}
void printLL(node* &head){
	node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int LengthLL(node* &head){
	int len = 0;
	node* temp = head;
	while(temp->next != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}
void insertattail(node* &tail, int d){
	node* temp = new node(d);
	if(tail == NULL)	
		tail = temp;
	else{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}
void insertananyposition(node* &head, node* &tail, int pos, int d){
	if(pos == 1){
		insertathead(head,d);
		return;
	}
	node* temp = head;
	int count = 1;
	while(count < pos -1){
		temp = temp->next;
		count++;
	}
	if(temp->next == NULL){
		insertattail(tail,d);
		return;
	}
	node* nodetoinsert = new node(d);
	nodetoinsert->next = temp->next;
	temp->next->prev = nodetoinsert;
	temp -> next = nodetoinsert;
	nodetoinsert-> prev = temp;
	return;
}	
		

int main(void) {
	node* node1 = new node(10);
	node* head = node1;
	node* tail = node1;
	insertananyposition(head,tail, 2,20);
	insertananyposition(head,tail, 3,30);
	insertananyposition(head,tail, 4,40);
	insertananyposition(head,tail, 2,15);
	printLL(head);
	

  return 0;
}
