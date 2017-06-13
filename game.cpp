#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

#include "food.hpp"
#include "object.hpp"
#include "fnake.hpp"
#include "header.hpp"
#include "game.hpp"

Game::Game() : _width(300), _height(300), score(0), speed(3000)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->fnake = new Fnake(x ,y);
    this->food = new Food(fnake);
    score = 0;
}

Game::Game(int w, int h) : _width(w), _height(h), score(0), speed(3000)
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

/* *** *** *** Main Loop *** *** *** */

void    Game::start()
{
    for (;;)
    {
        // Add user input and direction setting 
        if (gotFood(*fnake, *food))
        {
            fnake->eat();
            food->setEaten(true);
            food = new Food(fnake);
            this->score += 10;
            this->speed -= 10;
        }
        move();
        if (!blockClear())
            end();
        sleep(this->speed);
    }
}

/* Check if snake hit food */
// Unknown error -> won't accept 'gotFood' 
bool    Game::gotFood(Fnake const & fnake, Food & food)
{
    if (fnake.body[0].getX() == food.getX() && fnake.body[0].getY() == food.getY())
        return (true);
    return (false);
}

/* Move snake in set direction */

void    Game::move()
{
    int     dir = this->fnake->getDirection();

    if (dir == RIGHT)
        this->fnake->moveRight();
    else if (dir == LEFT)
        this->fnake->moveLeft();
    else if (dir == UP)
        this->fnake->moveUp();
    else if (dir == DOWN)
        this->fnake->moveDown();
}

/* Check that snake is not dead */

bool    Game::blockClear()
{
    int     x = this->fnake->body[0].getX();
    int     y = this->fnake->body[0].getY();

    if (x == 0 || y == 0 || x == this->_width || y == this->_height)
        return (false);
    if (fnakeHit(*this->fnake, this->fnake->body[0], 1))
        return (false);
    
    return (true);
}

/* End game */

void    Game::end()
{
    // Display user results and give option to exit or restart
}

int     Game::getWidth()
{
    return (this->_width);
}

int     Game::getHeight()
{
    return (this->_height);
}