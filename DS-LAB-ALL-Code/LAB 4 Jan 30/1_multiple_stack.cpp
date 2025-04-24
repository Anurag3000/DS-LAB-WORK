#include<iostream>
#define MAX 10
using namespace std;

int arr[MAX]; //array of length 10

int top1= -1, top2=MAX;

void push1(int x){
    if (top1+1==top2){
        cout<<"stack overflow";
    }
    else{
        top1++;
        arr[top1]=x;
    }
}

void push2(int x){
    if (top1+1==top2){
        cout<<"stack overflow";
    }
    else{
        top2--;
        arr[top2]=x;
    }
}

void pop1(){
    if (top1==-1){
        cout<<"stack underflow";
    }
    else{
        cout<<"popped out from stack 1: "<<arr[top1]<<endl;
        top1--;
    }
}

void pop2(){
    if (top2==MAX){
        cout<<"stack undrflow";
    }
    else{
        cout<<"popped out from stack 2: "<<arr[top2]<<endl;
        top2++;
    } 
}

void peek1(){
    if (top1==-1){
        cout<<"stack 1 is empty";
    }
    else{
        cout<<arr[top1];
    }
}

void peek2(){
    if (top2==MAX){
        cout<<"stack 2 is empty";
    }
    else{
        cout<<arr[top2];
    }
}

void display(string stack_name){
    if (stack_name=="stack1"){
        //cout<<top1;
        for (int i = 0; i <= top1; i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for (int i = MAX-1; i >= top2; i--){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){
    push1(1);
    //cout<<arr[0]<<endl;
    push1(2);
    push1(3);
    push1(4);
    push1(5);
    //push1(6);
    push2(5);
    push2(4);
    push2(3);
    push2(2);
    push2(1);
    display("stack1");
    cout<<endl;
    display("stack2");
    cout<<endl;
    push2(6);
    cout<<endl;
    pop1();
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    for (int i = 0; i < top1; i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = top2; i <= MAX-1; i++){
            cout<<arr[i]<<" ";
        }
    
    
}