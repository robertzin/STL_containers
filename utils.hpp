#pragma once

namespace ft {
	template < class T, class A >
	class vector;

	template < bool, typename T = void >
	struct enable_if {};

	template < typename T >
	struct enable_if<true, T> { typedef T type; };

	template < class It1, class It2 >
	bool lexicographical_compare (It1 first1, It1 last1, It2 first2, It2 last2) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void)++first2 ) {
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class It1, class It2>
	bool equal(It1 first1, It1 last1, It2 first2) {
		for ( ; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template < class T, bool V >
	struct integral_constant {
		static const bool value = V;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template < class T > struct is_integral				: false_type {};
	template <> struct is_integral<bool>				: true_type {};
	template <> struct is_integral<char>				: true_type {};
	template <> struct is_integral<unsigned char>		: true_type {};
	template <> struct is_integral<signed char>			: true_type {};
	template <> struct is_integral<wchar_t>				: true_type {};
	template <> struct is_integral<short>				: true_type {};
	template <> struct is_integral<unsigned short>		: true_type {};
	template <> struct is_integral<int>					: true_type {};
	template <> struct is_integral<unsigned int>		: true_type {};
	template <> struct is_integral<long>				: true_type {};
	template <> struct is_integral<unsigned long>		: true_type {};
	template <> struct is_integral<long long>			: true_type {};
	template <> struct is_integral<unsigned long long>	: true_type {};
}

namespace std {
	template < class T, class A >
	void swap(ft::vector<T, A> &first, ft::vector<T, A> &second) { first.swap(second); }
}

