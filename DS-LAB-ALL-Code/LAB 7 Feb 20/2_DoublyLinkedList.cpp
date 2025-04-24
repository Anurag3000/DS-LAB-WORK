#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
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
            newNode->prev = temp;
        }
    }

    void display() {
        if (!head) {
            cout << "The list is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int val) {
        if (!head) {
            cout << "The list is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Node with value " << val << " not found.\n";
            return;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << val << " deleted from the list.\n";
    }

    ~DoublyLinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val;
    while (true) {
        cout << "\n1.Insert at End\n2.Delete a Node\n3.Display\n4.Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at the end: ";
                cin >> val;
                dll.insertEnd(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                dll.deleteNode(val);
                break;
            case 3:
                dll.display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}
