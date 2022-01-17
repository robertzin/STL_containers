#ifndef TREE_HPP
# define TREE_HPP
# pragma once
# include "iterator.hpp"
# include "node.hpp"
# include "utils.hpp"

namespace ft {

	template <class T, class Compare = std::less<typename T::first_type>,
		class Alloc = std::allocator<T> >
	class tree
	{

		public:
			typedef 			T												value_type;
			typedef 			Alloc											pair_alloc;
			typedef typename	Alloc::template rebind<ft::Node< T > >::other	node_alloc;
			typedef typename 	Alloc::size_type								size_type;
			typedef typename 	Alloc::difference_type							difference_type;
			typedef typename	value_type::first_type							key;
			typedef typename	value_type::second_type							value;

			typedef				ft::Node<value_type>							Node;
			typedef				ft::map_iterator<T, Node>						iterator;
			typedef				ft::map_iterator<const T, const Node>			const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		public:
			tree() : _root(NULL), _size(0) {}
			tree(const tree &x) : _root(NULL) { *this = assign(x); }
			~tree() {}
			
			tree& assign(tree const& other) {
				deletetree();
				_pair_alloc = other._pair_alloc;
				_node_alloc = other._node_alloc;
				_comp = other._comp;
				for (const_iterator it = other.begin(); it != other.end(); it++)
					insert(*it);
				_size = other._size;
				return *this;
			}

			void copy_assign_alloc(const tree& t) {
			if (_node_alloc != t._node_alloc)
				deletetree();
			_node_alloc = t._node_alloc;
			}

			size_type size() const { return (_size); }

			bool empty() const { return (_size == 0); }

			void deletetree() {
				_root = _deletetree(_root);
				_size = 0;
			}
			Node * _deletetree(Node * node) {
				if (node != NULL) {
					_deletetree(node->left);
					_deletetree(node->right);
					deleteNode(node);
				}
				return NULL;
			}
		void deleteNode(Node * node) {
			_pair_alloc.destroy(node->data);
			_pair_alloc.deallocate(node->data, 1);
			node->data = NULL;
			_node_alloc.deallocate(node, 1);
			node = NULL;
			// _size--;
		}
		iterator begin() {
			Node *tmp = find(findMin(_root).first);
			return (iterator(tmp, _root));
		}
		const_iterator begin() const {
			Node *tmp = find(findMin(_root).first);
			return (iterator(tmp, _root));
		}
		iterator end() { return (iterator(NULL, _root)); }
		const_iterator end() const { return (iterator(NULL, _root)); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		Node* newNode(T obj) {
			Node* node = _node_alloc.allocate(1);
			_node_alloc.construct(node);
			node->data = _pair_alloc.allocate(1);
			_pair_alloc.construct(node->data, obj);
			return (node);
		}

		int height() {
			if (_root == NULL)
				return (0);
			return (height(_root) - 1);
		}

		bool contains(key &k) const { return (contains(_root, k)); }

		bool insert(T value) {
			if (!contains(_root, value.first)) {
				_root = insert(_root, value);
				_root->parent = NULL;
				_size++;
				return true;
			}
			return false;
		}

		bool remove(key &val) {
			bool c = contains(_root, val);
			if (c) {
				_root = remove(_root, val);
				_size--;
				return true;
			}
			return false;
		}

		Node* find(key val) {
			if (contains(_root, val))
				return (find(_root, val));
			return NULL;
		}
		Node* find(key val) const {
			if (contains(_root, val))
				return (find(_root, val));
			return NULL;
		}
		size_type max_size() const { return std::min<size_type>(std::allocator_traits<node_alloc>::max_size(node_alloc()), std::numeric_limits<difference_type >::max()); }
		// size_type max_size() const { return _node_alloc.max_size(); }
		node_alloc get_allocator() const { return _node_alloc; }
		Node* getRoot( void ) const { return _root; }
		Node* findm(Node* node) {
			Node *current = node;
			while (current && current->left != NULL)
				current = current->left;
			return (current);
		}
		Node* findm(Node* node) const {
			while (node && node->left != NULL)
				node = node->left;
			return (node);
		}
		Node* findM(Node* node) {
			while (node && node->right != NULL)
				node = node->right;
			return (node);
		}
		Node* findM(Node* node) const {
			while (node && node->right != NULL)
				node = node->right;
			return (node);
		}
		const Node* findm(const Node* node) const {
			while (node && node->left != NULL)
				node = node->left;
			return (node);
		}
		const Node* findM(const Node* node) const {
			while (node && node->right != NULL)
				node = node->right;
			return (node);
		}

	private:
		int height(Node* node) {
			if (node == NULL)
				return -1;
			int leftHeight = height(node->left) + 1;
			int rightHeight = height(node->right) + 1;
			if (leftHeight > rightHeight)
				return leftHeight;
			return rightHeight;
		}

		bool contains(Node* node, key k) const {
			if (node == NULL) { return false; }
			bool cmp = _comp(node->data->first, k); // first < k
			bool cmp1 = _comp(k, node->data->first); // k < first
			if (!cmp1 && !cmp)
				return true;
			if (!cmp)
				return (contains(node->left, k));
			if (cmp)
				return (contains(node->right, k));
			return true;
		}

		Node* insert(Node* node, T val) {
			if (node == NULL)
				return (newNode(val));
			bool cmp = _comp(val.first, node->data->first);
			if (cmp) {
				node->left = insert(node->left, val);
				node->left->parent = node;
			}
			else if (!cmp) {
				node->right = insert(node->right, val);
				node->right->parent = node;
			}
			update(node);
			return (balance(node));
		}

		void update(Node* node) {
			int leftNodeHeight = (node->left == NULL) ? -1 : node->left->height;
			int rightNodeHeight = (node->right == NULL) ? -1 : node->right->height;
			node->height = 1 + std::max(leftNodeHeight, rightNodeHeight);
			node->bf = rightNodeHeight - leftNodeHeight;
		}

		Node* balance(Node* node) {
			if (node->bf == -2) {
				if (node->left->bf <= 0)
					return leftleftCase(node);
				else
					return leftrightCase(node);
			}
			else if (node->bf == 2) {
				if (node->right->bf >= 0)
					return rightrightCase(node);
				else
					return rightleftCase(node);
			}
			return node;
		}

		Node* leftleftCase(Node* node) { return rightRotation(node); }
		Node* leftrightCase(Node* node) {
			node->left = leftRotation(node->left);
			return leftleftCase(node);
		}
		Node* rightrightCase(Node* node) { return leftRotation(node); }
		Node* rightleftCase(Node* node) {
			node->right = rightRotation(node->right);
			return rightrightCase(node);
		}

		Node* leftRotation(Node* node) {
			Node* tmp = node->right;
			node->right = tmp->left;
			tmp->left = node;
			_resetParent(node, tmp);
			update(node);
			update(tmp);
			return tmp;
		}
		Node* rightRotation(Node* node) {
			Node* tmp = node->left;
			node->left = tmp->right;
			tmp->right = node;
			_resetParent(node, tmp);
			update(node);
			update(tmp);
			return tmp;
		}

		void _resetParent(Node* oldRoot, Node* newRoot) const {
			if (!oldRoot->parent) {
				newRoot->parent = NULL;
				if (oldRoot->left)
					oldRoot->left->parent = oldRoot;
				if (oldRoot->right)
					oldRoot->right->parent = oldRoot;
				oldRoot->parent = newRoot;
				return;
			}
			newRoot->parent = oldRoot->parent;
			oldRoot->parent = newRoot;
			if (oldRoot->left)
				oldRoot->left->parent = oldRoot;
			if (oldRoot->right)
				oldRoot->right->parent = oldRoot;
		}

		Node* remove(Node* node, key val) {

			if (node == NULL)
				return NULL;
			int cmp = _comp(val, node->data->first); // val < first
			bool cmp1 = _comp(node->data->first, val); // first < val
			if (!cmp && !cmp1) {
				if (node->left == NULL || node->right == NULL) {
					Node *temp = node->left ? node->left : node->right;
					return temp;
				}
				else {
					Node* temp = findm(node->right);
					node->data = temp->data;
					node->right = remove(node->right, temp->data->first);
				}
			}
			else if (cmp)
				node->left = remove(node->left, val);
			else if (!cmp)
				node->right = remove(node->right, val);
			update(node);
			return balance(node);
		}

		Node* find(Node* node, key val) {
			if (node == NULL)
				return NULL;
			bool cmp = _comp(node->data->first, val);
			bool cmp1 = _comp(val, node->data->first);
			if (!cmp && !cmp1)
				return node;
			if (!cmp)
				return (find(node->left, val));
			else if (cmp)
				return (find(node->right, val));
			return node;
		}

		Node* find(Node* node, key val) const {
			if (node == NULL)
				return NULL;
			bool cmp = _comp(node->data->first, val);
			bool cmp1 = _comp(val, node->data->first);
			if (!cmp && !cmp1)
				return node;
			if (!cmp)
				return (find(node->left, val));
			else if (cmp)
				return (find(node->right, val));
			return node;
		}

		value_type findMin(Node* node) {
			if (node == NULL)
				return (ft::make_pair(key(), value()));
			while (node->left != NULL)
				node = node->left;
			return (*(node->data));
		}
		value_type findMax(Node* node) {
			if (node == NULL)
				return (ft::make_pair(key(), value()));
			while (node->right != NULL)
				node = node->right;
			return (*(node->data));
		}
		value_type findMin(Node* node) const {
			if (node == NULL)
				return (ft::make_pair(key(), value()));
			while (node->left != NULL)
				node = node->left;
			return (*(node->data));
		}
		value_type findMax(Node* node) const {
			if (node == NULL)
				return (ft::make_pair(key(), value()));
			while (node->right != NULL)
				node = node->right;
			return (*(node->data));
		}


		private:
			Node			*_root;
			node_alloc		_node_alloc;
			pair_alloc		_pair_alloc;
			size_type		_size;
			Compare			_comp;
	};
}

#endif
