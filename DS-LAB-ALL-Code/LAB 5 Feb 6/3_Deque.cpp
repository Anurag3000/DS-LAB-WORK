#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (front == (rear + 1) % MAX);
}

void insertFront(int key) {
    if (isFull()) {
        cout << "Deque is full\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    arr[front] = key;
}

void insertRear(int key) {
    if (isFull()) {
        cout << "Deque is full\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    arr[rear] = key;
}

void deleteFront() {
    if (isEmpty()) {
        cout << "Deque is empty\n";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void deleteRear() {
    if (isEmpty()) {
        cout << "Deque is empty\n";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

int getFront() {
    if (isEmpty()) {
        cout << "Deque is empty\n";
        return -1;
    }
    return arr[front];
}

int getRear() {
    if (isEmpty()) {
        cout << "Deque is empty\n";
        return -1;
    }
    return arr[rear];
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);

    cout << "Front: " << getFront() << endl;
    cout << "Rear: " << getRear() << endl;

    deleteFront();
    deleteRear();

    cout << "Front after deletion: " << getFront() << endl;
    cout << "Rear after deletion: " << getRear() << endl;

    return 0;
}
