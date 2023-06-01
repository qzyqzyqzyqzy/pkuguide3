#include "movelabel.h"
#include<QDebug>
movelabel::movelabel(const QStringList &imageFiles, const location_direction &b, QWidget *parent) :
    QLabel(parent), imageFiles(imageFiles),a(b)
{
    this->setGeometry(0,0,1618,983);
    this->setScaledContents(true);

    timer.setInterval(500);
    connect(&timer, &QTimer::timeout, this, &movelabel::onTimeout);
    timer.start();
}
void movelabel::onTimeout()
{
    // 如果所有图像都已显示，则停止定时器
    if (currentImageIndex >= imageFiles.size())
    {
        timer.stop();
        clear();
        close();
        emit movefinished(this->a);
        return;
    }
    // 读取下一张图像
    QImageReader reader(imageFiles[currentImageIndex]);
    QImage image = reader.read();
    if (!image.isNull())
        setPixmap(QPixmap::fromImage(image));
    currentImageIndex++;
}
