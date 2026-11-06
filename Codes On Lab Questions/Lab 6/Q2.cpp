#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

bool isMirror(Node* left, Node* right) {
    if (left == nullptr && right == nullptr)
        return true;

    if (left == nullptr || right == nullptr)
        return false;

    return left->data == right->data
        && isMirror(left->left, right->right)
        && isMirror(left->right, right->left);
}

bool isSymmetric(Node* root) {
    if (root == nullptr)
        return true;

    return isMirror(root->left, root->right);
}

int main(void){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
        cout << "Tree is Symmetric";
    else
        cout << "Tree is Not Symmetric";

    return 0;
}
