#ifndef MAIN_GRAPHICS_H
#define MAIN_GRAPHICS_H
//Libraries----------------------------------------------------------------------------------------------
#include <iostream>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <OpenAL/OpenAL.h>  //comment out
#include <cstdlib>
#include "preDefined.h"
//-------------------------------------------------------------------------------------------------------
using namespace std;


//Graphics-----------------------------------------------------------------------------------------
class Graphics {
    
private:
   
    const int NUM_ROWS = 31, NUM_COLS = 28;

    
    
public:
 
    //makes the window for the game to be displayed
    void initializeWindow(int argc, char* argv[], const GLint INIT_WIN_X, const GLint INIT_WIN_Y);
    
    
    
    
    
    //generates display
    void myResize(int w, int h);
    
    
    
};
//-------------------------------------------------------------------------------------------------------
#endif // main_graphics_h
