
#include "../inc/Fixed.hpp"

Fixed::Fixed() : _rawBits(0){
	#ifdef DEBUG
	std::cout << "Fixed dflt constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const Fixed& fixed) {
	#ifdef DEBUG
	std::cout << "Fixed copy constructor called" << std::endl;
	#endif
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	#ifdef DEBUG
	std::cout << "Fixed copy assignment operator overload called" << std::endl;
	#endif
	if (this != &fixed)
	{
		_rawBits = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	#ifdef DEBUG
	std::cout << "Fixed destructor called" << std::endl;
	#endif
}

int	Fixed::getRawBits() const {
	#ifdef DEBUG
	std::cout << "Get raw bits member function called" << std::endl;
	#endif
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	#ifdef DEBUG
	std::cout << "Set raw bits member function called" << std::endl;
	#endif
	_rawBits = raw;
}

const int	Fixed::_numOfFractBits = 8;

