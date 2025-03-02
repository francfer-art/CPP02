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

Fixed::Fixed(float const value)
{
  std::cout << "Float constructor called" << std::endl;
  _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
  return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
  return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
  out << fixed.toFloat();
  return out;
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member called" << std::endl;
  return _fixedPointValue;
}

bool Fixed::operator>(const Fixed &fixed) const
{
  return _fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
  return _fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
  return _fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
  return _fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
  return _fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
  return _fixedPointValue != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
  return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
  return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
  return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
  return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
{
  _fixedPointValue++;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed tmp(*this);
  operator++();
  return tmp;
}

Fixed &Fixed::operator--()
{
  _fixedPointValue--;
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed tmp(*this);
  operator--();
  return tmp;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
  return a < b ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
  return a > b ? a : b;
}