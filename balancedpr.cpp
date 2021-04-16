#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checking(char a,char b){
    return a==b;
}

bool checkparanth(string s){
    stack <char> st;
    char r;

    if(st.size()%2!=0){
        return false;
    }

    for(int i=0;i<s.size();i++){

        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            else{
                if(s[i]=='}')
                    r='{';
                else{
                    if(s[i]==']')
                        r='[';
                    else
                        r='(';
                }   
                if(checking(st.top(),r)){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }

        }

    }
    if(st.empty()){
        return true;
    }
    return false;
}


int main(){

    string s;
    cout<<"Enter paranthesis string: "<<endl;
    cin>>s;
    cout<<"Paranthesis are ";
    if(!checkparanth(s)){
        cout<<"not ";
    }
    cout<<"balanced"<<endl;

    return 0;
}