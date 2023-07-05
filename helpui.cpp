#include "helpui.h"
#include "ui_helpui.h"

HelpUi::HelpUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpUi)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        emit this->back();
    });

    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
}

HelpUi::~HelpUi()
{
    delete ui;
}

