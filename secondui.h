#ifndef SECONDUI_H
#define SECONDUI_H

#include <QWidget>
#include<QRandomGenerator>
#include<QDateTime>
#include<QMovie>
#include<QPropertyAnimation>
#include<QLabel>
#include<QPainter>
#include<QPixmap>
#include"selectlevel.h"
#include"firstround.h"
#include"ranklist.h"
#include"completelevel.h"
#include"helpui.h"

namespace Ui {
class secondUi;
}

class secondUi : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int Opacity READ getOpacity WRITE setOpercity)
public:
    explicit secondUi(QWidget *parent = nullptr);
    ~secondUi();

    SelectLevel *levelPage=NULL;
    FirstRound *firstRoundPage=NULL;
    RankList *rankListPage=NULL;
    HelpUi * helpPage=NULL;

    int getOpacity();
    void setOpercity(int);

    void paintEvent(QPaintEvent*);
signals:
    void back();
private:
    Ui::secondUi *ui;
    int Opacity;
    int feignOpacity=255;
    int loopAdress=0;
    int currentLoopAdress=0;
    int paintAdress;
    QStringList loopPixAdress;

    QPixmap animalPixmap;
    QPixmap tempPix;

    QPainter animalPainter;
    QPropertyAnimation *loopAnimation;
};

#endif // SECONDUI_H
