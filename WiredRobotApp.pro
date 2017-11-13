#-------------------------------------------------
#
# Project created by QtCreator 2017-11-01T15:37:48
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WiredRobotApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    model.h \
    coordinatestruct.h \
    glwidget.h

FORMS    += mainwindow.ui

LIBS += opengl32.lib
LIBS+= glu32.lib
