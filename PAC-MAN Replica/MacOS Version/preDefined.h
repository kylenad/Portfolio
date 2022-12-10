#ifndef PREDEFINED_H
#define PREDEFINED_H
using namespace std;

//--------------------------------------

// Custom data types

//--------------------------------------
typedef struct

{

        GLint row;

        GLint col;

        bool isPresent;

} Coin;

 

typedef enum

{

        NO_DIR,

        UP_DIR,

        DOWN_DIR,

        LEFT_DIR,

        RIGHT_DIR

} MoveDir;

 

using FontSize = enum

{

        TINY_FONT = 0,

        SMALL_FONT,

        MEDIUM_FONT,

        LARGE_FONT,

};






//--------------------------------------

//  Interface constants

//--------------------------------------


const GLfloat CIRCLE_PT32[32][2] = {

                                                              {1., 0.}, {0.980785, 0.19509}, {0.92388, 0.382683},

                                                              {0.83147, 0.55557}, {0.707107, 0.707107},

                                                              {0.55557, 0.83147}, {0.382683, 0.92388},

                                                              {0.19509, 0.980785}, {0., 1.}, {-0.19509, 0.980785},

                                                              {-0.382683, 0.92388}, {-0.55557, 0.83147},

                                                              {-0.707107, 0.707107}, {-0.83147, 0.55557},

                                                              {-0.92388, 0.382683}, {-0.980785, 0.19509}, {-1., 0.},

                                                              {-0.980785, -0.19509}, {-0.92388, -0.382683},

                                                              {-0.83147, -0.55557}, {-0.707107, -0.707107},

                                                              {-0.55557, -0.83147}, {-0.382683, -0.92388},

                                                              {-0.19509, -0.980785}, {0., -1.}, {0.19509, -0.980785},

                                                              {0.382683, -0.92388}, {0.55557, -0.83147},

                                                              {0.707107, -0.707107}, {0.83147, -0.55557},

                                                              {0.92388, -0.382683}, {0.980785, -0.19509} };


const unsigned int NB_CIRCLE_PT = 32;

#define CIRCLE_PT CIRCLE_PT32

 

#define TINY_DISPLAY_FONT        GLUT_BITMAP_HELVETICA_10

#define SMALL_DISPLAY_FONT        GLUT_BITMAP_HELVETICA_12

#define MEDIUM_DISPLAY_FONT        GLUT_BITMAP_HELVETICA_18

#define LARGE_DISPLAY_FONT        GLUT_BITMAP_TIMES_ROMAN_24

//     You can edit these

const GLfloat TEXT_COLOR[4] = { 1.f, 1.f, 1.f, 1.f };

const GLfloat TEXT_BACKGND_COLOR[4] = { 0.f, 0.f, 0.f, 0.f };

//     This defines the amount of "padding" of the backround box behind the

//     text

const int TEXT_HORIZ_PADDING = 10;

const int TEXT_VERT_PADDING = 10;


//-------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------





//--------------------------------------

//  Function prototypes

//--------------------------------------

void myDisplayFunc(void);

void myResizeFunc(int w, int h);

void myMouseFunc(int b, int s, int x, int y);

void myKeyboardFunc(unsigned char c, int x, int y);

void myTimerfunc(int val);

void checkCoinsAndPills(int col, int row);

void drawSquare(GLfloat cx, GLfloat cy, GLfloat angle, GLfloat scale, GLfloat r,

        GLfloat g, GLfloat b, bool contour);

void drawDisk(GLfloat cx, GLfloat cy, GLfloat scale, const GLfloat color[]);

void drawPacman();

void drawGhosts();

void drawCoin(int row, int coly);

void drawPill(int row, int coly);

void drawLargeCoin(int row, int col);

 

void initializeCoinList(void);

//NEW

//     pass the string to print out, x and y coordinates where to display it,

//     a font size (one of three allowed/supported), a scale factor, and

//     a bool indicated whether a colored box should be displayed below the text

//     (false by default)

void displayTextualInfo(const string& infoStr, int pixelX, int pixelY, FontSize fontSize,

        bool drawbackgnd = false);

 

void updateGhost(int ghostIndex);

void myAstarGhost();




//ghost coordinate information





#endif // PREDEFINED_H
