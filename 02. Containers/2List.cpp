/*
    ## List - 
            -(internally implemented as doubly Linked list)
            - so randomally element is not Accessible
    

    # implementation

        list<int>l;
        list<int>l = {1,2,3};


    # Functions

        1. Push_back & push_front()
        
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


#include<list>
#include<iostream>
using namespace std;

int main(){

    list<int>l;

    l.push_back(1);
    l.push_back(2);

    l.push_front(3);
    l.push_front(4);

    for(int val:l){
        cout<<val<<" ";
    }
    cout<<endl;

}