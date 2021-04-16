/*
    Given a array, find leftmost greater of every element; 
*/

#include<iostream>
#include<stack>
using namespace std;

class solution{
    public:
        int* makearr(int n);

        int* pre_gtr(int* arr , int n);

        void disp(int* arr,int n);
};

int main(){

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    
    solution sl;

    int* arr = sl.makearr(n);

    int* gtr = sl.pre_gtr(arr,n);

    sl.disp(gtr,n);

    return 0;
}

int* solution::makearr(int n){

    int* arr = new int [n];
    cout<<"Enter stocks price: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    return arr;
}

void solution::disp(int* arr,int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

int* solution::pre_gtr(int* arr,int n){

    int* gtr = new int [n];

    stack<int> st;

    for(int i=0; i<n; ++i){

        while(st.empty()==false && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            gtr[i] = -1;
        }
        else{
            gtr[i] = arr[st.top()];
        }

        st.push(i);

    }

    return gtr;

}