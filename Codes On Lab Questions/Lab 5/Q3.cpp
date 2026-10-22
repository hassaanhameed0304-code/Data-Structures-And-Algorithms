
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Call {
public:
    int id, arrivalTime;
    string customerName;

    Call(int i, int t, string name) {
        id = i;
        arrivalTime = t;
        customerName = name;
    }
};

class CallCenter {
    queue<Call> calls;
    int csrs;
    bool available[10];

public:
    CallCenter(int n) {
        csrs = n;

        for (int i = 0; i < csrs; i++) {
            available[i] = true;
        }
    }

    void addCall(Call c) {
        calls.push(c);
    }

   
	void processCalls() {
    	int i = 0;

    	while (!calls.empty()) {
        	if (available[i] == true) {
            	Call c = calls.front();
            	calls.pop();

            	available[i] = false;

            	cout << "CSR " << i + 1 << " handles " << c.customerName << endl;
				available[i] = true;
				cout << "CSR " << i + 1 << " is available" << endl;
        	}
			i = (i + 1) % csrs;
    	}
	}

};

int main(void) {
    CallCenter center(3);

    center.addCall(Call(1, 1, "Ali"));
    center.addCall(Call(2, 2, "Ahmed"));
    center.addCall(Call(3, 3, "Sara"));

    center.processCalls();

    return 0;
}
