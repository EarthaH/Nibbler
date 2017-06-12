#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "fnake.hpp"
#include "header.hpp"
#include "game.hpp"

Game::Game() : _width(300), _height(300)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->fnake = new Fnake(x ,y);
    this->food = new Food(fnake);
    score = 0;
}

Game::Game(int w, int h) : _width(w), _height(h)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->fnake = new Fnake(x ,y);
    this->food = new Food(fnake);
    score = 0;
}

Game::Game(Game const & copy)
{
    *this = copy;
}

Game const & Game::operator=(Game const & copy)
{
    this->_width = copy._width;
    this->_height = copy._height;
    return (*this);
}

Game::~Game()
{
    delete this->fnake;
    delete this->food;
}

bool    Game::gotFood(Fnake const & fnake, Food & food)
{
    if (fnake.body[0].getX() == food.getX() && fnake.body[0].getY() == food.getY())
        return (true);
    return (false);
}

void    Game::start()
{
    for (;;)
    {
        if (gotFood(*fnake, *food))
        {
            fnake->eat();
            food->setEaten(true);
            food = new Food(fnake);
        }
    }
}

int     Game::getWidth()
{
    return (this->_width);
}

int     Game::getHeight()
{
    return (this->_height);
}