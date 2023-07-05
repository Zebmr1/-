#ifndef SECONDROUND_H
#define SECONDROUND_H

#include <QWidget>
#include<QTimer>
#include<QRandomGenerator>
#include<QDateTime>
#include<QDebug>
#include<QPropertyAnimation>
#include"easyriddle.h"
#include"thirdround.h"
#include"ranklist.h"


namespace Ui {
class SecondRound;
}

class SecondRound : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int countDownWidth READ getCountDownWidth WRITE setCountDownWidth)


public:
    explicit SecondRound(QWidget *parent = nullptr);
    ~SecondRound();

    void nextRoundPage();
    void setRandomNum(int);
    void setRiddle();

    int getCountDownWidth();
    void setCountDownWidth(int);

    QTimer *chackPoint=new QTimer(this);
    ThirdRound *thirdRoundPage=NULL;
signals:
    back();
private:
    Ui::SecondRound *ui;
    int random_num=0;
    int countDownWidth;
};

#endif // SECONDROUND_H
