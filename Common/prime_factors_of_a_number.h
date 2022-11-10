#pragma once

#include "prime_number.h"

#include <vector>


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
