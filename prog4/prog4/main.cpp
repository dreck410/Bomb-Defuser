// ----------------------------------------
//file: main.cpp
//Author:  Daniel Recker User ID:   dreck410
//Class:  CPS 111
//Program : 4
//Version:  The Boss 90 version!! With some fun personal add ins
//Description:Creates a GUI that allows the user to interact with tracker, wanderer
// and basic objects. Including but is not limited to moving them, deleting them, and
// creating them. The user can also watch them move on their own, as trackers Find, and
// kill wanderers on the screen.


#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    
    return a.exec();
}
