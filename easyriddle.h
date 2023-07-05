#ifndef EASYRIDDLE_H
#define EASYRIDDLE_H
#include<QStringList>
#include<QFile>
#include<QDebug>

class EasyRiddle
{
public:
    EasyRiddle();
    QString getRiddleList(int);

private:
    QStringList Easy_Riddle_List;
};

#endif // EASYRIDDLE_H
