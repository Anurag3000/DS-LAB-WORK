//largest element

#include<iostream>
using namespace std;

int main(){

    int n,val;
    cout<<"enter total inputs: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<=n-1;i++){
        cin>>val;
        arr[i]=val;
    }
    int max= arr[0];

    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";  
    }

    
    for(int i=1;i<=n-1;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
        }
    cout<<"\nmaximum is: "<<max;
}
