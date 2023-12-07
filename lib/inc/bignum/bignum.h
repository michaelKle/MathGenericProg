#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>

// number of bytes represented
// i.e. for a 64 bit number this would be 8
template<size_t NumberSize>
class BigNum
{
public:
  // assume s holds a string of a hexadecimal number
  explicit BigNum(std::string_view s)
  {
    if (s.empty())
      return;

    size_t spaces = std::count(s.begin(), s.end(), ' ');
    size_t skipped = 0;
    for (int idx = 0; idx < s.size(); ++idx) {
      char c = s[idx];
      uint8_t nibble{};
      if (c == ' ') {
        skipped++;
        continue;
      }

      if (c >= '0' && c <= '9')
        nibble = c - '0';
      else if (c >= 'a' && c <= 'f')
        nibble = c - 'a' + 10;
      else if (c >= 'A' && c <= 'F')
        nibble = c - 'A' + 10;
      set_exponent(nibble, s.size() - idx - 1 - spaces + skipped);
    }
  }
  BigNum() {}

  // i.e. to set a000 means Set(5, 3) i.e. a * 10^3 (the 10 is in hexadecima
  // base)
  void set_exponent(uint8_t val, size_t hex_exponent)
  {
    auto offset = hex_exponent / 2;
    auto shift = (hex_exponent % 2) * 4;
    m_rep[offset] += val << shift;
  }

  char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                   '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

  /// will be base 16
  std::string to_string()
  {
    std::string ret;
    for (int idx = m_rep.size() - 1; idx >= 0; idx--) {
      auto num = m_rep[idx];
      char high = hex[(num >> 4)];
      char low = hex[(num & 0x0F)];
      ret += high;
      ret += low;
      if (idx % 2 == 0 && !ret.empty() && idx != 0)
        ret += ' ';
    }
    auto pos = ret.find_first_not_of("0 ");
    if (pos == std::string::npos)
      return "0";
    return ret.substr(pos);
  }

  std::array<uint8_t, NumberSize> get_rep() const { return m_rep; }

  template<size_t NumSize>
  friend BigNum<NumSize> operator+(const BigNum<NumSize>& l,
                                      const BigNum<NumSize>& r);

private:
  // rep has least significant byte first i.e. at index 0
  std::array<uint8_t, NumberSize> m_rep{};
};

template<size_t NumberSize>
BigNum<NumberSize>
operator+(const BigNum<NumberSize>& l, const BigNum<NumberSize>& r)
{
  BigNum<NumberSize> ret;
  uint8_t carry{};

  for (int idx = 0; idx < l.m_rep.size(); idx++) {
    uint16_t val_and_carry = l.m_rep[idx] + r.m_rep[idx] + carry;
    ret.m_rep[idx] = static_cast<uint8_t>(val_and_carry);
    carry = static_cast<uint8_t>(val_and_carry >> 8);
  }

  if (carry != 0)
    throw std::runtime_error("Overflow");

  return ret;
}