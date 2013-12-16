/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QRadioButton *rdbBasic;
    QRadioButton *rdbWand;
    QRadioButton *rdbTrack;
    QPushButton *btnMove;
    QPushButton *btnDelete;
    QPushButton *btnUndo;
    QPushButton *btnWall;
    QPushButton *btnBomb;
    QPushButton *btnRobot;
    QWidget *wdgWorld;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(687, 509);
        rdbBasic = new QRadioButton(MainWidget);
        rdbBasic->setObjectName(QStringLiteral("rdbBasic"));
        rdbBasic->setGeometry(QRect(110, 370, 116, 22));
        rdbWand = new QRadioButton(MainWidget);
        rdbWand->setObjectName(QStringLiteral("rdbWand"));
        rdbWand->setGeometry(QRect(90, 340, 116, 22));
        rdbTrack = new QRadioButton(MainWidget);
        rdbTrack->setObjectName(QStringLiteral("rdbTrack"));
        rdbTrack->setGeometry(QRect(70, 310, 116, 22));
        btnMove = new QPushButton(MainWidget);
        btnMove->setObjectName(QStringLiteral("btnMove"));
        btnMove->setGeometry(QRect(10, 220, 91, 81));
        btnMove->setStyleSheet(QStringLiteral("image: url(:/pointer.png);"));
        btnMove->setCheckable(true);
        btnDelete = new QPushButton(MainWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(110, 220, 91, 81));
        btnDelete->setCheckable(true);
        btnUndo = new QPushButton(MainWidget);
        btnUndo->setObjectName(QStringLiteral("btnUndo"));
        btnUndo->setEnabled(false);
        btnUndo->setGeometry(QRect(220, 220, 91, 81));
        btnWall = new QPushButton(MainWidget);
        btnWall->setObjectName(QStringLiteral("btnWall"));
        btnWall->setGeometry(QRect(210, 420, 91, 81));
        btnBomb = new QPushButton(MainWidget);
        btnBomb->setObjectName(QStringLiteral("btnBomb"));
        btnBomb->setGeometry(QRect(10, 420, 91, 81));
        btnRobot = new QPushButton(MainWidget);
        btnRobot->setObjectName(QStringLiteral("btnRobot"));
        btnRobot->setGeometry(QRect(110, 420, 91, 81));
        wdgWorld = new QWidget(MainWidget);
        wdgWorld->setObjectName(QStringLiteral("wdgWorld"));
        wdgWorld->setGeometry(QRect(320, 210, 361, 291));
        wdgWorld->setStyleSheet(QStringLiteral("background-color: white"));
        label = new QLabel(MainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 471, 151));
        label->setAutoFillBackground(false);
        label->setPixmap(QPixmap(QString::fromUtf8(":/cooltext.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 160, 191, 41));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "World Builder", 0));
        rdbBasic->setText(QApplication::translate("MainWidget", "Basic", 0));
        rdbWand->setText(QApplication::translate("MainWidget", "Wanderer", 0));
        rdbTrack->setText(QApplication::translate("MainWidget", "Tracker", 0));
        btnMove->setText(QApplication::translate("MainWidget", "move", 0));
        btnDelete->setText(QApplication::translate("MainWidget", "delete", 0));
        btnUndo->setText(QApplication::translate("MainWidget", "undo", 0));
        btnWall->setText(QApplication::translate("MainWidget", "wall", 0));
        btnBomb->setText(QApplication::translate("MainWidget", "bomb", 0));
        btnRobot->setText(QApplication::translate("MainWidget", "robot", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWidget", "By Daniel Recker", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
