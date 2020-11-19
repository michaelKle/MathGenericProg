#include "prime_number.h"

#include "timer.h"

#include <cassert>


int main(int, char* [])
{
    
    {
        Timer t;
        assert(IsPrime(1) == false);
        assert(IsPrime(2));
        assert(IsPrime(3));
        assert(IsPrime(4) == false);
        assert(IsPrime(5));
        assert(IsPrime(6) == false);
        assert(IsPrime(7));
    }

    {
        Timer t;
        assert(NextPrime(1) == 2);
        assert(NextPrime(2) == 3);
        assert(NextPrime(3) == 5);
        assert(NextPrime(4) == 5);
        assert(NextPrime(5) == 7);
        assert(NextPrime(7) == 11);
        assert(NextPrime(8) == 11);
    }
    
    return 0;
}
