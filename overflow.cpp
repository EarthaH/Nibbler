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

bool    fnakeHit(Fnake const & fnake, Object & obj, int start)
{
    for (int i = start; i < fnake.getSize(); i++)
        if (equal(fnake.body[i], obj))
            return (true);
    return (false);
}

bool    fnakeHit(Fnake const & fnake, int x, int y, int start)
{
    for (int i = start; i < fnake.getSize(); i++)
        if (equal(fnake.body[i], x, y))
            return (true);
    return (false);
}