#ifndef WIDGET_VISITORPAGE_H
#define WIDGET_VISITORPAGE_H
#include<QStackedWidget>
#include <QWidget>
#include<QToolButton>
#include<QVBoxLayout>
#include<QFont>
#include<QLabel>
#include<QMovie>
#include"movelabel.h"
#include<QMap>
class widget_visitorpage : public QWidget
{
    Q_OBJECT
public:
    explicit widget_visitorpage(QWidget *parent = 0);
    QStackedWidget *StackedWidget_visitorview;
    QToolButton *button_left;
    QToolButton *button_ahead;
    QToolButton *button_right;
    QVBoxLayout *Layout;
    QWidget *Widget_movie;
    QLabel *label_movie;
    QMovie *movie;
signals:

public slots:
    void Left();
    void Right();
    void Ahead();
    void shiftaftermove(const location_direction &b);
};

#endif // WIDGET_VISITORPAGE_H
