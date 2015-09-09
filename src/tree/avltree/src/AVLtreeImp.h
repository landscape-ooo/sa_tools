/*
 * NewAvlTree.h
 *
 *  Created on: 2015年9月9日
 *      Author: a11
 */
#include <algorithm>
#include <iostream>

#include "Node.cc"


/* AVL tree */
template <class T>
class AVLtree {
public:
	AVLtree(void);
	~AVLtree(void);
	bool insert(T key);
	void deleteKey(const T key);
	void printBalance();

private:
	AVLnode<T> *root;

	AVLnode<T>* rotateLeft          ( AVLnode<T> *a );
	AVLnode<T>* rotateRight         ( AVLnode<T> *a );
	AVLnode<T>* rotateLeftThenRight ( AVLnode<T> *n );
	AVLnode<T>* rotateRightThenLeft ( AVLnode<T> *n );
	void rebalance                  ( AVLnode<T> *n );
	int height                      ( AVLnode<T> *n );
	void setBalance                 ( AVLnode<T> *n );
	void printBalance               ( AVLnode<T> *n );
	void clearNode                  ( AVLnode<T> *n );
};

