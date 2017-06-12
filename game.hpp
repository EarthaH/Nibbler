#ifndef GAME_H
# define GAME_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "fnake.hpp"
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
        bool    gotFood(Fnake const &, Food &);
        void    start();

        Fnake   *fnake;
        Food    *food;
        int     score;
        
};

#endif