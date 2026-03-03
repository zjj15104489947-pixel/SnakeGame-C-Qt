#ifndef APPLE_H
#define APPLE_H

#include "Point.h"

class Apple
{
public:
    enum Type
    {
        Normal,
        Gold,
        Poison
    };

    Apple(Point pos,Type type,int life);

    Point position() const;
    Type type() const;

    void decreaseLife();  //苹果存在时间减少
    bool isDead() const;  //苹果是否要消失


private:
    Point m_pos;
    Type m_type;
    int m_life;  //剩余帧数
};

#endif // APPLE_H
