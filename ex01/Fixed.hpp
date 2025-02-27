#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
  public:
    Fixed();
    Fixed(int const value);
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    void setRawBits(int const raw);
    float toFloat( void ) const;
  private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

#endif