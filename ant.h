#ifndef ANT_H
#define ANT_H

#include "global.h"
#include <QVector>
#include <QObject>
class Ant : public QObject
{
    Q_OBJECT
public:
    explicit Ant(QObject *parent = nullptr);
    double length;    //路径总长度
    int *Path; //蚂蚁走的路径
    int *vis; //走过城市标记
    int cur_cityno;   //当前城市
    int moved_cnt;    //已走的数量
    int order_cnt;
    QTimer *antTimer;
//    explicit Ant(QObject *parent = nullptr);
    void init();
    int chooseNextCity();
    void move();
    void search();
signals:

};

#endif // ANT_H
