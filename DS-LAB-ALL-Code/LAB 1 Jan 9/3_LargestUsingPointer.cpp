#include <iostream> 
using namespace std; 
int main() { 
    int n,val; 
    cout<<"enter total inputs: ";
    cin >> n; 
    int arr[n]; 
    
    for (int i = 0; i <= n-1; i++){
        cin>>val;
        arr[i]=val;
    }
    int* ptr=arr;
    int max=*ptr;

    for (int i = 0; i < n; i++){
        if (ptr[i]>=max){
            max=ptr[i];
        }
    }
    cout<<"maximum is: "<<max;
}