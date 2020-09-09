#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    i=10;
    n=0;
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(slotMove()));
    timer.start(50);
    dx = dy =5;

}
void MyWidget::slotMove(){
    if(ui->label->y() <120)
        dy = i;
    if(ui->label->x() < 0)
        dx = i;
    if(ui->label->x() >width()-40)
        dx = -i;
    if(ui->label->x()+20>=ui->bat->x()&&ui->label->x()+20<=ui->bat->x()+130)
    {

       if(ui->label->y()+40==ui->bat->y())
       {

            n++;
            i+=2;
            dy=-i;
       }

    }
    ui->label->move(ui->label->x()+dx,ui->label->y()+dy);
    ui->grade->display(n);

}
void MyWidget::keyPressEvent(QKeyEvent *e){
    if(e->key()== Qt::Key_Left)
        ui->bat->move(ui->bat->x()-10,ui->bat->y());
    if(e->key()== Qt::Key_Right)
        ui->bat->move(ui->bat->x()+10,ui->bat->y());
}

MyWidget::~MyWidget()
{
    delete ui;
}
