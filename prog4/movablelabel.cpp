//
//MovableLabel.cpp
//

#include <string>
#include <QString>
#include <vector>
#include <QLabel>
#include <QMouseEvent>
#include <QPixmap>

#include "movablelabel.h"





MovableLabel::~MovableLabel()
{
    World::getInstance().destroy(getObj());
}
//if the mouse is dragging the label (aka clicked on the label) move him.
void MovableLabel::mouseMoveEvent(QMouseEvent *ev){
    if (mouseDragging){

        this->move(mapToParent(ev->pos() - this->offset));
        MoveObj(mapToParent(ev->pos() - this->offset),map->width(), map->height());

    }
}
//if the mouse clicked on the label check which button is clicked and delete or move him.
void MovableLabel::mousePressEvent(QMouseEvent *ev)
{
    int sel = map->on_label_Click(this);

    if(sel == 0){
        //output the new information
        map->uiOperation();

        //deleted in the method <on_label_click() since delete this; doesnt work
    }else{
        if(sel == 1){
            //move
            mouseDragging = true;
            offset = ev->pos();     // location where mouse was clicked within the label
        }
    }
}

//moves teh object to the same virtual point. like there is the image, and then the actual
// thing is doing stuff on a totally virtual fake plane!! IT's so cool!!
void MovableLabel::MoveObj(QPoint point,int width, int height){
    getObj()->setX(point.x(),width);
    getObj()->setY(point.y(),height);
}

//Drops the label off here.
void MovableLabel::mouseReleaseEvent(QMouseEvent *ev) {


    map->on_label_Click(this);
    mouseDragging = false;
    offset = ev->pos();
    map->uiOperation();

}
