#!/bin/bash -x
#you need specify paths to qt
export PATH="C:/Qt/Qt5.10.1/Tools/mingw530_32/bin/:$PATH"
cd C:/Qt/Qt5.10.1/5.10.1/mingw53_32/bin
#for qml 
./windeployqt -release --qmldir C:/Qt/Qt5.10.1/5.10.1/mingw53_32/qml C:/code/shp_viewer_qt/build/release/shp_viewer_qt.exe
echo "Done, Press ENTER to end"
read