#include <GL/glut.h>
#include <Windows.h>
#include <math.h>

float R = 2;

struct Point2D
{
    float x, y;
};

Point2D pointArr[10];

void drawPoint(Point2D p)
{
    glBegin(GL_POINT);
        glVertex2f(p.x, p.y);
    glEnd();
}


void init()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.5,4.5,-3.0,3.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}


void mydisplay()
{
    GLfloat vertices[3][2] = {{0.0,0.0},{25.0,50.0},{50.0,50.0}};


    glClear(GL_COLOR_BUFFER_BIT);

    //square
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 2.0);
        glVertex2f(-2.0,2.0);
        glVertex2f(-2.0,0.0);
    glEnd();

    //triangle
    glBegin(GL_POLYGON);

        glVertex2f(2.0, 0.0);
        glVertex2f(4.0, -4.0);
        glVertex2f(0.0,-4.0);
    glEnd();

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("National Flag");
    glutDisplayFunc(mydisplay);
    init();

    glutMainLoop();

}