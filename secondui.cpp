#include "secondui.h"
#include "ui_secondui.h"

extern int chack_num=1;
extern int disRepeatArr[]={0,0,0,0,0};

secondUi::secondUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondUi)
{
    ui->setupUi(this);

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        emit this->back();
    });

    this->levelPage=new SelectLevel;
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        this->hide();
        this->levelPage->show();
    });

    connect(this->levelPage,&SelectLevel::selectback,[=](){
        this->show();
        this->levelPage->hide();
    });

    this->firstRoundPage=new FirstRound;
    int min =0;
    int max =13;

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->firstRoundPage->show();
        quint32 seed=quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
        QRandomGenerator generator(seed);
        int random=generator.bounded(min,max);
        this->firstRoundPage->setRandomNum(random);
        disRepeatArr[0]=random;
        this->firstRoundPage->chackPoint->start();

        this->hide();
    });

    this->helpPage=new HelpUi;
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        this->helpPage->show();
    });

    connect(this->helpPage,&HelpUi::back,[=](){
        this->helpPage->hide();
    });

    connect(this->firstRoundPage,&FirstRound::back,[=](){
        this->show();
        this->firstRoundPage->hide();
    });

    this->rankListPage=new RankList;
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        this->rankListPage->show();
        this->hide();
    });

    connect(this->rankListPage,&RankList::back,[=](){
        this->show();
        this->rankListPage->hide();
    });

    loopAnimation=new QPropertyAnimation(ui->label_3,"Opacity");
    loopAnimation->setTargetObject(this);
    loopAnimation->setDuration(1500);
    loopAnimation->setStartValue(255);
    loopAnimation->setEndValue(0);

    //--------------------------------//

    connect(ui->radioButton,&QRadioButton::clicked,[=](){
        qDebug()<<"now current"<<currentLoopAdress;
        loopAdress=0;
        ui->label_4->setPixmap(QPixmap(loopPixAdress.at(loopAdress)));
        loopAnimation->start();
    });

    connect(ui->radioButton_2,&QRadioButton::clicked,[=]{
        qDebug()<<"now current"<<currentLoopAdress;
        loopAdress=1;
        ui->label_4->setPixmap(QPixmap(loopPixAdress.at(loopAdress)));
        loopAnimation->start();
    });

    connect(ui->radioButton_5,&QRadioButton::clicked,[=](){
        loopAdress=4;
        ui->label_4->setPixmap(QPixmap(loopPixAdress.at(loopAdress)));
        loopAnimation->start();
    });

    loopPixAdress<<":/loopAnimal/Library/loopAnimal/fox.png"
                <<":/loopAnimal/Library/loopAnimal/cat.png"
               <<":/loopAnimal/Library/loopAnimal/dog.png"
              <<":/loopAnimal/Library/loopAnimal/hedgehog.png"
             <<":/loopAnimal/Library/loopAnimal/rabbit.png";
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

void secondUi::paintEvent(QPaintEvent *){
    animalPixmap.load(loopPixAdress.at(currentLoopAdress));
    animalPainter.begin(&animalPixmap);
    animalPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    animalPainter.drawPixmap(0,0,animalPixmap);
    animalPainter.fillRect(animalPixmap.rect(),QColor(0,0,0,feignOpacity));
    animalPainter.end();
    ui->label_3->setPixmap(animalPixmap);
    if(feignOpacity==0){
        currentLoopAdress=loopAdress;
        loopAnimation->stop();
    }
}

secondUi::~secondUi()
{
    delete ui;
}

int secondUi::getOpacity(){
    return feignOpacity;
}

void secondUi::setOpercity(int fixOpacity){
    feignOpacity=fixOpacity;
    repaint();
    //update();
}
