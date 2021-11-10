#include <iostream>
#ifndef ALLOCATOR_
# define ALLOCATOR_

namespace ft {

	template < class T >
	class allocator {
		public:
			typedef T			value_type;
			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			typedef T&			reference;
			typedef const T&	const_reference;

			allocator() throw() { std::cout << "allocator constructed" << std::endl; } ;
			allocator (const allocator&) throw() { std::cout << "allocator copied" << std::endl; } ;
			~allocator () throw() { std::cout << "allocator destructed" << std::endl; } ;
			
			pointer allocate (size_type n, allocator* hint = 0) { return (pointer)operator new( n * sizeof(hint) ); } // operator new(n)
			pointer address ( reference x ) const { return &x; }
			const_pointer address ( const_reference x ) const { return &x; }
			size_type max_size() const throw() {
				size_type n = (size_type)(-1) / sizeof(T);
				return (0 < n ? n : 1);
			}

			void deallocate ( pointer p, size_type ) { operator delete(p); }
			void construct ( pointer p, const_reference val ) { new ((void*)p) value_type (val); }
			void destroy (pointer p) { p->~value_type(); }
			template < class U >
				struct rebind { // A::rebind<U>::other::pointer
					typedef allocator<U> other; // allocator<float>::rebind<Myelement>::other\n Myalloc(myal);
				};

			template < class U >
			allocator& operator=( const allocator<U>& x ) {
				std::cout << "allocator assigned" << std::endl;
				if (*this == x)
					return *this;
				this = x;
				return *this;				
			}
	};
	template < class T, class U >
		bool operator==( const allocator<T>&, const allocator<U>& ) { return true; }
	template < class T, class U >
		bool operator!=( const allocator<T>&, const allocator<U>& ) { return false; }
}
#endif