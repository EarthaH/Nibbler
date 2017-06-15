#ifndef HEADER_H
# define HEADER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
#include <unistd.h>

#include "object.hpp"
#include "food.hpp"
#include "fnake.hpp"
#include "game.hpp"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4



//class   Fnake;
//class   Game;
//class   Object;
//class   Food;

bool    equal(Object &, Object &);
bool    equal(Object &, int, int);
bool    fnakeHit(Fnake const &, Object &, int);
bool    fnakeHit(Fnake const &, int, int, int);

#endif