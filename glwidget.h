#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QtOpenGL>
#include <gl/GLU.h>
#include <QTimer>
#include "model.h"

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
};

#endif // GLWIDGET_H
