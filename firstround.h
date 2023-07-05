#ifndef FIRSTROUND_H
#define FIRSTROUND_H

#include <QWidget>
#include<QTimer>
#include<QRandomGenerator>
#include<QDateTime>
#include<QPropertyAnimation>
#include"easyriddle.h"
#include<QDebug>
#include"secondround.h"
#include"ranklist.h"

namespace Ui {
class FirstRound;
}

class FirstRound : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int countDownWidth READ getCountDownWidth WRITE setCountDownWidth)

public:
    explicit FirstRound(QWidget *parent = nullptr);
    ~FirstRound();

    void setRandomNum(int);
    void setRiddle();
    void nextRoundPage();

    int getCountDownWidth();
    void setCountDownWidth(int);

    SecondRound *secondRoundPage=NULL;

    QTimer *chackPoint=new QTimer(this);

signals:
    void back();


private:
    Ui::FirstRound *ui;
    int random_num=0;
    int countDownWidth;
};

#endif // FIRSTROUND_H
