/*
    ## Pair


    # Implementation

        pair<int,int>p;
        pair<int,int>p = {3,4};

        pair<int,pair<char,int>>p = {1,{'a',2}};

        vector<pair<int,int>>vec ={{1,2},{3,4},{5,6}};
        vec.emplace_back(7,8) // emplace back-->faster than push_back

    # Functions

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    pair<string,int>p = {"Avadhesh",12};

    cout<<p.first<<endl;
    cout<<p.second<<endl;

    pair<int,pair<char,int>>pr = {1,{'a',2}};
    cout<<pr.first<<endl;
    cout<<pr.second.first<<endl;//a
    cout<<pr.second.second<<endl;//2


    vector<pair<int,int>>vec ={{1,2},{3,4},{5,6}};
    vec.push_back({7,8}); //

    vec.emplace_back(9,10); // emplace back ---> no need to create pair--> it assume as a pair

    for(pair<int,int>p:vec){
        cout<<p.first<<" "<<p.second<<endl;
    }

}