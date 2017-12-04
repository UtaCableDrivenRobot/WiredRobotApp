#-------------------------------------------------
#
# Project created by QtCreator 2017-11-01T15:37:48
#
#-------------------------------------------------

QT       += core gui serialport
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WiredRobotApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    glwidget.cpp \
    endeffector.cpp \
    coordinates.cpp \
    calibrationform.cpp \
    teensyapi.cpp

HEADERS  += mainwindow.h \
    model.h \
    coordinatestruct.h \
    glwidget.h \
    framestruct.h \
    endeffector.h \
    coordinates.h \
    calibrationform.h \
    teensyapi.h

FORMS    += mainwindow.ui \
    calibrationform.ui

LIBS += -lopengl32 -lglu32

