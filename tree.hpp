#pragma once
#include "utils.hpp"

namespace ft {


	template <class Key, class Compare = std::less<Key>,
				class Allocator = std::allocator<Key> >
	class tree {
		// public:
		// 	ft::_NodePtr<Key> tmp;
		// 	ft::_NodePtr<Key> *root;
		// 	template <class _NodePtr>
		// 	bool __tree_is_left_child(_NodePtr *x) { return x == x->parent->left; }
		// 	unsigned __tree_sub_invariant(_NodePtr *x) {
		// 	if (x == nullptr)
		// 	return 1;
		// 	if (x->left != nullptr && x->left->parent != x) { return 0; }
		// 	if (x->right != nullptr && x->right->parent != x) { return 0; }
		// 	if (x->left == x->right && x->left != nullptr) { return 0; }
		// 	if (!x->isBlack) {
		// 	if (x->left && !x->left->isBlack) { return 0; }
		// 	if (x->right && !x->right->isBlack) { return 0; }
		// 	}
		// 	unsigned h = __tree_sub_invariant(x->left);
		// 	if (h == 0) { return 0; }
		// 	if (h != __tree_sub_invariant(x->right)) { return 0; }
		// 	return h + x->isBlack;
		// 	}

	};
}