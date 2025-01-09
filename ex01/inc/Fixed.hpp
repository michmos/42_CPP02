
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>
#define	MASK_24 0x00FFFFFF

class Fixed {

private:
	int	_numValue;
	static const int _numOfFractBits;

public:
	Fixed();
	Fixed(const int iNum);
	Fixed(const float fNum);
	Fixed(const Fixed& fixed);
	~Fixed();
	
	Fixed& operator=(const Fixed& fixed);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
