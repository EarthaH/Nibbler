#ifndef FNAKE_H
#define FNAKE_H

#include "header.hpp"

class   Object;

class   Fnake
{
    private:
        int     _size;
        int     _direction;
    
    public: 
        Fnake();
        Fnake(int, int);
        Fnake(Fnake const &);
        Fnake const & operator=(Fnake const &);
        ~Fnake();
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

};

#endif