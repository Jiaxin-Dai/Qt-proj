#include "dmwindow.h"
#include "ui_dmwindow.h"

DMWindow::DMWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DMWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(on_pushButton_2_clicked()));
    srand(time(0));
    this->setFixedSize(this->size());
}


DMWindow::~DMWindow()
{
    delete ui;
}

void DMWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QFile file("D:/study/c/qt creator/dianming/data/名单.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"Open file error!";
    else{

        while(!file.atEnd()){
            ui->listWidget->addItem(file.readLine().trimmed());
        }
    }
}


void DMWindow::on_pushButton_2_clicked()
{
    QListWidget *list = ui->listWidget;

    if(timer.isActive())
    {
        qDebug()<<timer.interval();
        if(timer.interval() < 330){
            int n = list->count();
            int cur = list->currentRow();
            list->setCurrentRow( ( cur + 1) % n );
            timer.setInterval(timer.interval() + 5);
            QListWidgetItem *item = list->currentItem();
            ui->lineEdit->setText(item->text());
        }
        else{
            timer.stop();
            }
        }
    else{
     timer.start(20);
    }
}
