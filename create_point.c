/*Write a program to draw a point of width 10 pixel*/
#include<GL/glut.h>
void Displaydot ( void ) {
glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_POINTS); // render with points
glVertex2i(50,40); //display a point
glEnd();
glFlush();
}
void MyInit ( void ) {

glClearColor ( 1.0, 1.0, 1.0, 0.0 ); //white background
glColor3f(0.0f, 1.0f,0.0f); // green drawing colour
glPointSize(10.0); // 10 pixel dot!
glMatrixMode ( GL_PROJECTION );
glLoadIdentity ( );
gluOrtho2D ( 0.0, (GLdouble)100, 0.0, (GLdouble)100 ); //Display area
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,25);
glutInitWindowSize(500,250);
glutCreateWindow("Green window");
MyInit ( );
glutDisplayFunc ( Displaydot );
glutMainLoop();
return 0;
}
