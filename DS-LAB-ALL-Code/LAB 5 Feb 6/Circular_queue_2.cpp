#include <iostream>
using namespace std;
#define MAX 3

int arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue is full\n";
        return;  // FIX: Stop execution when full
    }
    if (front == -1) front = 0;  // First insertion
    rear = (rear + 1) % MAX;
    arr[rear] = x;
}

void dequeue() {
    if (front == -1) {
        cout << "Underflow\n";
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    if (front == rear) {  // Last element being removed
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }
    int i = front;
    while (i != rear) {
        cout << arr[i] << " ";
        i = (i + 1) % MAX;  // Move circularly
    }
    cout << arr[rear] << endl;  // Print last element separately
}

int main() {
    enqueue(10);
    enqueue(20);
    display();  // Expected: 10 20 30 40
    dequeue();
    display();  // Expected: 20 30 40
    enqueue(30);
    enqueue(40);
    display();  // Expected: 20 30 40 50 60

    return 0;
}
