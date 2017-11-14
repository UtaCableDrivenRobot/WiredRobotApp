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
    createRobotFrame();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // setting up camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(-1,1,-1,1,1,30);
    glFrustum(-1,1,-1,1,1,30);
    gluLookAt(5,5,5,0,0,0,0,1,0);

    // drawing stuff
    glMatrixMode(GL_MODELVIEW);

    //X Y Z
    glPushMatrix();
    glLoadIdentity();
    glCallList(1) ;
    glPopMatrix();
    glPushMatrix();
    glLoadIdentity();
    glCallList(2) ;
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

void GLWidget::createRobotFrame()
{
    double xMax = myModel->ROBOT_WIDTH/2;
    double xMin = -1*xMax;
    double zMax = myModel->ROBOT_DEPTH/2;
    double zMin = -1*zMax;
    double frame = myModel->ROBOT_FRAME_SIZE;
    glNewList(2,GL_COMPILE);
    drawBox(1,1,1,-2,-2,-2);
    glEndList();

}

void GLWidget::drawBox(double x1, double y1,double z1, double x2, double y2, double z2)
{
    //Boxes have 8 points
    //      6-------7
    //    / |      /|
    //   /  |     / |
    //  2___|____3  |
    //  |   |    |  |
    //  |   |    |  |
    //  |   | ___|_8
    //  | /5     |
    //  1________4/
    //
    double p1[3] = {x1,y1,z1};
    double p2[3] = {x1,y2,z1};
    double p3[3] = {x2,y2,z1};
    double p4[3] = {x2,y1,z1};
    double p5[3] = {x1,y1,z2};
    double p6[3] = {x1,y2,z2};
    double p7[3] = {x2,y2,z2};
    double p8[3] = {x2,y1,z2};
    //6 faces
    glBegin(GL_QUADS);
    //Top Face
    glVertex3d(p2[0],p2[1],p2[2]);
    glVertex3d(p3[0],p3[1],p3[2]);
    glVertex3d(p7[0],p7[1],p7[2]);
    glVertex3d(p6[0],p6[1],p6[2]);
    //Left Face
    glVertex3d(p2[0],p2[1],p2[2]);
    glVertex3d(p6[0],p6[1],p6[2]);
    glVertex3d(p5[0],p5[1],p5[2]);
    glVertex3d(p1[0],p1[1],p1[2]);
    //Back
    glVertex3d(p6[0],p6[1],p6[2]);
    glVertex3d(p7[0],p7[1],p7[2]);
    glVertex3d(p8[0],p8[1],p8[2]);
    glVertex3d(p5[0],p5[1],p5[2]);
    //Right
    glVertex3d(p3[0],p3[1],p3[2]);
    glVertex3d(p7[0],p7[1],p7[2]);
    glVertex3d(p8[0],p8[1],p8[2]);
    glVertex3d(p4[0],p4[1],p4[2]);
    //Near
    glVertex3d(p3[0],p3[1],p3[2]);
    glVertex3d(p4[0],p4[1],p4[2]);
    glVertex3d(p1[0],p1[1],p1[2]);
    glVertex3d(p2[0],p2[1],p2[2]);
    //Bottom
    glVertex3d(p1[0],p1[1],p1[2]);
    glVertex3d(p5[0],p5[1],p5[2]);
    glVertex3d(p8[0],p8[1],p8[2]);
    glVertex3d(p4[0],p4[1],p4[2]);

    glEnd();


}


