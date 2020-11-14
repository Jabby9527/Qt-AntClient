#include "city.h"


City::City(QString name){

    this->setFixedSize(QSize(ICON,ICON));
    QString tmp=QString("QPushButton{border:1px solid black;border-radius:%1px;}").arg(ICON/2);
    this->setStyleSheet(tmp);
    this->setText(name);

}

void City::setVisit(QString color)
{
    QString tmp=QString("QPushButton{border:1px solid black;border-radius:%1px;background-color:%2;}")
            .arg(ICON/2).arg(color);
    this->setStyleSheet(tmp);
}
