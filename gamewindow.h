#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include "gamecontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class gamewindow;
}
QT_END_NAMESPACE

class gamewindow : public QWidget
{
    Q_OBJECT

public:
    gamewindow(QWidget *parent = nullptr);
    ~gamewindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;  //Qwidget中的虚函数，用于处理用户按下按键的事件


private slots:  //QT能自动调用的函数，每次timer到点就会调用
    void gameLoop();


private:
    gamecontroller m_controller;
    QTimer* m_timer;  //Qt中的定时器类，在指定时间间隔触发信号

    void startGame();

    int m_lastScore;
    void saveScore(int score);  //保存分数
    void updateRankPage();  //更新计分排行榜

    Ui::gamewindow *ui;
};

#endif // GAMEWINDOW_H
