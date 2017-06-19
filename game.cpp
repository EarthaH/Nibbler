#include "game.hpp"

Game::Game() : _width(300), _height(300), score(0), speed(2000)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->fnake = new Fnake(x ,y);
    this->food = new Food(fnake, this->_width, this->_height);
    score = 0;
}

Game::Game(int w, int h) : _width(w), _height(h), score(0), speed(2000)
{
    int     x = this->_width / 2;
    int     y = this->_height / 2;
    this->fnake = new Fnake(x ,y);
    this->food = new Food(fnake, this->_width, this->_height);
    score = 0;
}

Game::Game(Game const & copy)
{
    *this = copy;
}

Game const & Game::operator=(Game const & copy)
{
    this->_width = copy._width;
    this->_height = copy._height;
    return (*this);
}

Game::~Game()
{
    delete this->fnake;
    delete this->food;
}

/* *** *** *** Main Loop *** *** *** */

void    Game::start()
{
    for (;;)
    {
        // Add user input and direction setting 
        if (gotFood(*fnake, *food))
        {
            fnake->eat();
            delete food;
            food = new Food(fnake, this->_width, this->_height);
            this->score += 10;
            this->speed -= this->speed > 100 ? 10 : 0;
            std::cout << "Game speed now: " << this->speed << std::endl;
        }
        move();
        if (!blockClear())
            end();
            
        std::this_thread::sleep_for(std::chrono::milliseconds(this->speed));
    }
}

/* Check if snake hit food */

bool    Game::gotFood(Fnake const & fnake, Food & food)
{
    if (fnake.body->front().getX() == food.getX() && fnake.body->front().getY() == food.getY())
        return (true);
    return (false);
}

/* Move snake in set direction */ //also which direction snakes will move in

void    Game::move()
{
    int     dir = this->fnake->getDirection();

    if (dir == RIGHT)
        this->fnake->moveRight();
    else if (dir == LEFT)
        this->fnake->moveLeft();
    else if (dir == UP)
        this->fnake->moveUp();
    else if (dir == DOWN)
        this->fnake->moveDown();
    std::cout << "Snake moved from: " << this->fnake->body->front().getOldX() << " " \
     << this->fnake->body->front().getOldY() << " to: " << this->fnake->body->front().getX() \
     << " " << this->fnake->body->front().getY() << std::endl;
}

/* Check that snake is not dead */

bool    Game::blockClear()
{
    int     x = this->fnake->body->front().getX();
    int     y = this->fnake->body->front().getY();

    if (x == 0 || y == 0 || x == this->_width || y == this->_height)
        return (false);
    if (fnakeHit(*this->fnake, this->fnake->body->front(), 1))
        return (false);
    
    return (true);
}

/* End game */

void    Game::end()
{
    delete this->fnake;
    delete this->food;
    std::cout << "Game over! Score: " << this->score << std::endl;
    exit(0);
}

int     Game::getWidth()
{
    return (this->_width);
}

int     Game::getHeight()
{
    return (this->_height);
}