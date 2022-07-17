// PlanitChallenge1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

void setFibonacciSequence(std::vector<long long int>& v, int n)
{
    long long int prev1, prev2;
    //set the first 3 values to start off fibonacci sequence, unless n < 3 then just set appropriately
    for (int x = 0; x < n; x++)
    {
        if (x < 3)
        {
            if (x == 0)
                v.push_back(0);
            else
                v.push_back(1);
        }
    }

    for (int i = v.size(); i < n; i++)
    {
        prev1 = v.at(v.size() - 2);
        prev2 = v.at(v.size() - 1);

        v.push_back(prev1 + prev2);
    }
}

void getFibonacciSequence(std::vector<long long int> v, int n)
{
    if (n <= v.size())
        std::cout << "F(n) = " << v.at(n - 1) << std::endl;
    else
        std::cout << n << " not found!" << std::endl;
}

void isFibonacci(std::vector<long long int> v, int f)
{
    auto it = std::find(v.begin(), v.end(), f);
    if (it != v.end())
    {
        std::cout << "It is a fibonacci number found in index: " << std::distance(v.begin(), it);
    }
    else
    {
        std::cout << "It is NOT a fibonacci number. The closest index is: ";

        auto lower = std::lower_bound(v.begin(), v.end(), f);
        if (lower == v.end())
            std::cout << std::distance(v.begin(), lower) - 1 << std::endl;
        else
            std::cout << std::distance(v.begin(), lower) << std::endl;
    }
}

void printFibonacciSequence(std::vector<long long int> v)
{
    std::cout << "fibonacci sequence: {";
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i != 0)
            std::cout << ",";

        std::cout << v.at(i);
    }
    std::cout << "}" << std::endl;
}

int main()
{
    int n, f;                                   //at least 64 bits
    std::vector<long long int> v;

    std::cout << "Input number of fibonacci values: ";
    std::cin >> n;

    setFibonacciSequence(v, n);                 //set fibonacci sequence

    printFibonacciSequence(v);                  //print fibonacci sequence

    std::cout << "Input nth element (n): ";
    std::cin >> n;

    getFibonacciSequence(v, n);                 //get the value of n

    std::cout << "Check if fibonacci (F): ";
    std::cin >> f;

    isFibonacci(v, f);                          //get fibonacci index
}

