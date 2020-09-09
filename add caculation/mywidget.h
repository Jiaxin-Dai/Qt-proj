#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

class MyWidget : public QWidget{
    Q_OBJECT
public:
    MyWidget();
public slots:
    void slotButtonClick();
private:
    QPushButton *button;
    QLineEdit *edit1;
    QLineEdit *edit2;
    QLineEdit *lineEdit3;
    QLabel *Label;

};
#endif // MYWIDGET_H
