/*
 * binarytree.cc
 *
 *  Created on: 2015年9月8日
 *      Author: a11
 */
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

#include "NodeObject.h"

using namespace std;
/*******
 *
 * run pre_find by binary tree
 * 1,pre mid post
 *
 * 2,cacl by some ....
 *
 * *****/

template<typename T>
class BinaryTree {
public:
	//BinaryTree();
	void insertTreeNode(NodeObject<T>*, int);


	void inorder(NodeObject<T>*  ,vector<int>*);
	void preorder(NodeObject<T>*  ,vector<int>*);

	void postorder(NodeObject<T>*  ,vector<int>*);

	void displaytree(NodeObject<T>* p, int indent);
	int getHeigth(NodeObject<T> *current);
};



template<typename T>
void BinaryTree<T>::postorder(NodeObject<T>* node, vector<int>* collector) {
	if (node == NULL) {
		return;
	}
	postorder(node->left, collector);
	postorder(node->right, collector);
	collector->push_back(node->key);
}

template<typename T>
void BinaryTree<T>::preorder(NodeObject<T>* node,vector<int>* collector) {
	if (node == NULL) {
		return ;
	}
	collector->push_back(node->key);
	preorder(node->left,collector);
	preorder(node->right,collector);
}

template<typename T>
void BinaryTree<T>::inorder(NodeObject<T>* node, vector<int>* collector) {
	if (node == NULL) {
		return;
	}
	inorder(node->left, collector);
	collector->push_back(node->key);
	inorder(node->right, collector);
}

template<typename T>
void BinaryTree<T>::insertTreeNode(NodeObject<T> *leaf, int key) {
	if (key < leaf->key) {
		if (leaf->left == NULL/*null*/) {
			//here
			leaf->left = new NodeObject<T>;
			leaf->left->key = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		} else {
			insertTreeNode(leaf->left, key);
		}
	} else {
		if (leaf->right == NULL/*null*/) {
			//here
			leaf->right = new NodeObject<T>;
			leaf->right->key = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		} else {
			insertTreeNode(leaf->right, key);
		}
	}

}

template<typename T>
void BinaryTree<T>::displaytree(NodeObject<T>* p, int indent) {
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
#endif
