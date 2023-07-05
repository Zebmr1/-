#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //------界面切换-------//

    static int i=0;
    this->second_Page=new secondUi;
    QMovie *mov=new QMovie("://Material/1.gif");
    ui->label_2->setMovie(mov);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->label_2->show();
        mov->start();
        changAnimate->start(50);
        i=0;
    });

    connect(changAnimate,&QTimer::timeout,[=](){
        i++;
        if(i==30){second_Page->show();};
        if(i==1){
            ui->label->close();
            ui->label_3->close();
            ui->pushButton->close();
            ui->pushButton->close();
            ui->pushButton_2->close();
        }
        if(i==32){this->hide();changAnimate->stop();mov->stop(); ui->label_2->close();i++;}
    });

    connect(this->second_Page,&secondUi::back,[=](){
        this->second_Page->hide();
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->label->show();
        this->show();
    });

    //--------------------//

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->close();
    });

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
