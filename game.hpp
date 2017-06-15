#ifndef GAME_H
# define GAME_H

#include "header.hpp"
///////////////////////////////
/*
#include "object.hpp"
#include "fnake.hpp"
#include "food.hpp"
*/


class   Fnake;
//class   Object;
class   Food;//: public Object;//might need to take out inheritance

class   Game 
{
    private:
        int     _width;
        int     _height;

    public:
        Game();
        Game(int w, int h);
        Game(Game const &);
        Game const & operator=(Game const &);
        ~Game();
        int     getWidth();
        int     getHeight();
        bool    gotFood(Fnake const & fnake, Food & food);
        bool    blockClear();
        void    start();
        void    move();
        void    end();

        Fnake   *fnake;
        Food    *food;
        int     score;
        int     speed;
        
};

#endif