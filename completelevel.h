#ifndef COMPLETELEVEL_H
#define COMPLETELEVEL_H

#include <QWidget>
#include<QFont>
#include<QTimer>
#include<QDebug>
#include"ranklist.h"

namespace Ui {
class CompleteLevel;
}

class CompleteLevel : public QWidget
{
    Q_OBJECT

public:
    explicit CompleteLevel(QWidget *parent = nullptr);
    ~CompleteLevel();

    RankList i;
    QFont scoreResult;
    QTimer *chackPoint=new QTimer(this);
signals:
    back();
private:
    Ui::CompleteLevel *ui;

    int scoreResultData;
    QString Mark;
};

#endif // COMPLETELEVEL_H
