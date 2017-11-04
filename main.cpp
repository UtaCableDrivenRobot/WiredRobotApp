#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include "testclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    TestClass t;
    qDebug() << t.TestFunction();
    return a.exec();
}
