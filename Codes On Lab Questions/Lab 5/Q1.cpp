#include <iostream>
using namespace std;

class MyCQ {
private:
    int *arr;
    int f;
    int r;
    int size;
    int cap;

public:
    MyCQ(int c) {
        cap = c;
        arr = new int(cap);
        f = -1;
        r = -1; 
        size = 0;
    }

    bool insertf(int value) {
        if (isFull()) {
            return false;
        }
        f = (f + 1) % cap;
        arr[f] = value;
        size++;
        return true;
    }

    bool insertlast(int value) {
        if (isFull()) {
            return false;
        }
        r = (r + 1) % cap;
        arr[r] = value;
        size++;
        return true;
    }

    bool deletef() {
        if (isEmpty()) {
            return false;
        }
        f = (f + 1) % cap;
        size--;
        return true;
    }

    bool deletelast() {
        if (isEmpty()) {
            return false;
        }
        r = (r + 1) % cap;
        size--;
        return true;
    }

    int getf() {
        if (isEmpty()) {
            return -1;
        }
        return arr[f];
    }

    int getr() {
        if (isEmpty()) {
            return -1;
        }
        return arr[r];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};

int main(void) {
    MyCQ cq(3);
    

    cout << cq.insertlast(1) << endl; 
    cout << cq.insertlast(2) << endl; 
    cout << cq.insertf(3) << endl;
    cout << cq.insertf(4) << endl;
    cout << cq.getr() << endl;     
    cout << cq.isFull() << endl;      
    cout << cq.deletelast() << endl;  
    cout << cq.insertf(4) << endl;
    cout << cq.getf() << endl;    
    
    return 0;
}