#pragma once

#include "greatest_common_divisor.h"

unsigned int eulers_totient(unsigned int n)
{
    unsigned int count = 0;
    for (auto i = n; i > 0; --i)
    {
        if (GcdPrimeFactors(n, i) == 1)
            ++count;
    }
    return count;
}