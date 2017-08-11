#include "../includes/game.hpp"

Game::Game() : _width(300), _height(300), score(0), speed(1000)
{
    init();
}

Game::Game(int w, int h) : _width(w), _height(h), score(0), speed(500)
{
    init();
}

Game::Game(Game const &copy)
{
    *this = copy;
}

Game const &Game::operator=(Game const &copy)
{
    this->_width = copy._width;
    this->_height = copy._height;
    return (*this);
}

Game::~Game()
{
    delete this->fnake;
    delete this->food;
    dlclose(this->dl_handle);
}

void Game::init()
{
    const char *libs[3] = {LIB1, LIB2, LIB3};
    this->_libs = libs;

    setLib(0);
    this->fnake = new Fnake(this->_width / 2, this->_height / 2);
    this->food = new Food(fnake, this->_width, this->_height);

    score = 0;
}

/* *** *** *** Main Loop *** *** *** */

void Game::start()
{
    int key;
    
    for (;;)
    {
        if ((key = this->_library->getKey()) != ERR)
            changeDir(key);
        if (gotFood(*fnake, *food))
        {
            fnake->eat();
            delete food;
            food = new Food(fnake, this->_width, this->_height);
            this->score += 10;
            this->speed -= this->speed > 100 ? 50 : 0;
        }
        if (!blockClear())
            end();
        move();
        draw();
        //std::this_thread::sleep_for(std::chrono::milliseconds(this->speed));
    }
}

/* Library handling */

void Game::setLib(int num)
{

    const char *libs[3] = {LIB1, LIB2, LIB3};
    this->_libs = libs;
    
    IEntity *(*lib_ptr)();

    if (this->dl_handle)
        deleteLibrary();
    //std::cout << num << " " << this->_libs[0]<< " " << 1 << " " << this->_libs[1] << " " << 2 << " " << this->_libs[2] <<std::endl;
    std::cout << num << " Library = " << this->_libs[num] << std::endl;
    std::cout << num << " Library = " << this->_libs[1] << std::endl;

    //std::cout << num << " Library = " << this->_libs[0] << std::endl;
    this->dl_handle = dlopen(this->_libs[num], RTLD_LAZY | RTLD_LOCAL);
    if (!this->dl_handle)
        dlerror_wrapper();
    lib_ptr = (IEntity * (*)()) dlsym(dl_handle, "createLibrary");
    if (!lib_ptr)
        dlerror_wrapper();
        
    this->_library = lib_ptr();
    if (!this->_library->createWindow(this->_height, this->_width))
        std::cout << "Window not created." << std::endl;
}

void Game::deleteLibrary() ///
{
  //  std::cout << "1" << std::endl;
    void    (*lib_del)(IEntity *);

   // std::cout << "2" << std::endl;
    lib_del = (void (*)(IEntity*)) dlsym(dl_handle, "deleteLibrary");

   // std::cout << "3" << std::endl;
    if (!lib_del)
        dlerror_wrapper();
    
   // std::cout << "4" << std::endl;
    lib_del(this->_library);

    //std::cout << "5" << std::endl;
    dlclose(dl_handle);

    //std::cout << "6" << std::endl;
}

void Game::dlerror_wrapper()
{
    std::cerr << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}
/* Draw game */

void Game::draw()
{
    _library->clearWindow();
    for (int i = 0; i < this->fnake->getSize(); i++)
        {
            _library->draw(fnake->body->at(i).getX(), fnake->body->at(i).getY(), fnake->body->at(i).getCh());
        }
    _library->draw(food->getX(), food->getY(), food->getCh());
        
    this->_library->refresh();
}

/* Check if snake hit food */

bool Game::gotFood(Fnake const &fnake, Food &food)
{
    if (fnake.body->front().getX() == food.getX() && fnake.body->front().getY() == food.getY())
        return (true);
    return (false);
}

/* Move snake in set direction */ //also which direction snakes will move in

void Game::move()
{
    int dir = this->fnake->getDirection();

    if (dir == RIGHT)
        this->fnake->moveRight();
    else if (dir == LEFT)
        this->fnake->moveLeft();
    else if (dir == UP)
        this->fnake->moveUp();
    else if (dir == DOWN)
        this->fnake->moveDown();
}

void Game::changeDir(int key)
{
    int dir = fnake->getDirection();

    if (key == 103 && dir != UP)
        fnake->setDirection(DOWN);
    else if (key == 101 && dir != DOWN)
        fnake->setDirection(UP);
    else if (key == 100 && dir != RIGHT)
        fnake->setDirection(LEFT);
    else if (key == 102 && dir != LEFT)
        fnake->setDirection(RIGHT);
    else if (key == '1' && this->_library->getNumber() != 1)
        setLib(0);
    else if (key == '2' && this->_library->getNumber() != 2)
        setLib(1);
    else if (key == '3' && this->_library->getNumber() != 3)
        setLib(2);
}

/* Check that snake is not dead */

bool Game::blockClear()
{
    int x = this->fnake->body->front().getX();
    int y = this->fnake->body->front().getY();

    if (x == 0 || y == 0 || x == this->_width || y == this->_height)
        return (false);
    if (fnakeHit(*this->fnake, this->fnake->body->front(), 1))
        return (false);

    return (true);
}

/* End game */

void Game::end()
{
    delete this->fnake;
    delete this->food;
    std::cout << "Game over! Score: " << this->score << std::endl;
    exit(0);
}

int Game::getWidth()
{
    return (this->_width);
}

int Game::getHeight()
{
    return (this->_height);
}