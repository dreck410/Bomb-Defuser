//
//MainWidget.h
//


#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>

#include "world.h"


using namespace std;
class MovableLabel;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


    
private slots:

    bool check_Radio_Buttons(string);


    MovableLabel *makeImage(QString, WorldObject*);

    void on_btnBomb_clicked();



    void on_btnRobot_clicked();

    void on_btnWall_clicked();

    void on_btnMove_toggled(bool checked);

    void on_btnDelete_toggled(bool checked);

    void on_btnAnimate_clicked();

    void Animate();

public:

    int on_label_Click(MovableLabel*);

    vector<MovableLabel*> GetLbls(QObjectList);

    void uiOperation();

    /*   void setButton(bool isMove)
   {Move = isMove;}

   bool getMove()
   {return Move;}
*/

private:

    Ui::MainWidget *ui;
    void btnClicked();
    QTimer* timer;



};





#endif // MAINWIDGET_H
