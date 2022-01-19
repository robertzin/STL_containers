#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# pragma once
# include "utils.hpp"
# include "node.hpp"
# include <iostream>

namespace ft {

	template< class Iterator >
	struct iterator_traits {
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template< typename T >
	struct iterator_traits<T *> {
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef ptrdiff_t							difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ptrdiff_t						difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
	};
	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last) {
		typename iterator_traits<InputIterator>::difference_type rtn = 0;
		while (first != last) {
			first++;
			rtn++;
		}
		return (rtn);
	}

	template< class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	class iterator{
		public:
			typedef T				value_type;
			typedef Distance		difference_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Category		iterator_category;
	};

	template <class T>
	class bidirectional_iterator : iterator<std::bidirectional_iterator_tag, T> {
		public:
			typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename iterator<std::bidirectional_iterator_tag, T>::reference			reference;

		private:
			pointer _value;
	};

template <class T>
	class random_access_iterator : iterator<std::random_access_iterator_tag, T>
	{
		public :
			typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef T*																			pointer;
			typedef T&																			reference;

		public :
			random_access_iterator( pointer value = NULL ) :_value(value) {}
			// random_access_iterator() :_value(NULL) {}
			// random_access_iterator( pointer ptr ) :_value(ptr) {}
			// random_access_iterator( const random_access_iterator& other ) :_value(other._value) {}
			template <class U>
			random_access_iterator(const random_access_iterator<U>& other,
				typename ft::enable_if<std::is_convertible<U, iterator_category>::value>::type* = 0)
					: _value(other.base()) {}

			virtual ~random_access_iterator() {}

			pointer base() const { return (_value); }
			operator random_access_iterator<const value_type>() const 				{ return random_access_iterator<const value_type>(_value); }

			random_access_iterator& operator=(const random_access_iterator& other)	{ _value = other._value; return *this; }
			random_access_iterator& operator+=(difference_type n) 					{ _value += n; return *this; }
			random_access_iterator& operator-=(difference_type n) 					{ _value -= n; return *this; }

			random_access_iterator& operator++() 									{ _value++; return *this; }
			random_access_iterator& operator--() 									{ _value--; return *this; }
			random_access_iterator operator++(int)									{ random_access_iterator tmp(*this); _value++; return tmp; }
			random_access_iterator operator--(int)									{ random_access_iterator tmp(*this); _value--; return tmp; }

			random_access_iterator operator+(difference_type n) const 							{ return random_access_iterator(_value + n); }
			random_access_iterator operator-(difference_type n) const 							{ return random_access_iterator(_value - n); }
			friend random_access_iterator operator+(int nb, const random_access_iterator& it)	{ random_access_iterator newIt(it); return (newIt += nb); }
			friend random_access_iterator operator-(int nb, const random_access_iterator& it)	{ random_access_iterator newIt(it); return (newIt -= nb); }
			difference_type operator+(const random_access_iterator& other) const				{ return _value + other._value; }
			difference_type operator-(const random_access_iterator& other) const				{ return _value - other._value; }

			template <class Iter>
			difference_type operator-(const random_access_iterator<Iter>& x)	{ return _value - x.base(); }
			reference operator[](difference_type n) const								{ return _value[n]; }
			reference operator*()														{ return *_value; }
			pointer operator->()														{ return &(*_value); }

			template <class U>
			bool operator==(const random_access_iterator<U> other) const				{ return this->_value == other.base(); }
			template <class U>
			bool operator!=(const random_access_iterator<U> other) const				{ return this->_value != other.base(); }
			template <class U>
			bool operator<(const random_access_iterator<U>& other) const				{ return this->_value < other.base(); }
			template <class U>
			bool operator>(const random_access_iterator<U>& other) const				{ return this->_value > other.base(); }
			template <class U>
			bool operator<=(const random_access_iterator<U>& other) const				{ return this->_value <= other.base(); }
			template <class U>
			bool operator>=(const random_access_iterator<U>& other) const				{ return this->_value >= other.base(); }

		protected :
			pointer _value;
	};

	template < class Iter >
	class reverse_iterator {

		public:
			typedef				Iter												iterator_type;
			typedef typename	iterator_traits<iterator_type>::value_type			value_type;
			typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename	iterator_traits<iterator_type>::pointer				pointer;
			typedef typename	iterator_traits<iterator_type>::reference			reference;
			typedef	typename	iterator_traits<iterator_type>::iterator_category	iterator_category;

		public:
			reverse_iterator() : _value() {}
			reverse_iterator(Iter it) : _value(it) {}
			reverse_iterator(const reverse_iterator &rev_it) : _value(rev_it._value) {}

			// reverse_iterator(iterator_type const &it = NULL) : _value(it) {}
			~reverse_iterator() {}
			template<typename U>
			reverse_iterator(const reverse_iterator<U>& other,
				typename ft::enable_if<std::is_convertible<U, Iter>::value>::type* = 0)
						: _value(other.base()) {}

			Iter base() const 											{ return _value; }
			operator reverse_iterator<const Iter>() const 				{ return reverse_iterator<const Iter>(_value); }
			reverse_iterator& operator=(const reverse_iterator& other)	{ _value = other._value; return *this; }
			reverse_iterator& operator+=(difference_type n)				{ _value -= n; return *this; };
			reverse_iterator& operator-=(difference_type n)				{ _value += n; return *this; };

			reverse_iterator& operator++()								{ --_value; return *this; }
			reverse_iterator& operator--()								{ ++_value; return *this; }
			reverse_iterator operator++(int)							{ reverse_iterator tmp(*this); --_value; return tmp; }
			reverse_iterator operator--(int)							{ reverse_iterator tmp(*this); ++_value; return tmp; }

			reverse_iterator operator+(difference_type n) const			{ return reverse_iterator(_value - n); }
			reverse_iterator operator-(difference_type n) const			{ return reverse_iterator(_value + n); }
			// friend reverse_iterator operator+(int nb, const reverse_iterator& it)	{ return reverse_iterator(it.base() += nb); }
			// friend reverse_iterator operator-(int nb, const reverse_iterator& it)	{ return reverse_iterator(it.base() -= nb); }

			// template <class Iter1>
			// difference_type operator-(const reverse_iterator<Iter1>& x)	{ return x.base() - _value; }

			reference operator[](difference_type n) const				{ return *(*this + n); }
			reference operator*() const									{ Iter tmp = _value; return *--tmp; }
			pointer operator->() const									{ return std::addressof(operator*()); }

			template <class U>
			bool operator==(const reverse_iterator<U> other) const		{ return _value == other.base(); }
			template <class U>
			bool operator!=(const reverse_iterator<U> other) const		{ return _value != other.base(); }
			template <class U>
			bool operator<(const reverse_iterator<U>& other) const		{ return _value > other.base(); }
			template <class U>
			bool operator>(const reverse_iterator<U>& other) const		{ return _value < other.base(); }
			template <class U>
			bool operator<=(const reverse_iterator<U>& other) const		{ return _value >= other.base(); }
			template <class U>
			bool operator>=(const reverse_iterator<U>& other) const		{ return _value <= other.base(); }

		private:
			Iter _value;
	};

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type
		operator-( const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs ) { return rhs.base() - lhs.base(); }

	template< class Iterator, class Iterator1 >
	typename reverse_iterator<Iterator>::difference_type
		operator-( const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator1>& rhs ) { return rhs.base() - lhs.base(); }

	template< class Iter >
	reverse_iterator<Iter>
		operator+( typename reverse_iterator<Iter>::difference_type n,
				const reverse_iterator<Iter>& it ) { return reverse_iterator<Iter>(it.base() - n); }


	template <class T, class Node>
	class map_iterator : public iterator<std::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;

			map_iterator() : _ptr(), _root() {}
			map_iterator(Node* node, Node* root) : _ptr(node), _root(root) {}
			map_iterator(map_iterator const &x) {
				_ptr = x._ptr;
				_root = x._root;
			}
			virtual ~map_iterator() {}
			Node* base() const { return _ptr; }
			map_iterator& operator= (map_iterator const &x) {
				if (this == &x)
					return *this;
				_ptr = x._ptr;
				_root = x._root;
				return (*this);
			}

			Node *min(Node *node) {
				Node *current = node;
				while (current && current->left != NULL)
					current = current->left;
				return (current);
			}

			Node* max(Node* node) {
				while (node && node->right != NULL)
					node = node->right;
				return (node);
			}

			operator map_iterator<const T, const Node>() const { return map_iterator<const T, const Node>(_ptr, _root); }
			T* operator->() const { return (_ptr->data); }
			T& operator*() const { return (*_ptr->data); }
			map_iterator& operator++() {
				Node* p;
				if (_ptr == NULL) { return (*this = map_iterator(min(_root), _root)); }
				if (_ptr == max(_root)) { return (*this = map_iterator(NULL, _root)); }
				if (_ptr->right != NULL) {
					_ptr = _ptr->right;
					while (_ptr->left != NULL)
						_ptr= _ptr->left;
				}
				else {
					p = _ptr->parent;
					while (p != NULL && _ptr == p->right) {
						_ptr = p;
						p = p->parent;
					}
					_ptr = p;
				}
				return (*this);
			}

			map_iterator& operator--() {
				Node* p;
				if (_ptr == NULL) { _ptr = max(_root); }
				else {
					if (_ptr->left != NULL) {
						_ptr = _ptr->left;
						while (_ptr->right != NULL)
							_ptr= _ptr->right;
					}
					else {
						p = _ptr->parent;
						while (p != NULL && _ptr == p->left) {
							_ptr = p;
							p = p->parent;
						}
						_ptr = p;
					}
				}
				return (*this);
			}
			map_iterator operator++(int) { map_iterator tmp(*this); ++(*this); return (tmp); }
			map_iterator operator--(int) { map_iterator tmp(*this); --(*this); return (tmp); }
			friend bool	operator==(map_iterator const& lhs, map_iterator const& rhs) { return (lhs._ptr == rhs._ptr); }
			friend bool	operator!=(map_iterator const& lhs, map_iterator const& rhs) { return (lhs._ptr != rhs._ptr); }

		private :
			Node*	_ptr;
			Node*	_root;
	};
}

#endif
