#ifndef FOOD_H
# define FOOD_H

#include "header.hpp"
#include "object.hpp"
#include "game.hpp"

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