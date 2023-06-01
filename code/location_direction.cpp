#include "location_direction.h"

location_direction::location_direction()
{

}

location_direction::location_direction(int a,int b,int c, int d,QObject *parent) : QObject(parent)
{
        x=a;
        y=b;
        dx=c;
        dy=d;

}
location_direction::location_direction(const location_direction& s):QObject()
{
    this->x=s.x;
    this->y=s.y;
    this->dx=s.dx;
    this->dy=s.dy;

}
void location_direction::operator =(const location_direction& aa)
{
    this->x=aa.x;
    this->y=aa.y;
    this->dx=aa.dx;
    this->dy=aa.dy;
}
bool location_direction::operator ==(const location_direction& aa)
{
    return (this->x==aa.x&&this->y==aa.y);
}
bool location_direction::operator<(const location_direction& aa)const
{
    if(this->x<aa.x)
        return true;
    else if(this->x==aa.x)
    {
        if(this->y<aa.y)
            return true;
        else if(this->y==aa.y)
        {
            if(this->dx<aa.dx)
                return true;
            else if(this->dx==aa.dx)
            {
                if(this->dy<aa.dy)
                    return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
