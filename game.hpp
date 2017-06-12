#ifndef GAME_H
# define GAME_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "snake.hpp"
#include "header.hpp"

class   Game 
{
    private:
        int     _width;
        int     _height;

    public:
        Game();
        Game(int, int);
        Game(Game const &);
        Game const & operator=(Game const &);
        ~Game();
        int     getWidth();
        int     getHeight();
        bool    gotFood(Snake const &, Food &);
        void    start();

        Snake   *snake;
        Food    *food;
        int     score;
        
};

#endif