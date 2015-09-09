/*
 * image_logic.cc
 *
 *  Created on: 2015年8月13日
 *      Author: a11
 */
#ifndef WATERMARKER_H
#define WATERMARKER_H
#include <iostream>
#include <string>
#include  <map>
#include <list>
#include <stdexcept>
#include <Magick++.h>
#include <boost/lexical_cast.hpp>
#include <boost/tuple/tuple.hpp>

#include "UploadConf.h"
#include "ParseUriinfo.h"
using namespace std;

typedef map<Magick::Image, int> IMAGE_S;
class WaterInfo {
public:
	bool init;
	double x;
	double y;
	int mode;
	int index;
	Magick::Image watermarkImagePtr;
};
class WatermarkAction {
	const string _WATERPREFIXPATH = "images/";

public:
	WaterInfo waterinfoPtr;

public:
	WatermarkAction();
	/**
	 * @params
	 * @return dictionary
	 */
	bool getWatermarkInfo(Magick::Image*, Magick::Image*, int mode,
			int index,WaterInfo *waterinfoPtr);

	bool getWatermarkInfo(int width, int height,
			Magick::Image* watermarkImage, int water_width, int water_height,
			int mode, int index,WaterInfo *waterinfoPtr);

	Magick::Image* setWaterMarkOfImageObj(Magick::Image*  src,
			WaterInfo waterImageInfo);

	bool getWaterImageByid(string  ,WaterInfo*  ) ;

};

#endif
