#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"secondui.h"
#include<QTimer>
#include<QDebug>
#include<QMovie>
#include<QRect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    secondUi * second_Page=NULL;
    QTimer *changAnimate=new QTimer(this);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
