#include <iostream>
#include <filesystem>
#include <vector>
#include <array>
#include <typeinfo>


#define cin std::cin
#define cout std::cout
#define endl std::endl

template < typename Array >
struct array_iterator;
template < typename Array >
struct array_const_iterator;

template < typename T, std::size_t N >
struct array
{
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef std::size_t size_type;
	typedef array_iterator<array> iterator;
	typedef array_const_iterator<array> const_iterator;

	value_type storage[N];

	size_type size() const;

	iterator begin()
	{
		return (iterator(*this, 0));
	}
	const_iterator begin() const
	{
		return (const_iterator(*this, 0));
	}
	iterator end()
	{
		return (iterator(*this, N));
	}
	const_iterator end() const
	{
		return (const_iterator(*this, N));
	}
	const_iterator cbegin() const
	{
		return (const_iterator(*this, 0));
	}
	const_iterator cend() const
	{
		return (const_iterator(*this, N));
	}


	reference operator[]( size_type i)
	{
		return storage[i];
	}
	const_reference operator[]( size_type i) const
	{
		return storage[i];
	}
	reference front()
	{
		return storage[0];
	}
	const_reference front() const
	{
		return storage[0];
	}
	reference back()
	{
		return storage[N - 1];
	}
	const_reference back() const
	{
		return storage[N - 1];
	}
	void	fill(T const & num)
	{
		for (size_type i = 0; i < N; ++i)
		{
			storage[i] = num;
		}
	}

};

template < typename T, std::size_t N >
typename array<T, N>::size_type array<T, N>::size() const
{
	return (N);
}



template < typename Array >
struct array_iterator
{
	Array & a;
	std::size_t i;

	array_iterator(Array & a, std::size_t i) : a(a), i(i)
	{
	}
	typename Array::reference operator *()
	{
		return (a[i]);
	}
	const typename Array::reference operator *() const
	{
		return (a[i]);
	}
	typename Array::reference operator [](std::size_t n) const
	{
		return *(*this + n);
	}
	array_iterator & operator ++()
	{
		++i;
		return (*this);
	}
	array_iterator operator ++(int)
	{
		array_iterator copy = *this;
		++*this;
		return (copy);
	}
	array_iterator & operator --()
	{
		--i;
		return (*this);
	}
	array_iterator operator --(int)
	{
		array_iterator copy = *this;
		--*this;
		return (copy);
	}
	array_iterator & operator +=(std::size_t n)
	{
		i += n;
		return (*this);
	}
	array_iterator operator +(std::size_t n) const
	{
		array_iterator copy = *this;
		copy += n;
		return (copy);
	}
	array_iterator & operator -=(std::size_t n)
	{
		i -= n;
		return (*this);
	}
	array_iterator operator -(std::size_t n) const
	{
		array_iterator copy = *this;
		copy -= n;
		return (copy);
	}
	bool operator==(array_iterator const & right )
	{
		return (i == right.i);
	}
	bool operator!=(array_iterator const & right )
	{
		return (i != right.i);
	}
	bool operator<(array_iterator const & right )
	{
		return (i < right.i);
	}
	bool operator<=(array_iterator const & right )
	{
		return (i <= right.i);
	}
	bool operator>(array_iterator const & right )
	{
		return (i > right.i);
	}
	bool operator>=(array_iterator const & right )
	{
		return (i >= right.i);
	}
};

template < typename Array >
struct array_const_iterator
{
	Array const & a;
	std::size_t i;

	array_const_iterator(Array const & a, std::size_t i) : a(a), i(i)
	{
	}
	array_const_iterator( typename Array::iterator const & iter) : a(iter.a), i(iter.i)
	{
	}
	const typename Array::const_reference operator *() const
	{
		return (a[i]);
	}
	typename Array::reference operator [](std::size_t n) const
	{
		return *(*this + n);
	}
	array_const_iterator & operator ++()
	{
		++i;
		return (*this);
	}
	array_const_iterator operator ++(int)
	{
		array_const_iterator copy = *this;
		++*this;
		return (copy);
	}
	array_const_iterator & operator --()
	{
		--i;
		return (*this);
	}
	array_const_iterator operator --(int)
	{
		array_const_iterator copy = *this;
		--*this;
		return (copy);
	}
	array_const_iterator & operator +=(std::size_t n)
	{
		i += n;
		return (*this);
	}
	array_const_iterator operator +(std::size_t n) const
	{
		array_const_iterator copy = *this;
		copy += n;
		return (copy);
	}
	array_const_iterator & operator -=(std::size_t n)
	{
		i -= n;
		return (*this);
	}
	array_const_iterator operator -(std::size_t n) const
	{
		array_const_iterator copy = *this;
		copy -= n;
		return (copy);
	}
	bool operator==(array_const_iterator const & right )
	{
		return (i == right.i);
	}
	bool operator!=(array_const_iterator const & right )
	{
		return (i != right.i);
	}
	bool operator<(array_const_iterator const & right )
	{
		return (i < right.i);
	}
	bool operator<=(array_const_iterator const & right )
	{
		return (i <= right.i);
	}
	bool operator>(array_const_iterator const & right )
	{
		return (i > right.i);
	}
	bool operator>=(array_const_iterator const & right )
	{
		return (i >= right.i);
	}
};

