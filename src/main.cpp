#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>

float R = 4;

#define PI 3.14159265358
#define ARCDIV 19
#define LINEDIV 16

struct Point2D
{
    float x, y;
};

struct Point3D
{
    float x, y, z;
    Point3D(float x, float y, float z)
        : x(x)
        , y(x)
        , z(z)
    {

    }
    Point3D()
    {

    }
        
};

class VertexID
{
public:
    int vertIndex;

};

Point3D a{ 0,0,0 };
Point3D b{ 1,0,0 };
Point3D c{ 0,1,0 };
Point3D d{ 0,0,1 };

class Face
{
    public:
    int nVerts;
    VertexID* vert;

    Face()
    {
        nVerts = 0;
        vert = NULL;
    }

    ~Face()
    {
        if(vert != NULL)
        {
            delete[] vert;
            vert = NULL;
        }
        nVerts = 0;
    }
};

class Mesh
{
public:
    int Numsface;
    Face* face;

    int numVerts;
    Point3D* pt;

    Mesh()
    {
        numVerts = 0;
        pt = NULL;
        Numsface = 0;
        face = NULL;
    }
    ~Mesh()
    {
        if(pt!=NULL)    delete[] pt;
        if(face!=NULL)   delete[] face;
    }

    void DrawWireframe()
    {
        glColor3f(0,0,0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        for(int f = 0; f <Numsface; f++)
        {
            glBegin(GL_POLYGON);
            for(int v =0; v < face[f].nVerts ; v++)
            {
                int iv = face[f].vert[v].vertIndex;
                glVertex3f(pt[iv].x,pt[iv].y,pt[iv].z);
            }
            glEnd();
        }
    }

    void CreateTetrahedron(Point3D a, Point3D b,Point3D c,Point3D d)
    {
        numVerts = 4;
        pt = new Point3D[4];
        pt[0] = a;
        pt[1] = b;
        pt[2] = c;
        pt[3] = d;

        Numsface = 4;

        face = new Face[Numsface];
        face[0].nVerts = 3;
        face[0].vert = new VertexID[face[0].nVerts];
        face[0].vert[0].vertIndex = 1;
        face[0].vert[1].vertIndex = 2;
        face[0].vert[2].vertIndex = 3;

        face[1].nVerts = 3;
        face[1].vert = new VertexID[face[1].nVerts];
        face[1].vert[0].vertIndex = 0;
        face[1].vert[1].vertIndex = 2;
        face[1].vert[2].vertIndex = 1;

        face[2].nVerts = 3;
        face[2].vert = new VertexID[face[2].nVerts];
        face[2].vert[0].vertIndex = 0;
        face[2].vert[1].vertIndex = 3;
        face[2].vert[2].vertIndex = 2;

        face[3].nVerts = 3;
        face[3].vert = new VertexID[face[3].nVerts];
        face[3].vert[0].vertIndex = 1;
        face[3].vert[1].vertIndex = 3;
        face[3].vert[2].vertIndex = 0;
    }


};

float angle = 0;
Mesh myMesh;

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.7,0.5,0.3,0,0,0,0,1,0);
    glRotatef(angle,0,1,0);
    myMesh.DrawWireframe();
    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,1.5,-1.5,1.5,0.1,1000);

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
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Simple Data Structure");
    glutDisplayFunc(mydisplay);
    glutSpecialFunc(mySpecialFunc);

    myMesh.CreateTetrahedron(a, b, c, d);
    
    init();

    glutMainLoop();

}