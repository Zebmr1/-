#ifndef RANKLIST_H
#define RANKLIST_H

#include <QWidget>
#include<QStringList>
#include<QFile>
#include<QDebug>

namespace Ui {
class RankList;
}

class RankList : public QWidget
{
    Q_OBJECT

public:
    explicit RankList(QWidget *parent = nullptr);
    ~RankList();

    int GetScore();
    void SetScoreText();
    void SetTextStyleBegin();
    void SetTextOnly();
    QStringList RankSort(QStringList,QStringList&);
    QStringList SetScoreList(int);


signals:
    void back();

private:
    Ui::RankList *ui;

    int Score=100;
    QStringList Score_List;
    QStringList M_Score_List;
    QFont setTextStyle;
};

#endif // RANKLIST_H
