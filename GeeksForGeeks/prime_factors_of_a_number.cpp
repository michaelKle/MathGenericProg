/*
Given a number n, write an efficient function to print all prime factors of n.

Example:

Given number =  12
Output should be = 2 2 3

Given numbe = 315
Output should be = 3 3 5 7

*/

#include "timer.h"
#include "prime_number.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_map>



std::vector<unsigned int>
PrimeFactors(unsigned int num)
{
    std::vector<unsigned int> ret;

    unsigned int fac = 2;
    while (num > 1)
    {
        if (num % fac == 0)
        {
            ret.push_back(fac);
            num = num / fac;
            fac = 2;
        }
        else
        {
            fac = NextPrime(fac);
        }
        
    }

    return ret;
}

int main(int, char* [])
{
    
    {
        Timer t;
        
        auto factors = PrimeFactors(12);
        auto factors_expect = std::vector<unsigned int>{2, 2, 3};
        assert(factors == factors_expect);
    }

    {
        Timer t;
        
        auto factors = PrimeFactors(315);
        auto factors_expect = std::vector<unsigned int>{3, 3, 5, 7};
        assert(factors == factors_expect);
    }
    
    return 0;
}
