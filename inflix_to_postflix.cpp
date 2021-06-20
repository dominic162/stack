/*
    Infix to posfix
*/

#include<iostream>
#include<map>
#include<stack>
using namespace std;

char * find_ans(char * s , int n){

    stack<char> st;

    map<char,int> mp;
    mp['('] = 0;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    mp['^'] = 3;

    char * ans = new char [n + 1];
   
    int size = 0;

    for(int i = 0 ; s[i] != '\0' ; ++i){

        if(s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(s[i] == ')'){
                while(st.top() != '('){
                    ans[size] = st.top();
                    size++;
                    st.pop();
                }
                st.pop();
            }
            else{

                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){

                    
                    while(!st.empty() && mp[st.top()] > mp[s[i]]){
                        ans[size] = st.top();
                        st.pop();
                        size++;
                    }
                    
                    if( !st.empty() && mp[s[i]] == mp[st.top()]){

                        if( !st.empty() && s[i] != '^'){
                            ans[size] = st.top();
                            size++;
                            st.pop();
                        }

                    }
                    
                    st.push(s[i]);

                }
                else{
                    ans[size] = s[i];
                    size++;
                }

            }
        }

    }

    while(!st.empty()){
        ans[size] = st.top();
        size++;
        st.pop();
    }
    
    for( ; size < n + 1 ; size++){
        ans[size] = '\0';
    }

    return ans;

}

int main(){

    cout<<"Enter length of string: ";
    int n;
    cin>>n;

    char * s = new char [n + 1];
    s[n] = '\0';
    cout<<"Enter infix: ";
    cin>>s;

    char * ans = find_ans(s , n);

    cout<<"Postfix exp is: ";

    cout<<ans;

    delete []s;
    delete []ans;

    return 0;
}