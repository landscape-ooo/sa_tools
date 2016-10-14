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

echo /usr/local/webserver/libevent2/lib   >> /etc/ld.so.conf
/sbin/ldconfig



##############exe
cd /tmp
wget -O fdfs2qq_mong.tar  https://github.com/gjpicker/bplustree_datax/archive/master.zip
unzip -o fdfs2qq_mong.tar
cd  bplustree_datax-master
make
make install 
make clean 
##############end exe



