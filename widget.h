#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "global.h"
#include "tsp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void initInput();
private slots:

    void on_initButton_clicked();

    void on_startup_clicked();

private:
    QTimer *timer;
    Ui::Widget *ui;
    Tsp tsp;
};
#endif // WIDGET_H
