#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>

#include <memory>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    explicit OpenGLWidget (QWidget *parent = 0);
    ~OpenGLWidget();

    void createVBOs();
    void createShaders();

    void destroyVBOs();
    void destroyShaders();

protected:
    void initializeGL();
    void resizeGL (int width, int height);
    void paintGL();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public slots:
    void animate();

};
#endif
