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

class BST {
public:
    Node* root;
    BST() {
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

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void display() {
        cout << "In-order traversal: ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        tree.insert(val);
    }

    tree.display();
    return 0;
}
