/*
 * test1.cc
 *
 *  Created on: 2015年8月13日
 *      Author: a11
 */
//#include <boost/regex.hpp>
//#include <boost/xpressive/xpressive.hpp>
//#include <boost/xpressive/regex_actions.hpp>
//#include <boost/foreach.hpp>
////#include <regex>
#include <iostream>
//#include <string>
//#include <vector>
//#include <exception>
//#include <typeinfo>
//#include <stdexcept>
//#include <cstdlib>

#include "../ParseUriinfo.h"
using namespace std;
//using namespace boost::xpressive;

int main() {
	GanjiFdfsUriInfo obj;
	vector<string> unittest_str;
	unittest_str.push_back(
			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685_800-600_4-0.jpg");
	unittest_str.push_back(
			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685_800-600_1-0.doc");
	unittest_str.push_back(
			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685.mp3");

	BOOST_FOREACH(string e_str,unittest_str) {
		obj = GanjiFdfsUriInfo::parse(e_str);
		cout << obj.toString();
	}

}

//int main() {
//	vector<string> URLPATTERNS_LIST;
////	URLPATTERNS_LIST.push_back("^/(?P<path>gjfs.*)_(?P<width>\\d+)");
////	URLPATTERNS_LIST.push_back("^/(?P<path>gjfs.*)_(?P<sss>\\d+)");
//	URLPATTERNS_LIST.push_back("^/(?P<path>gjfs.*)_(?P<width>\\d+)-(?P<height>\\d+)(?P<cut>c|f)?_(?P<quality>\\d)-(?P<verison>\\d+)\\.(?P<ext>doc|docx|pdf|txt|csv|xls|apk|ipa|amr|mp3)$");
//	URLPATTERNS_LIST.push_back("^/(?P<path>gjfs.*)\\.(?P<ext>amr)\\.mp3$");
//	URLPATTERNS_LIST.push_back("^/(?P<path>gjfs.*)\\.(?P<ext>doc|docx|pdf|txt|xls|csv|swf|flv|3gp|3gpp|mpg|mpeg|wmv|mov|avi|mp4|f4v|rmvb|apk|ipa|amr|mp3)$");
//
//	vector<string> unittest_str;
//	unittest_str.push_back(
//			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685_800-600_6-0.jpg");
//	unittest_str.push_back(
//			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685_800-600_6-0.doc");
//	unittest_str.push_back(
//			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685.mp3");
//	for (int i = 0; i < unittest_str.size(); i++) {
//		string v = unittest_str[i];
//		std::string str(v);
//		for (int ii = 0; ii < URLPATTERNS_LIST.size(); ii++) {
//			string reg_p = URLPATTERNS_LIST[ii];
//			try{
//				sregex rx = sregex::compile(reg_p);
//				smatch what;
//				if (regex_search(str, what, rx)) {
//					 const string  _keylist[]
//											={"path","width","height","cut","quality","version","ext"};
//					 UriInfo  uriobj;
//					 BOOST_FOREACH (string text ,_keylist) {   // Range-for!
//
//						try {
//								if(text=="path"||text=="ext"){
//										uriobj.fileid = what["path"] + "."
//												+ what["ext"];
//										uriobj.ext=what["ext"];
//										continue;
//								}
//								if(text=="width"){
//										uriobj.width =boost::lexical_cast<double>( what["width"] );
//										continue;
//								}
//								if(text=="height"){
//										uriobj.height =boost::lexical_cast<double>( what["height"] );
//										continue;
//								}
//								if(text=="cut"){
//										if(what["cut"]=="c")uriobj.cut =true;
//										if(what["cut"]=="f")uriobj.fill =true;
//										continue;
//								}
//								if(text=="quality"){
//										uriobj.quality =boost::lexical_cast<int>( what["quality"] );
//										continue;
//								}
//								if(text=="version"){
//										uriobj.version =boost::lexical_cast<int>( what["height"] );
//										continue;
//								}
//							} catch (const exception& s) {
//
//							}
//					}
//					break; //end big for
//				}
//			}catch(const std::exception& s) {
//				 std::exception_ptr p = std::current_exception();
//				 cout<<p;
//				// std::clog <<(p ? p.exception_ptr() : "null") << std::endl;
//				cout << s.what();
//			}
//		}
//	}
//}

//#include <regex>
//#include <iomanip>
//#include <iostream>
//#include <string>
//
//#include <boost/regex.hpp>
//#include <stdexcept>
//
//using namespace std;
//
//using namespace boost;
//regex expression("([0-9]+)(\\-| |$)(.*)");
//// process_ftp:
//// on success returns the ftp response code, and fills
//// msg with the ftp response message.
//int process_ftp(const char* response, std::string* msg) {
//	cmatch what;
//	if (regex_match(response, what, expression)) {
//// what[0] contains the whole string
//// what[1] contains the response code
//// what[2] contains the separator character
//// what[3] contains the text message.
//		if (msg)
//			msg->assign(what[3].first, what[3].second);
//		return std::atoi(what[1].first);
//	}
//// failure did not match
//	if (msg)
//		msg->erase();
//	return -1;
//}

//template<class BidIt>
//void show(const char *title, const sub_match<BidIt>& sm) {
//	cout << 'ss' << title << ":";
//	if (sm.matched)
//		cout << sm.str() << '\n';
//	else
//		cout << "[no match]\n";
//}
//
//int main() {
//	try {
//		regex rgx( "^/(gjfs.*)_(\\d+)-(\\d+)(c|f)?_(\\d)-(\\d+)\\.(jpg|jpeg|png|gif|bmp|swf)$",regex_constants::ECMAScript );
//		string tgt(
//				"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685_800-600_6-0.jpg");
//		match_results<string::iterator> m;
//		if (!regex_match(tgt.begin(), tgt.end(), m, rgx))
//			cout << "search failed\n";
//		else { // search succeeded, capture group 1 not part of match
//			show("full match", m[0]);
//			show("capture group 1", m[1]);
//			show("capture group 2", m[2]);
//			show("capture group 2", m[3]);
//			show("capture group 2", m[4]);
//			show("capture group 2", m[5]);
//			show("capture group 2", m[6]);
//			show("capture group 2", m[7]);
//
//			show("capture group e", m[8]);
//			cout << tgt.length();
//			for(int i=0 ;i<m.length();i++){
//				cout << m[i]<<endl;
//			}
//		}
//	} catch (exception &ex) {
//		cout << ex.what();
//	}
//	return 0;
//}

