#ifndef CITY_H
#define CITY_H

#include <QPushButton>
#define ICON 50
class City : public QPushButton
{
    Q_OBJECT
public:
//    explicit City(QWidget *parent = nullptr);
    int posX;
    int posY;
    int label;
    friend class Ant;
    City(QString name);
    void setVisit(QString color);

signals:

};

#endif // CITY_H
