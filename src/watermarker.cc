/*
 * Magick::Image_logic.cc
 *
 *  Created on: 2015年8月13日
 *      Author: a11
 */
#include "watermarker.h"
using namespace std;

WatermarkAction::WatermarkAction() {
}
/**
 *
 */
bool WatermarkAction::getWatermarkInfo(
		int width , int height,
		Magick::Image*  watermarkImagePtr ,
		int water_width,int water_height,
		int mode,int index,
		WaterInfo *waterinfoPtr
		) {

		if(!WatermarkerUploadConf::WATERMARKS.count(index)){
			waterinfoPtr->init=false;
			return false;
		}
		(*waterinfoPtr).mode=mode;
		(*waterinfoPtr).index=index;

		Magick::Geometry	g = (*watermarkImagePtr).size();
		switch(mode){
			case 3:
				if(waterinfoPtr->index==0 &&  ((width >= 150 && width <= 340) || (height >= 100 && height <= 220))) {
					string tmp_path=_WATERPREFIXPATH;
					tmp_path.append("ganji_v4_small.png");
					try{
						Magick::Image  watermarkImage(tmp_path);
						g = watermarkImage.size();
						waterinfoPtr->watermarkImagePtr=watermarkImage;
						//watermarkImagePtr=&watermarkImage;
					}catch(exception &ex){
					}
					water_height = g.height();
					water_width= g.width();
					waterinfoPtr->x=width-water_width-7;
					waterinfoPtr->y=height-water_height-5;
				}else{
					waterinfoPtr->x=width-water_width-10;
					waterinfoPtr->y=height-water_height-10;
				}
				break;
			case 5:
				waterinfoPtr->x=width-water_width-10;
				waterinfoPtr->y=10;
				break;
			case 7:
				waterinfoPtr->x=10;
				waterinfoPtr->y=10;
				break;
		}
		waterinfoPtr->init = true;

		return true;
}



/**
 *
 */
bool WatermarkAction::getWatermarkInfo(
		Magick::Image* srcPtr ,
		Magick::Image* watermarkImagePtr ,
		int mode,int index,WaterInfo *waterinfoPtr) {

		Magick::Geometry g_src = (*srcPtr).size();
		int width=g_src.width();
		int height=g_src.height();

		Magick::Geometry g = (*watermarkImagePtr).size();
		int water_width= g.width();
		int water_height = g.height();

		return this->getWatermarkInfo(width,height,watermarkImagePtr,
				water_width,water_height,mode,index,waterinfoPtr
				);
}



Magick::Image* WatermarkAction::setWaterMarkOfImageObj(
		Magick::Image*  src,
		WaterInfo waterImageInfo) {
	if(waterImageInfo.init==true){
//		Magick::Image origin=*src ;
		try{
			src->composite(waterImageInfo.watermarkImagePtr
					,waterImageInfo.x,waterImageInfo.y
					,Magick::OverCompositeOp);
		}catch(exception &ex){

		}
		return src;
	}
	return src;
}

bool WatermarkAction::getWaterImageByid(string category,WaterInfo* watermarkImagePtr) {

	map<int, int>  waterSetting;
	string water_name;

	map<string, map<int, int> >::const_iterator pos = WatermarkerUploadConf::CATEGORYS.find(category);
	if (pos == WatermarkerUploadConf::CATEGORYS.end()) {
		//default
		category="default";
	}
	waterSetting=WatermarkerUploadConf::CATEGORYS.find(category)->second;

	int _index,_mode;
	BOOST_FOREACH(FDFS_II_TYPE::value_type item,waterSetting){
		_index=item.first;
		_mode=item.second;
	}

	map<int,string>::const_iterator pos_i = WatermarkerUploadConf::WATERMARKS.find(_index);
	if (pos_i != WatermarkerUploadConf::WATERMARKS.end()) {
		water_name=WatermarkerUploadConf::WATERMARKS.find(_index)->second;
	}
	string fileName=_WATERPREFIXPATH;
	fileName.append(water_name);
	//WaterInfo ret;
	try{
		Magick::Image image(fileName);
		(*watermarkImagePtr).watermarkImagePtr =image;
		(*watermarkImagePtr).index=_index;
		(*watermarkImagePtr).mode=_mode;
		cout<<fileName<<"^^^^^^^"<<image.size().width()<<endl;;
		return true;
	}catch(std::exception &ex){
		cout<<ex.what()<<"^^^^^^^"<<endl;;
		return false;
	}
}
