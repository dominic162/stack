/*
    Given a histogram, find max rectangular area in it;
*/

#include<iostream>
#include<stack>

using namespace std;

class solution{
    public:
        int* makearr(int n);

        int naive_appr(int* arr , int n);  // Naive approach

        int btr_appr(int* arr , int n); // better approach

        int bst_appr(int* arr , int n);

        void disp(int* arr,int n);
};

int main(){

    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    
    solution sl;

    int* arr = sl.makearr(n);

    int gtr = sl.bst_appr(arr,n);

    cout<<"Max area is "<<gtr;

    return 0;
}

int* solution::makearr(int n){

    int* arr = new int [n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    return arr;
}

void solution::disp(int* arr,int n){
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

// Naive approach
int solution::naive_appr(int* arr, int n){

    int area=0,carea=0;

    for(int i=0; i < n ;++i){

        carea=arr[i];

        for(int j = i-1; j>=0; j--){
            if(arr[j] >= arr[i]){
                carea+=arr[i];
            }
            else{
                break;
            }
        }

        for(int j=i+1; j<n; j++){
            if(arr[j] >= arr[i]){
                carea+=arr[i];
            }
            else{
                break;
            }
        }

        area = max(area,carea);

    }

    return area;

}

//Better approach
int solution::btr_appr(int* arr , int n){

    int marea=0;

    int* ps = new int [n];
    int* ns = new int [n];
    stack<int> st;
    for(int i=0;i<n;++i){

        while( st.empty() == false && arr[i] <= arr[st.top()]){
            st.pop();
        }

        if(st.empty()){
            ps[i] = -1;
        }
        else{
            ps[i] = st.top();
        }
        st.push(i);
    }

    while(st.empty()==false){
        st.pop();
    }

    for(int i=n-1; i>=0; i--){

        while(st.empty()==false && arr[i] <= arr[st.top()]){
            st.pop();
        }

        if(st.empty()){
            ns[i] = -1;
        }
        else{
            ns[i] = st.top();
        }

        st.push(i);
    }

    while(st.empty()==false){
        st.pop();
    }

    int csum;
    for(int i=0; i<n ;++i){

        csum=arr[i];

        if(ps[i]==-1){
            csum+=(arr[i]*i);
        }
        else{
            csum+=(arr[i]*(i-ps[i]-1));
        }

        if(ns[i]==-1){
            csum+=(arr[i]*(n-1-i));
        }
        else{
            csum+=(arr[i]*(ns[i]-i-1));
        }

        marea = max(marea,csum);

    }    

    return marea;
}


//Best approach
int solution::bst_appr(int* arr , int n){

    int marea = 0, carea = 0;

    stack<int> st;

    for(int i = 0 ; i < n ; ++i){

        while(st.empty() == false && arr[st.top()] > arr[i]){

            int temp = st.top();
            st.pop();

            carea = arr[temp]*(st.empty()?i:(i-st.top()-1));
            marea = max(marea,carea);
        }
        st.push(i);
    }

    while(st.empty() == false){

        int temp = st.top();
        st.pop();

        carea = arr[temp]*(st.empty()?n:(n-st.top()-1));
        marea = max(marea , carea );
    }


    return marea;
}