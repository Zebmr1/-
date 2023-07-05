#include "prompt.h"

Prompt::Prompt()
{
    QFile promptFile("E:\\Qt\\project\\guessRiddle\\Library\\RiddlePrompt.txt");
    promptFile.open(QIODevice::ReadOnly);
    while(promptFile.atEnd()==false){
        QByteArray buf=promptFile.readLine();
        buf=buf.trimmed();
        promptList<<buf.data();
}

}

QString Prompt::GetPromptList(int random){
    return promptList.at(random);
}
