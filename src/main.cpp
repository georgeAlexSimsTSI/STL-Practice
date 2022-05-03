
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <sstream>
#include <limits>
#include "test.cpp"
using std::cout;
using std::endl;

bool isBalanced(const std::string &s)
{
    int n = s.length();
    std::stack<char> st;
    for (int i = 0; i < n; ++i)
    {
        char c = s.at(i);
        if (st.empty())
            st.push(c);
        else if (st.top() == '(' && c == ')' || st.top() == '{' && c == '}' || st.top() == '[' && c == ']')
            st.pop();
        else
            st.push(c);
    }
    return st.size() == 0;
}

template <typename T>
std::vector<std::pair<T, int>> topKFrequent(std::vector<T> &a)
{
    std::unordered_map<T, int> u;
    int n = a.size(), i = 0;
    for (; i < n; ++i) // count occurrence of each value
        u[a[i]]++;
    std::vector<std::pair<T, int>> v(u.begin(), u.end());
    sort(v.begin(), v.end(), [](std::pair<T, int> x, std::pair<T, int> y)
         {
        if(x.second == y.second)
            return x.first < y.first;
        return x.second > y.second; });

    return v;
}

namespace printers
{
    template <typename T, typename Y>
    void printValues(const std::vector<std::pair<T, Y>> &t)
    {
        for (auto it = t.begin(); it != t.end(); ++it)
        {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    }

    template <typename T>
    void printValues(std::stack<T> s)
    {
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    template <typename T>
    void printValues(std::priority_queue<T> s)
    {
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }

    template <typename T>
    void printValues(std::priority_queue<T, std::vector<T>, std::greater<T>> s)
    {
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }

    template <typename T>
    void printValues(const T &t)
    {
        for (auto it = t.begin(); it != t.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

namespace userInput
{
    template <typename T>
    void validateInput(T &val, const std::string &prompt)
    {
        while (true)
        {
            std::cout << prompt;
            if (std::cin >> val)
                break;
            std::cout << "Invalid Input, Enter a Valid Input" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

struct employee
{
    int empID;
    char name[50];
    float salary;
    char department[50];
};

// find the index of the minimum value in a rotated sorted array
inline int findMin(const std::vector<int> &m)
{
    int i = 0, n = m.size();
    for (; i < n; ++i)
    {
        if (i == 0)
        {
            if ((m[0] < m[n - 1] && m[0] < m[1])) // if the first value && the first value is smaller than the last value and smaller than the next then it is sorted
                break;
        }
        else
        {
            if (m[i] < m[i - 1] && m[i] < m[(i + 1) % n]) // if current is smaller than previous value and smaller than the next value
                break;
        }
    }
    return i % n; // the % n is to keep it in the valid range
};

template <typename T>
bool pairCmp(std::pair<T, T> x, std::pair<T, T> y) // different sorting condition for pairs
{
    if (x.first != y.first)
        return x.first < y.first; // return the one with smaller first element
    else
        return x.second < y.second; // if first element is equal then return the one with smaller second element
}

namespace customException
{
    class MyException : public std::exception
    {
        int x;
        std::string str;

    public:
        explicit MyException(const int &x) : x(x), str("") {}
        explicit MyException(const std::string &str) : x(0),str(str){}
        const char *what()
        {
            return "Custom Exception";
        }

        std::string getStr() { return str; }
        int getX() { return x; }
    };
}

int main()
{
    // Struct
    struct employee emp[3] = {{1, "Harry", 20000, "Finance"}, {2, "Sally", 50000, "HR"}, {3, "John", 15000, "Technical"}};
    cout << "Employee information is given as follows:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Employee ID: " << emp[i].empID << endl;
        cout << "Name: " << emp[i].name << endl;
        cout << "Salary: " << emp[i].salary << endl;
        cout << "Department: " << emp[i].department << endl;
        cout << endl;
    }

    // Vectors
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    cout << "Vector 1 elements are: " << endl;
    printers::printValues(v);
    v = std::vector<int>{1, 2, 3, 4, 5};
    cout << "Vector 2 elements are: " << endl;
    printers::printValues(v);
    v = std::vector<int>(6, 10); // 6 elements all with the value of 10
    cout << "Vector 3 elements are: " << endl;
    printers::printValues(v);
    int a[] = {11, 22, 33};
    int n = sizeof(a) / sizeof(int);
    v = std::vector<int>(a, a + n);
    cout << "Vector 4 elements are: " << endl;
    printers::printValues(v);

    // Find the minimum element in a Rotated Sorted Vector

    // e.g. 4,5,6,7,0,1,2 is a rotated version of 0,1,2,3,4,5,6,7
    v = std::vector<int>{4, 5, 6, 7, 1, 3, 2};
    cout << "Vector 5 elements are: " << endl;
    printers::printValues(v);
    int index = findMin(v);
    cout << "The Minimum element is found at index: " << index << " Value is: " << v[index] << endl;

    // Lower Bound
    // Method returns to an iterator pointing to the first element which has a value not less than the given values, In other words the first value greater than or equal to

    v = std::vector<int>{10, 12, 35, 65, 21, 90};
    cout << "Vector 6 elements are: " << endl;
    printers::printValues(v);
    cout << endl;
    std::vector<int>::iterator low;
    low = std::lower_bound(v.begin(), v.end(), 35);
    cout << "The index (starting from 0) of the lower_bound of 35 is: " << (low - v.begin()) << endl;

    // Upper Bound, returns the index of the first value to have a value greater than the provided one
    cout << endl;
    std::vector<int>::iterator high;
    sort(v.begin(), v.end());
    cout << "Vector 7 elements are: " << endl;
    printers::printValues(v);
    high = std::upper_bound(v.begin(), v.end(), 35);
    cout << "The index (starting from 0) of the upper_bound of 35 is: " << (high - v.begin()) << endl; // by definition excludes the value itself

    // List
    std::list<int> l1, l2;
    for (int i = 1; i <= 5; ++i)
    {
        l1.push_back(i * 10);
        l2.push_front(i * 20);
    }
    cout << "List values pushed back: ";
    printers::printValues(l1);
    cout << "List values pushed front: ";
    printers::printValues(l2);
    cout << "List 1 after being reversed is: ";
    l1.reverse();
    printers::printValues(l1);
    cout << "List 2 after being sorted is: ";
    l2.sort();
    printers::printValues(l2);

    // Pair, I want to skip this
    std::vector<std::pair<int, int>> v2;
    v2.push_back(std::make_pair(8, 64));
    v2.push_back(std::make_pair(1, 1));
    v2.push_back(std::make_pair(3, 6));
    v2.push_back(std::make_pair(2, 4));
    v2.push_back(std::make_pair(5, 25));
    printers::printValues(v2);
    cout << "Sorting the elements by the first value in ascending order: ";
    sort(v2.begin(), v2.end());
    printers::printValues(v2);
    v2.clear();
    v2.push_back(std::make_pair(1, 5));
    v2.push_back(std::make_pair(1, 3));
    v2.push_back(std::make_pair(2, 6));
    v2.push_back(std::make_pair(2, 4));
    v2.push_back(std::make_pair(5, 24));
    cout << "Sorting the elements by the first value in ascending order: ";
    sort(v2.begin(), v2.end(), pairCmp<int>); // providing my own sorting condition to take the second value into consideration
    printers::printValues(v2);

    // Find the Top K most frequent Elements

    v = std::vector<int>{1, 2, 3, 1, 2, 1};
    printers::printValues(v);
    v2 = topKFrequent(v);
    printers::printValues(v2);

    for (auto i : v2)
    {
        cout << i.first << " occurred " << i.second << " times, ";
    }

    // Stack
    std::stack<int> s;
    for (int i = 1; i <= 5; ++i)
    {
        s.push(i * 10);
    }
    cout << endl
         << "The top element of the stack is: " << s.top() << " The size of this stack is: " << s.size() << endl;
    cout << "The stack in LIFO order is: ";
    printers::printValues(s);

    // Balanced Bracket String using a stack
    cout << "The String {{[[(())]]}} is balanced? " << isBalanced("{{[[(())]]}}") << endl;
    cout << "The String {[(])} is balanced? " << isBalanced("{[(])}") << endl;

    // Priority Queue
    std::priority_queue<int> q; // This is a max Heap
    for (int i = 1; i <= 5; ++i)
        q.push(i * 10);
    q.push(1);
    cout << "Priority Queue Order is: ";
    printers::printValues(q);
    cout << endl;
    // Using a Priority Queue we can make a Min Heap

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int i = 0; i <= 5; ++i)
        minHeap.push(i * 20);
    cout << "Min Heap Values are: ";
    printers::printValues(minHeap);
    cout << endl;

    // Sets
    std::set<int> setS;
    setS.insert(5);
    setS.insert(39);
    setS.insert(64);
    setS.insert(82);
    setS.insert(35);
    setS.insert(54);
    setS.insert(5);
    cout << "The Set values are: ";
    printers::printValues<std::set<int>>(setS);

    // We can specify the storage order via
    std::set<int, std::greater<int>> setS2;
    setS2.insert(5);
    setS2.insert(39);
    setS2.insert(64);
    setS2.insert(82);
    setS2.insert(35);
    setS2.insert(54);
    setS2.insert(5);
    cout << "The Set values are: ";
    printers::printValues(setS2);

    cout << "Erasing element 5 from the set: ";
    setS.erase(5);
    printers::printValues(setS);
    if (setS.find(5) == setS.end())
        cout << "Element 5 is not in the set " << endl;

    // MultiSet, a Set that allows Duplicates
    std::multiset<int> multiSet;
    multiSet.insert(5);
    multiSet.insert(39);
    multiSet.insert(64);
    multiSet.insert(82);
    multiSet.insert(35);
    multiSet.insert(54);
    multiSet.insert(5);
    cout << "The multiset elements are: ";
    printers::printValues(multiSet);
    multiSet.erase(5);
    cout << "MultiSet Erase 5: ";
    printers::printValues(multiSet);
    multiSet.erase(multiSet.begin(), multiSet.find(54));
    cout << "MultiSet Erase all elements less than 54: ";
    printers::printValues(multiSet);

    // Skipping map, refer back to oop project for example

    // Sorting Strings by writing a Custom Sort Method, same thing as one of the previous methods where you provide a boolean function as the conditional comparasion

    std::unordered_set<std::string> stringSet;
    stringSet.insert("Study");
    stringSet.insert("Tonight");
    stringSet.insert("Amity");
    stringSet.insert("Abolisher");
    stringSet.insert("C++");
    stringSet.insert("Hi");
    cout << "Elements before sort: ";
    printers::printValues(stringSet);

    std::vector<std::string> stringVector(stringSet.begin(), stringSet.end()); // initialize using set
    cout << "Unsorted Vector: ";
    printers::printValues(stringVector);
    sort(stringVector.begin(), stringVector.end(), [](const std::string &x, const std::string &y) // Lambda Sort method
         { return x.size() > y.size(); });
    cout << "Sorted Vector: ";
    printers::printValues(stringVector);

    std::string message;
    userInput::validateInput(message, "Enter a message: ");
    printers::print(message);

    try
    {
        throw customException::MyException("Hello There");
    }
    catch (customException::MyException &e)
    {
        cout << e.what() << endl;
        cout << e.getStr() << endl;
        cout << e.getX() << endl;
    }

    try
    {
        throw customException::MyException(7);
    }
    catch (customException::MyException &e)
    {
        cout << e.what() << endl;
        cout << e.getStr() << endl;
        cout << e.getX() << endl;
    }
}