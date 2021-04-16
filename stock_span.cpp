/*
    Given stock prices, find span of each day(span is contiguous element before it which has less price as it);
*/

#include<iostream>
#include<stack>
using namespace std;

class solution{
    public:
        int* makearr(int n);

        int* stock_span(int* arr , int n);

        void disp(int* arr,int n);
};

int main(){

    int n;
    cout<<"Enter number of stocks: ";
    cin>>n;
    
    solution sl;

    int* arr = sl.makearr(n);

    int* stspan = sl.stock_span(arr,n);
    cout<<"\nStock Span is:\n";
    sl.disp(stspan , n);

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

int* solution::stock_span(int* arr , int n ){
    int* span = new int [n];

    stack<int> st;

    for(int i=0; i<n; ++i){

        while(!st.empty() && arr[st.top()] < arr[i] ){
            st.pop();
        }

        if(st.empty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-st.top();
        }
        st.push(i);

    }

    return span;
}

void solution::disp(int* arr,int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}