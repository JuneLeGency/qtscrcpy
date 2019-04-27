#ifndef VIDEOWIDET_H
#define VIDEOWIDET_H

#include <QWidget>
#include <decoder.h>
#include <frames.h>
#include <server.h>

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = nullptr);
    ~VideoWidget();

private:
    Ui::VideoWidget *ui;
    Server* m_server = Q_NULLPTR;
    Decoder m_decoder;
    Frames m_frames;
protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
};

#endif // VIDEOWIDET_H
