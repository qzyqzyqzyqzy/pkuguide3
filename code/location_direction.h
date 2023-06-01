#ifndef LOCATION_DIRECTION_H
#define LOCATION_DIRECTION_H

#include <QObject>

class location_direction : public QObject
{
    Q_OBJECT
public:
    explicit location_direction();
    int x;
    int y;//x y的坐标信息
    int dx;
    int dy;//角度信息（01）（10）（0-1）（-10）四
    explicit location_direction(int a,int b,int c,int d,QObject *parent = 0);
    location_direction(const location_direction& s);


        bool operator<(const location_direction& aa)const;
        void operator=(const location_direction& aa);
        bool operator==(const location_direction& aa);
signals:

public slots:
};

#endif // LOCATION_DIRECTION_H
