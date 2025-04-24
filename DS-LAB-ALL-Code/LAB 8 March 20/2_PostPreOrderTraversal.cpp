#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    Node* insertNode(Node* node, int val) {
        if (node == nullptr) return new Node(val);
        if (val < node->data) node->left = insertNode(node->left, val);
        else node->right = insertNode(node->right, val);
        return node;
    }

    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void displayPreOrder() {
        cout << "Pre-order: ";
        preOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        cout << "Post-order: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        tree.insert(val);
    }

    tree.displayPreOrder();
    tree.displayPostOrder();

    return 0;
}
