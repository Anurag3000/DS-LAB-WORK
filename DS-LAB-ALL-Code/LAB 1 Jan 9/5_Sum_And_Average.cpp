#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cout << "Enter the number of elements: "; 
    cin >> n; 
    int* arr = new int[n]; 
    cout << "Enter the elements:\n"; 
    for (int i = 0; i < n; i++) cin >> *(arr + i); 
    int sum = 0; 
    for (int i = 0; i < n; i++) sum += *(arr + i); 
    float avg = (float)sum / n; 
    cout << "Sum: " << sum << endl; 
    cout << "Average: " << avg << endl; 
    delete[] arr; 
    return 0; 
}