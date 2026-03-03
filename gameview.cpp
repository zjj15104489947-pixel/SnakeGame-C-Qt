#include "gameview.h"
#include <QPainter>

GameView::GameView(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

void GameView::setController(gamecontroller *controller)
{
    m_controller = controller;
}

void GameView::paintEvent(QPaintEvent* event)
{
    if (!m_controller) return;

    (void)event;
    QPainter painter(this);
    painter.setBrush(QColor(30,30,30));  //设置填充笔刷，QColor红绿蓝配比（0-255）
    painter.drawRect(0,0,width(),height());  //画矩形，左上角坐标+宽高

    painter.setBrush(Qt::green);
    for (const auto& p : m_controller->snake().body())
    {
        painter.drawRect(p.x * 20, p.y * 20, 20, 20);
    }

    for (const auto& a : m_controller->apples())
    {
        if (a.type() == Apple::Normal)
            painter.setBrush(Qt::red);
        else if (a.type() == Apple::Gold)
            painter.setBrush(Qt::yellow);
        else
            painter.setBrush(Qt::magenta);

        painter.drawEllipse(a.position().x * 20,a.position().y * 20,20, 20);
    }
}
