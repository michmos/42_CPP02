
#include "../inc/Fixed.hpp"
#include <climits>

int main( void ) {
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		Fixed e;
		std::cout << "e is " << e << std::endl;
		std::cout << "e is " << e.toInt() << " as integer" << std::endl;
		Fixed f(8388607);
		std::cout << "f is " << f << std::endl;
		Fixed g(-1234.4321f);
		std::cout << "g is " << g << std::endl;
	}
	return 0;
}
