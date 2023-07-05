#include "hardriddle.h"

HardRiddle::HardRiddle()
{
    QFile hardRiddleFile("E:\\Qt\\project\\guessRiddle\\Library\\HardRiddleUse.txt");
    if(!hardRiddleFile.open(QIODevice::ReadOnly)){
        qDebug()<<hardRiddleFile.errorString();
    }
    while(hardRiddleFile.atEnd()==false){
        QByteArray buf=hardRiddleFile.readLine();
        buf=buf.trimmed();
        Hard_Riddle_List<<buf.data();
    }

    QFile hardRiddleAnswerFlie("E:\\Qt\\project\\guessRiddle\\Library\\HardRiddleAnswer.txt");
    if(!hardRiddleAnswerFlie.open(QIODevice::ReadOnly)){
        qDebug()<<hardRiddleAnswerFlie.errorString();
    }
    while(hardRiddleAnswerFlie.atEnd()==false){
        QByteArray buf_2 =hardRiddleAnswerFlie.readLine();
        buf_2=buf_2.trimmed();
        Hard_Riddle_Answer_List<<buf_2;

    }
}

QString HardRiddle::getRiddleList(int random){
    return Hard_Riddle_List.at(random);
}

QString HardRiddle::getRiddleAnswerList(int random){
    return Hard_Riddle_Answer_List.at(random);
}
