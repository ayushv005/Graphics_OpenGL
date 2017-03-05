// Liang Barksy Line Clipping  Made by - Ayush Verma
#include<GLUT/glut.h>

float xmax=230, xmin=70, ymax=150, ymin=60, x0=30, x1=280, y0=20, y1=160;

void DisplayLine ( void ) {
glClear ( GL_COLOR_BUFFER_BIT );
glColor3f(0.0f, 0.0f,0.0f);
glBegin(GL_LINES);
    glVertex2f(30, 20);     // printing original line : color black
    glVertex2f(280, 160);
glEnd();

glColor3f(0.0f, 1.0f,0.0f);
glBegin(GL_LINES);
    glVertex2f(x0, y0);     // printing clipped line : color green
    glVertex2f(x1, y1);
glEnd();
// view window create
glColor3f(1.0f, 0.0f,0.0f);

glBegin(GL_LINES);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
glEnd();

glBegin(GL_LINES);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
glEnd();

glBegin(GL_LINES);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
glEnd();

glBegin(GL_LINES);
    glVertex2f(xmin, ymax);
    glVertex2f(xmin, ymin);
glEnd();

glFlush();
}
void MyInit ( void ) {

glClearColor ( 1.0, 1.0, 1.0, 0.0 ); //white background
glColor3f(0.0f, 0.0f,0.0f);   // black color
glPointSize(10.0); // 10 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)300, 0.0, (GLdouble)300 ); //Display area
}
int main(int argc, char **argv)
{
  // Liang-Barksy Algo implemented here
  float p[4],q[4],t[4];
  int i;
  float t1 = 0.0, t2 = 1.0;

  float dx = x1 - x0;
  float dy = y1 - y0;

  p[0] = -dx;   //left, right, bottom, top
  p[1] = dx;
  p[2] = -dy;
  p[3] = dy;

  q[0] = x0 - xmin;
  q[1] = xmax - x0;
  q[2] = y0 - ymin;
  q[3] = ymax - y0;

  for (i=0;i<4;i++)
  {
    t[i] = q[i]/p[i];
    if (p[i]==0 && q[i]<0)
    {
      //printf("Line parallel & outside clipping boundary for iteration %d\n",i+1);
    }
    if (p[i]==0 && q[i]>=0)
    {
      //printf("Line parallel and inside clipping boundary for iteration %d\n",i+1);
    }
    if (p[i]<0)
    {
      t1 = fmax(t1,t[i]);
    }
    if (p[i]>0)
    {
      t2 = fmin(t2,t[i]);
    }
  }

   x1 = x0 + t2*dx;
   y1 = y0 +t2*dy;
   x0 = x0 + t1*dx;
   y0 = y0 +t1*dy;

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,25);
glutInitWindowSize(300,300);
glutCreateWindow("Liang Barksy Clipping");
MyInit ( );
glutDisplayFunc ( DisplayLine );
glutMainLoop();
return 0;
}
