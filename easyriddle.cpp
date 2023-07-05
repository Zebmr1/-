#include "easyriddle.h"

EasyRiddle::EasyRiddle()
{
     QFile easyRiddleFile("E:\\Qt\\project\\guessRiddle\\Library\\EasyRiddlUse.txt");
     if(!easyRiddleFile.open(QIODevice::ReadOnly)){
         qDebug()<<easyRiddleFile.errorString();
     }
     while (easyRiddleFile.atEnd()==false) {
         QByteArray buf=easyRiddleFile.readLine();
         buf=buf.trimmed();
         Easy_Riddle_List<<buf.data();
         static int i=0;

         i++;

     }
//     if(Easy_Riddle_List.at(0)=="耳朵长，尾巴短。只吃菜，不吃饭。"){
//         qDebug()<<"yes";
//     }
}

QString EasyRiddle::getRiddleList(int ramdom){
    return Easy_Riddle_List.at(ramdom);
}
