#include <GL/glut.h>
#include <Windows.h>
#include <math.h>

float R = 4;

#define PI 3.14159265358
#define ARCDIV 19
#define LINEDIV 16

struct Point2D
{
    float x, y;
};

Point2D pointArr[10];
Point2D circleArr[ARCDIV*5];
Point2D lineArr[5][LINEDIV+1];
Point2D arcArr[5][ARCDIV];



void drawPoint(Point2D p)
{
    glBegin(GL_POINTS);
        glVertex2f(p.x, p.y);
    glEnd();
}

void drawLine(Point2D p1, Point2D p2)
{
    glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
    glEnd();
}

void drawCircle(float x0, float y0, float R, int n = 40)
{
    float x, y;
    float angleinc = 2 * PI / n;
    float angle;
    glBegin(GL_LINE_LOOP);
    angle = 0;
    x = R * cos(angle);
    y = R * sin(angle);
    glVertex2f(x,y);
    for(int i = 0; i < n; i++)
    {
        angle += angleinc;
        x = R * cos(angle);
        y = R * sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
}

Point2D lineIntersection(Point2D p1, Point2D p2, Point2D p3, Point2D p4)
{
    Point2D t;
    float A1, B1, A2, B2;
    A1 = (p2.y - p1.y)/(p2.x - p1.x);
    B1 = p1.y - A1*p1.x;
    A2 = (p4.y - p3.y)/(p4.x - p3.x);
    B2 = p3.y - A2*p3.x;

    t.x = (B2 - B1)/(A1 - A2);
    t.y = A1*t.x +B1;
    return t;
    
}

void calculatePoint()
{
    for(int i = 0; i < ARCDIV * 5 ; i++)
    {
        circleArr[i].x = R * cos(PI/2 + i*2*PI/(ARCDIV*5));
        circleArr[i].y = R * sin(PI/2 + i*2*PI/(ARCDIV*5));
    }


}

void init()
{
    calculatePoint();
    glClearColor(1,0,0,0);
    glColor3f(1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.5,4.5,-4.5,4.5,-1.0,1.0);

}






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