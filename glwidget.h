#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QtOpenGL>
#include <QTimer>
#include "model.h"
#include <GL/glu.h>

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget *parent=0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void setModel(Model* newModel);
private:
    QTimer timer;
    Model* myModel;
    void createAxisPaint();
    void createRobotFrame();
    void drawBox(double x1, double y1,double z1, double x2, double y2, double z2);
};

#endif // GLWIDGET_H
