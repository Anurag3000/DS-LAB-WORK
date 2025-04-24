#include<iostream>
using namespace std;

int add(int a, int b){
    cout<<"addition is: ";
    return a+b;
}

int subtract(int a, int b){
    cout<<"subtraction is: ";
    return a-b;
}

int main(){
    int(*ptr[2])(int,int)={add,subtract};
    int a,b;
    cin>>a>>b;
    for (int i = 0; i < 2; i++)
    {
        cout<<ptr[i](a,b)<<endl;
    }
    

}