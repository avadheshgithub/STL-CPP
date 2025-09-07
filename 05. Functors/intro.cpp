/*
    ## Functos 
    
        - predefined function objects

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // For std::greater

int main() {
    std::vector<int> v = {5, 2, 8, 1, 3};

    // greater<int>() --> functor
    sort(v.begin(), v.end(), std::greater<int>());

    return 0;
}