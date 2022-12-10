
//Libraires----------------------------------------------------------------------------------------------
#include "main_graphics.h"
//-------------------------------------------------------------------------------------------------------
//DEFINE INFORMATION-------------------------------------------------------------------------------------

//const GLint    INIT_WIN_X = 100,
//INIT_WIN_Y = 40;

const GLint squareSize = 25;
const int NUM_ROWS = 31, NUM_COLS = 28;

const GLfloat BACKGND_COLOR[3] = { 0.f, 0.f, 0.f };

GLint       scorePanelWidth_t = 200;

GLint       gridWidth_t = NUM_COLS * squareSize;

GLint       winWidth_t = gridWidth_t + scorePanelWidth_t,

winHeight_t = NUM_ROWS * squareSize;
//-------------------------------------------------------------------------------------------------------



//MAKE WINDOW---------------------------------------------------------------------------------------------
void Graphics::initializeWindow(int argc, char* argv[], const GLint INIT_WIN_X, const GLint INIT_WIN_Y) {
    
    
    //     Initialize glut and create a new window

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);



    glutInitWindowSize(winWidth_t, winHeight_t);

    glutInitWindowPosition(INIT_WIN_X, INIT_WIN_Y);

    glutCreateWindow("demo 2D OpenGL + glut");

    //     this will be the background color of my window

    glClearColor(BACKGND_COLOR[0], BACKGND_COLOR[1], BACKGND_COLOR[2], 1.f);

}
//-------------------------------------------------------------------------------------------------------




//RESIZE WINDOW-------------------------------------------------------------------------------------------
void Graphics::myResize(int w, int h) {
    
   
    //     This callback function is called when the window is resized

    //     (generally by the user of the application).

    //     It is also called when the window is created, why I placed there the

    //     code to set up the virtual camera for this application.
    
    
    
    //     This calls says that I want to use the entire dimension of the window for my drawing.

    glViewport(0, 0, w, h);

    winWidth_t = w;

    winHeight_t = h;



    //     Here I create my virtual camera.  We are going to do 2D drawing for a while, so what this

    //     does is define the dimensions (origin and units) of the "virtual world that my viewport

    //     maps to.

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();



    //     Here I am saying that the lower-left corner of my window is the point (0, 0) in my

    //     virtual world and that the virtual world has width and height 1.0

    gluOrtho2D(0.f, winWidth_t, 0.f, winHeight_t);



    //     When it's done, request a refresh of the display

    glutPostRedisplay();

    
   }
//-------------------------------------------------------------------------------------------------------

