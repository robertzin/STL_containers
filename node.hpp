#ifndef NODE_HPP
# define NODE_HPP
# pragma once

namespace ft {

	template<class T>
	struct Node {

		public :
			typedef	T		value_type;
			value_type		*data;
			Node			*left;
			Node			*right;
			Node			*parent;
			int				height;
			int				bf;

		public :
			Node() : 					data(0), left(NULL), right(NULL), parent(NULL), height(0) {}
			Node(value_type val) :		data(val), left(NULL), right(NULL), height(0), parent(NULL) {}
			Node(const Node& other) :	data(other.data), left(other.left), right(other.right), height(other.height),
										bf(other.bf), parent(other.parent) {}

			~Node() {};
			Node& operator=(const Node& other) {
				if (this == &other)
					return *this;
				bf = other.bf;
				data = other.data;
				left = other.left;
				right = other.right;
				parent = other.parent;
				height = other.height;
				return (*this);
			}
	};

	template<class T>
	bool  operator== (const Node<T>&lhs, const Node<T>&rhs) {
		if (lhs->data == NULL && rhs->data == NULL)
			return true;
		return (lhs->data == rhs.data);
	}
	template<class T>
	bool operator!=(const Node<T>&lhs, const Node<T>&rhs) { return (!(lhs == rhs)); }

	template <class T>
	struct less : std::binary_function<T,T,bool> {
		bool operator() (const T& x, const T& y) const {
			return (x < y);
		}
	};
}

#endif
