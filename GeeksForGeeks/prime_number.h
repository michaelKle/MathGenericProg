#pragma once

bool IsPrime(unsigned int num)
{
    if (num == 1)
        return false;
        
    for (unsigned int fac = 2; fac <= num/2; ++fac)
    {
        if (num % fac == 0)
            return false;
    }

    return true;
}

unsigned int NextPrime(unsigned int num)
{
    for (++num;;++num)
    {
        if (IsPrime(num))
        {
            return num;
        }
    }
}