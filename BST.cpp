#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    // Insert a value into the BST
    Node* insert(Node* root, int val) {
        if (root == nullptr)
            return new Node(val);
        
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        
        return root;
    }

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;

    // Insert elements into BST
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 70);
    tree.insert(root, 60);
    tree.insert(root, 80);

    cout << "Inorder traversal of BST: ";
    tree.inorder(root);
    cout << endl;

    return 0;
}
