#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void keyPressEvent(QKeyEvent *e);

public slots:
    void slotMove();

private:
    Ui::MyWidget *ui;
    QTimer timer;
    int dx,dy,n;
    float i;
};

#endif // MYWIDGET_H
