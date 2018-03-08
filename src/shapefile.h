#ifndef SHAPEFILE_H
#define SHAPEFILE_H
#include "shapefile.h"

/*
Simple ShapeFile OpenGL renderer.
Adapted from http://www.codeproject.com/Articles/32035/Rendering-Shapefile-in-OpenGL

Authors
-Tiago Augusto Engel (tengel@inf.ufsm.br)
-Cesar Pozzer		 (pozzer@inf.ufsm.br)

Using ShapeLib version 1.3
*/
// адаптировано под QVectorX
#include "libs/shapelib/shapefil.h"
//#include "Vectors.h"
#include <vector>
#include <string>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>

using namespace std;

struct Entity{
    vector<QVector3D> points;
};

class ShapeFile {
public:
    ShapeFile(const char* filename);
    ~ShapeFile();
    void printDBFHeader(int nFirstItems);
    static const char* typeStr(int type);
    QVector4D getBoundaries();
    static int shpCount;
    vector<Entity>* getEntity();
    int getnEntities();
    int getshpType();

private:
    QVector2D boundBoxMin, boundBoxMax;
    int nEntities, shpType;
    string filename;
    SHPHandle hSHP;
    DBFHandle hDBF;
vector<Entity> entities;

    void init();
    void beginPrimitive(int shpType);

    int shpID;
};

#endif // SHAPEFILE_H
