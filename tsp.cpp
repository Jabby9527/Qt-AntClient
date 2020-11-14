#include "tsp.h"

static int CityPos[30][2] = {{87, 7},
                      {91, 38},
                      {83, 46},
                      {71, 44},
                      {64, 60},
                      {68, 58},
                      {83, 69},
                      {87, 76},
                      {74, 78},
                      {71, 71},
                      {58, 69},
                      {54, 62},
                      {51, 67},
                      {37, 84},
                      {41, 94},
                      {2,  99},
                      {7,  64},
                      {22, 60},
                      {25, 62},
                      {18, 54},
                      {4,  50},
                      {13, 40},
                      {18, 40},
                      {24, 42},
                      {25, 38},
                      {41, 26},
                      {45, 21},
                      {44, 35},
                      {58, 35},
                      {62, 32}};

Tsp::Tsp(QObject *parent) : QObject(parent){

}
void Tsp::init() {
    for(int i=0;i<ANT_NUM;i++){
        ants.push_back(new Ant(this));
    }
    //初始化为最大值
    ant_best->length = MMAX;
    puts("calulate dis");
    //计算两两城市间距离
    for (int i = 0; i < CITY_NUM; i++) {
        for (int j = 0; j < CITY_NUM; j++) {
            double temp1 = CityPos[j][0] - CityPos[i][0];
            double temp2 = CityPos[j][1] - CityPos[i][1];
            dis[i][j] = sqrt(temp1 * temp1 + temp2 * temp2);
        }
    }
    //初始化环境信息素
    puts("initialize info");
    for (int i = 0; i < CITY_NUM; i++) {
        for (int j = 0; j < CITY_NUM; j++) {
            info[i][j] = 1.0;
        }
    }
}

//更新信息素,当前每条路上的信息素等于过去保留的信息素
//加上每个蚂蚁这次走过去剩下的信息素
void Tsp::updateInfo() {
    //puts("update info");
    double tmpinfo[CITY_NUM][CITY_NUM];
    memset(tmpinfo, 0, sizeof(tmpinfo));
    int m = 0;
    int n = 0;
    //遍历每只蚂蚁
    for (int i = 0; i < ANT_NUM; i++) {
        //puts("****");
//            for  (int j = 0; j < CITY_NUM; j++) {
//                printf("%d ", ants[i].Path[j]);
//            }
        //puts("");
        for (int j = 1; j < CITY_NUM; j++) {
            m = ants[i]->Path[j];
            n = ants[i]->Path[j - 1];
            //printf("%d %d\n", m, n);
            tmpinfo[n][m] += Q / ants[i]->length;
            tmpinfo[m][n] = tmpinfo[n][m];
        }
        //最后城市和开始城市之间的信息素
        n = ants[i]->Path[0];
        tmpinfo[n][m] = tmpinfo[n][m] + Q / ants[i]->length;
        tmpinfo[m][n] = tmpinfo[n][m];
    }

    //更新环境信息素
    for (int i = 0; i < CITY_NUM; i++) {
        for (int j = 0; j < CITY_NUM; j++) {
            //最新的环境信息素 = 留存的信息素 + 新留下的信息素
            info[i][j] = info[i][j] * ROU + tmpinfo[i][j];

        }
    }
}

//寻找路径，迭代TMAC次
void Tsp::search() {
    for (int i = 0; i < TMAX; i++) {
//        printf("current iteration times %d\n", i);
        for (int j = 0; j < ANT_NUM; j++) {
//            cout<<TMAX<<" "<<ANT_NUM<<endl;
//            ants[j].search();
            ants[j]->search();


        }
        //保存最佳结果
        for (int j = 0; j < ANT_NUM; j++) {
            if (ant_best->length > ants[j]->length) {
                ant_best = ants[j];
            }
        }

        //更新环境信息素
        updateInfo();

//        printf("current minimum length %lf\n", ant_best.length);
    }
}

