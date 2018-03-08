#include "opengl_render.h"
#include <QtQuick/qquickwindow.h>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLContext>

#include <QtGui/QMatrix4x4>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>

#include "shapefile.h"

static const char *vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

static const char *fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";

OpenGL_Render::OpenGL_Render()   : m_t(0), m_program(0)
{
    if (!m_program) {
        initializeOpenGLFunctions();
        m_program = new QOpenGLShaderProgram();
        m_program->addCacheableShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
        m_program->addCacheableShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
        m_program->link();
        m_posAttr = m_program->attributeLocation("posAttr");
        m_colAttr = m_program->attributeLocation("colAttr");
        m_matrixUniform = m_program->uniformLocation("matrix");


        vector<GLfloat> x;
        vector<GLfloat> y;

        g_Shapefiles.push_back(*(new ShapeFile("Shapefiles\\boundary-polygon")));
        nVertices.reserve(g_Shapefiles.at(0).getEntity()->size());


        for (uint i = 0; i < g_Shapefiles.at(0).getEntity()->size(); ++i)
        {


            vertices.push_back(vector<GLfloat>());
            colors.push_back(vector<GLfloat>());

            for (uint j = 0; j < g_Shapefiles.at(0).getEntity()->at(i).points.size(); ++j)
            {
              //  qDebug()<< j;

                x.push_back(GLfloat(g_Shapefiles.at(0).getEntity()->at(i).points.at(j).x() )  );
                y.push_back(GLfloat(g_Shapefiles.at(0).getEntity()->at(i).points.at(j).y()  ) );

                colors[i].push_back(0.1f); //red
                colors[i].push_back(0.8f); //green
                colors[i].push_back(0.1f); //blue
            }
            normalize2dVector(x,y);



            // заполняем массив вертексами
            for (uint k=0;k<x.size();++k)
            {
                vertices[i].push_back(x[k]);
                vertices[i].push_back(y[k]);
            }
            nVertices[i]= colors[i].size()/3;
            x.clear();
            y.clear();
        }



        g_Shapefiles.at(0).getEntity()->clear();
        g_Shapefiles.clear();


    }
}

OpenGL_Render::~OpenGL_Render()
{
    delete m_program;
}



void OpenGL_Render::paint()
{
    // m_program->setUniformValue("t", (float) m_t); //передача параметра анимации из qml в шейдер

    glViewport(0, 0, m_viewportSize.width()*this->ev->retinaScale, m_viewportSize.height()*this->ev->retinaScale);



    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(255,255,255,255);

    m_program->bind();
    QMatrix4x4 Camera;

    //Camera.ortho(boundaries.x(),boundaries.z(),boundaries.y(),boundaries.w(),-1,1);
    Camera.perspective(60.0f, float(m_viewportSize.width() )/float( m_viewportSize.height() ), 0.1f, 10000.0f);

    Camera.translate(float(ev->deltaMouseMove.x()),-float(ev->deltaMouseMove.y()), ev->wheel);
    // model.rotate(100.0f * m_frame / 60, 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, Camera);
   // for (uint i=0;i<nVertices.size();++i)
  //  {

        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.at(0).data() );
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.at(0).data() ) ;

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINE_LOOP, 0 ,nVertices[0]);

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);





        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.at(1).data() );
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.at(1).data() ) ;

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINE_LOOP, 0 ,nVertices[1]);

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);







        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.at(2).data() );
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.at(2).data() ) ;

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINE_LOOP, 0 ,nVertices[2]);

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);


        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.at(3).data() );
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors.at(3).data() ) ;

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_LINE_LOOP, 0 ,nVertices[3]);

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);

 //  }
    m_program->release();
    ++m_frame;
    m_window->resetOpenGLState();
}


void OpenGL_Render::normalize2dVector(vector<GLfloat>& x, vector<GLfloat>& y)
{
    //Нормализуем координаты от 0 до 1
    //qDebug()<<"x";
    std::vector<GLfloat>::iterator result_x;
    result_x = std::max_element(x.begin(), x.end());
    int maxIndex_x=std::distance(x.begin(), result_x);

    GLfloat max_x=x[maxIndex_x];
    for (uint i=0;i<x.size();++i)
    {
        x[i]=(x[i]/max_x-0.999f)*1000.0f;
      //  qDebug()<<x[i];
    }
   // qDebug()<<"y";
    std::vector<GLfloat>::iterator result_y;
    result_y = std::max_element(y.begin(), y.end());
    int maxIndex_y=std::distance(y.begin(), result_y);

    GLfloat max_y=y[maxIndex_y];
    for (uint i=0;i<x.size();++i)
    {
        y[i]=(y[i]/max_y-0.999f)*1000.0f;
       // qDebug()<<y[i];
    }
}
