/*
 * ParseUriinfo.h
 *
 *  Created on: 2015年8月13日
 *      Author: a11
 */
#include "ParseUriinfo.h"


const string GanjiFdfsUriInfo::URLPATTERNS_LIST[]={
	"^/(?P<path>gjfs.*)_(?P<width>\\d+)-(?P<height>\\d+)(?P<cut>c|f)?_(?P<quality>\\d)-(?P<verison>\\d+)\\.(?P<ext>jpg|jpeg|png|gif|bmp|swf)$",
	"^/(?P<path>gjfs.*)_(?P<width>\\d+)-(?P<height>\\d+)(?P<cut>c|f)?_(?P<quality>\\d)-(?P<verison>\\d+)\\.(?P<ext>doc|docx|pdf|txt|csv|xls|apk|ipa|amr|mp3)$",
	"^/(?P<path>gjfs.*)\\.(?P<ext>amr)\\.mp3$",
	"^/(?P<path>gjfs.*)\\.(?P<ext>doc|docx|pdf|txt|xls|csv|swf|flv|3gp|3gpp|mpg|mpeg|wmv|mov|avi|mp4|f4v|rmvb|apk|ipa|amr|mp3)$"
};
const string  GanjiFdfsUriInfo::_KEYLIST[]={
		"path","width","height","cut","quality","version","ext"};



GanjiFdfsUriInfo::GanjiFdfsUriInfo() {
	this->cut = false;
	this->fill = false;
	this->quality = 6;
	this->version = 1;
	this->ext = "";
	this->fileid = "";
	this->height = 0.0;
	this->width = 0.0;
}

GanjiFdfsUriInfo GanjiFdfsUriInfo::parse(string str) {
	BOOST_FOREACH (string reg_p,GanjiFdfsUriInfo::URLPATTERNS_LIST) {
		try {
			sregex rx = sregex::compile(reg_p);
			smatch what;
			if (regex_search(str, what, rx)) {
				GanjiFdfsUriInfo uriobj;
				uriobj.uri=str;
				BOOST_FOREACH (string text ,GanjiFdfsUriInfo::_KEYLIST) {   // Range-for!
					try {
						if (text == "path" || text == "ext") {
							uriobj.fileid = what["path"] + "." + what["ext"];
							uriobj.ext = what["ext"];
							continue;
						}
						if (text == "width") {
							uriobj.width = boost::lexical_cast<double>(
									what["width"]);
							continue;
						}
						if (text == "height") {
							uriobj.height = boost::lexical_cast<double>(
									what["height"]);
							continue;
						}
						if (text == "cut") {
							if (what["cut"] == "c")
								uriobj.cut = true;
							if (what["cut"] == "f")
								uriobj.fill = true;
							continue;
						}
						if (text == "quality") {
							uriobj.quality = boost::lexical_cast<int>(
									what["quality"]);
							continue;
						}
						if (text == "version") {
							uriobj.version = boost::lexical_cast<int>(
									what["height"]);
							continue;
						}
					} catch (const exception& s) {
					}
				}
				return uriobj;
				break; //end big for
			}
		} catch (const std::exception& s) {
		}
	}

}

string GanjiFdfsUriInfo::toString() {
	cout<<"cut:"<<this->cut<<endl
			<<"fill:"<<this->fill<<endl
			<<"quality:"<<this->quality<<endl
			<<"version:"<<this->version<<endl
			<<"ext:"<<this->ext<<endl
			<<"fileid:"<<this->fileid<<endl
			<<"height:"<<this->height<<endl
			<<"width:"<<this->width<<endl
	<<"uri:"<<this->uri<<endl;
	return "\n\n";
}
