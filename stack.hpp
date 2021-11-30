#pragma once
#include "vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef Container								container_type;
			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;
		
			stack ( const container_type& ctnr = container_type() ) : c(ctnr) {}
			stack( const stack& cont ) : c(cont.c) {}
			stack& operator=( const stack& other ) { c = other.c; return *this;; }
			~stack() {}
			
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			reference top() { return c.back(); }
			const_reference top() const { return c.back(); }
			void push (const value_type& val) { c.push_back(val); }
			void pop() { c.pop_back(); }
			
			friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c == rhs.c; }
			friend bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c != rhs.c; }
			friend bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c < rhs.c; }
			friend bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c <= rhs.c; }
			friend bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c > rhs.c; }
			friend bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return lhs.c >= rhs.c; }
		
		protected:
			container_type c;

	};

}