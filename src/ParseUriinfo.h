/*
 * ParseUriinfo.h
 *
 *  Created on: 2015年8月13日
 *      Author: a11
 */

#ifndef PARSEURIINFO_H
#define PARSEURIINFO_H

#include <iostream>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <vector>
#include <exception>
#include <cstdlib>

using namespace std;
using namespace boost::xpressive;

class GanjiFdfsUriInfo {

public:

	double width;
	double height;
	string fileid;
	string ext;
	bool cut;
	bool fill;
	int quality;
	int version;

	string uri;

public:

	static const string URLPATTERNS_LIST[];
	static const string _KEYLIST[];
	GanjiFdfsUriInfo();
	static GanjiFdfsUriInfo parse(string);
	string toString();

};

#endif
