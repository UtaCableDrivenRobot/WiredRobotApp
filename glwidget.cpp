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
    //glOrtho(-1,1,-1,1,1,500);
    glFrustum(-1,1,-1,1,1,5000);
    gluLookAt(1700,1500,3000,1000,1000,1000,0,1,0);

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
    robotFrame = myModel->getFrame();
    endEffector = myModel->getEndEffector();

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
    glNewList(2,GL_COMPILE);
    for(frame frameItem : robotFrame)
    {
        drawBox(frameItem.point1[0],frameItem.point1[1],frameItem.point1[2],frameItem.point2[0],frameItem.point2[1],frameItem.point2[2]);
    }
    glEndList();

}

void GLWidget::drawBox(float x1, float y1,float z1, float x2, float y2, float z2)
{
    float color = 0;
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
    float p1[3] = {x1,y1,z1};
    float p2[3] = {x1,y2,z1};
    float p3[3] = {x2,y2,z1};
    float p4[3] = {x2,y1,z1};
    float p5[3] = {x1,y1,z2};
    float p6[3] = {x1,y2,z2};
    float p7[3] = {x2,y2,z2};
    float p8[3] = {x2,y1,z2};
    //6 faces
    glBegin(GL_QUADS);
    //Top Face
    glColor3f(1,0,0);
    glVertex3f(p2[0],p2[1],p2[2]);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p7[0],p7[1],p7[2]);
    glVertex3f(p6[0],p6[1],p6[2]);
    //Left Face
    glColor3f(0,1,0);
    glVertex3f(p2[0],p2[1],p2[2]);
    glVertex3f(p6[0],p6[1],p6[2]);
    glVertex3f(p5[0],p5[1],p5[2]);
    glVertex3f(p1[0],p1[1],p1[2]);
    //Back
    glColor3f(0,0,1);
    glVertex3f(p6[0],p6[1],p6[2]);
    glVertex3f(p7[0],p7[1],p7[2]);
    glVertex3f(p8[0],p8[1],p8[2]);
    glVertex3f(p5[0],p5[1],p5[2]);
    //Right
    glColor3f(1,1,0);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p7[0],p7[1],p7[2]);
    glVertex3f(p8[0],p8[1],p8[2]);
    glVertex3f(p4[0],p4[1],p4[2]);
    //Near
    glColor3f(0,1,1);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p4[0],p4[1],p4[2]);
    glVertex3f(p1[0],p1[1],p1[2]);
    glVertex3f(p2[0],p2[1],p2[2]);
    //Bottom
    glColor3f(1,1,1);
    glVertex3f(p1[0],p1[1],p1[2]);
    glVertex3f(p5[0],p5[1],p5[2]);
    glVertex3f(p8[0],p8[1],p8[2]);
    glVertex3f(p4[0],p4[1],p4[2]);

    glEnd();


}

void GLWidget::drawBox(EndEffector endEffector)
{

}


