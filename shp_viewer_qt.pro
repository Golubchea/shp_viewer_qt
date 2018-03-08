QT += qml quick

HEADERS += \
    src/opengl_render.h \
    src/WindowHandler.h \
    src/event_stucture.h \
    src/shapefile.h \
    libs/shapelib/shapefil.h
SOURCES += src/main.cpp \
    src/opengl_render.cpp \
    src/WindowHandler.cpp \
    src/shapefile.cpp\
    libs/shapelib/dbfopen.c\
    libs/shapelib/safileio.c\
    libs/shapelib/shpopen.c
RESOURCES += src/openglunderqml.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/openglunderqml
INSTALLS += target
