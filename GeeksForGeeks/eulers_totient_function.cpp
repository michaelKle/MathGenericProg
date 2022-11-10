/*
    Euler’s Totient function Φ (n) for an input n is the count of numbers in {1, 2, 3, …, n-1}
    that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.
*/

#include "eulers_totient_function.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("Calculate eulers totient")
{
    CHECK(eulers_totient(1) == 1); // gcd(1, 1) is 1
    CHECK(eulers_totient(2) == 1); // gcd(1, 2) is 1, but gcd(2, 2) is 2
    CHECK(eulers_totient(3) == 2); // gcd(1, 3) is 1, gcd(2, 3) is 1,  gcd(3, 3) is 3
    CHECK(eulers_totient(4) == 2); // gcd(1, 4) is 1, gcd(2, 4) is 2,  gcd(3, 4) is 1, gcd(4, 4) is 4
    CHECK(eulers_totient(5) == 4); // gcd(1, 5) is 1, gcd(2, 5) is 1,  gcd(3, 5) is 1, gcd(4, 5) is 1, gcd(5, 5) is 5
    CHECK(eulers_totient(6) == 2);

    // p=11 q=23
    // expect: phi(11*23) = (p-1)(q-1) = 10*22 = 220
    CHECK(eulers_totient(253) == 220);

}