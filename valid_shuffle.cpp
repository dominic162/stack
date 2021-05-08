/*
    Given 2 string and a reference string , find if reference string is a valid shuffle of 2 strings;
    valid shuffle means all elements of s1 must be in order and all elements of s2 must also be in order;
*/

#include<iostream>
#include<string>
using namespace std;

bool check( string s1 , string s2 , string r ){

    int l1 = s1.size() , l2 = s2.size() , l3 = r.size();

    if(l1 + l2 != l3){
        return false;
    }

    int i = 0 , j = 0 , k = 0;

    while( i < l1 && j < l2){

        if(r[k] == s1[i]){
            ++i;
        }
        else{
            if(r[k] == s2[j]){
                ++j;
            }
            else{
                return false;
            }
        }

        ++k;
    }

    while( i < l1){
        if(s1[i] != r[k]){
            return false;
        }
        ++i;
        ++k;
    }

    while( j < l2){
        if(s2[j] != r[k]){
            return false;
        }
        ++j;
        ++k;
    }


    return true;

}

int main(){

    string s1,s2;
    cout<<"Enter 1st string: ";
    cin>>s1;
    cout<<"Enter 2nd string: ";
    cin>>s2;
    
    string r;
    cout<<"Enter reference string: ";
    cin>>r;

    if(check(s1,s2,r)){
        cout<<"Valid shuffle";
    }
    else{
        cout<<"Not valid shuffle";
    }


    return 0;
}
