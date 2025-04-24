#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head || val < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

Node* merge(Node* a, Node* b) {
    Node dummy;
    Node* tail = &dummy;

    while (a && b) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a) ? a : b;
    return dummy.next;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* X = nullptr;
    Node* Y = nullptr;
    int n, val;

    cout << "Enter size of list X: ";
    cin >> n;
    cout << "Enter sorted elements of X: ";
    while (n--) {
        cin >> val;
        insert(X, val);
    }

    cout << "Enter size of list Y: ";
    cin >> n;
    cout << "Enter sorted elements of Y: ";
    while (n--) {
        cin >> val;
        insert(Y, val);
    }

    Node* Z = merge(X, Y);
    cout << "Merged List Z: ";
    display(Z);

    return 0;
}
