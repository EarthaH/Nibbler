#include "header.hpp"

bool    equal(Object & a, Object & b)
{
    if (a.getX() == b.getX() && a.getY() == b.getY())
        return (true);
    return (false);
}

bool    equal(Object & obj, int x, int y)
{
    if (obj.getX() == x && obj.getY() == y)
        return (true);
    return (false);
}

bool    snakeHit(Snake const & snake, Object & obj, int start)
{
    for (int i = start; i < snake.getSize(); i++)
        if (equal(snake.body[i], obj))
            return (true);
    return (false);
}

bool    snakeHit(Snake const & snake, int x, int y, int start)
{
    for (int i = start; i < snake.getSize(); i++)
        if (equal(snake.body[i], x, y))
            return (true);
    return (false);
}