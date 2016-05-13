#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

/*------------- Code Info --------------

Student Name : Daniel Rejniak
Student : 12483958

------------- Instructions -------------

I have implemented all of the features such as brightnes and transparancy.

To start using the program firstly select a color from the color spectrum by 
clicking the right mouse button. This selects the color from palet.

To draw a shape simply navigaate to draw window right click it to select the
type of the shape to be drawn. Use left mouse button to draw.

For Line : Select starting point and ending point.
For Square / Restangle : Select starting point and ending point.
For Triangle : Select three points of the triangle.
For Pentagon : Select five points.
For Clear Screen : select clear option form the drawign menu.

To change brightness navigate to color palet ang right right click to select one 
of th eoptions. Brightnes & Transparancy.

Brightnes : Simply Increase increase or decrease the transparaency. Increased and decreased by 0.1 at time.
Transparancy : Select range of transparancy optios ranging from 0% meaning the drawing will not be trasnparent to 
100% transparent meaning drawing will be fully transparent.



################################################################################################################################

NOTE.. THE CODE WAS WRITEN AND TESTED ON MAC OSX SYSTEM I DID NOT GET A CHANCE TO TEST IT ON THE LAB MACHINES.

THE HEADERS USED FOR COMPILING WERE AS FOLLOW : 

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

TO ENABLE IT RUN ON WINDOWS MACHINE I INSERTED THE ORIGINAL HEADERS FROM THE LABS BUT WAS NOT ABLE TO PERFORM 
A TEST RUN ON WINDOWS MACHINE.

#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

THE CODE COMPLILES AND RUNS WITH NO ERRORS ON MAC OSX ENVIROMENT I HOPE THAT BY SIMPLY CHANGING THE 
TOP HEADERS TO THE ABOVE THE CODE WILL FUNCTION THE SMAE ON WINDOWS MACHINE. 

THE COMMAND TO COMPILE THE CODE ON OSX SYSTEM :

gcc opengl_assignment_2.c -o opengl_assignment_2 -framework OpenGL -framework GLUT

THE COMMAND TO RUN THE CODE ON OSX SYSTEM :

./opengl_assignment_2

################################################################################################################################


*/

//Initialise Components
#define Test_1    1
#define Test_2    2
#define Test_3    3
#define Test_4    4
#define Test_5    5
#define Test_6    6

void drawMenu(int);
void colorMenu(int);
void transparancyMenu(int);
void brightnessMenu(int);
int select; 

int colorMenuId;
int drawMenuId;
int brightnessMenuId;
int transparancyMenuId;

int mousex, mousey;

GLfloat x1,x2,y1,y2,x3,y3,x4,y4,x5,y5;
GLfloat x_Src, y_Src, x_Dest, y_Dest;
GLfloat hh;
float pick[3];

//Set Transparancy To 1 By Default
float transparancy = 1.0;

void display(void)
{
	glPointSize(6.0);
	
	if(select == 1)
	{	
		//Line vertices
		glBegin(GL_LINES);
		glColor4f(pick[0],pick[1],pick[2],transparancy);
			glVertex2i(x1,y1);
			glVertex2i(x2,y2);
		glEnd();
	}

	if(select == 2)
	{	
		//Rectangle
		glBegin(GL_POLYGON);
		//glColor3f(pick[0],pick[1],pick[2]);
		glColor4f(pick[0],pick[1],pick[2],transparancy);
			glVertex2f(x1,y1);
			glVertex2f(x1,y2);
			glVertex2f(x2,y2);
			glVertex2f(x2,y1);
		glEnd();
	}

	if(select == 3)
	{
		//Triangle
		glBegin(GL_TRIANGLES);
        glColor4f(pick[0],pick[1],pick[2],transparancy);
	        glVertex2f(x1, y1);
	        glVertex2f(x2, y2);
	        glVertex2f(x3, y3);
        glEnd();
	}

	if(select == 4)
	{
		//Pentagon
		glBegin(GL_POLYGON);
        glColor4f(pick[0],pick[1],pick[2],transparancy);
	        glVertex2f(x1, y1);
	        glVertex2f(x2, y2);
	        glVertex2f(x3, y3);
	        glVertex2f(x4, y4);
	        glVertex2f(x5, y5);
        glEnd();	
	}

	glFlush();
	return;
}

//Color Picker Color Spectrum
void colorPicker(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);       
		glColor3f(1.0, 0.0, 0.0); // Red
       	glVertex2f(-1, 1);
	    glColor3f(0.0, 1.0, 0.0); // Green
	    glVertex2f(-1, -1);
	    glColor3f(0.0, 0.0, 1.0); // Blue
	    glVertex2f(1, -1);
	    glColor3f(0.0, 0.0, 0.0); // Black
	    glVertex2f(1, 1);
    glEnd();

    glFlush();
	return;


}

//Generic Mouse Function To Select Two points x1,y1 // x2,y2
void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (first)
		{
			x1=x; 
			y1=hh-y;
		}
		else
	    {
	        x2=x;
			y2=hh - y;
	        glutPostRedisplay();
	    }
	    first = !first;
	}

	return;
}

// Mouse Function For Drawing Triangle
void MyTriangle(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (first == 1)
	    {
	        x1=x; 
			y1=hh -y;

			first++;

	    }
	    else if(first == 2)
	    {
	        x2=x;
			y2=hh - y;
			first++;
	        //glutPostRedisplay();
	    }
	    else
	    {
	    	x3=x;
			y3=hh - y;
			first = 1;
	        glutPostRedisplay();
	    }
	    
	}

	return;
}

//Mouse Function For Drawing Pentagon
void MyPentagon(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (first == 1)
	    {
	        x1=x; 
			y1=hh -y;
			first++;

	    }
	    else if(first == 2)
	    {
	        x2=x;
			y2=hh - y;
			first++;
	    }
	    else if(first == 3)
	    {
	    	x3=x;
			y3=hh - y;
			first++;
	    }
	    else if(first == 4)
	    {
	    	x4=x;
			y4=hh - y;
			first++;
	    }
	    else if(first == 5)
	    {
	    	x5=x;
			y5=hh - y;
			first = 1;
	        glutPostRedisplay();
	    }
	}
	return;
}

//Mouse Function For Color Picker
void colorMouse(GLint button, GLint state, GLint x, GLint y)
{
	
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		
			mousex=x; 
			mousey=hh -y;
			glutPostRedisplay();
	}

	glReadPixels(mousex , mousey , 1 , 1 , GL_RGB , GL_FLOAT , &pick);

}

// Reshape Function Form The Lab Sample Programms
void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);
	glViewport(0,0,w,h);
	hh=h;
	return;
}

//Clear The Drawing Display 
void clear()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	display();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	//Initialize The Window Size
	glutInitWindowSize(500,500);

	//Color Picker Window
	glutInitWindowPosition(610,200);
	glutCreateWindow("Color Picker");
	glutDisplayFunc(colorPicker);

	glutMouseFunc(colorMouse);

	// Create Brightnes Menu
    brightnessMenuId = glutCreateMenu(brightnessMenu);

    // Brightnes Menu Items
    glutAddMenuEntry("+ Increae Brightnes", Test_1);
    glutAddMenuEntry("- Decrese Brightnes", Test_2);
    
    // Create Transparancy Menu
    transparancyMenuId = glutCreateMenu(transparancyMenu);

    // Transparancy Menu items
    glutAddMenuEntry("0%", Test_1);
    glutAddMenuEntry("20%", Test_2);
    glutAddMenuEntry("40%", Test_3);
    glutAddMenuEntry("60%", Test_4);
    glutAddMenuEntry("80%", Test_5);
    glutAddMenuEntry("100%", Test_6);

    // Create Color Menu
    colorMenuId = glutCreateMenu(colorMenu);
    glutAddSubMenu("Brightnes", brightnessMenuId);
    glutAddSubMenu("Transparancy", transparancyMenuId);

    // Associate a mouse button with color picker menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	//Draw Window 
	glutInitWindowPosition(100,200);
	glutCreateWindow("Drawing Window");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	glutDisplayFunc(display);

    // Create draw menu
    glutCreateMenu(drawMenu);

    // Draw Menu items
    glutAddMenuEntry("Line", Test_1);
    glutAddMenuEntry("Square / Rectangle", Test_2);
    glutAddMenuEntry("Triangle", Test_3);
    glutAddMenuEntry("Pentagon", Test_4);
    glutAddMenuEntry("Clear", Test_5);

    // Associate a mouse button with draw menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Call The Reshape Function
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}

//Drawing Menu Commands
void drawMenu(int item)
{
  switch (item) {  

  //Draw Line                   
  case Test_1:

  	select = 1;
  	glutMouseFunc(MyMouse);
    break;

  //Draw Square / Rectangle  
  case Test_2:
    
    select = 2;
    glutMouseFunc(MyMouse);
    break;

  //Draw Triangle  
  case Test_3:
    select = 3;
    glutMouseFunc(MyTriangle);
    break;

  //Draw Pentagon  
  case Test_4:
    select = 4;
    glutMouseFunc(MyPentagon);
    break;  

  //Clear  
  case Test_5:
  	select = 0;
    clear();
   }
}

//Color Menu Commands
void colorMenu(int item){} 

//Brightnes Menu Commands
void brightnessMenu(int item)
{
  switch (item) {  

  //Increase Brightnes                 
  case Test_1:
  	pick[0] = pick[0] + 0.1;
  	pick[1] = pick[1] + 0.1;
  	pick[2] = pick[2] + 0.1;
    break;

  //Decrease Transparency  
  case Test_2:
 	pick[0] = pick[0] - 0.1;
  	pick[1] = pick[1] - 0.1;
  	pick[2] = pick[2] - 0.1;
    break;     

  }
}  

//Transparancy Menu
void transparancyMenu(int item)
{
  switch (item) {  
               
  case Test_1:
  	transparancy = 1.0;
    break;
    
  case Test_2:
  	transparancy = 0.8;
    break;
     
  case Test_3:
    transparancy = 0.6;
    break;
     
  case Test_4:
  	transparancy = 0.4;
    break;
     
  case Test_5:
  	transparancy = 0.2;
    break; 

  case Test_6:
  	transparancy = 0.0;
    break;        

  }
}   