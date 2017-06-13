#include "header.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "food.hpp"
#include "object.hpp"
#include "fnake.hpp"
#include "game.hpp"

int     x;
int     y;

void    getSize(int ac, char **av)
{
    if (ac == 3)
    {
        try
        {
            x = atoi(av[1]);
            y = atoi(av[2]);
            // Add max height and width handle
        }
        catch (...)
        {
            std::cout << "Yes a window can totally be of size " << av[1] << " x " << av[2] << std::endl;
            std::cout << "Come back when you know what an int is!" << std::endl;
            exit(0);
        }
    }
    else
    {
        std::cout << "It seems you need womans help... Usage: av[1] = width, av[2] = height" << std::endl;
        exit(0);
    }
}

int     main(int argc, char **argv)
{
    getSize(argc, argv);
    
    srand((unsigned)time(0));

    Game    *game = new Game(x, y);
    game->start();

    return (0);
}