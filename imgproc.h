#ifndef IMGPROC_H
#define IMGPROC_H

#include <QThread>
#include <QImage>

class ImgProc: public QThread
{
    Q_OBJECT
public:
    explicit ImgProc(QString name, QString path);
    void run() override;

signals:
    void ready();//Готовность
private:
    QString path;
    QString name;
    QImage image;
};

#endif // IMGPROC_H
