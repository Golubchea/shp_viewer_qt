#!/bin/bash -x
#for windows 
cd libs

./wget http://download.osgeo.org/shapelib/shapelib-1.4.1.zip
unzip -q shapelib-1.4.1.zip
mv shapelib-1.4.1 shapelib
rm shapelib-1.4.1.zip