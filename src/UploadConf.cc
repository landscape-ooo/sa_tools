/*
 * UploadConf.cc
 *
 *  Created on: 2015年8月19日
 *      Author: a11
 */
#include "UploadConf.h"
const map<int,string> WatermarkerUploadConf::WATERMARKS =
		  	  	  map_list_of(0,"ganji_v4.png")
                            (1,"guazi.png")
                            (2,"duanzu-1.png")
                            (3,"duanzu-2.png")
                            (4,"")
                            (5,"mayi_you.png")
    						(6,"mayi_you_br.png")
							(7,"mayi_you_br_big.png");

  const map<string, map<int, int> > WatermarkerUploadConf::CATEGORYS = map_list_of(
		"default"                  ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "xiaoqu"                   ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "tuan"                     ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "nomask"                   ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "youhuijuan"               ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "groupon"                  ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "tuiguang/ad"              ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "tuiguang/mqjob"           ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "tuiguang/contract"        ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "company_license"          ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "guazi"                    ,map_list_of(1, 3).convert_to_container<map<int, int> >())(
        "guazi_avatar"             ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "duanzu"                   ,map_list_of(3, 7).convert_to_container<map<int, int> >())(
        "duanzu_vip"               ,map_list_of(2, 7).convert_to_container<map<int, int> >())(
        "tuiguang"                 ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "duanzu_head"              ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "raw"                      ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "tuiguang/customer"        ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "tuiguang/idcard"          ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "tuiguang/business_card"   ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "mayinomask"               ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "mayi_you"                 ,map_list_of(5, 7).convert_to_container<map<int, int> >())(
    	"mayi_you_br"              ,map_list_of(6, 3).convert_to_container<map<int, int> >())(
		"mayi_you_br_big"          ,map_list_of(7, 3).convert_to_container<map<int, int> >())(
        "bangbang_pic"             ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "zhaopin/renzheng"         ,map_list_of(0, 5).convert_to_container<map<int, int> >())(
        "tuiguang/fang"            ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "secondmarket"		       ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "pet"			           ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "vehicle"		           ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "hospital"                 ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "hospital_nomask"          ,map_list_of(4, 3).convert_to_container<map<int, int> >())(
        "ticketing"                ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "event"                    ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "personals"                ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "housing"                  ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "training"                 ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "wanted"                   ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "parttime_wanted"          ,map_list_of(0, 3).convert_to_container<map<int, int> >())(
        "findjob"                  ,map_list_of(0, 3).convert_to_container<map<int, int> >()
		);


  const map<string, map<int, int> > WatermarkerUploadConf::DUANZU_CATEGORYS =
		map_list_of(
			"duanzu",
			map_list_of(640, 640).convert_to_container<map<int, int> >()
			)
			(
			"duanzu_head",
			map_list_of(640, 640).convert_to_container<map<int, int> >()
			)
			(
			"duanzu_vip",
			map_list_of(640, 640).convert_to_container<map<int, int> >()
			)
			(
			"mayi_you",
			map_list_of(640, 640).convert_to_container<map<int, int> >()
			)
			(
			"mayi_you_br",
			map_list_of(640, 640).convert_to_container<map<int, int> >()
			)
			(
			"mayi_you_br_big",
			map_list_of(640, 640).convert_to_container<map<int, int> >()
			);



  const map<int,int> WatermarkerUploadConf::JPG_QUALITY=
		map_list_of
			(0,15)(1,40)(2,50)
			(3,60)(4,70)(5,75)
			(6,80)(7,85)(8,90);


