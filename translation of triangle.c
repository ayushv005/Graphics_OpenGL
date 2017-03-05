/*Write a program to draw a green color line from (10,10) to (50,50) */
#include<GLUT/glut.h>
#include <stdio.h>

int xt=0,yt=0;
void DisplayLine ( ) {
glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_LINES);
    glVertex2i(25+xt, 25+yt);
    glVertex2i(50+xt, 75+yt);
    glVertex2i(50+xt, 75+yt);
    glVertex2i(75+xt, 25+yt);
    glVertex2i(75+xt, 25+yt);
    glVertex2i(25+xt, 25+yt);
glEnd();
glFlush();
}
void MyInit ( void ) {

glClearColor ( 1.0, 1.0, 1.0, 0.0 ); //white background
glColor3f(0.0f, 0.0f,0.0f); // green drawing colour
glPointSize(10.0); // 10 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)100, 0.0, (GLdouble)100 ); //Display area
}
int main(int argc, char **argv)
{
  printf("Enter x and y translation co-ordiantes\n");
  scanf("%d%d",&xt,&yt);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,25);
glutInitWindowSize(500,500);
glutCreateWindow("New Green Line");
MyInit ( );
//glClear ( GL_COLOR_BUFFER_BIT );
glutDisplayFunc(DisplayLine);
//glFlush();
glutMainLoop();
return 0;
}
