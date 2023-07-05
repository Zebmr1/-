#ifndef HELPUI_H
#define HELPUI_H

#include <QWidget>

namespace Ui {
class HelpUi;
}

class HelpUi : public QWidget
{
    Q_OBJECT

public:
    explicit HelpUi(QWidget *parent = nullptr);
    ~HelpUi();

signals:
    back();

private:
    Ui::HelpUi *ui;
};

#endif // HELPUI_H
