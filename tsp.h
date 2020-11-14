#ifndef TSP_H
#define TSP_H

#include <QObject>
#include "global.h"
#include "ant.h"

class Tsp : public QObject
{
    Q_OBJECT
public:
    explicit Tsp(QObject *parent = nullptr);
    QVector <Ant*> ants;  //定义一群蚂蚁
    Ant *ant_best;       //保存最好结果的蚂蚁
    void init();
    void updateInfo();
    void search();
    Global g;
    void test(QWidget*);
signals:

};

#endif // TSP_H
