/*
Given two numbers, write an efficient function to find their greates common divisor.

Example:

Given numbers =  60 27
Output should be = 

Given numbe = 6 9
Output should be = 3

*/

#include "prime_factors_of_a_number.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "timer.h"

#include <algorithm>
#include <cassert>
#include <numeric>

struct PrimeFactor
{
    unsigned int base;
    unsigned int exponent;
};

std::vector<unsigned int> UniqueSorted(std::vector<unsigned int>&& fac)
{
    std::sort(fac.begin(), fac.end());
    auto last = std::unique(fac.begin(), fac.end());
    fac.erase(last, fac.end());
    return fac;
}

std::vector<unsigned int> Sorted(std::vector<unsigned int>&& fac)
{
    std::sort(fac.begin(), fac.end());
    return fac;
}

unsigned int GcdPrimeFactors(unsigned int num_a, unsigned int num_b)
{
    auto fac_a = Sorted(PrimeFactors(num_a));
    auto fac_b = Sorted(PrimeFactors(num_b));

    std::vector<unsigned int> common;
    std::set_intersection(fac_a.begin(), fac_a.end(),
                          fac_b.begin(), fac_b.end(),
                          std::back_inserter(common));

    return std::accumulate(common.begin(), common.end(), 1, std::multiplies<unsigned int>());
}


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