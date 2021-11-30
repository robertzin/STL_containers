#pragma once
#include <memory>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

template < class Key, class Compare = less<Key>,
	class Allocator = std::allocator<Key> >

class set
{
	public:
	
	typedef Key											key_type;
	typedef key_type									value_type;
	typedef Compare										key_compare;
	typedef key_compare									value_compare;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;

	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	// typedef implementation-defined                   	iterator;
	// typedef implementation-defined                   	const_iterator;
	// typedef std::reverse_iterator<iterator>          	reverse_iterator;
	// typedef std::reverse_iterator<const_iterator>    	const_reverse_iterator;
	
	// construct/copy/destroy:
	explicit set (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());
	
	template <class InputIterator>
	set (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());

	set (const set& x);

	~set() {}

	set& operator= (const set& x);

	// iterators:
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	// capacity:
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	// modifiers:
	pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);
	size_type erase (const value_type& val);
	void erase (iterator first, iterator last);

	void swap (set& x);
	void clear();

	// observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	// set operations:
	iterator find (const value_type& val) const;
	size_type count (const value_type& val) const;
	iterator lower_bound (const value_type& val) const;
	iterator upper_bound (const value_type& val) const;
	pair<iterator,iterator> equal_range (const value_type& val) const;
	
	// allocator
	allocator_type get_allocator() const;

};

	template< class Key, class Compare, class Alloc >
	bool operator==( const std::set<Key,Compare,Alloc>& lhs,
						const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
	bool operator!=( const std::set<Key,Compare,Alloc>& lhs,
						const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
	bool operator<( const std::set<Key,Compare,Alloc>& lhs,
						const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
	bool operator<=( const std::set<Key,Compare,Alloc>& lhs,
						const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
	bool operator>( const std::set<Key,Compare,Alloc>& lhs,
						const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
	bool operator>=( const std::set<Key,Compare,Alloc>& lhs,
						const std::set<Key,Compare,Alloc>& rhs );

	template< class Key, class Compare, class Alloc >
	void swap( std::set<Key,Compare,Alloc>& lhs, 
				std::set<Key,Compare,Alloc>& rhs );
}
