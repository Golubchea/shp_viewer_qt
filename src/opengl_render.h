#ifndef OPENGL_RENDER_H
#define OPENGL_RENDER_H

#include <QtQuick/QQuickItem>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLFunctions>

#include <QMouseEvent>
#include <QWheelEvent>
#include "event_stucture.h"

// for shapefiles
#include <vector>
#include "shapefile.h"

class OpenGL_Render : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGL_Render() ;
    ~OpenGL_Render();

    void setT(qreal t) { m_t = t; }
    void setViewportSize(const QSize &size) { m_viewportSize = size; }
    void setWindow(QQuickWindow *window) { m_window = window; }
    int m_frame;
    event_structure * ev;
    void normalize2dVector(vector<GLfloat> &x, vector<GLfloat> &y);
    //shapefile class composition
    std::vector<ShapeFile> g_Shapefiles;
    //from shape to opengl container
    vector<vector<GLfloat>> vertices;
    vector<vector<GLfloat>> colors;
    QVector4D boundaries;
    vector<uint> nVertices;
public slots:
    void paint();


private:
    QSize m_viewportSize;
    qreal m_t;
    QOpenGLShaderProgram *m_program;
    QQuickWindow *m_window;
    //opengl id's and uniforms
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;
    //opengl camera




};


#endif // OPENGL_RENDER_H
