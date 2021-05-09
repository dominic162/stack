/*
    Given a substring , find maximum length of valid paranthesis substring;
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack < int > st;
        int mlen = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            
            if(s[i] == '('){
                st.push(i);
            }
            else{
                
                if(st.empty() || s[st.top()] == ')'){
                    st.push(i);
                }
                else{
                    st.pop();
                    int clen = st.empty()?-1:st.top();
                    
                    clen = i - clen;
                    if(clen > mlen){
                        mlen = clen;
                    }
                }
                
            }
            
        }
        return mlen;
    }
};

int main(){
    
    string s;
    cout<<"Enter string: ";
    cin>>s;

    Solution sl;
    
    cout<<"Max length of valid substring: "<<sl.findMaxLen(s);

    return 0;
}