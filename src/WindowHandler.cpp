/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "WindowHandler.h"

#include <QtQuick/qquickwindow.h>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLContext>

//for events
#include <QPoint>
#include <QDebug>
#include "event_stucture.h"

WindowHandler::WindowHandler()
    : m_t(0)
    , m_renderer(0)
{
    // структура нужна для передачи событий в рендер по указателю(к ней обращаются 2 класса)
    this->passEvent=new event_structure();

    passEvent->wheel=-5.0f;
    passEvent->speedCoefficient=1.05f;
    passEvent->m_middleButtonPressed=false;
    passEvent->m_oldMousePosition=QPointF(this->width()/2,this->height()/2);
    //
    //
    //функции чтобы принять события с qt quick в cpp класс
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    setFlag(ItemAcceptsInputMethod, true);
    connect(this, &QQuickItem::windowChanged, this, &WindowHandler::handleWindowChanged);





}

///////////////////////////////EVENTS///////////////////////////////////////////////////////////////
void WindowHandler::mousePressEvent(QMouseEvent *event)
{
    QQuickItem::mousePressEvent(event);

    if(event->button()==Qt::RightButton)
    {
        passEvent->m_middleButtonPressed=true;
        passEvent->m_oldMousePosition=QPointF(qreal(event->pos().x()),qreal(event->pos().y()));
    }
    else
    {
        passEvent->m_middleButtonPressed=false;
    }

}

void WindowHandler::mouseReleaseEvent(QMouseEvent *event)
{
    QQuickItem::mouseReleaseEvent(event);

    passEvent->m_middleButtonPressed=false;

}

void WindowHandler::wheelEvent(QWheelEvent *event)
{
    QQuickItem::wheelEvent(event);
    if(event->delta()>0)
    {
        passEvent->wheel=passEvent->wheel+passEvent->speedCoefficient;
        qDebug()<<passEvent->wheel;
    }
    else
    {
        passEvent->wheel=passEvent->wheel-passEvent->speedCoefficient;
        qDebug()<<passEvent->wheel;
    }

}
void WindowHandler::hoverMoveEvent(QHoverEvent* event) {
    QQuickItem::hoverMoveEvent(event);

    if(passEvent->m_middleButtonPressed)
    {

        passEvent->deltaMouseMove=(event->pos()*0.01f-passEvent->m_oldMousePosition*0.01f);
        qDebug()<<passEvent->deltaMouseMove;
    }
  //  passEvent->m_oldMousePosition=event->pos();
    //   qDebug() << event->pos();
}

///////////////////////////////EVENTS///////////////////////////////////////////////////////////////

void WindowHandler::setT(qreal t)
{
    if (t == m_t)
        return;
    m_t = t;
    emit tChanged();
    if (window())
        window()->update();
}

void WindowHandler::handleWindowChanged(QQuickWindow *win)
{
    if (win) {
        connect(win, &QQuickWindow::beforeSynchronizing, this, &WindowHandler::sync, Qt::DirectConnection);
        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &WindowHandler::cleanup, Qt::DirectConnection);

        // If we allow QML to do the clearing, they would clear what we paint
        // and nothing would show.

        win->setClearBeforeRendering(false);
    }
}

void WindowHandler::cleanup()
{
    if (m_renderer) {
        delete m_renderer;
        m_renderer = 0;
        delete this->passEvent;
    }
}

void WindowHandler::sync()
{
    if (!m_renderer) {


        m_renderer = new OpenGL_Render();
        connect(window(), &QQuickWindow::beforeRendering, m_renderer, &OpenGL_Render::paint, Qt::DirectConnection);
    }
    this->passEvent->retinaScale= window()->devicePixelRatio();
    m_renderer->setViewportSize(window()->size() * window()->devicePixelRatio());
    m_renderer->setT(m_t);
    m_renderer->setWindow(window());

    this->m_renderer->ev=this->passEvent;
}
