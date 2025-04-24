#include <iostream>
using namespace std;

int main() {
    int m, n, p, val, a, b;
    cin >> m;
    cin >> n;
    cin >> p;

    int arr1[m][n];
    int (*ptr1)[n] = arr1;

    int arr2[n][p];
    int (*ptr2)[p] = arr2;

    int arr3[m][p];
    int (*ptr3)[p] = arr3;

    cout << "FOR MATRIX 1" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            arr1[i][j] = val;
        }
    }

    cout << "FOR MATRIX 2" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> val;
            arr2[i][j] = val;
        }
    }

    cout << "MATRIX MULTIPLICATION" << endl;
    for (int k = 0; k < m; k++) {
        for (int l = 0; l < p; l++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                a = *(*(ptr1 + k) + j);
                b = *(*(ptr2 + j) + l);
                sum += a * b;
            }
            arr3[k][l] = sum;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
