#include "food.hpp"
#include <iostream>
#include <cstdlib>

Food::Food() : _eaten(false)
{
    int     x = rand();
    int     y = rand();

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
}