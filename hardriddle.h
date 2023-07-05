#ifndef HARDRIDDLE_H
#define HARDRIDDLE_H
#include<QStringList>
#include<QFile>
#include<QDebug>

class HardRiddle
{
public:
    HardRiddle();
    QString getRiddleList(int);
    QString getRiddleAnswerList(int);
private:
    QStringList Hard_Riddle_List;
    QStringList Hard_Riddle_Answer_List;
};

#endif // HARDRIDDLE_H
