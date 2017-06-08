#ifndef FOOD_H
# define FOOD_H

#include "object.hpp"

class   Food: public Object
{
    private:
        bool    _eaten;

    public:
        Food();
        Food(Food const &);
        Food const & operator=(Food const &);
        ~Food();
        bool    getEaten();
        void    setEaten(bool);
};

#endif