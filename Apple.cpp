#include "Apple.h"
using namespace std;

Apple::Apple(Point pos,Type type,int life): m_pos(pos),m_type(type),m_life(life) {}

Point Apple::position() const
{
    return m_pos;
}

Apple::Type Apple::type() const
{
    return m_type;
}


void Apple::decreaseLife() {
    if (m_life > 0)
        m_life--;
}

bool Apple::isDead() const {
    return m_life == 0;
}
