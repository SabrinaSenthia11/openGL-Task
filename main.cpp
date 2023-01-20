#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535898
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius,GLfloat r,GLfloat g,GLfloat b){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
     glColor3f(r,g,b);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void display(void)
{ /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.5);


    //rectan
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0, 10.0);
    glVertex2f(10.0, 10.0);
    glVertex2f(10.0, -10.0);
   glVertex2f(-10.0, -10.0);
    glEnd();
    glColor3f (0.25, 1.0, 0.25);

// big circle 1st half.....
    GLint circle_points = 200;
    GLfloat angle; glLineWidth(1.5);
    glColor3f(0,0,0.8);
    glBegin(GL_POLYGON);
    for (int i = 0; i < (circle_points); i++)
        {
            angle = 2*PI*i/circle_points;
            glVertex2f(cos(angle)/0.3, sin(angle)/0.3);
        }
     glEnd();
    // big circle 2nd half...
         glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for (int i = -30; i < (circle_points-40); i++)
        {
            angle = PI*i/circle_points;
            glVertex2f(cos(angle)/0.3, sin(angle)/0.3);
        }
     glEnd();
     drawFilledCircle(1.27,-1.2,1.73,0,0,0.8);
      drawFilledCircle(-1.23,1.2,1.73,1,0,0);
    /* don't wait!
    * start processing buffered OpenGL routines */
/*      Line
glColor3f(1,0,1);
 glBegin(GL_LINES);
 glVertex2f(-10.0,8.0);
 glVertex2f(10.0,-8.0);
 glVertex2f(-10.0,-8.0);
 glVertex2f(10.0,8.0);
 glEnd();
 */
//Left top lines
 glLineWidth(12.5);

       glColor3f(0,0,0);
 glBegin(GL_LINES);

 glVertex2f(-8.0,4.0);
 glVertex2f(-6.0,6.0);
  glVertex2f(-8.5,4.5);
 glVertex2f(-6.5,6.5);
 glVertex2f(-7.5,3.5);
 glVertex2f(-5.5,5.5);

 glEnd();

//Left down lines
glColor3f(0,0,0);
  glBegin(GL_LINES);

 glVertex2f(-8.0,-4.0);
 glVertex2f(-6.0,-6.0);

  glColor3f(1,1,1);
  glVertex2f(-9.0,-7.2);
 glVertex2f(-5.0,-3.2);

glColor3f(0,0,0);
 glVertex2f(-8.5,-4.5);
 glVertex2f(-6.5,-6.5);


 glVertex2f(-7.5,-3.5);
 glVertex2f(-5.5,-5.5);

 glEnd();

 //Right top lines

  glBegin(GL_LINES);

 glVertex2f(8.5,4.5);
 glVertex2f(6.5,6.5);



 glVertex2f(7.5,3.5);
 glVertex2f(5.5,5.5);

  glColor3f(1,1,1);
  glVertex2f(9.0,7.2);
 glVertex2f(5.0,3.2);

glColor3f(0,0,0);
 glVertex2f(8.0,4.0);
 glVertex2f(6.0,6.0);

 glEnd();
//right down lines


    glColor3f(0,0,0);
 glBegin(GL_LINES);
 glVertex2f(8.5,-4.5);
 glVertex2f(6.5,-6.5);

 glVertex2f(8.0,-4.0);
 glVertex2f(6.0,-6.0);

 glVertex2f(7.5,-3.5);
 glVertex2f(5.5,-5.5);
  glColor3f(1,1,1);
  glVertex2f(9.0,-7.2);
 glVertex2f(5.0,-3.2);

 glEnd();

    glFlush();
    }
    void init (void)
    {
        /* select clearing color */
        glClearColor (1, 1, 1, 0.0);
        /* initialize viewing values */
        glOrtho(-10, 10, -8, 8, -10, 10);
        }


        /*
        * Declare initial window size, position, and display mode
        * (single buffer and RGBA). Open window with "hello"
        * in its title bar. Call initialization routines.
        * Register callback function to display graphics.
        * Enter main loop and process events.
        */
        int main()



        {
            glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Mode for later glutCreateWindow()

            glutInitWindowSize (400, 200);
            glutInitWindowPosition (100, 100);
            glutCreateWindow("South Korea National Flag");
            init();
            glutDisplayFunc(display);
            glutMainLoop();
            return 0;
            }
