/*
 * avltree.cc
 *
 *  Created on: 2015年9月8日
 *      Author: a11
 */
#include <vector>
#include "avltree.h"

void AvlTree::getAvlTreeByNodelist(AVLTree *theAVLTree,vector<int>* current) {
	vector<int>::iterator it;
	for (it = current->begin(); it != current->end(); it++) {
		cout<<"---->"<<*it<<endl;
		int item=*it;
		theAVLTree->Insert(createNewNode(item));
	}
	cout<<"end"<<endl;
//	    for (it = current->begin();
//	      it!=current->end();
//	      it++) {
//	        cout<<"--->"<<*it<<endl;
//	    }



	//print
//	displaytree(theAVLTree->root,20);
}

void AvlTree::displaytree(AVLTreeNode* p, int indent) {


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


//---------------------------------------------
// Create a new tree node with the given key
//---------------------------------------------

AVLTreeNode* AvlTree::createNewNode(int key)
{
   AVLTreeNode *temp = new AVLTreeNode();
   temp->key = key;
   temp->left = NULL;
   temp->right = NULL;
   temp->parent = NULL;
   temp->balanceFactor = '=';
   return temp;
}
