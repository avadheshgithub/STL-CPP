/*

    ## Priorty Queue 

        - called the heap
        - internally tree strcture implemented


    # Implementation

        priority_queue<int>q; // max heap
        priority_queue<int,vector<int>,greater<int>>q; // min heap


        Note - Greater<int> --> functor (function Obj)

    ## Functions

        1. push,emplace -->O(logn)
        2. top ---> O(1)
        3. pop --->O(logn)
        4. size ---> O(1)
        5. empty
        6. swap

*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);

    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;

}