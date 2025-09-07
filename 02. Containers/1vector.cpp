/*

    ## Vector -

        - similar to array but size is dynamic
        - resize at runTime

    # Define-

        Vector<int>vec;
        vector<int>vec= {1,2,3,4,5};
        vector<int>vec(3,-1); // DP - tabulation
        vector<int>vec2(vec1); // copy vector

    # Function -
    
        TC - O(1)

        1. size & capacity ----->capacity double when size full
        2. push_back & pop_back --->
        3. emplace_back ---> similar to push_back but 
        4. at() , []
        5. front & back - first and last element


        TC - O(n)

        1. Erase()
        2. insert
        3. clear
        4. Empty

        ## Note - erase & clear only can chnage the size,not the capacity

        * begin
        * end
        * rbegin
        * rend
        * 
    
    # Iterators

        1. vec.begin
        2. vec.end       -- it point to last element to next aval (garbage)


        1. Farword

        vector<int>::iterator it;

        for(it=vec.begin();it!=vec.end();it++){
            cout<<*(it)<<endl;
        }

        2. BackWard
        
        for(auto it=vec.begin();it!=vec.rend();i++){
            cout<<*(it)<<endl;
        }

*/


#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int>vec;
    vec.push_back(1);
    cout<<vec.size()<<" "<<vec.capacity()<<endl;
    vec.push_back(2);
    cout<<vec.size()<<" "<<vec.capacity()<<endl;
    vec.push_back(3);
    cout<<vec.size()<<" "<<vec.capacity()<<endl;
    vec.pop_back();
    cout<<vec.size()<<" "<<vec.capacity()<<endl;
    vec.emplace_back(6);

    cout<<vec[2]<<endl;
    cout<<vec.at(2);

    cout<<vec.front()<<endl;// first element
    cout<<vec.back()<<endl; // last Element


    for(int x:vec){
        cout<<x<<" ";
    }

    vector<int>vec2(vec);


    vec.erase(vec.begin()); // 1st element erased
    vec.erase(vec.begin()+2);// 3rd element erased
    vec.erase(vec.begin(),vec.begin()+3);  // Vec.erase[start,end)

    vec.insert(vec.begin()+2,100); // vec.insert(pos,val)

    vec.clear(); // capacity same but size=0;

    vec.empty() ; // true/false;



    *(vec.begin()); // first value
    *(vec.end());  // last ele ke next value -->0



    vector<int>::iterator it; // auto --> in place of this big line

    for(it=vec.begin();it!=vec.end();it++){ // farward
        cout<<*(it)<<endl;
    }

    for(auto it=vec.rbegin();it!=vec.rend();it++){ // backward
        cout<<*(it)<<endl;
    }

}

