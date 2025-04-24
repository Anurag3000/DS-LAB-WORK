#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    s.peek();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
