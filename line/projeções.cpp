#include<stdlib.h>
#include<GL/glut.h>
#include <math.h>


static int rodatudo = 0;
const float DEG2RAD = 3.14159/180;



void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
      glColor3f (0.0, 0.0, 0.0);

      glVertex3f (0.1, 0.1, 0.0);
      glVertex3f (0.9, 0.1, 0.0);
      glVertex3f (0.9, 0.9, 0.0);
      glVertex3f (0.1, 0.9, 0.0);

    glEnd();

    glFlush();
}


void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  glRotatef ((GLfloat) rodatudo, 0.0, 1.0, 0.0);
  
  /* chao */
  glPushMatrix();
//  glTranslatef (-2.0, 0.0, 0.0);
  glScalef (50.0, 1.0, 40.0);
  glutWireCube (1.0);
  glPopMatrix();
   
  /* Coluna*/ 
  glPushMatrix();
//  glRotatef (25.0, 0.0, 0.0, 1.0);
  glTranslatef (0.0, 5.5, -21.5);
  glScalef (3.0, 10.0, 3.0);
  glutWireCube (1.0);
  // glutSolidCube (1.0);
  glPopMatrix();

// ------------------------------------------- //

	/* ----- Postes ------ */
  glPushMatrix();
  glTranslatef (23.0, 10.0, 17.5);
  glScalef (4.0, 20.0, 4.5);
  glutWireCube (1.0);
  glPopMatrix();
  
  glPushMatrix();
  glTranslatef (-23.0, 10.0, -17.5);
  glScalef (4.0, 20.0, 4.5);
  glutWireCube (1.0);
  glPopMatrix(); 
  
  glPushMatrix();
  glTranslatef (23.0, 10.0, -17.5);
  glScalef (4.0, 20.0, 4.5);
  glutWireCube (1.0);
  glPopMatrix(); 
  
  glPushMatrix();
  glTranslatef (-23.0, 10.0, 17.5);
  glScalef (4.0, 20.0, 4.5);
  glutWireCube (1.0);
  glPopMatrix();
  
   
  
  glBegin(GL_LINE_LOOP);
				for(int i =0; i < 300; i++){
					double angle =  2 * DEG2RAD * i / 300;
					double x = cos(angle);
					double y = sin(angle);
					glVertex2d(x,y);
				}
			glEnd();
			
	
  
  
// ------------------------------------------- //
  
   /* suporte */
  glPushMatrix();
  glTranslatef (0.0, 12.0, -19.5);
  glScalef (3.0, 2.0, 7.0);
  glutWireCube (1.0);
  glPopMatrix();

     /* Cobertura*/ 
  glPushMatrix();
  glTranslatef (0.0, 8.5, -16.0);
  glScalef (12.0, 1.0, 8.0);
  glutWireCube (1.0);
  glPopMatrix();

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
  glTranslatef (0.0, -5.0, -50.0);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
 case 'r':
    rodatudo = (rodatudo + 5) % 360;
    glutPostRedisplay();
    break;
  case 'R':
    rodatudo = (rodatudo - 5) % 360;
    glutPostRedisplay();
    break;
   case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
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
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

