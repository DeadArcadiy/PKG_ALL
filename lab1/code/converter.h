#ifndef CONVERTER_H
#define CONVERTER_H
#include "QVector"
#include "QString"
#include <QColor>

class converter
{
public:
    converter();
    QVector <int> conv (QColor color,QString format);
    QVector <int> toxyz (double r,double g,double b);
    QVector <int> tolab (int x,int y,int z);
    QColor input(QString format,QString value1,QString value2,QString value3,QString value4);
    QColor fromxyz(QString value1,QString value2,QString value3);
    QColor fromlab(QString value1,QString value2,QString value3);
};

#endif // CONVERTER_H
