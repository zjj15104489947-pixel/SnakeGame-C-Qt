#include "Snake.h"
using namespace std;

Snake::Snake(): m_dir(Right),m_growPending(0)
{
    m_body.push_back({5,5});
    m_body.push_back({4,5});
    m_body.push_back({3,5});
}

Point Snake::head() const
{
    return m_body.front();
}

int Snake::length() const
{
    return m_body.size();
}

void Snake::move()
{
    Point newhead=head();
    switch(m_dir)
    {
        case Up: newhead.y--; break;
        case Down: newhead.y++; break;
        case Left: newhead.x--; break;
        case Right: newhead.x++; break;
        default:     break;
    }

    m_body.push_front(newhead);

    if(m_growPending>0) m_growPending--;
    else m_body.pop_back();
}

void Snake::grow(int count)
{
    if(count>0)
    m_growPending+=count;
}

void Snake::shrink(int count)
{
    while(count-->0&&m_body.size()>1)
    {
        m_body.pop_back();
    }
}

void Snake::changeDirection(Direction dir)
{
    if((m_dir==Up&&dir==Down)||(m_dir==Down&&dir==Up)||(m_dir==Left&&dir==Right)||(m_dir==Right&&dir==Left))
        return;
    m_dir=dir;
}

bool Snake::hitself() const
{
    const Point h=head();
    for(size_t i=1;i<m_body.size();i++)
    {
        if(m_body[i]==h) return true;
    }
    return false;
}

bool Snake::contains(const Point& p) const
{
    for(const auto& bodyPoint: m_body)
    {
        if(bodyPoint==p) return true;
    }
    return false;
}

const deque<Point>& Snake::body() const
{
    return m_body;
}



