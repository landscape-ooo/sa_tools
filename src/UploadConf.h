/*
 * UploadConf.cc
 *
 *  Created on: 2015年8月19日
 *      Author: a11
 */
#ifndef UPLOADCONF_CC_
#define UPLOADCONF_CC_
#include <iostream>
#include <map>
using namespace std;
#include <string>
#include <boost/assign/list_of.hpp>
#include <boost/foreach.hpp>
using boost::assign::map_list_of;

typedef map<string, map<int, int> > FDFS_Str_II_TYPE;
typedef map<int, int> FDFS_II_TYPE;
typedef map<int, string> FDFS_IStr_TYPE;


class WatermarkerUploadConf{
public :
	static const map<int,string> WATERMARKS ;

	static const  map<string, FDFS_II_TYPE > CATEGORYS ;
	static const map<string, map<int, int> > DUANZU_CATEGORYS;
	static const map<int,int> JPG_QUALITY ;
};


#endif /* UPLOADCONF_CC_ */
