#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "snake.hpp"
#include "header.hpp"
#include "game.hpp"

Game::Game() : _width(300), _height(300)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->snake = new Snake(x ,y);
    this->food = new Food(snake);
    score = 0;
}

Game::Game(int w, int h) : _width(w), _height(h)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->snake = new Snake(x ,y);
    this->food = new Food(snake);
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
    delete this->snake;
    delete this->food;
}

bool    Game::gotFood(Snake const & snake, Food & food)
{
    if (snake.body[0].getX() == food.getX() && snake.body[0].getY() == food.getY())
        return (true);
    return (false);
}

void    Game::start()
{
    for (;;)
    {
        if (gotFood(*snake, *food))
        {
            snake->eat();
            food->setEaten(true);
            food = new Food(snake);
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