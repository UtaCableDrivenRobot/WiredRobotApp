#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Model t;
    qDebug() << t.insertNewPoint(1,2,3,1,2,3);
    return a.exec();
}
