/*
 * avltree.cc
 *
 *  Created on: 2015年9月8日
 *      Author: a11
 */
#ifndef AVLTREE_H_
#define AVLTREE_H_
#include "STLAvltree.h"
#include "binarytree.h"
class AvlTree
		:public BinaryTree
{
	public:
//	int getAvlTreeByNodelist(  vector<T>   const*);
	void getAvlTreeByNodelist(AVLTree *,vector<int>* );

	void displaytree(AVLTreeNode* p, int indent);
	
	AVLTreeNode *createNewNode(int key);
};


#endif
