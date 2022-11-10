#pragma once

#include "prime_factors_of_a_number.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <functional>

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
