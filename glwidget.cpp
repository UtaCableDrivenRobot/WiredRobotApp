#include "glwidget.h"
#include <QtDebug>


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
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
    gluLookAt(500,500,1700,500,500,500,0,1,0);
    //gluLookAt(250,100,250,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);

    //Origin Axis
    glPushMatrix();
    glLoadIdentity();
    glCallList(1) ;
    glPopMatrix();

    //Robot Frame
    glPushMatrix();
    glLoadIdentity();
    glCallList(2) ;
    glPopMatrix();

    //Robot Endeffector
    glPushMatrix();
    glLoadIdentity();
    paintRobotEndEffector();
    glPopMatrix();
}

void GLWidget::resizeGL(int w, int)
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

void GLWidget::paintRobotEndEffector()
{
    myModel->updateEndEffector();
    glm::vec3 p1(endEffector->points[0]);
    glm::vec3 p2(endEffector->points[1]);
    glm::vec3 p3(endEffector->points[2]);
    glm::vec3 p4(endEffector->points[3]);
    glm::vec3 p5(endEffector->points[4]);
    glm::vec3 p6(endEffector->points[5]);
    glm::vec3 p7(endEffector->points[6]);
    glm::vec3 p8(endEffector->points[7]);
    drawBox(p1,p2,p3,p4,p5,p6,p7,p8);
}

// Draws X Y Z lines
void GLWidget::createAxisPaint()
{
    glNewList(1,GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(300,0,0);
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,300,0);
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,300);
    glEnd();
    glEndList();
}

void GLWidget::createRobotFrame()
{
    glNewList(2,GL_COMPILE);
    for(frame frameItem : robotFrame)
    {
        glm::vec3 p1(frameItem.point1[0],frameItem.point1[1],frameItem.point1[2]);
        glm::vec3 p2(frameItem.point1[0],frameItem.point2[1],frameItem.point1[2]);
        glm::vec3 p3(frameItem.point2[0],frameItem.point2[1],frameItem.point1[2]);
        glm::vec3 p4(frameItem.point2[0],frameItem.point1[1],frameItem.point1[2]);
        glm::vec3 p5(frameItem.point1[0],frameItem.point1[1],frameItem.point2[2]);
        glm::vec3 p6(frameItem.point1[0],frameItem.point2[1],frameItem.point2[2]);
        glm::vec3 p7(frameItem.point2[0],frameItem.point2[1],frameItem.point2[2]);
        glm::vec3 p8(frameItem.point2[0],frameItem.point1[1],frameItem.point2[2]);
        drawBox(p1, p2, p3, p4, p5, p6, p7, p8);
    }
    glEndList();
}

void GLWidget::drawBox(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4, glm::vec3 p5, glm::vec3 p6, glm::vec3 p7, glm::vec3 p8 )
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
