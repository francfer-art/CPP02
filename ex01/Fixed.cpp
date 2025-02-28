#include "Fixed.hpp"

Fixed::Fixed()
{
  std::cout << "Default constructor called" << std::endl;
  _fixedPointValue = 0;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << "Assignation operator called" << std::endl;
  if(this != &fixed)
    _fixedPointValue = fixed.getRawBits();
  return *this;
}

Fixed::Fixed(int const value)
{
  std::cout << "Int constructor called" << std::endl;
  _fixedPointValue = value << _fractionalBits;
}