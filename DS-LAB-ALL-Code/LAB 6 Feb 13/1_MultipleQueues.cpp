#include <iostream>
using namespace std;

class MultipleQueues {
    int *arr, size, front1, rear1, front2, rear2;
public:
    MultipleQueues(int s) {
        size = s;
        arr = new int[size];
        front1 = rear1 = -1;
        front2 = rear2 = size;
    }

    void enqueueQueue1(int val) {
        if (rear1 + 1 == front2 || rear1 == size - 1) {
            cout << "Queue 1 Overflow!\n";
            return;
        }
        if (front1 == -1) front1 = 0;
        arr[++rear1] = val;
        cout << val << " enqueued in Queue 1.\n";
    }

    void enqueueQueue2(int val) {
        if (rear2 - 1 == front1 || rear2 == 0) {
            cout << "Queue 2 Overflow!\n";
            return;
        }
        if (front2 == size) front2 = size - 1;
        arr[--rear2] = val;
        cout << val << " enqueued in Queue 2.\n";
    }

    void dequeueQueue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue 1 Underflow!\n";
            return;
        }
        cout << arr[front1++] << " dequeued from Queue 1.\n";
    }

    void dequeueQueue2() {
        if (front2 == size || front2 < rear2) {
            cout << "Queue 2 Underflow!\n";
            return;
        }
        cout << arr[front2--] << " dequeued from Queue 2.\n";
    }

    void displayQueue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue 1 is empty!\n";
            return;
        }
        cout << "Queue 1: ";
        for (int i = front1; i <= rear1; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void displayQueue2() {
        if (front2 == size || front2 < rear2) {
            cout << "Queue 2 is empty!\n";
            return;
        }
        cout << "Queue 2: ";
        for (int i = front2; i >= rear2; i--) cout << arr[i] << " ";
        cout << endl;
    }

    ~MultipleQueues() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array for two queues: ";
    cin >> size;
    MultipleQueues queues(size);

    while (true) {
        cout << "\n1.Enqueue Queue 1\n2.Enqueue Queue 2\n3.Dequeue Queue 1\n4.Dequeue Queue 2\n5.Display Queue 1\n6.Display Queue 2\n7.Exit\nChoose: ";
        int choice, val;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value for Queue 1: ";
                cin >> val;
                queues.enqueueQueue1(val);
                break;
            case 2:
                cout << "Enter value for Queue 2: ";
                cin >> val;
                queues.enqueueQueue2(val);
                break;
            case 3:
                queues.dequeueQueue1();
                break;
            case 4:
                queues.dequeueQueue2();
                break;
            case 5:
                queues.displayQueue1();
                break;
            case 6:
                queues.displayQueue2();
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
}
