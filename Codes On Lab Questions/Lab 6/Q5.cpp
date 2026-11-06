#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

struct Result {
    int take;
    int skip;
};

Result solve(Node* root) {
    if (root == NULL)
        return {0, 0};

    Result left = solve(root->left);
    Result right = solve(root->right);

    Result ans;

    // Rob current house
    ans.take = root->data + left.skip + right.skip;

    // Do not rob current house
    int leftMax = (left.take > left.skip)
                  ? left.take : left.skip;

    int rightMax = (right.take > right.skip)
                   ? right.take : right.skip;

    ans.skip = leftMax + rightMax;

    return ans;
}

int rob(Node* root) {
    Result ans = solve(root);

    if (ans.take > ans.skip)
        return ans.take;
    else
        return ans.skip;
}

int main(void){
    Node* root = new Node(3);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(3);
    root->right->right = new Node(1);

    cout << "Maximum Money: " << rob(root);

    return 0;
}
