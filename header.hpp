#ifndef HEADER_H
# define HEADER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "fnake.hpp"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

bool    equal(Object &, Object &);
bool    equal(Object &, int, int);
bool    fnakeHit(Fnake const &, Object &, int);
bool    fnakeHit(Fnake const &, int, int, int);

#endif