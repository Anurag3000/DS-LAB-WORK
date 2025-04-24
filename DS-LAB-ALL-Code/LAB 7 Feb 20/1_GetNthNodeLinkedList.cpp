#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void getNthNode(int n) {
        if (n <= 0) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp) {
            if (count == n) {
                cout << "The data at node " << n << " is: " << temp->data << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "The list has fewer than " << n << " nodes.\n";
    }

    void display() {
        if (!head) {
            cout << "The list is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Singly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    int n, val;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        sll.insertEnd(val);
    }
    sll.display();
    int position;
    cout << "Enter the position to get the Nth node: ";
    cin >> position;
    sll.getNthNode(position);
    return 0;
}
