#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T03:22:12
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prog4
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    worldobj.cpp \
    world.cpp \
    movablelabel.cpp

HEADERS  += mainwidget.h \
    worldobj.h \
    world.h \
    movablelabel.h

FORMS    += mainwidget.ui

RESOURCES += \
    Resources.qrc
