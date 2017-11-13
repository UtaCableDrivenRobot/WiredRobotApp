#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QtOpenGL>
#include <gl/GLU.h>
#include <QTimer>

class GLWidget : public QGLWidget
{
public:
    explicit GLWidget(QWidget *parent=0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void testUpdate(int x);
private:
    int x = 0;
    QTimer timer;
};

#endif // GLWIDGET_H
