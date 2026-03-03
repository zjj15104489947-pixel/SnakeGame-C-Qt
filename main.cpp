#include "gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(nullptr));  //初始化随机数种子
    QApplication a(argc, argv);
    gamewindow w;
    w.show();
    return a.exec();
}
