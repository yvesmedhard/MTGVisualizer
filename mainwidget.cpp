#include "mainwidget.h"

#include <QMouseEvent>

#include "backengine.h"
#include <math.h>

MainWidget::MainWidget(QWidget *parent) : QOpenGLWidget(parent),
                                          geometries(0),
                                          back(0),
                                          angularSpeed(0)
{
}

MainWidget::~MainWidget()
{
  makeCurrent();
  delete geometries;
  delete back;

  doneCurrent();
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
  mousePressPosition = QVector2D(e->localPos());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
  angularSpeed = 0;
}

void MainWidget::mouseMoveEvent(QMouseEvent *e)
{
  if (e->buttons() & Qt::LeftButton)
  {
    QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

    QVector3D n = QVector3D(diff.y(), diff.x(), 1.0).normalized();

    qreal acc = diff.length() / 1000.0;

    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    if (angularSpeed <= 3){
      angularSpeed += acc;
    }else{
      angularSpeed = 3;
    }
  }
}

void MainWidget::timerEvent(QTimerEvent *)
{
  angularSpeed *= 0.99;

  if (angularSpeed < 0.01)
  {
    angularSpeed = 0.0;
  }
  else
  {
    rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

    update();
  }
}

void MainWidget::initializeGL()
{
  initializeOpenGLFunctions();

  glClearColor(0.3, 0.3, 0.3, 1);

  initShaders();

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);

  geometries = new GeometryEngine;
  back = new BackEngine;

  timer.start(12, this);
}

void MainWidget::initShaders()
{
  if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
    close();

  if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
    close();

  if (!program.link())
    close();

  if (!program.bind())
    close();
}

void MainWidget::resizeGL(int w, int h)
{
  qreal aspect = qreal(w) / qreal(h ? h : 1);

  const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

  projection.setToIdentity();

  projection.perspective(fov, aspect, zNear, zFar);
}

void MainWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  QMatrix4x4 matrix;
  matrix.translate(0.0, 0.0, -5.0);
  matrix.rotate(rotation);

  program.setUniformValue("mvp_matrix", projection * matrix);

  geometries->drawCardGeometry(&program);
  back->drawCardGeometry(&program);
}
