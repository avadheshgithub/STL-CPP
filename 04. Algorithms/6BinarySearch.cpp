/*
    Binary Search

        binary_search(v.begin(),v.end(),target);
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>vec = {1,15,24,67,453};

    cout<<binary_search(vec.begin(),vec.end(),15);

    cout<<binary_search(vec.begin(),vec.end(),19);
}