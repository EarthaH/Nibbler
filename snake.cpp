#include "fnake.hpp"

Fnake::Fnake() : _size(4), _direction(0)
{
    this->body = new Object[_size];
    for (int x = 10, y = 10, i = 0; i < this->_size; i++, x--)
    {
        this->body[i].init(x, y, 'o');
    }
}

Fnake::Fnake(int x, int y) : _size(4), _direction(0)
{
    this->body = new Object[_size];
    for (int i = 0; i < this->_size; i++, x--)
    {
        this->body[i].init(x, y, 'o');
    }
}

Fnake::Fnake(Fnake const & copy)
{
    *this = copy;
}

Fnake const & Fnake::operator=(Fnake const & copy)
{
    this->_size = copy._size;
    this->_direction = copy._direction;
    this->body = copy.body;
    return (*this);
}

Fnake::~Fnake()
{
    delete [] this->body;
}

int     Fnake::getSize() const
{
    return (this->_size);
}

int     Fnake::getDirection() const 
{
    return (this->_direction);
}

void    Fnake::setSize(int size)
{
    this->_size = size;
}

void    Fnake::setDirection(int dir)
{
    this->_direction = dir;
}

void    Fnake::moveBody()
{
    for (int i = 1, j = 0; i < this->_size; i++, j++)
    {
        this->body[i].move(this->body[j].getOldX(), this->body[j].getOldY());
    }
}

void    Fnake::moveUp()
{
    this->body[0].move(this->body[0].getX(), this->body[0].getY() - 1);
    this->moveBody();
}

void    Fnake::moveDown()
{
    this->body[0].move(this->body[0].getX(), this->body[0].getY() + 1);
    this->moveBody();
}

void    Fnake::moveLeft()
{
    this->body[0].move(this->body[0].getX() - 1, this->body[0].getY());
    this->moveBody();
}

void    Fnake::moveRight()
{
    this->body[0].move(this->body[0].getX() + 1, this->body[0].getY());
    this->moveBody();
}

void    Fnake::eat()
{
    this->_size++;
    Object  *newFnake = new Object[this->_size];
    for (int i = 0; i < this->_size - 1; i++)
    {
        newFnake[i] = this->body[i];
    }
    delete [] this->body;
    newFnake[this->_size].init(newFnake[this->_size - 1].getOldX(), newFnake[this->_size - 1].getOldY(), 'o');
    this->body = newFnake;
    delete [] newFnake;
}