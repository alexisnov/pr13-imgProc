#include "imgproc.h"

//Конструктор - загрузка картинки
ImgProc::ImgProc(QString name,QString path): name(name),path(path)
{
    bool res = image.load(path);
    if(res){
        //TODO: обработка ошибки загрузки изображения
    }
}

void ImgProc::run(){
    //Обработка картинки
    image = image.scaled(QSize(image.width()/2,image.height()/2));
    image.save(path);
    //Сигнал готовности
    emit ready();
}
