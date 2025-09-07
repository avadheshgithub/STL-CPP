/*
    1. Sorting

        sort(arr,arr+n);

        sort(arr,arr+n,greater<int>());

        sort(v.begin(),v.end());


    # custom Comparator - boolean function

        vector<pair<int,int>>vec ={{1,2},{3,4},{1,5},{6,2}};

*/

#include<iostream>
using namespace std;
#include<algorithm>

#include<bits/stdc++.h>


int main(){
    int arr[5] ={1,2,5,2,1};

    sort(arr,arr+5); // increasing order
    
    for(auto x:arr){ 
        cout<<x<<" ";
    }
    cout<<endl;


    sort(arr,arr+5,greater<int>()); // decreasing order
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;


    //---------------------------Vector---------------
    vector<int>vec = {1,6,5,7,8};

    sort(vec.begin(),vec.end()); // increasing
    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;

    sort(vec.begin(),vec.end(),greater<int>()); // decreasing
    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<endl;



    //--------------------------------Custom Comparator-----------------
    vector<pair<int,int>>v ={{1,2},{3,4},{1,5},{6,2}};

    sort(v.begin(),v.end());  //---> sort based on first ele
    
    
    bool comparator(pair<int,int>p1,pair<int,int>p2){
        if(p1.second<p2.second) return true;
        else return false;
    }
    sort(v.begin(),v.end(),comparator);  //---> sort based on second ele


    bool comp(pair<int,int>p1,pair<int,int>p2){ //--? if 2nd ele same then sorting based on first ele
        if(p1.second<p2.second) return true;
        if(p1.second<p2.second) return false;
        
        if(p1.first<p2.first) return true;
        else return false;
    }
    sort(v.begin(),v.end(),comparator);

}