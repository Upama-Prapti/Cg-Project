#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdio>
#include<iostream>
#include<math.h>
#include <cmath>
#include<MMSystem.h>
#include <stdbool.h>
GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.02f;
float planeX = -0.5f;
const float MOVE_SPEED = 0.005f;
bool movePlane = false;
float cloudX = -0.5f;
const float CLOUD_SPEED = 0.002f;
bool moveCloud = false;
const int numRaindrops = 200; //  number of raindrops
float raindropX[numRaindrops];
float raindropY[numRaindrops];
float raindropSpeed[numRaindrops];
bool isRaining = false;
int rainDensity = 1;

float boatX = 0.0f;
float boatY = 0.0f;
float sinkProgress = 0.0f;
float angle1 = 0.0f;
bool isSinking = false;

bool showIntro = true;
int currentScene = 1;
bool isScene1SoundPlaying = false;

/****************************************************Oishis Part*************************************************/
GLfloat positioniao=0.0f;
GLfloat speediao = 0.05;
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}
void display3()
{


    glClear(GL_COLOR_BUFFER_BIT);

    /** set the window**/
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(50, 50, 30, 30);  // 4:3 coordinate view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.7, 0.8, 0.9);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 1.0);
    glVertex2f(0.8, 1.0);
    glVertex2f(0.8, 0.2);
    glVertex2f(-0.8,0.2);
    glEnd();

    glColor3f(0.1, 0.6, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.2);
    glVertex2f(0.0, 0.2);
    glVertex2f(-0.2, -1.0);
    glVertex2f(-0.8,-1.0);
    glEnd();
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.2);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.8,-1.0);
    glVertex2f(-0.2,-1.0);
    glEnd();

    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.8, -0.6);
    glVertex2f(0.8, -1.0);
    glVertex2f(0.6,-1.0);
    glEnd();

    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.8, -0.2);
    glVertex2f(0.8, -0.6);
    glVertex2f(0.6,-0.6);
    glEnd();

    glColor3f(1.0, 0.8, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.8, -0.2);
    glVertex2f(0.6,-0.2);
    glEnd();

    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.8, 0.6);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.6,0.2);
    glEnd();

    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.28, 0.78);
    glVertex2f(0.6, 0.9);
    glVertex2f(0.8, 0.9);
    glVertex2f(0.8,0.6);
    glVertex2f (0.28, 0.6);
    glEnd();

    glColor3f(0.5, 0.4, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.14, 0.4);
    glVertex2f(0.28, 0.56);
    glVertex2f(0.6, 0.56);
    glVertex2f(0.6,0.2);
    glVertex2f (0.14, 0.2);
    glEnd();


    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.14, 0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.14,-0.06);
    glEnd();


    glColor3f(0.5, 0.4, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.14, -0.06);
    glVertex2f(0.6, -0.1);
    glVertex2f(0.6, -0.36);
    glVertex2f(0.14,-0.26);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.6, 0.9);
    glVertex2f(0.6, -1.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, 0.56);
    glVertex2f(0.28, -0.3);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.14, -0.26);
    glVertex2f(0.6, -0.36);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, 0.78);
    glVertex2f(0.6, 0.9);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.6, 0.9);
    glVertex2f(0.8, 0.9);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, 0.6);
    glVertex2f(0.8, 0.6);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.14, 0.4);
    glVertex2f(0.14, -0.26);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, 0.78);
    glVertex2f(0.28, 0.6);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.14, 0.2);
    glVertex2f(0.8, 0.2);
    glEnd();



    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.14, 0.4);
    glVertex2f(0.28, 0.56);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, 0.56);
    glVertex2f(0.6, 0.56);
    glEnd();



    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.14, -0.06);
    glVertex2f(0.6, -0.1);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.8, -0.2);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.8, -0.6);
    glEnd();


    glColor3f(1.1, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.18, 0.6);
    glVertex2f(0.6, 0.6);
    glVertex2f(0.6, 0.56);
    glVertex2f(-0.18,0.56);
    glEnd();


    glColor3f(1.1, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.98);
    glVertex2f(0.04, 0.98);
    glVertex2f(0.04, 0.0);
    glVertex2f(0.0,0.0);
    glEnd();

    glPushMatrix();
    glTranslatef(positioniao,0.0f,0.0f);
    glColor3f(0.9, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.36, 0.66);
    glVertex2f(0.5, 0.66);
    glVertex2f(0.5, 0.6);
    glVertex2f(0.36,0.6);
    glEnd();
    glPopMatrix();


    glColor3f(0.6, 0.4, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.28, -0.5);
    glVertex2f(0.28, -0.3);
    glVertex2f(0.6, -0.36);
    glVertex2f(0.6,-0.6);
    glEnd();


    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(0.28, -0.8);
    glVertex2f(0.28, -0.5);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.6,-1.0);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, -0.3);
    glVertex2f(0.28, -0.8);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, -0.5);
    glVertex2f(0.6, -0.6);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.28, -0.8);
    glVertex2f(0.6, -1.0);
    glEnd();


    glColor3f(1.1, 0.9, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(0.04, -0.54);
    glVertex2f(0.04, -0.34);
    glVertex2f(0.1, -0.34);
    glVertex2f(0.1,-54);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.04, -0.4);
    glVertex2f(0.1, -0.4);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.04, -0.54);
    glVertex2f(0.1, -0.54);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.04, -0.74);
    glVertex2f(0.1, -0.74);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.04, -0.94);
    glVertex2f(0.1, -0.94);
    glEnd();



    glColor3f(0.6, 0.1, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.58, -0.1);
    glVertex2f(-0.56, -0.04);
    glVertex2f(-0.2, -0.1);
    glEnd();

    glColor3f(0.8, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.64, 0.38);
    glVertex2f(-0.64, 0.52);
    glVertex2f(-0.1, 0.52);
    glVertex2f(-0.1,0.36);
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.56, -0.04);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.08, 0.34);
    glVertex2f(-0.4,0.52);
    glVertex2f (-0.66, 0.36);
    glVertex2f(-0.52,0.12);
    glEnd();


    glColor3f(0.7, 0.5, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, 0.52);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.18, 0.6);
    glVertex2f(-0.18,0.52);
    glEnd();


    glColor3f(0.1, 0.2, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(-0.18, 0.52);
    glVertex2f(-0.18, 0.58);
    glVertex2f(-0.12, 0.58);
    glVertex2f(-0.12,0.52);
    glEnd();

    glColor3f(0.1, 0.2, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(-0.56, 0.6);
    glVertex2f(-0.56, 0.66);
    glVertex2f(-0.32, 0.66);
    glVertex2f(-0.32,0.6);
    glEnd();

    glColor3f(0.0, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, 0.6);
    glVertex2f(-0.32, 0.7);
    glVertex2f(-0.28, 0.7);
    glVertex2f(-0.28,0.6);
    glEnd();



    glColor3f(0.9, 0.2, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.28, 0.6);
    glVertex2f(-0.28, 0.66);
    glVertex2f(-0.22, 0.66);
    glVertex2f(-0.22,0.6);
    glEnd();



    glColor3f(0.6, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.66);
    glVertex2f(-0.5, 0.7);
    glVertex2f(-0.32, 0.7);
    glVertex2f(-0.32,0.66);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.8);
    glVertex2f(-0.4, 0.7);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.42, 0.8);
    glVertex2f(-0.4, 0.84);
    glVertex2f(-0.38, 0.8);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.4, 0.76);
    glVertex2f(-0.4, 0.78);
    glVertex2f(-0.38, 0.78);
    glVertex2f(-0.38,0.76);
    glEnd();



    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.42, 0.74);
    glVertex2f(-0.42, 0.76);
    glVertex2f(-0.4, 0.76);
    glVertex2f(-0.4,0.74);
    glEnd();



    glColor3f(1.1, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.36, 0.7);
    glVertex2f(-0.38, 0.7);
    glVertex2f(-0.0, 0.92);
    glVertex2f(-0.0,0.9);
    glEnd();

    glColor3f(1.1, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.92);
    glVertex2f(0.0, 0.94);
    glVertex2f(0.48, 0.66);
    glVertex2f(0.46,0.66);
    glEnd();

    glColor3f(1.1, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.22, 0.6);
    glVertex2f(-0.22, 0.64);
    glVertex2f(-0.0, 0.92);
    glVertex2f(-0.0,0.9);
    glEnd();


    glColor3f(1.1, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.9);
    glVertex2f(0.0, 0.92);
    glVertex2f(0.28, 0.6);
    glVertex2f(0.26,0.6);
    glEnd();

    glColor3f(1.1, 1.1, 1.1);
    glBegin(GL_LINES);
    glVertex2f(-0.66, 0.36);
    glVertex2f(-0.4, 0.52);
    glEnd();

    glColor3f(1.1, 1.1, 1.1);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.52);
    glVertex2f(-0.08, 0.34);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.16, -0.26);
    glVertex2f(0.16,- 0.74);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.24, -0.28);
    glVertex2f(0.24,- 0.58);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.42, -0.32);
    glVertex2f(0.42,- 0.96);
    glEnd();


    glFlush();
}

void updateiao(int value)

{

    if(positioniao < -0.55)

        positioniao = 0.16f;



    positioniao -= speediao;



    glutPostRedisplay();

    glutTimerFunc(100, updateiao, 0);

}



/***************************************************Turjos Part**************************************************/

// Ship position
float shipX = -1.2f;
float shipSpeed = 0.002f;
bool moveRight = true;


// Bird positions
GLfloat bird1X = -1.0f;
GLfloat bird2X = -1.3f;
GLfloat bird3X = -1.6f;
GLfloat birdY = 0.85f;
GLfloat birdSpeed = 0.003f;

// Position variables
GLfloat positionX = 0.0f;
GLfloat positionY = 0.0f;
GLfloat step = 0.05f;  // Movement step size


// Cloud positions and speed
GLfloat bigCloud1X = -0.8f, bigCloud1Y = 0.8f;
GLfloat bigCloud2X = 0.3f,  bigCloud2Y = 0.7f;
GLfloat tinyCloud1X = -0.4f, tinyCloud1Y = 0.4f;
GLfloat tinyCloud2X = 0.6f,  tinyCloud2Y = 0.3f;

GLfloat cloudSpeed = 0.005f;



// Timer update function

void updatet(int value)
{
    // Move clouds right
    bigCloud1X += cloudSpeed;
    bigCloud2X += cloudSpeed;
    tinyCloud1X += cloudSpeed;
    tinyCloud2X += cloudSpeed;

    // Wrap around when off right edge
    if (bigCloud1X > 1.2f) bigCloud1X = -1.6f;
    if (bigCloud2X > 1.2f) bigCloud2X = -1.6f;
    if (tinyCloud1X > 1.2f) tinyCloud1X = -1.6f;
    if (tinyCloud2X > 1.2f) tinyCloud2X = -1.6f;

    // For bird
    bird1X += birdSpeed;
    bird2X += birdSpeed;
    bird3X += birdSpeed;

    if (bird1X > 1.2f) bird1X = -1.2f;
    if (bird2X > 1.2f) bird2X = -1.2f;
    if (bird3X > 1.2f) bird3X = -1.2f;

    // For ship
    if (moveRight)
    {
        shipX += shipSpeed;
        if (shipX > 1.2f)
            shipX = -1.2f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updatet, 0);  // ~60fps
}

// Function to draw a circle at (cx, cy) with given radius and segments
void drawCircle(float cx, float cy, float radius, int segments = 100)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++)
    {
        float angle = i * 2.0f * 3.1415926f / segments;
        float x = cx + radius * cosf(angle);
        float y = cy + radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Draw one cloud made of overlapping circles
void drawCloud(float x, float y, float bigRadius, float tinyRadius)
{
    drawCircle(x, y, bigRadius);
    drawCircle(x + bigRadius * 0.8f, y + bigRadius * 0.3f, bigRadius);
    drawCircle(x + bigRadius * 1.6f, y, bigRadius);

    drawCircle(x + bigRadius * 0.4f, y + bigRadius * 0.8f, tinyRadius);
    drawCircle(x + bigRadius * 1.2f, y + bigRadius * 0.8f, tinyRadius);
}

//draw bird

void drawBird(GLfloat x, GLfloat y)
{
    glBegin(GL_LINES);
    glVertex2f(x - 0.02f, y);
    glVertex2f(x, y + 0.02f);

    glVertex2f(x, y + 0.02f);
    glVertex2f(x + 0.02f, y);
    glEnd();
}

// Ship body


void drawCargoShip()
{

    glColor3f(0.3f, 0.3f, 0.3f);  // Dark gray hull
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f, -0.05f);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.35f, -0.1f);
    glVertex2f(-0.35f, -0.1f);
    glEnd();

    // Deckhouse
    glColor3f(0.7f, 0.7f, 0.7f);  // Light gray
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.25f, 0.05f);
    glVertex2f(0.25f, -0.05f);
    glVertex2f(0.1f, -0.05f);
    glEnd();

    // Antenna/Mast
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark line
    glBegin(GL_LINES);
    glVertex2f(0.18f, 0.05f);
    glVertex2f(0.18f, 0.12f);
    glEnd();

    // Cargo containers
    glColor3f(0.9f, 0.3f, 0.2f);  // Red
    glBegin(GL_QUADS);
    glVertex2f(-0.35f, 0.05f);
    glVertex2f(-0.25f, 0.05f);
    glVertex2f(-0.25f, -0.05f);
    glVertex2f(-0.35f, -0.05f);
    glEnd();

    glColor3f(0.2f, 0.6f, 1.0f);  // Blue
    glBegin(GL_QUADS);
    glVertex2f(-0.22f, 0.05f);
    glVertex2f(-0.12f, 0.05f);
    glVertex2f(-0.12f, -0.05f);
    glVertex2f(-0.22f, -0.05f);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.4f);  // Green
    glBegin(GL_QUADS);
    glVertex2f(-0.09f, 0.05f);
    glVertex2f(0.01f, 0.05f);
    glVertex2f(0.01f, -0.05f);
    glVertex2f(-0.09f, -0.05f);
    glEnd();
}




// Display callback function
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);         // Clear screen with background color
    /** set the window**/
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(50, 50, 30, 30);  // 4:3 coordinate view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Clear screen with background color

    // Draw ash ground
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.45f);
    glEnd();


// Draw water

    glColor3f(0.0f, 0.2f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.45f);
    glVertex2f(-1.0f, -0.45f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();

// Draw sky

    glColor3f(0.53f, 0.81f, 0.92f);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f, 1.0f);   // Top Left
    glVertex2f(1.0f, 1.0f);    // Top Right
    glVertex2f(1.0f, -0.1f);   // Bottom Right
    glVertex2f(-1.0f, -0.1f);  // Bottom Left

    glEnd();

// Draw ship
    glPushMatrix();
    glTranslatef(shipX, 0.00f, 0.0f);
    drawCargoShip();
    glPopMatrix();


// Draw circle as sun at (-0.75, 0.78)
    glColor3f(1.0f, 0.65f, 0.0f);

    float radius = 0.1f;
    float cx = -0.75f;
    float cy = 0.78f;
    const int triangleAmount = 400;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);  // Center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        float angle = i * 2.0f * (float)M_PI / triangleAmount;
        float x = cx + radius * cosf(angle);
        float y = cy + radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();



//draw cloude
    glColor3f(1.0f, 1.0f, 1.0f); // white clouds
    drawCloud(bigCloud1X, bigCloud1Y, 0.15f, 0.07f);
    drawCloud(bigCloud2X, bigCloud2Y, 0.15f, 0.07f);
    drawCloud(tinyCloud1X, tinyCloud1Y, 0.08f, 0.04f);
    drawCloud(tinyCloud2X, tinyCloud2Y, 0.08f, 0.04f);


//draw stand
    glColor3f(1.0f, 0.85f, 0.2f);

    // Draw vertical yellow quad
    glBegin(GL_QUADS);
    glVertex2f(0.65f, 1.0f);
    glVertex2f(0.68f, 1.0f);
    glVertex2f(0.68f, -0.45f);
    glVertex2f(0.65f, -0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.68f, 0.65f);
    glVertex2f(1.0f, 0.65f);
    glVertex2f(1.0f, 0.55f);
    glVertex2f(0.68f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.68f, -0.01f);
    glVertex2f(1.0f, -0.01f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(0.68f, -0.1f);
    glEnd();

//cross 1
    glBegin(GL_QUADS);
    glVertex2f(0.75f, 1.0f);
    glVertex2f(0.80f, 1.0f);
    glVertex2f(1.0f, 0.8f);
    glVertex2f(1.0f, 0.75f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.85f, 1.0f);  // Bottom-left
    glVertex2f(0.90f, 1.0f);  // Bottom-right
    glVertex2f(0.65f, 0.75f);   // Top-right
    glVertex2f(0.65f, 0.80f);   // Top-left
    glEnd();


//cross 2

    glBegin(GL_QUADS);
    glVertex2f(1.0f, 0.45f);
    glVertex2f(1.0f, 0.40f);
    glVertex2f(0.68f, 0.1f);
    glVertex2f(0.68f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(1.0f, 0.05f);
    glVertex2f(0.68f, 0.45f);
    glVertex2f(0.68f, 0.40f);
    glEnd();

// White color for birds
    glColor3f(1.0f, 1.0f, 1.0f);
    drawBird(bird1X, birdY);
    drawBird(bird2X, birdY + 0.02f);
    drawBird(bird3X, birdY - 0.02f);



// Define container body 1

    float left = -0.65f, right = 0.0f;
    float top = -0.3f, bottom = -0.7f;

    // Number of vertical stripes
    int stripeCount = 20;
    float stripeWidth = (right - left) / stripeCount;

    for (int i = 0; i < stripeCount; ++i)
    {
        // Alternate between light orange and dark orange
        if (i % 2 == 0)
            glColor3f(1.0f, 0.7f, 0.3f);  // Light orange
        else
            glColor3f(0.9f, 0.4f, 0.0f);  // Dark orange

        float xLeft = left + i * stripeWidth;
        float xRight = xLeft + stripeWidth;

        glBegin(GL_QUADS);
        glVertex2f(xLeft, top);
        glVertex2f(xRight, top);
        glVertex2f(xRight, bottom);
        glVertex2f(xLeft, bottom);
        glEnd();
    }

// ----------- Middle Container (Wood Stripes using translation) -----------
    glPushMatrix();
    glTranslatef(-0.35, 0.4, 0.0) ;

    {
        float left = -0.6f, right = -0.1f;
        float top = -0.3f, bottom = -0.7f;

        int stripeCount = 20;
        float stripeWidth = (right - left) / stripeCount;

        for (int i = 0; i < stripeCount; ++i)
        {
            if (i % 2 == 0)
                glColor3f(0.76f, 0.60f, 0.42f);  // Light wood
            else
                glColor3f(0.52f, 0.37f, 0.26f);  // Dark wood

            float xLeft = left + i * stripeWidth;
            float xRight = xLeft + stripeWidth;

            glBegin(GL_QUADS);
            glVertex2f(xLeft, top);
            glVertex2f(xRight, top);
            glVertex2f(xRight, bottom);
            glVertex2f(xLeft, bottom);
            glEnd();
        }
    }

    glPopMatrix();


    // ----------- New Container (Left, Blue Stripes using translation) -----------
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.0f); // Translate leftward

    {
        float left = 0.0f, right = 0.35f;
        float top = -0.3f, bottom = -0.7f;
        int stripeCount = 20;
        float stripeWidth = (right - left) / stripeCount;

        for (int i = 0; i < stripeCount; ++i)
        {
            if (i % 2 == 0)
                glColor3f(0.4f, 0.6f, 1.0f);  // Light blue
            else
                glColor3f(0.0f, 0.0f, 0.5f);  // Deep blue

            float xLeft = left + i * stripeWidth;
            float xRight = xLeft + stripeWidth;

            glBegin(GL_QUADS);
            glVertex2f(xLeft, top);
            glVertex2f(xRight, top);
            glVertex2f(xRight, bottom);
            glVertex2f(xLeft, bottom);
            glEnd();
        }
    }

    glPopMatrix();


// ----------- New Container (Right, Aqua Stripes) -----------
    glPushMatrix();

    {
        float left = 0.5f, right = 1.0f;
        float top = -0.2f, bottom = -0.6f;
        int stripeCount = 20;
        float stripeWidth = (right - left) / stripeCount;

        for (int i = 0; i < stripeCount; ++i)
        {
            if (i % 2 == 0)
                glColor3f(0.5f, 1.0f, 1.0f);  // Aqua (light cyan)
            else
                glColor3f(0.0f, 0.5f, 0.5f);  // Dark aqua (teal)

            float xLeft = left + i * stripeWidth;
            float xRight = xLeft + stripeWidth;

            glBegin(GL_QUADS);
            glVertex2f(xLeft, top);
            glVertex2f(xRight, top);
            glVertex2f(xRight, bottom);
            glVertex2f(xLeft, bottom);
            glEnd();
        }
    }

    glPopMatrix();


// ----------- New Container (Right, Yellow Stripes) -----------
    glPushMatrix();

    {
        float left = 0.05f, right = 0.8f;
        float top = -0.37f, bottom = -0.8f;
        int stripeCount = 20;
        float stripeWidth = (right - left) / stripeCount;

        for (int i = 0; i < stripeCount; ++i)
        {
            if (i % 2 == 0)
                glColor3f(1.0f, 1.0f, 0.2f);  // Yellow
            else
                glColor3f(0.8f, 0.8f, 0.0f);  // Dark yellow

            float xLeft = left + i * stripeWidth;
            float xRight = xLeft + stripeWidth;

            glBegin(GL_QUADS);
            glVertex2f(xLeft, top);
            glVertex2f(xRight, top);
            glVertex2f(xRight, bottom);
            glVertex2f(xLeft, bottom);
            glEnd();
        }
    }

    glPopMatrix();

////////////////////////////make animation container///////////////////////

    glLoadIdentity();

    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);

    // ----------- Maroon stripes container -----------
    {
        float left = 0.05f, right = 0.8f;
        float top = 0.3f, bottom = -0.15f;
        int stripeCount = 20;
        float stripeWidth = (right - left) / stripeCount;

        for (int i = 0; i < stripeCount; ++i)
        {
            if (i % 2 == 0)
                glColor3f(0.5f, 0.0f, 0.0f);  // Maroon
            else
                glColor3f(0.3f, 0.0f, 0.0f);  // Dark Maroon

            float xLeft = left + i * stripeWidth;
            float xRight = xLeft + stripeWidth;

            glBegin(GL_QUADS);
            glVertex2f(xLeft, top);
            glVertex2f(xRight, top);
            glVertex2f(xRight, bottom);
            glVertex2f(xLeft, bottom);
            glEnd();
        }
    }

    // ----------- Orange-yellow polygon -----------
    glColor3f(1.0f, 0.75f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.53f, 0.87f);
    glVertex2f(0.5f, 0.7f);
    glVertex2f(0.45f, 0.7f);
    glVertex2f(0.42f, 0.87f);
    glVertex2f(0.45f, 0.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.49f, 0.7f);
    glVertex2f(0.49f, 0.67f);
    glVertex2f(0.53f, 0.67f);
    glVertex2f(0.53f, 0.65f);
    glVertex2f(0.46f, 0.65f);
    glVertex2f(0.46f, 0.7f);
    glEnd();

    // ----------- Black lines -----------
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.45f, 2.0f);
    glVertex2f(0.45f, 0.9f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.5f, 2.0f);
    glVertex2f(0.5f, 0.9f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.46f, 0.7f);
    glVertex2f(0.05f, 0.3f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.49f, 0.7f);
    glVertex2f(0.8f, 0.3f);
    glEnd();

    glPopMatrix();


    glFlush();                            // Render now
}



/***************************************************Sadias Part*************************************************/
/***************************************************Sadias Part*************************************************/
# define PI 3.14159265358979323846
GLfloat positionp = 0.0f;
GLfloat positiont = 0.0f;
GLfloat speedc = 0.05f;
/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display5()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int i;

    GLfloat x=0.0f;
    GLfloat y=0.4f;
    GLfloat radius =.05f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI; // Clear the color buffer with current clearing color

    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.529f, 0.808f, 0.980f); // cyan
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);

    glEnd();

    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.921f, 0.356f, 0.204f); // cyan
    glVertex2f(-0.5f, 0.3f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, 0.3f);

    glEnd();
    glColor3f(0.6f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPushMatrix();
    glTranslatef(positionp, 0.0f, 0.0f);
    glBegin(GL_QUADS); //ship1 body; // These vertices form a closed polygon
    glColor3f(0.1f, 0.0f, 0.0f); // cyan
    glVertex2f(-0.35f, -0.05f);
    glVertex2f(-.35f, 0.0f);
    glVertex2f(0.05f, 0.05f);
    glVertex2f(0.05f, -0.1f);

    glEnd();

    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 0.1f, 0.0f); // cyan
    glVertex2f(-0.28f, 0.0f);
    glVertex2f(-.28f, 0.13f);
    glVertex2f(-0.27f, 0.12f);
    glVertex2f(-0.27f, 0.0f);

    glEnd();

    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(1.0f, 0.0f, 0.0f); // cyan
    glVertex2f(-0.319f, 0.0f);
    glVertex2f(-.28f, 0.09f);
    glVertex2f(-0.28f, 0.08f);
    glVertex2f(-0.27f, 0.0f);

    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(1.0f, 0.0f, 0.0f); // cyan
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-.27f, 0.08f);
    glVertex2f(-0.27f, 0.07f);
    glVertex2f(-0.24f, 0.02f);

    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.1f); // cyan
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-.24f, 0.1f);
    glVertex2f(-0.2f, 0.12f);
    glVertex2f(-0.2f, 0.0f);

    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 1.0f, 0.f); // cyan
    glVertex2f(-0.24f, 0.072f);
    glVertex2f(-.24f, 0.1f);
    glVertex2f(-0.2f, 0.12f);
    glVertex2f(-0.2f, 0.09f);

    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 1.0f); // cyan
    glVertex2f(-0.19f, 0.072f);
    glVertex2f(-.19f, 0.14f);
    glVertex2f(-0.16f, 0.16f);
    glVertex2f(-0.16f, 0.03f);

    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 1.0f, 0.0f); // cyan
    glVertex2f(-0.19f, 0.12f);
    glVertex2f(-.19f, 0.14f);
    glVertex2f(-0.16f, 0.16f);
    glVertex2f(-0.16f, 0.14f);

    glEnd();

    glBegin(GL_POLYGON); // These vertices form a closed polygon
    glColor3f(1.0f, .0f, 0.0f); // cyan
    glVertex2f(-0.19f, 0.0f);
    glVertex2f(-.19f, 0.01f);
    glVertex2f(-0.18f, 0.01f);
    glVertex2f(-0.18f, 0.02f);
    glVertex2f(-0.17f, 0.02f);
    glVertex2f(-0.17f, 0.03f);
    glVertex2f(-0.12f, 0.03f);
    glVertex2f(-0.12f, 0.02f);
    glVertex2f(-0.11f, 0.02f);
    glVertex2f(-0.11f, 0.01f);
    glVertex2f(-0.1f, 0.01f);
    glVertex2f(-0.1f, 0.0f);

    glEnd();

    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.1f); // cyan
    glVertex2f(-0.14f, 0.03f);
    glVertex2f(-.14f, 0.19f);
    glVertex2f(-0.11f, 0.21f);
    glVertex2f(-0.11f, 0.02f);

    glEnd();

    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 1.0f, 0.0f); // cyan
    glVertex2f(-0.14f, 0.16f);
    glVertex2f(-.14f, 0.19f);
    glVertex2f(-0.11f, 0.21f);
    glVertex2f(-0.11f, 0.19f);

    glEnd();//ship 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(positiont, 0.0f, 0.0f);
    glBegin(GL_QUADS); //ship2 body; // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // cyan
    glVertex2f(-0.35f, 0.25f);
    glVertex2f(-.35f, 0.29f);
    glVertex2f(-0.18f, 0.32f);
    glVertex2f(-0.18f, 0.24f);

    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 1.0f, 0.0f); // cyan
    glVertex2f(-0.3f, 0.275f);
    glVertex2f(-.3f, 0.275f);
    glVertex2f(-0.19f, 0.31f);
    glVertex2f(-0.19f, 0.3f);

    glEnd();
    glBegin(GL_POLYGON); // These vertices form a closed polygon
    glColor3f(01.0f, 0.0f, 0.0f); // cyan
    glVertex2f(-0.31f, 0.278f);
    glVertex2f(-.31f, 0.29f);
    glVertex2f(-0.18f, 0.29f);
    glVertex2f(-0.27f, 0.29f);
    glVertex2f(-0.27f, 0.31f);
    glVertex2f(-0.22f, 0.31f);
    glVertex2f(-0.22f, 0.3f);
    glEnd();
    glBegin(GL_QUADS); // These vertices form a closed polygon
    glColor3f(0.0f, 1.0f, 0.0f); // cyan
    glVertex2f(-0.25f, 0.31f);
    glVertex2f(-.25f, 0.38f);
    glVertex2f(-0.24f, 0.38f);
    glVertex2f(-0.24f, 0.31f);

    glEnd();
    glPopMatrix();
    glFlush(); // Render now
}
void updatex(int value)
{
    if(positionp < -0.4)
        positionp = 0.4f;

    if(positiont > 0.4)
        positiont = -0.4f;


    positionp -= speedc;
    positiont += speedc;

    glutPostRedisplay();
    glutTimerFunc(300, updatex, 0);
}
void updatey(int value)
{
    if(positionp > 0.5)
        positionp = -0.5f;

    if(positiont < -0.4)
        positiont = 0.4f;


    positionp += speedc;
    positiont -= speedc;

    glutPostRedisplay();
    glutTimerFunc(300, updatey, 0);
}
/*******************************************Airins Part**********************************************************/

/*******************************************Airins Part**********************************************************/


float positionx = 0.1f;
float speedx = 0.01f;

void display4()
{
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2);

    glBegin(GL_QUADS);//sky
    glColor3f(0.42f, 0.54f, 0.85f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.05f);
    glVertex2f(-0.5f, -0.05f);

    glEnd();


    glBegin(GL_QUADS);//sea
    glColor3f(0.12f, 0.31f, 0.44f);
    glVertex2f(-0.5f, -0.05f);
    glVertex2f(0.5f, -0.05f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);

    glEnd();

    glPushMatrix();
    glTranslatef(positionx, 0.0f, 0.0f);
    glBegin(GL_QUADS);//red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.21f, -0.09f);
    glVertex2f(0.4f, -0.09f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(-0.21f, -0.1f);

    glEnd();


    glBegin(GL_QUADS); //black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.25f, -0.05f);
    glVertex2f(0.4f, -0.05f);
    glVertex2f(0.4f, -0.09f);
    glVertex2f(-0.21f, -0.09f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f,-0.05f);
    glVertex2f(-0.25f, -0.05f);

    glEnd();


    glBegin(GL_QUADS);//blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.35f, 0.05f);
    glVertex2f(-0.29f, 0.05f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.3f, 0.0f);

    glEnd();



    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(0.1f, 0.45f);
    glVertex2f(0.1f, 0.03f);
    glVertex2f(0.05f, 0.03f);
    glVertex2f(0.05f, 0.45f);

    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.0f, 0.31f);//black
    glVertex2f(0.05f, 0.4f);//black
    glVertex2f(0.01f, 0.31f);
    glVertex2f(0.05f, 0.42f);//black
    glVertex2f(0.1f, 0.28f);
    glVertex2f(-0.25f, 0.41f);//black
    glVertex2f(-0.23f, 0.41f);
    glVertex2f(0.05f, 0.45f);
    glVertex2f(-0.22f, 0.4f);
    glVertex2f(0.08f, 0.45f);//black
    glVertex2f(0.05f, 0.44f);//black
    glVertex2f(-0.24f,0.31f);
    glVertex2f(-0.24f,0.33f);
    glVertex2f(0.05f, 0.4f);//black
    glVertex2f(0.1f, 0.4f);//black
    glVertex2f(0.05f, 0.35f);//black
    glVertex2f(0.1f, 0.35f);//black





    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.19f, 0.03f);//red
    glVertex2f(0.4f, 0.03f);//red
    glVertex2f(-0.19f, 0.02f);//red
    glVertex2f(0.4f, 0.02f);
    glVertex2f(-0.19f, 0.017f);
    glVertex2f(0.4f, 0.01f);//red
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(-0.15f, 0.03f);
    glVertex2f(-0.05f,0.0f);
    glVertex2f(-0.05f, 0.03f);
    glVertex2f(0.05f, 0.0f);
    glVertex2f(0.05f, 0.03f);
    glVertex2f(0.15f, 0.0f);
    glVertex2f(0.15f, 0.03f);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.25f, 0.03f);
    glVertex2f(0.35f, 0.0f);//red
    glVertex2f(0.35f, 0.03f);//red

    glVertex2f(-0.23f, 0.41f);//red
    glVertex2f(0.1f, 0.27f);//red
    glVertex2f(-0.23f, 0.39f);
    glVertex2f(0.05f, 0.26f);
    glVertex2f(-0.23f, 0.37f);
    glVertex2f(0.05f, 0.25f);
    glVertex2f(-0.23f, 0.36f);//red

    glVertex2f(-0.28f, 0.23f);//red
    glVertex2f(-0.15f, 0.16f);//red

    glEnd();


    glBegin(GL_QUADS); //green
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(0.21f, 0.15f);
    glVertex2f(0.4f, 0.15f);
    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.21f, 0.1f);

    glEnd();


    glBegin(GL_QUADS);//red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(0.21f, 0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.21f, 0.05f);

    glEnd();

    glBegin(GL_QUADS);//green
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.05f, 0.2f);
    glVertex2f(-0.05f, 0.17f);
    glVertex2f(-0.1f, 0.17f);

    glEnd();

    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.05f, 0.2f);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(0.0f, 0.15f);
    glVertex2f(-0.05f, 0.15f);

    glEnd();

    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.1f, 0.17f);
    glVertex2f(-0.05f, 0.17f);
    glVertex2f(-0.05f, 0.13f);
    glVertex2f(-0.1f, 0.13f);

    glEnd();


    glBegin(GL_QUADS); //green
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(-0.05f, 0.15f);
    glVertex2f(0.0f, 0.15f);
    glVertex2f(0.0f, 0.11f);
    glVertex2f(-0.05f, 0.11f);

    glEnd();


    glBegin(GL_QUADS);//blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.05f, 0.11f);
    glVertex2f(0.0f, 0.11f);
    glVertex2f(0.0f, 0.07f);
    glVertex2f(-0.05f, 0.07f);

    glEnd();


    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.1f, 0.13f);
    glVertex2f(-0.05f, 0.13f);
    glVertex2f(-0.05f, 0.07f);
    glVertex2f(-0.1f, 0.07f);

    glEnd();


    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.15f, 0.16f);
    glVertex2f(-0.1f, 0.16f);
    glVertex2f(-0.1f, 0.12f);
    glVertex2f(-0.15f, 0.12f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.15f, 0.12f);
    glVertex2f(-0.1f, 0.12f);
    glVertex2f(-0.1f, 0.07f);
    glVertex2f(-0.15f, 0.07f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.2f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glVertex2f(-0.15f, 0.12f);
    glVertex2f(-0.2f, 0.12f);

    glEnd();


    glBegin(GL_QUADS); //yellow
    glColor3f(0.83f, 0.51f, 0.1f);
    glVertex2f(-0.19f, 0.12f);
    glVertex2f(-0.15f, 0.12f);
    glVertex2f(-0.15f, 0.07f);
    glVertex2f(-0.19f, 0.07f);

    glEnd();


    glBegin(GL_QUADS); //green
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(-0.25f, 0.12f);
    glVertex2f(-0.19f, 0.12f);
    glVertex2f(-0.19f, 0.07f);
    glVertex2f(-0.25f, 0.07f);

    glEnd();


    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.25f, 0.07f);
    glVertex2f(-0.19f, 0.07f);
    glVertex2f(-0.19f, 0.04f);
    glVertex2f(-0.25f, 0.04f);

    glEnd();


    glBegin(GL_QUADS); //green
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(-0.19f, 0.07f);
    glVertex2f(-0.1f, 0.07f);
    glVertex2f(-0.1f, 0.04f);
    glVertex2f(-0.19f, 0.04f);

    glEnd();//box


    glBegin(GL_QUADS); //black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.25f, 0.04f);
    glVertex2f(-0.2f, 0.04f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.25f, 0.03f);

    glEnd();


    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.34f, 0.12f);
    glVertex2f(-0.26f, 0.12f);
    glVertex2f(-0.26f, 0.09f);
    glVertex2f(-0.34f, 0.09f);

    glEnd();


    glBegin(GL_QUADS); //green
    glColor3f(0.2f, 0.5f, 0.2f);
    glVertex2f(-0.34f, 0.09f);
    glVertex2f(-0.26f, 0.09f);
    glVertex2f(-0.26f, 0.06f);
    glVertex2f(-0.34f, 0.06f);

    glEnd();


    glBegin(GL_QUADS); //black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.19f, 0.04f);
    glVertex2f(-0.11f, 0.04f);
    glVertex2f(-0.11f, 0.03f);
    glVertex2f(-0.19f, 0.03f);

    glEnd();


    glBegin(GL_QUADS);//black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.1f, 0.04f);
    glVertex2f(-0.01f, 0.04f);
    glVertex2f(-0.01f, 0.03f);
    glVertex2f(-0.1f, 0.03f);

    glEnd();


    glBegin(GL_QUADS);//red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.22f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.2f, 0.12f);
    glVertex2f(-0.22f, 0.12f);

    glEnd();


    glBegin(GL_QUADS);//red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.24f, 0.17f);
    glVertex2f(-0.23f, 0.17f);
    glVertex2f(-0.23f, 0.12f);
    glVertex2f(-0.24f, 0.12f);

    glEnd();


    glBegin(GL_QUADS); //black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.29f, 0.23f);
    glVertex2f(-0.28f, 0.23f);
    glVertex2f(-0.28f, 0.21f);
    glVertex2f(-0.29f, 0.21f);

    glEnd();


    glBegin(GL_QUADS);//red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.28f, 0.3f);
    glVertex2f(-0.18f, 0.3f);
    glVertex2f(-0.18f, 0.29f);
    glVertex2f(-0.28f, 0.29f);

    glEnd();


    glBegin(GL_QUADS); //ash
    glColor3f(0.45f, 0.44f, 0.35f);
    glVertex2f(-0.28f, 0.29f);
    glVertex2f(-0.18f, 0.29f);
    glVertex2f(-0.18f, 0.25f);
    glVertex2f(-0.28f, 0.25f);

    glEnd();


    glBegin(GL_QUADS);//black
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.26f, 0.41f);
    glVertex2f(-0.23f, 0.41f);
    glVertex2f(-0.23f, 0.36f);
    glVertex2f(-0.26f, 0.37f);

    glEnd();


    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.25f, 0.31f);
    glVertex2f(-0.23f, 0.31f);
    glVertex2f(-0.23f, 0.3f);
    glVertex2f(-0.25f, 0.3f);

    glEnd();


    glBegin(GL_QUADS); //red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.33f, 0.15f);
    glVertex2f(-0.32f, 0.15f);
    glVertex2f(-0.32f, 0.12f);
    glVertex2f(-0.33f, 0.12f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(0.29f, 0.05f);
    glVertex2f(0.3f, 0.05f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.29f, 0.0f);

    glEnd();


    glBegin(GL_QUADS);//blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(0.29f, 0.05f);
    glVertex2f(0.21f, 0.05f);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.18f, 0.0f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(0.09f, 0.05f);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.09f, 0.0f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.01f, 0.05f);
    glVertex2f(0.0f, 0.05f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.01f, 0.0f);

    glEnd();


    glBegin(GL_QUADS);//blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.11f, 0.05f);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.11f, 0.0f);

    glEnd();


    glBegin(GL_QUADS); //blue
    glColor3f(0.25f, 0.28f, 0.73f);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.19f, 0.05f);
    glVertex2f(-0.19f, 0.0f);
    glVertex2f(-0.2f, 0.0f);

    glEnd();


    glBegin(GL_QUADS);//black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.29f, 0.21f);
    glVertex2f(-0.28f, 0.21f);
    glVertex2f(-0.23f, 0.19f);
    glVertex2f(-0.31f, 0.19f);

    glEnd();





    glBegin(GL_POLYGON);//red
    glColor3f(0.63f, 0.3f, 0.2f);
    glVertex2f(-0.31f, 0.15f);
    glVertex2f(-0.33f, 0.15f);
    glVertex2f(-0.35f, 0.3f);
    glVertex2f(-0.33f, 0.34f);
    glVertex2f(-0.31f, 0.34f);

    glEnd();



    glBegin(GL_TRIANGLES);//black
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.05f, 0.45f);
    glVertex2f(0.1f, 0.45f);
    glVertex2f(0.072f, 0.43f);

    glEnd();


    glBegin(GL_TRIANGLES);//yellow
    glColor3f(0.83f, 0.51f, 0.1f);
    glVertex2f(-0.25f, 0.36f);
    glVertex2f(-0.23f, 0.36f);
    glVertex2f(-0.24f, 0.33f);

    glEnd();

    glPopMatrix();


    glFlush();
}


void update3(int value)
{
    if (currentScene != 4)
        return;

    positionx += speedx;

    if (positionx > 0.4f)
        positionx = 0.1f; // Wrap around

    glutPostRedisplay();
    glutTimerFunc(100, update3, 0); // Continue the loop
}



void reshape(int width, int height)
{
    if (height == 0) height = 1;


    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-0.5, 0.5, -0.4, 0.4, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/*******************************************Upamas Part**********************************************************/
/*******************************************Praptis Part**********************************************************/
void initRain()
{
    for (int i = 0; i < numRaindrops; ++i)
    {

        raindropX[i] = -0.5 + (rand() / (float)RAND_MAX) * 1.0;

        raindropY[i] = 0.4 + (rand() / (float)RAND_MAX) * 0.2;

        raindropSpeed[i] = 0.015 + (rand() / (float)RAND_MAX) * 0.01;
    }
}

void updateRain(int value)
{
    if (isRaining)
    {
        for (int i = 0; i < numRaindrops * rainDensity; ++i % numRaindrops)
        {

            raindropY[i % numRaindrops] = raindropY[i % numRaindrops] - raindropSpeed[i % numRaindrops];
            if (raindropY[i % numRaindrops] < -0.4)
            {

                raindropY[i % numRaindrops] = 0.4 + (rand() / (float)RAND_MAX) * 0.2;

                raindropX[i % numRaindrops] = -0.5 + (rand() / (float)RAND_MAX) * 1.0;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(16, updateRain, 0);
    }
}

void raindrops()
{
    if (!isRaining) return;
    glBegin(GL_LINES);
    for (int i = 0; i < numRaindrops * rainDensity; ++i % numRaindrops)
    {

        float alpha = (raindropY[i % numRaindrops] + 0.4) / 0.8;
        glColor4f(0.5f, 0.5f, 0.5f, alpha);

        float length = 0.02 + (0.01 * (rand() / (float)RAND_MAX));

        glVertex2f(raindropX[i % numRaindrops], raindropY[i % numRaindrops]);

        glVertex2f(raindropX[i % numRaindrops], raindropY[i % numRaindrops] - length);
    }
    glEnd();
}
void StartingText()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    char text[256];
    float y = 0.9f;
    float step = 0.05f;
    void* font = GLUT_BITMAP_8_BY_13;

    const char* lines[] =
    {
        "Chittagong Sea Port",


        "Keyboard Instructions:",
        "Press 1 for Scene 1 (Ship Crashing)",
        "Press 2 for Scene 2 (Crane Movement)",
        "Press 3 for Scene 3 (Placing Containers)",
        "Press 4 for Scene 4 (Shipping Start)",
        "Press 5 for Scene 5 (Sea View)",
        "",
        "Scene 1:",
        "- Right/Left Arrow: Move Ship",
        "- Up/Down Arrow: Speed Control",
        "- C: Toggle Clouds",
        "- W: Toggle Plane",
        "- R: Toggle Rain",
        "- D: Change Rain Speed",
        "- S: Reset Ship Position",
        "",
        "Scene 2:",
        "- Arrow Keys: Move Crane (Up/Down/Left/Right)",
        "",
        "Scene 3:",
        "- Left Arrow: Move Container",
        "- Up/Down: Speed Control",
        "",
        "Scene 4:",
        "- Right Arrow: Start Ship",
        "- Up/Down: Speed Control",
        "",
        "Scene 5:",
        "- Right Arrow: Ships Move Opposite Directions",
        "- Left Arrow: Reverse Ship Directions",
        "- Up/Down: Speed Control for Both Ships"
    };

    int numLines = sizeof(lines) / sizeof(lines[0]);
    for (int i = 0; i < numLines; ++i)
    {
        glRasterPos2f(-0.95f, y);  // Left
        for (int j = 0; lines[i][j] != '\0'; ++j)
        {
            glutBitmapCharacter(font, lines[i][j]);
        }
        y -= step;
    }

    glFlush();
}

bool b= false;

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // White background
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2);
    GLfloat global_ambient1[] = {0.0,5.9,0.0,0.1};//ambient RGBA intensity of light
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.5, 0.5, -0.4, 0.4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    static int lastScene = -1;

    if (currentScene != lastScene)//sound scene 1
    {
        PlaySound(NULL, 0, 0);


        if (currentScene == 3)
        {
            PlaySound("s3.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP); // Sadia's part
        }

        lastScene = currentScene;
    }

    if (showIntro)
    {
        StartingText();
    }
    else if(currentScene==1)
    {



        if(!isSinking)
        {
            glBegin(GL_QUADS);
            glColor3f(0.14f, 0.28f, 0.38f);
            glVertex2f(0.25f, -0.2f);
            glVertex2f(0.25f, -0.4f);
            glVertex2f(-0.5f, -0.4f);
            glVertex2f(-0.5f, -0.2f);
            glEnd();
        }

        /******************************************* sea *********************************************/
        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(-0.5f, -0.4f);
        glEnd();


        /******************************************* sky *********************************************/
        if (isRaining)
        {
            glBegin(GL_QUADS);
            glColor3f(0.11f, 0.2f, 0.27f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(0.5f, 0.0f);
            glVertex2f(0.5f, 0.4f);
            glVertex2f(-0.5f, 0.4f);
            glEnd();
            raindrops();
        }
        else
        {
            glBegin(GL_QUADS);
            glColor3f(0.20f, 0.38f, 0.56f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(0.5f, 0.0f);
            glVertex2f(0.5f, 0.4f);
            glVertex2f(-0.5f, 0.4f);
            glEnd();
        }

        /******************************************* cloud *********************************************/
        glPushMatrix();
        glTranslatef(cloudX, 0.0f, 0.0f); // Move clouds
        glBegin(GL_POLYGON);
        glColor3f(0.49f, 0.53f, 0.54f);
        glVertex2f(-0.29f, 0.36f);
        glVertex2f(-0.26f, 0.37f);
        glVertex2f(-0.25f, 0.38f);
        glVertex2f(-0.23f, 0.37f);
        glVertex2f(-0.21f, 0.36f);
        glVertex2f(-0.2f, 0.35f);
        glVertex2f(-0.21f, 0.33f);
        glVertex2f(-0.24f, 0.31f);
        glVertex2f(-0.25f, 0.32f);
        glVertex2f(-0.27f, 0.31f);
        glVertex2f(-0.29f, 0.33f);
        glVertex2f(-0.28f, 0.35f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.49f, 0.53f, 0.54f);
        glVertex2f(0.01f, 0.24f);
        glVertex2f(0.02f, 0.25f);
        glVertex2f(0.03f, 0.26f);
        glVertex2f(0.04f, 0.25f);
        glVertex2f(0.05f, 0.27f);
        glVertex2f(0.07f, 0.26f);
        glVertex2f(0.09f, 0.26f);
        glVertex2f(0.11f, 0.23f);
        glVertex2f(0.1f, 0.21f);
        glVertex2f(0.06f, 0.22f);
        glVertex2f(0.03f, 0.2f);
        glVertex2f(0.02f, 0.22f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.49f, 0.53f, 0.54f);
        glVertex2f(0.24f, 0.32f);
        glVertex2f(0.26f, 0.35f);
        glVertex2f(0.28f, 0.34f);
        glVertex2f(0.3f, 0.335f);
        glVertex2f(0.31f, 0.33f);
        glVertex2f(0.34f, 0.32f);
        glVertex2f(0.32f, 0.29f);
        glVertex2f(0.3f, 0.27f);
        glVertex2f(0.28f, 0.28f);
        glVertex2f(0.26f, 0.27f);
        glVertex2f(0.25f, 0.29f);
        glVertex2f(0.21f, 0.3f);

        glEnd();
        glPopMatrix();

        /******************************************* plane *********************************************/
        glPushMatrix();
        glTranslatef(planeX, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.45f, 0.3f);
        glVertex2f(-0.46f, 0.31f);
        glVertex2f(-0.33f, 0.31f);
        glVertex2f(-0.34f, 0.3f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.6f, 0.63f, 0.67f);
        glVertex2f(-0.46f, 0.31f);
        glVertex2f(-0.49f, 0.37f);
        glVertex2f(-0.47f, 0.37f);
        glVertex2f(-0.45f, 0.34f);
        glVertex2f(-0.34f, 0.34f);
        glVertex2f(-0.32f, 0.32f);
        glVertex2f(-0.33f, 0.31f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.405f, 0.28f);
        glVertex2f(-0.4f, 0.3f);
        glVertex2f(-0.38f, 0.3f);
        glVertex2f(-0.39f, 0.28f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.4f, 0.34f);
        glVertex2f(-0.405f, 0.36f);
        glVertex2f(-0.39f, 0.36f);
        glVertex2f(-0.38f, 0.34f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.35f, 0.32f);
        glVertex2f(-0.35f, 0.33f);
        glVertex2f(-0.33f, 0.33f);
        glVertex2f(-0.32f, 0.32f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.38f, 0.32f);
        glVertex2f(-0.38f, 0.33f);
        glVertex2f(-0.37f, 0.33f);
        glVertex2f(-0.37f, 0.32f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.39f, 0.32f);
        glVertex2f(-0.39f, 0.33f);
        glVertex2f(-0.4f, 0.33f);
        glVertex2f(-0.4f, 0.32f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.41f, 0.32f);
        glVertex2f(-0.41f, 0.33f);
        glVertex2f(-0.42f, 0.33f);
        glVertex2f(-0.42f, 0.32f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.14f, 0.28f, 0.38f);
        glVertex2f(-0.43f, 0.32f);
        glVertex2f(-0.43f, 0.33f);
        glVertex2f(-0.44f, 0.33f);
        glVertex2f(-0.44f, 0.32f);
        glEnd();
        glPopMatrix();

        /******************************************* Boat *********************************************/
        glPushMatrix();

        GLfloat global_ambient1[] = {0.0,5.9,0.0,0.1};//ambient RGBA intensity of light
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.



        if (isSinking)
        {

            glTranslatef(0.65f, -sinkProgress, 0.0f);
            glRotatef(angle1, 0.0f, 0.0f, 1.0f);
            glTranslatef(-0.45f, 0.0f, 0.0f);
        }
        else
        {
            glTranslatef(boatX, boatY, 0.0f); // Normal movement
        }

        glBegin(GL_POLYGON);   // boat ground
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.45f, -0.08f);
        glVertex2f(-0.4f, -0.11f);
        glVertex2f(-0.35f, -0.13f);
        glVertex2f(-0.3f, -0.14f);
        glVertex2f(-0.25f, -0.15f);
        glVertex2f(-0.2f, -0.165f);
        glVertex2f(-0.15f, -0.17f);
        glVertex2f(-0.1f, -0.175f);
        glVertex2f(-0.05f, -0.18f);
        glVertex2f(0.03f, -0.18f);
        glVertex2f(0.0305f, -0.01f);
        glVertex2f(-0.05f, -0.02f);
        glVertex2f(-0.15f, -0.03f);
        glVertex2f(-0.25f, -0.04f);
        glVertex2f(-0.35f, -0.0402f);
        glVertex2f(-0.42f, -0.0405f);
        glVertex2f(-0.46f, -0.04f);
        glEnd();

        glBegin(GL_POLYGON); // line
        glColor3f(0.96f, 0.64f, 0.18f);
        glVertex2f(-0.05f, -0.015f);
        glVertex2f(-0.15f, -0.025f);
        glVertex2f(-0.25f, -0.035f);
        glVertex2f(-0.35f, -0.037f);
        glVertex2f(-0.42f, -0.04f);
        glVertex2f(-0.46f, -0.032f);
        glVertex2f(-0.46f, -0.04f);
        glVertex2f(-0.42f, -0.0405f);
        glVertex2f(-0.35f, -0.0402f);
        glVertex2f(-0.25f, -0.04f);
        glVertex2f(-0.15f, -0.03f);
        glVertex2f(-0.05f, -0.02f);
        glVertex2f(0.0305f, -0.01f);
        glVertex2f(0.0305f, -0.002f);
        glEnd();

        glBegin(GL_POLYGON); // middle
        glColor3f(0.98f, 0.87f, 0.72f);
        glVertex2f(-0.4f, -0.015f);
        glVertex2f(-0.35f, -0.01f);
        glVertex2f(-0.32f, 0.0f);
        glVertex2f(-0.32f, -0.01f);
        glVertex2f(-0.25f, -0.01f);
        glVertex2f(-0.2f, 0.0f);
        glVertex2f(-0.15f, 0.005f);
        glVertex2f(-0.1f, 0.01f);
        glVertex2f(-0.05f, 0.02f);
        glVertex2f(0.0f, 0.025f);
        glVertex2f(0.035f, 0.03f);
        glVertex2f(0.0305f, -0.002f);
        glVertex2f(-0.05f, -0.015f);
        glVertex2f(-0.15f, -0.025f);
        glVertex2f(-0.25f, -0.035f);
        glVertex2f(-0.35f, -0.037f);
        glVertex2f(-0.42f, -0.04f);
        glVertex2f(-0.46f, -0.032f);
        glVertex2f(-0.46f, -0.018f);
        glEnd();

        glBegin(GL_LINE_LOOP); // middle
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.4f, -0.015f);
        glVertex2f(-0.35f, -0.01f);
        glVertex2f(-0.32f, 0.0f);
        glVertex2f(-0.32f, -0.01f);
        glVertex2f(-0.25f, -0.01f);
        glVertex2f(-0.2f, 0.0f);
        glVertex2f(-0.15f, 0.005f);
        glVertex2f(-0.1f, 0.01f);
        glVertex2f(-0.05f, 0.02f);
        glVertex2f(0.0f, 0.025f);
        glVertex2f(0.035f, 0.03f);
        glVertex2f(0.0305f, -0.002f);
        glVertex2f(-0.05f, -0.015f);
        glVertex2f(-0.15f, -0.025f);
        glVertex2f(-0.25f, -0.035f);
        glVertex2f(-0.35f, -0.037f);
        glVertex2f(-0.42f, -0.04f);
        glVertex2f(-0.46f, -0.032f);
        glVertex2f(-0.46f, -0.018f);
        glEnd();

        glBegin(GL_POLYGON); // middle
        glColor3f(0.98f, 0.87f, 0.72f);
        glVertex2f(-0.46f, -0.018f);
        glVertex2f(-0.4f, -0.015f);
        glVertex2f(-0.35f, -0.01f);
        glVertex2f(-0.32f, 0.0f);
        glVertex2f(-0.32f, 0.017f);
        glVertex2f(-0.46f, -0.01f);
        glEnd();

        glBegin(GL_LINE_LOOP); // middle
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.46f, -0.018f);
        glVertex2f(-0.4f, -0.015f);
        glVertex2f(-0.35f, -0.01f);
        glVertex2f(-0.32f, 0.0f);
        glVertex2f(-0.32f, 0.017f);
        glVertex2f(-0.46f, -0.01f);
        glEnd();

        // Dori (ropes)
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.44f, 0.01f);
        glVertex2f(-0.42f, 0.1f);
        glVertex2f(-0.43f, 0.01f);
        glVertex2f(-0.42f, 0.05f);
        glVertex2f(-0.415f, 0.1f);
        glVertex2f(-0.395f, 0.05f);
        glVertex2f(-0.415f, 0.0105f);
        glVertex2f(-0.395f, 0.07f);
        glVertex2f(-0.415f, 0.027f);
        glVertex2f(-0.395f, 0.09f);
        glVertex2f(-0.35f, 0.09f);
        glVertex2f(-0.36f, 0.1f);
        glVertex2f(-0.35f, 0.05f);
        glVertex2f(-0.36f, 0.06f);
        glVertex2f(-0.31f, 0.09f);
        glVertex2f(-0.3f, 0.11f);
        glVertex2f(-0.31f, 0.06f);
        glVertex2f(-0.3f, 0.08f);
        glVertex2f(-0.25f, 0.14f);
        glVertex2f(-0.22f, 0.06f);
        glVertex2f(-0.25f, 0.08f);
        glVertex2f(-0.22f, 0.06f);
        glVertex2f(-0.25f, 0.14f);
        glVertex2f(-0.19f, 0.3f);
        glVertex2f(-0.25f, 0.08f);
        glVertex2f(-0.19f, 0.23f);
        glVertex2f(-0.23f, 0.06f);
        glVertex2f(-0.19f, 0.18f);
        glVertex2f(-0.22f, 0.06f);
        glVertex2f(-0.19f, 0.16f);
        glVertex2f(-0.09f, 0.0105f);
        glVertex2f(-0.18f, 0.3f);
        glVertex2f(-0.18f, 0.22f);
        glVertex2f(-0.1f, 0.01f);
        glVertex2f(-0.18f, 0.17f);
        glVertex2f(-0.11f, 0.01f);
        glVertex2f(-0.18f, 0.13f);
        glVertex2f(-0.12f, 0.01f);
        glEnd();

        // Three pillars
        glBegin(GL_QUADS);
        glColor3f(0.96f, 0.64f, 0.18f); // deep brown
        glVertex2f(-0.35f, 0.035f);
        glVertex2f(-0.35f, 0.165f);
        glVertex2f(-0.31f, 0.175f);
        glVertex2f(-0.31f, 0.05f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.96f, 0.64f, 0.18f); // deep brown
        glVertex2f(-0.3f, 0.045f);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.25f, 0.21f);
        glVertex2f(-0.25f, 0.045f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.96f, 0.64f, 0.18f); // deep brown
        glVertex2f(-0.395f, 0.02f);
        glVertex2f(-0.395f, 0.13f);
        glVertex2f(-0.36f, 0.14f);
        glVertex2f(-0.36f, 0.025f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.35f, 0.13f);
        glVertex2f(-0.35f, 0.165f);
        glVertex2f(-0.31f, 0.175f);
        glVertex2f(-0.31f, 0.14f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.3f, 0.16f);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.25f, 0.21f);
        glVertex2f(-0.25f, 0.17f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.395f, 0.1f);
        glVertex2f(-0.395f, 0.13f);
        glVertex2f(-0.36f, 0.14f);
        glVertex2f(-0.36f, 0.11f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // deep brown
        glVertex2f(-0.35f, 0.035f);
        glVertex2f(-0.35f, 0.165f);
        glVertex2f(-0.31f, 0.175f);
        glVertex2f(-0.31f, 0.05f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // deep brown
        glVertex2f(-0.3f, 0.045f);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.25f, 0.21f);
        glVertex2f(-0.25f, 0.045f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // deep brown
        glVertex2f(-0.395f, 0.02f);
        glVertex2f(-0.395f, 0.13f);
        glVertex2f(-0.36f, 0.14f);
        glVertex2f(-0.36f, 0.025f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.98f, 0.87f, 0.72f); // middle
        glVertex2f(-0.32f, 0.017f);
        glVertex2f(-0.285f, 0.015f);
        glVertex2f(-0.285f, 0.025f);
        glVertex2f(-0.195f, 0.025f);
        glVertex2f(-0.195f, 0.015f);
        glVertex2f(-0.16f, 0.01f);
        glVertex2f(-0.16f, 0.02f);
        glVertex2f(-0.15f, 0.025f);
        glVertex2f(-0.15f, 0.005f);
        glVertex2f(-0.2f, 0.0f);
        glVertex2f(-0.26f, 0.0f);
        glVertex2f(-0.26f, -0.01f);
        glVertex2f(-0.29f, -0.01f);
        glVertex2f(-0.29f, 0.0f);
        glVertex2f(-0.32f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // middle
        glVertex2f(-0.32f, 0.017f);
        glVertex2f(-0.285f, 0.015f);
        glVertex2f(-0.285f, 0.025f);
        glVertex2f(-0.195f, 0.025f);
        glVertex2f(-0.195f, 0.015f);
        glVertex2f(-0.16f, 0.01f);
        glVertex2f(-0.16f, 0.02f);
        glVertex2f(-0.15f, 0.025f);
        glVertex2f(-0.15f, 0.005f);
        glVertex2f(-0.2f, 0.0f);
        glVertex2f(-0.26f, 0.0f);
        glVertex2f(-0.26f, -0.01f);
        glVertex2f(-0.29f, -0.01f);
        glVertex2f(-0.29f, 0.0f);
        glVertex2f(-0.32f, 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.195f, 0.025f);
        glVertex2f(-0.195f, 0.015f);
        glVertex2f(-0.16f, 0.015f);
        glVertex2f(-0.16f, 0.025f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.98f, 0.87f, 0.72f); // middle
        glVertex2f(-0.45f, 0.01f);
        glVertex2f(-0.4f, 0.015f);
        glVertex2f(-0.34f, 0.03f);
        glVertex2f(-0.34f, 0.02f);
        glVertex2f(-0.4f, 0.01f);
        glVertex2f(-0.45f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // middle
        glVertex2f(-0.45f, 0.01f);
        glVertex2f(-0.4f, 0.015f);
        glVertex2f(-0.34f, 0.03f);
        glVertex2f(-0.34f, 0.02f);
        glVertex2f(-0.4f, 0.01f);
        glVertex2f(-0.45f, 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.345f, 0.025f);
        glVertex2f(-0.345f, 0.04f);
        glVertex2f(-0.15f, 0.04f);
        glVertex2f(-0.15f, 0.025f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.345f, 0.025f);
        glVertex2f(-0.345f, 0.04f);
        glVertex2f(-0.15f, 0.04f);
        glVertex2f(-0.15f, 0.025f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.27f, 0.04f);
        glVertex2f(-0.27f, 0.06f);
        glVertex2f(-0.2f, 0.06f);
        glVertex2f(-0.2f, 0.04f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.27f, 0.04f);
        glVertex2f(-0.27f, 0.06f);
        glVertex2f(-0.2f, 0.06f);
        glVertex2f(-0.2f, 0.04f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.35f, 0.022f);
        glVertex2f(-0.35f, 0.045f);
        glVertex2f(-0.345f, 0.045f);
        glVertex2f(-0.345f, 0.022f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.35f, 0.022f);
        glVertex2f(-0.35f, 0.045f);
        glVertex2f(-0.345f, 0.045f);
        glVertex2f(-0.345f, 0.022f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.345f, 0.04f);
        glVertex2f(-0.345f, 0.045f);
        glVertex2f(-0.32f, 0.045f);
        glVertex2f(-0.32f, 0.04f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.345f, 0.04f);
        glVertex2f(-0.345f, 0.045f);
        glVertex2f(-0.32f, 0.045f);
        glVertex2f(-0.32f, 0.04f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.32f, 0.04f);
        glVertex2f(-0.32f, 0.05f);
        glVertex2f(-0.31f, 0.05f);
        glVertex2f(-0.31f, 0.04f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.32f, 0.04f);
        glVertex2f(-0.32f, 0.05f);
        glVertex2f(-0.31f, 0.05f);
        glVertex2f(-0.31f, 0.04f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.31f, 0.04f);
        glVertex2f(-0.307f, 0.049f);
        glVertex2f(-0.265f, 0.049f);
        glVertex2f(-0.265f, 0.04f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.31f, 0.04f);
        glVertex2f(-0.307f, 0.049f);
        glVertex2f(-0.265f, 0.049f);
        glVertex2f(-0.265f, 0.04f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.3f, 0.049f);
        glVertex2f(-0.3f, 0.06f);
        glVertex2f(-0.281f, 0.06f);
        glVertex2f(-0.281f, 0.049f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.3f, 0.049f);
        glVertex2f(-0.3f, 0.06f);
        glVertex2f(-0.281f, 0.06f);
        glVertex2f(-0.281f, 0.049f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.45f, 0.44f, 0.44f); // black
        glVertex2f(-0.28f, 0.049f);
        glVertex2f(-0.28f, 0.052f);
        glVertex2f(-0.265f, 0.059f);
        glVertex2f(-0.265f, 0.049f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.3f, 0.34f, 0.34f); // black
        glVertex2f(-0.44f, -0.01f);
        glVertex2f(-0.445f, 0.003f);
        glVertex2f(-0.325f, 0.027f);
        glVertex2f(-0.325f, 0.015f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.45f, 0.44f, 0.44f); // black
        glVertex2f(-0.325f, 0.015f);
        glVertex2f(-0.325f, 0.027f);
        glVertex2f(-0.285f, 0.027f);
        glVertex2f(-0.285f, 0.015f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.45f, 0.44f, 0.44f); // black
        glVertex2f(-0.32f, -0.01f);
        glVertex2f(-0.32f, 0.0f);
        glVertex2f(-0.29f, 0.0f);
        glVertex2f(-0.29f, -0.01f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.98f, 0.87f, 0.72f); // black
        glVertex2f(-0.26f, -0.01f);
        glVertex2f(-0.26f, 0.0f);
        glVertex2f(-0.2f, 0.0f);
        glEnd();

        // Two bash pillars
        glBegin(GL_QUADS);
        glColor3f(0.81f, 0.49f, 0.07f); // black
        glVertex2f(-0.42f, 0.015f);
        glVertex2f(-0.42f, 0.135f);
        glVertex2f(-0.415f, 0.135f);
        glVertex2f(-0.415f, 0.015f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.81f, 0.49f, 0.07f); // black
        glVertex2f(-0.19f, 0.0f);
        glVertex2f(-0.19f, 0.35f);
        glVertex2f(-0.18f, 0.35f);
        glVertex2f(-0.18f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.42f, 0.015f);
        glVertex2f(-0.42f, 0.135f);
        glVertex2f(-0.415f, 0.135f);
        glVertex2f(-0.415f, 0.015f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f); // black
        glVertex2f(-0.19f, 0.0f);
        glVertex2f(-0.19f, 0.35f);
        glVertex2f(-0.18f, 0.35f);
        glVertex2f(-0.18f, 0.0f);
        glEnd();

        /*************************************************LIGHT************************************************************/

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.77f, 0.0f); // green
        glVertex2f(-0.01f, 0.0f);
        glVertex2f(-0.01f, 0.01f);    // x, y
        glVertex2f(-0.02f, 0.01f);
        glVertex2f(-0.02f,  0.0f);

        glEnd();

        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.01f, 0.0f);
        glVertex2f(-0.01f, 0.01f);    // x, y
        glVertex2f(-0.02f, 0.01f);
        glVertex2f(-0.02f,  0.0f);

        glEnd();

        glDisable(GL_LIGHTING);//Enable Light Effect


        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 1.0f, 0.0f); // green
        glVertex2f(-0.07f, 0.0f);
        glVertex2f(-0.07f, -0.01f);    // x, y
        glVertex2f(-0.08f, -0.01f);
        glVertex2f(-0.08f,  0.0f);

        glEnd();

        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.07f, 0.0f);
        glVertex2f(-0.07f, -0.01f);    // x, y
        glVertex2f(-0.08f, -0.01f);
        glVertex2f(-0.08f,  0.0f);

        glEnd();

        glDisable(GL_LIGHTING);//Enable Light Effect

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 1.0f); // green
        glVertex2f(-0.15f, -0.005f);
        glVertex2f(-0.15f, -0.015f);    // x, y
        glVertex2f(-0.16f, -0.015f);
        glVertex2f(-0.16f,  -0.005f);

        glEnd();

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.15f, -0.005f);
        glVertex2f(-0.15f, -0.015f);    // x, y
        glVertex2f(-0.16f, -0.015f);
        glVertex2f(-0.16f,  -0.005f);

        glEnd();


        glDisable(GL_LIGHTING);//Enable Light Effect

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.2f, -0.01f);
        glVertex2f(-0.2f, -0.02f);    // x, y
        glVertex2f(-0.21f, -0.02f);
        glVertex2f(-0.21f,  -0.01f);

        glEnd();


        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.2f, -0.01f);
        glVertex2f(-0.2f, -0.02f);    // x, y
        glVertex2f(-0.21f, -0.02f);
        glVertex2f(-0.21f,  -0.01f);

        glEnd();

        glDisable(GL_LIGHTING);//Enable Light Effect

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 1.0f); // green
        glVertex2f(-0.28f, -0.015f);
        glVertex2f(-0.28f, -0.025f);    // x, y
        glVertex2f(-0.29f, -0.025f);
        glVertex2f(-0.29f,  -0.015f);

        glEnd();

        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.28f, -0.015f);
        glVertex2f(-0.28f, -0.025f);    // x, y
        glVertex2f(-0.29f, -0.025f);
        glVertex2f(-0.29f,  -0.015f);

        glEnd();

        glDisable(GL_LIGHTING);//Enable Light Effect

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 1.0f, 1.0f); // green
        glVertex2f(-0.36f, -0.02f);
        glVertex2f(-0.36f, -0.03f);    // x, y
        glVertex2f(-0.37f, -0.03f);
        glVertex2f(-0.37f,  -0.02f);

        glEnd();

        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.36f, -0.02f);
        glVertex2f(-0.36f, -0.03f);    // x, y
        glVertex2f(-0.37f, -0.03f);
        glVertex2f(-0.37f,  -0.02f);

        glEnd();

        glDisable(GL_LIGHTING);//Enable Light Effect

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);//A lighting model parameter.

        // Draw a Red 1x1 Square centered at origin
        glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(0.77f, 0.55f, 0.67f); // green
        glVertex2f(-0.41f, -0.025f);
        glVertex2f(-0.41f, -0.035f);    // x, y
        glVertex2f(-0.42f, -0.035f);
        glVertex2f(-0.42f,  -0.025f);

        glEnd();
        glBegin(GL_LINE_LOOP);              // Each set of 4 vertices form a quad
        glColor3f(0.0f, 0.0f, 0.0f); // green
        glVertex2f(-0.41f, -0.025f);
        glVertex2f(-0.41f, -0.035f);    // x, y
        glVertex2f(-0.42f, -0.035f);
        glVertex2f(-0.42f,  -0.025f);

        glEnd();

        glDisable(GL_LIGHTING);//Enable Light Effect
        glPopMatrix();






        /******************************************* water *********************************************/
        if(isSinking)
        {
            glBegin(GL_QUADS);
            glColor3f(0.14f, 0.28f, 0.38f);
            glVertex2f(0.25f, -0.2f);
            glVertex2f(0.25f, -0.4f);
            glVertex2f(-0.5f, -0.4f);
            glVertex2f(-0.5f, -0.2f);
            glEnd();
        }
        glPushMatrix();
        glTranslatef(position2, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        glColor3f(0.85f, 0.87f, 0.9f);
        glVertex2f(-0.49f, -0.26f);
        glVertex2f(-0.45f, -0.24f);
        glVertex2f(-0.44f, -0.25f);
        glVertex2f(-0.44f, -0.26f);
        glVertex2f(-0.41f, -0.27f);
        glVertex2f(-0.41f, -0.29f);
        glVertex2f(-0.49f, -0.29f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.87f, 0.95f, 0.98f);
        glVertex2f(-0.4f, -0.34f);
        glVertex2f(-0.38f, -0.33f);
        glVertex2f(-0.37f, -0.34f);
        glVertex2f(-0.35f, -0.34f);
        glVertex2f(-0.34f, -0.35f);
        glVertex2f(-0.4f, -0.35f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.77f, 0.94f, 0.97f);
        glVertex2f(-0.21f, -0.31f);
        glVertex2f(-0.18f, -0.29f);
        glVertex2f(-0.15f, -0.31f);
        glVertex2f(-0.15f, -0.32f);
        glVertex2f(-0.21f, -0.32f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.87f, 0.95f, 0.98f);
        glVertex2f(-0.06f, -0.37f);
        glVertex2f(-0.04f, -0.35f);
        glVertex2f(-0.02f, -0.34f);
        glVertex2f(0.03f, -0.36f);
        glVertex2f(0.05f, -0.37f);
        glVertex2f(0.04f, -0.38f);
        glVertex2f(-0.08f, -0.38f);
        glEnd();
        glPopMatrix();

        /******************************************* ice *********************************************/
        glBegin(GL_POLYGON);            // icemain
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.16f, -0.36f);
        glVertex2f(0.16f, -0.33f);
        glVertex2f(0.19f, -0.29f);
        glVertex2f(0.21f, -0.23f);
        glVertex2f(0.2f, -0.17f);
        glVertex2f(0.22f, -0.13f);
        glVertex2f(0.22f, -0.08f);
        glVertex2f(0.24f, -0.03f);
        glVertex2f(0.26f, 0.03f);
        glVertex2f(0.32f, 0.09f);
        glVertex2f(0.35f, 0.11f);
        glVertex2f(0.4f, 0.17f);
        glVertex2f(0.45f, 0.1f);
        glVertex2f(0.48f, 0.09f);
        glVertex2f(0.5f, 0.05f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.13f, -0.4f);


        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.55f, 0.65f, 0.79f);
        glVertex2f(0.16f, -0.36f);
        glVertex2f(0.16f, -0.33f);
        glVertex2f(0.19f, -0.29f);
        glVertex2f(0.21f, -0.23f);
        glVertex2f(0.2f, -0.17f);
        glVertex2f(0.22f, -0.13f);
        glVertex2f(0.22f, -0.08f);
        glVertex2f(0.27f, -0.04f);
        glVertex2f(0.3f, -0.07f);
        glVertex2f(0.33f, -0.07f);
        glVertex2f(0.34f, -0.1f);
        glVertex2f(0.37f, -0.14f);
        glVertex2f(0.41f, -0.17f);
        glVertex2f(0.41f, -0.24f);
        glVertex2f(0.46f, -0.3f);
        glVertex2f(0.49f, -0.35f);
        glVertex2f(0.5f, -0.3f);
        glVertex2f(0.13f, -0.4f);


        glBegin(GL_POLYGON);            // ice
        glColor3f(0.8f, 0.95f, 0.96f);
        glVertex2f(0.34f, -0.3f);
        glVertex2f(0.34f, -0.25f);
        glVertex2f(0.37f, -0.22f);
        glVertex2f(0.4f, -0.19f);
        glVertex2f(0.41f, -0.03f);
        glVertex2f(0.45f, -0.06f);
        glVertex2f(0.47f, -0.1f);
        glVertex2f(0.5f, -0.15f);
        glVertex2f(0.5f, -0.2f);
        glVertex2f(0.3f, -0.4f);
        glBegin(GL_POLYGON);

        glColor3f(0.77f, 0.94f, 0.97f);

        glVertex2f(0.28f, -0.15f);
        glVertex2f(0.35f, -0.02f);
        glVertex2f(0.34f, 0.08f);
        glVertex2f(0.38f, 0.11f);
        glVertex2f(0.45f, 0.05f);
        glVertex2f(0.5f, -0.06f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.28f, -0.4f);

        glBegin(GL_POLYGON);

        glColor3f(0.8f, 0.9f, 0.98f);

        glVertex2f(0.27f, -0.03f);
        glVertex2f(0.22f, -0.08f);
        glVertex2f(0.24f, -0.03f);
        glVertex2f(0.26f, 0.03f);
        glVertex2f(0.32f, 0.09f);
        glVertex2f(0.39f, -0.01f);
        glVertex2f(0.45f, -0.1f);
        glVertex2f(0.32f, -0.09f);

        glBegin(GL_POLYGON);

        glColor3f(0.87f, 0.95f, 0.98f);


        glVertex2f(0.34f, 0.08f);
        glVertex2f(0.32f, 0.09f);
        glVertex2f(0.35f, 0.11f);
        glVertex2f(0.4f, 0.17f);
        glVertex2f(0.45f, 0.1f);
        glVertex2f(0.48f, 0.09f);

        glEnd();



        /*glBegin(GL_LINE_LOOP);            // ice
          glColor3f(0.36f, 0.54f, 0.61f);

            glVertex2f(0.16f, -0.36f);
            glVertex2f(0.16f, -0.33f);
            glVertex2f(0.19f, -0.29f);
            glVertex2f(0.21f, -0.23f);
            glVertex2f(0.2f, -0.17f);
            glVertex2f(0.22f, -0.13f);
            glVertex2f(0.22f, -0.08f);
            glVertex2f(0.24f, -0.03f);
            glVertex2f(0.26f, 0.03f);
            glVertex2f(0.32f, 0.09f);
            glVertex2f(0.35f, 0.11f);
            glVertex2f(0.4f, 0.17f);
            glVertex2f(0.45f, 0.1f);
            glVertex2f(0.48f, 0.09f);
            glVertex2f(0.5f, 0.05f);
            glVertex2f(0.5f, -0.4f);
            glVertex2f(0.13f, -0.4f);
        glEnd();*/



        if (isRaining)
        {
            raindrops();
        }
        //done pu

        if (!b)
        {
            PlaySound("p.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            b = true;
        }
    }

        //done pu


    else if (currentScene == 2)
    {
        display2(); // tauhids
    }
    else if (currentScene == 3)
    {
        display3(); // oishes display func
    }
    else if (currentScene == 4)
    {
        display4(); // airins display func
    }
    else if(currentScene ==5)
    {
        display5(); // sadia
    }


    glFlush();  // Render now
}



/*****************************************plane  move************************************/
void timer(int value)
{
    if (movePlane)
    {
        planeX += MOVE_SPEED;
        if (planeX > 0.88f)
        {
            planeX = -0.5f;
        }
    }

    /*******************************************Cloud Move*************************************/
    if (moveCloud)
    {
        cloudX += CLOUD_SPEED;
        if (cloudX > 0.5f)
        {
            cloudX = -0.5f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}




/*************************press key***********************************/
void keyboard(unsigned char key, int x, int y)
{
    if (key == '1')
    {
        showIntro = false;
        currentScene = 1;
        glutPostRedisplay();//My
    }
    else if (key == '2')
    {
        showIntro = false;
        currentScene = 2; // Switch to tauhids scene
        glutPostRedisplay();
    }
    else if (key == '3')
    {
        showIntro = false;
        currentScene = 3; // Switch to oishes scene
        glutPostRedisplay();
    }
    else if (key == '4')
    {
        showIntro = false;
        currentScene = 4; // Switch to airins scene
        glutPostRedisplay();
    }

    else if (key == '5')
    {
        showIntro = false;
        currentScene = 5; // Switch to sadias scene
        glutPostRedisplay();
    }
    else if (currentScene == 1) // Only respond to keys if in Upamas scene
    {
        if (key == 'r' || key == 'R')
        {
            isRaining = !isRaining;
            if (isRaining)
            {
                initRain();
                glutTimerFunc(0, updateRain, 0);
            }
            glutPostRedisplay();
        }
        else if (key == 'w' || key == 'W')
        {
            movePlane = !movePlane;
            glutPostRedisplay();
        }
        else if (key == 'd' || key == 'D')
        {
            if (rainDensity == 1) rainDensity = 2;
            else if (rainDensity == 2) rainDensity = 0.5;
            else rainDensity = 1;

            if (isRaining)
            {
                initRain();
                glutTimerFunc(0, updateRain, 0);
            }
            glutPostRedisplay();
        }
        else if (key == 'c' || key == 'C')
        {
            moveCloud = !moveCloud;
            if (moveCloud)
            {
                glutTimerFunc(0, timer, 0);
            }
            glutPostRedisplay();
        }
        else if (key == 's' || key == 'S')
        {
            boatX = 0.0f;
            boatY = 0.0f;
            sinkProgress = 0.0f;
            angle1 = 0.0f;
            isSinking = false;
            glutPostRedisplay();
        }
    }
}

void update(int value)
{
    if (!isSinking)
    {
        if (boatX > 0.0f)
        {
            boatX = 0.3f; // Move left
        }
        else
        {
            boatX -=speed; // Clamp at left
        }
        glutPostRedisplay();
        glutTimerFunc(100, update, 0);
    }
}
void update2(int value)
{
    if (!isSinking)
    {
        if (boatX < 0.2f)   // Move until hitting iceberg
        {
            boatX += speed;
        }
        else
        {
            isSinking = true;
            boatX = 0.45f;
        }
    }
    else
    {
        sinkProgress += 0.002f;
        if (sinkProgress < 0.4f)
        {
            angle1 += 0.3f;
            if (angle1 > 15.0f)
            {
                angle1 = 15.0f; //  angle
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(200, update2, 0);
}

void SpecialInput(int key, int x, int y)
{
    if (currentScene == 1)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            speed += 0.01f;
            break;
        case GLUT_KEY_DOWN:
            speed -= 0.01f;
            if (speed < 0.01f) speed = 0.01f;
            break;
        case GLUT_KEY_LEFT:
            glutTimerFunc(100, update, 0);
            break;
        case GLUT_KEY_RIGHT:
            glutTimerFunc(100, update2, 0);
            break;
        }
    }
    else if (currentScene == 2)
    {
        switch(key)// turjo
        {
        case GLUT_KEY_UP:
            positionY += step;
            break;

        case GLUT_KEY_DOWN:
            positionY -= step;
            break;

        case GLUT_KEY_LEFT:
            positionX -= step;
            break;

        case GLUT_KEY_RIGHT:
            positionX += step;
            break;
        }
    }
    else if(currentScene==3)
    {

        switch(key) // oishi

        {

        case GLUT_KEY_UP:

            speediao = speediao + 0.01;

            break;

        case GLUT_KEY_DOWN:

            speediao = speediao - 0.01;

            break;

        case GLUT_KEY_LEFT:

            glutTimerFunc(100, updateiao, 0);

            break;



        }
    }
    else if(currentScene==4)
    {
        switch (key) // airin
        {
        case GLUT_KEY_UP:
            speedx += 0.01f;
            break;
        case GLUT_KEY_DOWN:
            speedx -= 0.01f;
            if (speedx < 0.0f) speedx = 0.0f;
            break;
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_LEFT:
            glutTimerFunc(0, update3, 0);
            break;
        }


    }
    else if(currentScene ==5)
    {


        switch(key) // sadia
        {
        case GLUT_KEY_UP:
            speedc = speedc + 0.01;
            break;

        case GLUT_KEY_DOWN:
            speedc = speedc - 0.01;
            break;

        case GLUT_KEY_LEFT:
            glutTimerFunc(100, updatex, 0);
            break;

        case GLUT_KEY_RIGHT:
            glutTimerFunc(100, updatey, 0);
            break;
        }


    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Combined OpenGL Project");

    // init();

    glutDisplayFunc(display);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    // ← Use your main display function
    // glutDisplayFunc(display4);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(0, update3, 0);
    glutReshapeFunc(reshape);
    //gluOrtho2D(-60, 60, -40, 40);
    glutTimerFunc(0, updatet, 0);

    glutMainLoop();
    return 0;
}
