/*
 * NewAvlTree.h
 *@see https://tfetimes.com/c-avl-tree/
 *  Created on: 2015年9月9日
 *      Author: a11
 */

#include <algorithm>
#include <iostream>
#include <iomanip>

#include "NodeObject.h"

using namespace std;

template<class T>
class AVLnode :public NodeObject<T> {
public:
	T key;
	int balance;
	AVLnode *left, *right, *parent;

	AVLnode(T k, AVLnode *p) :
			key(k), balance(0), parent(p), left(NULL), right(NULL) {
	}

	~AVLnode() {
		delete left;
		delete right;
	}
};

/* AVL tree */
template<typename T>
class AVLtree {
public:
	AVLtree(void);
	~AVLtree(void);
	bool insert(T key);
	void deleteKey(const T key);
	void printBalance();
	void displaytree(AVLnode<T>* , int );

	AVLnode<T> *root;
private:

	AVLnode<T>* rotateLeft(AVLnode<T> *a);
	AVLnode<T>* rotateRight(AVLnode<T> *a);
	AVLnode<T>* rotateLeftThenRight(AVLnode<T> *n);
	AVLnode<T>* rotateRightThenLeft(AVLnode<T> *n);
	void rebalance(AVLnode<T> *n);
	int height(AVLnode<T> *n);
	void setBalance(AVLnode<T> *n);
	void printBalance(AVLnode<T> *n);
	void clearNode(AVLnode<T> *n);
};

/* AVL class definition */
template<typename T>
void AVLtree<T>::rebalance(AVLnode<T> *n) {
	setBalance(n);

	if (n->balance == -2) {
		if (height(n->left->left) >= height(n->left->right))
			n = rotateRight(n);
		else
			n = rotateLeftThenRight(n);
	} else if (n->balance == 2) {
		if (height(n->right->right) >= height(n->right->left))
			n = rotateLeft(n);
		else
			n = rotateRightThenLeft(n);
	}

	if (n->parent != NULL) {
		rebalance(n->parent);
	} else {
		root = n;
	}
}

template<typename T>
AVLnode<T>* AVLtree<T>::rotateLeft(AVLnode<T> *a) {
	AVLnode<T> *b = a->right;
	b->parent = a->parent;
	a->right = b->left;

	if (a->right != NULL)
		a->right->parent = a;

	b->left = a;
	a->parent = b;

	if (b->parent != NULL) {
		if (b->parent->right == a) {
			b->parent->right = b;
		} else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template<typename T>
AVLnode<T>* AVLtree<T>::rotateRight(AVLnode<T> *a) {
	AVLnode<T> *b = a->left;
	b->parent = a->parent;
	a->left = b->right;

	if (a->left != NULL)
		a->left->parent = a;

	b->right = a;
	a->parent = b;

	if (b->parent != NULL) {
		if (b->parent->right == a) {
			b->parent->right = b;
		} else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template<typename T>
AVLnode<T>* AVLtree<T>::rotateLeftThenRight(AVLnode<T> *n) {
	n->left = rotateLeft(n->left);
	return rotateRight(n);
}

template<typename T>
AVLnode<T>* AVLtree<T>::rotateRightThenLeft(AVLnode<T> *n) {
	n->right = rotateRight(n->right);
	return rotateLeft(n);
}

template<typename T>
int AVLtree<T>::height(AVLnode<T> *n) {
	if (n == NULL)
		return -1;
	return 1 + std::max(height(n->left), height(n->right));
}

template<typename T>
void AVLtree<T>::setBalance(AVLnode<T> *n) {
	n->balance = height(n->right) - height(n->left);
}

template<typename T>
void AVLtree<T>::printBalance(AVLnode<T> *n) {
	if (n != NULL) {
		printBalance(n->left);
		std::cout << n->balance << " ";
		printBalance(n->right);
	}
}

template<typename T>
AVLtree<T>::AVLtree(void) :
		root(NULL) {
}

template<typename T>
AVLtree<T>::~AVLtree(void) {
	delete root;
}

template<typename T>
bool AVLtree<T>::insert(T key) {
	if (root == NULL) {
		root = new AVLnode<T>(key, NULL);
	} else {
		AVLnode<T> *n = root, *parent;

		while (true) {
			if (n->key == key)
				return false;

			parent = n;

			bool goLeft = n->key > key;
			n = goLeft ? n->left : n->right;

			if (n == NULL) {
				if (goLeft) {
					parent->left = new AVLnode<T>(key, parent);
				} else {
					parent->right = new AVLnode<T>(key, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

template<typename T>
void AVLtree<T>::deleteKey(const T delKey) {
	if (root == NULL)
		return;

	AVLnode<T> *n = root, *parent = root, *delNode = NULL, *child = root;

	while (child != NULL) {
		parent = n;
		n = child;
		child = delKey >= n->key ? n->right : n->left;
		if (delKey == n->key)
			delNode = n;
	}

	if (delNode != NULL) {
		delNode->key = n->key;

		child = n->left != NULL ? n->left : n->right;

		if (root->key == delKey) {
			root = child;
		} else {
			if (parent->left == n) {
				parent->left = child;
			} else {
				parent->right = child;
			}

			rebalance(parent);
		}
	}
}

template<typename T>
void AVLtree<T>::printBalance() {
	printBalance(root);
	std::cout << std::endl;
}


template<typename T>
void AVLtree<T>::displaytree(AVLnode<T>* p, int indent) {
	if (p != NULL) {
		if (p->right) {
			displaytree(p->right, indent + 4);
		}
		if (indent) {
			cout << setw(indent) << ' ';
		}
		if (p->right)
			cout << " /\n" << setw(indent) << ' ';
		cout << p->key << "\n ";
		if (p->left) {
			cout << setw(indent) << ' ' << " \\\n";
			displaytree(p->left, indent + 4);
		}
	}
}


