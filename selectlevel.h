#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QWidget>
#include<QTimer>
#include<QRandomGenerator>
#include<QDateTime>
#include"firstround.h"
#include"secondround.h"
#include"thirdround.h"
#include"fourthround.h"
#include"fifthround.h"

namespace Ui {
class SelectLevel;
}

class SelectLevel : public QWidget
{
    Q_OBJECT

public:
    explicit SelectLevel(QWidget *parent = nullptr);
    ~SelectLevel();

    FirstRound *firstPage=NULL;
    SecondRound *secondPage=NULL;
    ThirdRound *thirdPage=NULL;
    FourthRound *fourthPage=NULL;
    FifthRound *fifthPage=NULL;

signals:
    void selectback();

private:
    Ui::SelectLevel *ui;
    int random_num;
};

#endif // SELECTLEVEL_H
