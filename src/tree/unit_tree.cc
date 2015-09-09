/*
 * unit_tree.cc
 *
 *  Created on: 2015年9月8日
 *      Author: a11
 */
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

#include "binarytree.h"
#include "avltree.h"
#include "nodeobject.cc"









nodeObject* contructSampleTree() {
	BinaryTree* obj=new BinaryTree;

	nodeObject* root = new nodeObject;
	root->key = 6;
	root->left = NULL;
	root->right = NULL;

	const int length = 30;

	int ar[length];
	srand(time(0)); // use current time as seed for random generator
	for (int i = 0; i < length; i++) {
		int random_variable = rand();
		ar[i] = random_variable % 100;
	}

	vector<int> dataset(ar,ar+length);
	std::sort(dataset.begin(), dataset.end());
	std::vector<int>::iterator last = std::unique(dataset.begin(), dataset.end());
	dataset.erase(last, dataset.end());


	for (const auto& i : dataset){
	      obj->insertTreeNode(root, i);
	      std::cout << i << " ";
	}
	std::cout << "-----\n";


	return root;
}
//
//
//
//
//void testBinarytree() {
//	BinaryTree obj;
//	nodeObject* root = contructSampleTree();
//	cout << "root=====" << root->key << endl;
//
//	obj.displaytree(root, 15);
//
//	vector<int>* cl = new vector<int>;
//	obj.preorder(root, cl);
//	for (vector<int>::iterator it = cl->begin(); it != cl->end(); ++it) {
//		cout << "-->" << *it << endl;
//	}
//	cout << cl->size() << endl;
//}
void testAvltree(){
	AvlTree* obj=new AvlTree();
	vector<int>* nodelist_order=new vector<int>;
//	vector<int>* s=new vector<int>;

	//
	nodeObject* root = contructSampleTree();
	obj->inorder(root,nodelist_order);
//
//
	cout<<"size is "<<nodelist_order->size()<<endl;

	AVLTree *theAVLTree;
	theAVLTree = new AVLTree();

	obj->getAvlTreeByNodelist(theAVLTree,   nodelist_order);

	obj->displaytree(theAVLTree->root,20);
	//cout<<obj->getAvlTreeByNodelist(nodelist_order)<<endl;
}








int main() {
//	testBinarytree();
	testAvltree();

}
