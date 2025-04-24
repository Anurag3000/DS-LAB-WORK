#include <iostream> 
using namespace std; 
int main() { 
    int n,val;
    cout<<"enter total inputs: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>val;
        arr[i]=val;
    }
    int sum=0;
    for (int i = 0; i < n; i++){
        sum+=arr[i];
    }
    cout<<"\nsum is: "<<sum;
    
}