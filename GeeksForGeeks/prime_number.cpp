#include "prime_number.h"


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"


#include "timer.h"

#include <cassert>


TEST_CASE("is prime")
{
    {
        Timer t;
        CHECK(IsPrime(1) == false);
        CHECK(IsPrime(2));
        CHECK(IsPrime(3));
        CHECK(IsPrime(4) == false);
        CHECK(IsPrime(5));
        CHECK(IsPrime(6) == false);
        CHECK(IsPrime(7));
    }

    {
        Timer t;
        CHECK(NextPrime(1) == 2);
        CHECK(NextPrime(2) == 3);
        CHECK(NextPrime(3) == 5);
        CHECK(NextPrime(4) == 5);
        CHECK(NextPrime(5) == 7);
        CHECK(NextPrime(7) == 11);
        CHECK(NextPrime(8) == 11);
    }

}
