/*
    ## Reverse


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include<bits/stdc++.h>


int main(){
    vector<int>vec ={1,2,5,2,1};

    reverse(vec.begin(),vec.end());

    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;

    reverse(vec.begin()+1,vec.begin()+3);

    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;

    

}