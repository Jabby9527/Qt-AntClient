#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include "global.h"
#include "ant.h"
#include "city.h"

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();
    void showMap();
    void destroyCity();

    static QVector<City *>  cityList;
    int cnt;
    friend class Ant;
//    void paintEvent(QPaintEvent *event);

private:
    Ui::Map *ui;
};

#endif // MAP_H
