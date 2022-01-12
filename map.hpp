#ifndef MAP_HPP
# define MAP_HPP
# pragma once
# include <algorithm>
# include "vector.hpp"
# include "tree.hpp"
# include "utils.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {

		public:
			typedef				Key										key_type;
			typedef				T										mapped_type;
			typedef				Compare									key_compare;
			typedef 			ft::pair< const key_type, mapped_type >	value_type;

			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::pointer					pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::size_type				size_type;
			typedef typename	allocator_type::difference_type			difference_type;

			typedef 			ft::tree<value_type, Compare, Alloc>							tree;
			typedef typename	ft::tree<value_type, Compare, Alloc>::Node						node;
			typedef typename	ft::tree<value_type, Compare, Alloc>::iterator					iterator;
			typedef typename	ft::tree<value_type, Compare, Alloc>::const_iterator			const_iterator;
			typedef typename	ft::tree<value_type, Compare, Alloc>::reverse_iterator			reverse_iterator;
			typedef typename	ft::tree<value_type, Compare, Alloc>::const_reverse_iterator	const_reverse_iterator;

			class value_compare : public std::binary_function<value_type, value_type, bool> {
				friend class map;
				protected:
					key_compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					typedef bool	result_type;
					typedef			value_type	first_argument_type;
					typedef			value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};

			// constructors
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _cmp(comp) {}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _cmp(comp) {
				insert(first, last);
			}
			map (const map& x) : _tree(x._tree), _alloc(x._alloc), _cmp(x._cmp) {}
			~map() {}
			map& operator= (const map& x)
			{
				_alloc = x._alloc;
				_cmp = x._cmp;
				_tree = _tree.assign(x._tree);
				return (*this);
			}

			// Iterators:
			iterator begin() 						{ return _tree.begin(); }
			const_iterator begin() const			{ return _tree.begin(); }
			reverse_iterator rbegin()				{ return _tree.rbegin(); }
			const_reverse_iterator rbegin() const	{ return _tree.rbegin(); }

			iterator end()							{ return _tree.end(); }
			const_iterator end() const				{ return _tree.end(); }
			reverse_iterator rend()					{ return _tree.rend(); }
			const_reverse_iterator rend() const		{ return _tree.rend(); }

	// 		// Capacity:
			bool empty() const						{ return _tree.empty();}
			size_type size() const					{ return _tree.size();}
			size_type max_size() const				{ return _tree.max_size(); }

	// 		// Element access:
			mapped_type& operator[] (const key_type& k) {
				if (_tree.find(k) == NULL)
					return (insert(ft::make_pair(k, mapped_type())).first)->second;
				return (_tree.find(k)->data->second);
			}

	// 		// Observers:
			key_compare key_comp() const { return (_cmp); }
			value_compare value_comp() const { return (value_compare(_cmp));}

	// 		// Modifiers:
			ft::pair<iterator, bool> insert(const value_type& x) {
				bool sec = _tree.insert(x);
				iterator first = iterator(_tree.find(x.first), &_tree);
				ft::pair<iterator, bool> ret = ft::make_pair(first, sec);
				return (ret);
			}
			iterator insert(iterator position, const value_type& x) {
				(void)position;
				_tree.insert(x);
				return (iterator(_tree.find(x.first), &_tree));
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; first++)
					_tree.insert(*first);
				return ;
			}

			void erase(iterator position) {
				key_type x = position->first;
				_tree.remove(x);
				return ;
			}

			size_type erase(const key_type& x) { return (_tree.remove(x)); }

			void erase (iterator first, iterator last) {
				while (first != last)
					this->erase((*(first++)).first);
			}
			void swap(map& x) {
				tree	tmp_tree;
				tmp_tree = x._tree;
				x._tree = _tree;
				_tree = tmp_tree;
				return ;
			}

			void clear() { _tree.deletetree(); }

	// 		// Operations:
			iterator find(const key_type& x)					{ return (iterator(_tree.find(x),&_tree)); }
			const_iterator find(const key_type& x) const		{ return (iterator(_tree.find(x), &_tree)); }
			size_type count(const key_type& x) const			{ return (_tree.contains(x)); }
			iterator lower_bound(const key_type& x)	{
				iterator beg = this->begin();
				iterator end = this->end();
				while (beg != end) {
					if (!_cmp(beg->first, x)) { break; }
					beg++;
				}
				return (beg);
			}
			const_iterator lower_bound(const key_type& x) const	{
				const_iterator beg = this->begin();
				const_iterator end = this->end();
				while (beg != end) {
					if (!_cmp(beg->first, x)) { break; }
					beg++;
				}
				return (beg);
			}
			iterator upper_bound(const key_type& x) {
				iterator beg = this->begin();
				iterator end = this->end();
				while (beg != end) {
					if (_cmp(x, beg->first)) { break; }
					beg++;
				}
				return (beg);
			}
			const_iterator upper_bound(const key_type& x) const	{
				const_iterator beg = this->begin();
				const_iterator end = this->end();
				while (beg != end) {
					if (_cmp(x, beg->first)) { break; }
					beg++;
				}
				return (beg);
			}

			ft::pair<iterator,iterator> equal_range(const key_type& x) {
				return ft::make_pair(lower_bound(x), upper_bound(x));
			}
			ft::pair<const_iterator,const_iterator> equal_range(const key_type& x) const {
				return ft::make_pair(lower_bound(x), upper_bound(x));
			}

			allocator_type get_allocator() const { return (_tree.get_allocator()); }

		private :
			tree			_tree;
			allocator_type	_alloc;
			key_compare		_cmp;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return (lhs.size() == rhs.size());
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator> ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=  ( const map<Key,T,Compare,Alloc>& lhs,  const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs > rhs || lhs == rhs)
			return (true);
		return (false);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,  const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs  < rhs || lhs == rhs)
			return (true);
		return (false);
	}
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) { x.swap(y); }

	}

#endif
