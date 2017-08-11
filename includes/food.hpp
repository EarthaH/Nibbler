#ifndef FOOD_H
# define FOOD_H

#include "header.hpp"

class   Fnake;
class   Game;
class   Object;

class   Food: public Object
{
    private:
        bool    _eaten;

    public:
        Food();
        Food(int, int);
        Food(Fnake const *, int, int);
        Food(Food const &);
        Food const & operator=(Food const &);
        ~Food();
        bool    getEaten();
        void    setEaten(bool);
};

#endif