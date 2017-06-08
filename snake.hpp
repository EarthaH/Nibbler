#ifndef SNAKE_H
#define SNAKE_H

#include "object.hpp"
#include "food.hpp"

class   Snake
{
    private:
        int     _size;
        int     _direction;
    
    public: 
        Snake();
        Snake(int, int);
        Snake(Snake const &);
        Snake const & operator=(Snake const &);
        ~Snake();
        Object  *body;
        int     getSize() const;
        int     getDirection() const;
        void    setSize(int);
        void    setDirection(int);
        void    moveBody();
        void    moveUp();
        void    moveDown();
        void    moveLeft();
        void    moveRight();
        void    eat();
        void    eat(Food &);

};

#endif