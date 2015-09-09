/*
 * unit_Uploadconf.cc
 *
 *  Created on: 2015年8月20日
 *      Author: a11
 */
#include "../UploadConf.h"

typedef map<string, map<int, int> > SSSSS;
typedef map<int, int> S2;
typedef map<int, string> S3;
int main() {
	BOOST_FOREACH( S3::value_type ch, WatermarkerUploadConf::WATERMARKS ) {
		cout << ch.second << "----" << endl;
	}

	BOOST_FOREACH(SSSSS::value_type item_v,WatermarkerUploadConf::CATEGORYS ) {
		//map<string, map<int, int> >
		BOOST_FOREACH(S2::value_type val, item_v.second) {
			std::cout << item_v.first << "^^" << val.first << ": " << val.second
					<< std::endl;
		}
	}

	BOOST_FOREACH(SSSSS::value_type item_v,WatermarkerUploadConf::DUANZU_CATEGORYS) {
		BOOST_FOREACH(S2::value_type val,item_v.second) {
			std::cout << item_v.first << "^^" << val.first << ": " << val.second
					<< std::endl;

		}
	}

	BOOST_FOREACH(S2::value_type item ,WatermarkerUploadConf::JPG_QUALITY) {
		cout << item.first << "===>" << item.second << endl;
	}
}

