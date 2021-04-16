/*
    Implement n stacks in a array;
*/

#include<iostream>
using namespace std;

class stack{
    public:
        int k;
        int size;
        int* next;
        int* arr;
        int* top;
        int freetop;

        void push(int element, int sn);

        stack(int n,int k1); 

        int pop(int sn);

};

int main(){

    int n,k;
    cout<<"Enter total number of elements and number of stacks: ";
    cin>>n>>k;
    stack st(n,k);

    int i,sn;
    do{
        cout<<"\nEnter 1 for push\n2 for pop\n3 for exit";
        cin>>i;
        switch(i){
            case 1:
                int e;
                cout<<"Enter element and stack number: ";
                cin>>e>>sn;
                st.push(e,sn);
                break;

            case 2:
                cout<<"Enter stack number: ";
                int ans;
                cin>>sn;
                ans=st.pop(sn);
                if(ans == -1){
                    cout<<"Stack is empty";
                }
                else{
                    cout<<"Top element of stack number "<<sn<<" is "<<ans;
                }
                break;
        }
    }while(i!=3);

    return 0;
}

stack::stack(int n,int k1):size(n),k(k1){
    arr  = new int[size];
    next = new int[size];
    top  = new int[k];
    freetop = 0;
    for(int i=0;i<k;++i){
        top[i] = -1;
    }
    for(int i=0;i<size;++i){
        arr[i] = 0;
        next[i] = i+1;
    }
    next[size-1] = -1;
}

void stack::push(int element, int sn){

    if(freetop == -1){
        cout<<"Stack overflow";
        return ;
    }
    int temp = next[freetop];

    arr[freetop] = element;
    next[freetop] = top[sn];
    top[sn] = freetop;
    freetop = temp;
    return ;
}   



int stack::pop(int sn){

    if(top[sn]==-1){
        return -1;
    }

    int i=top[sn],ans=arr[i];
    arr[i]=0;
    top[sn] = next[i];
    next[i] = freetop;
    freetop = i;

    return ans;
}