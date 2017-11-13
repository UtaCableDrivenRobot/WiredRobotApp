#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QtOpenGL>
#include <gl/GLU.h>

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget *parent=0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // GLWIDGET_H
