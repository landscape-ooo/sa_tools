/*
* unittest.cc
*
*  Created on: 2015年9月9日
*      Author: a11
*/



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

                #include "NodeObject.h"
                #include "Binarytree.h"
                #include "AVLtreeImp.h"









                NodeObject<int>* contructSampleTree() {
                    BinaryTree<int>* obj=new BinaryTree<int>;

                        NodeObject<int>* root = new NodeObject<int>;
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
                                        void testBinarytree() {
                                        BinaryTree<int> obj;
                                        NodeObject<int>* root = contructSampleTree();
                                            cout << "root=====" << root->key << endl;

                                                obj.displaytree(root, 15);

                                                vector<int>* cl = new vector<int>;
                                                    obj.preorder(root, cl);
                                                    for (vector<int>::iterator it = cl->begin(); it != cl->end(); ++it) {
                                                        cout << "-->" << *it << endl;
                                                            }
                                                            cout << cl->size() << endl;
                                                                }


                                                                void testAvltree(){
                                                                AVLtree<int>* obj=new AVLtree<int>;
                                                                    NodeObject<int>* root = contructSampleTree();


                                                                        BinaryTree<int>* obj_b=new BinaryTree<int>;
                                                                            vector<int>* nodelist_order=new vector<int>;
                                                                                obj_b->inorder(root,nodelist_order);


                                                                                vector<int>::iterator it ;
                                                                                    for(it=nodelist_order->begin();it!=nodelist_order->end();++it){
                                                                                    obj->insert(*it);
                                                                                    }

                                                                                    obj->displaytree(obj->root,20);
                                                                                    }








                                                                                    int main() {
                                                                                    testBinarytree();
                                                                                    testAvltree();

                                                                                    }
