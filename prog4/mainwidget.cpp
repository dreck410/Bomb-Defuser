//----------Project 4
//----------Daniel Recker
//---------- 10/18/2013

#include <string>
#include <vector>
#include <QLabel>
#include <QMouseEvent>
#include <QString>
#include <QPixmap>
#include "worldobj.h"
#include "world.h"
#include <QDebug>

#include "movablelabel.h"
#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QMessageBox>

//Instantiate MainWidget

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);


    //Timer--------------------------------
    timer = new QTimer(this);
    timer->setInterval(125);
    connect(timer, &QTimer::timeout,this, &MainWidget::Animate);

}


MainWidget::~MainWidget()
{
    delete timer;

    delete ui;
}



//Toggle Buttons----------------------------------------------->

//Move Toggle
//Global Variable taht says which button is pressed
//Move = true when it's the move button and
//Move = false when it's the delete button.

bool Move;

void MainWidget::on_btnMove_toggled(bool checked)
{
    checked;
    ui->btnDelete->setChecked(false);
    Move = true;
}

//Delete Toggle

void MainWidget::on_btnDelete_toggled(bool checked)
{
    checked;
    ui->btnMove->setChecked(false);
    Move = false;
}

//when a label is clicked delete it.
int MainWidget::on_label_Click(MovableLabel *lbl)
{

    if(Move == false){
        //deletebutton is checked delete it

        delete lbl;

        return 0;
    }else{if(Move == true){
            //move button is checked move it
            return 1;
        }else{

            QMessageBox::information(this,"Uh-Oh","Please select Delete or Move");
            return -1;
        }
    }
}

//----------------------Create Functions------------------------//


//puts out qDebug information.
void MainWidget::uiOperation(){
    int i = 0;
    for (; i < World::getInstance().getObjects().size(); i++) {

        qDebug() << QString::fromStdString(World::getInstance().getObjects().at(i)->toString());

    }if(i==0)
    {
        qDebug() << "\tNo creatures in World.\n";
    }
    qDebug() << "\n";
}

bool MainWidget::check_Radio_Buttons(string image){

    string type = "ba";
    if(ui->rdbBasic->isChecked()){
        type = "ba";
    }else{
        if(ui->rdbTrack->isChecked()){
            type = "tr";
        }else{
            if(ui->rdbWand->isChecked()){
                type = "wa";
            }else{
                return false;
            }//else none
        }//else wand
    }//else bas

    WorldObject* obj = World::getInstance().createObject(type);
    obj->setImage(image);
    obj->setKills(0);
    obj->setAlive(true);
    QString Qimage = QString::fromStdString(image);


    World::getInstance().add(obj);
    makeImage(Qimage, obj);

    this->uiOperation();

    return true;

}
//creates the image and associates the object with the label.
//also puts the label into a vector of more labels.
MovableLabel* MainWidget::makeImage(QString image, WorldObject* obj)
{
    //:/images/cooltext.png
    image = ":/images/" + image;
    MovableLabel *label = new MovableLabel(ui->wdgWorld,obj);
    label->setGeometry(0,0,40,40);
    obj->setX(0,10);
    obj->setY(0,10);
    const QPixmap Img = QPixmap(image);
    label->setPixmap(Img);
    label->setScaledContents(true);
    label->show();
    return label;
}

//if the bomb is clicked
void MainWidget::on_btnBomb_clicked()
{
    bool is = check_Radio_Buttons("bomb.png");
    if(is){


    }else{
        QMessageBox::information(this,"Uh-Oh", "Please select a radio Button");
    }
}

//if the robot is clicked
void MainWidget::on_btnRobot_clicked()
{
    bool is = check_Radio_Buttons("robot.png");
    if(is){

    }else{
        QMessageBox::information(this,"Uh-Oh", "Please select a radio Button");
    }
}

//if the wall was clicked... But why would you want a wall?
void MainWidget::on_btnWall_clicked()
{
    bool is = check_Radio_Buttons("wall.jpg");
    if(is){

    }else{
        QMessageBox::information(this,"Uh-Oh", "Please select a radio Button");
    }
}




//----------------- Animate----------------------//

//turns on the clock if clicked!!
void MainWidget::on_btnAnimate_clicked()
{
    if(ui->btnAnimate->isChecked()){
        ui->btnAnimate->setText("Stop Animation");
        timer->start();
    }
    if(ui->btnAnimate->isChecked() == false){
        ui->btnAnimate->setText("Animate");
        timer->stop();
    }
    uiOperation();

}
//Separates the Qlabels from the rest of the QObjects
vector<MovableLabel*> MainWidget::GetLbls(QObjectList QObjects)
{
    vector<MovableLabel*> labels;
    for(int i = 0; i < QObjects.size();i++)
    {
        if(QObjects.at(i)->inherits("QLabel"))
        {
            labels.push_back((MovableLabel*)QObjects.at(i));
        }
    }
    return labels;
}

//the animation code that moved the labels and objects
//also does some fun killing of the wanderers. those pesky wanderers
// must me killed!!
void MainWidget::Animate()
{
    //    vector<WorldObject*> objects = World::getInstance().getObjects();
    vector<MovableLabel*> lbls = this->GetLbls(ui->wdgWorld->children());
    for(int i = 0; i < lbls.size();i++)
    {

        MovableLabel* lbl = lbls.at(i);


        //if he's alive after his clock tick. move him if not...
        if( lbl->getObj() != NULL && lbl->getObj()->isAlive() ){

            lbl->getObj()->Move(ui->wdgWorld->width(),ui->wdgWorld->height());
            lbl->setGeometry(lbl->getObj()->getx(),lbl->getObj()->gety(),40,40);

        }else{
            //he's dead jack
            delete lbl;
            uiOperation();

        }
    }

}






