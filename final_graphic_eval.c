#include<stdio.h>
#include<GLUT/glut.h>

GLfloat x1,y1,x2,y2,x3,y3,x4,y4;
int xc = 70, yc = 105;
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  //glVertex2i(xc-x, yc-y);
  //glVertex2i(xc-y, yc-x);
  //glVertex2i(xc-x, yc+y);
  //glVertex2i(xc-y, yc+x);
  glEnd();
}
void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;
  plot_point(x,y);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}
void concentric_circles(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,0.0);
  int radius = 55;
  bresenham_circle(radius);
  radius = 35;
  bresenham_circle(radius);
}
void edgedetect(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,int *le,int *re)
{
      float mx,x,temp;
      int i;
      if((y2-y1)<0)
      {
        temp=x1;x1=x2;x2=temp;
        temp=y1;y1=y2;y2=temp;
      }
        if((y2-y1)!=0)
            mx=(x2-x1)/(y2-y1);
      else
            mx=x2-x1;
      x=x1;
      for(i=y1;i<y2;i++)
      {
            if(x<le[i])
                le[i]=x;

            if(x>re[i])
                re[i]=x;
            x+=mx;
      }
}
void drawpixel(int x,int y)
{
      glColor3f(1.0,0.0,0.0);
      glBegin(GL_POINTS);
      glVertex2i(x,y);
      glEnd();
}
void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
      int le[500],re[500];
      int i,y;
      for(i=0;i<500;i++)
      {
          le[i]=500;
          re[i]=0;
      }
      edgedetect(x1,y1,x2,y2,le,re);
      edgedetect(x2,y2,x3,y3,le,re);
      edgedetect(x3,y3,x4,y4,le,re);
      edgedetect(x4,y4,x1,y1,le,re);
      for(y=0;y<500;y++)
      {
          if(le[y]<=re[y])
          for(i=le[y]+1;i<re[y];i++)
              drawpixel(i,y);
      }
}
void display()
{
      glClear(GL_COLOR_BUFFER_BIT);
      concentric_circles();
      glColor3f(0.0,0.0,0.0);
      glBegin(GL_LINES);
          glVertex2f(50, 70);
          glVertex2f(50, 140);
      glEnd();
      glBegin(GL_LINES);
          glVertex2f(70, 70);
          glVertex2f(70, 140);
      glEnd();
      glColor3f(1.0,0.0,0.0);
      x1=50,y1=50,x2=70,y2=50,x3=70,y3=70,x4=50,y4=70;
      glBegin(GL_LINE_LOOP);
          glVertex2f(x1,y1);
          glVertex2f(x2,y2);
          glVertex2f(x3,y3);
          glVertex2f(x4,y4);
      glEnd();
      scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
      x1=50,y1=140,x2=70,y2=140,x3=70,y3=160,x4=50,y4=160;
      glBegin(GL_LINE_LOOP);
          glVertex2f(x1,y1);
          glVertex2f(x2,y2);
          glVertex2f(x3,y3);
          glVertex2f(x4,y4);
      glEnd();
      scanfill(x1,y1,x2,y2,x3,y3,x4,y4);

      glFlush();
}
void Init()
{
      glClearColor(1.0,1.0,1.0,1.0);
      glColor3f(0.0,0.0,0.0);
      glPointSize(1.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main(int argc,char **argv)
{
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(500,500);
      glutInitWindowPosition(0,0);
      glutCreateWindow("Test");
      glutDisplayFunc(display);
      Init();
      glutMainLoop();
      return 0;
   }
