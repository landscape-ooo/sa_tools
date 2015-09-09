/*
 * test_tree.cc
 *
 *  Created on: 2015年8月28日
 *      Author: a11
 */
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;
/*******
 *
 * run pre_find by binary tree
 * 1,pre mid post
 *
 * 2,cacl by some ....
 *
 * *****/
struct nodeObject {
	int name;
	nodeObject* left;
	nodeObject* right;
};
class BtreeArightmatic {
public:
	vector<nodeObject> treeNodeList;
	stack<nodeObject*> _tree;
public:
	BtreeArightmatic();
	BtreeArightmatic(vector<nodeObject>);
	void insertTreeNode(nodeObject*, int);
	/**
	 * sample 0-100 random datatree
	 */
	nodeObject* contructSampleTree();


	void displaytree(nodeObject* p, int indent);
	void inorder(nodeObject* root,vector<int>*);
	void preorder(nodeObject* root,vector<int>*);
	void postorder(nodeObject* root,vector<int>*);

	int getNodecounter(nodeObject *root);
};

inline BtreeArightmatic::BtreeArightmatic() {
	stack<nodeObject*> treelist;
	this->_tree = treelist;
}

inline BtreeArightmatic::BtreeArightmatic(vector<nodeObject> allocator) {
	stack<nodeObject*> treelist;
	this->_tree = treelist;
}
inline void BtreeArightmatic::postorder(nodeObject* node,vector<int>* collector) {
	if (node == NULL) {
		return ;
	}
	preorder(node->left,collector);
	preorder(node->right,collector);
	collector->push_back(node->name);
}
inline void BtreeArightmatic::preorder(nodeObject* node,vector<int>* collector) {
	if (node == NULL) {
		return ;
	}
	collector->push_back(node->name);
	preorder(node->left,collector);
	preorder(node->right,collector);
}
inline void BtreeArightmatic::inorder(nodeObject* node,vector<int>* collector) {
	if (node == NULL) {
		return ;
	}
	inorder(node->left,collector);
	collector->push_back(node->name);
	inorder(node->right,collector);
}
void BtreeArightmatic::insertTreeNode(nodeObject *leaf,
		int key) {
	if(key<leaf->name){
		if(leaf->left==NULL/*null*/){
			//here
			leaf->left=new nodeObject;
			leaf->left->name=key;
			leaf->left->left=NULL;
			leaf->left->right=NULL;
		}else{
			insertTreeNode(leaf->left,key);
		}
	}else{
		if (leaf->right==NULL/*null*/) {
			//here
			leaf->right=new nodeObject;
			leaf->right->name=key;
			leaf->right->left=NULL;
			leaf->right->right=NULL;
		} else {
			insertTreeNode(leaf->right, key);
		}
	}

}

void BtreeArightmatic::displaytree(nodeObject* p, int indent)
{
    if(p != NULL) {
        if(p->right) {
            displaytree(p->right, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (p->right) cout<<" /\n" << setw(indent) << ' ';
        cout<< p->name << "\n ";
        if(p->left) {
            cout << setw(indent) << ' ' <<" \\\n";
            displaytree(p->left, indent+4);
        }
    }
}

/**
 *@source
 * 	http://images.cnitblog.com/blog/441348/201301/07113506-aa51aed49a8849be9f751f37647b0714.jpg
 *
 */
inline nodeObject* BtreeArightmatic::contructSampleTree() {
	const int length=30;

	int ar[length];
	srand(time(0)); // use current time as seed for random generator
	for(int i=0;i<length;i++){
		int random_variable = rand();
		ar[i]=random_variable%100;
	}
	nodeObject* root;
	root = new nodeObject;
	root->name = 6;
	root->left = NULL;
	root->right = NULL;
	for (int i = 1; i < length; i++) {
		insertTreeNode(root, ar[i]);
	}
	insertTreeNode(root, 27);
	insertTreeNode(root, 37);
	insertTreeNode(root, 98);
	insertTreeNode(root, 96);

	return root;
}

int main() {
	BtreeArightmatic obj;
	nodeObject* root=obj.contructSampleTree();

	cout<<"root====="<<root->name<<endl;

	obj.displaytree(root,15);

	vector<int>* cl = new vector<int>;
	obj.postorder(root,cl);
	for(vector<int>::iterator it=cl->begin();it!=cl->end();++it  ){
		cout<<"-->"<<*it<<endl;
	}

	cout<<cl->size()<<endl;
}

inline int BtreeArightmatic::getNodecounter(nodeObject* root) {

}
