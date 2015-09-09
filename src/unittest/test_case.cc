/*
 * test_case.cc
 *
 *  Created on: 2015年8月20日
 *      Author: a11
 */

#include <iostream>
#include <cassert>     /* assert */
#include <Magick++.h>
#include "../watermarker.h"
using namespace std;
using namespace Magick;

//
void run_getWaterImageByid(){
	string input;
	WaterInfo* trulyPtr=new WaterInfo();

	//
	WatermarkAction obj;
	input="daunzu";
	bool is_success=obj.getWaterImageByid(input,trulyPtr);
	WaterInfo expect=(*trulyPtr);
	assert(expect.index==0 );
	assert(expect.mode==3 );

	Magick::Image * ptr;
	Magick::Image orig(Geometry(1, 1), Color("white"));
	ptr=&orig;
	cout<<(*ptr).size().width()<<endl;

	delete trulyPtr;
	is_success=false;

	WaterInfo* tmp_obj=new WaterInfo();
	trulyPtr=tmp_obj;
	input="duanzu";
	is_success=obj.getWaterImageByid(input,trulyPtr);
	expect=(*trulyPtr);
	assert(expect.index==3 );
	assert(expect.mode==7);
	delete trulyPtr;
	delete tmp_obj;

}


void run_getWatermarkInfo_case3_smallwidth() {
	int inp_width = 100, inp_heigth = 99;
	int wat_width = 20, wat_heigth = 20;

	Magick::Image src(Geometry(inp_width, inp_heigth), Color("white"));
	Magick::Geometry src_g = src.size();
	Magick::Image water_src(Geometry(wat_width, wat_heigth), Color("black"));
	Magick::Geometry water_src_g = src.size();

	WaterInfo* trulyPtr=new WaterInfo();
	WaterInfo expect;
	expect.index = 0;
	expect.mode = 3;
	expect.init = true;
	expect.x = inp_width - wat_width - 10; //tmp_path.append("ganji_v4_small.png");
	expect.y = inp_heigth - wat_heigth - 10;

	WatermarkAction obj;

	bool is_success  = obj.getWatermarkInfo(inp_width, inp_heigth, &water_src,
			wat_width, wat_heigth, expect.mode, expect.index,trulyPtr);

	cout<<__LINE__<<__FUNCTION__<<endl;
	WaterInfo truly=*trulyPtr;
	cout<<__LINE__<<__FUNCTION__<<endl;

	if (expect.index == truly.index && expect.mode == truly.mode
			&& expect.init == truly.init && expect.x == truly.x
			&& expect.y == truly.y) {

		cout << " yes  yes ye !" << endl;
	} else {
		cout << " nononononon====== error !" << endl;
		cout <<truly.index;
		cout	<<"^"<< truly.mode;
		cout	<<"^"<< truly.init;
		cout	<<"^"<<truly.x;
		cout	<<"^"<<truly.y;

	}
}

void run_getWatermarkInfo_mode3_bigwidth() {
	int inp_width = 300, inp_heigth = 200;
	int wat_width = 20, wat_heigth = 20;

	Magick::Image src(Geometry(inp_width, inp_heigth), Color("white"));
	Magick::Geometry src_g = src.size();
	Magick::Image water_src(Geometry(wat_width, wat_heigth), Color("black"));
	Magick::Geometry water_src_g = src.size();
	WaterInfo* trulyPtr=new WaterInfo();

	WaterInfo expect;
	expect.index = 0;
	expect.mode = 3;
	expect.init = true;
	expect.x = inp_width - 93 - 7;
	expect.y = inp_heigth - 25 - 5;

	WatermarkAction obj;
	bool is_success = obj.getWatermarkInfo(inp_width, inp_heigth, &water_src,
			wat_width, wat_heigth, expect.mode, expect.index,trulyPtr);

	WaterInfo truly;
	truly=(*trulyPtr);
	if (expect.index == truly.index && expect.mode == truly.mode
			&& expect.init == truly.init && expect.x == truly.x
			&& expect.y == truly.y) {

		cout << " yes  yes ye !" << endl;
	} else {
		cout << " nononononon====== error !" << endl;
		cout <<truly.index;
		cout	<<"^"<< truly.mode;
		cout	<<"^"<< truly.init;
		cout	<<"^"<<truly.x;
		cout	<<"^"<<truly.y;

	}
}
void run_getWatermarkInfo_case1() {
	int inp_width = 300, inp_heigth = 200;
	int wat_width = 20, wat_heigth = 20;

	Magick::Image src(Geometry(300, 200), Color("white"));
	Magick::Geometry src_g = src.size();
	Magick::Image water_src(Geometry(20, 20), Color("black"));
	Magick::Geometry water_src_g = src.size();

	WaterInfo* trulyPtr=new WaterInfo();
	WaterInfo expect;
	expect.index = 3;
	expect.mode = 5;
	expect.init = true;
	expect.x = inp_width - wat_width - 10;
	expect.y = 10;

	WatermarkAction obj;
	bool is_success = obj.getWatermarkInfo(inp_width, inp_heigth,& water_src,
			wat_width, wat_heigth, expect.mode, expect.index,trulyPtr);

	 WaterInfo truly=(*trulyPtr);

	if (expect.index == truly.index && expect.mode == truly.mode
			&& expect.init == truly.init && expect.x == truly.x
			&& expect.y == truly.y) {
		cout << " yes  yes ye !" << endl;
	} else {
		cout << " nononononon====== error !" << endl;
		cout <<truly.index
				<<"^"<< truly.mode
				<<"^"<< truly.init
				<<"^"<<truly.x
				<<"^"<<truly.y;
	}
}


int main(void) {
	run_getWatermarkInfo_case3_smallwidth();
	run_getWatermarkInfo_mode3_bigwidth();
	run_getWatermarkInfo_case1();

	run_getWaterImageByid();
}

