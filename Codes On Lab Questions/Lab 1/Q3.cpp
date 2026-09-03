#include <iostream>
#include <vector>
using namespace std;

class MedianFinder{
private:
    vector<int> arr;

public:
    	MedianFinder(){}
		void addNum(int num){
        arr.push_back(num);

        for (int i = 0; i < arr.size() - 1; i++){
            for (int j = 0; j < arr.size() - i - 1; j++){
                if (arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
	double findMedian(){
        int n = arr.size();

        if (n % 2 == 1){
            return arr[n / 2];
        }
        else{
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};

int main(void){
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);

    cout << mf.findMedian() << endl;

    mf.addNum(3);

    cout << mf.findMedian() << endl;

    return 0;
}