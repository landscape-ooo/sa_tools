//============================================================================
// Name        : ssp.cpp
// Author      : ssss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "watermarker.h"
using namespace std;


void run_setWaterMarkOfImageObj(){

	WatermarkAction obj;
	map<Magick::Image,int> wanterinfo=	obj.getWaterImageByid("mayi_you_br");

	Magick::Image srcImage("/Users/a11/Documents/d.jpg");

	obj.setWaterMarkOfImageObj(srcImage,wanterinfo);
}
//void run_markwater(){
//	Magick::Image water("/data/workspace/cpp_local/ssp/src/images/mayi_you.png");
//	Magick::Image src("/Users/a11/Documents/d.jpg");
//
//	src.composite(water,10,20,Magick::OverCompositeOp);
//	cout<<"----begin<<save "<<endl;
//	src.write("/tmp/water.jpg");
//
//}

///**
// * unittest getWatermarkInfo
// */
//void run_getWatermarkInfo() {
//	string uri =
//			"/gjfs12/M04/74/10/CgEHolTtX1CLmlNSAAGl1qu9kBA685_800-600_4-0.jpg";
//	GanjiFdfsUriInfo urlinfo = GanjiFdfsUriInfo::parse(uri);
//
//	WatermarkAction obj;
//	map<string, string> e = obj.getWatermarkInfo(urlinfo, "this_category", 0.2,
//			0.3);
//	cout << "map.x_aix=>" << e["x_aix"] << endl << "map.y_aix=>" << e["y_aix"]
//			<< endl << "map.waterid=>" << e["waterid"] << endl;
//}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	//run run_getWatermarkInfo
	run_setWaterMarkOfImageObj();

	return 0;
}
