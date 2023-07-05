#ifndef FIFTHROUND_H
#define FIFTHROUND_H

#include <QWidget>
#include<QFile>
#include<QTimer>
#include<QRandomGenerator>
#include<QDateTime>
#include<QTextStream>
#include<QFont>
#include<QPropertyAnimation>
#include"hardriddle.h"
#include"completelevel.h"
#include"ranklist.h"
#include"prompt.h"

namespace Ui {
class FifthRound;
}

class FifthRound : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int countDownWidth READ getCountDownWidth WRITE setCountDownWidth)

public:
    explicit FifthRound(QWidget *parent = nullptr);
    ~FifthRound();

    void setRandomNum(int);
    void setRiddle();

    int getCountDownWidth();
    void setCountDownWidth(int);

    QFont promptFont;
    QTimer *chackPoint=new QTimer(this);
    CompleteLevel *completeLevelPage=NULL;

signals:
    back();
private:
    Ui::FifthRound *ui;
    int random_num;
    int countDownWidth;
};

#endif // FIFTHROUND_H
