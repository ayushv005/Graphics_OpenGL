/*WAP to create empty window*/
#include<GL/glut.h>
int main(int argc, char **argv)
{
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowSize(300, 300);
glutInitWindowPosition(200, 200);
glutCreateWindow("New Window"); 
glClearColor(0.0f,0.0f,0.0f,0.0f);
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
glutMainLoop(); 
return 0;
}
