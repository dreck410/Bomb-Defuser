//
//MovableLabel.h
//
#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H

#include <string>
#include <QString>
#include <vector>
#include <QLabel>
#include <QMouseEvent>
#include <QPixmap>

#include "worldobj.h"
#include "world.h"
#include "mainwidget.h"

class MovableLabel : public QLabel
{
    MainWidget* map;
    bool mouseDragging;
    QPoint offset;
    WorldObject* obj;

public:


    //instantiates teh movablelabel
    explicit MovableLabel(QWidget* parent, WorldObject* inObj): QLabel(parent) {
        map = new MainWidget(parent);
        setMouseTracking(true); // enable mouse move events
        mouseDragging = false;
        obj = inObj;
    }
    //upon ceases to exist delete obj
    ~MovableLabel();

    WorldObject* getObj(){return obj;}

    int eraseSpot(MovableLabel*);

    void mouseMoveEvent(QMouseEvent*);

    void mousePressEvent(QMouseEvent*);

    void MoveObj(QPoint, int width, int height);

    void mouseReleaseEvent(QMouseEvent*);
};
#endif // MOVABLELABEL_H
