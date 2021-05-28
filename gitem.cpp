#include "gitem.h"

int GItem::getId() const
{
    return id;
}

void GItem::setId(int value)
{
    id = value;
}

QRectF GItem::boundingRect() const
{
    return QRectF(0,0,this->width,this->height);
}

void GItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(0,0,this->width,this->height);
    painter->drawRect(0,0,this->width,this->height/3);
    painter->drawRect(0,0,this->width/5,this->height/3);

    painter->drawLine(this->width,0,this->width+10,-10);
    painter->drawLine(this->width,this->height,this->width+10,this->height-10);
    painter->drawLine(0,0,10,-10);
    painter->drawLine(this->width+10,this->height-10,this->width+10,-10);
    painter->drawLine(10,-10,this->width+10,-10);

    painter->drawText(QRect(0,0,20,20),Qt::AlignCenter,QString::number(id));
    painter->drawText(QRect(25,0,width*4/5,20),Qt::AlignCenter,type);
    painter->drawText(QRect(width/10,20,80,30),Qt::AlignCenter,name);
}

QString GItem::getName() const
{
    return name;
}

void GItem::setName(const QString &value)
{
    name = value;
}

GItem::GItem(int _id, QString _name, QString _type)
{
    id = _id;
    name = _name;
    type = _type;
}

GItem::GItem(const GItem &gi)
{
    GItem(gi.getId(),gi.getName(),gi.getType());
}

QString GItem::getType() const
{
    return type;
}

void GItem::setType(const QString &value)
{
    type = value;
}

/*GItem &GItem::operator =(const GItem &gi)
{
    this->setX(gi.x());
    this->setY(gi.y());
    this->setId(gi.getId());
    this->setName(gi.getName());
    this->setType(gi.getType());
}*/


