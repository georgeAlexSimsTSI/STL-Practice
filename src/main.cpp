
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <stack>
using std::cout;
using std::endl;

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

template <typename T>
void printValues(T &t)
{
    for (auto it = t.begin(); it < t.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename T>
void printValues(std::list<T> &t)
{
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename T, typename Y>
void printValues(std::vector<std::pair<T, Y>> &t)
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
    printValues(v);
    v = std::vector<int>{1, 2, 3, 4, 5};
    cout << "Vector 2 elements are: " << endl;
    printValues(v);
    v = std::vector<int>(6, 10); // 6 elements all with the value of 10
    cout << "Vector 3 elements are: " << endl;
    printValues(v);
    int a[] = {11, 22, 33};
    int n = sizeof(a) / sizeof(int);
    v = std::vector<int>(a, a + n);
    cout << "Vector 4 elements are: " << endl;
    printValues(v);

    // Find the minimum element in a Rotated Sorted Vector

    // e.g. 4,5,6,7,0,1,2 is a rotated version of 0,1,2,3,4,5,6,7
    v = std::vector<int>{4, 5, 6, 7, 1, 3, 2};
    cout << "Vector 5 elements are: " << endl;
    printValues(v);
    int index = findMin(v);
    cout << "The Minimum element is found at index: " << index << " Value is: " << v[index] << endl;

    // Lower Bound
    // Method returns to an iterator pointing to the first element which has a value not less than the given values, In other words the first value greater than or equal to

    v = std::vector<int>{10, 12, 35, 65, 21, 90};
    cout << "Vector 6 elements are: " << endl;
    printValues(v);
    cout << endl;
    std::vector<int>::iterator low;
    low = std::lower_bound(v.begin(), v.end(), 35);
    cout << "The index (starting from 0) of the lower_bound of 35 is: " << (low - v.begin()) << endl;

    // Upper Bound, returns the index of the first value to have a value greater than the provided one
    cout << endl;
    std::vector<int>::iterator high;
    sort(v.begin(), v.end());
    cout << "Vector 7 elements are: " << endl;
    printValues(v);
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
    printValues(l1);
    cout << "List values pushed front: ";
    printValues(l2);
    cout << "List 1 after being reversed is: ";
    l1.reverse();
    printValues(l1);
    cout << "List 2 after being sorted is: ";
    l2.sort();
    printValues(l2);

    // Pair, I want to skip this
    std::vector<std::pair<int, int>> v2;
    v2.push_back(std::make_pair(8, 64));
    v2.push_back(std::make_pair(1, 1));
    v2.push_back(std::make_pair(3, 6));
    v2.push_back(std::make_pair(2, 4));
    v2.push_back(std::make_pair(5, 25));
    printValues(v2);
    cout << "Sorting the elements by the first value in ascending order: ";
    sort(v2.begin(), v2.end());
    printValues(v2);
    v2.clear();
    v2.push_back(std::make_pair(1, 5));
    v2.push_back(std::make_pair(1, 3));
    v2.push_back(std::make_pair(2, 6));
    v2.push_back(std::make_pair(2, 4));
    v2.push_back(std::make_pair(5, 24));
    cout << "Sorting the elements by the first value in ascending order: ";
    sort(v2.begin(), v2.end(), pairCmp<int>); // providing my own sorting condition to take the second value into consideration
    printValues(v2);

    // Find the Top K most frequent Elements

    v = std::vector<int>{1, 2, 3, 1, 2, 1};
    printValues(v);
    v2 = topKFrequent(v);
    printValues(v2);

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
    printValues(s);
}