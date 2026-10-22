#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
    vector<int> products;

public:
    ProductOfNumbers() {
    }

    void add(int num) {
        if (num == 0) {
            products.clear();
        } else {
            if (products.empty())
                products.push_back(num);
            else
                products.push_back(products.back() * num);
        }
    }

    int getProduct(int k) {
        if (k > products.size())
            return 0;

        if (k == products.size())
            return products.back();

        return products.back() / products[products.size() - k - 1];
    }
};

int main(void) {
    ProductOfNumbers p;

    p.add(3);
    p.add(0);
    p.add(2);
    p.add(5);
    p.add(4);

    cout << p.getProduct(2) << endl;
    cout << p.getProduct(3) << endl;
    cout << p.getProduct(4) << endl;

    return 0;
}
