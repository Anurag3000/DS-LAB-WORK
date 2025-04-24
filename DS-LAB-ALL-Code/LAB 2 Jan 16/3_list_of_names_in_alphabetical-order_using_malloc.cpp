#include <iostream>
#include <cstring>  // For strcmp, strcpy
#include <cstdlib>  // For malloc, free
using namespace std;

int main() {
    int n;
    cout << "Enter the number of names: ";
    cin >> n;

    // Clear input buffer
    cin.ignore();

    // Allocate memory for array of char pointers
    char** names = (char**)malloc(n * sizeof(char*));

    cout << "Enter " << n << " names:\n";
    for (int i = 0; i < n; i++) {
        char temp[100];
        cin.getline(temp, 100);

        // Allocate memory for each name
        names[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(names[i], temp);
    }

    // Alphabetical sort using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap pointers
                char* temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    cout << "\nNames in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
        free(names[i]);  // Free memory for each name
    }

    free(names);  // Free array of pointers

    return 0;
}
