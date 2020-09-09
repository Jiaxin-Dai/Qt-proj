#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->send,SIGNAL(clicked()),this,SLOT(slotInput()));
    connect(ui->cancel,SIGNAL(clicked()),ui->input,SLOT(clear()));
}
void MainWindow::slotInput(){

          ui->output->setPlainText(ui->input->text());
          ui->input->clear();
}

MainWindow::~MainWindow()
{
    delete ui;

}
