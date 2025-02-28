#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    int getRawBits(void) const;
    int toInt( void ) const;
  private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

#endif