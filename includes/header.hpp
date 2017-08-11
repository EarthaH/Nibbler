#ifndef HEADER_H
# define HEADER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <dlfcn.h>
#include <curses.h>

#include "object.hpp"
#include "food.hpp"
#include "fnake.hpp"
#include "game.hpp"

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define LIB1 "lib1.so"
#define LIB2 "lib2.so"
#define LIB3 "lib3.so"

bool    equal(Object &, Object &);
bool    equal(Object &, int, int);
bool    fnakeHit(Fnake const &, Object &, int);
bool    fnakeHit(Fnake const &, int, int, int);

#endif