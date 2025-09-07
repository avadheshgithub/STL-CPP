/*
    ## Deque : 
            -Double Ended Queue
            - implementd with help of dynamic Array
            - randomally ele acessible

    #Implementation

        deque<int>d;
        deque<int>d = {1,2,3};

    # Funcions

        1. push_back & push_front
        2. emplace_back & emplace_front
        3. pop_back & pop_front

    # OTher Fun

        1. size
        2. erase
        3. clear
        4. begin
        5. end
        6. rbegin
        7. rend
        8. insert
        9. front
        10. back
*/

#include<deque>
#include<iostream>
using namespace std;

int main(){

    deque<int>d;

    d.push_back(1);
    d.push_back(2);

    d.push_front(3);
    d.push_front(4);

    for(int val:d){
        cout<<val<<" ";
    }
    cout<<endl;

}