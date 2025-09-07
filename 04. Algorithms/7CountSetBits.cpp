/*
    ## Count Set Bits

        __builtin_popcount()

        __builtin_popcountl()

        __builtin_popcountll()

*/

#include<iostream>
using namespace std;


int main(){

    int n = 15;
    long int n2 = 15;
    long long int n3 = 15;

    cout<<__builtin_popcount(n)<<endl;
    cout<<__builtin_popcountl(n)<<endl;
    cout<<__builtin_popcountll(n)<<endl;


}