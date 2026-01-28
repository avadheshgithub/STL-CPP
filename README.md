# C++ STL Quick Help
It contains C++ STLs usage and quick help with easy to understand comments and examples (copy+paste to use).
I learned these while solving different kinds of Leetcode Questions.  

### :memo:Different ways of using priority_queue (i.e. heap) :mount_fuji:-

- Default declarations
```c++
priority_queue<int> pq;                            //creates max-heap
priority_queue<int, vector<int>> pq;               //creates min-heap
```
<br>

- writing comparator function for priority_queue
```c++
1. Using the built-in comparator provided by C++ : 

priority_queue<int, vector<int>, greater<int>> pq;  //creates min-heap
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //min_heap of pairs
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq;               //min_heap of pairs
```
```c++
2. Using user defined comparator as a structure

struct comp {
    bool operator()(int &a, int &b) {
        return a<b; //max-heap
        return a>b; //min-heap
    }
};

priority_queue<int, vector<int>, comp> pq;
```

```c++
3. Using user defined comparator as a function

static bool comp(int &a, int &b) {
    return a<b; //max-heap
    return a>b; //min-heap
}

priority_queue<int, vector<int>, function<bool(int&, int&)> > pq(comp);   //usage
```
```c++
4. Using lambda function

auto comp = [](int &a, int &b) {
    return a<b; //max-heap
    return a>b; //min-heap 
};

priority_queue<int, vector<int>, decltype(comp) > pq(comp);   //usage

NOTE :
You can receive parameters inside [] as well i.e. auto comp = [some_parameters]
Ex : You want to access a map inside this lambda function
unordered_map<int, int> mp;

auto comp = [&mp](int &a, int &b) {
    return mp[a] < mp[b]; //etc.
};

```

### :memo: When and why to use std::move() :arrow_left:
```c++
/*
    To efficiently transfer the resources from source to target.
    By efficient, I mean no usage of extra space and time for creating copy.
*/
Examples :
    string source = "MIK";
    string target = "";
    target = std::move(source);
    cout << " source = " << source << endl;
    cout << "target = "  << target << endl;
    /*
        output :
        source = 
        target = "MIK"
    */
    
    vector<string> v;
    string str = "example";
    v.push_back(std::move(str));
    /*
    After this, str becomes empty i.e. ""
    And while moving str inside v, no extra copy of str was done implicitly.
    */

    vector<int> temp{1, 2, 3};
    vector<vector<int>> result;
    result.push_back(std::move(temp));
    /*
    This allows no copy of "temp" being created.
    It ensures that the contents of "temp"
    will be moved into the "result".  This is less
    expensive, also means temp will now be empty.
    */
```

### :memo: std::accumulate(begin_iterator, end_iterator, initial_sum) :heavy_plus_sign:
```c++
int sum = 0;
vector<int> nums{1, 3, 2, 5};
sum = accumulate(begin(nums), end(nums), 0);

cout << sum; //11

Benefit : You didn't have to write for loop to find the sum
```

### :memo: std::accumulate(begin_iterator, end_iterator, initial_sum, lambda) :heavy_plus_sign:
```c++
lambda : Binary operation taking an element of type <initial_sum> as first argument and an
            element in the range as second, and which returns a value that can be assigned to type T.

Example-1 : 

auto lambda = [&](int s, long n) {
    return s + n*n; //sums the square of numbers
    //You can call any other function inside as well
};

int sum = 0;
vector<int> nums{1, 3, 2, 5};
sum = accumulate(begin(nums), end(nums), 0, lambda);

cout << sum; //39

Example-2 : Handling 2-D matrix
//Summming all elements row by row
auto lambda = [&](int sum, vector<int> vec) {
    sum = sum + accumulate(begin(vec), end(vec), 0);
    return sum;
};

int result =  accumulate(matrix.begin(), matrix.end(), 0, lambda);


Beautiful example and usage :
Leetcode-1577 (My Approach - https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/discuss/1305961/C%2B-(A-very-simple-Two-Sum-like-approach)

Leetcode-1572 (My Approach - https://leetcode.com/problems/matrix-diagonal-sum/discuss/3498479/Using-C%2B%2B-STL-%3A-accumulate)

```

### :memo: min_element(begin_iterator, end_iterator), max_element(begin_iterator, end_iterator), minmax_element(begin_iterator, end_iterator) :astonished:
```c++
vector<int> nums{1, 3, 2, 5};

int minimumValue = *min_element(begin(nums), end(nums)); //1
int maximumValue = *max_element(begin(nums), end(nums)); //5
                OR,
        auto itr  = minmax_element(begin(nums), end(nums));
int minimumValue  = *itr.first;  //remember, first is minimum  //1
int maximumValue  = *itr.second; //remember, second is maximum //5


Benefit : You didn't have to write for loop to find the max or min element
```

### :memo: upper_bound(), lower_bound() in sorted vector, ordered set, ordered map :outbox_tray:
```c++

For vector:
vector<int> vec{10,20,30,30,20,10,10,20};
vector<int>::iterator up  = upper_bound(begin(vec), end(vec), 35);//returns iterator to first element "greater" than 35
vector<int>::iterator low = lower_bound(begin(vec), end(vec), 35);//returns iterator to first element "greater or equal" to 35
cout << "upper_bound at position " << (up - vec.begin()) << '\n';
cout << "lower_bound at position " << (low- vec.begin()) << '\n';

For set:
st.upper_bound(35); //returns iterator to first element "greater" than 35
st.lower_bound(35); //returns iterator to first element "greater or equal" than 35

For map:
mp.upper_bound(35); //returns iterator to first element "greater" than 35
mp.lower_bound(35); //returns iterator to first element "greater or equal" than 35

Benefit : You didn't have to write binary search (in case of vector),
JAVA's tree_map equivalent in C++ (in case of map or set)
There are amazing applications or problems that can be solved using the above concepts.
Example : My Calendar I (Leetcode - 729) -
         You can find it in my interview_ds_algo repository as well B-)
```

### :memo: std::rotate 🌀
```c++
vector<int> vec{1, 2, 3, 4};
int n = vec.size();
int k = 2;

rotate(vec.begin(), vec.begin()+k, vec.end());   //Left Rotate by K times

rotate(vec.begin(), vec.begin()+n-k, vec.end()); //Right Rotate by K times

```

### :memo: To check if some rotation of string s can become string t🌀
```c++

string s = "abcde";
string t = "cdeab";

cout << (s.length() == t.length() && (s+s).find(t) != string::npos) << endl;

```

### :memo: std::next_permutation ➡️
```c++
It gives the next lexicographically greater permutation.
So, if the container is already the greatest permutation (descending order), it returns nothing.

vector<int> vec{1, 2, 3, 4};
    
if(next_permutation(begin(vec), end(vec)))
    cout << "Next permutation available" << endl;

for(int &x : vec)
    cout << x << " ";
    
//Output : 1, 2, 4, 3

Also see : std::prev_permutation() - It gives just the previous lexicographically smaller permutation.
But I have never encountered any question where it's required till now. So you can skip it.
    Leetcode - 31  : Next Permutation
    etc.
```


### :memo: std::stringstream :fast_forward:
```c++
Usage:
1) Converting string to number
2) Count number of words in a string

Example-1
    string s = "12345";
    stringstream ss(s);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    ss >> x;
    cout << x;
    
Exmaple-2
    stringstream s(ss);
    string word; // to store individual words
  
    int count = 0;
    while (s >> word)
        count++;
    cout << count;
    NOTE: It will tokenize words on the basis of ' ' (space by default) characters
Example-3
    It can be used very well to extract numbers from string.
    string complex = "1+1i";
    stringstream ss(complex);
    char justToSkip;
    int real, imag;
    ss >> real >> justToSkip >> imag >> justToSkip;
    cout << real << ", " << imag; //output : 1, 1
    
    Other application on this STL :
    Leetcode - 151  : Reverse Words in a String
    Leetcode - 186  : Reverse Words in a String II
    Leetcode - 557  : Reverse Words in a String III
    Leetcode - 1108 : Defanging an IP Address
    Leetcode - 1816 : Truncate Sentence
    Leetcode - 884  : Uncommon Words from Two Sentences
    Leetcode - 537  : Complex Number Multiplication (Example-3 above)
    Leetcode - 165  : Compare Version Numbers
    etc.
```


### :memo: std::transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op) :robot:
```c++
Applies an operation sequentially to the elements of one (1) or
two (2) ranges and stores the result in the range that begins at result.
Uage :
1) Convert all letters of a string to lower case
2) Convert all letters of a string to upper case

Example : 
    string line = "Hello world, this is MIK";

    transform(begin(line), end(line), begin(line), ::tolower);

    cout << line << endl;

    transform(begin(line), end(line), begin(line), ::toupper);

    cout << line << endl;

```

### :memo: std::regex_replace :pager:
```c++
It converts a regular expression given by user to desired expression given by user.

Example : 
    Ex-1 - Remove all vowels from a string.
    string s = "mika";
    auto rgx = regex("[aeiouAEIOU]");
    cout << regex_replace(s, rgx, "");
    
    Ex-2 - Replace all '.' to "[.]"
    string s = "1.2.3.4";
    auto rgx = regex("\\.");
    regex_replace(s, rgx, "[.]");
    
    Note : You can write smart regex for achieving amazing replacements.
    Qns on Leetcode:
    Leetcode - 1108 : Defanging an IP Address
    Leetcode - 1119 : Remove Vowels from a String
    etc.
```

### :memo: std::count_if :1234:
```c++
counts the number of elements satisfying a given condition (given by comparator function or lambda)

Example : 
    vector<int> vec{1, 3, 2, 0, 5, 0};

    auto lambda = [&](const auto& i) {
        return i == 0;
    };

    cout << count_if(begin(vec), end(vec), lambda); //output : 2
    
    Note : You can write any kind of lambda/comparator functions for matching your required condition
    Qns on Leetcode:
    Leetcode - 1773 : Count Items Matching a Rule
    etc.
```

### :memo: std::copy_if :1234:
```c++
Copies the elements to a container
how copy_if function works : in this function you have to pass four parameters 
copy_if(begin iterator , end iterator , destination , condition)
			
    eg :    vector<int> from_vec = {1,2,3,4,5,6,7,8,9,10};
            vector<int> to_vec;
            //here i want to copy all the number from from_vec vector to to_vec vector which are divisible by 2 .
            
            copy_if(from_vec.begin(), from_vec.end(), back_inserter(to_vec),[](int n){return n%2==0;});
            
            for(auto it : to_vec) 
                cout<<it<<" ";
            o/p : 2 4 6 8 10
Example : 
    Note : You can write any kind of lambda/comparator functions for matching your required condition
    Qns on Leetcode:
    Leetcode - 1796 : Second Largest Digit in a String
    etc.
```


### :memo: Writing lambda for upper_bound or lower_bound for vector<pair<int, string>> :1234:
```c++
Example-1 : 
        //Let's say you want upper_bound for a variable timestamp, take it in a pair (because it's a vector of pairs)
        pair<int, string> ref = make_pair(timestamp, "");
            
        auto lambda = [](const pair<int, string>& p1, const pair<int, string>& p2) {
            return p1.first < p2.first;
        };
        
        auto it = upper_bound(begin(my_vector), end(my_vector), ref, lambda);
	
Example-2 : 
        //Let's say you want to find the upper bound of a value in a non-increasing vector.
	vector<int> vec{1, 0, -1, -2}
	int idx = upper_bound(begin(vec), end(vec), 0, greater<int>()) - begin(vec);
	Output will be index of -1 (i.e., 2)
	
	Qns on Leetcode:
    	Leetcode - 981: Time-Based Key-Value Store
	Leetcode - 744: Find Smallest Letter Greater Than Target
	Leetcode - 1351: Count Negative Numbers in a Sorted Matrix
    
```


### :memo: Writing lambda for unordered_map to make life simple :1234:
```c++
Example : 
        //Let's say, you want to store different evaluation logic for different operators "+", "-", "*", "/"
	unordered_map<string, function<int (int, int) > > mp = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
	
	//Simply use it like below:-
	int result = mp["+"](1, 2); //This will return 1+2 i.e. 3
	
	Qns on Leetcode: 150
	Leetcode -: Evaluate Reverse Polish Notation
    
```




### :memo: std::set_difference and std::back_inserter :1234:
```c++
set_difference -> Copies the elements from the sorted s1 which are not found in the sorted s2 to a container in sorted order
back_inserter -> Can be used to add elements to the end of a container
Example : 
        set<int> st1, st2;
	vector<int> v1;
	//Find difference in between set1 and set2 and put unique element of set1 in v1
	set_difference(begin(st1), end(st1), begin(st2), end(st2), back_inserter(v1));
	
	Qns on Leetcode: 
	Leetcode 2215 : Find the Difference of Two Arrays
    
```


### :memo: std::hypot :triangular_ruler:
```c++
hypot -> Computes sqrt(x*x + y*y) (or sqrt(x*x + y*y + z*z) in C++17) safely, avoiding overflow/underflow.

Example-1 : Compute hypotenuse of right triangle
        double x = 3.0, y = 4.0;
        double result = std::hypot(x, y);
        cout << result; //5.0

Example-2 : Distance between two points (x1, y1) and (x2, y2)
        double x1 = 1, y1 = 2;
        double x2 = 4, y2 = 6;
        double dist = std::hypot(x2 - x1, y2 - y1);
        cout << dist; //5.0

Example-3 (C++17) : 3D Distance
        double x = 1, y = 2, z = 2;
        double dist3D = std::hypot(x, y, z);
        cout << dist3D; //3.0

Benefit :
        - Numerically stable (avoids overflow/underflow)
        - Cleaner than writing sqrt(x*x + y*y)
        - Works with float, double, long double

Qns on Leetcode:
        Leetcode 812 : Largest Triangly Area



```

# C\+\+ STL-Library 📚📚

In C++, the Standard Template Library (STL) provides a set of programming tools to implement algorithms and data structures like vectors, lists, queues, etc. This repository contains entire C++ STL Library which anyone require while doing Competitive Programming, Contest solving or in Online Assessment. 

---

###

#### Join us for all the latest offcampus job updates, webinar, hackathons, resume review and a lot more :heart::heart:

<div align="left">
  <a href="https://www.linkedin.com/in/amanchowdhury046/" target="_blank">
    <img src="https://img.shields.io/static/v1?message=LinkedIn&logo=linkedin&label=&color=0077B5&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="linkedin logo"  />
  </a>
  <a href="https://www.youtube.com/@amanchowdhury046" target="_blank">
    <img src="https://img.shields.io/static/v1?message=Youtube&logo=youtube&label=&color=FF0000&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="youtube logo"  />
  </a>
  <a href="https://telegram.me/offcampus_phodenge" target="_blank">
    <img src="https://img.shields.io/static/v1?message=Telegram&logo=telegram&label=&color=2CA5E0&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="telegram logo"  />
  </a>
  <a href="https://www.instagram.com/aman_chowdhury_046/" target="_blank">
    <img src="https://img.shields.io/static/v1?message=Instagram&logo=instagram&label=&color=E4405F&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="instagram logo"  />
  </a>
  <a href="https://whatsapp.com/channel/0029Va9Q0lkDZ4LYNx6ukw2u" target="_blank">
    <img src="https://img.shields.io/static/v1?message=Whatsapp&logo=Whatsapp&label=&color=25D366&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="whatsapp logo"  />
  </a>
</div>

###

---

## 🚀 Table of Contents

- [Vector In C++](#vector-in-c)
- [Stack In C++](#stack-in-c)
- [Queue In C++](#queue-in-c)
- [Deque In C++](#deque-in-c)
- [Priotity Queue In C++](#priority-queue-in-c)
- [Set In C++](#set-in-c)
- [Unordered Set In C++](#unordered-set-in-c)
- [Multiset In C++](#multiset-in-c)
- [Unordered Multiset In C++](#unordered-multiset-in-c)
- [Map In C++](#maps-in-c)
- [Unordered Map In C++](#unordered-maps-in-c)
- [MultiMap In C++](#multimaps-in-c)
- [Unordered MultiMap In C++](#unordered-multimaps-in-c)

---

<img src="/assets/images/CPPSTL.png" width="400" height="200">

---

# VECTOR IN C++

A **vector** is a dynamic array whose size can be changed automatically when an element is inserted or deleted. Vector elements are stored in contiguous memory locations so that they can be accessed in constant time.

It is defined inside the `<vector>` header file (also available in `<bits/stdc++.h>`).

The complexity (efficiency) of common operations on vectors is as follows:

- Random access - constant 𝓞(1).
- Insertion or removal of elements at the end - amortized constant 𝓞(1).
- Insertion or removal of elements in front or middle of the vector 𝓞(n).

## Ways to declare a vector

### Syntax

- `vector<int> vec;` *Empty*
- `vector<int> vec( size );` *Vector with size 'size'*
- `vector<int> vec( size, value );` *Vector with size 'size' and all elements with value 'value'*
- `vector<int> vec = { value1, value2, value3,...,valueN};` *Vector with N values*

### Examples

```cpp
vector<int> vec; // Declares an empty vector with name as vec ---> []
vector<int> vec(5); // Declares vector of ints with size 5 and the default values assigned are 0s ---> [0,0,0,0,0]
vector<int> vec(5, 10); // Declares vector of ints with size 5 and values assigned are 10s ---> [10,10,10,10,10]
vector<int> vec = {1, 2, 3, 4}; // Declares vector with size 4 and values as ---> [1, 2, 3, 4]
vector<string> vect(5) ; // Declares vector with 5 empty strings ---> ["", "", "", "", ""]
vector<string> vec(5, "Leetcode"); // Declares vector of strings with size 5 and values initialised are "Leetcode" ---> ["Leetcode", "Leetcode", "Leetcode", "Leetcode", "Leetcode"]
vector<vector<int>> vec(5);  // Declares vector of vectors ---> [[], [], [], [], []]
vector<vector<int>> vec(5, vector<int>(2)); // Declares vector of vectors(here inside vector size is 2 and default values assigned are 0's) ---> [[0,0], [0,0], [0,0], [0,0], [0,0]]
vector<vector<int>> vec(5, vector<int>(2, 10)); // Declares vector of vectors(here inside vector size is 2 and default values assigned are 10's) ---> [[10,10], [10,10],[10,10],[10,10],[10,10]]

```


## Ways to Insert Elements into Vector

### Syntax

- `vec.push_back( ele );` Adds an element 'ele' at the end, and size of the vector increases by 1 (TC - 𝓞(1))
- `vec.emplace_back( ele );` Adds an element 'ele' at the end, and size of the vector increases by 1 (TC - 𝓞(1))
- `vec.insert( vec.begin() + i, ele );` Inserting element 'ele' at index i | Use i = 0 for inserting at the front (TC - 𝓞(n))
- `vec.insert( vec.end(), vec2.begin(), vec2.end() );` Inserting the elements of vector 'v2' to the end of vector 'v' (TC - 𝓞(n))

## Ways to Delete Elements from Vector

### Syntax

- `v.pop_back();` Remove element at the end (TC - 𝓞(1))
- `v.erase( v.begin() + i );` Remove element at index i or i = 0 to remove the first element (TC - 𝓞(n))
- `v.erase( v.begin() + i, v.begin() + j );` Remove elements from index i to j-1 (TC - 𝓞(n))
- `v.erase( remove( v.begin(), v.end(), value ), v.end() );` Removes all elements with value 'value' from the vector (TC - 𝓞(n))

## Basic Inbuilt Functions

### Syntax

- `v.size();` Returns the size of vector (TC - 𝓞(1))
- `v.resize( size, val );` If the 'size' is greater than the previous size, then it adds elements with value 'val' at end and if 'size' is less than previous, then it removes from end
- `v.empty();` Returns true if the vector is empty (TC - 𝓞(1))
- `v.front();` or `v[0];` Accessing the first element (TC - 𝓞(1))
- `v.back();` or `v[v.size()-1];` Accessing the last element (TC - 𝓞(1))
- `v[i];` Accessing element at i'th index (0-based) (TC - 𝓞(1))
- `v.at(i);` Accessing element at i'th index (0-based) (TC - 𝓞(1))
- `v.clear();` Clears vector elements by making vector as empty (TC - 𝓞(n))

## Some Algorithmic Based Functions

- `sort(v.begin(), v.end());` Sorts vector elements in ascending order by default (TC - 𝓞(nlogn))
- `sort(v.begin(), v.end(), greater<int>);` Sorts vector elements in descending order (TC - 𝓞(nlogn))
- `reverse(v.begin(), v.end());` Reverses vector elements (TC - 𝓞(n))
- `count(v.begin(), v.end(), x);` Returns the count of x in vector (TC - 𝓞(n))
- `min_element(v.begin(), v.end()) - v.begin();` Returns the minimum element's index (0-based) from the vector (TC - 𝓞(n))
- `max_element(v.begin(), v.end()) - v.begin();` Returns the maximum element's index (0-based) from the vector (TC - 𝓞(n))
- `*min_element(v.begin(), v.end());` Returns the minimum element from the vector (TC - 𝓞(n))
- `*max_element(v.begin(), v.end());` Returns the maximum element from the vector (TC - 𝓞(n))

*Note: The difference between `v[i]` and `v.at(i)` is that 'at' will raise an exception if you try to access an element outside the vector while the `[]` operator won't.*



*Lets undertand by sample program*

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 2}; // Create a vector containing integers ---> [1, 3, 2]

    // Insertion
    v.push_back(5); // Adding 5 at the end ---> [1, 3, 2, 5]
    v.emplace_back(4); // Adding 4 at the end ---> [1, 3, 2, 5, 4]
    v.insert(v.begin(), 10); // Inserts 10 at the beginning ---> [10, 1, 3, 2, 5, 4]
    v.insert(v.begin() + 3, 15); // Inserts 15 at 3rd index ---> [10, 1, 3, 15, 2, 5, 4]

    // Deletion
    v.pop_back(); // Removes an element at the end ---> [10, 1, 3, 15, 2, 5]
    v.erase(v.begin()); // Removes an element at the front ---> [1, 3, 15, 2, 5]
    v.erase(v.begin() + 3); // Removes an element at 3rd index ---> [1, 3, 15, 5]

    // Accessing and Updating
    int a = v[3]; // Here the variable a stores the value at 3rd index i.e., 5
    v[1] = 100; // Here the value at index 1 is updated with 100 ---> [1, 100, 15, 5]
    int last_element = v.back(); // i.e., 5
    int first_element = v.front(); // i.e., 1

    sort(v.begin(), v.end()); // Sorts vector elements ---> [1, 5, 15, 100]
    reverse(v.begin(), v.end()); // Reverses vector elements ---> [100, 15, 5, 1]

    // Traversing the vector using a for loop
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // After the for loop, Output is: 100 15 5 1
    }
    int length = v.size(); // Here the variable length stores the vector size i.e., 4
    v.clear(); // Vector is cleared ---> []
    bool isVectorEmpty = v.empty(); // Here the variable isVectorEmpty stores 'true' as the vector is empty

    return 0;
}


```

---

# STACK IN C++

- A stack is a linear data structure that follows the principle of `Last In First Out (LIFO)`. This means the last element inserted inside the stack is removed first.
- It is defined inside `<stack>` header file (also available in `<bits/stdc++.h>`).

## Declaring a Stack

### Syntax
```cpp
stack< data_type > stack_name;
```

### Examples

- `stack<int> stk;` stack of int's
- `stack<string> stk;` stack of strings
- `stack<pair<int, int>> stk;` stack of pairs
- `stack<vector<int>> stck;` stack of vectors

*Note: Similar syntax for `char`, `long long int`, `float`, `double`, `long double`, and some other data types, including user-defined data types.*

## Important Functions on Stack

- `stk.push(ele);` pushes an element 'ele' into the stack      TC - 𝓞(1)
- `stk.pop();` removes the top element      TC - 𝓞(1)
- `stk.top();` returns the topmost element      TC - 𝓞(1)
- `stk.size();` returns the size of stack      TC - 𝓞(1)
- `stk.empty();` returns true if the stack is empty else false      TC - 𝓞(1)

*Note: The time complexity of all above inbuilt functions is constant - 𝓞(1)*

## Accessing Stack Elements

Since it won't provide indexing, *we cannot directly access any element except the top element.* The below is the way to traverse the stack.
```cpp
while(!stk.empty()){
    cout << stk.top() << " ";
    stk.pop();
}
```

*Lets understand by sample program*

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<string> stk;
	
	//pushing data into the stack
	stk.push("Hi");
	stk.push("Hello");
	stk.push("How are you?");
	
	//poping data from top of the stack
	stk.pop(); // the top element i.e "How are you?" is removed;
	
	cout << stk.top() << " "; // prints top element "Hello"
	cout << stk.size() << " "; // prints 2
	cout << stk.empty(); //prints false | 0
	
	return 0;
}
```

---

# QUEUE IN C++

- A queue is a linear data structure that follows the `FIFO (First In First Out)` principle, i.e., elements that are added first will be removed first.
- It is defined inside `<queue>` header file (also available in `<bits/stdc++.h>`).


## Declaring a Queue

### Syntax
```cpp
queue< data_type > queue_name;
```

### Examples

- `queue<int> q;` queue of int's
- `queue<string> q;` queue of strings
- `queue<pair<int, int>> q;` queue of pairs
- `queue<vector<int>> q;` queue of vectors

*Note: Similar syntax for `char`, `long long int`, `float`, `double`, `long double`, and some other data types, including user-defined data types.*

## Important Functions on Queue

- `q.push(ele);` pushes an element 'ele' into the queue from the end      TC - 𝓞(1)
- `q.pop();` removes an element from the front of the queue      TC - 𝓞(1)
- `q.front();` returns the first element      TC - 𝓞(1)
- `q.back();` returns the last element      TC - 𝓞(1)
- `q.size();` returns the size of the queue      TC - 𝓞(1)
- `q.empty();` returns true if the queue is empty else false      TC - 𝓞(1)

*Note: The time complexity of all above inbuilt functions is constant - 𝓞(1)*

## Accessing Queue Elements

Since it won't provide indexing, we cannot directly access any element except the first and last element. The below is the way to traverse the queue.

```cpp
while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}
```

*Let's understand with a sample program*

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    queue<string> q;
    
    // Pushing data into the queue
    q.push("Hi");
    q.push("Hello");
    q.push("How are you?");
    
    // Popping data from the top of the queue
    q.pop(); // The front element, i.e., "Hi", is removed;
    
    cout << q.front() << " "; // Prints the front element, "Hello"
    cout << q.back() << " "; // Prints the back element, "How are you?"
    cout << q.size() << " "; // Prints 2
    cout << q.empty(); // Prints false | 0
    
    return 0;
}
```

---

# DEQUE IN C++

Deque is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end.

The complexity (efficiency) of common operations on deques is as follows:
- Random access - constant 𝓞(1)
- Insertion or removal of elements at the end or beginning - constant 𝓞(1)
- Insertion or removal of elements - linear 𝓞(n)

Formally, a deque supports all the functions that a vector supports. The difference between a deque and a vector is that deques do not guarantee that their elements are contiguous in memory, so accessing may not be as efficient.

## Ways to Declare a Deque

### Syntax
```cpp
deque< data_type > deque_name;
```

### Examples
- `deque<int> dq;` Deque of int (Empty) 
- `deque<int> dq( size );`  Deque with size 'size' 
- `deque<int> dq( size, value );`  Deque with size 'size' and all elements with value 'value' 
- `deque<int> dq = { value1, value2, value3,...,valueN};` Deque with N values 


*Note: Similar syntax for `char`, `long long int`, `float`, `double`, `long double`, and some other data types, including user-defined data types.*

## Important Functions

- `dq.push_back( ele );` Adds an element 'ele' at the end (TC - 𝓞(1))
- `dq.pop_back();` Removes an element at the end (TC - 𝓞(1))
- `dq.push_front( ele );` Adds an element 'ele' at the front (TC - 𝓞(1))
- `dq.pop_front();` Removes an element at the front (TC - 𝓞(1))
- `dq.size();` Returns the size of the deque (TC - 𝓞(1))
- `dq.empty();` Returns true if the deque is empty, else false (TC - 𝓞(1))
- `dq.front();` or `dq[0];` Accesses the first element (TC - 𝓞(1))
- `dq.back();` or `dq[dq.size()-1];` Accesses the last element (TC - 𝓞(1))
- `dq[i];` Accesses the element at the i'th index (0-based) (TC - 𝓞(1))
- `dq.at(i);` Accesses the element at the i'th index (0-based) (TC - 𝓞(1))


---

# PRIORITY QUEUE IN C++

- A priority queue is a special type of queue in which each element is associated with a priority value, and elements are served based on their priority.
- It is defined inside the `<queue>` header file (also available in `<bits/stdc++.h>`).
- By default, C++ creates a max priority queue. We can change it to a min priority queue by passing additional parameters during declaration.


## Syntax

### Max - Priority Queue
```cpp
priority_queue< data_type > priority_queue_name;
```

### Max - Priority Queue
```cpp
priority_queue< data_type, vector< data_type >, greater< data_type > > priority_queue_name;
```

## Examples

### Max Priority Queue
```cpp
priority_queue<int> q; // max priority_queue of int's
priority_queue<string> q; // max priority_queue of strings
priority_queue<pair<int, int>> q; // max priority_queue of pairs
priority_queue<vector<int>> q; // max priority_queue of vectors
```

### Min Priority Queue
```cpp
priority_queue<int, vector<int>, greater<int>> q; // min priority_queue of int's
priority_queue<string, vector<string>, greater<string>> q; // min priority_queue of strings
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // min priority_queue of pairs
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q; // min priority_queue of vectors
```

*Note: Similar syntax for `char`, `long long int`, `float`, `double`, `long double`, and some other data types, including user-defined data types.*

## Important functions on priority_queue

- `pq.push(ele);` Inserts the element 'ele' into the priority queue. [Time Complexity: 𝓞(logn)]
- `pq.pop();` Removes the element with the highest priority. [Time Complexity: 𝓞(logn)]
- `pq.top();` Returns the element with the highest priority. [Time Complexity: 𝓞(1)]
- `pq.size();` Returns the size of the priority_queue. [Time Complexity: 𝓞(1)]
- `pq.empty();` Returns true if the priority_queue is empty, else false. [Time Complexity: 𝓞(1)]

## Accessing priority_queue elements

Since it won't provide indexing, we cannot directly access any element except the top element. The below is the way to traverse the priority_queue.

```cpp
while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

*Lets understand by sample program*

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;

    // Pushing data into the priority_queue
    pq.push(6);
    pq.push(10);
    pq.push(0);
    pq.push(-40);
    pq.push(8);
    pq.push(-20);
    pq.push(3);

    cout << pq.top() << " "; // Prints the top element, i.e., 10

    // Popping data from the top of the queue
    pq.pop(); // The top element, i.e., 10, is removed;

    cout << pq.top() << " "; // Prints the current top element, i.e., 8
    cout << pq.size() << " "; // Prints 6
    cout << pq.empty(); // Prints false | 0

    return 0;
}
```

---

# SET IN C++

- A set data structure `won't allow duplicate keys`.
- Keys are sorted in ascending order by default. We can also change the order by passing extra arguments during its declaration.
- Implemented using `Binary search tree` (Red-Black trees).

## Declaring set

### Syntax
```cpp
set< data_type > st; stores keys in ascending order
set< data_type, greater< data_type > > st; stores keys in descending order
```

### Examples

- `set<int> st;` set of int's
- `set<string> st;` set of strings
- `set<pair<int, int>> st;` set of pairs
- `set<vector<int>> st;` set of vectors


*Note: Similar syntax for `char`, `long long int`, `float`, `double`, `long double`, and some other data types, including user-defined data types.*

## Important functions on set

- `st.insert( key );` Inserts the element into the set (if not present). TC - 𝓞(logn)
- `st.erase( key );` Removes the specified key if present. TC - 𝓞(logn)
- `st.find( key );` Returns an iterator pointing to the key; if the key is not present, returns st.end(). TC - 𝓞(logn)
- `st.size();` Returns the size of the set. TC - 𝓞(1)
- `st.empty();` Returns true if the set is empty, else false. TC - 𝓞(1)
- `st.clear();` Removes all set elements. TC - 𝓞(n)

## Accessing set elements

Since it won't provide indexing, we cannot directly access any element. The below is the way to traverse the set.

```cpp
for (auto x : st) {
    cout << x << " ";  // Prints each key in ascending order
}
```

*Lets understand by sample program*

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> st;

    // Inserting data into the set
    st.insert(1);    // Inserts 1 into the set
    st.insert(1);    // Since 1 is already present, it won't insert 1 again into the set
    st.insert(5);    // Inserts 5 into the set
    st.insert(10);   // Inserts 10 into the set
    st.insert(15);   // Inserts 15 into the set
    st.insert(5);     // Since 5 is already present, it won't insert 5 again into the set

    if (st.find(100) != st.end()) {
        cout << "Key is present ";
    } else {
        cout << "Key is not present "; // Prints "Key is not present"
    }

    if (st.find(1) != st.end()) {
        cout << "Key is present "; // Prints "Key is present" since 1 is present in the set
    } else {
        cout << "Key is not present ";
    }

    st.erase(1); // Removes 1 from the set

    cout << st.size() << " "; // Prints 3
    cout << st.empty(); // Prints false | 0
    st.clear(); // Removes all elements.

    return 0;
}
```

---

# Unordered Set in C++

- An `uno
