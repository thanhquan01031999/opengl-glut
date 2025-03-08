#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
float R = 4;
using namespace std;
int Width = 500;
int Height = 500;
int len = 20;
float l = 2, r = 4, b =-4,t=2;
#define PI 3.14159265358
#define ARCDIV 19
#define LINEDIV 16
float angle = 0;

void drawText(float xPos, float yPos, float zPos, char str[])
{
    glRasterPos3d(xPos,yPos,zPos);

    void *font = GLUT_BITMAP_9_BY_15;
    for( int i = 0; i < strlen(str); i++)
    {
        glutBitmapCharacter(font, str[i]);
    }
}

void drawAxis()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3d(1, 0, 0);
    glVertex3f(0,0,0);
    glVertex3f(2,0,0);
    glColor3d(0, 1, 0);
    glVertex3f(0,0,0);
    glVertex3f(0,2,0);
    glColor3d(0, 0, 1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,2);
    glEnd();
    glColor3f(0,0,0);
    drawText(1.9,0,0,"X");
    drawText(0,1.7,0,"Y");
    drawText(0,0,1.9,"Z");
    

}

void myMouse(int btn, int state, int x, int y)
{

}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(0.7,0.5,0.3,0,0,0,0,1,0);
    
    glRotatef(angle,0,1,0);

    drawAxis();

    double b = 0.05;
    double R = 0.5;
    glBegin(GL_LINE_STRIP);
    for(double t= 0; t < 40; t += 0.01)
    {
        glVertex3f(R*cos(t),R*sin(t),b*t);
    }
    glEnd();
    glFlush();

    
}

void init()
{
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3,3,-3,3,-10,100);

}

void mySpecialFunc(int key, int x, int y)
{
    if(key == GLUT_KEY_RIGHT)
    {
        angle += 5;
    }
    else if(key == GLUT_KEY_LEFT)
    {
        angle -= 5;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(Width,Height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Simple Data Structure");
    glutDisplayFunc(mydisplay);
    glutSpecialFunc(mySpecialFunc);
    init();
    glutMainLoop();

}