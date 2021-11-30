#pragma once
#include "iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class map {

		public:
			typedef 			Key										key_type;
			typedef 			T										mapped_type;
			typedef 			Compare									key_compare;
			typedef 			Allocator								allocator_type;
			typedef typename 	std::pair<const Key, T>					value_type;
			typedef typename 	std::size_t								size_type;
			typedef typename 	std::ptrdiff_t							difference_type;
			typedef typename 	Allocator::pointer						pointer;
			typedef typename 	Allocator::const_pointer				const_pointer;
			typedef 			value_type&								reference;
			typedef 			const value_type&						const_reference;
			typedef 			ft::iterator<T*>						iterator;
			typedef 			ft::iterator<const T*>					const_iterator;
			typedef 			ft::reverse_iterator<iterator>			reverse_iterator;
			typedef 			ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			
	};
}