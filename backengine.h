#ifndef BACKENGINE_H
#define BACKENGINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLTexture>

class BackEngine : protected QOpenGLFunctions
{
public:
    BackEngine();
    virtual ~BackEngine();

    void drawCardGeometry(QOpenGLShaderProgram *program);

private:
    void initCardGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLTexture *back_texture;

};

#endif // BACKENGINE_H
