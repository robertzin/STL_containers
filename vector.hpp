#ifndef VECTOR_HPP
# define VECTOR_HPP
# pragma once
# include <memory>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

template < class T, class A = std::allocator<T> >
class vector {

	public:
		typedef				T												value_type;
		typedef				A												allocator_type;
		typedef typename 	allocator_type::size_type						size_type;
		typedef typename 	allocator_type::difference_type					difference_type;
		typedef typename 	allocator_type::pointer							pointer;
		typedef typename 	allocator_type::reference						reference;
		typedef typename 	allocator_type::const_reference					const_reference;

		typedef 			ft::random_access_iterator<value_type>			iterator;
		typedef 			ft::random_access_iterator<const value_type>	const_iterator;
		typedef 			ft::reverse_iterator<iterator>					reverse_iterator;
		typedef 			ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		// Iterators:
		iterator begin() { return iterator(_array); }
		iterator end() { return iterator(_array + _size); }
		const_iterator begin() const { return const_iterator(_array); }
		const_iterator end() const { return const_iterator(_array + _size); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		// Constructors:
		vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _array(_alloc.allocate(0)) { }

		vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(n), _size(n), _array(_alloc.allocate(n)) {
			for (size_type i = 0; i < n; i++)
				_array[i] = val;
		}
		vector(const vector& other) : _capacity(0), _size(0), _array(NULL) { *this = other; }

		template < class It >
		vector(It first, It last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(0), _size(0), _array(NULL) { assign(first, last); }
		~vector() {
			this->clear();
			_alloc.deallocate(_array, _capacity);
		}
		vector& operator= (const vector& other) {
			if (this == &other)
				return *this;
			clear();
			reserve(other._size);
			_size = other._size;
			for (size_type i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		}

		// Capacity:
		size_type size() const { return _size; }
		size_type max_size() const { return _alloc.max_size(); }
		void resize (size_type n, value_type val = T()) {
			if (n < _size) {
				while (_size != n)
					pop_back();
			}
			else {
				if (_capacity * 2 < n)
					reserve(n);
				while (_size != n)
					push_back(val);
			}
		}
		size_type capacity() const { return _capacity;}
		bool empty() const { return size() == 0;}

		void reserve (size_type n) {
			// if (n <= _capacity)
			// 	return;
			// n = std::max(n, _size * 2);
			// T* new_arr = _alloc.allocate(new_arr);
			// for (size_type i = 0; i < size; i++)
			// 	new_arr[i] = _array[i];
			// if (_array)
			// 	_alloc.deallocate(_array, _capacity);
			// _array = new_arr;
			// _capacity = n;
			if (n > _capacity) {
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i)
					tmp[i] = _array[i];
				if (_array)
					_alloc.deallocate(_array, _capacity);
				_capacity = n;
				_array = tmp;
			}
		}

		// Element access:
		reference operator[] (size_type n) { return *(begin() + n); }
		const_reference operator[] (size_type n) const  { return *(begin() + n); }
		reference at (size_type n) {
			if (n < _size)
				return *(begin() + n);
			throw std::out_of_range("vector reference at");
		}
		const_reference at (size_type n) const {
			if (n < _size)
				return *(begin() + n);
			throw std::out_of_range("vector reference at");
		}
		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }
		reference back() { return *(end() - 1); }
		const_reference back() const { return *(end() - 1); }
		value_type* data() { return _array; }
		const value_type* data() const { return _array; }

		// Modifiers:
		template <class InputIterator>
		void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			clear();
			size_type i = std::distance(first, last);
			reserve(i);
			_size = i;
			i = 0;
			while (first != last) {
				_array[i++] = *first++;
			}
		}

		void assign (size_type n, const value_type& val) {
			if (n < 0)
				throw std::out_of_range("vector");
			clear();
			resize(n, val);
		}
		void push_back (const value_type& val) {
			if (_size == _capacity)
				reserve(_size ? _size * 2 : 1);
			_array[_size++] = val;
		}

		void pop_back() { _alloc.destroy(_array + _size); _size--; }

		iterator insert (iterator position, const value_type& val) {
			difference_type idx = position - this->begin();
			this->insert(position, 1, val);
			return (iterator(this->begin() + idx));
		}
		void insert (iterator position, size_type n, const value_type& val) {
			difference_type const	idx = position - this->begin();
			difference_type const	old_end_idx = this->end() - this->begin();
			iterator				old_end;
			iterator				end;

			this->resize(this->_size + n);
			end = this->end();
			position = this->begin() + idx;
			old_end = this->begin() + old_end_idx;
			while (old_end != position)
				*--end = *--old_end;
			while (n-- > 0)
				*position++ = val;
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			difference_type const	idx = position - this->begin();
			difference_type const	old_end_idx = this->end() - this->begin();
			iterator				old_end;
			iterator				end;

			this->resize(this->_size + (ft::distance(first, last)));

			end = this->end();
			position = this->begin() + idx;
			old_end = this->begin() + old_end_idx;
			while (old_end != position)
				*--end = *--old_end;
			while (first != last)
				*position++ = *first++;
		}

		iterator erase (iterator pos) {
			size_type idx = pos - begin();
			for (size_type i = idx; i < _size; ++i) {
				_array[i] = _array[i + 1];
			}
			_size--;
			return pos;
		}

		iterator erase (iterator first, iterator last) {
			size_type start = first - begin();
			size_type finish = last - begin();
			size_type offset = finish - start;

			_size -= offset;
			for (size_type i = start; i < _size; ++i) {
				_array[i] = _array[i + offset];
			}
			return _array + start;
		}

		void swap (vector& x) {
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
			std::swap(_array, x._array);
			std::swap(_alloc, x._alloc);
		}

		void clear() {
				for (iterator it = begin(); it != end(); it++)
					_alloc.destroy(&(*it));
				_size = 0;
		}

		// Allocator:
		A get_allocator() const { return _alloc; }

	private:
		A			_alloc;
		size_type	_capacity;
		size_type	_size;
		pointer		_array;
	};

	template < class T, class A >
	bool operator==( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template < class T, class A >
	bool operator!=( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { return !(lhs == rhs); }
	template < class T, class A >
	bool operator<( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template < class T, class A >
	bool operator>=( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { return !(lhs < rhs); }
	template < class T, class A >
	bool operator<=( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { return !(rhs < lhs); }
	template < class T, class A >
	bool operator>( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { return (rhs < lhs); }
	template < class T, class A >
	void swap( const ft::vector <T, A>& lhs, const ft::vector <T, A>& rhs ) { lhs.swap(rhs); }
}

#endif
