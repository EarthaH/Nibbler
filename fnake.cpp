#include "fnake.hpp"

Fnake::Fnake() : _size(4), _direction(RIGHT)
{
    this->body = new std::vector<Object>;

    Object  head(10, 10, 'b');
    Object  bod1(9, 10, 'o');
    Object  bod2(8, 10, 'o');
    Object  bod3(7, 10, 'o');

    body->push_back(head);
    body->push_back(bod1);
    body->push_back(bod2);
    body->push_back(bod3);
}

Fnake::Fnake(int x, int y) : _size(4), _direction(RIGHT)
{
    this->body = new std::vector<Object>;

    Object  head(x--, y, 'b');
    Object  bod1(x--, y, 'o');
    Object  bod2(x--, y, 'o');
    Object  bod3(x--, y, 'o');

    body->push_back(head);
    body->push_back(bod1);
    body->push_back(bod2);
    body->push_back(bod3);
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
    delete this->body;
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
        this->body->at(i).move(this->body->at(j).getOldX(), this->body->at(j).getOldY());
    }
}

void    Fnake::moveUp()
{
    this->body->front().move(this->body->front().getX(), this->body->front().getY() - 1);
    this->moveBody();
}

void    Fnake::moveDown()
{
    this->body->front().move(this->body->front().getX(), this->body->front().getY() + 1);
    this->moveBody();
}

void    Fnake::moveLeft()
{
    this->body->front().move(this->body->front().getX() - 1, this->body->front().getY());
    this->moveBody();
}

void    Fnake::moveRight()
{
    this->body->front().move(this->body->front().getX() + 1, this->body->front().getY());
    this->moveBody();
}

void    Fnake::eat()
{
    Object  bod(body->at(_size).getOldX(), body->at(_size).getOldY(), 'o');

    body->push_back(bod);
    _size++;
}