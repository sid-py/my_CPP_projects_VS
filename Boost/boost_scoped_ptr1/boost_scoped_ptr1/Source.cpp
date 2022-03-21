#include<boost/scoped_array.hpp>
#include<iostream>

/*
int main()
{
	boost::scoped_ptr<int> p{ new int{1} };
	std::cout << *p << '\n';
	p.reset(new int{ 2 });
	std::cout << *p.get() << '\n';
	p.reset();
	std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
}
*/


/*
int main() {
	boost::scoped_array<int> p{ new int[2] };
	*p.get() = 1;
	p.reset(new int[3]);
	std::cout << *p.get() << std::endl;
}

*/

