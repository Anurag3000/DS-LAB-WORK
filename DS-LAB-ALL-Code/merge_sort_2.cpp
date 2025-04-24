#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> a, vector<int> b, vector<int>& ans){
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i++];
        }
        else{
            ans[k++] = b[j++];
        }
    }
    while(i < a.size()){
        ans[k++] = a[i++];
    }
    while(j < b.size()){
        ans[k++] = b[j++];
    }
}


void mergesort(vector<int>& v){
    int n=v.size();
    if(n==1) return;
    else{
        int n1= n/2, n2= n-n1;
        vector<int>a(n1),b(n2);
        for (int i = 0; i < n1; i++){
            a[i]=v[i];
        }
        int idx=0;
        for (int j = n1; j < n; j++){
            b[idx]=v[j];
            idx++;
        }
        mergesort(a);
        mergesort(b);
        merge(a,b,v);
    }
};


int main() {
    vector<int> v = {5, 2, 9, 1, 6, 3};
    mergesort(v);
    for(int x : v) {
        cout << x << " ";
    }
    return 0;
}
