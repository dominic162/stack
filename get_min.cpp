/*
    get min in O(1) if all elements are positive;
*/

#include<iostream>
#include<stack>
using namespace std;

class solution{
    public:
        stack<int> s;
        int mins;

        void push(int x);
        void pop();
        int min();
        int top();
        solution():mins(-1){}

};

int main(){

    solution sl;
    char ch;
    int x;
    do{
        cout<<"\nEnter 1 for push\n2 for pop\n3 for top element\n4 for min element\n5 for exit\n";
        cin>>ch;
        switch(ch){
            case '1':
                cout<<"Enter element to push: ";
                cin>>x;
                sl.push(x);
                break;
            
            case '2':
                sl.pop();
                break;

            case '3':
                if(sl.top()==-1){
                    cout<<"\nStack is empty";
                }
                else{
                    cout<<"\nTop element is "<<sl.top();
                }
                break;

            case '4':
                if(sl.min()==-1){
                    cout<<"\nStack is empty";
                }
                else{
                    cout<<"Min element is "<<sl.min();
                }
                break;
        }

    }while(ch!='5');

    return 0;
}

void solution::push(int x){
    if(mins == -1){
        s.push(0);
        mins=x;
        return ;
    }

    if(x < mins){
        s.push(2*x-mins);
        mins=x;
        return ;
    }

    s.push(x);
    return ;
}

void solution::pop(){
    if(s.top()<=mins){
        mins = 2*mins - s.top();
    }
    s.pop();
    return ;
}

int solution::top(){
    if(s.top()<=mins){
        return mins;
    }
    return s.top();
}

int solution::min(){
    return mins;
}
