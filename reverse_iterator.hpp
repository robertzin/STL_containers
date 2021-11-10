#include "iterator_traits.hpp"

// namespace ft {

// template < typename Iter >
// 	class reverse_iterator {
	
// 		public:
// 			typedef typename	iterator_traits<Iter>::difference_type		difference_type;
// 			typedef typename	iterator_traits<Iter>::value_type			value_type;
// 			typedef typename	iterator_traits<Iter>::reference			reference;
// 			typedef typename	iterator_traits<Iter>::pointer				pointer;
// 			typedef	typename	iterator_traits<Iter>::iterator_category	iterator_category;
			
// 			reverse_iterator() : _current() {}
// 			reverse_iterator(Iter other) : _current(other) {}
// 			reverse_iterator(const reverse_iterator& other) : _current(other._current) {}
// 			template< typename _Iter >
// 			reverse_iterator(const reverse_iterator<_Iter>& other) : _current(other.base()) {}
// 			template< class _Iter > 
// 			Iter base() const { return _current; }
// 			reference operator*() const { Iter tmp = _current; return *--tmp; }
// 			pointer operator->() const { return std::addressof(operator*()); }
// 			reference operator[](difference_type n) const { return *(*this + n); }

// 			reverse_iterator& operator=( const reverse_iterator<Iter>& other ) { _current = other._current; return *this; }
// 			bool operator==(const reverse_iterator other) const { return _current == other._current; }
// 			bool operator!=(const reverse_iterator other) const { return _current != other._current; }
// 			bool operator<(const reverse_iterator& other) const { return _current < other._current; }
// 			bool operator>(const reverse_iterator& other) const { return _current > other._current; }
// 			bool operator<=(const reverse_iterator& other) const { return _current <= other._current; }
// 			bool operator>=(const reverse_iterator& other) const { return _current >= other._current; }
			
// 			reverse_iterator&	operator++() { --_current; return *this; }
// 			reverse_iterator	operator++(int) { reverse_iterator t = _current; --_current; return t; }
// 			reverse_iterator&	operator--() { ++_current; return *this; }
// 			reverse_iterator	operator--(int) { reverse_iterator t = _current; ++_current; return t; }
// 			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_current - n); }
// 			reverse_iterator&	operator+=(difference_type n);
// 			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_current + n); }
// 			reverse_iterator&	operator-=(difference_type n);
			
// 		protected:
// 			Iter _current;
// 	};
// }