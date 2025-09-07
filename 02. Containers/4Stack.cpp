/*
    ## Stack

        - LIFO / FILO
        - 

    # Implementation

        stack<int>st;
    

    # Functions

        1. push,emplace
        2. top
        3. pop
        4. size
        5. empty
        6. swap
*/

#include<iostream>
#include<stack>
using namespace std;


int main(){

    stack<int>st;

    st.push(1);
    st.push(2);
    st.emplace(54);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout<<st.top()<<endl;

    cout<<st.size()<<endl;

    st.pop();


    stack<int>st2;
    st2.swap(st); // s1 become Empty

    cout<<st.size()<<endl; // 0

    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }

}