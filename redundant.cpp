/*
    Check whether string contains redundant parenthesis
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool check(string s){

    stack<char> st;

    for(int i = 0 ; i < s.size() ; ++i){

        if(s[i] == ')'){

            if(st.top() == '('){
                return true;
            }

            while(st.top() != '('){
                st.pop();
            }
            st.pop();

        }
        else{
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }
        }

    }
    return false;

}

int main(){
    
    string s;
    cin>>s;

    if(check(s)){
        cout<<"Redundant paranthesis";
    }
    else{
        cout<<"No redundant parenthesis";
    }


    return 0;
}