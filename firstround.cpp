#include "firstround.h"
#include "ui_firstround.h"

extern int chack_num;
extern int disRepeatArr[];
extern int ScoreRecord=0;

FirstRound::FirstRound(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirstRound)
{
    ui->setupUi(this);

    this->secondRoundPage=new SecondRound;

    QPropertyAnimation *countDown=new QPropertyAnimation(ui->label_cd,"countDownWidth");
    countDown->setTargetObject(this);
    countDown->setDuration(10000);
    countDown->setEndValue(0);

    connect(chackPoint,QTimer::timeout,[=](){
        countDown->start();
        chackPoint->stop();
        if(chack_num!=0){
            qDebug()<<random_num<<endl;
            nextRoundPage();
            setRiddle();
        }    
    });

    connect(this->secondRoundPage,&SecondRound::back,[=](){
        emit this->back();
    });

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

FirstRound::~FirstRound()
{
    delete ui;
}

void FirstRound::setRandomNum(int ramdom){
    random_num=ramdom;
}

static int mistake=0;
void FirstRound::nextRoundPage(){

     int min=0;
     int max=13;

    if(random_num==0){

        connect(ui->pushButton_3,&QPushButton::clicked,[=]{
            ui->label_3->setPixmap(QPixmap("://Material/errorTest.png"));
            mistake=1;

        });

        connect(ui->pushButton_2,&QPushButton::clicked,[=](){
            this->secondRoundPage->show();
            if(mistake==0){
                ScoreRecord=ScoreRecord+20;
            }
            qDebug()<<"now ScoreRecord"<<ScoreRecord;

            quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
            QRandomGenerator generator(seed);

            reRound:
                int random=generator.bounded(min,max);
                this->secondRoundPage->setRandomNum(random);
                if(disRepeatArr[0]==random){
                    goto reRound;
                }

            disRepeatArr[1]=random;
            this->secondRoundPage->chackPoint->start();

            //this->hide();
            this->close();
        });
    }
    else if(random_num%2!=0){

        connect(ui->pushButton_3,&QPushButton::clicked,[=]{
            ui->label_3->setPixmap(QPixmap("://Material/errorTest.png"));
            mistake=1;
        });

        connect(ui->pushButton_2,&QPushButton::clicked,[=](){
            this->secondRoundPage->show();
            if(mistake==0){
                ScoreRecord=ScoreRecord+20;              
            }
            qDebug()<<"now ScoreRecord"<<ScoreRecord;           

            quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
            QRandomGenerator generator(seed);

            reRound:
                int random=generator.bounded(min,max);
                this->secondRoundPage->setRandomNum(random);
                if(disRepeatArr[0]==random){
                    goto reRound;
                }

            disRepeatArr[1]=random;
            this->secondRoundPage->chackPoint->start();

            //this->hide();
            this->close();
        });
    }
    else if(random_num%2==0){

        connect(ui->pushButton_2,&QPushButton::clicked,[=]{
            ui->label_3->setPixmap(QPixmap("://Material/errorTest.png"));
            mistake=1;
        });

        connect(ui->pushButton_3,&QPushButton::clicked,[=](){
            this->secondRoundPage->show();
            if(mistake==0){
                ScoreRecord=ScoreRecord+20;             
            }
            qDebug()<<"now ScoreRecord"<<ScoreRecord;

            quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
            QRandomGenerator generator(seed);

            reRound:
                int random=generator.bounded(min,max);
                this->secondRoundPage->setRandomNum(random);
                this->secondRoundPage->setRandomNum(random);
                if(disRepeatArr[0]==random){
                    goto reRound;
                }

            disRepeatArr[1]=random;
            this->secondRoundPage->chackPoint->start();

            //this->hide();
            this->close();
        });
    }
}

void FirstRound::setRiddle(){
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

int FirstRound::getCountDownWidth(){
    return ui->label_cd->width();
}

void FirstRound::setCountDownWidth(int fixWidth){
    ui->label_cd->setFixedWidth(fixWidth);
}
