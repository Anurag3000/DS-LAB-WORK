#include<iostream>
using namespace std;
#define MAX 5

int rear=-1;
int front=-1,size=0;
int arr[MAX];

bool isFull(){
    if (size==MAX){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if (size==0){
        return true;
    }
    else{
        return false;
    }
}

void push_front(int x){
    if (isFull()==true){
        cout<<"Overflow";
    }
    else if (front==-1 && rear==-1){
        front=0;
        rear=0;
        arr[front]=x;
        size++;
    }
    else{
        front=(front-1+MAX)%MAX;
        arr[front]=x;
        size++;
    }
}

void pop_front(){
    if (isEmpty()==true){
        cout<<"Underflow";
    }
    else if(front==rear){
        cout<<arr[front];
        front=-1;
        rear=-1;
        size--;
    }
    else{
        cout<<arr[front];
        front=(front+1)%MAX;
        size--;
    }
}

void push_back(int x){
    if (isFull()==true)
    {
        cout<<"overflow";
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        arr[rear]=x;
        size++;
    }
    else{
        rear=(rear+1)%MAX;
        arr[rear]=x;
        size++;
    }
}

void pop_back(){
    if (isEmpty()==true){
        cout<<"underflow";
    }
    else if(front==rear){
        cout<<arr[rear];
        rear=-1;
        front=-1;
        size--;
    }
    else{
        cout<<arr[rear];
        rear=(rear-1+MAX)%MAX;
        size--;
    }
}

void display(){
    if (front==-1 && rear==-1)
    {
        cout<<"empty";}
    else{
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%MAX;
        }
        cout<<arr[rear];
    }   
}

