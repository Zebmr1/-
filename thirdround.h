#ifndef THIRDROUND_H
#define THIRDROUND_H

#include <QWidget>
#include<QTimer>
#include<QRandomGenerator>
#include<QDateTime>
#include<QPropertyAnimation>
#include"easyriddle.h"
#include"fourthround.h"
#include"ranklist.h"

namespace Ui {
class ThirdRound;
}

class ThirdRound : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int countDownWidth READ getCountDownWidth WRITE setCountDownWidth)


public:
    explicit ThirdRound(QWidget *parent = nullptr);
    ~ThirdRound();

    void setRandomNum(int);
    void setRiddle();
    void nextRoundPage();

    int getCountDownWidth();
    void setCountDownWidth(int);

    QTimer *chackPoint=new QTimer(this);
    FourthRound *fourthRoundPage=NULL;
signals:
    back();

private:
    Ui::ThirdRound *ui;
    int random_num;
    int countDownWidth;
};

#endif // THIRDROUND_H
