#include "ant.h"

//Ant::Ant()
//{
//    Path=new int[CITY_NUM];
//    vis=new int[CITY_NUM];

//    order_cnt=0;
//    connect(antTimer,&QTimer::timeout,[=](){
//       if(order_cnt<moved_cnt){
//           city_list[Path[order_cnt]]->setVisit();
//       }
//       else antTimer->stop();
//    });
//}

Ant::Ant(QObject *parent)
{
    Path=new int[CITY_NUM];
    vis=new int[CITY_NUM];
    antTimer=new QTimer(this);
    order_cnt=1;

}

void Ant::init() {
    memset(vis,0,sizeof (int)*CITY_NUM);
    length = 0;
    cur_cityno = Global::rnd(0, CITY_NUM);//随机选择一个出发城市
    Path[0] = cur_cityno;
    vis[cur_cityno] = 1;
    moved_cnt = 1;
    //printf("Init %d \n", cur_cityno);
}

//选择下一个城市
//返回值 为城市编号
int Ant::chooseNextCity() {
    int nSelectedCity = -1; //返回结果，先暂时把其设置为-1
    //计算当前城市和没去过的城市之间的信息素总和
    double dbTotal = 0.0;
    double prob[CITY_NUM]; //保存各个城市被选中的概率
    for (int i = 0; i < CITY_NUM; i++) {
        if (!vis[i]) {
            prob[i] = pow(info[cur_cityno][i], ALPHA)
                      * pow(1.0 / dis[cur_cityno][i], BETA);
            dbTotal += prob[i];
        } else {
            prob[i] = 0;
        }
    }
    //进行轮盘选择
    double dbTemp = 0.0;
    //总的信息素值大于0
    if (dbTotal > 0.0) {
        dbTemp = Global::rnd(0.0, dbTotal);
        for (int i = 0; i < CITY_NUM; i++) {
            if (!vis[i]) {
                dbTemp -= prob[i];
                if (dbTemp < 0.0) {
                    nSelectedCity = i;
                    break;
                }
            }
        }
    }
    //如果城市间的信息素非常小 ( 小到比double能够表示的最小的数字还要小 )
    //出现这种情况，就把第一个没去过的城市作为返回结果

    if (nSelectedCity == -1) {
        for (int i = 0; i < CITY_NUM; i++) {
            if (!vis[i]) //城市没去过
            {
                nSelectedCity = i;
                break;
            }
        }
    }
    return nSelectedCity;
}

//蚂蚁在城市间移动
void Ant::move() {
    int nCityno = chooseNextCity();//选择下一个城市
    Path[moved_cnt] = nCityno;//保存蚂蚁走的路径
    vis[nCityno] = 1;//把这个城市设置成已经去过

    cur_cityno = nCityno;
    //更新已走路径长度
    length += dis[Path[moved_cnt - 1]][Path[moved_cnt]];
    moved_cnt++;
}

void Ant::search(QString color) {
    init();
    connect(antTimer,&QTimer::timeout,[=](){
        if(order_cnt<moved_cnt){
            city_list[Path[order_cnt]]->setVisit(color);
            order_cnt++;
        }
        else antTimer->stop();
    });
    //如果蚂蚁去过的城市数量小于城市数量，就继续移动
    while (moved_cnt < CITY_NUM) {
        move();
    }
    length += dis[Path[CITY_NUM - 1]][Path[0]];

    city_list[Path[0]]->setVisit(color);
    antTimer->start(GAP_TIME);
}

