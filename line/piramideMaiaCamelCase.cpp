#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define textura "TCG1.tga"

#define PI_ 3.14159265358979323846

// Nomes: Nykson Souza Krenkin da Silva RA: 175352    Leonardo Ferrari Soares RA:201164

float zoom = -45.0;
float test = 00.0;

static int shoulder = 0, elbow = 0, elbow2 = 0;


static int rodatudo = 0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}



void display(void){
	
	glEnable(GL_TEXTURE_2D);
glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
GLuint texture_id[1];
glGenTextures (1, texture_id);

texture_id[0] = 1001;

glBindTexture (GL_TEXTURE_2D, textura);

image_t temp_image;
tgaLoad ( "TCG1.tga", &temp_image, TGA_FREE | TGA_LOW_QUALITY ); 

glTexCoord2f(1.0f, 0.0f); glVertex3f( 5.0f, -1.0f, -5.0f); 
glTexCoord2f(1.0f, 1.0f); glVertex3f( 5.0f, 1.0f, -5.0f); 
glTexCoord2f(0.0f, 1.0f); glVertex3f( 5.0f, 1.0f, 5.0f); 
glTexCoord2f(0.0f, 0.0f); glVertex3f( 5.0f, -1.0f, 5.0f);
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  glRotatef ((GLfloat) rodatudo, 1.0, 0.0, 0.0);
	
	glEnable ( GL_TEXTURE_2D );
  
  //glutSolidCube(5.0);
  	
  	glPushMatrix();
  glTranslatef (0.0, 0.0, 0.0);
  glScalef (5.0, 1.0, 5.0);
  glutSolidCube (5.0);
  glPopMatrix();

  	
  	glPushMatrix();
  glTranslatef (0.0, 1.5, 0.0);
  glScalef (4.0, 1.0, 4.0);
  glutSolidCube (5.0);
  glPopMatrix();

	
  	glPushMatrix();
  glTranslatef (0.0, 2.5, 0.0);
  glScalef (3.0, 1.0, 3.0);
  glutSolidCube (5.0);
  glPopMatrix();

	
  	glPushMatrix();
  glTranslatef (0.0, 3.5, 0.0);
  glScalef (2.0, 1.0, 2.0);
  glutSolidCube (5.0);
  glPopMatrix();

	
  	glPushMatrix();
  glTranslatef (0.0, 6.5, 0.0);
  glScalef (1.0, 0.25, 1.0);
  glutSolidCube (5.0);
  glPopMatrix();

 
  
  glPushMatrix();
  glTranslatef(-10.0, 20.0,0.0);
  glColor3f(1,0.5,0); 
  glutSolidSphere(5.0,12.5,12.5);
  
  glPopMatrix(); 


glEnd();

  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 85.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (test, 0.0, zoom);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
 case 'q':
    rodatudo = (rodatudo + 2) % 360;
    glutPostRedisplay();
    break;
  case 'Q':
    rodatudo = (rodatudo - 2) % 360;
    glutPostRedisplay();
    break;
	   
   case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}



void mouse(int button, int state, int zoom, int test)
{
    if (button == GLUT_LEFT_BUTTON )
        {
            zoom = zoom +0.1;
            test = test;
            reshape(test,zoom);

        }

        if (button == GLUT_RIGHT_BUTTON )
        {
            zoom = zoom - 0.1;
            test = test;
            reshape(test,zoom);

        }


}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
   glutMouseFunc(mouse);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
