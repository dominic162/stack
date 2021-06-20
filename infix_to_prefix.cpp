#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;

string get_ans(const string &s){


    map<char , int > mp;
    mp[')'] = 0;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    mp['^'] = 3;

    stack <char> st;
    stack<char> ans;

    for(int i = s.size() - 1; i >= 0 ; --i){

        if(s[i] == ')'){
            st.push(s[i]);
        }
        else{

            if(s[i] == '('){
                while(st.top() != ')'){
                    ans.push(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{

                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] =='^'){

                    while(!st.empty() && mp[st.top()] > mp[s[i]]){
                        ans.push(st.top());
                        st.pop();
                    }

                    if( !st.empty() && mp[s[i]] == mp[st.top()]){

                        if(s[i] == '^'){
                            ans.push(st.top());
                            st.pop();
                        }

                    }
                    st.push(s[i]);

                }
                else{
                    ans.push(s[i]);
                }
            
            }

        }

    }

    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }

    string pref = "";

    while(!ans.empty()){
        pref += ans.top();
        ans.pop();
    }

    return pref;
}

int main(){

    string s;
    cout<<"Enter infix expression : ";
    cin>>s;

    string ans = get_ans(s);

    cout<<ans;

    return 0;
}