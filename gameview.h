#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#pragma once
#include <QWidget>
#include "gamecontroller.h"


class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = nullptr);

    void setController(gamecontroller *controller);

protected:
    void paintEvent(QPaintEvent* event) override;  //Qwidget中的虚函数，用于完成绘制操作

private:
    gamecontroller *m_controller = nullptr;
};

#endif // GAMEVIEW_H
