#ifndef MOVELABEL_H
#define MOVELABEL_H
#include<QLabel>
#include<QTimer>
#include<QImageReader>
#include"location_direction.h"
class movelabel : public QLabel
{
    Q_OBJECT

public:
    movelabel(const QStringList &imageFiles, const location_direction &b, QWidget *parent = nullptr);
    location_direction a;
signals:
    void movefinished(const location_direction &a);
private slots:
    void onTimeout();

private:
    QStringList imageFiles;
    int currentImageIndex = 0;
    QTimer timer;
};

#endif // MOVELABEL_H

