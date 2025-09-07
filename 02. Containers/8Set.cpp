/*
    ## Set - avoid duplicate


    # Implementation

        set<int>st;

    1. insert,emplace -->O(logn)
        2. count -->O(logn)
        3. erase -->O(logn)
        4. find
        5. size
        6. empty

    # Type of Set

        1. multi set  - allow duplicate values

            multiset<int>m;

        2. unordered set - not any order

            unordered_set<int>m;

            1. insert,emplace -->O(1)
            2. count -->O(1)
            3. erase -->O(1)
            4. find
            5. size
            6. empty


*/

#include<iostream>
using namespace std;
#include<set>
#include<unordered_set>


int main(){

    //---------------------SET--------------------------
    set<int>st;
    st.insert(1);
    st.insert(3);
    st.insert(2);
    st.insert(3);
    st.insert(2);

    st.lower_bound(3); // if 3 so 3 otherwise just big to 3
    st.upper_bound(3); // only greater than 3 (not equal)

    cout<<st.size();
    //---------------------------multiset-----------------------------------------------
    multiset<int>mst;
    mst.insert(1);
    mst.insert(3);
    mst.insert(2);
    mst.insert(3);
    mst.insert(2);

    //----------------------unordered_set-----------------------------------------------------
    unordered_set<int>s;







}