#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{

}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1, 0, 1, 1);
}

void OpenGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenGLWidget::paintGL()
{
}

void OpenGLWidget::createShaders()
{
}

void OpenGLWidget::destroyShaders()
{
}

void OpenGLWidget::createVBOs()
{
}

void OpenGLWidget::animate()
{
}

// Strong focus is required
void OpenGLWidget::keyPressEvent(QKeyEvent *event)
{
}

void OpenGLWidget::keyReleaseEvent(QKeyEvent *event)
{
}
