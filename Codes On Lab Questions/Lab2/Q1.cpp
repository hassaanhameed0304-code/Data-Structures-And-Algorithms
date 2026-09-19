#include <iostream>
using namespace std;


class node{
	public:
		int data;
		node* next;
		node(int value){
			data = value;
			next = nullptr;
		}	
};
node* mergelist(node* list1 , node* list2){
	node* dummy = new node(0);
	node* current = dummy;
	while(list1 != nullptr && list2 != nullptr){
		if(list1->data < list2->data){
			current->next = list1;
			list1 = list1->next;
		}else{
			current->next = list2;
            list2 = list2->next;
		}
		current = current->next;
		
	} 
	if (list1 != nullptr){
		current->next = list1;
	}
	if (list2 != nullptr){
		current->next = list2;
	}
    return dummy->next;
	
}
void printList(node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(void){
    node* list1 = new node(1);
    list1->next  = new node(3);
    list1->next->next = new node(5);

    node* list2 = new node(2);
    list2->next  = new node(4);
    list2->next->next = new node(6);

    cout << "List 1  : "; printList(list1);
    cout << "List 2  : "; printList(list2);

    node* merged = mergelist(list1, list2);
    cout << "Merged  : "; printList(merged);

    return 0;
}
