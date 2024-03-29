#ifndef GAME_H
# define GAME_H

#include "header.hpp"
#include "IEntity.hpp"
#include <thread>

class   Fnake;
class   Food;

class   Game 
{
    private:
        int         _width;
        int         _height;
        IEntity     *_library;
        const char  **_libs;

    public:
        Game();
        Game(int w, int h);
        Game(Game const &);
        Game const & operator=(Game const &);
        ~Game();
        int     getWidth();
        int     getHeight();
        bool    gotFood(Fnake const & fnake, Food & food);
        bool    blockClear();
        void    start();
        void    move();
        void    end();
        void    init();
        void    draw();
        void    changeDir(int);
        void    setLib(int);
        void    dlerror_wrapper();
        void    deleteLibrary();

        Fnake   *fnake;
        Food    *food;
        int     score;
        int     speed;
        void    *dl_handle;
        
};

#endif