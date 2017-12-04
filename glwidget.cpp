#include "glwidget.h"
#include <QtDebug>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glm/ext.hpp"


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent),
    xVec(1,0,0),
    yVec(0,1,0),
    zVec(0,0,1)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    timer.start(16);
}

void GLWidget::initializeGL()
{
    glClearColor(0.85f,0.85f,0.85f,1.0f);
    glEnable(GL_DEPTH_TEST);
    /* Enable a single OpenGL light. */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    createAxisPaint();
    createRobotFrame();
    createGround();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // setting up camera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1,1,-1,1,1,500);
    glm::mat4 rotateXMat;
    glm::mat4 rotateYMat;
    glm::mat4 translate;
    glm::vec3 center(500,500,500);
    glm::vec4 eye(0,0,1200,1);
    rotateXMat = glm::rotate(rotateXMat,glm::radians((*eyeRotation)[0]),xVec);
    rotateYMat = glm::rotate(rotateYMat,glm::radians((*eyeRotation)[1]),yVec);
    translate = glm::translate(translate,center);
    eye = translate*rotateYMat*rotateXMat*eye;
    glFrustum(-1,1,-1,1,1,10000);
    gluLookAt(eye[0],eye[1],eye[2],500,500,500,0,1,0);


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

    //Floor

    glPushMatrix();
    glLoadIdentity();
    glCallList(3);
    glPopMatrix();


    //Robot Endeffector
    glPushMatrix();
    glLoadIdentity();
    paintRobotEndEffector();
    glPopMatrix();

    // Wires
    glPushMatrix();
    glLoadIdentity();
    paintWireStarts();
    glPopMatrix();
}

void GLWidget::createGround()
{
    glNewList(3,GL_COMPILE);

    glBegin(GL_QUADS);
    //glClearColor(0.2f,0.2f,0.2f,1.0f);
    //glColor3f(0.25f,0.16f,0.1f);
    glColor3f(0.2f,0.2f,0.2f);
    glNormal3f(0,1,0);
    glVertex3f(-10000,0,-10000);
    glVertex3f(-10000,0,10000);
    glVertex3f(10000,0,10000);
    glVertex3f(10000,0,-10000);

    glEnd();

    glEndList();

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
    eyeRotation = myModel->getEyeRotation();
    wireStarts = myModel->getWireStarts();
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


//    // TESTING REMOVE LATER
//    std::vector<float> newLine;
//    for(unsigned int i=0;i<8;i++)
//    {
//        newLine.push_back(sqrt(pow(endEffector->points[i][0]-(*wireStarts)[i][0],2)+pow(endEffector->points[i][1]-(*wireStarts)[i][1],2)+pow(endEffector->points[i][2]-(*wireStarts)[i][2],2)));
//    }


//    qDebug() << "   "+QString::number((floor(newLine[5])))+"-----"+QString::number(floor(newLine[6]));
//    qDebug() << "    /|      /  |";
//    qDebug() << "   / |     /   |";
//    qDebug() << QString::number(floor(newLine[1]))+"_|____"+QString::number(floor(newLine[2]))+"  |";
//    qDebug() << "  |  |      |  |";
//    qDebug() << "  |  |      |  |";
//    qDebug() << " |  | _____|_"+QString::number(floor(newLine[7]));
//    qDebug() << " |/"+QString::number(floor(newLine[4]))+"     | /";
//    qDebug() << QString::number(floor(newLine[0]))+"______"+QString::number(floor(newLine[3]))+"/";
}

void GLWidget::paintWireStarts()
{
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    for(unsigned int i=0;i<8;i++)
    {
        glVertex3f((*wireStarts)[i][0],(*wireStarts)[i][1],(*wireStarts)[i][2]);
        glVertex3f(endEffector->points[i][0],endEffector->points[i][1],endEffector->points[i][2]);
    }
    glEnd();
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
    //Boxes have 8 points
    //      ---------
    //    / |      /|
    //   /  |     / |
    //  ____|____2  |
    //  |   |    |  |
    //  |   |    |  |
    //  |   1 ___|__
    //  | /      |
    //  __________/
    //
    // TO
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
    glNewList(2,GL_COMPILE);
    for(frame frameItem : robotFrame)
    {
        glm::vec3 p1(frameItem.point1[0],frameItem.point1[1],frameItem.point2[2]);
        glm::vec3 p2(frameItem.point1[0],frameItem.point2[1],frameItem.point2[2]);
        glm::vec3 p3(frameItem.point2[0],frameItem.point2[1],frameItem.point2[2]);
        glm::vec3 p4(frameItem.point2[0],frameItem.point1[1],frameItem.point2[2]);
        glm::vec3 p5(frameItem.point1[0],frameItem.point1[1],frameItem.point1[2]);
        glm::vec3 p6(frameItem.point1[0],frameItem.point2[1],frameItem.point1[2]);
        glm::vec3 p7(frameItem.point2[0],frameItem.point2[1],frameItem.point1[2]);
        glm::vec3 p8(frameItem.point2[0],frameItem.point1[1],frameItem.point1[2]);
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
    glm::vec3 normal;
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
    glBegin(GL_QUADS);
    //Top Face
    glColor3f(1,0,0);

    a = glm::vec3(p2[0],p2[1],p2[2]);
    b = glm::vec3(p3[0],p3[1],p3[2]);
    c = glm::vec3(p7[0],p7[1],p7[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glVertex3f(p2[0],p2[1],p2[2]);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p7[0],p7[1],p7[2]);
    glVertex3f(p6[0],p6[1],p6[2]);
    //Left Face
    glColor3f(0,1,0);

    a = glm::vec3(p2[0],p2[1],p2[2]);
    b = glm::vec3(p6[0],p6[1],p6[2]);
    c = glm::vec3(p5[0],p5[1],p5[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glVertex3f(p2[0],p2[1],p2[2]);
    glVertex3f(p6[0],p6[1],p6[2]);
    glVertex3f(p5[0],p5[1],p5[2]);
    glVertex3f(p1[0],p1[1],p1[2]);
    //Back
    glColor3f(0,0,1);

    a = glm::vec3(p6[0],p6[1],p6[2]);
    b = glm::vec3(p7[0],p7[1],p7[2]);
    c = glm::vec3(p8[0],p8[1],p8[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glVertex3f(p6[0],p6[1],p6[2]);
    glVertex3f(p7[0],p7[1],p7[2]);
    glVertex3f(p8[0],p8[1],p8[2]);
    glVertex3f(p5[0],p5[1],p5[2]);
    //Right

    a = glm::vec3(p3[0],p3[1],p3[2]);
    b = glm::vec3(p4[0],p4[1],p4[2]);
    c = glm::vec3(p8[0],p8[1],p8[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glColor3f(1,1,0);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p4[0],p4[1],p4[2]);
    glVertex3f(p8[0],p8[1],p8[2]);
    glVertex3f(p7[0],p7[1],p7[2]);
    //Near

    a = glm::vec3(p3[0],p3[1],p3[2]);
    b = glm::vec3(p2[0],p2[1],p2[2]);
    c = glm::vec3(p1[0],p1[1],p1[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glColor3f(0,1,1);
    glVertex3f(p3[0],p3[1],p3[2]);
    glVertex3f(p2[0],p2[1],p2[2]);
    glVertex3f(p1[0],p1[1],p1[2]);
    glVertex3f(p4[0],p4[1],p4[2]);
    //Bottom

    a = glm::vec3(p1[0],p1[1],p1[2]);
    b = glm::vec3(p5[0],p5[1],p5[2]);
    c = glm::vec3(p8[0],p8[1],p8[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glColor3f(1,1,1);

    a = glm::vec3(p1[0],p1[1],p1[2]);
    b = glm::vec3(p5[0],p5[1],p5[2]);
    c = glm::vec3(p8[0],p8[1],p8[2]);
    normal = glm::vec3(glm::normalize(glm::cross(c-a,b-a)));
    glNormal3f(normal[0],normal[1],normal[2]);

    glVertex3f(p1[0],p1[1],p1[2]);
    glVertex3f(p5[0],p5[1],p5[2]);
    glVertex3f(p8[0],p8[1],p8[2]);
    glVertex3f(p4[0],p4[1],p4[2]);
    glEnd();
}
