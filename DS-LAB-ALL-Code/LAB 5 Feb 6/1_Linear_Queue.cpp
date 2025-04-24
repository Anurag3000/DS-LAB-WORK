#include <iostream>
#define MAX 10
using namespace std;

int arr[MAX];
int front = 0;
int rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Is Full\n";
    } else {
        arr[++rear] = x;
    }
}

void dequeue() {
    if (front > rear) {  // Correct underflow check
        cout << "Underflow\n";
    } else {
        front++;
        if (front > rear) {  // Reset when queue is empty
            front = 0;
            rear = -1;
        }
    }
}

void display() {
    if (front > rear) {
        cout << "empty queue\n";
    } else {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;  // Newline for better readability
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    display();  // Output: 10 20 30

    dequeue();
    display();  // Output: 20 30

    dequeue();
    dequeue();

    return 0;
}
