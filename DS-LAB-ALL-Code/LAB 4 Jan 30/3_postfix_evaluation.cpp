#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    int n=s.size();
    int arr[n],top=-1,number_count=0,operand_count=0;

    for (int i = 0; i < n; i++){
        if (isdigit(s[i])){
            number_count++;
        }
        else{
            operand_count++;
        }
    }

    for (int i = 0; i < n; i++){
        if (isdigit(s[i])){
            int num=s[i]-'0';
            top++;
            
            arr[top]=num;
        }
        
        else{
            if (s[i]=='+'){
                int val=arr[top-1]+arr[top];
                top--;
                //cout<<val<<endl;
                arr[top]=val;
            }
            else if(s[i]=='-'){
                int val=arr[top-1]-arr[top];
                top--;
                arr[top]=val;
                //cout<<val<<endl;
            }
            else if(s[i]=='*'){
                int val=arr[top-1]*arr[top];
                top--;
                arr[top]=val;
                //cout<<val<<endl;
            }
            else if(s[i]=='/'){
                int val=arr[top-1]/arr[top];
                top--;
                arr[top]=val;
                //cout<<val<<endl;
            }
            
            
        }
    }
    cout<<arr[top];
    
}