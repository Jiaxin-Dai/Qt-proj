#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include<QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MyGame");
    myGame.Create();
    offsetx=5;
    offsety=30;
    setFixedSize(myGame.mx*20+offsetx*2,myGame.my*20+offsety+66);//设置这个窗口部件的宽高
    time=new QTimer(this);
    connect( time,SIGNAL(timeout()), this, SLOT(on_time()) );
}

void MainWindow::on_actionRestart_triggered()
{
    myGame.Restart();
    update();//重绘
}
void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPixmap bmpmap(":new/prefix1/res/item2.bmp");
    QPixmap bmpnub(":new/prefix1/res/item1.bmp");
    QPixmap bmpfame(":new/prefix1/res/item3.bmp");
    QPixmap bmpface(":new/prefix1/res/item4.bmp");
    //实例 QPainter 绘制类
    QPainter painter(this);
    //绘制雷区
    for(int i=0;i<myGame.mx;i++)
    {
        for(int j=0;j<myGame.my;j++)
        {
            if (myGame.Map[i][j] >= 0 && myGame.Map[i][j] < 9)
            {
                painter.drawPixmap( i * 20+offsetx, j * 20 + 40+offsety,  bmpmap, myGame.Map[i][j] * 20, 0,20,20);
            }
            if (myGame.Map[i][j]>90)
                painter.drawPixmap(i * 20+offsetx, j * 20 + 40+offsety,bmpmap, 10 * 20, 0,20,20);
            if (myGame.Map[i][j] == -1)
                painter.drawPixmap(i * 20+offsetx, j * 20 + 40+offsety,bmpmap, 9 * 20, 0,20,20);
            if (myGame.Map[i][j] == -2)
                painter.drawPixmap(i * 20+offsetx, j * 20 + 40+offsety,  bmpmap, 12 * 20, 0,20,20);
            if (myGame.Map[i][j] > 40 && myGame.Map[i][j] < 60)
                painter.drawPixmap(i * 20+offsetx, j * 20 + 40+offsety,  bmpmap, 11 * 20, 0,20,20);
        }
    }
    int rm=myGame.rBoom;
    int rt=myGame.timer;
    //绘制框架
    painter.drawPixmap( 0+offsetx, 0+offsety, bmpfame, 0, 0, 70, 40);
    painter.drawPixmap(myGame.mx * 10 - 20+offsetx, 0+offsety, bmpfame, 80, 0, 40, 40);
    painter.drawPixmap(myGame.mx * 20 - 70+offsetx, 0+offsety, bmpfame, 130, 0, 70, 40);
    painter.drawPixmap(70+offsetx, 0+offsety, myGame.mx * 10 - 90, 40, bmpfame, 70, 0, 10, 40);
    painter.drawPixmap(myGame.mx * 10 + 20+offsetx, 0+offsety, myGame.mx * 10 - 90, 40, bmpfame, 70, 0, 10, 40);
    painter.drawPixmap(myGame.mx * 10 - 12+offsetx, 7+offsety, bmpface, myGame.winf * 24, 0, 24, 24);
    //绘制剩余雷数
    if (rm < 0) rm = 0;
    painter.drawPixmap(6+offsetx, 5+offsety, bmpnub, rm / 100 * 20, 0, 20, 28);
    if (rm >= 100) rm %= 100;
    painter.drawPixmap(26+offsetx, 5+offsety, bmpnub, rm / 10 * 20, 0, 20, 28);
    painter.drawPixmap(46+offsetx, 5+offsety, bmpnub, rm % 10 * 20, 0, 20, 28);
    //绘制扫雷时间
    if (rt >= 1000) rt %= 1000;
    painter.drawPixmap(myGame.mx*20-66+offsetx, 5+offsety, bmpnub, rt / 100 * 20, 0, 20, 28);
    if (rt >= 100) rt %= 100;
    painter.drawPixmap(myGame.mx*20 - 46+offsetx, 5+offsety, bmpnub, rt / 10 * 20, 0, 20, 28);
    painter.drawPixmap(myGame.mx*20 - 26+offsetx, 5+offsety, bmpnub, rt % 10 * 20, 0, 20, 28);
}

//鼠标消息处理
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int px=event->x()-offsetx;
    int py=event->y() -offsety;
    int m = (px) / 20;
    int n = (py) / 20 - 2;
    if(event->buttons()==(Qt::LeftButton|Qt::RightButton))
    {
        if(myGame.Onlrbtdown(m, n))
            update();
    }
    else if(event->button()==Qt::LeftButton)
    {
        if(myGame.Onlbtup(m,n))
        {
            if (!(time->isActive() ))
                time->start(1000);//开始计时
            update();
        }
        if (myGame.winf==0 || myGame.winf == 2)
        {
            if (time->isActive() )
                time->stop();//停止计时
            if (px >  myGame.mx * 10 - 15 && px< myGame.mx * 10 + 15 && py>4 && py < 34)
            {
                myGame.Restart();//点击表情图标重新开始
                update();
            }
        }
    }
    else if(event->button()==Qt::RightButton)
    {
        if(myGame.Onrbtdown(m, n))
            update();
    }
    else if(event->button()==Qt::MidButton)
    {

    }
}

//初级
void MainWindow::on_actionEasy_triggered()
{
    myGame.Create(10,8,15);
    setFixedSize(myGame.mx*20+offsetx*2,myGame.my*20+offsety+66);
}
//中级
void MainWindow::on_actionNormal_triggered()
{
    myGame.Create(20,15,50);
    setFixedSize(myGame.mx*20+offsetx*2,myGame.my*20+offsety+66);
}
//高级
void MainWindow::on_actionHard_triggered()
{
    myGame.Create(30,20,100);
    setFixedSize(myGame.mx*20+offsetx*2,myGame.my*20+offsety+66);
}
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"about","CREAT BY : DAIJIAXIN & WANGMIAO");
}


//计时器每秒加一
void MainWindow::on_time()
{
    myGame.timer++;
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
