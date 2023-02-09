#include "bignum/bignum.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"


#include "timer.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <unordered_map>

TEST_CASE("Parse 0")
{
    CHECK(BigNum<2>("0").to_string() == "0");
}

TEST_CASE("Parse 1")
{
    CHECK(BigNum<2>("1").to_string() == "1");
}

TEST_CASE("Parse f")
{
    CHECK(BigNum<2>("F").to_string() == "F");
}

TEST_CASE("Parse 10")
{
    CHECK(BigNum<2>("10").to_string() == "10");
}

TEST_CASE("Parse ff")
{
    CHECK(BigNum<2>("ff").to_string() == "FF");
    CHECK(BigNum<2>("ff").get_rep() == std::array<uint8_t,2>{0xFF, 0x00});
}

TEST_CASE("Parse skips whitespace 12 34")
{
    CHECK(BigNum<2>("12 34").to_string() == "1234");
    CHECK(BigNum<2>("12 34").get_rep() == std::array<uint8_t,2>{0x34, 0x12});
}

TEST_CASE("Parse 1111 2222 3333 44444")
{
    CHECK(BigNum<8>("1111 2222 3333 4444").to_string() == "1111 2222 3333 4444");
    CHECK(BigNum<8>("1111 2222 3333 4444").get_rep() == std::array<uint8_t,8>{0x44, 0x44, 0x33, 0x33, 0x22, 0x22, 0x11, 0x11});
}
