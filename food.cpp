#include "food.hpp"
#include "object.hpp"
#include "game.hpp"

Food::Food() : _eaten(false)
{
    int     x = rand();
    int     y = rand();

    this->init(x, y, '*');
}

Food::Food(int x, int y) : _eaten(false)
{
    this->init(x, y, '*');
}

Food::Food(Snake const & snake) : _eaten(false)
{
    int     x = rand();
    int     y = rand();
    while (snakeHit(snake, x, y, 0))
    {
        x = rand();
        y = rand();
    }
    this->init(x, y, '*');
}

Food::Food(Snake const & snake, Game const & game) : _eaten(false)
{
    int     x = rand();
    int     y = rand();
    while (snakeHit(snake, x, y, 0))
    {
        x = rand();
        y = rand();
    }
    this->init(x, y, '*');
}

Food::Food(Snake const * snake) : _eaten(false)
{
    int     x = rand();
    int     y = rand();
    while (snakeHit(snake, x, y, 0))
    {
        x = rand();
        y = rand();
    }
    this->init(x, y, '*');
}

Food::Food(Food const & copy)
{
    *this = copy;
}

Food const & Food::operator=(Food const & copy)
{
    this->_eaten = copy._eaten;
    return (*this);
}

Food::~Food()
{

}

bool    Food::getEaten()
{
    return (this->_eaten);
}

void    Food::setEaten(bool eaten)
{
    this->_eaten = eaten;
    if (this->_eaten)
        delete this;
}