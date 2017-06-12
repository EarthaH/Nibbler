#include "header.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "snake.hpp"
#include "game.hpp"

void    start()
{
    

}

int     main(int argc, char **argv)
{
    int     x, y;

    if (argc == 3)
    {
        try
        {
            x = atoi(argv[1]);
            y = atoi(argv[2]);
        }
        catch (...)
        {
            std::cout << "Yes a window can totally be of size " << argv[1] << " x " << argv[2] << std::endl;
            std::cout << "Come back when you know what an int is!" << std::endl;
            exit(0);
        }
    }
    else
    {
        x = 300;
        y = 200;
    }
    
    srand((unsigned)time(0));

    Game    *game = new Game(x, y);
    game->start();

    return (0);
}