/*2D transformations on a triangle*/
#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

float b[3][3],x[3]={300, 400, 500},y[3]={100, 200, 100};
void matrix(void);
void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_TRIANGLES);
  glVertex2i( x[0], y[0]);    // lower left vertex //galt e
  glVertex2i( x[1], y[1]);    // lower right vertex
  glVertex2i( x[2], y[2]);    // upper vertex
  glEnd();

  glColor3f(1.0,0.0,0.0);
  matrix();
  glFlush ();
}

void matrix()
{
float a[3][1], c[3][1]={0};

glBegin(GL_TRIANGLES);

for(int i=0;i<3;++i)
  {
  a[0][0] = x[i];
  a[1][0] = y[i];
  a[2][0] = 1;
  for(int j=0;j<3;++j)
    {
    for(int k=0;k<3;++k)
      {
        c[j][0]+=b[j][k]*a[k][0];
      }
    }
    //printf("x = %f, y = %f",c[0][0],c[1][0]);
    glVertex2i( c[0][0], c[1][0]);
    c[0][0]=0;c[1][0]=0;c[2][0] = 0;
  }
glEnd();
glFlush();
}

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640,0,480);
}

int main(int argc, char** argv)
{
    int i,tqx=0,tqy=0;
    float sx=1.0,sy=1.0,theta=0.0;
    printf("What do you want to do?\n1. Transform\n2. Scale\n3. Rotate\t");
    scanf("%d",&i);
    switch (i)
    {
      case 1:
            printf("Enter translation co-ordinates (tx,ty)\t");
            scanf("%d %d",&tqx,&tqy);
            b[0][0]=1;b[0][1]=0;b[0][2]=tqx; //b[3][3]={1,0,tqx,0,1,tqy,0,0,1}
            b[1][0]=0;b[1][1]=1;b[1][2]=tqy;
            b[2][0]=0;b[2][1]=0;b[2][2]=1;
            break;
      case 2:
            printf("Enter scaling co-efficients (sx,sy)\t");
            scanf("%f %f",&sx,&sy);
            b[0][0]=sx;b[0][1]=0;b[0][2]=0; //b[3][3]={sx,0,0,0,sy,0,0,0,1}
            b[1][0]=0;b[1][1]=sy;b[1][2]=0;
            b[2][0]=0;b[2][1]=0;b[2][2]=1;
            break;
      case 3:
            printf("Enter angle of rotation (in degrees)\t");
            scanf("%f",&theta);
            theta=theta*PI/360.0; // goes anticlockwise
            //b[3][3]={cos(theta),-sin(theta),0,sin(theta),cos(theta),0,0,0,1}
            b[0][0]=cos(theta);b[0][1]=-sin(theta);b[0][2]=0;
            b[1][0]=sin(theta);b[1][1]=cos(theta);b[1][2]=0;
            b[2][0]=0;b[2][1]=0;b[2][2]=1;
            break;
      default:
            break;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("2D Transformations");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
