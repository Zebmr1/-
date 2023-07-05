#include "completelevel.h"
#include "ui_completelevel.h"

extern int chack_num;
extern int ScoreRecord;

CompleteLevel::CompleteLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompleteLevel)
{
    ui->setupUi(this);

    scoreResult.setBold(1);
    scoreResult.setFamily("猫啃什锦黑");
    scoreResult.setPixelSize(50);

    connect(chackPoint,QTimer::timeout,[=](){
        if(chack_num!=0){
            ui->label_2->setText(QString::number(ScoreRecord));
            ui->label_3->setText(QString::number(ScoreRecord));

            QFile RankListFile("E:\\Qt\\project\\guessRiddle\\Library\\RankList.txt");
            RankListFile.open(QIODevice::Text|QIODevice::ReadWrite|QIODevice::Append);

            QTextStream outRankList(&RankListFile);
            outRankList<<ScoreRecord<<endl;
            RankListFile.close();
            QFile MarkListFile("E:\\Qt\\project\\guessRiddle\\Library\\MarkList.txt");
            MarkListFile.open(QIODevice::ReadOnly);
            RankListFile.open(QIODevice::ReadOnly);
            qDebug()<<Mark;
            while(RankListFile.atEnd()==false){
                RankListFile.readLine();
                QByteArray buf=MarkListFile.readLine();
                buf=buf.trimmed();
                Mark=buf.data();

            }
            ui->label_4->setText(Mark);
            RankListFile.close();
        }
        this->chackPoint->stop();
    });


    connect(ui->pushButton,&QPushButton::clicked,[=](){
       emit this->back();
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        emit exit(0);
    });

    //ui->label_4->setText("ok");
    ui->label_4->setFont(scoreResult);
    ui->label_2->setFont(scoreResult);
    ui->label_3->setFont(scoreResult);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

CompleteLevel::~CompleteLevel()
{
    delete ui;
}
