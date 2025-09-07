/*
    1. Vector max

        *max_element(vec.begin(),vec.end());

    2. Vector min

        *min_element(vec.begin(),vec.end());

    3. Vector sum

        accumulate(vec.begin(),vec.end(),0);
*/

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
    vector<int>vec = {1,15,24,67,453};

    cout<<*max_element(vec.begin(),vec.end()); // max

    cout<<*min_element(vec.begin(),vec.end());//min

    cout<<accumulate(vec.begin(), vec.end(), 0);// sum
}