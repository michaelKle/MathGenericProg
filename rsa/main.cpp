#include "prime_number.h"

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "RSA - Public / Private key implementation\n";

    std::cout << "1) Choose two large primes\n";

    unsigned int startA = 10;
    unsigned int startB = 20;

    auto p = NextPrime(startA);
    auto q = NextPrime(startB);
    std::cout << "\t p=" << p << " q=" << q << "\n";

    std::cout << "2) Moduls n = p x q\n";
    auto n = p * q;
    std::cout << "\t n=" << n << "\n";

    std::cout << "3) Calculate Eulers totient phi(n) = (p-1)(q-1) with p and q prime\n";


    return 0;
}