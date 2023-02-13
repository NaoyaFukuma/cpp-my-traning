#include "main.hpp"
#include <iostream>
#define cout std::cout
#define endl std::endl

int	main()
{
	ft::allocator<int> alloc;
	ft::vector<int> vec(alloc);
	ft::vector<int> vec1(5,alloc);
	ft::vector<int> vec2(5,123,alloc);
	cout << &vec << endl;

}
