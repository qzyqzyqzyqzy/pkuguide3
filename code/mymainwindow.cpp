#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include<QMap>
#include<QDebug>
#include"location_direction.h"
QString path="C:/Users/86139/Desktop/pkuguide3/img/";
extern QMap<location_direction,int> map;
QMap<QString,location_direction> guidemap;
extern location_direction nowlocation_direction;
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("PKU GUIDE"));
    this->setMinimumSize(QSize(1618, 1000));
    this->setMaximumSize(QSize(1618, 1000));
    action_Back=new QAction(tr("Back"),this);
    action_Exit=new QAction(tr("Exit"),this);
    action_Help=new QAction(tr("Help"),this);
    action_Back->setObjectName(QStringLiteral("action_Back"));
    action_Exit->setObjectName(QStringLiteral("action_Exit"));
    action_Help->setObjectName(QStringLiteral("action_Help"));
    QMenu *menu=new QMenu(tr("Menu"),this);
    QMenuBar *menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);
    menuBar->setStyleSheet("QMenuBar::icon { visibility: hidden; }");
    menuBar->addMenu(menu);
    menu->setTearOffEnabled(false);
    menu->setStyleSheet("QMenu::icon { width: 0px; }");
    menu->addAction(action_Back);
    menu->addAction(action_Exit);
    menu->addAction(action_Help);
    connect(action_Back,SIGNAL(triggered(bool)),this,SLOT(actionBack()));
    connect(action_Exit,SIGNAL(triggered(bool)),this,SLOT(actionExit()));
    connect(action_Help,SIGNAL(triggered(bool)),this,SLOT(actionHelp()));
    StackedWidget_mainfunctionpage=new QStackedWidget(ui->centralWidget);
    this->setCentralWidget(ui->centralWidget);
    Widget_startpage=new QWidget();
    Widget_startpage->setGeometry(QRect(0,0,1618,983));
    StackedWidget_mainfunctionpage->addWidget(Widget_startpage);
    StackedWidget_mainfunctionpage->setObjectName(QStringLiteral("StackedWidget_mainfunctionpage"));
    StackedWidget_mainfunctionpage->setGeometry(QRect(0, 0, 1618, 983));
    StackedWidget_mainfunctionpage->setMaximumSize(1618,983);
    StackedWidget_mainfunctionpage->setMinimumSize(1618,983);
    button_guide=new QToolButton(Widget_startpage) ;
    connect(button_guide,SIGNAL(clicked(bool)),this,SLOT(guideskip()));
    button_visitor=new QToolButton(Widget_startpage);
    connect(button_visitor,SIGNAL(clicked(bool)),this,SLOT(visitorskip()));
    label_startpageimg=new QLabel(Widget_startpage);
    button_guide->raise();
    button_visitor->raise();
    Widget_startpage->setObjectName(QStringLiteral("Widget_startpage"));
    button_guide->setObjectName(QStringLiteral("button_guide"));
    button_guide->setText(tr("Guide Mode"));
    button_guide->setGeometry(QRect(370, 800, 400, 200));
    QFont font;//设置字体
    font.setFamily(QStringLiteral("Kristen ITC"));
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    button_guide->setFont(font);
    button_guide->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0)"));//透明背景
    button_visitor->setObjectName(QStringLiteral("button_visitor"));
    button_visitor->setText(tr("Visitor Mode"));
    button_visitor->setGeometry(QRect(850, 800, 400, 200));
    button_visitor->setFont(font);
    button_visitor->setStyleSheet(QStringLiteral("background-color: rbga(0,0,0,0);"));
    label_startpageimg->setObjectName(QStringLiteral("label_startpageimg"));
    label_startpageimg->setGeometry(QRect(0, 0, 1618, 983));
    label_startpageimg->setStyleSheet(QStringLiteral("background-color: transparent; border: 1px solid black;"));
    label_startpageimg->setPixmap(QPixmap(QString(path+"westgate.jpg")));
    label_startpageimg->setScaledContents(true);
    Widget_guidepage=new QWidget();
    StackedWidget_mainfunctionpage->addWidget(Widget_guidepage);
    Widget_guidepage->setObjectName(QStringLiteral("Widget_guidepage"));
    box_start = new QComboBox(Widget_guidepage);
    box_start->setObjectName(QStringLiteral("box_start"));
    box_start->setGeometry(QRect(300, 100, 400, 40));
    box_start->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    box_end = new QComboBox(Widget_guidepage);
    box_end->setObjectName(QStringLiteral("box_end"));
    box_end->setGeometry(QRect(300, 200, 400, 40));
    box_end->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    box_start->clear();
    box_start->insertItems(0, QStringList()
             << QApplication::translate("MyMainWindow", "teachingbuilding", Q_NULLPTR)
             << QApplication::translate("MyMainWindow", "canteen", Q_NULLPTR)
            );
    box_end->clear();
    box_end->insertItems(0, QStringList()
             << QApplication::translate("MyMainWindow", "teachingbuilding", Q_NULLPTR)
             << QApplication::translate("MyMainWindow", "canteen", Q_NULLPTR)
            );
    QLabel *label_startpoint = new QLabel(Widget_guidepage);
    label_startpoint->setText(tr("Start from"));
    label_startpoint->setObjectName(QStringLiteral("label_startpoint"));
    label_startpoint->setGeometry(QRect(80, 100, 200, 40));
    label_startpoint->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    label_startpoint->setScaledContents(true);
    QLabel *label_endpoint = new QLabel(Widget_guidepage);
    label_endpoint->setText(tr("End   at"));
    label_endpoint->setObjectName(QStringLiteral("endpoint"));
    label_endpoint->setGeometry(QRect(80, 200, 200, 40));
    label_endpoint->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    label_endpoint->setTextFormat(Qt::AutoText);
    label_endpoint->setScaledContents(true);
    QLabel *label_guidepageimg = new QLabel(Widget_guidepage);
    label_guidepageimg->lower();
    label_guidepageimg->setObjectName(QStringLiteral("guidepageimg"));
    label_guidepageimg->setGeometry(QRect(0, 0, 1618, 1800));
    label_guidepageimg->setPixmap(QPixmap((path+"guidepageimg.jpg")));
    label_guidepageimg->setScaledContents(true);
    button_startguide = new QToolButton(Widget_guidepage);
    button_startguide->setObjectName(QStringLiteral("startguide"));
    button_startguide->setText(tr("Start"));
    button_startguide->setGeometry(QRect(700, 80, 400, 200));
    button_startguide->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);font: 75 16pt \"Kristen ITC\";"));
    Widget_visitorpage=new widget_visitorpage();
    StackedWidget_mainfunctionpage->addWidget(Widget_visitorpage);
    connect(button_startguide,SIGNAL(clicked(bool)),this,SLOT(guide()) );
    guidemap.insert("canteen",location_direction(0,0,0,1));
    guidemap.insert("teachingbuilding",location_direction(0,300,0,1));
    time =new QTimer(this);
    connect(time,&QTimer::timeout,this,&MyMainWindow::ontimeout);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
void MyMainWindow::actionExit()
{
    this->close();
}
void MyMainWindow::actionBack()
{
    this->StackedWidget_mainfunctionpage->setCurrentIndex(0);

}
void MyMainWindow::actionHelp()
{

}
void MyMainWindow::visitorskip()
{
    this->StackedWidget_mainfunctionpage->setCurrentIndex(2);
     this->Widget_visitorpage->StackedWidget_visitorview->setCurrentIndex(0);
    nowlocation_direction=location_direction(0,0,0,1);
}
void MyMainWindow::guideskip()
{
    this->StackedWidget_mainfunctionpage->setCurrentIndex(1);
}
void MyMainWindow::ontimeout()
{
    if(!(timeoutlocation_direction==timeoutlocation_directionend))
    {
        timeoutlocation_direction.x+=10*timeoutdx;
        timeoutlocation_direction.y+=10*timeoutdy;
        this->Widget_visitorpage->StackedWidget_visitorview->setCurrentIndex(map[timeoutlocation_direction]);
    }
    else
    {
        time->stop();
        timestop=true;
    }
}

void MyMainWindow::guide()
{
    timestop=false;
    QString start=this->box_start->currentText();
    QString end=this->box_end->currentText();
    if(start==end)return;
    this->StackedWidget_mainfunctionpage->setCurrentIndex(2);
    this->Widget_visitorpage->StackedWidget_visitorview->setCurrentIndex(0);
    this->Widget_visitorpage->button_ahead->lower();
    this->Widget_visitorpage->button_left->lower();
    this->Widget_visitorpage->button_right->lower();

    this->timeoutlocation_direction=location_direction(guidemap[start]);
    this->timeoutlocation_directionend=location_direction(guidemap[end]);
    //把这两个location_dirction输入后得到一个QVector，依次是经过的结点，并且保证两个相邻节点都是以直线连接的
    //这里以头尾在一条直线上为例子
    //实际上，应该用timeoutlocation_direction 与vector中的元素一一进行下述操作。
//    for(...)
//    {
//        int lx=timeoutlocation_directionend.x-timeoutlocation_direction.x;
//        if(lx==0)timeoutdx=0;
//        else if(lx>0)timeoutdx=1;
//        else timeoutdx=-1;
//        int ly=timeoutlocation_directionend.y-timeoutlocation_direction.y;
//        if(ly==0)timeoutdy=0;
//        else if(ly>0)timeoutdy=1;
//        else timeoutdy=-1;
//        time->start();
//        while(!timestop)
//        {
//            QCoreApplication::processEvents();
//        }

//    }
    time->start(200);
    int lx=timeoutlocation_directionend.x-timeoutlocation_direction.x;
    if(lx==0)timeoutdx=0;
    else if(lx>0)timeoutdx=1;
    else timeoutdx=-1;
    int ly=timeoutlocation_directionend.y-timeoutlocation_direction.y;
    if(ly==0)timeoutdy=0;
    else if(ly>0)timeoutdy=1;
    else timeoutdy=-1;
    while(!timestop)
            {
                QCoreApplication::processEvents();
            }
    qDebug()<<this->timeoutlocation_direction.y<<"   "<<this->timeoutlocation_directionend.y;
    this->StackedWidget_mainfunctionpage->setCurrentIndex(1);
    this->Widget_visitorpage->button_ahead->raise();
    this->Widget_visitorpage->button_left->raise();
    this->Widget_visitorpage->button_right->raise();
}
