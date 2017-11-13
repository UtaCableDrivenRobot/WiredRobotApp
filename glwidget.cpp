#include "glwidget.h"
#include <QtDebug>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    qDebug() <<"parent called";
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    timer.start(16);
}

void GLWidget::initializeGL()
{
    glClearColor(0.2f,0.2f,0.2f,1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    createAxisPaint();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // setting up camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(-1,1,-1,1,1,30);
    glFrustum(-1,1,-1,1,1,30);
    gluLookAt(2,2,2,0,0,0,0,1,0);

    // drawing stuff
    glMatrixMode(GL_MODELVIEW);

    //X Y Z
    glPushMatrix();
    glLoadIdentity();
    glCallList(1) ;
    glPopMatrix();






}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,w*3/4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    updateGL();
}

void GLWidget::setModel(Model* newModel)
{
    myModel = newModel;
}


// Draws X Y Z lines
void GLWidget::createAxisPaint()
{
    glNewList(1,GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(2,0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,2,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,2);
    glEnd();
    glEndList();
}


