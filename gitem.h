#ifndef GITEM_H
#define GITEM_H
#include <QGraphicsItem>
#include <QPainter>

class GItem: public QGraphicsItem
{
private:

    int id;
    QString name;
    QString type;
public:
    GItem(int _id, QString _name, QString _type);
    GItem(const GItem &gi);
    static const int width = 100;
    static const int height = 50;

    QString getType() const;
    void setType(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    int getId() const;
    void setId(int value);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    //GItem& operator =(const GItem&);
    int getIndex(int id);
};

#endif // GITEM_H
