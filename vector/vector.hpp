#include <memory>


namespace ft
{
template < typename T, typename Allocator = std::allocator<T> >
class vector
{
	public :
		// 型名をネストし、抽象化
		typedef T value_type;
		typedef value_type* pointer;
   		typedef const pointer const_pointer;
		typedef value_type & reference;
		typedef const value_type & const_reference;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef pointer iterator;
		typedef const_pointer const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		// iterator
		iterator begin()
		{ return first; }

		iterator end()
		{ return last; }

		const_iterator begin() const
		{ return first; }

		const_iterator end() const
		{ return last; }

		const_iterator cbegin() const
		{ return first; }

		const_iterator cend() const
		{ return last; }

		// reverse_iterator
		reverse_iterator rbegin()
		{ return reverse_iterator{last}; }

		reverse_iterator rend()
		{ return reverse_iterator{first}; }

		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator{last}; }

		const_reverse_iterator rend() const
		{ return const_reverse_iterator{first}; }

		const_reverse_iterator rcbegin() const
		{ return const_reverse_iterator{last}; }

		const_reverse_iterator rcend() const
		{ return const_reverse_iterator{first}; }

		size_type size() const
		{ return (std::distance(begin(), end())); }

		bool empty() const
		{ return begin() == end(); }

		size_type capacity() const
		{ return reserved_last - first; }

		reference operator [] (size_type i)
		{ return first[i] ; }

		const_reference operator [] (size_type i) const
		{ return first[i] ; }

		reference at(size_type i)
		{
			if (i >= size() )
				throw std::out_of_range("index is out of range.");
			return (first[i]);
		}

		const_reference at(size_type i) const
		{
			if (i >= size() )
				throw std::out_of_range("index is out of range.");
			return (first[i]);
		}

		reference front()
		{ return (*first) ;}
		const_reference front() const
		{ return (*first) ;}
		reference back()
		{ return (*(last - 1)) ;}
		const_reference back() const
		{ return (*(last - 1)) ;}
		pointer data()
		{ return first; }
		const_pointer data() const
		{ return first; }

		vector ( const allocator_type &alloc)
			: alloc (alloc) {}
		vector()
			: vector( allocator_type() )
		{ }

		vector( size_type size, const allocator_type & alloc = allocator_type() )
			: vector( alloc)
		{ resize(size); }

		vector( size_type size, const_reference value, const allocator_type & alloc = allocator_type() )
			: vector( alloc)
		{ resize(size); }

		void clear()
		{ destroy_until( rend() ) ; }
		// vector( std::size_t n = 0, Allocator a = Allocator() ) ;
		// ~vector();
		// vector( const vector & x) ;
		// vector &operator =(const vector & x) ;
		~vector()
		{
			clear();
			deallocate();
		}
		void reserve( size_type size )
		{
			if (sz <= capacity())
				return ;
			pointer ptr = allocate(size);

			pointer old_first = first;
			pointer old_last = last;
			pointer old_capacity = capacity();

			first = ptr;
			last = first;
			reserved_last = first + size;




		}

private :
		pointer first;
		pointer last;
		pointer reserved_last;
		allocator_type alloc;
		typedef std::allocator_traits<allocator_type> traits;

		pointer allocate( size_type n )
		{ return (traits::allocate( alloc, n) ;) }

		void deallocate()
		{ traits::deallocate( alloc, first, capacity()); }

		void construct( pointer ptr)
		{ traits::construct( alloc, ptr); }
		void construct( pointer ptr, const_reference value)
		{ traits::construct( alloc, ptr, value); }
		void construct( pointer ptr, value_type && value)
		{ traits::construct( alloc, ptr, std::move(value)); }
		void destroy( pointer ptr )
		{ traits::destroy(alloc, ptr) ; }
		void destroy_until( reverse_iterator rend)
		{
			for (reverse_iterator riter = rbegin(); riter != rend; ++iter, --last)
				destroy( &*riter);
		}
} ;
}
