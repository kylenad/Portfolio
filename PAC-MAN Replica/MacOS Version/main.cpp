//  PAC MAN GAME FINAL PROJECT
//Libraries----------------------------------------------------------------------------------------------
#include <iostream>
//#include "windows.h" //################################# FOR SOUND ###############################
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <list>
#include "main_graphics.h"
#include "preDefined.h"
//#include "Astar.h"
#include <vector>
//-------------------------------------------------------------------------------------------------------
using namespace std;




class point {
private:
    

public:

    
    
    point( int a = 16, int b = 11 ) { x = a; y = b; }
    bool operator ==( const point& o ) { return o.x == x && o.y == y; }
    point operator +( const point& o ) { return point( o.x + x, o.y + y ); }
    int x, y;
};

class map {
public:
    //define map
    map() {
        const int NUM_ROWS2 = 31, NUM_COLS2 = 28;
        char t[NUM_ROWS2][NUM_COLS2] = {
            
            
            {'1','H','H','H','H','H','H','H','H','H','H','H','H','3','1','H','H','H','H','H','H','H','H','H','H','H','H','3'},  //   1
            
            {'V','h','a','a','a','a','c','a','a','a','a','a','j','V','V','h','a','a','a','a','a','c','a','a','a','a','g','V'},  //  2
            
            {'V','b','1','H','H','3','b','1','H','H','H','3','b','V','V','b','1','H','H','H','3','b','1','H','H','3','b','V'},  //       3
            
            {'V','b','V','I','I','V','b','V','I','I','I','V','b','V','V','b','V','I','I','I','V','b','V','I','I','V','b','V'},  //      4
            
            {'V','b','2','H','H','4','b','2','H','H','H','4','b','2','4','b','2','H','H','H','4','b','2','H','H','4','b','V'},  //       5
            
            {'V','e','a','a','a','a','l','a','a','c','a','a','d','a','a','d','a','a','c','a','a','l','a','a','a','a','f','V'},  //    6
            
            {'V','b','1','H','H','3','b','1','3','b','1','H','H','H','H','H','H','3','b','1','3','b','1','H','H','3','b','V'},  //        7
            
            {'V','b','2','H','H','4','b','V','V','b','2','H','H','3','1','H','H','4','b','V','V','b','2','H','H','4','b','V'},  //       8
            
            {'V','k','a','a','a','a','f','V','V','k','a','a','g','V','V','h','a','a','i','V','V','n','a','a','a','a','i','V'},  //  9
            
            {'2','H','H','H','H','3','b','V','2','H','H','3','b','V','V','b','1','H','H','4','V','b','1','H','H','H','H','4'},  //      10
            
            {'I','I','I','I','I','V','b','V','1','H','H','4','b','2','4','b','2','H','H','3','V','b','V','I','I','I','I','I'},  //      11
            
            {'I','I','I','I','I','V','b','V','V','h','a','a','d','a','a','d','a','a','j','V','V','b','V','I','I','I','I','I'},  // 12
            
            {'I','I','I','I','I','V','b','V','V','b','1','H','H','S','S','H','H','3','b','V','V','b','V','I','I','I','I','I'},  //      13 - S - k - i - S
            
            {'H','H','H','H','H','4','b','2','4','b','V','C','C','C','C','C','C','V','b','2','4','b','2','H','H','H','H','H'},  //       14
            
            {'<','a','a','a','a','a','l','a','a','m','V','C','C','C','C','C','C','V','n','a','a','l','a','a','a','a','a','>'},  // 15
            
            {'H','H','H','H','H','3','b','1','3','b','V','C','C','C','C','C','C','V','b','1','3','b','1','H','H','H','H','H'},  //       16
            
            {'I','I','I','I','I','V','b','V','V','b','2','H','H','H','H','H','H','4','b','V','V','b','V','I','I','I','I','I'},  //   17
            
            {'I','I','I','I','I','V','b','V','V','n','a','a','a','a','a','a','a','a','m','V','V','b','V','I','I','I','I','I'},  //        18
            
            {'I','I','I','I','I','V','b','V','V','b','1','H','H','H','H','H','H','3','b','V','V','b','V','I','I','I','I','I'},  //   19
            
            {'1','H','H','H','H','4','b','2','4','b','2','H','H','3','1','H','H','4','b','2','4','b','2','H','H','H','H','3'},  //       20
            
            {'V','h','a','a','a','a','l','a','a','d','a','a','j','V','V','h','a','a','d','a','a','l','a','a','a','a','j','V'},  //    21
            
            {'V','b','1','H','H','3','b','1','H','H','H','3','b','V','V','b','1','H','H','H','3','b','1','H','H','3','b','V'},  //       22
            
            {'V','b','2','H','3','V','b','2','H','H','H','4','b','2','4','b','2','H','H','H','4','b','V','1','H','4','b','V'},  //       23
            
            {'V','k','a','g','V','V','e','a','a','c','a','a','d','a','a','d','a','a','c','a','a','f','V','V','h','a','i','V'},  // 24 bottom dot
            
            {'2','H','3','b','V','V','b','1','3','b','1','H','H','H','H','H','H','3','b','1','3','b','V','V','b','1','H','4'},  // 25
            
            {'1','H','4','b','2','4','b','V','V','b','2','H','H','3','1','H','H','4','b','V','V','b','2','4','b','2','H','3'},  //  26
            
            {'V','h','a','d','a','a','i','V','V','k','a','a','g','V','V','h','a','a','i','V','V','k','a','a','d','a','g','V'},  // 27
            
            {'V','b','1','H','H','H','H','4','2','H','H','3','b','V','V','b','1','H','H','4','2','H','H','H','H','3','b','V'},  //      28
            
            {'V','b','2','H','H','H','H','H','H','H','H','4','b','2','4','b','2','H','H','H','H','H','H','H','H','4','b','V'},  //     29
            
            {'V','k','a','a','a','a','a','a','a','a','a','a','d','a','a','d','a','a','a','a','a','a','a','a','a','a','i','V'},  // 30
            
            {'2','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','4'},  //  31
            
            
            
            
            
            /*{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}*/
        };
        //define width and height of map
        w = 28;
        h = 31;
        for( int r = 0; r < h; r++ )
            for( int s = 0; s < w; s++ )
            m[s][r] = t[r][s];
    }
    int operator() ( int x, int y ) { return m[x][y]; }
    char m[28][31];
    int w, h;
};

class node {
public:
    bool operator == (const node& o ) { return pos == o.pos; }
    bool operator == (const point& o ) { return pos == o; }
    bool operator < (const node& o ) { return dist + cost < o.dist + o.cost; }
    point pos, parent;
    int dist, cost;
};

class aStar {
public:
    aStar() {
        //define neightbors
        //neighbours[0] = point( -1, -1 ); neighbours[1] = point(  1, -1 );
    //    neighbours[2] = point( -1,  1 ); neighbours[3] = point(  1,  1 );
        neighbours[0] = point(  0, -1 ); neighbours[1] = point( -1,  0 );
        neighbours[2] = point(  0,  1 ); neighbours[3] = point(  1,  0 );
    }
    
    int calcDist( point& p ){
        // need a better heuristic
        int x = end.x - p.x, y = end.y - p.y;
        return( x * x + y * y );
    }
    
    bool isValid( point& p ) {
        return ( p.x >-1 && p.y > -1 && p.x < m.w && p.y < m.h );
    }
    
    bool existPoint( point& p, int cost ) {
        std::list<node>::iterator i;
        i = std::find( closed.begin(), closed.end(), p );
        if( i != closed.end() ) {
            if( ( *i ).cost + ( *i ).dist < cost ) return true;
            else { closed.erase( i ); return false; }
        }
        i = std::find( open.begin(), open.end(), p );
        if( i != open.end() ) {
            if( ( *i ).cost + ( *i ).dist < cost ) return true;
            else { open.erase( i ); return false; }
        }
        return false;
    }
    
    bool fillOpen( node& n ) {
        int stepCost, nc, dist;
        point neighbour;
        
        for( int x = 0; x < 4; x++ ) {
            // one can make diagonals have different cost
            stepCost = x < 4 ? 1 : 1;
            neighbour = n.pos + neighbours[x];
            if( neighbour == end ) return true;
            //define where the walls are and say it can go there
            if( isValid( neighbour ) && m( neighbour.x, neighbour.y ) != 'C' && m(neighbour.x, neighbour.y ) != 'H' && m(neighbour.x, neighbour.y ) != 'V' && m(neighbour.x, neighbour.y ) != '1' && m(neighbour.x, neighbour.y ) != '2' && m(neighbour.x, neighbour.y ) != '3' && m(neighbour.x, neighbour.y ) != '4') {
                
                nc = stepCost + n.cost;
                dist = calcDist( neighbour );
                if( !existPoint( neighbour, nc + dist ) ) {
                    node m;
                    m.cost = nc; m.dist = dist;
                    m.pos = neighbour;
                    m.parent = n.pos;
                    open.push_back( m );
                }
            }
        }
        return false;
    }
    
    
    
    
    
  
    
    
    
    
    
    
    
    
    bool search( point& s, point& e, map& mp ) {
        node n; end = e; start = s; m = mp;
        n.cost = 0; n.pos = s; n.parent = 0; n.dist = calcDist( s );
        open.push_back( n );
        while( !open.empty() ) {
            //open.sort();
            node n = open.front();
            open.pop_front();
            closed.push_back( n );
            if( fillOpen( n ) ) return true;
        }
        return false;
    }
    
    int path( std::list<point>& path ) {
        path.push_front( end );
        int cost = 1 + closed.back().cost;
        path.push_front( closed.back().pos );
        point parent = closed.back().parent;
        
        for( std::list<node>::reverse_iterator i = closed.rbegin(); i != closed.rend(); i++ ) {
            
            if( ( *i ).pos == parent && !( ( *i ).pos == start ) ) {
                path.push_front( ( *i ).pos );
                parent = ( *i ).parent;
            }
        }
        path.push_front( start );
        return cost;
    }
    
    map m; point end, start;
    point neighbours[4];
    std::list<node> open;
    std::list<node> closed;
};




















void updateAstarGhost(int ghostIndex, std::list<point> path, int c );
//void updateAstarGhost2(int ghostIndex, std::list<point> path, int c);
//void myTimerfunc2(int val);


//--------------------------------------

//  Interface constants (SEE PREDEFINED.H FOR MORE)

//--------------------------------------

const GLint    INIT_WIN_X = 100,

INIT_WIN_Y = 40;

 
//--------------------------------------

//  File-level global variables

//--------------------------------------

//GRID DEFINTION

const int NUM_ROWS = 31, NUM_COLS = 28;
char GRID[NUM_ROWS][NUM_COLS] =

{       //                                                                                                                                                                                                                                Row:

        {'1','H','H','H','H','H','H','H','H','H','H','H','H','3','1','H','H','H','H','H','H','H','H','H','H','H','H','3'},  //   1

        {'V','h','a','a','a','a','c','a','a','a','a','a','j','V','V','h','a','a','a','a','a','c','a','a','a','a','g','V'},  //  2

        {'V','b','1','H','H','3','b','1','H','H','H','3','b','V','V','b','1','H','H','H','3','b','1','H','H','3','b','V'},  //       3

        {'V','b','V','I','I','V','b','V','I','I','I','V','b','V','V','b','V','I','I','I','V','b','V','I','I','V','b','V'},  //      4

        {'V','b','2','H','H','4','b','2','H','H','H','4','b','2','4','b','2','H','H','H','4','b','2','H','H','4','b','V'},  //       5

        {'V','e','a','a','a','a','l','a','a','c','a','a','d','a','a','d','a','a','c','a','a','l','a','a','a','a','f','V'},  //    6

        {'V','b','1','H','H','3','b','1','3','b','1','H','H','H','H','H','H','3','b','1','3','b','1','H','H','3','b','V'},  //        7

        {'V','b','2','H','H','4','b','V','V','b','2','H','H','3','1','H','H','4','b','V','V','b','2','H','H','4','b','V'},  //       8

        {'V','k','a','a','a','a','f','V','V','k','a','a','g','V','V','h','a','a','i','V','V','n','a','a','a','a','i','V'},  //  9

        {'2','H','H','H','H','3','b','V','2','H','H','3','b','V','V','b','1','H','H','4','V','b','1','H','H','H','H','4'},  //      10

        {'I','I','I','I','I','V','b','V','1','H','H','4','b','2','4','b','2','H','H','3','V','b','V','I','I','I','I','I'},  //      11

        {'I','I','I','I','I','V','b','V','V','h','a','a','d','a','a','d','a','a','j','V','V','b','V','I','I','I','I','I'},  // 12

        {'I','I','I','I','I','V','b','V','V','b','1','H','H','S','S','H','H','3','b','V','V','b','V','I','I','I','I','I'},  //      13 - S - k - i - S

        {'H','H','H','H','H','4','b','2','4','b','V','C','C','C','C','C','C','V','b','2','4','b','2','H','H','H','H','H'},  //       14

        {'<','a','a','a','a','a','l','a','a','m','V','C','C','C','C','C','C','V','n','a','a','l','a','a','a','a','a','>'},  // 15

        {'H','H','H','H','H','3','b','1','3','b','V','C','C','C','C','C','C','V','b','1','3','b','1','H','H','H','H','H'},  //       16

        {'I','I','I','I','I','V','b','V','V','b','2','H','H','H','H','H','H','4','b','V','V','b','V','I','I','I','I','I'},  //   17

        {'I','I','I','I','I','V','b','V','V','n','a','a','a','a','a','a','a','a','m','V','V','b','V','I','I','I','I','I'},  //        18

        {'I','I','I','I','I','V','b','V','V','b','1','H','H','H','H','H','H','3','b','V','V','b','V','I','I','I','I','I'},  //   19

        {'1','H','H','H','H','4','b','2','4','b','2','H','H','3','1','H','H','4','b','2','4','b','2','H','H','H','H','3'},  //       20

        {'V','h','a','a','a','a','l','a','a','d','a','a','j','V','V','h','a','a','d','a','a','l','a','a','a','a','j','V'},  //    21

        {'V','b','1','H','H','3','b','1','H','H','H','3','b','V','V','b','1','H','H','H','3','b','1','H','H','3','b','V'},  //       22

        {'V','b','2','H','3','V','b','2','H','H','H','4','b','2','4','b','2','H','H','H','4','b','V','1','H','4','b','V'},  //       23

        {'V','k','a','g','V','V','e','a','a','c','a','a','d','a','a','d','a','a','c','a','a','f','V','V','h','a','i','V'},  // 24 bottom dot

        {'2','H','3','b','V','V','b','1','3','b','1','H','H','H','H','H','H','3','b','1','3','b','V','V','b','1','H','4'},  // 25

        {'1','H','4','b','2','4','b','V','V','b','2','H','H','3','1','H','H','4','b','V','V','b','2','4','b','2','H','3'},  //  26

        {'V','h','a','d','a','a','i','V','V','k','a','a','g','V','V','h','a','a','i','V','V','k','a','a','d','a','g','V'},  // 27

        {'V','b','1','H','H','H','H','4','2','H','H','3','b','V','V','b','1','H','H','4','2','H','H','H','H','3','b','V'},  //      28

        {'V','b','2','H','H','H','H','H','H','H','H','4','b','2','4','b','2','H','H','H','H','H','H','H','H','4','b','V'},  //     29

        {'V','k','a','a','a','a','a','a','a','a','a','a','d','a','a','d','a','a','a','a','a','a','a','a','a','a','i','V'},  // 30

        {'2','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','H','4'},  //  31

};


//     define wall types

//     plain wall                               W

//     horizontal                              H

//     vertical                           V

//     upper-left corner          1

//     lower-left corner          2

//     upper-right corner                3

//     lower-right corner        4

 

//  Define map square types:

//     left, right                 a

//  up, down                    b

//     left, right, down           c

//  left, right, up             d

//  up, down, right             e

//  up, down, left              f

//  left, down                  g

//  right, down                 h

//  left, up                    i

//  left, down                  j

//  right, up                   k

//  up, down, left, right       l

//  up, down, left              m

//  up, down, right             n

//     left only                                 o

//     right only p                           p

//     wall                         W

//  left bridge                 <

//  right bridge                              >

//  shield: up only                         S

//  ghost cage: up only                 C

//  inside wall                                I

 

 

//  left move allowed:          'a', 'c', 'd', 'f', 'g', 'i', 'j', 'l', 'm'

//  right move allowed:                'a', 'c', 'd', 'e', 'h', 'k', 'l', 'n'

//  up move allowed:           'b', 'd', 'e', 'f', 'i', 'k', 'l', 'm', 'n'

//  down move allowed:              'b', 'c', 'e', 'f', 'g', 'h', 'j', 'l', 'm', 'n'

 

 

//   for every coin {row, col, 1}   1--> coin still there (not picked up)

vector<Coin> coinList;
const GLint squareSize = 25;


const GLfloat BACKGND_COLOR[3] = { 0.f, 0.f, 0.f };



const GLint heartBeat = 10;

 
GLint       scorePanelWidth = 200;

GLint       gridWidth = NUM_COLS * squareSize;

GLint       winWidth = gridWidth + scorePanelWidth,

winHeight = NUM_ROWS * squareSize;

 

 

const GLfloat PACMAN_SCALE = 0.75f * squareSize;

const GLfloat COIN_SCALE = 0.1f * squareSize;

const GLfloat LARGE_COIN_SCALE = 0.32f * squareSize;

const GLfloat pacmanCrossScreenTime = 5000;// pacman goes across the screen in that many ms

const GLfloat PACMAN_SPEED = gridWidth * heartBeat / pacmanCrossScreenTime;

const int PACMAN_MAX_OPENING = 5;

const unsigned long POWERED_UP_DURATION = 10;

const float COLLISION_DIST_SQ = PACMAN_SCALE * PACMAN_SCALE;

 

const float GHOST_SCALE_X = 0.8f * PACMAN_SCALE, GHOST_SCALE_Y = 1.4f * PACMAN_SCALE;

const GLfloat GHOST_COLOR[][3] = { {255.f, 0.f, 0.f},

                                                                      {1.f, 0.7f, 1.f},  //  {255.f, 184.f, 255.f},

                                                                      {0.f, 255.f, 255.f},

                                                                      {1.f, 0.7f, 0.2f}  //  {255.f, 184.f, 82.f}

};

GLfloat GHOST_SPEED = PACMAN_SPEED;

 

 

GLfloat pacmanX = 14.f * squareSize, pacmanY = 17.5f * squareSize;  //  spawn point


GLfloat ghost[][2] = { {11.5f * squareSize, 14.5f * squareSize },

                                               {13.f * squareSize, 14.5f * squareSize },

                                               {14.5f * squareSize, 14.5f * squareSize },

                                               {16.f * squareSize, 14.5f * squareSize } };  //  spawn point  //////////////////////////////////////////////////////////////////////////


const GLfloat ghostStart[][2] = { {11.5f * squareSize, 11.5f * squareSize },

                                               {13.f * squareSize, 11.5f * squareSize },

                                               {14.5f * squareSize, 11.5f * squareSize },

                                               {16.f * squareSize, 11.5f * squareSize } };  //  spawn point  //////////////////////////////////////////////////////////////////////////

MoveDir ghostDir[] = { NO_DIR , NO_DIR, NO_DIR, NO_DIR };

const MoveDir ghostStartDir[] = { LEFT_DIR , LEFT_DIR, RIGHT_DIR};

// row and col of the square where a ghost last made a  direction change/keep decision

GLint ghostDecisionLoc[][2] = { {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1} };

bool ghostAlive[] = { true, true, true, true };

int numGhosts = 4;

bool ghostsStarted = false;

const int GHOST_START_TIME = 3;

 

int pacmanOpening = 1;

bool mouthOpening = true;

 

int score = 0;

bool gameRunning;

bool pacmanPoweredUp = false;

//     will have effect on ghost update

int poweredUpStartTime;

int startTime;

int frameCount = 0;

 

GLint gateRow = 12, gateCol = 13;

 

const GLfloat WALL_COLOR[3] = { 0.f, 0.f, 1.f };

const GLfloat COIN_COLOR[3] = { 1.f, 1.f, 1.f };

const GLfloat PILL_COLOR[3] = { 1.f, 1.f, 1.f };

const GLfloat PACMAN_COLOR[3] = { 1.f, 1.f, 0.f };

//const GLfloat BACKGND_COLOR[3] = { 0.f, 0.f, 0.f };

const GLfloat EMPTY_COLOR[3] = { 0.f, 0.f, 0.f };

 

MoveDir currentDir = NO_DIR, lastDir = NO_DIR;


 

//     This is the function that does the actual scene drawing

//     Typically, you should almost never have to call this function directly yourself.

//     It will be called automatically by glut, the way in Java the JRE invokes the paint

//     method of a frame.  Simply, because there is no inheritance/overriding mechanism, we

//     need to set up this function as a "callback function."  In this demo I do it in the

//     main function.  A plus side of this way of doing is that the function can be named any way

//     we want, and that in fact we can have different display functions and change during

//     the execution of the program the current display function used by glut.

//

void myDisplayFunc(void)

{

        //     This clears the buffer(s) we draw into.  We will see later this

        //     semester what this really means

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 

        //     There are two "matrix modes" in OpenGL: "projection", which sets up the

        //     camera, and "model view" which we have to be in to do any drawing

        glMatrixMode(GL_MODELVIEW);

 

        //     This says that we start from the lower-left corner of the screen

        glLoadIdentity();

 

        // move to top-left of the window

        glTranslatef(0, winHeight, 0);

        // filp the Y axis so that it points down

        glScalef(1.f, -1.f, 1.f);

 

        //     "save the state" (current coordinate system)

        glPushMatrix();

 

        // draw a wall-colored frame all around the window

        glColor3fv(WALL_COLOR);

        //top

        glBegin(GL_POLYGON);

        glVertex2f(0, 0);

        glVertex2f(gridWidth, 0);

        glVertex2f(gridWidth, squareSize / 2);

        glVertex2f(0, squareSize / 2);

        glEnd();

 

        //left

        glBegin(GL_POLYGON);

        glVertex2f(0, 0);

        glVertex2f(0, winHeight);

        glVertex2f(squareSize / 2, winHeight);

        glVertex2f(squareSize / 2, 0);

        glEnd();

 

        //right

        glBegin(GL_POLYGON);

        glVertex2f(gridWidth - squareSize / 2, 0);

        glVertex2f(gridWidth - squareSize / 2, winHeight);

        glVertex2f(gridWidth, winHeight);

        glVertex2f(gridWidth, 0);

        glEnd();

 

        //bottom

        glBegin(GL_POLYGON);

        glVertex2f(0, winHeight);

        glVertex2f(gridWidth, winHeight);

        glVertex2f(gridWidth, winHeight - squareSize / 2);

        glVertex2f(0, winHeight - squareSize / 2);

        glEnd();

 

        //     Draw 4the grid

        for (int i = 0; i < NUM_ROWS; i++)

        {

                //     translate to the top of the window

                for (int j = 0; j < NUM_COLS; j++)

                {

                       switch (GRID[i][j])

                       {

                       case 'W':

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(0, 0);

                               glVertex2f(squareSize, 0);

                               glVertex2f(squareSize, squareSize);

                               glVertex2f(0, squareSize);

                               glEnd();

                               break;

 

                       case 'I':

                               glColor3fv(EMPTY_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(0, 0);

                               glVertex2f(squareSize, 0);

                               glVertex2f(squareSize, squareSize);

                               glVertex2f(0, squareSize);

                               glEnd();

                               break;

 

                       case 'V':

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glPushMatrix();

                               glTranslatef(squareSize / 3, 0, 0);

                               glBegin(GL_POLYGON);

                               glVertex2f(0, 0);

                               glVertex2f(squareSize / 3, 0);

                               glVertex2f(squareSize / 3, squareSize);

                               glVertex2f(0, squareSize);

                               glEnd();

                               glPopMatrix();

                               break;

 

                       case 'H':

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glPushMatrix();

                               glTranslatef(0, squareSize / 3, 0);

                               glBegin(GL_POLYGON);

                               glVertex2f(0, 0);

                               glVertex2f(0, squareSize / 3);

                               glVertex2f(squareSize, squareSize / 3);

                               glVertex2f(squareSize, 0);

                               glEnd();

                               glPopMatrix();

                               break;

                               // Upper left

                       case '1':

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(squareSize / 3, squareSize / 3);

                               glVertex2f(squareSize / 3, 2 * squareSize / 3);

                               glVertex2f(squareSize, 2 * squareSize / 3);

                               glVertex2f(squareSize, squareSize / 3);

                               glEnd();

                               glBegin(GL_POLYGON);

                               glVertex2f(squareSize / 3, 2 * squareSize / 3);

                               glVertex2f(squareSize / 3, squareSize);

                               glVertex2f(2 * squareSize / 3, squareSize);

                               glVertex2f(2 * squareSize / 3, 2 * squareSize / 3);

                               glEnd();

                               break;

                               // lower left

                       case '2':

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(squareSize / 3, squareSize / 3);

                               glVertex2f(squareSize / 3, 2 * squareSize / 3);

                               glVertex2f(squareSize, 2 * squareSize / 3);

                               glVertex2f(squareSize, squareSize / 3);

                               glEnd();

                               glBegin(GL_POLYGON);

                               glVertex2f(squareSize / 3, squareSize / 3);

                               glVertex2f(2 * squareSize / 3, squareSize / 3);

                               glVertex2f(2 * squareSize / 3, 0);

                               glVertex2f(squareSize / 3, 0);

                               glEnd();

                               break;

                       case '3':

                               //     .  .  .  .

                               //     1  1  1  .

                               //     1  1  1  .

                               //     .  .  .  .

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(0, squareSize / 3);

                               glVertex2f(0, 2 * squareSize / 3);

                               glVertex2f(2 * squareSize / 3, 2 * squareSize / 3);

                               glVertex2f(2 * squareSize / 3, squareSize / 3);

                               glEnd();

                               glBegin(GL_POLYGON);

                               glVertex2f(squareSize / 3, 2 * squareSize / 3);

                               glVertex2f(squareSize / 3, squareSize);

                               glVertex2f(2 * squareSize / 3, squareSize);

                               glVertex2f(2 * squareSize / 3, 2 * squareSize / 3);

                               glEnd();

                               break;

 

                       case '4':

                               glColor3fv(WALL_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(2 * squareSize / 3, 2 * squareSize / 3);

                               glVertex2f(2 * squareSize / 3, squareSize / 3);

                               glVertex2f(0, squareSize / 3);

                               glVertex2f(0, 2 * squareSize / 3);

                               glEnd();

                               glBegin(GL_POLYGON);

                               glVertex2f(squareSize / 3, squareSize / 3);

                               glVertex2f(2 * squareSize / 3, squareSize / 3);

                               glVertex2f(2 * squareSize / 3, 0);

                               glVertex2f(squareSize / 3, 0);

                               glEnd();

                               // lower right

 

 

                               break;

                       default:

                               glColor3fv(EMPTY_COLOR);  //  box rgb

                               glBegin(GL_POLYGON);

                               glVertex2f(0, 0);

                               glVertex2f(squareSize, 0);

                               glVertex2f(squareSize, squareSize);

                               glVertex2f(0, squareSize);

                               glEnd();

 

                               break;

                       }

                       //draw grid

                                          //     set contour color

                                         //      glColor3f(1.f, 1.f, 1.f);

                                         //      glBegin(GL_LINE_LOOP);

                                         //      glVertex2f(0, 0);

                                            //   glVertex2f(squareSize, 0);
                                            //   glVertex2f(squareSize, squareSize);

                                            //   glVertex2f(0, squareSize);

                                           //    glEnd();

                       

                       //     move to the next square

                       glTranslatef(squareSize, 0, 0);

                }

                // move to begiinning of the next row

                glTranslatef(-gridWidth, +squareSize, 0);

        }

 

        //restore the origin of the coordinated sytem

        glPopMatrix();

 

        // draw all the coins

        //     loop.  For every coin.  If not not picked call drawCoin function

        for (unsigned long i = 0; i < coinList.size(); i++)

        {

                if (coinList[i].isPresent)

                       drawCoin(coinList[i].row, coinList[i].col);

        }

        //    for (unsigned long i = 0; i < pillList.size(); i++)

             //   {

            //           if (pillList[i].isPresent)

             //                  drawPill(pillList[i].row, pillList[i].col);

            //    }

        

        if (gameRunning)

                drawPacman();

 

        drawGhosts();

 

        //NEW

        //     Write some text
    //TEST OUTPUTS HERE
    //pacman x and y coordinate test outputs
    int px = pacmanX/squareSize;
    int py = pacmanY/squareSize;
    //ghost coordinates test output
    
    
        string outStr = "Score: " + to_string(score) + " " + to_string(py);
    
 
        //     Note: TEXT_HORIZ_PADDING and TEXT_VERT_PADDING affect actual

        //                    drawing location (mostly useful when drawing background box)

        //                                               x  y               draw colored background

        displayTextualInfo(outStr, gridWidth, 0, LARGE_FONT, true);

 

        // if the playerlost the game say "Game Over"

        if (!gameRunning)

        {

                displayTextualInfo("RIP bozo", gridWidth / 2 - 3 * squareSize, winHeight / 2 - 1.5f * squareSize, LARGE_FONT, true);

                for (int i = 0; i < 1; i++)

                {

                       //  bool played = PlaySound(TEXT("h3.wav"), NULL, SND_SYNC);
//#############################################################################################################################################################################################################################################

                }

        }

 

        glutSwapBuffers();

 

}


//     This function is called when a mouse event occurs.  This event, of type s

//     (up, down, dragged, etc.), occurs on a particular button of the mouse.

//

void myMouseFunc(int button, int state, int x, int y)

{

        //     shut up warnings

        (void)x;

        (void)y;

 

        switch (button)

        {

        case GLUT_LEFT_BUTTON:

                if (state == GLUT_DOWN)

                {

                       //     do something

                }

                else if (state == GLUT_UP)

                {

                       //                    exit(0);

                }

                break;

 

        default:

                break;

        }

}

 

//     This callback function is called when a keyboard event occurs

//

void myKeyboardFunc(unsigned char c, int x, int y)

{

        //     shut up warnings

        (void)x;

        (void)y;

 

        switch (c)

        {

        case 'w':

                // if we we were not moving, start the sound

               // if (currentDir == NO_DIR)
                    
               
             

                   //    PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_LOOP | SND_ASYNC);
//##################################################################################################################################################################################################################################################################################################################

                currentDir = UP_DIR;

                break;

 

        case 'a':

               // if (currentDir == NO_DIR)

                    //   PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_LOOP | SND_ASYNC);
//##################################################################################################################################################################################################################################################################################################################


                currentDir = LEFT_DIR;

                break;

 

        case 'd':

             //   if (currentDir == NO_DIR)

                 //      PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_LOOP | SND_ASYNC);
//##################################################################################################################################################################################################################################################################################################################


                currentDir = RIGHT_DIR;

                break;

 

        case 's':

              //  if (currentDir == NO_DIR)

                    //   PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_LOOP | SND_ASYNC);
  //##################################################################################################################################################################################################################################################################################################################


                currentDir = DOWN_DIR;

                break;

 

                //     use 'ESC' to end execution

        case 27:

                exit(0);

                break;

 

        default:

                break;

        }

}

 

double frac(double x)

{

        return x - floor(x);

}

 

void myTimerfunc(int val)


{

   

        int col = static_cast<int>(floor(pacmanX / squareSize));

        int row = static_cast<int>(floor(pacmanY / squareSize));

        char currSq = GRID[row][col];

 

        if (pacmanPoweredUp)

        {

                // check time since went powered up

                //     if too long (> POWERED_UP_DURATION)  --> revert to pacmanPoweredUp = false;

 

        }

 

        if (mouthOpening)

        {

                pacmanOpening++;

                if (pacmanOpening > PACMAN_MAX_OPENING)

                {

                       mouthOpening = false;

                       pacmanOpening = PACMAN_MAX_OPENING;

 

                }

        }

        else

        {

                pacmanOpening--;

                if (pacmanOpening < 0)

                {

                       mouthOpening = true;

                       pacmanOpening = 0;

 

                }

        }

 

        switch (currentDir)

        {

        case LEFT_DIR:

                //     is a left move possible a current location?

                //     if fractional part of x coord is right of square center keep going

                if (frac(pacmanX / squareSize) > 0.5)

                {

                       pacmanX -= PACMAN_SPEED;

                       checkCoinsAndPills(col, row);

                }

                else

                {

                       if (currSq == 'a' || currSq == 'c' || currSq == 'd' || currSq == 'f' || currSq == 'g' || currSq == 'i' ||

                               currSq == 'j' || currSq == 'l' || currSq == 'm')

                       {

                               pacmanX -= PACMAN_SPEED;

                       }

                       else if (currSq == '>')

                       {

                               // just got teleported

                               pacmanX -= PACMAN_SPEED;

                               checkCoinsAndPills(col, row);

                       }

                       else if (currSq == '<')

                       {

                               //     reappear on right side

                               pacmanX = (NUM_COLS - 0.5f) * squareSize;

                       }

                       // can't move left anymore

                       else

                       {

                               currentDir = NO_DIR;

                               lastDir = LEFT_DIR;

                            //   PlaySound(NULL, NULL, 0);
//##################################################################################################################################################################################################################################################################################################################


                               // don't allow drift:  set x to be exactly at center of sqaure

                               pacmanX = (col + 0.5f) * squareSize;

                       }

                }

                break;

 

                //  right move allowed:                'a', 'c', 'd', 'e', 'h', 'k', 'l', 'n'

        case RIGHT_DIR:

                //     is a right move possible a current location?

                //     if fractional part of x coord is right of square center keep going

                if (frac(pacmanX / squareSize) < 0.5 ||

                       (currSq == 'a' || currSq == 'c' || currSq == 'd' || currSq == 'e' || currSq == 'h' || currSq == 'k' ||

                               currSq == 'l' || currSq == 'n'))

                {

                       pacmanX += PACMAN_SPEED;

                       checkCoinsAndPills(col, row);

                }

                else if (currSq == '<')

                {

                       // just got teleported

                       pacmanX += PACMAN_SPEED;

                       checkCoinsAndPills(col, row);

                }

                else if (currSq == '>')

                {

                       //     reappear on left side

                       pacmanX = 0.5f * squareSize;

                }

                // else at grid[row][col-1] allows left move?

                else

                {

                       currentDir = NO_DIR;

                       lastDir = RIGHT_DIR;

                   //    PlaySound(NULL, NULL, 0);
//##################################################################################################################################################################################################################################################################################################################


                       // don't allow drift:  set x to be exactly at center of sqaure

                       pacmanX = (col + 0.5f) * squareSize;

                }

                break;

 

                //  up move allowed:           'b', 'd', 'e', 'f', 'i', 'k', 'l', 'm', 'n'

        case UP_DIR:

                //     is an up move possible a current location?

                //     if fractional part of y coord is right of square center keep going

                if (frac(pacmanY / squareSize) > 0.5 ||

                       (currSq == 'b' || currSq == 'd' || currSq == 'e' || currSq == 'f' || currSq == 'i' || currSq == 'k' ||

                               currSq == 'l' || currSq == 'm' || currSq == 'n'))

                {

                       pacmanY -= PACMAN_SPEED;

 

                       checkCoinsAndPills(col, row);

                }

                // else at grid[row][col-1] allows left move?

                else

                {

                       currentDir = NO_DIR;

                       lastDir = UP_DIR;

                  //    PlaySound(NULL, NULL, 0);
//##################################################################################################################################################################################################################################################################################################################


                       // don't allow drift:  set x to be exactly at center of sqaure

                       pacmanY = (row + 0.5f) * squareSize;

                }

                break;

 

                //  down move allowed:              'b', 'c', 'e', 'f', 'g', 'h', 'j', 'l', 'm', 'n'

        case DOWN_DIR:

                //     is a down move possible a current location?

                //     if fractional part of y coord is right of square center keep going

                if (frac(pacmanY / squareSize) < 0.5 ||

                       (currSq == 'b' || currSq == 'c' || currSq == 'e' || currSq == 'f' || currSq == 'g' || currSq == 'h' ||

                               currSq == 'j' || currSq == 'l' || currSq == 'm' || currSq == 'n'))

                {

                       pacmanY += PACMAN_SPEED;

 

                       checkCoinsAndPills(col, row);

                }

                // else at grid[row][col-1] allows left move?

                else

                {

                       currentDir = NO_DIR;

                       lastDir = DOWN_DIR;

                  //    PlaySound(NULL, NULL, 0);
 //##################################################################################################################################################################################################################################################################################################################


                       // don't allow drift:  set x to be exactly at center of sqaure

                       pacmanY = (row + 0.5f) * squareSize;

                }

                break;

 

 

        default:

                break;

 

        }

 

        if (ghostsStarted)

        {
            
            
            //if you change k to = 3 and run the program, only the orange (4th) ghost will move
            //only chnaging number of ghosts to numGhosts-1 will allow all ghosts but the orange (4th) ghost to move
            for (int k = 0; k < numGhosts-1; k++)
                
            {
                
                if (ghostAlive[k])
                    
                {
                    
                      updateGhost(k);
                    
                    
                    
                    // compute distance ghost and pacman  if less than collision distance --> game over
                    
                    float dx = ghost[k][0] - pacmanX, dy = ghost[k][1] - pacmanY;
                    
                    if (dx * dx + dy * dy < COLLISION_DIST_SQ)
                        
                        gameRunning = false;
                    
                    
                    
                }
                
            }
            
            for (int k = 3; k < numGhosts; k++)
                
            {
                
                if (ghostAlive[k])
                    
                {
                    
                    map m;
                    //end point or Pac-Man Position
                    int pacy = pacmanY/squareSize;
                    int pacx = pacmanX/squareSize;
                    point s, e( pacy, pacx );   //pac man loc. pacy, pacx
                    aStar as;
                    
                    if( as.search( s, e, m ) ) {
                        std::list<point> path;
                        int c = as.path( path );
                        
                        updateAstarGhost(k, path, c);
                    }
                        //  moveOrangeGhost();
                        
                        
                        // compute distance ghost and pacman  if less than collision distance --> game over
                        
                        float dx = ghost[k][0] - pacmanX, dy = ghost[k][1] - pacmanY;
                        
                        if (dx * dx + dy * dy < COLLISION_DIST_SQ)
                            
                            gameRunning = false;
                        
                        
                        
                    
                    
                }
                
            }
        }
    
        else

        {

                if (time(NULL) - startTime > GHOST_START_TIME)

                {

                       ghostsStarted = true;

                       for (int k = 0; k < numGhosts-1; k++)

                       {

                               ghost[k][0] = ghostStart[k][0];

                               ghost[k][1] = ghostStart[k][1];

                               ghostDir[k] = ghostStartDir[k];

                       }
                    for (int k = 3; k < numGhosts; k++)

                    {

                            ghost[k][0] = ghostStart[k][0];

                            ghost[k][1] = ghostStart[k][1];

                            ghostDir[k] = ghostStartDir[k];

                    }

                }

        }

 

        frameCount++;

        //     I perform the rendering one heartbeat out of 2

        if (frameCount % 3 == 0)

                glutPostRedisplay();

 

        //     I re-prime this function to get called again in n miliseconds.

        //     Note that this means that we can change the "timer function" during the

        //     execution of a program

        glutTimerFunc(heartBeat, myTimerfunc, val);

 

}

 



























/*
void myTimerfunc2(int val)

{

      

        int col = static_cast<int>(floor(pacmanX / squareSize));

        int row = static_cast<int>(floor(pacmanY / squareSize));

        char currSq = GRID[row][col];

 

        if (pacmanPoweredUp)

        {

                // check time since went powered up

                //     if too long (> POWERED_UP_DURATION)  --> revert to pacmanPoweredUp = false;

 

        }

 

        if (mouthOpening)

        {

                pacmanOpening++;

                if (pacmanOpening > PACMAN_MAX_OPENING)

                {

                       mouthOpening = false;

                       pacmanOpening = PACMAN_MAX_OPENING;

 

                }

        }

        else

        {

                pacmanOpening--;

                if (pacmanOpening < 0)

                {

                       mouthOpening = true;

                       pacmanOpening = 0;

 

                }

        }

 

        switch (currentDir)

        {

        case LEFT_DIR:

                //     is a left move possible a current location?

                //     if fractional part of x coord is right of square center keep going

                if (frac(pacmanX / squareSize) > 0.5)

                {

                       pacmanX -= PACMAN_SPEED;

                       checkCoinsAndPills(col, row);

                }

                else

                {

                       if (currSq == 'a' || currSq == 'c' || currSq == 'd' || currSq == 'f' || currSq == 'g' || currSq == 'i' ||

                               currSq == 'j' || currSq == 'l' || currSq == 'm')

                       {

                               pacmanX -= PACMAN_SPEED;

                       }

                       else if (currSq == '>')

                       {

                               // just got teleported

                               pacmanX -= PACMAN_SPEED;

                               checkCoinsAndPills(col, row);

                       }

                       else if (currSq == '<')

                       {

                               //     reappear on right side

                               pacmanX = (NUM_COLS - 0.5f) * squareSize;

                       }

                       // can't move left anymore

                       else

                       {

                               currentDir = NO_DIR;

                               lastDir = LEFT_DIR;

                            //   PlaySound(NULL, NULL, 0);
//##################################################################################################################################################################################################################################################################################################################


                               // don't allow drift:  set x to be exactly at center of sqaure

                               pacmanX = (col + 0.5f) * squareSize;

                       }

                }

                break;

 

                //  right move allowed:                'a', 'c', 'd', 'e', 'h', 'k', 'l', 'n'

        case RIGHT_DIR:

                //     is a right move possible a current location?

                //     if fractional part of x coord is right of square center keep going

                if (frac(pacmanX / squareSize) < 0.5 ||

                       (currSq == 'a' || currSq == 'c' || currSq == 'd' || currSq == 'e' || currSq == 'h' || currSq == 'k' ||

                               currSq == 'l' || currSq == 'n'))

                {

                       pacmanX += PACMAN_SPEED;

                       checkCoinsAndPills(col, row);

                }

                else if (currSq == '<')

                {

                       // just got teleported

                       pacmanX += PACMAN_SPEED;

                       checkCoinsAndPills(col, row);

                }

                else if (currSq == '>')

                {

                       //     reappear on left side

                       pacmanX = 0.5f * squareSize;

                }

                // else at grid[row][col-1] allows left move?

                else

                {

                       currentDir = NO_DIR;

                       lastDir = RIGHT_DIR;

                   //    PlaySound(NULL, NULL, 0);
//##################################################################################################################################################################################################################################################################################################################


                       // don't allow drift:  set x to be exactly at center of sqaure

                       pacmanX = (col + 0.5f) * squareSize;

                }

                break;

 

                //  up move allowed:           'b', 'd', 'e', 'f', 'i', 'k', 'l', 'm', 'n'

        case UP_DIR:

                //     is an up move possible a current location?

                //     if fractional part of y coord is right of square center keep going

                if (frac(pacmanY / squareSize) > 0.5 ||

                       (currSq == 'b' || currSq == 'd' || currSq == 'e' || currSq == 'f' || currSq == 'i' || currSq == 'k' ||

                               currSq == 'l' || currSq == 'm' || currSq == 'n'))

                {

                       pacmanY -= PACMAN_SPEED;

 

                       checkCoinsAndPills(col, row);

                }

                // else at grid[row][col-1] allows left move?

                else

                {

                       currentDir = NO_DIR;

                       lastDir = UP_DIR;

                  //    PlaySound(NULL, NULL, 0);
//##################################################################################################################################################################################################################################################################################################################


                       // don't allow drift:  set x to be exactly at center of sqaure

                       pacmanY = (row + 0.5f) * squareSize;

                }

                break;

 

                //  down move allowed:              'b', 'c', 'e', 'f', 'g', 'h', 'j', 'l', 'm', 'n'

        case DOWN_DIR:

                //     is a down move possible a current location?

                //     if fractional part of y coord is right of square center keep going

                if (frac(pacmanY / squareSize) < 0.5 ||

                       (currSq == 'b' || currSq == 'c' || currSq == 'e' || currSq == 'f' || currSq == 'g' || currSq == 'h' ||

                               currSq == 'j' || currSq == 'l' || currSq == 'm' || currSq == 'n'))

                {

                       pacmanY += PACMAN_SPEED;

 

                       checkCoinsAndPills(col, row);

                }

                // else at grid[row][col-1] allows left move?

                else

                {

                       currentDir = NO_DIR;

                       lastDir = DOWN_DIR;

                  //    PlaySound(NULL, NULL, 0);
 //##################################################################################################################################################################################################################################################################################################################


                       // don't allow drift:  set x to be exactly at center of sqaure

                       pacmanY = (row + 0.5f) * squareSize;

                }

                break;

 

 

        default:

                break;

 

        }

 

        if (ghostsStarted)

        {
            
            
            //if you change k to = 3 and run the program, only the orange (4th) ghost will move
            //only chnaging number of ghosts to numGhosts-1 will allow all ghosts but the orange (4th) ghost to move
            for (int k = 0; k < numGhosts-1; k++)
                
            {
                
                if (ghostAlive[k])
                    
                {
                    
                      updateGhost(k);
                    
                    
                    
                    // compute distance ghost and pacman  if less than collision distance --> game over
                    
                    float dx = ghost[k][0] - pacmanX, dy = ghost[k][1] - pacmanY;
                    
                    if (dx * dx + dy * dy < COLLISION_DIST_SQ)
                        
                        gameRunning = false;
                    
                    
                    
                }
                
            }
            
            for (int k = 3; k < numGhosts; k++)
                
            {
                
                if (ghostAlive[k])
                    
                {
                    
                    map m;
                    //end point or Pac-Man Position
                    int pacy = pacmanY/squareSize;
                    int pacx = pacmanX/squareSize;
                    point s, e( 14, 17 );   //pac man loc. pacy, pacx
                    aStar as;
                    
                    if( as.search( s, e, m ) ) {
                        std::list<point> path;
                        int c = as.path( path );
                        
                        
                        updateAstarGhost(k, path, c);
                    }
                        //  moveOrangeGhost();
                        
                        
                        // compute distance ghost and pacman  if less than collision distance --> game over
                        
                        float dx = ghost[k][0] - pacmanX, dy = ghost[k][1] - pacmanY;
                        
                        if (dx * dx + dy * dy < COLLISION_DIST_SQ)
                            
                            gameRunning = false;
                        
                        
                        
                    
                    
                }
                
            }
        }
    
        else

        {

                if (time(NULL) - startTime > GHOST_START_TIME)

                {

                       ghostsStarted = true;

                       for (int k = 0; k < numGhosts-1; k++)

                       {

                               ghost[k][0] = ghostStart[k][0];

                               ghost[k][1] = ghostStart[k][1];

                               ghostDir[k] = ghostStartDir[k];

                       }
                    for (int k = 3; k < numGhosts; k++)

                    {

                            ghost[k][0] = ghostStart[k][0];

                            ghost[k][1] = ghostStart[k][1];

                            ghostDir[k] = ghostStartDir[k];

                    }
                   

                }

        }

 

        frameCount++;

        //     I perform the rendering one heartbeat out of 2

        if (frameCount % 3 == 0)

                glutPostRedisplay();

 

        //     I re-prime this function to get called again in n miliseconds.

        //     Note that this means that we can change the "timer function" during the

        //     execution of a program

        glutTimerFunc(heartBeat, myTimerfunc, val);

 

}



*/









































void checkCoinsAndPills(int col, int row)

{

        // check for coin pickup.  Go over the list of all coins

        for (unsigned long i = 0; i < coinList.size(); i++)

        {

                if (coinList[i].isPresent)

                {

                       // check x difference between coin and pacman

                       if (coinList[i].col == col && coinList[i].row == row)

                       {

                               coinList[i].isPresent = false;

                               // update score

                               score += 1;

                       }

                }

        }

 

        // same thing with pills

}

 

void updateGhost(int ghostIndex)

{

        /*    pacmanX += pacmanVx;

                pacmanY += pacmanVy;

                cout << "x=" << pacmanX << "(" << (pacmanX/squareSize) << "), " <<

                "y=" << pacmanY << "(" << (pacmanY / squareSize) << "), " << endl;

        */

        int col = static_cast<int>(floor(ghost[ghostIndex][0] / squareSize));

        int row = static_cast<int>(floor(ghost[ghostIndex][1] / squareSize));

        char currSq = GRID[row][col];

        //     cout << "ghostXY = (" << ghost[ghostIndex][0] << ", " << ghost[ghostIndex][1] <<

        //            ", ghostRowCol = [" << row << ", " << col << "], square: " << currSq << endl;

        MoveDir newDir;

 

        //     first handle the teleport squares

        if (currSq == '<' || currSq == '>')

        {

                if (currSq == '>')

                {

                       // ghost was moving LEFT --> just got teleported

                       //     keep moving left

                       if (ghostDir[ghostIndex] == LEFT_DIR)

                       {

                               ghost[ghostIndex][0] -= GHOST_SPEED;

                                newDir = LEFT_DIR;

                       }

                       //     the ghost is moving right --> teleport

                       else

                       {

                               //     reappear on left side, still moving right

                               ghost[ghostIndex][0] = 0.5f * squareSize;

                               newDir = RIGHT_DIR;

                       }

                }

                else // if (currSq == '<')

                {

                       // ghost was moving RIGHT --> just got teleported

                       //     keep moving right

                       if (ghostDir[ghostIndex] == RIGHT_DIR)

                       {

                               ghost[ghostIndex][0] += GHOST_SPEED;

                               newDir = RIGHT_DIR;

                       }

                       //     the ghost is moving left --> teleport

                       else

                       {

                               //     reappear on right side

                               ghost[ghostIndex][0] = (NUM_COLS - 0.5f) * squareSize;

                               newDir = LEFT_DIR;

                       }

                }

        }

        //     Handle non-teleport square types, but only if didn't already make a direction

        //     decision in the same square

        else if (row != ghostDecisionLoc[ghostIndex][0] || col != ghostDecisionLoc[ghostIndex][1])

        {

                switch (GRID[row][col])

                {

 

                       // intersection or corner tile:  pick random among (possibly reversing direction)

 

 

                //     left, right, down           c

                case 'c':

                {

                       //     V1 arrive to a T corner:  1/3 chance of taking the turn v.s going thru vs reversing direction

//                    MoveDir possible[] = { LEFT_DIR, RIGHT_DIR, DOWN_DIR };

                       // get random direction

//                    newDir = possible[rand() % 3];

 

                       // V2 arrive to a T turn: 5/5/ chance depending on incoming direction

                       //     if ghost was moving right -->50/50 left or down

                       if (ghostDir[ghostIndex] == RIGHT_DIR)

                       {

                               MoveDir possible[] = { LEFT_DIR, DOWN_DIR };

                               // get random direction

                               newDir = possible[rand() % 2];

                       }

                       else if (ghostDir[ghostIndex] == LEFT_DIR)

                       {

                               MoveDir possible[] = { RIGHT_DIR, DOWN_DIR };

                               // get random direction

                               newDir = possible[rand() % 2];

                       }

                       else // UP_DIR  50/50 LEFT or RIGHT

                       {

                               MoveDir possible[] = { RIGHT_DIR, LEFT_DIR };

                               // get random direction

                               newDir = possible[rand() % 2];

                       }

                       // move direction is one random among left, right, down

 

 

                }

                break;

 

                //  left, right, up             d

                case 'd':

                {

                       MoveDir possible[] = { LEFT_DIR, RIGHT_DIR, UP_DIR };

                       // get random direction

                       newDir = possible[rand() % 3];

                }

                break;

 

                //  up, down, right             e

                case 'e':

                {

                       // move direction is one random among up, down, right

                       MoveDir possible[] = { UP_DIR, DOWN_DIR, RIGHT_DIR };

                       // get random direction

                       newDir = possible[rand() % 3];

                }

                break;

 

                //  up, down, left              f

                case 'f':

                {

                       // move direction is one random among up, down, left

                       MoveDir possible[] = { UP_DIR, DOWN_DIR, LEFT_DIR };

                       // get random direction

                       newDir = possible[rand() % 3];

                }

                break;

 

                //  left, down                  g

                case 'g':

                {

                       //     V1 arrive to a corner turn:  50/50 chance of taking the turn v.s reversing direction

//                    MoveDir possible[] = { LEFT_DIR, DOWN_DIR };

                       // get random direction

        //            newDir = possible[rand() % 2];

 

                       // V2 arrive to a corner turn: always take the turn

                       //     if ghost was moving right --> go DOWN

                       if (ghostDir[ghostIndex] == RIGHT_DIR)

                               newDir = DOWN_DIR;

                       //     if ghost was coming UP, turn left

                       else

                               newDir = LEFT_DIR;

 

                }

                break;

 

                //  right, down                 h

                case 'h':

                {

                       // move direction is one random among right, down

                       MoveDir possible[] = { RIGHT_DIR, DOWN_DIR };

                       // get random direction

                       newDir = possible[rand() % 2];

                }

                break;

 

                //  left, up                    i

                case 'i':

                {

                       // move direction is one random among left, up

                       MoveDir possible[] = { LEFT_DIR, UP_DIR };

                       // get random direction

                       newDir = possible[rand() % 2];

                }

                break;

 

                //  left, down                  j

                case 'j':

                {

                       // move direction is one random among left, down

                       MoveDir possible[] = { LEFT_DIR, DOWN_DIR };

                       // get random direction

                       newDir = possible[rand() % 2];

                }

                break;

 

                //  right, up                   k

                case 'k':

                {

                       // move direction is one random among right, up

                       MoveDir possible[] = { RIGHT_DIR, UP_DIR };

                       // get random direction

                       newDir = possible[rand() % 2];

                }

                break;

 

                //  up, down, left, right       l

                case 'l':

                {

                       // move direction is one random among up, down, left, right

                       MoveDir possible[] = { UP_DIR, DOWN_DIR, LEFT_DIR, RIGHT_DIR };

                       // get random direction

                       newDir = possible[rand() % 4];

                }

                break;

 

                //  up, down, left              m

                case 'm':

                {

                       // move direction is one random among up, down, left

                       MoveDir possible[] = { UP_DIR, DOWN_DIR, LEFT_DIR };

                       // get random direction

                       newDir = possible[rand() % 3];

                }

                break;

 

                //  up, down, right             n

                case 'n':

                {

                       // move direction is one random among up, down, right

                       MoveDir possible[] = { UP_DIR, DOWN_DIR, RIGHT_DIR };

                       // get random direction

                       newDir = possible[rand() % 3];

                }

                break;

 

                //2 opposite directions possible (corridor):  do nothing  (keep direction)

                //     left, right                 a

                //  up, down                    b

                default:

                       newDir = ghostDir[ghostIndex];

                       break;

 

                }

 

                //     in any case, we remember that this ghost has made a direction decision for this square

                ghostDecisionLoc[ghostIndex][0] = row;

                ghostDecisionLoc[ghostIndex][1] = col;

 

        }

        else

        {

                newDir = ghostDir[ghostIndex];

        }

 

 

        // if we changed direction, then force the gohst to restart from the center of its corrent square

        if (newDir != ghostDir[ghostIndex])

        {

                ghost[ghostIndex][0] = (col + 0.5f) * squareSize;

                ghost[ghostIndex][1] = (row + 0.5f) * squareSize;

                ghostDir[ghostIndex] = newDir;

 

        }

 

        switch (ghostDir[ghostIndex])

        {

        case LEFT_DIR:

                ghost[ghostIndex][0] -= GHOST_SPEED;

                break;

 

        case RIGHT_DIR:

                ghost[ghostIndex][0] += GHOST_SPEED;

                break;

 

        case UP_DIR:

                ghost[ghostIndex][1] -= GHOST_SPEED;

                break;

 

                //  down move allowed:              'b', 'c', 'e', 'f', 'g', 'h', 'j', 'l', 'm', 'n'

        case DOWN_DIR:

                ghost[ghostIndex][1] += GHOST_SPEED;

                break;

 

        default:

                break;

        }

 

}


//FUNCTION TO IMPLEMENT ALGORITHM-------------------------------------------------------------------------
void updateAstarGhost(int ghostIndex, std::list<point> path, int c)
{
    /*
    map m;
    //end point or Pac-Man Position
    int pacy = pacmanY/squareSize;
    int pacx = pacmanX/squareSize;
    point s, e( 14, 17 );   //pac man loc. pacy, pacx
    aStar as;
    
    if( as.search( s, e, m ) ) {
        std::list<point> path;
        int c = as.path( path );
        
        */
        //go through path coordinates
        int xt =(*path.begin()).x;
        int yt = (*path.begin()).y;
        MoveDir neighDir;
    int direction = 0;
        
        for (list<point>::iterator i = path.begin(); i != path.end(); i++ ) {
         
            //move right
            if (( *i ).x  - 1 == xt ) {
            
                direction = 1;
              

                xt = (*i).x;
                
            }
            
            //move left
            else if ((*i).x + 1 == xt) {
             
                direction = 2;
                 

                xt = (*i).x;
                
            }
            
            //move up
            else if ((*i).y + 1 == yt) {
            
                direction = 3;
                    
                    
                yt = (*i).y;
                
            }
            
            //move down
            else if ((*i).y - 1 == yt) {
              
                direction = 4;
              
              
                yt = (*i).y;
                
            }
            
            
                
                int col = static_cast<int>(floor(ghost[ghostIndex][0] / squareSize));
                
                int row = static_cast<int>(floor(ghost[ghostIndex][1] / squareSize));
                
                char currSq = GRID[(*i).x][(*i).y];
            
            MoveDir newDir;

                
                //     cout << "ghostXY = (" << ghost[ghostIndex][0] << ", " << ghost[ghostIndex][1] <<
                
                //            ", ghostRowCol = [" << row << ", " << col << "], square: " << currSq << endl;
                
                
                
                
                //     first handle the teleport squares
                /*
                if (currSq == '<' || currSq == '>')
                
                {
                
                if (currSq == '>')
                
                {
                
                // ghost was moving LEFT --> just got teleported
                
                //     keep moving left
                
                if (ghostDir[ghostIndex] == LEFT_DIR)
                
                {
                
                ghost[ghostIndex][0] -= GHOST_SPEED;
                
                newDir = LEFT_DIR;
                
                }
                
                //     the ghost is moving right --> teleport
                
                else
                
                {
                
                //     reappear on left side, still moving right
                
                ghost[ghostIndex][0] = 0.5f * squareSize;
                
                newDir = RIGHT_DIR;
                
                }
                
                }
                
                else // if (currSq == '<')
                
                {
                
                // ghost was moving RIGHT --> just got teleported
                
                //     keep moving right
                
                if (ghostDir[ghostIndex] == RIGHT_DIR)
                
                {
                
                ghost[ghostIndex][0] += GHOST_SPEED;
                
                newDir = RIGHT_DIR;
                
                }
                
                //     the ghost is moving left --> teleport
                
                else
                
                {
                
                //     reappear on right side
                
                ghost[ghostIndex][0] = (NUM_COLS - 0.5f) * squareSize;
                
                newDir = LEFT_DIR;
                
                }
                
                }
                
                }
                 */
                
                //     Handle non-teleport square types, but only if didn't already make a direction
                
                //     decision in the same square
                
                 if (row != ghostDecisionLoc[ghostIndex][0] || col != ghostDecisionLoc[ghostIndex][1])
                
                {
                
                switch (GRID[(*i).x][(*i).y])
                
                {
                
                
                
                // intersection or corner tile:  pick random among (possibly reversing direction)
                
                
                
                
                
                //     left, right, down           c
                
                case 'c':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                }
                
                break;
                
                
                
                //  left, right, up             d
                
                case 'd':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                }
                
                break;
                
                
                
                //  up, down, right             e
                
                case 'e':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  up, down, left              f
                
                case 'f':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  left, down                  g
                
                case 'g':
                
                {
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  right, down                 h
                
                case 'h':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  left, up                    i
                
                case 'i':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  left, down                  j
                
                case 'j':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  right, up                   k
                
                case 'k':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                }
                
                break;
                
                
                
                //  up, down, left, right       l
                
                case 'l':
                
                {
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //  up, down, left              m
                
                case 'm':
                
                {
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                }
                
                break;
                
                
                
                //  up, down, right             n
                
                case 'n':
                
                {
                
                    if (direction == 1) {
                       
                        newDir = RIGHT_DIR;
                    }
                
                    else if (direction == 2) {
                      
                        newDir = LEFT_DIR;
                    }
                
                    else if (direction == 3) {
                       
                        newDir = UP_DIR;
                    }
                    
                    else if (direction == 4) {
                       
                        newDir = DOWN_DIR;
                    }
                
                
                }
                
                break;
                
                
                
                //2 opposite directions possible (corridor):  do nothing  (keep direction)
                
                //     left, right                 a
                
                //  up, down                    b
                
                default:
                
                newDir = ghostDir[ghostIndex];
                
                break;
                
                
                
                }
                
                
                
                //     in any case, we remember that this ghost has made a direction decision for this square
                
                ghostDecisionLoc[ghostIndex][0] = (*i).x;
                
                ghostDecisionLoc[ghostIndex][1] = (*i).y;
                
                
                
                }
                
                else
                
                {
               
                newDir = ghostDir[ghostIndex];
                
                }
                
                
                
                
                
                // if we changed direction, then force the gohst to restart from the center of its corrent square
                
                if (newDir != ghostDir[ghostIndex])
                
                {
                
                ghost[ghostIndex][0] = ((*i).y + 0.5f) * squareSize;
                
                ghost[ghostIndex][1] = ((*i).x + 0.5f) * squareSize;
                
                ghostDir[ghostIndex] = newDir;
                
                
                
                }
                
                
                
                switch (ghostDir[ghostIndex])
                
                {
                
                case LEFT_DIR:
                
                ghost[ghostIndex][0] -= GHOST_SPEED/10;
                
                break;
                
                
                
                case RIGHT_DIR:
                
                ghost[ghostIndex][0] += GHOST_SPEED/10;
                
                break;
                
                
                
                case UP_DIR:
                
                ghost[ghostIndex][1] -= GHOST_SPEED/10;
                
                break;
                
                
                
                //  down move allowed:              'b', 'c', 'e', 'f', 'g', 'h', 'j', 'l', 'm', 'n'
                
                case DOWN_DIR:
                
                ghost[ghostIndex][1] += GHOST_SPEED/10;
                
                break;
                
                
                
                default:
                
                break;
                
                }
            
        }
        
    }








void updateAstarGhost2(int ghostIndex, std::list<point> path, int c)

{
    
    map m;
    //end point or Pac-Man Position
    int pacy = pacmanY/squareSize;
    int pacx = pacmanX/squareSize;
    point s, e( 14, 17 );   //pac man loc. pacy, pacx
    aStar as;
    
    if( as.search( s, e, m ) ) {
        std::list<point> path;
        int c = as.path( path );
        
        
        
        //start point
        list<point>::iterator i = path.begin();
        //neighbor point
        list<point>::iterator it = path.begin();
        std::advance(it, 1);
        
        
        
        //go through path coordinates
        int xt =(*path.begin()).x;
        int yt = (*path.begin()).y;
        int direction = 0;
        
        
        
        //move right
        if (xt  + 1 == (*it).x  ) {
            
            direction = 1;
            path.erase(path.begin());
            
            
            
            
        }
        
        //move left
        else if (xt - 1 == (*it).x) {
            
            direction = 2;
            path.erase(path.begin());
            
            
            
            
        }
        
        //move up
        else if (yt - 1 == (*it).y) {
            
            direction = 3;
            path.erase(path.begin());
            
            
            
            
        }
        
        //move down
        else if (yt + 1 == (*it).y) {
            
            direction = 4;
            path.erase(path.begin());
            
            
            
            
        }
    
    
    
    int col = static_cast<int>(floor(ghost[ghostIndex][0] / squareSize));
    
    int row = static_cast<int>(floor(ghost[ghostIndex][1] / squareSize));
    
    char currSq = GRID[row][col];
    
    MoveDir newDir;
    
    
    //     cout << "ghostXY = (" << ghost[ghostIndex][0] << ", " << ghost[ghostIndex][1] <<
    
    //            ", ghostRowCol = [" << row << ", " << col << "], square: " << currSq << endl;
    
    
    
    
    //     first handle the teleport squares
    /*
     if (currSq == '<' || currSq == '>')
     
     {
     
     if (currSq == '>')
     
     {
     
     // ghost was moving LEFT --> just got teleported
     
     //     keep moving left
     
     if (ghostDir[ghostIndex] == LEFT_DIR)
     
     {
     
     ghost[ghostIndex][0] -= GHOST_SPEED;
     
     newDir = LEFT_DIR;
     
     }
     
     //     the ghost is moving right --> teleport
     
     else
     
     {
     
     //     reappear on left side, still moving right
     
     ghost[ghostIndex][0] = 0.5f * squareSize;
     
     newDir = RIGHT_DIR;
     
     }
     
     }
     
     else // if (currSq == '<')
     
     {
     
     // ghost was moving RIGHT --> just got teleported
     
     //     keep moving right
     
     if (ghostDir[ghostIndex] == RIGHT_DIR)
     
     {
     
     ghost[ghostIndex][0] += GHOST_SPEED;
     
     newDir = RIGHT_DIR;
     
     }
     
     //     the ghost is moving left --> teleport
     
     else
     
     {
     
     //     reappear on right side
     
     ghost[ghostIndex][0] = (NUM_COLS - 0.5f) * squareSize;
     
     newDir = LEFT_DIR;
     
     }
     
     }
     
     }
     */
    
    //     Handle non-teleport square types, but only if didn't already make a direction
    
    //     decision in the same square
    
    if (row != ghostDecisionLoc[ghostIndex][0] || col != ghostDecisionLoc[ghostIndex][1])
        
    {
        
        switch (GRID[row][col])
            
        {
                
                
                
                // intersection or corner tile:  pick random among (possibly reversing direction)
                
                
                
                
                
                //     left, right, down           c
                
            case 'c':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
            }
                
                break;
                
                
                
                //  left, right, up             d
                
            case 'd':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
            }
                
                break;
                
                
                
                //  up, down, right             e
                
            case 'e':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  up, down, left              f
                
            case 'f':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  left, down                  g
                
            case 'g':
                
            {
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  right, down                 h
                
            case 'h':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  left, up                    i
                
            case 'i':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  left, down                  j
                
            case 'j':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  right, up                   k
                
            case 'k':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
            }
                
                break;
                
                
                
                //  up, down, left, right       l
                
            case 'l':
                
            {
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //  up, down, left              m
                
            case 'm':
                
            {
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
            }
                
                break;
                
                
                
                //  up, down, right             n
                
            case 'n':
                
            {
                
                if (direction == 1) {
                    
                    newDir = RIGHT_DIR;
                }
                
                else if (direction == 2) {
                    
                    newDir = LEFT_DIR;
                }
                
                else if (direction == 3) {
                    
                    newDir = UP_DIR;
                }
                
                else if (direction == 4) {
                    
                    newDir = DOWN_DIR;
                }
                
                
            }
                
                break;
                
                
                
                //2 opposite directions possible (corridor):  do nothing  (keep direction)
                
                //     left, right                 a
                
                //  up, down                    b
                
            default:
                
                newDir = ghostDir[ghostIndex];
                
                break;
                
                
                
        }
        
        
        
        //     in any case, we remember that this ghost has made a direction decision for this square
        
        ghostDecisionLoc[ghostIndex][0] = row;
        
        ghostDecisionLoc[ghostIndex][1] = col;
        
        
        
    }
    
    else
        
    {
        
        newDir = ghostDir[ghostIndex];
        
    }
    
    
    
    
    
    // if we changed direction, then force the gohst to restart from the center of its corrent square
    
    if (newDir != ghostDir[ghostIndex])
        
    {
        
        ghost[ghostIndex][0] = ((*i).y + 0.5f) * squareSize;
        
        ghost[ghostIndex][1] = ((*i).x + 0.5f) * squareSize;
        
        ghostDir[ghostIndex] = newDir;
        
        
        
    }
    
    
    
    switch (ghostDir[ghostIndex])
        
    {
            
        case LEFT_DIR:
            
            ghost[ghostIndex][0] -= GHOST_SPEED;
            
            break;
            
            
            
        case RIGHT_DIR:
            
            ghost[ghostIndex][0] += GHOST_SPEED;
            
            break;
            
            
            
        case UP_DIR:
            
            ghost[ghostIndex][1] -= GHOST_SPEED;
            
            break;
            
            
            
            //  down move allowed:              'b', 'c', 'e', 'f', 'g', 'h', 'j', 'l', 'm', 'n'
            
        case DOWN_DIR:
            
            ghost[ghostIndex][1] += GHOST_SPEED;
            
            break;
            
            
            
        default:
            
            break;
            
    }
    
}
        
    }






























//-------------------------------------------------------------------------------------------------------
 
//MAIN FUNCTION------------------------------------------------------------------------------------------
int main(int argc, char* argv[])

{

      //  bool played = PlaySound(TEXT("pacstart.wav"), NULL, SND_SYNC);  //  plays start up sound
//##################################################################################################################################################################################################################################################################################################################
    
        gameRunning = true;

        //     seed the random generator
        startTime = time(NULL);
        srand(static_cast<unsigned int>(startTime));

//call for initialize coinlist function
        initializeCoinList();

    
    //initializeWindow() //     Initialize glut and create a new window
    //call using objects/classes
    Graphics make_window = Graphics();
    make_window.initializeWindow(argc, argv, INIT_WIN_X, INIT_WIN_Y);
    

        //==================================

        //     set up the callback functions

        //==================================
    
        glutDisplayFunc(myDisplayFunc);

    Graphics resize = Graphics();
    resize.myResize(winWidth, winHeight);
    
        
        //     glutMouseFunc(myMouseFunc);
    
   
        
        glutKeyboardFunc(myKeyboardFunc);
    
        //     Use glutTimerFunc for animated scenes, where you need a display with a

        //     constant redraw rate

        //     Arguments are: number of milli-seconds, function to call, int value to pass

        //     to that function (often just zero).

        //     Note that we can change the "timer function" anytime during the execution

        //     of the program

    
    //find path and pass through neighbor to change location
    
   
        glutTimerFunc(heartBeat, myTimerfunc, 0);
        
    

 

 

        //     Now we enter the main loop of the program and to a large extend

        //     "lose control" over its execution.  The callback functions that

        //     we set up earlier will be called when the corresponding event

        //     occurs

        glutMainLoop();

 

        //     This will never be executed (the exit point will be in one of the

        //     call back functions).

 
    
        return 0;
    

}
//END OF MAIN FUNCTION-----------------------------------------------------------------------------------
 







//============================================================================

#if 0

#pragma mark -

#pragma mark Drawing primitives

#endif

//============================================================================

 

//     A simple function to draw a colored rotated square centered at the designated

//     location.

void drawSquare(GLfloat cx, GLfloat cy, GLfloat angle, GLfloat scale, GLfloat r,

        GLfloat g, GLfloat b, bool contour)

{

        //-------------------------------------------------

        //     Part 0:  First preserve the current state

        //-------------------------------------------------

        glPushMatrix();

 

        //-------------------------------------------------

        //     Part 1:  Apply transformations (translation, rotation, scaling; typically in that

        //     order) to get to the object's reference frame

        //-------------------------------------------------

 

        //     Translation coordinates are in "world units," defined (in the case of this program)

        //     by the call to gluOrtho2D in myResizeFunc() function below.

        glTranslatef(cx, cy, 0);

 

        //     OpenGL rotations angles are in degrees.  You (like everybody else) will

        //     every now and then get into trouble because your math calculations involving

        //     the built-in trigonometric functions of C/C++ (sin, cos, etc.) all use radians.

        glRotatef(angle, 0.f, 0.f, 1.f);

        glScalef(scale, scale, 1.f);

 

        //-------------------------------------------------

        //     Part 2:  Do the drawing in the object's own reference frame

        //-------------------------------------------------

        glColor3f(r, g, b);

        glBegin(GL_POLYGON);

        glVertex2f(1.f, 0.f);

        glVertex2f(0.f, 1.f);

        glVertex2f(-1.f, 0.f);

        glVertex2f(0.f, -1.f);

        glEnd();

 

        if (contour) {

                glColor3f(1.f - r, 1.f - g, 1.f - b);

                glBegin(GL_LINE_LOOP);

                glVertex2f(1.f, 0.f);

                glVertex2f(0.f, 1.f);

                glVertex2f(-1.f, 0.f);

                glVertex2f(0.f, -1.f);

                glEnd();

        }

 

        //-------------------------------------------------

        //     Part 3: Restore the initial reference frame

        //-------------------------------------------------

        glPopMatrix();

}

 

// draw a colored disk at the location, scale, and color specified

void drawDisk(GLfloat cx, GLfloat cy, GLfloat scale, const GLfloat color[])

{

        //-------------------------------------------------

        //     Part 0:  First preserve the current state

        //-------------------------------------------------

        glPushMatrix();

 

        //-------------------------------------------------

        //     Part 1:  Apply transformations (translation, scaling; typically in that

        //     order) to get to the object's reference frame.  Obviously, there is no

        //     rotation for a circle

        //-------------------------------------------------

 

        //     Translation coordinates are in "world units," defined (in the case of this program)

        //     by the call to gluOrtho2D in myResizeFunc() function below.

        glTranslatef(cx, cy, 0);

        glScalef(scale, scale, 1.f);

 

        //-------------------------------------------------

        //     Part 2:  Do the drawing in the object's own reference frame

        //-------------------------------------------------

        glColor3fv(color);

        glBegin(GL_POLYGON);

        for (unsigned int k = 0; k < NB_CIRCLE_PT; k++)

        {

                glVertex2f(CIRCLE_PT[k][0], CIRCLE_PT[k][1]);

        }

        glEnd();

 

        //-------------------------------------------------

        //     Part 3: Restore the initial reference frame

        //-------------------------------------------------

        glPopMatrix();

}

 

 

void drawGhosts()

{

        //  Prototype  //////////////////////////////////////////////////////////////////////////////////////////////////////

        for (int i = 0; i < numGhosts; i++)

        {

                if (ghostAlive[i])

                {

                       // draw Ghost k

                       glPushMatrix();

 

                       glTranslatef(ghost[i][0], ghost[i][1] + 0.5f * squareSize, 0.f);

                       glScalef(GHOST_SCALE_X, -GHOST_SCALE_Y, 1.f);

                       //MoveDir drawDir;

                       glColor3fv(GHOST_COLOR[i]);

                       // draw bottom half

                       glBegin(GL_POLYGON);

                       //display top half

 

                       for (unsigned int k = 0; k <= NB_CIRCLE_PT / 2; k++)

                       {

                               glVertex2f(CIRCLE_PT[k][0], CIRCLE_PT[k][1]);

                       }

                       glEnd();

 

                       glPopMatrix();

 

 

 

                       //glPushMatrix();

                       //drawDisk(squareSize/2, squareSize/2, squareSize/2, COIN_COLOR);

                       //glEnd();

                       //glPopMatrix();

                }

        }

}

 

void drawPacman()

{

        glPushMatrix();

        glTranslatef(pacmanX, pacmanY, 0.f);

        glScalef(PACMAN_SCALE, PACMAN_SCALE, PACMAN_SCALE);

        MoveDir drawDir;

        //if pacman is moving, draw direction = move direction

        if (currentDir != NO_DIR)

        {

                drawDir = currentDir;

        }

        // otherwise, we draw the pacman in the direction of its last mocve

        else

        {

                drawDir = lastDir;

        }

 

        switch (drawDir)

        {

        case LEFT_DIR:

                glRotatef(180.f, 0.f, 0.f, 1.f);

                break;

 

        case UP_DIR:

                glRotatef(270.f, 0.f, 0.f, 1.f);

                break;

 

        case DOWN_DIR:

                glRotatef(90.f, 0.f, 0.f, 1.f);

                break;

 

        default:

                break;

 

        case RIGHT_DIR:

                glRotatef(0.f, 0.f, 0.f, 1.f);

                break;

        }

        //-------------------------------------------------

        //     Part 1:  Apply transformations (translation, scaling; typically in that

        //     order) to get to the object's reference frame.  Obviously, there is no

        //     rotation for a circle

        //-------------------------------------------------

        //     Translation coordinates are in "world units," defined (in the case of this program)

        //     by the call to gluOrtho2D in myResizeFunc() function below.

        //-------------------------------------------------

        //     Part 2:  Do the drawing in the object's own reference frame

        //-------------------------------------------------

        glColor3fv(PACMAN_COLOR);

        // draw bottom half

        glBegin(GL_POLYGON);

        glVertex2f(0, 0);

        for (unsigned int k = pacmanOpening; k <= NB_CIRCLE_PT / 2; k++)

        {

                glVertex2f(CIRCLE_PT[k][0], CIRCLE_PT[k][1]);

        }

        glEnd();

        // draw top half: same code after flipping y axis

        glScalef(1.f, -1.f, 1.f);

        glBegin(GL_POLYGON);

        glVertex2f(0, 0);

        for (unsigned int k = pacmanOpening; k <= NB_CIRCLE_PT / 2; k++)

        {

                glVertex2f(CIRCLE_PT[k][0], CIRCLE_PT[k][1]);

        }

        glEnd();

 

        glPopMatrix();

}

 

void drawCoin(int row, int col)

{

        GLfloat cx = (col + 0.5f) * squareSize;

        GLfloat cy = (row + 0.5f) * squareSize;

        drawDisk(cx, cy, COIN_SCALE, COIN_COLOR);

}

 

void drawLargeCoin(int row, int col)

{

        GLfloat cx = (col + 0.5f) * squareSize;

        GLfloat cy = (row + 0.5f) * squareSize;

        drawDisk(cx, cy, LARGE_COIN_SCALE, COIN_COLOR);

}

 

void initializeCoinList(void)

{

        // coinList.push_back(Coin{ 2, 1, true });

 

                // iterate over the entire grid (row by row, col by col

        for (int i = 0; i < NUM_ROWS; i++)

        {

                //     translate to the top of the window

                for (int j = 0; j < NUM_COLS; j++)

                {

                       //     for every grid square that is not some kind of wall, pushon coinList a new coin for that location

                       if (GRID[i][j] != 'I' && GRID[i][j] != 'C' && GRID[i][j] != 'S' && GRID[i][j] != 'B' && GRID[i][j] != 'H'

                               && GRID[i][j] != 'V' && GRID[i][j] != '1' && GRID[i][j] != '2' && GRID[i][j] != '3' && GRID[i][j] != '4')

                       {

                           coinList.push_back(Coin{i, j, true});

                       }

                }

        }

}

 

void displayTextualInfo(const string& infoStr, int pixelX, int pixelY, FontSize fontSize,

        bool drawbackgnd)

{

        //-----------------------------------------------

        //  0.  get current material properties

        //-----------------------------------------------

        float oldAmb[4], oldDif[4], oldSpec[4], oldShiny;

        glGetMaterialfv(GL_FRONT, GL_AMBIENT, oldAmb);

        glGetMaterialfv(GL_FRONT, GL_DIFFUSE, oldDif);

        glGetMaterialfv(GL_FRONT, GL_SPECULAR, oldSpec);

        glGetMaterialfv(GL_FRONT, GL_SHININESS, &oldShiny);

 

        glPushMatrix();

 

        //-----------------------------------------------

        //  1.  Build the string to display <-- parameter

        //-----------------------------------------------

        unsigned long infoLn = infoStr.length();

 

        //---------------------------------------------------------

        //  2.  Determine the string's length & height (in pixels)

        //---------------------------------------------------------

        void* FONT_CHOICE;

        int textWidth = 0, textHeight;

        switch (fontSize)

        {

        case TINY_FONT:

                textHeight = 16 + 2 * TEXT_VERT_PADDING;

                FONT_CHOICE = TINY_DISPLAY_FONT;

                break;

 

        case SMALL_FONT:

                textHeight = 18 + 2 * TEXT_VERT_PADDING;

                FONT_CHOICE = SMALL_DISPLAY_FONT;

                break;

 

        case MEDIUM_FONT:

                textHeight = 28 + 2 * TEXT_VERT_PADDING;

                FONT_CHOICE = MEDIUM_DISPLAY_FONT;

                break;

 

        case LARGE_FONT:

        default:

                textHeight = 32 + 2 * TEXT_VERT_PADDING;

                FONT_CHOICE = LARGE_DISPLAY_FONT;

                break;

        }

 

        for (unsigned long k = 0; k < infoLn; k++)

        {

                textWidth += glutBitmapWidth(FONT_CHOICE, infoStr[k]);

        }

 

        //  add horizontal padding on both sides

        textWidth += 2 * TEXT_HORIZ_PADDING;

 

        //-----------------------------------------------

        //  3.  If asked for, draw a background

        //-----------------------------------------------

        if (drawbackgnd)

        {

                glPushMatrix();

                glTranslatef(pixelX, pixelY - textHeight / 2, 0.f);

                glColor4fv(TEXT_BACKGND_COLOR);

                glBegin(GL_POLYGON);

                glVertex2f(0, 0);

                glVertex2f(0, textHeight);

                glVertex2f(textWidth, textHeight);

                glVertex2f(textWidth, 0);

                glEnd();

                glPopMatrix();

        }

 

        //-----------------------------------------------

        //  4.  Draw the string

        //-----------------------------------------------

        glColor4fv(TEXT_COLOR);

        glTranslatef(pixelX + TEXT_HORIZ_PADDING, pixelY + textHeight / 3, 0.f);

        int x = 0;

        for (unsigned long k = 0; k < infoLn; k++)

        {

                glRasterPos2i(x, 0);

                glutBitmapCharacter(FONT_CHOICE, infoStr[k]);

                x += glutBitmapWidth(FONT_CHOICE, infoStr[k]);

        }

 

        //-----------------------------------------------

        //  5.  Restore old material properties

        //-----------------------------------------------

        glMaterialfv(GL_FRONT, GL_AMBIENT, oldAmb);

        glMaterialfv(GL_FRONT, GL_DIFFUSE, oldDif);

        glMaterialfv(GL_FRONT, GL_SPECULAR, oldSpec);

        glMaterialf(GL_FRONT, GL_SHININESS, oldShiny);

 

        //-----------------------------------------------

        //  6.  Restore reference frame

        //-----------------------------------------------

        glPopMatrix();
}
