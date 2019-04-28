#include "videowidget.h"
#include "ui_videowidget.h"

#include <QTimer>
#include <QRegion>

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //透过去让屏幕OpenGL区域可点击
//    15 67 14 19  371 825
    QRegion regionAll = QRegion(0,0,371,825);
    QRegion region = QRegion(15,67,342,739);
    ui->cover->setMask(regionAll-region);
    m_server = new Server();
    m_frames.init();
    m_decoder.setFrames(&m_frames);
    ui->video->setFocus();
    connect(m_server, &Server::serverStartResult, this, [this](bool success){
        if (!success) {
            close();
        }
    });

    connect(m_server, &Server::connectToResult, this, [this](bool success, const QString &deviceName, const QSize &size){
        if (success) {
            // update ui
            setWindowTitle(deviceName);
            // init decoder
            m_decoder.setDeviceSocket(m_server->getDeviceSocket());
            m_decoder.startDecode();
            ui->video->setDeviceSocket(m_server->getDeviceSocket());
        }
    });

    connect(m_server, &Server::onServerStop, this, [this](){
        close();
        qDebug() << "server process stop";
    });

    connect(&m_decoder, &Decoder::onDecodeStop, this, [this](){
        close();
        qDebug() << "decoder thread stop";
    });

    // must be Qt::QueuedConnection, ui update must be main thread
    connect(&m_decoder, &Decoder::onNewFrame, this, [this](){
        m_frames.lock();
        const AVFrame *frame = m_frames.consumeRenderedFrame();
        //qDebug() << "widthxheight:" << frame->width << "x" << frame->height;

        ui->video->setFrameSize(QSize(frame->width, frame->height));
        ui->video->updateTextures(frame->data[0], frame->data[1], frame->data[2], frame->linesize[0], frame->linesize[1], frame->linesize[2]);
        m_frames.unLock();
    },Qt::QueuedConnection);
    QTimer::singleShot(0, this, [this](){
        // max size support 480p 720p 1080p 设备原生分辨率
        // support wireless connect, example:
        //m_server->start("192.168.0.174:5555", 27183, m_maxSize, m_bitRate, "");
        // only one devices, serial can be null
        // mark: crop input format: "width:height:x:y" or - for no crop, for example: "100:200:0:0"
        // sendFrameMeta for recorder mp4
        m_server->start("e98d7a87", 27183, 0, 10000000, "-", false);
    });
}

VideoWidget::~VideoWidget()
{
    delete ui;
}

//void VideoWidget::mousePressEvent(QMouseEvent *event)
//{

//}

//void VideoWidget::mouseReleaseEvent(QMouseEvent *event)
//{

//}

//void VideoWidget::mouseMoveEvent(QMouseEvent *event)
//{

//}
