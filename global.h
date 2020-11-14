#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QVector>
#include <QTimer>
#include <QPainter>
#include <city.h>

using namespace std;
//extern double E[CITY_NUM][CITY_NUM]; //启发因子矩阵
//extern int vis[CITY_NUM][CITY_NUM];
#define MMAX 10e9
#define GAP_TIME 500
extern double **dis;        //距离
extern double **info;  //信息素矩阵
extern int CITY_NUM;  //城市数量
extern int ANT_NUM;   //蚁群数量
extern int TMAX;  //迭代最大次数
extern float ROU;     //误差大小
extern int ALPHA;     // 信息素重要程度的参数
extern int BETA;     // 启发式因子重要程度的参数
extern int Q; //信息素残留参数
extern int SP;
extern bool initmap;
extern int **cityCoord;
extern QTimer *mapTimer;
extern QVector<City*> city_list;

class Global {
public:
    static int rnd(int nLow, int nUpper);
    static double rnd(double dbLow, double dbUpper);
    static double ROUND(double dbA);
    void init(int al,int be,int q,float rou,int an,int cn,int tmax,int sp=-1);
};

#endif // GLOBAL_H

