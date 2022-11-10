/*
Given two numbers, write an efficient function to find their greates common divisor.

Example:

Given numbers =  60 27
Output should be = 

Given numbe = 6 9
Output should be = 3

*/

#include "greatest_common_divisor.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "timer.h"





TEST_CASE("greatest common divisor")
{
    {
        Timer t;
        CHECK(36 == GcdPrimeFactors(360u, 756u));
    }
    {
        Timer t;
        std::vector<unsigned int> given{1, 2, 1, 1, 3, 3, 3, 4, 5, 4};
        auto expect = std::vector<unsigned int>{1, 2, 3, 4, 5};
        CHECK(expect == UniqueSorted(std::move(given)));
    }

    {
        Timer t;
        CHECK(3 == GcdPrimeFactors(6u, 9u));
    }
    
}