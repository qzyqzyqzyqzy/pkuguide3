#include "mymainwindow.h"
#include <QApplication>
#include"location_direction.h"
#include<QMap>
#include<QDebug>
QMap<location_direction,int> map;
location_direction nowlocation_direction(0,0,0,1);//定义一个现在位置方向状态的对象，不需要父对象
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    map.insert(location_direction(0,0,0,1),0);
//    map.insert(location_direction(0,0,1,0),1);
//    map.insert(location_direction(0,0,-1,0),2);
//    map.insert(location_direction(0,1,0,1),3);


    MyMainWindow w;
    QMap<location_direction, int>::const_iterator i = map.constBegin();
       while (i != map.constEnd()) {
           qDebug() << i.key().x <<i.key().y<<i.key().dx<<i.key().dy<< i.value();
           ++i;
       }
    w.show();

    return a.exec();
}
