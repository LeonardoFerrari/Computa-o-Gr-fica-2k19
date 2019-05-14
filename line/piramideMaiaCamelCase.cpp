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

#define PI_ 3.14159265358979323846

// Nomes: Nykson Souza Krenkin da Silva RA: 175352    Leonardo Ferrari Soares RA:201164

float zoom = -45.0;
float test = 00.0;

static int shoulder = 0, elbow = 0, elbow2 = 0;


static int rodatudo = 0;

void init(void){
  
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
	
	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz ); 
   
  
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   
    // Habilita a definição da cor do material a partir da cor corrente
        glEnable(GL_COLOR_MATERIAL);
        //Habilita o uso de iluminação
        glEnable(GL_LIGHTING);  
        // Habilita a luz de número 0
        glEnable(GL_LIGHT0);
        // Habilita o depth-buffering
        glEnable(GL_DEPTH_TEST);
 
        // Habilita o modelo de colorização de Gouraud
        glShadeModel(GL_SMOOTH);
   
   		  
  }




void display(void){
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  
  glPushMatrix();

  glRotatef ((GLfloat) rodatudo, 1.0, 0.0, 0.0);

  
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
