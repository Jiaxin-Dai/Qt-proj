#ifndef DMWINDOW_H
#define DMWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <stdlib.h>
#include <QTimer>


namespace Ui {
class DMWindow;
}

class DMWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DMWindow(QWidget *parent = 0);
    ~DMWindow();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DMWindow *ui;
    QTimer timer;
    int n , i;
};

#endif // DMWINDOW_H
