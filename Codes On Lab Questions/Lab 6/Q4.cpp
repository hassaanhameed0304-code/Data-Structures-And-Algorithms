#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

int getHeight(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    int diff = leftHeight - rightHeight;

    if (diff < 0)
        diff = -diff;

    if (diff > 1)
        return -1;

    return 1 + (leftHeight > rightHeight
                ? leftHeight : rightHeight);
}

bool isBalanced(Node* root) {
    return getHeight(root) != -1;
}

int main(void){
    Node* root = new Node(3);

    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    if (isBalanced(root))
        cout << "Tree is Balanced";
    else
        cout << "Tree is Not Balanced";

    return 0;
}
