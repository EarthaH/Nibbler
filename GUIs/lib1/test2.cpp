# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
# else
#  include <GL/gl.h>
#  include <GL/glut.h>
# endif
 
/*
 * GL09KeyControl.cpp: A key-controlled bouncing ball
 */
//#include <windows.h>  // for MS Windows
//#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <Math.h>     // Needed for sin, cos
#include <stdlib.h>
#define PI 3.14159265f
 
// Global variables
char title[] = "Snake Lib 1";  // Windowed mode's title
int windowWidth  = 640;     // Windowed mode's width
int windowHeight = 480;     // Windowed mode's height
int windowPosX   = 50;      // Windowed mode's top-left corner x
int windowPosY   = 50;      // Windowed mode's top-left corner y //change these depending on user input in earthas input
 
//int snakePosX   =25;
//int snakePosX   =25;

int refreshMillis = 30;
 
// Projection clipping area
GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;//????
 
bool fullScreenMode = true; 
 

void initGL() {
   glClearColor(0.54, 0.705, 0.105, 1.0);
}
 
//drawGrid(){};
void    drawSnake()
{
    glBegin(GL_QUADS); 
      glColor3f(0.58f, 0.58f, 0.58f); // Green
      glVertex2f(-0.7f, -0.1f);
      glVertex2f(-0.1f, -0.1f);
      glVertex2f(-0.1f,  0.0f);//need o do a calculaion w speed adn map size and ..soming elses
      glVertex2f(-0.7f,  0.0f);
 
   glEnd();

}
/* Callback handler for window re-paint event */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
   glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
   glLoadIdentity();              // Reset model-view matrix
 
 
   //glBegin(GL_TRIANGLE_FAN);
      
//   drawGrid();
   drawSnake();
  // drawFood();
   //drawObstructions();

   //glEnd();
 
   glutSwapBuffers(); 
 
}
 
/* Call back when the windows is re-sized 
void reshape(GLsizei width, GLsizei height) {
   // Compute aspect ratio of the new window
   if (height == 0) 
        height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
      clipAreaXLeft   = -1.0 * aspect;
      clipAreaXRight  = 1.0 * aspect;
      clipAreaYBottom = -1.0;
      clipAreaYTop    = 1.0;
   } else {
      clipAreaXLeft   = -1.0;
      clipAreaXRight  = 1.0;
      clipAreaYBottom = -1.0 / aspect;
      clipAreaYTop    = 1.0 / aspect;
   }
   gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
   ballXMin = clipAreaXLeft + ballRadius;
   ballXMax = clipAreaXRight - ballRadius;
   ballYMin = clipAreaYBottom + ballRadius;
   ballYMax = clipAreaYTop - ballRadius;
}*/
 
/* Called back when the timer expired */
void Timer(int value) {
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}
 
/* Callback handler for normal-key event */
void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
   }
}
 
/* Callback handler for special-key event 
void specialKeys(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
         fullScreenMode = !fullScreenMode;         // Toggle state
         if (fullScreenMode) {                     // Full-screen mode
            windowPosX   = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
            windowPosY   = glutGet(GLUT_WINDOW_Y);
            windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
            windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            glutFullScreen();                      // Switch into full screen
         } else {                                         // Windowed mode
            glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
            glutPositionWindow(windowPosX, windowPosX);   // Position top-left corner
         }
         break;
      case GLUT_KEY_RIGHT:    // Right: increase x speed
         xSpeed *= 1.05f; break;
      case GLUT_KEY_LEFT:     // Left: decrease x speed
         xSpeed *= 0.95f; break;
      case GLUT_KEY_UP:       // Up: increase y speed
         ySpeed *= 1.05f; break;
      case GLUT_KEY_DOWN:     // Down: decrease y speed
         ySpeed *= 0.95f; break;
      case GLUT_KEY_PAGE_UP:  // Page-Up: increase ball's radius
         ballRadius *= 1.05f;
         ballXMin = clipAreaXLeft + ballRadius;
         ballXMax = clipAreaXRight - ballRadius;
         ballYMin = clipAreaYBottom + ballRadius;
         ballYMax = clipAreaYTop - ballRadius;
         break;
      case GLUT_KEY_PAGE_DOWN: // Page-Down: decrease ball's radius
         ballRadius *= 0.95f;
         ballXMin = clipAreaXLeft + ballRadius;
         ballXMax = clipAreaXRight - ballRadius;
         ballYMin = clipAreaYBottom + ballRadius;
         ballYMax = clipAreaYTop - ballRadius;
         break;
   }
}*/
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(windowWidth, windowHeight);  // Initial window width and height
   glutInitWindowPosition(windowPosX, windowPosY); // Initial window top-left corner (x, y)
   glutCreateWindow(title);      // Create window with given title
   glutDisplayFunc(display);     // Register callback handler for window re-paint
   //glutReshapeFunc(reshape);     // Register callback handler for window re-shape
   glutTimerFunc(0, Timer, 0);   // First timer call immediately
  // glutSpecialFunc(specialKeys); // Register callback handler for special-key event
   glutKeyboardFunc(keyboard);   // Register callback handler for special-key event
   glutFullScreen();             // Put into full screen
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}