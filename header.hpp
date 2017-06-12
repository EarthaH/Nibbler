#ifndef HEADER_H
# define HEADER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "snake.hpp"

bool    equal(Object &, Object &);
bool    equal(Object &, int, int);
bool    snakeHit(Snake const &, Object &, int);
bool    snakeHit(Snake const &, int, int, int);

#endif