#ifndef EVENT_STUCTURE_H
#define EVENT_STUCTURE_H
#include <QPointF>

struct event_structure{
    QPointF deltaMouseMove;
    qreal wheel;
    qreal speedCoefficient;

    bool m_middleButtonPressed;
    bool m_animating;
    QPointF m_oldMousePosition;
    qreal retinaScale;
};


#endif // EVENT_STUCTURE_H
