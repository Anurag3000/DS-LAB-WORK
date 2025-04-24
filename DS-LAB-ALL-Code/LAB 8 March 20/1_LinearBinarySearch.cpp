#include <iostream>
#include <algorithm>
using namespace std;

class SearchOperations {
public:
    int linearSearch(int arr[], int size, int target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    int binarySearch(int arr[], int size, int target) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

int main() {
    int choice, target, result, n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    SearchOperations searchOps;
    while (true) {
        cout << "\n1.Linear Search\n2.Binary Search\n3.Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to search: ";
                cin >> target;
                result = searchOps.linearSearch(arr, n, target);
                if (result != -1) cout << "Element found at index: " << result << endl;
                else cout << "Element not found.\n";
                break;
            case 2:
                sort(arr, arr + n);
                cout << "Array sorted for Binary Search.\n";
                cout << "Enter element to search: ";
                cin >> target;
                result = searchOps.binarySearch(arr, n, target);
                if (result != -1) cout << "Element found at index: " << result << endl;
                else cout << "Element not found.\n";
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}
