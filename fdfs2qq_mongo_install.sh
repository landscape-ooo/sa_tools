#!/bin/env sh

############libevent
###download
cd /tmp/;
wget -O  libevent2.tar https://github.com/libevent/libevent/releases/download/release-2.0.22-stable/libevent-2.0.22-stable.tar.gz;
###install 
tar -xvf libevent2.tar && cd libevent-2.0.22-stable
./configure --prefix=/usr/local/webserver/libevent-2.0.22-stable
make 
make install 
###ln 
ln -s /usr/local/webserver/libevent-2.0.22-stable /usr/local/webserver/libevent2
############libevent end 



############mongo_c_driver
cd /tmp/
wget -O mongo_c_driver.tar https://github.com/mongodb/mongo-c-driver/releases/download/1.4.2/mongo-c-driver-1.4.2.tar.gz
###install 
tar -xvf  mongo_c_driver.tar && cd mongo-c-driver-1.4.2
./configure --prefix=/usr/local/webserver/mongo-c-driver-1.4.2
make 
make install 
####ln 
ln -s /usr/local/webserver/mongo-c-driver-1.4.2 /usr/local/webserver/mongo-c-driver
#############mongo_c_driver end 



echo /usr/local/webserver/libevent2/lib   >> /etc/ld.so.conf
echo /usr/local/webserver/mongo-c-driver/lib   >> /etc/ld.so.conf
/sbin/ldconfig



##############exe
cd /tmp
wget -O fdfs2qq_mong.tar  https://github.com/gjpicker/bplustree_datax/archive/lib_mongo.zip
unzip -o fdfs2qq_mong.tar
cd  bplustree_datax-lib_mongo
make
make install 
make clean 
##############end exe



