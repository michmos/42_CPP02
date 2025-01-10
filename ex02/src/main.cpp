
#include "../inc/Fixed.hpp"
#include <climits>
#include <string>

void	testCompOperators(const Fixed& num1, const Fixed& num2)
{
	std::cout << "Comparison operators\n" << std::endl;

	std::cout << "== ";
	if (num1 == num2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;

	std::cout << "!= ";
	if (num1 != num2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;

	std::cout << "<  ";
	if (num1 < num2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;

	std::cout << ">  ";
	if (num1 > num2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;

	std::cout << "<= ";
	if (num1 <= num2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;

	std::cout << ">= ";
	if (num1 >= num2)
		std::cout << "1" << std::endl;
	else
		std::cout << "0" << std::endl;
}

void	testArthmtcOperators(const Fixed& num1, const Fixed& num2)
{
	std::cout << "\nArithmetic operators\n" << std::endl;

	std::cout << "Sum: " << num1 + num2 << std::endl;
	std::cout << "Sub: " << num1 - num2 << std::endl;
	std::cout << "Prod: " << num1 * num2 << std::endl;
	std::cout << "Div: " << num1 / num2 << std::endl;
}

void	testIncDecs(Fixed num1)
{
	std::cout << "\nIncrements & Decrements\n" << std::endl;

	std::cout << "Num: " << num1 << std::endl;
	std::cout << "Pre++: " << ++num1 << std::endl;
	std::cout << "Post--: " << num1-- << std::endl;
	std::cout << "Num: " << num1 << std::endl;
	std::cout << "Pre--: " << --num1 << std::endl;
	std::cout << "Post++: " << num1++ << std::endl;
	std::cout << "Num: " << num1 << std::endl;
}

int main( int argc, char *argv[] ) {

	if (argc != 3) {
		std::cerr << "Usage ./program <num1> <num2>" << std::endl;
		return (-1);
	}

	Fixed	num1;
	Fixed	num2;

	try {
		num1 = (std::stof(argv[1]));
		num2 = (std::stof(argv[2]));
	}
	catch (...) {
		return (-1);
	}

	testCompOperators(num1, num2);
	testArthmtcOperators(num1, num2);
	testIncDecs(num1);


	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
