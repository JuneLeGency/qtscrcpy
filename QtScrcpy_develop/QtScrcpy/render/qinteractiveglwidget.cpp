#include "qinteractiveglwidget.h"

QInteractiveGLWidget::QInteractiveGLWidget(QWidget * parent):QYUVOpenGLWidget(parent)
{

}

void QInteractiveGLWidget::setDeviceSocket(DeviceSocket *socket)
{
    m_inputConvert.setDeviceSocket(socket);
}

void QInteractiveGLWidget::mousePressEvent(QMouseEvent *event)
{

    m_inputConvert.mouseEvent(event, frameSize(), size());
}

void QInteractiveGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_inputConvert.mouseEvent(event, frameSize(), size());
}

void QInteractiveGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_inputConvert.mouseEvent(event, frameSize(), size());
}

void QInteractiveGLWidget::wheelEvent(QWheelEvent *event)
{
    m_inputConvert.wheelEvent(event, frameSize(), size());
}

void QInteractiveGLWidget::keyPressEvent(QKeyEvent *event)
{
    m_inputConvert.keyEvent(event, frameSize(), size());
}

void QInteractiveGLWidget::keyReleaseEvent(QKeyEvent *event)
{
    m_inputConvert.keyEvent(event, frameSize(), size());
}

void QInteractiveGLWidget::dragEnterEvent(QDragEnterEvent *event)
{

}

void QInteractiveGLWidget::dragMoveEvent(QDragMoveEvent *event)
{

}

void QInteractiveGLWidget::dragLeaveEvent(QDragLeaveEvent *event)
{

}

void QInteractiveGLWidget::dropEvent(QDropEvent *event)
{

}
