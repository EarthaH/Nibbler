#include <cstdlib>
#include <ctime>
#include <iostream>
#include "food.hpp"
#include "object.hpp"
#include "snake.hpp"

bool    gotFood(Snake const & snake, Food & food)
{
    if (snake.body[0].getX() == food.getX() && snake.body[0].getY() == food.getY())
        return (true);
    return (false);
}

void    start()
{
    Snake   *snake = new Snake();
    Food    *food = new Food();

    for (;;)
    {
        if (gotFood(*snake, *food))
        {
            snake->eat();
            food->setEaten(true);
            delete food;
            food = new Food();
        }
    }
}

int     main()
{
    start();
    return (0);
}