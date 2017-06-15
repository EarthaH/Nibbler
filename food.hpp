#ifndef FOOD_H
# define FOOD_H

#include "header.hpp"
//#include "fnake.hpp"
//////////////////
/*
#include "game.hpp"
#include "object.hpp"
#include "fnake.hpp"
*/


//class   Object;

//#include "object.hpp"




class   Fnake;
class   Game;
//class   Object;

class   Food: public Object
{
    private:
        bool    _eaten;

    public:
        Food();
        Food(int, int);
        Food(Fnake const &);
        Food(Fnake const *);
        Food(Fnake const &, Game const &);
        Food(Food const &);
        Food const & operator=(Food const &);
        ~Food();
        bool    getEaten();
        void    setEaten(bool);
};

#endif