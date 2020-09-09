#include "dmwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DMWindow w;
    w.show();

    return a.exec();
}
