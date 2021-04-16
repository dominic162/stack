/*
    Given a stack,reverse ot by using recursion;
*/

#include<iostream>
#include<stack>
using namespace std;

class solution{
    public:
        void reverse_stack(stack<int> &st1);

        void push_bottom(stack<int> &st1,int x);
};


void solution::reverse_stack(stack<int> &st1){
    
    if(st1.empty()){
        return ;
    }

    int temp=st1.top();
    st1.pop();
    reverse_stack(st1);
    push_bottom(st1,temp);

    return ;
}

void solution::push_bottom(stack<int> &st1,int x){
    
    if(st1.empty()){
        st1.push(x);
        return ;
    }

    int temp=st1.top();
    st1.pop();
    push_bottom(st1,x);
    st1.push(temp);

    return ;
}

int main(){

    int n;
    cout<<"Enter number of elements in stack: ";
    cin>>n;

    cout<<"Enter element in stack: ";
    stack<int> st1;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        st1.push(x);
    }

    solution sl;
    sl.reverse_stack(st1);

    cout<<"Reversed elements in stack are:\n ";
    for(int i=0;i<n;i++){
        cout<<st1.top()<<" ";
        st1.pop();
    }

    return 0;
}