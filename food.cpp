#include "food.hpp"
//#include "object.hpp"
//#include "game.hpp"
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

Food::Food(Fnake const & fnake) : _eaten(false)
{
    int     x = rand();
    int     y = rand();
    while (fnakeHit(fnake, x, y, 0))
    {
        x = rand();
        y = rand();
    }
    this->init(x, y, '*');
}

Food::Food(Fnake const & fnake, Game const & game) : _eaten(false)//why is game here? it is not used here at all. need to add a cout to make it useful
{
    int     x = rand();
    int     y = rand();
    while (fnakeHit(fnake, x, y, 0))
    {
        x = rand();
        y = rand();
    }
    this->init(x, y, '*');
    ///random code ot make it work
    std::cout << game.score << " testing I guess" << std::endl;
}

Food::Food(Fnake const * fnake) : _eaten(false)
{
    int     x = rand();
    int     y = rand();

    ///////
   // Fnake   const &tempFnake = *fnake;
    ///////
    while (fnakeHit(*fnake, x, y, 0))//added * to make it work
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