/*
 * binarytree.cc
 *
 *  Created on: 2015年9月8日
 *      Author: a11
 */
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

#include "binarytree.h"
#include "nodeobject.cc"

using namespace std;
/*******
 *
 * run pre_find by binary tree
 * 1,pre mid post
 *
 * 2,cacl by some ....
 *
 * *****/
//inline BinaryTree::BinaryTree() {
//}
void BinaryTree::postorder(nodeObject* node, vector<int>* collector) {
	if (node == NULL) {
		return;
	}
	postorder(node->left, collector);
	postorder(node->right, collector);
	collector->push_back(node->key);
}
void BinaryTree::preorder(nodeObject* node,vector<int>* collector) {
	if (node == NULL) {
		return ;
	}
	collector->push_back(node->key);
	preorder(node->left,collector);
	preorder(node->right,collector);
}
void BinaryTree::inorder(nodeObject* node, vector<int>* collector) {
	if (node == NULL) {
		return;
	}
	inorder(node->left, collector);
	collector->push_back(node->key);
	inorder(node->right, collector);
}

void BinaryTree::insertTreeNode(nodeObject *leaf, int key) {
	if (key < leaf->key) {
		if (leaf->left == NULL/*null*/) {
			//here
			leaf->left = new nodeObject;
			leaf->left->key = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		} else {
			insertTreeNode(leaf->left, key);
		}
	} else {
		if (leaf->right == NULL/*null*/) {
			//here
			leaf->right = new nodeObject;
			leaf->right->key = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		} else {
			insertTreeNode(leaf->right, key);
		}
	}

}

void BinaryTree::displaytree(nodeObject* p, int indent) {
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

