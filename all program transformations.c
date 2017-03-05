/*Write a program to draw a triangle on black background*/
#include <GLUT/glut.h>
float x[3],y[3],tqx,tqy;

void transform(void);
void scale(void);
void rotate(void);
void reflect(void);
void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
  glVertex2i( x[0], y[0]);    // lower left vertex
  glVertex2i( x[1], y[1]);    // lower right vertex
  glVertex2i( x[2], y[2]);    // upper vertex
  glEnd();

  glBegin(GL_LINES);
  glVertex2i(0 , 2);
  glVertex2i(500 , 502);
  glEnd();
  //  transform();
  //  scale();
  //  rotate();
  // reflect();
  glFlush ();
}

void transform()
{
float a[3][1],b[3][3] = {1,0,tqx,0,1,tqy,0,0,1} ,c[3][1]={0};

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
    printf("x = %f, y = %f",c[0][0],c[1][0]);

    glVertex2i( c[0][0], c[1][0]);

    c[0][0]=0;c[1][0]=0;c[2][0] = 0;
  }

glEnd();
glFlush();
}

void scale()
{
float a[3][1],b[3][3] = {tqx/20,0,1,0,tqy/20,1,0,0,1} ,c[3][1]={0};

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
    printf("x = %f, y = %f",c[0][0],c[1][0]);

    glVertex2i( c[0][0], c[1][0]);

    c[0][0]=0;c[1][0]=0;c[2][0] = 0;
  }

glEnd();
glFlush();
}
void rotate()
{
float a[3][1],b[3][3] = {cos(0.785),-sin(0.785),0,sin(0.785),cos(0.785),0,0,0,1} ,c[3][1]={0};

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
    printf("x = %f, y = %f",c[0][0],c[1][0]);

    glVertex2i( c[0][0], c[1][0]);

    c[0][0]=0;c[1][0]=0;c[2][0] = 0;
  }

glEnd();
}

void init (void)
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640,0,480);
}
void reflect()
{
float a[3][1],b[3][3] = {0,1,2,1,0,-2,0,0,1} ,c[3][1]={0};

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
    printf("x = %f, y = %f",c[0][0],c[1][0]);

    glVertex2i( c[0][0], c[1][0]);

    c[0][0]=0;c[1][0]=0;c[2][0] = 0;
  }

glEnd();
glFlush();
}

int main(int argc, char** argv)
{
  printf("Enter co-ordinates for the triangle\n");
  scanf("%f %f %f %f %f %f",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
  //printf("Transform values");
  //scanf("%f %f",&tqx,&tqy);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("dhi");
    init ();
  glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
