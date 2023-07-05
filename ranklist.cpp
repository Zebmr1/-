#include "ranklist.h"
#include "ui_ranklist.h"

extern int ScoreRecord;

RankList::RankList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankList)
{
    ui->setupUi(this);

    QFile MarkListFile("E:\\Qt\\project\\guessRiddle\\Library\\MarkList.txt");
    QFile RankListFile("E:\\Qt\\project\\guessRiddle\\Library\\RankList.txt");
    MarkListFile.open(QIODevice::ReadOnly);
    RankListFile.open(QIODevice::ReadOnly);
    while(RankListFile.atEnd()==false){
        QByteArray buf=RankListFile.readLine();
        QByteArray buf_2=MarkListFile.readLine();
        buf=buf.trimmed();
        buf_2=buf_2.trimmed();
        Score_List<<buf.data();
        M_Score_List<<buf_2.data();
        //RankListFile.close();
        //MarkListFile.close();
    }

    if(Score_List.isEmpty()==false){
        qDebug()<<"right";
        Score_List=RankSort(Score_List,M_Score_List);
        SetTextStyleBegin();
    }
    else{
        SetTextStyleBegin();
    }

    RankListFile.close();

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        emit this->back();
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        Score_List.clear();
        M_Score_List.clear();
        SetScoreText();
        Score_List=RankSort(Score_List,M_Score_List);
        SetTextOnly();
    });

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

RankList::~RankList()
{
    delete ui;
}

int RankList::GetScore(){
    return Score;
}

void RankList::SetScoreText(){
    QFile RankListFile("E:\\Qt\\project\\guessRiddle\\Library\\RankList.txt");
    QFile MarkListFile("E:\\Qt\\project\\guessRiddle\\Library\\MarkList.txt");
    RankListFile.open(QIODevice::ReadOnly);
    MarkListFile.open(QIODevice::ReadOnly);
    while(RankListFile.atEnd()==false){
       QByteArray buf=RankListFile.readLine();
       QByteArray buf_2=MarkListFile.readLine();
       buf=buf.trimmed();
       buf_2=buf_2.trimmed();
       Score_List<<buf.data();
       M_Score_List<<buf_2.data();
    }
}

QStringList RankList::RankSort(QStringList rankList,QStringList &MarkList){
        for(int i=0;i<=rankList.length()-1;i++){
            for(int j=0;i<rankList.length()-1-j;j++){
                QString a1= rankList.at(j);
                QString a2= rankList.at(j+1);
                a1=a1.toInt();
                a2=a2.toInt();
                if(a1<a2){
                    QString temp=rankList.at(j);
                    rankList.replace(j,rankList.at(j+1));
                    rankList.replace(j+1,temp);

                    QString temp_2=MarkList.at(j);
                    MarkList.replace(j,MarkList.at(j+1));
                    MarkList.replace(j+1,temp_2);
                }
            }
        }
    return rankList;
}

void RankList::SetTextStyleBegin(){
    setTextStyle.setBold(1);
    setTextStyle.setFamily("猫啃什锦黑");
    setTextStyle.setPixelSize(60);
    ui->label_3->setFont(setTextStyle);
    ui->label_4->setFont(setTextStyle);
    ui->label_5->setFont(setTextStyle);
    ui->label_6->setFont(setTextStyle);
    ui->label_7->setFont(setTextStyle);
    ui->label_8->setFont(setTextStyle);
    ui->label_9->setFont(setTextStyle);
    ui->label_10->setFont(setTextStyle);
    ui->label_11->setFont(setTextStyle);
    ui->label_12->setFont(setTextStyle);
    ui->label_13->setFont(setTextStyle);
    ui->label_14->setFont(setTextStyle);

    ui->label_3->setText(Score_List.at(0));
    ui->label_4->setText(Score_List.at(1));
    ui->label_5->setText(Score_List.at(2));
    ui->label_6->setText(Score_List.at(3));
    ui->label_7->setText(Score_List.at(4));
    ui->label_8->setText(Score_List.at(5));
    ui->label_9->setText(Score_List.at(0));
    ui->label_10->setText(Score_List.at(1));
    ui->label_11->setText(Score_List.at(2));
    ui->label_12->setText(Score_List.at(3));
    ui->label_13->setText(Score_List.at(4));
    ui->label_14->setText(Score_List.at(5));

    ui->label_2->setText(M_Score_List.at(0));
    ui->label_15->setText(M_Score_List.at(1));
    ui->label_16->setText(M_Score_List.at(2));
    ui->label_17->setText(M_Score_List.at(3));
    ui->label_18->setText(M_Score_List.at(4));
    ui->label_19->setText(M_Score_List.at(5));

    ui->label_2->setFont(setTextStyle);
    ui->label_15->setFont(setTextStyle);
    ui->label_16->setFont(setTextStyle);
    ui->label_17->setFont(setTextStyle);
    ui->label_18->setFont(setTextStyle);
    ui->label_19->setFont(setTextStyle);
}

void RankList::SetTextOnly(){
    ui->label_3->setText(Score_List.at(0));
    ui->label_4->setText(Score_List.at(1));
    ui->label_5->setText(Score_List.at(2));
    ui->label_6->setText(Score_List.at(3));
    ui->label_7->setText(Score_List.at(4));
    ui->label_8->setText(Score_List.at(5));
    ui->label_9->setText(Score_List.at(0));
    ui->label_10->setText(Score_List.at(1));
    ui->label_11->setText(Score_List.at(2));
    ui->label_12->setText(Score_List.at(3));
    ui->label_13->setText(Score_List.at(4));
    ui->label_14->setText(Score_List.at(5));

    ui->label_2->setText(M_Score_List.at(0));
    ui->label_15->setText(M_Score_List.at(1));
    ui->label_16->setText(M_Score_List.at(2));
    ui->label_17->setText(M_Score_List.at(3));
    ui->label_18->setText(M_Score_List.at(4));
    ui->label_19->setText(M_Score_List.at(5));
}
