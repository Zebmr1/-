#include "thirdround.h"
#include "ui_thirdround.h"

extern int chack_num;
extern int disRepeatArr[];
extern int ScoreRecord;

ThirdRound::ThirdRound(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThirdRound)
{
    ui->setupUi(this);

    QPropertyAnimation *countDown=new QPropertyAnimation(ui->label_6,"countDownWidth");
    countDown->setTargetObject(this);
    countDown->setDuration(10000);
    countDown->setEndValue(0);

    this->fourthRoundPage=new FourthRound;

    connect(chackPoint,&QTimer::timeout,[=](){
        countDown->start();
        if(chack_num!=0){
            qDebug()<<random_num<<" "<<"(3)";
            nextRoundPage();
            setRiddle();
        }
        chackPoint->stop();
    });

    connect(this->fourthRoundPage,&FourthRound::back,[=](){
        emit this->back();
    });

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

ThirdRound::~ThirdRound()
{
    delete ui;

}

void ThirdRound::setRandomNum(int random){
    random_num=random;
}

static int mistake02=0;
void ThirdRound::nextRoundPage(){

     int min=0;
     int max=13;

    if(random_num==0){

        connect(ui->pushButton_2,&QPushButton::clicked,[=]{
            ui->label_3->setPixmap(QPixmap("://Material/errorTest.png"));

            mistake02=1;

        });

        connect(ui->pushButton,&QPushButton::clicked,[=](){
            if(mistake02==0){
                ScoreRecord=ScoreRecord+20;
            }
            qDebug()<<"now ScoreRecord"<<ScoreRecord;
            this->fourthRoundPage->show();

            quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
            QRandomGenerator generator(seed);

            int random=generator.bounded(min,max);
            this->fourthRoundPage->setRandomNum(random);
            disRepeatArr[3]=random;

            this->fourthRoundPage->chackPoint->start();
            //this->hide();
            this->close();
        });
    }
    else if(random_num%2!=0){

        connect(ui->pushButton_2,&QPushButton::clicked,[=]{
            ui->label_3->setPixmap(QPixmap("://Material/errorTest.png"));
            mistake02=1;
        });

        connect(ui->pushButton,&QPushButton::clicked,[=](){
            if(mistake02==0){
                ScoreRecord=ScoreRecord+20;
            }
            qDebug()<<"now ScoreRecord"<<ScoreRecord;
            this->fourthRoundPage->show();

            quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
            QRandomGenerator generator(seed);

            int random=generator.bounded(min,max);
            this->fourthRoundPage->setRandomNum(random);
            disRepeatArr[3]=random;

            this->fourthRoundPage->chackPoint->start();
            //this->hide();
            this->close();
        });
    }
    else if(random_num%2==0){

        connect(ui->pushButton,&QPushButton::clicked,[=]{
            ui->label_3->setPixmap(QPixmap("://Material/errorTest.png"));
            mistake02=1;
        });

        connect(ui->pushButton_2,&QPushButton::clicked,[=](){
            if(mistake02==0){
                ScoreRecord=ScoreRecord+20;
            }
            qDebug()<<"now ScoreRecord"<<ScoreRecord;
            this->fourthRoundPage->show();

            quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
            QRandomGenerator generator(seed);

            int random=generator.bounded(min,max);
            this->fourthRoundPage->setRandomNum(random);
            disRepeatArr[3]=random;

            this->fourthRoundPage->chackPoint->start();
            //this->hide();
            this->close();
        });
    }
}

void ThirdRound::setRiddle(){
    EasyRiddle i;
    switch (random_num)
    {
    case 0:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle00.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/rabbit.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/fox.png"));
        break;
    }
    case 1:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle01.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/dog.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/rabbit.png"));
        break;
    }
    case 2:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle02.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/hornet.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/fireworm.png"));
        break;
    }
    case 3:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle03.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/earthworm.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/snake.png"));
        break;
    }
    case 4:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle04.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/frog.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/cat.png"));
        break;
    }
    case 5:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle05.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/hedgehog.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/centipede.png"));
        break;
    }
    case 6:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle06.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/tortoise.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/trionyx.png"));
        break;
    }
    case 7:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle07.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/tortoise.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/trionyx.png"));
        break;
    }
    case 8:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle08.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/inkfish.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/fish.png"));
        break;
    }
    case 9:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle09.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/ant.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/centipede.png"));
        break;
    }
    case 10:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle10.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/goose.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/grusJaponensis.png"));
        break;
    }
    case 11:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle11.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/goose.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/grusJaponensis.png"));
        break;
    }
    case 12:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle12.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/katydid.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/crab.png"));
        break;
    }
    case 13:{
        ui->label->setPixmap(QPixmap(":/RiddlPix/Library/LibraryPix/Riddle13.png"));
        ui->label_4->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/katydid.png"));
        ui->label_5->setPixmap(QPixmap(":/AnimalLibrary/Library/AnimalPix/crab.png"));
        break;
    }
    }
}

int ThirdRound::getCountDownWidth(){
    return ui->label_6->width();
}

void ThirdRound::setCountDownWidth(int fixWidth){
    ui->label_6->setFixedWidth(fixWidth);
}
