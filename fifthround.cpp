#include "fifthround.h"
#include "ui_fifthround.h"

extern int chack_num;
extern int ScoreRecord;

FifthRound::FifthRound(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FifthRound)
{
    ui->setupUi(this);

    QPropertyAnimation *countDown=new QPropertyAnimation(ui->label_6,"countDownWidth");
    countDown->setTargetObject(this);
    countDown->setDuration(15000);
    countDown->setEndValue(0);

    promptFont.setFamily("猫啃什锦黑");
    promptFont.setPixelSize(30);

    this->completeLevelPage=new CompleteLevel;
    connect(chackPoint,&QTimer::timeout,[=](){
        countDown->start();
        if(chack_num!=0){           
            setRiddle();
            chackPoint->stop();
        }

        HardRiddle chack_Answer;
        QString getAnswer=chack_Answer.getRiddleAnswerList(random_num);

        static int j=0;
        if(j==0){
            qDebug()<<getAnswer;
            j++;
        }

        connect(ui->pushButton,&QPushButton::clicked,[=](){
            QString playerAnswer=ui->textEdit->toPlainText();

            if(playerAnswer!=getAnswer){
                ui->label_4->setPixmap(QPixmap("://Material/errorTest.png"));
                if(ScoreRecord!=0){
                    ScoreRecord=ScoreRecord-5;
                    qDebug()<<"now ScoreRecord"<<ScoreRecord;
                    chackPoint->stop();
                }
            }
            else{
                ScoreRecord=ScoreRecord+20;

                ui->label_3->setPixmap(QPixmap("://Material/CompleteBackUi.png"));
                this->completeLevelPage->show();
                this->completeLevelPage->chackPoint->start();
                ui->pushButton->close();
                countDown->stop();
                qDebug()<<"now ScoreRecord"<<ScoreRecord;
                chackPoint->stop();
            }
        });

        chackPoint->stop();
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        Prompt i;
        ui->label_5->setText(i.GetPromptList(random_num));
        ui->pushButton_2->close();
        if(ScoreRecord!=0){
            ScoreRecord=ScoreRecord-10;
        }
        qDebug()<<"now ScoreRecord"<<ScoreRecord;
    });


    connect(this->completeLevelPage,&CompleteLevel::back,[=](){
        this->completeLevelPage->hide();
        this->hide();
        emit this->back();
    });

    ui->label_3->setGeometry(690,330,1201,821);
    ui->label_3->setPixmap(QPixmap("://Material/backUi01.png"));
    ui->pushButton_2->setStyleSheet("background-image: url(:/Material/prompt.png);"
                                    "background-color: rgba(255, 255, 255, 0);");
    ui->textEdit->setFont(promptFont);
    ui->label_5->setFont(promptFont);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);

}

FifthRound::~FifthRound()
{
    delete ui;
}

void FifthRound::setRandomNum(int random){
    random_num=random;
}

void FifthRound::setRiddle(){
    switch (random_num)
    {
    case 0:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle15.png"));
        break;
    }
    case 1:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle16.png"));
        break;
    }
    case 2:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle17.png"));
        break;
    }
    case 3:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle18.png"));
        break;
    }
    case 4:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle19.png"));
        break;
    }
    case 5:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle20.png"));
        break;
    }
    case 6:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle21.png"));
        break;
    }
    case 7:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle22.png"));
        break;
    }
    case 8:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle23.png"));
        break;
    }
    case 9:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle24.png"));
        break;
    }
    case 10:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle25.png"));
        break;
    }
    case 11:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle26.png"));
        break;
    }
    case 12:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle27.png"));
        break;
    }
    case 13:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle28.png"));
        break;
    }
    case 14:{
        ui->label->setPixmap(QPixmap(":/RiddlePixHard/Library/LibraryPix/Riddle29.png"));
        break;
    }
    }
}

int FifthRound::getCountDownWidth(){
    return ui->label_6->width();
}

void FifthRound::setCountDownWidth(int fixWidth){
    ui->label_6->setFixedWidth(fixWidth);
}
