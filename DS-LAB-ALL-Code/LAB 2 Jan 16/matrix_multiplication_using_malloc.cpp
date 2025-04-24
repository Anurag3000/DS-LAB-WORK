#include <iostream>
#include <cstdlib> // For malloc and free

using namespace std;

int main() {
    int m, n, p;

    cout<<"MATRIX 1"<<endl;
    cout << "m: ";
    cin >> m;
    cout << "n: ";
    cin >> n;

    // Allocate memory for the array of pointers (rows)
    int** arr = (int**)malloc(m * sizeof(int*));
    if (arr == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return -1;
    }

    // In each elemt of row, another array ko create kar rha length = columns
    for (int i = 0; i < m; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
        if (arr[i] == nullptr) {
            cout << "Memory allocation failed for row " << i + 1 << "!" << endl;
            return -1;
        }
    }

    // Input values into the 2D array
    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Output the 2D array
    cout << "The 2D array is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"MATRIX 2"<<endl;
    cout << "m: ";
    cin >> n;
    cout << "n: ";
    cin >> p;

    // Allocate memory for the array of pointers (rows)
    int** arr2 = (int**)malloc(n * sizeof(int*));
    if (arr2 == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return -1;
    }

    // In each elemt of row, another array ko create kar rha length = columns
    for (int i = 0; i < n; i++) {
        arr2[i] = (int*)malloc(p * sizeof(int));
        if (arr2[i] == nullptr) {
            cout << "Memory allocation failed for row " << i + 1 << "!" << endl;
            return -1;
        }
    }

    // Input values into the 2D array
    cout << "Enter the elements of the 2D array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> arr2[i][j];
        }
    }

    // Output the 2D array
    cout << "The 2D array is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }



    // // Free the allocated memory
    // for (int i = 0; i < m; i++) {
    //     free(arr2[i]); // Free each row
    // }
    // free(arr2); // Free the array of pointers

    cout<<"MATRIX 3"<<endl;
    
    // Allocate memory for the array of pointers (rows)
    int** arr3 = (int**)malloc(m * sizeof(int*));
    if (arr3 == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return -1;
    }

    // Allocate memory for each row (columns)
    for (int i = 0; i < m; i++) {
        arr3[i] = (int*)malloc(p * sizeof(int));
        if (arr3[i] == nullptr) {
            cout << "Memory allocation failed for row " << i + 1 << "!" << endl;
            return -1;
        }
    }



    // // Free the allocated memory
    // for (int i = 0; i < m; i++) {
    //     free(arr2[i]); // Free each row
    // }
    // free(arr2); // Free the array of pointers

    cout<<"MATRIX MULTIPLICATION"<<endl;

    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < p; i++)
        {
            int sum=0;
            for (int j = 0; j < n; j++)
            {
                sum+=arr[k][j]*arr2[j][i];
            }
            arr3[k][i]=sum;
        }
        
    }
    cout << "The 2D array is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < m; i++) {
        free(arr[i]); // Free each row
    }
    free(arr); 
    for (int i = 0; i < n; i++) {
        free(arr2[i]);
    }
    free(arr2);
    for (int i = 0; i < m; i++) {
        free(arr3[i]);
    }
    free(arr3); 
}
