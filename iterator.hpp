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
	};

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
			random_access_iterator() :_value(NULL) {}
			random_access_iterator( pointer ptr ) :_value(ptr) {}
			random_access_iterator( const random_access_iterator& other ) :_value(other._value) {}
			virtual ~random_access_iterator() {}

			pointer base() const { return (_value); }
			operator random_access_iterator<const value_type>() const 				{ return random_access_iterator<const value_type>(_value); }

			random_access_iterator& operator=(const random_access_iterator& other)	{ _value = other._value; return *this; }
			random_access_iterator& operator+=(difference_type n) 					{ _value += n; return *this; }
			random_access_iterator& operator-=(difference_type n) 					{	_value -= n; return *this; }

			random_access_iterator& operator++() 									{ _value++; return *this; }
			random_access_iterator& operator--() 									{ _value--; return *this; }
			random_access_iterator operator++(int)									{ random_access_iterator tmp(*this); _value++; return tmp; }
			random_access_iterator operator--(int)									{ random_access_iterator tmp(*this); _value--; return tmp; }

			random_access_iterator operator+(difference_type n) const 				{ return random_access_iterator(_value + n); }
			random_access_iterator operator-(difference_type n) const 				{ return random_access_iterator(_value - n); }
			difference_type operator+(const random_access_iterator& other) const	{ return _value + other._value; }
			difference_type operator-(const random_access_iterator& other) const	{ return _value - other._value; }

			reference operator[](difference_type n) const							{ return *this->_value[n]; }
			reference operator*()													{ return *_value; }
			pointer operator->()													{ return &(*_value); }

			bool operator==(const random_access_iterator other) const				{ return this->_value == other._value; }
			bool operator!=(const random_access_iterator other) const				{ return this->_value != other._value; }
			bool operator<(const random_access_iterator& other) const				{ return this->_value < other._value; }
			bool operator>(const random_access_iterator& other) const				{ return this->_value > other._value; }
			bool operator<=(const random_access_iterator& other) const				{ return this->_value <= other._value; }
			bool operator>=(const random_access_iterator& other) const				{ return this->_value >= other._value; }

		protected :
			pointer _value;
	};

	template < class T >
	class reverse_iterator {

		public:
			typedef				T													iterator_type;
			typedef typename	iterator_traits<iterator_type>::value_type			value_type;
			typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename	iterator_traits<iterator_type>::pointer				pointer;
			typedef typename	iterator_traits<iterator_type>::reference			reference;
			typedef	typename	iterator_traits<iterator_type>::iterator_category	iterator_category;

		public:
			reverse_iterator() : _value(iterator_type()) {}
			reverse_iterator(iterator_type const &it) { iterator_type tmp = it; _value = --tmp; }
			reverse_iterator(reverse_iterator const &rev_it) : _value(rev_it._value) {}
			~reverse_iterator() {}
			template<typename iter>
			reverse_iterator(const reverse_iterator<iter> & it) : _value(--it.base()) {}

			iterator_type base() const 									{ iterator_type tmp = _value; return ++tmp; }
			reverse_iterator& operator=(const reverse_iterator& other)	{ _value = other._value; return *this; }
			reverse_iterator& operator+=(difference_type n)				{ return reverse_iterator(_value - n); };
			reverse_iterator& operator-=(difference_type n)				{ return reverse_iterator(_value - n); };

			reverse_iterator&	operator++()							{ --_value; return *this; }
			reverse_iterator&	operator--()							{ ++_value; return *this; }
			reverse_iterator	operator++(int)							{ reverse_iterator tmp(*this); _value--; return tmp; }
			reverse_iterator	operator--(int)							{ reverse_iterator tmp(*this); _value++; return tmp; }

			reverse_iterator	operator+(difference_type n) const		{ return reverse_iterator(_value - n - 1); }
			reverse_iterator	operator-(difference_type n) const		{ return reverse_iterator(_value + n + 1); }

			reference operator[](difference_type n) const				{ return *(*this + n); }
			reference operator*() const									{ iterator_type tmp = _value; return *tmp; }
			pointer operator->() const									{ return std::addressof(operator*()); }

			bool operator==(const reverse_iterator other) const			{ return _value == other._value; }
			bool operator!=(const reverse_iterator other) const			{ return _value != other._value; }
			bool operator<(const reverse_iterator& other) const			{ return _value < other._value; }
			bool operator>(const reverse_iterator& other) const			{ return _value > other._value; }
			bool operator<=(const reverse_iterator& other) const		{ return _value <= other._value; }
			bool operator>=(const reverse_iterator& other) const		{ return _value >= other._value; }

		private:
			iterator_type _value;
	};

	template <class T, class Node, class Compare, class Tree>
	class map_iterator : public iterator<std::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;

			map_iterator() : _ptr(), _cmp(), _tree() {}
			map_iterator(Node* node, const Tree *tree) : _ptr(node), _tree(tree) {}
			map_iterator(map_iterator const&other) { *this = other; }
			virtual ~map_iterator() {}
			Node* base() const { return _ptr; }
			map_iterator& operator= (map_iterator const& x) {
				_ptr = x._ptr;
				_tree = x._tree;
				_cmp = x._cmp;
				return (*this);
			}
			operator map_iterator<const T, const Node, Compare, Tree>() const { return map_iterator<const T, const Node, Compare, Tree>(_ptr, _tree); }
			T* operator->() const { return (_ptr->data); }
			T& operator*() const { return (*_ptr->data); }
			map_iterator& operator++()
			{
				Node* p;
				if (_ptr == NULL)
					return (*this = map_iterator(_tree->findm(_tree->getRoot()), _tree));
				if (_ptr == _tree->findM(_tree->getRoot()))
					return (*this = map_iterator(NULL, _tree));
				if (_ptr->right != NULL)
				{
					_ptr = _ptr->right;
					while (_ptr->left != NULL)
						_ptr= _ptr->left;
				}
				else
				{
					p = _ptr->parent;
					while (p != NULL && _ptr == p->right)
					{
						_ptr = p;
						p = p->parent;
					}
					_ptr = p;
				}
				return (*this);
			}
			map_iterator& operator--()
			{
				Node* p;
				if (_ptr == NULL) {
					Node *root = _tree->getRoot();
					_ptr = _tree->findM(root);
				}
				else
				{
					if (_ptr->left != NULL)
					{
						_ptr = _ptr->left;
						while (_ptr->right != NULL)
							_ptr= _ptr->right;
					}
					else
					{
						p = _ptr->parent;
						while (p != NULL && _ptr == p->left)
						{
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
			Node*		_ptr;
			Compare		_cmp;
			Tree const	*_tree;
	};
}

#endif
