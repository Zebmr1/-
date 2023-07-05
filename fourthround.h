#ifndef FOURTHROUND_H
#define FOURTHROUND_H

#include <QWidget>
#include<QTimer>
#include<QRandomGenerator>
#include<QDateTime>
#include<QFont>
#include<QPropertyAnimation>
#include"fifthround.h"
#include"hardriddle.h"
#include"ranklist.h"
#include"prompt.h"

namespace Ui {
class FourthRound;
}

class FourthRound : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int countDownWidth READ getCountDownWidth WRITE setCountDownWidth)

public:
    explicit FourthRound(QWidget *parent = nullptr);
    ~FourthRound();

    void setRandomNum(int);
    void setRiddle();
    void nextRoundPage();

    int getCountDownWidth();
    void setCountDownWidth(int);

    QFont promptFont;
    QTimer *chackPoint=new QTimer(this);
    FifthRound *fifthRoundPage=NULL;
signals:
    back();

private:
    Ui::FourthRound *ui;
    int random_num;
    int countDownWidth;
};

#endif // FOURTHROUND_H
