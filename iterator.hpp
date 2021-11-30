#pragma once
#include "utils.hpp"

namespace ft {

	template< class Iter >
	struct iterator_traits {
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::const_pointer		const_pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::const_reference		const_reference;
		typedef typename Iter::iterator_category	iterator_category;
	};
	
	template< typename T >
	struct iterator_traits<T *> {
		typedef T									value_type;
		typedef T*									pointer;
		typedef const T*							const_pointer;
		typedef T&									reference;
		typedef const T&							const_reference;
		typedef ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
    };

	template < class T >
	class iterator{
		private:
			T _value;

		public:
			typedef				T													iterator_type;
			typedef typename	iterator_traits<iterator_type>::value_type			value_type;
			typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename	iterator_traits<iterator_type>::pointer				pointer;
			typedef typename	iterator_traits<iterator_type>::const_pointer		const_pointer;
			typedef typename	iterator_traits<iterator_type>::reference			reference;
			typedef typename	iterator_traits<iterator_type>::const_reference		const_reference;
			typedef	typename	iterator_traits<iterator_type>::iterator_category	iterator_category;

			iterator(iterator_type value = nullptr) : _value(value) {}
			~iterator() {}
			template <class U>
			iterator(const iterator<U>& other) : _value(other.base()) {}
			
			iterator_type base() const									{ return _value; }
			iterator& operator=(const iterator& other)					{ this->_value = other._value; return *this; }
			iterator& operator+=(difference_type n)						{ this->_value += n; return *this; }
			iterator& operator-=(difference_type n)						{ this->_value -= n; return *this; }
			
			iterator& operator++() 										{ _value++; return *this; }
			iterator& operator--() 										{ _value--; return *this; }
			iterator operator++(int) 									{ iterator tmp(*this); _value++; return tmp; }
			iterator operator--(int) 									{ iterator tmp(*this); _value--; return tmp; }
			
			iterator operator+(difference_type n) const					{ return iterator(this->_value + n); }
			iterator operator-(difference_type n) const					{ return iterator(this->_value - n); }
			difference_type operator+(const iterator& other) const		{ return _value + other._value; }
			difference_type operator-(const iterator& other) const		{ return _value - other._value; }
			
			reference operator[](difference_type n) const				{ return *this->_value[n]; }
			reference operator*() const									{ return *_value; }
			pointer operator->() const									{ return &(*_value); }

			bool operator==(const iterator other) const					{ return this->_value == other._value; }
			bool operator!=(const iterator other) const					{ return this->_value != other._value; }
			bool operator<(const iterator& other) const					{ return this->_value < other._value; }
			bool operator>(const iterator& other) const					{ return this->_value > other._value; }
			bool operator<=(const iterator& other) const				{ return this->_value <= other._value; }
			bool operator>=(const iterator& other) const				{ return this->_value >= other._value; }
	};

	template < class T >
	class reverse_iterator {
		private:
			T _value;

		public:
			typedef				T													iterator_type;
			typedef typename	iterator_traits<iterator_type>::value_type			value_type;
			typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename	iterator_traits<iterator_type>::pointer				pointer;
			typedef typename	iterator_traits<iterator_type>::const_pointer		const_pointer;
			typedef typename	iterator_traits<iterator_type>::reference			reference;
			typedef typename	iterator_traits<iterator_type>::const_reference		const_reference;
			typedef	typename	iterator_traits<iterator_type>::iterator_category	iterator_category;
			
			reverse_iterator(iterator_type value = nullptr) : _value(value) {}
			~reverse_iterator() {}
			template <class U>
			reverse_iterator(const reverse_iterator<U>& other) : _value(other.base()) {}

			iterator_type base() const 									{ return _value; }
			reverse_iterator& operator=(const reverse_iterator& other)	{ _value = other._value; return *this; }
			reverse_iterator& operator+=(difference_type n)				{ return reverse_iterator(_value - n); };
			reverse_iterator& operator-=(difference_type n)				{ return reverse_iterator(_value - n); };

			reverse_iterator&	operator++()							{ --_value; return *this; }
			reverse_iterator&	operator--()							{ ++_value; return *this; }
			reverse_iterator	operator++(int)							{ reverse_iterator t = _value; --_value; return t; }
			reverse_iterator	operator--(int)							{ reverse_iterator t = _value; ++_value; return t; }

			reverse_iterator	operator+(difference_type n) const		{ return reverse_iterator(_value - n); }
			reverse_iterator	operator-(difference_type n) const		{ return reverse_iterator(_value + n); }

			reference operator[](difference_type n) const				{ return *(*this + n); }
			reference operator*() const									{ iterator_type tmp = _value; return *--tmp; }
			pointer operator->() const									{ return std::addressof(operator*()); }
			
			bool operator==(const reverse_iterator other) const			{ return _value == other._value; }
			bool operator!=(const reverse_iterator other) const			{ return _value != other._value; }
			bool operator<(const reverse_iterator& other) const			{ return _value < other._value; }
			bool operator>(const reverse_iterator& other) const			{ return _value > other._value; }
			bool operator<=(const reverse_iterator& other) const		{ return _value <= other._value; }
			bool operator>=(const reverse_iterator& other) const		{ return _value >= other._value; }
	};
}
