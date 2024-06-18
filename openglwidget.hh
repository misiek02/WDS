#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include "model3d.hh""
class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
public:
    OpenGLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        model3D.initialize();
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
        projection.setToIdentity();
        projection.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
    }

    void paintGL() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        view.setToIdentity();
        view.translate(0.0f, 0.0f, -5.0f);
        model3D.draw(projection * view);
    }

private:
    QMatrix4x4 projection;
    QMatrix4x4 view;
    Model3D model3D;
};

#endif // OPENGLWIDGET_H
