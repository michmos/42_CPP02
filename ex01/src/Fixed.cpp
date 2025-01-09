
#include "../inc/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _numValue(0){
	#ifdef DEBUG
	std::cout << "Fixed dflt constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const int iNum) {
	#ifdef DEBUG
	std::cout << "Fixed integer constructor called" << std::endl;
	if (iNum > pow(2, (sizeof(int) * 8) - _numOfFractBits - 1) - 1)
	{
		std::cout << "Fixed numer did overflow when being constructed through integer" << std::endl;
	}
	#endif
	_numValue = iNum << _numOfFractBits;
}

Fixed::Fixed(const float fNum) {
	#ifdef DEBUG
	std::cout << "Fixed float constructor called" << std::endl;
	#endif

	_numValue = static_cast<int>(std::round(fNum * (1 << _numOfFractBits)));
}

Fixed::Fixed(const Fixed& fixed) {
	#ifdef DEBUG
	std::cout << "Fixed copy constructor called" << std::endl;
	#endif
	*this = fixed;
}

Fixed::~Fixed() {
	#ifdef DEBUG
	std::cout << "Fixed destructor called" << std::endl;
	#endif
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	#ifdef DEBUG
	std::cout << "Fixed copy assignment operator overload called" << std::endl;
	#endif
	if (this != &fixed)
	{
		_numValue = fixed._numValue;
	}
	return (*this);
}

int	Fixed::getRawBits() const {
	#ifdef DEBUG
	std::cout << "Get raw bits member function called" << std::endl;
	#endif
	return (_numValue);
}

void	Fixed::setRawBits(int const raw) {
	#ifdef DEBUG
	std::cout << "Set raw bits member function called" << std::endl;
	#endif
	_numValue = raw;
}

float	Fixed::toFloat() const {
	return (static_cast<float>(_numValue) / (1 << _numOfFractBits));
}

int	Fixed::toInt() const {
	return (_numValue >> _numOfFractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}



const int	Fixed::_numOfFractBits = 8;

