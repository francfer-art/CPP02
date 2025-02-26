#include "Fixed.hpp"

Fixed::Fixed() 
{
  std::cout << "Default constructor called" << std::endl;
  _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed) 
{
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member called" << std::endl;
  return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
  _fixedPointValue = raw;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << "Copy aassignment operator called" << std::endl;
  if(this != &fixed)
    _fixedPointValue = fixed.getRawBits();
  return *this;
}