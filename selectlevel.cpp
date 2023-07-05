#include "selectlevel.h"
#include "ui_selectlevel.h"

SelectLevel::SelectLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectLevel)
{
    ui->setupUi(this);

    int min=0;
    int max=15;

    this->firstPage=new FirstRound;
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->firstPage->show();
        quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
        QRandomGenerator generator(seed);
        int random=generator.bounded(min,max);
        this->firstPage->setRandomNum(random);
        this->firstPage->chackPoint->start();
        this->hide();
    });

    this->secondPage=new SecondRound;
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        this->secondPage->show();
        quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
        QRandomGenerator generator(seed);
        int random=generator.bounded(min,max);
        this->secondPage->setRandomNum(random);
        this->secondPage->chackPoint->start();
        this->hide();
    });

    this->thirdPage=new ThirdRound;
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        this->thirdPage->show();
        quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
        QRandomGenerator generator(seed);
        int random=generator.bounded(min,max);
        this->thirdPage->setRandomNum(random);
        this->thirdPage->chackPoint->start();
        this->hide();
    });

    this->fourthPage=new FourthRound;
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        this->fourthPage->show();
        quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
        QRandomGenerator generator(seed);
        int random=generator.bounded(min,max);
        this->fourthPage->setRandomNum(random);
        this->fourthPage->chackPoint->start();
        this->hide();
    });

    this->fifthPage=new FifthRound;
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
        this->fifthPage->show();
        quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
        QRandomGenerator generator(seed);
        int random=generator.bounded(min,max);
        this->fifthPage->setRandomNum(random);
        this->fifthPage->chackPoint->start();
        this->hide();
    });

    connect(ui->pushButton,&QPushButton::clicked,[=]{
        emit this->selectback();
    });

    connect(this->fifthPage,&FifthRound::back,[=](){
        emit this->selectback();
    });

    connect(this->fourthPage,&FourthRound::back,[=](){
        emit this->selectback();
    });

    connect(this->thirdPage,&ThirdRound::back,[=](){
        emit this->selectback();
    });

    connect(this->secondPage,&SecondRound::back,[=](){
        emit this->selectback();
    });

    connect(this->firstPage,&FirstRound::back,[=](){
        emit this->selectback();
    });

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

SelectLevel::~SelectLevel()
{
    delete ui;
}
