#include "../includes/food.hpp"
//////////////////////

bool    fnakeHit(Fnake const &, Object &, int);
bool    fnakeHit(Fnake const &, int, int, int);

//////////////////////
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

Food::Food(Fnake const * fnake, int w, int h) : _eaten(false)
{
    int     x = rand() % (w - 1) + 1;
    int     y = rand() % (h - 1) + 1;

    while (fnakeHit(*fnake, x, y, 0))
    {
        x = rand() % w;
        y = rand() % h;
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