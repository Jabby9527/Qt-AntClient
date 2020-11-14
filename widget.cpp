#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "tsp.h"
#include <iostream>
#include <QPainter>
#include "city.h"
using namespace  std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pic/ant.jpg"));
//    init(int cn,int an,int tmax,float rou,int al,int be,int q)
    timer=new QTimer(this);

    connect(timer,&QTimer::timeout,[=](){
        ui->map->destroyCity();
        qDebug()<<"销毁城市";
    });

    this->setWindowTitle("蚁群算法演示");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::initInput()
{
    if(ui->alpha->text().isEmpty()) ui->alpha->setText("1");
    if(ui->beta->text().isEmpty()) ui->beta->setText("4");

    if(ui->residueQ->text().isEmpty()) ui->residueQ->setText("100");
    if(ui->error->text().isEmpty()) ui->error->setText("0.5");

    if(ui->cityNum->text().isEmpty()) ui->cityNum->setText("30");
    if(ui->antNum->text().isEmpty()) ui->antNum->setText("1");

    if(ui->times->text().isEmpty()) ui->times->setText("1");
    if(ui->startPos->text().isEmpty()) ui->startPos->setText("-1");

    tsp.g.init(ui->alpha->text().toInt(),ui->beta->text().toInt(),ui->residueQ->text().toInt(),
               ui->error->text().toFloat(),ui->antNum->text().toInt(),
               ui->cityNum->text().toInt(),ui->times->text().toInt(),ui->startPos->text().toInt());

    srand(time(NULL));
    int wid=ui->map->width();
    int hei=ui->map->height();

    for(int i=0;i<CITY_NUM;i++){
        cityCoord[i][0]=rand()%(wid-ICON);
        cityCoord[i][1]=rand()%(hei-ICON);
    }
}

//开始运行
void Widget::on_startup_clicked()
{
    //初始化蚁群
    tsp.init();
    //开始查找
    tsp.search();
    puts("The Minimum length route is :\n");
    for (int i = 0; i < CITY_NUM; i++) {
        cout << tsp.ant_best->Path[i] << " ";
        if (i != 0 && i % 10 == 0) cout << endl;
    }
    cout<<endl;
}

//生成地图
void Widget::on_initButton_clicked()
{
    initInput();
    ui->map->showMap();
}
