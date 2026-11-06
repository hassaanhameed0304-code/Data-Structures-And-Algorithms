#include <iostream>
#include <queue>
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

class BinaryTree {
private:
    Node* root;

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    // Insert in level order
    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            q.push(current->left);

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            q.push(current->right);
        }
    }

    // Search a node
    bool search(int value) {
        if (root == nullptr) return false;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->data == value)
                return true;

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
        return false;
    }

    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }
};

int main(void){
    BinaryTree tree;

    for (int i = 1; i <= 7; i++)
        tree.insert(i);

    cout << "Search 5: "
         << (tree.search(5) ? "Found" : "Not found") << endl;

    cout << "Search 10: "
         << (tree.search(10) ? "Found" : "Not found") << endl;

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    return 0;
}
