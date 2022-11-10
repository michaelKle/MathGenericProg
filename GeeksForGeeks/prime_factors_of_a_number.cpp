/*
Given a number n, write an efficient function to print all prime factors of n.

Example:

Given number =  12
Output should be = 2 2 3

Given numbe = 315
Output should be = 3 3 5 7

*/

#include "timer.h"
#include "prime_factors_of_a_number.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_map>

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
