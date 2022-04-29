#include <iostream>
namespace printers
{
    template <typename T>
    void print(const T &t)
    {
        std::cout << t << std::endl;
    }
}