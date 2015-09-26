#!/bin/sh
rm -rf ./somoclu/m4
rm -rf ./somoclu/src
rm -rf ./somoclu/autogen.sh
rm -rf ./somoclu/Makefile*
rm -rf ./somoclu/config*
rm -rf ./somoclu/*so
rm -rf ./somoclu/*c
rm -rf ./somoclu/*cxx
rm -rf ./somoclu/LICENSE
rm -rf ./dist
rm -rf ./build
mkdir somoclu/src
mkdir somoclu/src/Windows
cp -R ../../m4 ./somoclu/
cp ../../autogen.sh ./somoclu/
cp ../../LICENSE ./somoclu/
cp ../../Makefile.in ./somoclu/
cp ../../configure.ac ./somoclu/
cp ../../src/Makefile.in ./somoclu/src/
cp ../../src/*.h ./somoclu/src/
cp ../../src/*.cpp ./somoclu/src/
cp ../../src/*.cu ./somoclu/src/
swig -c++ -python somoclu/somoclu.i
python setup.py build
#cp  build/lib.linux-x86_64-2.7/_somoclu_wrap.so somoclu/
#sudo python2 setup.py install
