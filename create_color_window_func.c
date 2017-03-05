/*Write a program to create empty window (Black, White and different Colors)*/
#include<GL/glut.h>
void draw(void)
{
glClearColor(0,1,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,25);
glutInitWindowSize(500,250);
glutCreateWindow("Green window");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
