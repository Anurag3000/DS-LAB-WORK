#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

int main() {
    string elements[MAX];
    int priorities[MAX];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter element and priority:\n";
    for (int i = 0; i < n; i++) {
        cin >> elements[i] >> priorities[i];
    }

    // Sort by priority (higher to lower)
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (priorities[i] < priorities[j]) {
                swap(priorities[i], priorities[j]);
                swap(elements[i], elements[j]);
            }
        }
    }

    cout << "Priority Queue (high to low):\n";
    for (int i = 0; i < n; i++) {
        cout << elements[i] << " (priority " << priorities[i] << ")\n";
    }

    return 0;
}
