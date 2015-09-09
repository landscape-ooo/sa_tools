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

class BinaryTree {
public:
	//BinaryTree();
	void insertTreeNode(nodeObject*, int);


	void inorder(nodeObject*  ,vector<int>*);
	void preorder(nodeObject*  ,vector<int>*);

	void postorder(nodeObject*  ,vector<int>*);

	void displaytree(nodeObject* p, int indent);
	int getHeigth(nodeObject *current);
};


#endif
