/*
    ## Map

        - key,value


    # Implementation

        map<string,int>mp;
        m[key]=value;


    # Functions

        1. insert,emplace -->O(logn)
        2. count -->O(logn)
        3. erase -->O(logn)
        4. find
        5. size
        6. empty

    # Type of Map

        1. multi map  - multple keys we can use (duplicate key) & dont use curly braces

            multimap<string,int>m;

        2. unordered map - not any order

            unordered_map<string,int>m;

            1. insert,emplace -->O(1)
            2. count -->O(1)
            3. erase -->O(1)
            4. find
            5. size
            6. empty

*/

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    //-----------------------------MAP--------------------------------
    map<string,int>mp;
    mp["tv"]= 100;
    mp["laptop"]=120;
    mp["tablet"]= 109;
    mp["watch"] = 50;

    mp.insert({"camera",89}); // insert
    mp.emplace("Avadhesh",04);//emplace

    cout<<"count = "<<mp["laptop"]<<endl;// count
    mp.erase("tv"); // erase

    if(mp.find("camera")!=mp.end()){ // find
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    cout<<mp.size()<<endl;

    cout<<mp.empty()<<endl;
    for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;



    //------------------------------MultiMap-------------------------------
    multimap<string,int>mmp;
    mmp.emplace("Tv",100);
    mmp.emplace("Tv",100);
    mmp.emplace("Tv",100);
    mmp.emplace("Tv",100);
    mmp.emplace("Tv",100);

    for(auto p:mmp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    mmp.erase("tv");
    mmp.erase(mmp.find("tv"));


    //---------------------------UnorderedMap-------------------------
    unordered_map<string,int>m;
    m["tv"]= 100;
    m["laptop"]=120;
    m["tablet"]= 109;
    m["watch"] = 50;

    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }

}