#include "lib.hpp"

Lib::Lib()
{
    _number = 2;
    std::cout << "Library created." << std::endl;
}

Lib::Lib(Lib const &copy)
{
    *this = copy;
}

Lib const &Lib::operator=(Lib const &copy)
{
    this->_number = copy._number;
    return (*this);
}

Lib::~Lib()
{
    //glutDestroyWindow(win);
    std::cout << "deleting library..." << std::endl;
}

int Lib::getNumber()
{
    return (this->_number);
}

int Lib::getKey()
{
    return (keyPressed);
}

bool Lib::createWindow(int height, int width)
{
    try
    { //might need to change all to `this->...`
        //myInit();
        char *myargv[1];
        int myargc = 1;
        myargv[0] = strdup("./lib1");

        mapWidth = width;
        mapHeight = height;

        glutInit(&myargc, myargv);                      // Initialize GLUT
        glutInitDisplayMode(GLUT_DOUBLE);               // Enable double buffered mode
        glutInitWindowSize(windowWidth, windowHeight);  // Initial window width and height
        glutInitWindowPosition(windowPosX, windowPosY); // Initial window top-left corner (x, y)
        glutCreateWindow("Snake");                      // Create window with given title
        glutDisplayFunc(display);                       // Register callback handler for window re-paint
        glutReshapeFunc(reshape);                       // Register callback handler for window re-shape
                                                        // glutTimerFunc(0, Timer, 0);                     // First timer call immediately
        glutSpecialFunc(specialKeys);                   // Register callback handler for special-key event
        glutKeyboardFunc(keyboard);                     // Register callback handler for special-key event
        //glutFullScreen();                               // Put into full screen
        glutTimerFunc(refreshMillis, Timer, 0);
        initGL();                                       // Our own OpenGL initialization
    }
    catch (...)
    {
        return (false);
    }
    return (true);
}

void Lib::Timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMillis, Timer, 0);
}

void Lib::refresh() //may be unescary
{
    glutCheckLoop();
    display();
}

void Lib::draw(int x, int y, char ch) //again might not be needed
{
    s_objectsToDraw     tempObject;
    tempObject.x = x;
    tempObject.y = y;
    tempObject.c = ch;
    objectsToDraw.push_back(tempObject);
}

void Lib::clearWindow() //might not be needed
{
    objectsToDraw.clear();
}

void destroy_window() { 
 window_valid = -1;
}

void Lib::display()
{
     
    if(window_valid == -1)
        return;
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);   // To operate on the model-view matrix
    glLoadIdentity();             // Reset model-view matrix

    drawBorders();

    for (int i = 0; i < objectsToDraw.size(); i++)//draws whole body!!!! need one for obsticles
    {
        float     v0x, v1x, v2x, v3x;
        float     v0y, v1y, v2y, v3y;

        v0x = -(1 - (1 / (((float)mapWidth + 1) / 2) * (float)(objectsToDraw.at(i).x + 0)));//this needs a turnary operator to determine negative or plus.. maybe simplified
        v0y = 1 - (1 / (((float)mapHeight + 1) / 2) * (float)(objectsToDraw.at(i).y + 1));

        v1x = -(1 - (1 / (((float)mapWidth + 1) / 2) * (float)(objectsToDraw.at(i).x + 1)));
        v1y = v0y;//1 - (1 / ((float)mapHeight / 2) * (float)(objectsToDraw.at(i).y + 1));

        v2x = v1x;//1 - (1 / ((float)mapWidth / 2) * (float)(objectsToDraw.at(i).x));
        v2y = 1 - (1 / (((float)mapHeight + 1) / 2) * (float)(objectsToDraw.at(i).y + 0));

        v3x = v0x;//1 - (1 / ((float)mapWidth / 2) * (float)(objectsToDraw.at(i).x));
        v3y = v2y;//1 - (1 / ((float)mapHeight / 2) * (float)(objectsToDraw.at(i).y));

        if (objectsToDraw.at(i).c == 'b')
        {
            glBegin(GL_QUADS);
	            glColor3f(0.99f, 0.99f, 0.99f);
	            glVertex2f(v0x, v0y);
	            glVertex2f(v1x, v1y);
    	        glVertex2f(v2x, v2y);
                glVertex2f(v3x, v3y);
	        glEnd();
        }
        if (objectsToDraw.at(i).c == 'o')
        {
            glBegin(GL_QUADS);
	            glColor3f(0.77f, 0.77f, 0.77f);
	            glVertex2f(v0x, v0y);
	            glVertex2f(v1x, v1y);
    	        glVertex2f(v2x, v2y);
                glVertex2f(v3x, v3y);
	        glEnd();    
        }
        if (objectsToDraw.at(i).c == '*')
        {
            glBegin(GL_QUADS);
	            glColor3f(0.55f, 0.55f, 0.55f);
	            glVertex2f(v0x, v0y);
	            glVertex2f(v1x, v1y);
    	        glVertex2f(v2x, v2y);
                glVertex2f(v3x, v3y);
	        glEnd();
        }
    }
    glutSwapBuffers();
}

void Lib::drawBorders()//TIDY!!!!!!!
{
    float     v0x, v1x, v2x, v3x;
    float     v0y, v1y, v2y, v3y;

    v0x = -1.0;
    v0y = 1 - (1 / (((float)mapHeight + 2) / 2));

    v1x = 1.0;
    v1y = 1 - (1 / (((float)mapHeight + 2) / 2));

    v2x = 1.0;
    v2y = 1.0;

    v3x = -1.0;
    v3y = 1.0;

    //int i = rand() % 21;
    //std::cout << i << "  sdgdfgdgfdhthfdhdsgfghstfhbsgretjhweheha" << std::endl;
    //float arr1[40] = { 0.0001, 0.05, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, 0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 0.99, 0.99 };

    
    //std::cout << arr1[2] << std::endl;
    

    glBegin(GL_QUADS);
	    glColor3f(0.8f, 0.8f, 0.8f);
	    glVertex2f(v0x, v0y);
	    glVertex2f(v1x, v1y);
	    glVertex2f(v2x, v2y);
	    glVertex2f(v3x, v3y);
	glEnd();

    v0x = 1 - (1 / (((float)mapWidth + 2) / 2));
    v0y = -1.0;

    v1x = 1.0;
    v1y = -1.0;

    v2x = 1.0;
    v2y = 1.0;

    v3x = 1 - (1 / (((float)mapWidth + 2) / 2));
    v3y = 1.0;

    glBegin(GL_QUADS);
	    glColor3f(0.5f, 0.5f, 0.5f);
	    glVertex2f(v0x, v0y);
	    glVertex2f(v1x, v1y);
	    glVertex2f(v2x, v2y);
        glVertex2f(v3x, v3y);
	glEnd();

    v0x = -1.0;
    v0y = -1.0;

    v1x = 1.0;
    v1y = -1.0;

    v2x = 1.0;
    v2y = -(1 - (1 / (((float)mapHeight + 2) / 2)));

    v3x = -1.0;
    v3y = -(1 - (1 / (((float)mapHeight + 2) / 2)));


    glBegin(GL_QUADS);
	    glColor3f(0.5f, 0.5f, 0.5f);
	    glVertex2f(v0x, v0y);
	    glVertex2f(v1x, v1y);
	    glVertex2f(v2x, v2y);
        glVertex2f(v3x, v3y);
	glEnd();

    v0x = -1.0;
    v0y = -1.0;

    v1x = -(1 - (1 / (((float)mapWidth + 2) / 2)));
    v1y = -1.0;

    v2x = -(1 - (1 / (((float)mapWidth + 2) / 2)));
    v2y = 1.0;

    v3x = -1.0;
    v3y = 1.0;


    glBegin(GL_QUADS);
	    glColor3f(0.5f, 0.5f, 0.5f);
	    glVertex2f(v0x, v0y);
	    glVertex2f(v1x, v1y);
	    glVertex2f(v2x, v2y); 
        glVertex2f(v3x, v3y);
	glEnd();
}

void Lib::reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1; // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
    glLoadIdentity();            // Reset the projection matrix
    if (width >= height)
    {
        clipAreaXLeft = -1.0 * aspect;
        clipAreaXRight = 1.0 * aspect;
        clipAreaYBottom = -1.0;
        clipAreaYTop = 1.0;
    }
    else
    {
        clipAreaXLeft = -1.0;
        clipAreaXRight = 1.0;
        clipAreaYBottom = -1.0 / aspect;
        clipAreaYTop = 1.0 / aspect;
    }
    gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

void Lib::specialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_F1:
            fullScreenMode = !fullScreenMode; // Toggle state
            if (fullScreenMode)
            {                                        // Full-screen mode
                windowPosX = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
                windowPosY = glutGet(GLUT_WINDOW_Y);
                windowWidth = glutGet(GLUT_WINDOW_WIDTH);
                windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
                glutFullScreen(); // Switch into full screen
            }
            else
            {                                                 // Windowed mode
                glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
                glutPositionWindow(windowPosX, windowPosX);   // Position top-left corner
            }
            break;
        case GLUT_KEY_LEFT: // left key
            keyPressed = key;
            break;
        case GLUT_KEY_UP: // up key
            keyPressed = key;
            break;
        case GLUT_KEY_RIGHT: // right key
            keyPressed = key;
            break;
        case GLUT_KEY_DOWN: // down key
            keyPressed = key;
            break;
        case '1':
            keyPressed = key;
            break;
        case '2':
            keyPressed = key;
            break;
        case '3':
            keyPressed = key;
            break;
            
    }
    glutPostRedisplay();
}

void Lib::keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: // ESC key
            exit(0);
            break;
        case '1':
            destroy_window();
            std::cout << "You have selected a new library... now we just need to implement it someohow" << std::endl;
            keyPressed = key;
            break;
        case '2':
            destroy_window();
            std::cout << "You have selected a new library... now we just need to implement it someohow" << std::endl;
            keyPressed = key;
            break;
        case '3':
            destroy_window();
            std::cout << "You have selected a new library... now we just need to implement it someohow" << std::endl;
            keyPressed = key;
            break;
    }
}

void Lib::initGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

Lib *createLibrary()
{
    return (new Lib());
}

void deleteLibrary(Lib *library)
{
    delete library;
}