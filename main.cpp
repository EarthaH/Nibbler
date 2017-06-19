#include "header.hpp"

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
            if (x < 10 || y < 10 || x > 1000 || y > 1000)
                throw std::overflow_error("incorrect size") ;
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