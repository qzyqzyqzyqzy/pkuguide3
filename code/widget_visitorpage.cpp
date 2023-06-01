#include "widget_visitorpage.h"
//#include"movelabel.h"
#include"location_direction.h"
#include<QMap>
#include<QMovie>
#include<QDebug>
#include<QStringList>
extern QString path;
extern QMap<location_direction,int> map;
extern location_direction nowlocation_direction;
widget_visitorpage::widget_visitorpage(QWidget *parent) : QWidget(parent)
{
     StackedWidget_visitorview=new QStackedWidget(this);
     StackedWidget_visitorview->setGeometry(0,0,1618,983);
     StackedWidget_visitorview->setObjectName(QStringLiteral("StackedWidget_visitor"));
     Widget_movie = new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(Widget_movie);//编号为0的一页专门播放动画
     label_movie= new QLabel(Widget_movie);
     label_movie->setGeometry(0,0,1618,983);
     //label_movie->setText("dbvbwv");
     button_left = new QToolButton(this);
     button_left->setText(tr("Left"));
     button_left->setObjectName(QStringLiteral("button_left"));
     button_left->setGeometry(QRect(200, 750, 300, 150));
     button_left->setStyleSheet(QStringLiteral(""));
     button_ahead = new QToolButton(this);
     button_ahead->setText(tr("Ahead"));
     button_ahead->setObjectName(QStringLiteral("button_ahead"));
     button_ahead->setGeometry(QRect(500, 750, 300, 150));
     button_right = new QToolButton(this);
     button_right->setText(tr("Right"));
     button_right->setObjectName(QStringLiteral("button_right"));
     button_right->setGeometry(QRect(800, 750, 300, 150));
     QFont font;//设置字体
     font.setFamily(QStringLiteral("Kristen ITC"));
     font.setPointSize(28);
     font.setBold(true);
     font.setWeight(75);
     button_ahead->setFont(font);
     button_left->setFont(font);
     button_right->setFont(font);
     connect(button_left,SIGNAL(clicked(bool)),this,SLOT(Left()));
     connect(button_ahead,SIGNAL(clicked(bool)),this,SLOT(Ahead()));
     connect(button_right,SIGNAL(clicked(bool)),this,SLOT(Right()));
     int k=1;
     for(int i=0;i<=60;i++)
     {

         QWidget *page = new QWidget(StackedWidget_visitorview);
         StackedWidget_visitorview->addWidget(page);
         QLabel *img= new QLabel(page);
         img->setGeometry(0,0,1618,983);
         img->setPixmap(QPixmap(QString(path+"img0_"+QString::number(i*10)+"_0_1")));
         img->setScaledContents(true);
         map.insert(location_direction(0,i*10,0,1),k++);

     }
     for(int i=0;i<=23;i++)
     {

         QWidget *page = new QWidget(StackedWidget_visitorview);
         StackedWidget_visitorview->addWidget(page);
         QLabel *img= new QLabel(page);
         img->setGeometry(0,0,1618,983);
         img->setPixmap(QPixmap(QString(path+"img"+QString::number(i*10)+"_600_1_0")));
         img->setScaledContents(true);
         map.insert(location_direction(i*10,600,1,0),k++);

     }
     for(int i=60;i>=58;i--)
     {

         QWidget *page = new QWidget(StackedWidget_visitorview);
         StackedWidget_visitorview->addWidget(page);
         QLabel *img= new QLabel(page);
         img->setGeometry(0,0,1618,983);
         img->setPixmap(QPixmap(QString(path+"img230_"+QString::number(i*10)+"_0_i1")));
         img->setScaledContents(true);
         map.insert(location_direction(230,i*10,0,-1),k++);

     }


     movie = new QMovie();
     label_movie->setMovie(movie);
     StackedWidget_visitorview->setCurrentIndex(1);
     //nowlocation_direction.y=600;

}
void widget_visitorpage::Left()
{
    this->StackedWidget_visitorview->setCurrentIndex(0);
    int xx,yy;
    xx=-nowlocation_direction.dy;
    yy=nowlocation_direction.dx;
    QString moviepath=path+"left"+QString::number(nowlocation_direction.x)+"_"+QString::number(nowlocation_direction.y)+"_";
    moviepath=moviepath+QString::number(nowlocation_direction.dx).replace("-","i")+"_"+QString::number(nowlocation_direction.dy).replace("-","i");
    moviepath=moviepath+"to"+QString::number(xx).replace("-","i")+"_"+QString::number(yy).replace("-","i")+".gif";
    qDebug()<<moviepath;
    nowlocation_direction.dx=xx;
    nowlocation_direction.dy=yy;
    int newindex=map[nowlocation_direction];
    this->movie->setFileName(moviepath);
    this->label_movie->setScaledContents(true);
    this->movie->start();
    connect(this->movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber == movie->frameCount() - 1) {
            movie->stop();
            this->StackedWidget_visitorview->setCurrentIndex(newindex);
        }
    });
    if(map.contains(location_direction(nowlocation_direction.x+10*nowlocation_direction.dx,nowlocation_direction.y+10*nowlocation_direction.dy,nowlocation_direction.dx,nowlocation_direction.dy)))
        this->button_ahead->raise(); //setEnabled(true);
    else this->button_ahead->lower();//setEnabled(false);
    if(map.contains(location_direction(nowlocation_direction.x,nowlocation_direction.y,nowlocation_direction.dy,-nowlocation_direction.dx)))
        this->button_right->raise();  //setEnabled(true);
    else this->button_right->lower();    //setEnabled(false);
    if(map.contains(location_direction(nowlocation_direction.x,nowlocation_direction.y,-nowlocation_direction.dy,nowlocation_direction.dx)))
        this->button_left->raise(); //setEnabled(true);
    else this->button_left->lower();//setEnabled(false);

}
void widget_visitorpage::shiftaftermove(const location_direction &b)
{
    this->StackedWidget_visitorview->setCurrentIndex(map[b]);
}

void widget_visitorpage::Right()
{
    this->StackedWidget_visitorview->setCurrentIndex(0);
    int xx,yy;
    xx=nowlocation_direction.dy;
    yy=-nowlocation_direction.dx;
    QString moviepath=path+"right"+QString::number(nowlocation_direction.x)+"_"+QString::number(nowlocation_direction.y)+"_";
    moviepath=moviepath+QString::number(nowlocation_direction.dx).replace("-","i")+"_"+QString::number(nowlocation_direction.dy).replace("-","i");
    moviepath=moviepath+"to"+QString::number(xx).replace("-","i")+"_"+QString::number(yy).replace("-","i")+".gif";
    qDebug()<<moviepath;
    nowlocation_direction.dx=xx;
    nowlocation_direction.dy=yy;
    int newindex=map[nowlocation_direction];
    this->movie->setFileName(moviepath);
    this->label_movie->setScaledContents(true);
    this->movie->start();
    connect(this->movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber == movie->frameCount() - 1) {
            movie->stop();
            this->StackedWidget_visitorview->setCurrentIndex(newindex);
        }
    });
    if(map.contains(location_direction(nowlocation_direction.x+10*nowlocation_direction.dx,nowlocation_direction.y+10*nowlocation_direction.dy,nowlocation_direction.dx,nowlocation_direction.dy)))
        this->button_ahead->raise(); //setEnabled(true);
    else this->button_ahead->lower();//setEnabled(false);
    if(map.contains(location_direction(nowlocation_direction.x,nowlocation_direction.y,nowlocation_direction.dy,-nowlocation_direction.dx)))
        this->button_right->raise();  //setEnabled(true);
    else this->button_right->lower();    //setEnabled(false);
    if(map.contains(location_direction(nowlocation_direction.x,nowlocation_direction.y,-nowlocation_direction.dy,nowlocation_direction.dx)))
        this->button_left->raise(); //setEnabled(true);
    else this->button_left->lower();//setEnabled(false);
}
void widget_visitorpage::Ahead()
{

    qDebug()<<nowlocation_direction.x<<nowlocation_direction.y<<nowlocation_direction.dx<<nowlocation_direction.dy;
    nowlocation_direction.x+=nowlocation_direction.dx*10;
    nowlocation_direction.y+=nowlocation_direction.dy*10;
    this->StackedWidget_visitorview->setCurrentIndex(map[nowlocation_direction]);
    if(map.contains(location_direction(nowlocation_direction.x+10*nowlocation_direction.dx,nowlocation_direction.y+10*nowlocation_direction.dy,nowlocation_direction.dx,nowlocation_direction.dy)))
       {

        this->button_ahead->raise();// setEnabled(true);

    }
    else this->button_ahead->lower();// setEnabled(false);
    if(map.contains(location_direction(nowlocation_direction.x,nowlocation_direction.y,nowlocation_direction.dy,-nowlocation_direction.dx)))
        this->button_right->raise();// setEnabled(true);
    else this->button_right->lower();// setEnabled(false);
    if(map.contains(location_direction(nowlocation_direction.x,nowlocation_direction.y,-nowlocation_direction.dy,nowlocation_direction.dx)))
        this->button_left->raise(); //setEnabled(true);
    else this->button_left->lower();//setEnabled(false);
}
