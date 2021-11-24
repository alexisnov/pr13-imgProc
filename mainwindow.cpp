#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString path = "C:\\tmp\\1";
    dir = QDir(path);
    qDebug() << "Files: " << dir.count();
    ui->label->setText(QString::number(dir.count()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QStringList paths = dir.entryList();
    foreach(QString path,paths){
        ImgProc *imgProc = new ImgProc("imgProc",path);
        imgProc->start();
        threads.append(imgProc);
        connect(imgProc,SIGNAL(ready()),this,SLOT(imgReady()));
    }
}

void MainWindow::imgReady(){
    qDebug() << "Image Ready";
}
