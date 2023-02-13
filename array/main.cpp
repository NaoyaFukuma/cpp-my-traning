#include "main.hpp"

template < typename Container >
void	print( Container const &a)
{
	for (std::size_t i = 0; i != a.size(); ++i)
	{
		cout << a[i] << endl;
	}
}

int	main()
{
// 	typedef array<int, 5> array_type;
//
// 	array_type a = {1,2,3,4,5};
// 	print(a);
// 	cout << "front " << a.front() << endl;
// 	cout << "back " << a.back() << endl;
// 	a.fill(100);
// 	print(a);
// 	cout << *(a.cbegin()) << "  " << *(a.cend()) << endl;
// 	array_type::const_iterator ite = a.cbegin();
// 	for (size_t i = 0; i < 3; i++, ite++)
// 		cout << *ite << endl;
	std::istream_iterator<int> iter( cin ), end_iter;
	std::vector<int> v;
}
