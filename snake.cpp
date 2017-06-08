#include "snake.hpp"
#include "food.hpp"

Snake::Snake() : _size(4), _direction(0)
{
    this->body = new Object[_size];
    for (int x = 10, y = 10, i = 0; i < this->_size; i++, x--)
    {
        this->body[i].init(x, y, 'o');
    }
}

Snake::Snake(int x, int y) : _size(4), _direction(0)
{
    this->body = new Object[_size];
    for (int i = 0; i < this->_size; i++, x--)
    {
        this->body[i].init(x, y, 'o');
    }
}

Snake::Snake(Snake const & copy)
{
    *this = copy;
}

Snake const & Snake::operator=(Snake const & copy)
{
    this->_size = copy._size;
    this->_direction = copy._direction;
    this->body = copy.body;
    return (*this);
}

Snake::~Snake()
{
    delete [] this->body;
}

int     Snake::getSize() const
{
    return (this->_size);
}

int     Snake::getDirection() const 
{
    return (this->_direction);
}

void    Snake::setSize(int size)
{
    this->_size = size;
}

void    Snake::setDirection(int dir)
{
    this->_direction = dir;
}

void    Snake::moveBody()
{
    for (int i = 1, j = 0; i < this->_size; i++, j++)
    {
        this->body[i].move(this->body[j].getOldX(), this->body[j].getOldY());
    }
}

void    Snake::moveUp()
{
    this->body[0].move(this->body[0].getX(), this->body[0].getY() - 1);
    this->moveBody();
}

void    Snake::moveDown()
{
    this->body[0].move(this->body[0].getX(), this->body[0].getY() + 1);
    this->moveBody();
}

void    Snake::moveLeft()
{
    this->body[0].move(this->body[0].getX() - 1, this->body[0].getY());
    this->moveBody();
}

void    Snake::moveRight()
{
    this->body[0].move(this->body[0].getX() + 1, this->body[0].getY());
    this->moveBody();
}

void    Snake::eat()
{
    this->_size++;
    Object  *newSnake = new Object[this->_size];
    for (int i = 0; i < this->_size - 1; i++)
    {
        newSnake[i] = this->body[i];
    }
    delete [] this->body;
    newSnake[this->_size].init(newSnake[this->_size - 1].getOldX(), newSnake[this->_size - 1].getOldY(), 'o');
    this->body = newSnake;
    delete [] newSnake;
}