#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "Point.h"

class Snake
{
public:
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    };
    Snake();

    void move();
    void grow(int count);
    void shrink(int count);
    void changeDirection(Direction dir);

    Point head() const;
    int length() const;
    bool hitself() const;
    bool contains(const Point& p) const;  //检测是否在蛇身上

    const std::deque<Point>& body() const;

private:
    std::deque<Point> m_body; //蛇全身坐标
    Direction m_dir;  //蛇移动方向
    int m_growPending;  //蛇变长节数
};

#endif // SNAKE_H
