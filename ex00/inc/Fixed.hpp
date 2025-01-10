
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int	_rawBits;
	static const int _numOfFractBits;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	Fixed& operator=(const Fixed& fixed);
	~Fixed();
	
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
