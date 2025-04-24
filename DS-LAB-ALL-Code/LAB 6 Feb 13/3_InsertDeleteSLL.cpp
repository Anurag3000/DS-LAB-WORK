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

    // Insertion at the end
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
        cout << val << " inserted at the end.\n";
    }

    // Deletion of a specific node
    void deleteNode(int val) {
        if (!head) {
            cout << "The list is empty!\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << val << " deleted from the list.\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Node with value " << val << " not found.\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        cout << val << " deleted from the list.\n";
    }

    // Display the list
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
    int choice, val;

    while (true) {
        cout << "\n1.Insert at End\n2.Delete a Node\n3.Display\n4.Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the end: ";
                cin >> val;
                sll.insertEnd(val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                sll.deleteNode(val);
                break;

            case 3:
                sll.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid option!\n";
        }
    }
}
