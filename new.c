/*Write a program to draw a triangle on black background*/
//#include <GL/gl.h>
#include <GLUT/glut.h>
#include<stdio.h>

void display(float x,float y)
{
/*  clear all pixels  */
  //  glClear (GL_COLOR_BUFFER_BIT);

/*  draw white polygon (rectangle) with corners at
 *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
 */

    glBegin(GL_TRIANGLES);
        glVertex3f( 25.0f+x, 0+y, 0.0f);    // lower left vertex
	glVertex3f( 75.0f+x, 0+y, 0.0f);    // lower right vertex
	glVertex3f( 50.0f+x,  75.0f+y, 0.0f);    // upper vertex

  glEnd();


/*  don't wait!
 *  start processing buffered OpenGL routines
 */
    //glFlush ();
}

void init (void)
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
float x,y;
scanf("%f%f",&x,&y);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (750, 750);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    //glutDisplayFunc(display);
glClear(GL_COLOR_BUFFER_BIT) ;
display(0,0);
//float x,y;
//scanf("%f%f",&x,&y);
display(x,y);
glFlush();
	glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}
