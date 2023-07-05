#include "thirdpage.h"
#include "ui_thirdpage.h"

ThirdPage::ThirdPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThirdPage)
{
    ui->setupUi(this);
}

ThirdPage::~ThirdPage()
{
    delete ui;
}
