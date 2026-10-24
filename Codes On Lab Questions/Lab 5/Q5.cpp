
#include <iostream>
using namespace std;

class DataStream {
    int value, k, count;

public:
    DataStream(int v, int n) {
        value = v;
        k = n;
        count = 0;
    }

    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0;
        }

        if (count >= k) {
            return true;
        }

        return false;
    }
};

int main(void) {
    DataStream dataStream(4, 3);

    cout << dataStream.consec(4) << endl;
    cout << dataStream.consec(4) << endl;
    cout << dataStream.consec(4) << endl;
    cout << dataStream.consec(3) << endl;

    return 0;
}
