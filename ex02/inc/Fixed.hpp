
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>
#include <type_traits>
#define	MASK_24 0x00FFFFFF

class Fixed {

private:
	int	_numValue;
	static const int _numOfFractBits;

public:
	// dflt constructor
	Fixed();
	// param constructors
	Fixed(const int iNum);
	Fixed(const float fNum);
	// copy constructor
	Fixed(const Fixed& fixed);
	// destructor
	~Fixed();
	
	// assignment operator
	Fixed&	operator=(const Fixed& fixed);

	// comparison operators
	bool	operator<(const Fixed& fixed) const;
	bool	operator>(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;

	// arithmetic operators
	Fixed	operator+(const Fixed& fixed) const;
	Fixed	operator-(const Fixed& fixed) const;
	Fixed	operator*(const Fixed& fixed) const;
	Fixed	operator/(const Fixed& fixed) const;

	// pre- and postincrement and decrement operators
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	// get and set
	int		getRawBits() const;
	void	setRawBits(int const raw);
	// conversions
	float	toFloat() const;
	int		toInt() const;
	// min
	Fixed&	min(Fixed& num1, Fixed& num2) const;
	const Fixed&	min(const Fixed& num1, const Fixed& num2) const;
	// max
	Fixed&	max(Fixed& num1, Fixed& num2) const;
	const Fixed&	max(const Fixed& num1, const Fixed& num2) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
