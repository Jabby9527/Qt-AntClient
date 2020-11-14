#include "map.h"
#include "ui_map.h"
#include <QPainter>
#include <ctime>

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);

}

Map::~Map()
{
    delete ui;
}

void Map::showMap()
{

    for (int i=0;i<CITY_NUM;i++) {
        City *c=new City(QString::number(i));
        c->setParent(this);
        c->move(cityCoord[i][0], cityCoord[i][1]);
        c->show();
        city_list.push_back(c);
    }

}

void Map::destroyCity()
{
//    for (int i=0;i<CITY_NUM;i++) {
//       city_list[i]->deleteLater();
//    }
}

//void Map::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    //设置画笔
//    QPen pen(Qt::red);

//    //设置画刷
//    QBrush brush(Qt::darkCyan);
//    //设置画刷风格
//    brush.setStyle(Qt::Dense7Pattern);
//    //让画家使用画刷
////    painter.setBrush(brush);


//    QFont font = painter.font();
//    font.setPixelSize(20);
//    painter.setFont(font);

//    pen.setStyle(Qt::SolidLine);
//    painter.setPen(pen);

//    QRect res[CITY_NUM];

//    if(initmap){
////        for(int i=0;i<CITY_NUM;i++){
////            res[i] = QRect(cityCoord[i][0], cityCoord[i][1], 30, 30);
////            painter.drawText(res[i], Qt::AlignCenter, QString::number(i));

////            //外框
////            painter.drawRect(res[i].adjusted(0,0, -pen.width(), -pen.width()));
////        }

//    }
//}
