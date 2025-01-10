
#include "../inc/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0){
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
	_rawBits = iNum << _numOfFractBits;
}

Fixed::Fixed(const float fNum) {
	#ifdef DEBUG
	std::cout << "Fixed float constructor called" << std::endl;
	#endif

	_rawBits = static_cast<int>(std::round(fNum * (1 << _numOfFractBits)));
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
		_rawBits = fixed._rawBits;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}


//////////////////////////////////////////////////////////////////////
/// comparsion operators
//////////////////////////////////////////////////////////////////////
bool	Fixed::operator<(const Fixed& fixed) const
{
	return (_rawBits < fixed._rawBits);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (_rawBits > fixed._rawBits);
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (_rawBits <= fixed._rawBits);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (_rawBits >= fixed._rawBits);
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (_rawBits == fixed._rawBits);
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (_rawBits != fixed._rawBits);
}

//////////////////////////////////////////////////////////////////////
/// arithmetic operators
//////////////////////////////////////////////////////////////////////
Fixed	Fixed::operator+(const Fixed& fixed) const {
	Fixed	newFixed;

	newFixed.setRawBits(this->_rawBits + fixed._rawBits);
	return (newFixed);
}

Fixed	Fixed::operator-(const Fixed& fixed) const {
	Fixed	newFixed;

	newFixed.setRawBits(this->_rawBits - fixed._rawBits);
	return (newFixed);
}

Fixed	Fixed::operator*(const Fixed& fixed) const {
	Fixed	newFixed;
	
	newFixed._rawBits = (this->_rawBits * fixed._rawBits) >> _numOfFractBits;
	return (newFixed);
}

Fixed	Fixed::operator/(const Fixed& fixed) const {
	Fixed	newFixed;
	
	newFixed._rawBits = (this->_rawBits << _numOfFractBits) / fixed._rawBits;
	return (newFixed);
}

//////////////////////////////////////////////////////////////////////
/// pre and post increment and decrement operators
//////////////////////////////////////////////////////////////////////
Fixed&	Fixed::operator++() {
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int ) {
	Fixed	old(*this);
	++(*this);
	return (old);
}

Fixed&	Fixed::operator--() {
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	old(*this);
	--(*this);
	return (old);
}

//////////////////////////////////////////////////////////////////////
/// Getter and setter
//////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////
/// conversions
//////////////////////////////////////////////////////////////////////
float	Fixed::toFloat() const {
	return (static_cast<float>(_rawBits) / (1 << _numOfFractBits));
}

int	Fixed::toInt() const {
	return (_rawBits >> _numOfFractBits);
}

//////////////////////////////////////////////////////////////////////
/// min and max
//////////////////////////////////////////////////////////////////////
Fixed&	Fixed::min(Fixed& num1, Fixed& num2) const {
	if (num1 < num2)
		return (num1);
	return (num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2) const
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2) const
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2) const
{
	if (num1 > num2)
		return (num1);
	return (num2);
}





const int	Fixed::_numOfFractBits = 8;

