#pragma once

	template <class Key>
	struct node {
		enum nodecolor	{ RED, BLACK };
		_NodePtr() : color(RED),
							parent(NULL),
							left(NULL),
							right(NULL),
							key(key) {}
		nodecolor	color;
		struct node	*parent;
		struct node	*left;
		struct node	*right;
		bool		isBlack;
		bool		isRed;
		Key			key;
	};