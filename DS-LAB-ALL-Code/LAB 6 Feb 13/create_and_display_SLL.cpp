#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next=NULL;
    Node(int val){
        this->val=val;
    }
};

int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    a.next=&b;
    b.next=&c;
    Node* temp=&a;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}