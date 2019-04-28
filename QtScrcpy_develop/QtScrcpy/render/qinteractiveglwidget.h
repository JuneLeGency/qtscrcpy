#ifndef INTERACTIVEGLWIDGET_H
#define INTERACTIVEGLWIDGET_H

#include "qyuvopenglwidget.h"
#include "inputconvertgame.h"
class QInteractiveGLWidget : public QYUVOpenGLWidget
{
    Q_OBJECT
public:
    explicit QInteractiveGLWidget(QWidget * parent= nullptr);
    void setDeviceSocket(DeviceSocket *socket);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);


    InputConvertGame m_inputConvert;

};

#endif // INTERACTIVEGLWIDGET_H
