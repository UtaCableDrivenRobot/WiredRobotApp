#include "glwidget.h"
#include <QtDebug>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    qDebug() <<"parent called";
}

void GLWidget::initializeGL()
{
    glClearColor(0,1,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::resizeGL(int w, int h)
{

}
