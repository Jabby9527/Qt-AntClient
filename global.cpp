#include "global.h"

int CITY_NUM=0;  //城市数量
int ANT_NUM=0;   //蚁群数量
int TMAX=0;  //迭代最大次数
float ROU=0;     //误差大小
int ALPHA=0;     // 信息素重要程度的参数
int BETA=0;     // 启发式因子重要程度的参数
int Q=0; //信息素残留参数
int SP=0;//起点城市
double **dis;        //距离
double **info;  //信息素矩阵
bool initmap=false;
int **cityCoord;
QVector<City*> city_list;

//double E[CITY_NUM][CITY_NUM]; //启发因子矩阵
//int vis[CITY_NUM][CITY_NUM];

void Global::init(int al,int be,int q,float rou,int an,int cn,int tmax,int sp){
    CITY_NUM=cn;
    ANT_NUM=an;
    TMAX=tmax;
    ROU=rou;
    ALPHA=al;
    BETA=be;
    Q=q;
    SP=sp;
    dis=new double*[cn];
    info=new double*[cn];
    cityCoord=new int *[cn];

    for (int i = 0; i <cn; ++i){
        dis[i]=new double[cn];
        info[i]=new double[cn];
        cityCoord[i]=new int[2];
    }
}

//返回指定范围内的随机整数
int Global::rnd(int nLow, int nUpper) {
    return nLow + (nUpper - nLow) * rand() / (RAND_MAX + 1);
}

//返回指定范围内的随机浮点数
double Global::rnd(double dbLow, double dbUpper) {
    double dbTemp = rand() / ((double) RAND_MAX + 1.0);
    return dbLow + dbTemp * (dbUpper - dbLow);
}

//返回浮点数四舍五入取整后的浮点数
double Global::ROUND(double dbA) {
    return (double) ((int) (dbA + 0.5));
}
