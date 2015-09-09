/*
 * nodeobject.h
 *
 *  Created on: 2015年9月8日
 *      Author: a11
 */

#ifndef NODEOBJECT_H_
#define NODEOBJECT_H_

template<class T>
class NodeObject {
public:
	T key;
	NodeObject* left;
	NodeObject* right;
};

#endif


