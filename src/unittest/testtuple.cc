/*
 * testtuple.cc
 *
 *  Created on: 2015年8月13日
 *      Author: a11
 */

//#include "ParseUriinfo.h";
//#include "image_logic.cc";
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include <iostream>
//#include <magick/api.h>
#include <regex>
using namespace std;

int main(int argc, char **argv) {

	string pattern = "a";
	regex base_regex(pattern);
	// Extraction of a sub-match
	smatch base_match;
	string allocator = "this is value";
	if (regex_match(allocator, base_match, base_regex)) {
		if (base_match.size() == 2) {
			std::ssub_match base_sub_match = base_match[1];
			std::string base = base_sub_match.str();

			std::cout << allocator << " has a base of " << base << '\n';
		}

	}

//	ExceptionInfo exception;
//	Image *image, *images, *resize_image, *thumbnails;
//	ImageInfo *image_info;
//	/*
//	 Initialize the image info structure and read an image.
//	 */
//	InitializeMagick(*argv);
//	GetExceptionInfo(&exception);
//
//
//
//
//	image_info = CloneImageInfo((ImageInfo *) NULL);
//	(void) strcpy(image_info->filename, "/tmp/ts.jpg");
//	images = ReadImage(image_info, &exception);
//
//	if (exception.severity != UndefinedException)
//		CatchException(&exception);
//	if (images == (Image *) NULL){
//		cout << 'image excep';
//		exit(1);
//	}
//	thumbnails = NewImageList();
//	WatermarkAction wateraction();
//
//
//
//	/*
//	 Write the image as MIFF and destroy it.
//	 */
//	(void) strcpy(thumbnails->filename, "after_water_image.jpg");
//	WriteImage(image_info, thumbnails);
//	DestroyImageList(thumbnails);
//	DestroyImageInfo(image_info);
//	DestroyExceptionInfo(&exception);
//	DestroyMagick();
//	return (0);
}

