/*Write a program to draw a green color line from (10,10) to (50,50) */
#include<GL/glut.h>
void DisplayLine ( void ) {
glClear ( GL_COLOR_BUFFER_BIT ); //clear pixel buffer
glBegin(GL_LINES);
    glVertex2f(10, 10);
    glVertex2f(20, 20);
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
glutCreateWindow("New Green Line");
MyInit ( );
glutDisplayFunc ( DisplayLine );
glutMainLoop();
return 0;
}
