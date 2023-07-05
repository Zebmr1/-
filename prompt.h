#ifndef PROMPT_H
#define PROMPT_H

#include<QFile>

class Prompt
{
public:
    Prompt();

    QString GetPromptList(int);
private:
    QStringList promptList;
};

#endif // PROMPT_H
