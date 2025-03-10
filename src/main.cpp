#include <GL/glut.h>
#include <Windows.h>
#include <math.h>

const int screenHeight = 480;
const int screenWidth = 640;
void init()
{
    glClearColor(1,1,1,1);

    //Set up Light
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);

    GLfloat lightIntensity[] = {0.7f, 0.7f,0.7f,1.0f};
    GLfloat lightPosition[] = 

    glColor3f(1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.5,4.5,-4.5,4.5,-1.0,1.0);

}
//test





void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,1);
    drawCircle(0,0,R,100);
    glPointSize(5);
    glLineWidth(5);
    Point2D center = {0,0};
    for(int i = 0; i < ARCDIV*5; i++)
    {
        drawPoint(circleArr[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        drawLine(center,circleArr[i*ARCDIV]);
    }
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