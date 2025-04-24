#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter size of string: ";
    cin>>n;

    char arr[n];
    string s,ans=" ";
    //s="anu";
    cin.sync();
    getline(cin,s);
    cin.sync();
    if(s.size()>n){
        cout<<"max size exceeded";
    }
    else{
        int top=-1;
        for (int i = 0; i < n; i++){
            arr[i]=s[i];
            top++;
        }

        for (int i = n-1; i >= 0; i--){
            ans+=arr[top];
            top--;
        }

        cout<<ans;
        
    }
    
    
}