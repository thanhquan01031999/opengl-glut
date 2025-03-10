#include <GL/glut.h>
#include <Windows.h>
#include <math.h>

const int screenHeight = 480;
const int screenWidth = 640;
#define PI 3.1415926

float v0[12][2] =
{{0,0},{0,2},{0.6,2},{0.6,1.2},{1.4,1.2},{1.4,2},{2,2},{2,0},{1.4,0},{1.4,0.8},{0.6,0.8},{0.6,0}};

float m[16] = {cos(PI/3),sin(PI/3),0,0,
                -sin(60),cos(60),0,0,
                0,0,1,0,
                4,5,0,1};

void drawGrid()
{
    glColor3f(0.5,0.5,0.5);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = -8; x <= 8; x++)
    {
        glVertex2f(x,-8);
        glVertex2f(x,8);
    }

    for(int y = -8; y <= 8; y++)
    {
        glVertex2f(-8,y);
        glVertex2f(8,y);
    }
    glEnd();

    // glColor3f(0,0,0);
    // glLineWidth(4);
    // glBegin(GL_LINES);
    //     glVertex2f(-5,0);
    //     glVertex2f(5,0);
    //     glVertex2f(0,5);
    //     glVertex2f(0,-5);
    // glEnd();
}

void MakeNGon(float fRadius, int n, float startAngle)
{
    float del_angle = 2.0*PI/n;
    float angle;
    float x,y;
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glLineWidth(4);
    for(int i = 0; i <= n; i++)
    {
        angle = i*del_angle + startAngle;
        x = fRadius*cos(angle);
        y = fRadius*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-fRadius,0);
        glVertex2f(fRadius,0);
        glVertex2f(0,-fRadius);
        glVertex2f(0,fRadius);
    glEnd();
}

void drawFigure0()
{
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i <12; i++)
    {
        glVertex2fv(v0[i]);
    }
    glEnd();
}
void drawFigure1()
{
    float v1[12][2];
    for(int i = 0; i < 12 ; i++)
    {
        v1[i][0] = v0[i][0]*cos(PI/3) - v0[i][1]*sin(PI/3);
        v1[i][1] = v0[i][0]*sin(PI/3) + v0[i][1]*sin(PI/3);
    }
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 12 ; i++)
    {
        glVertex2fv(v1[i]);
    }
    glEnd();
}

void init()
{
    glClearColor(1,1,1,1);




    glColor3f(1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-8,8,0,10,-1.0,1.0);

}
//test





void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,1);
    drawGrid();

    
    // glTranslatef(1.5,2.5,0);
    // glRotatef(30,0,0,1);
    // glScalef(1.5,0.5,1);
    glPushMatrix();
    glLoadMatrixf(m);
    glColor3f(0,0,1);
    drawFigure0();
    glPopMatrix();

    // glColor3f(1,0,0);
    // drawFigure0();
    // drawFigure1();
    glFlush();
}


int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Amazing Art");
    glutDisplayFunc(mydisplay);
    
    init();

    glutMainLoop();

}