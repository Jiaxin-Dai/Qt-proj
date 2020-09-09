#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenuBar>//所有窗口的菜单栏，在此基础上添加不同的QMenu和QAction
#include <QMenu>//菜单栏里面菜单，可以显示文本和图标，但是并不负责执行操作
#include <QAction>//用户与界面进行交互的元素,负责执行操作的部件
#include <QTimer>//计时器
#include "MyGame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

protected:
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件

private slots:

    void on_actionRestart_triggered();//重新开始触发函数
    void on_actionExit_triggered();//退出游戏触发函数

    void on_actionEasy_triggered();//简单模式

    void on_actionNormal_triggered();//中等难度

    void on_actionHard_triggered();//困难难度
    void on_actionAbout_triggered();

    void on_time();//计时

private:
    CMyGame myGame;
    int offsetx,offsety;//用于储存鼠标指针位置与窗口位置的插值
    QTimer *time;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
