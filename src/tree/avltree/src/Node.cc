/*
 * Node.h
 *
 *  Created on: 2015年9月9日
 *      Author: a11
 */

/* AVL node */
#include <algorithm>
#include <iostream>

template <class T>
class AVLnode {
public:
	T key;
	int balance;
	AVLnode *left, *right, *parent;

	AVLnode(T k, AVLnode *p) : key(k), balance(0), parent(p),
	left(NULL), right(NULL) {}

	~AVLnode() {
		delete left;
		delete right;
	}
};


