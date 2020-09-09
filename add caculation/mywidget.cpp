#include <MyWidget.h>

MyWidget::MyWidget(){
    edit1 = new QLineEdit(this);
    edit2 = new QLineEdit(this);
    lineEdit3 = new QLineEdit(this);
    button = new QPushButton("test",this);
    connect(button,SIGNAL(clicked()),this,SLOT(slotButtonClick()));

    edit1->move(60,50);
    edit2->move(60,150);
    lineEdit3->move(60,250);
    button->move(200,350);
    setFont(QFont("",32));
    resize(500,400);
}
void MyWidget::slotButtonClick(){
    QString str1,str2,strResult;
    int add1=0,add2=0,result=0;
    str1 = edit1->text();
    str2 = edit2->text();
    add1=str1.toInt();
    add2=str2.toInt();
    result = add1 + add2;
    strResult.sprintf("%d+%d=%d",add1,add2,result);
    lineEdit3->setText(strResult);
}
