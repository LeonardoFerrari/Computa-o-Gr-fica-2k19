#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h> 

//RA's: 176257 e 182787


void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void processMouse(int button, int state, int x, int y);


int main(int argc, char** argv){
  glutInit(&argc, argv);                              
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);           
  glutInitWindowSize (800, 800);                          
  glutInitWindowPosition (200, 200);                      
  glutCreateWindow ("RA201164_RA175352");              
  init();
  glutDisplayFunc(display);        
    glutMouseFunc(processMouse);             
  glutKeyboardFunc(keyboard);                             
  glutMainLoop();                                
  return 0;
}


void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);    
  glOrtho (0, 500, 0, 500, -1 ,1);     
} 

void processMouse(int button, int state, int x, int y){
   double  randomR = (double)rand() / (RAND_MAX);
   double  randomG = (double)rand() / (RAND_MAX);
   double  randomB = (double)rand() / (RAND_MAX);
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
// ------- Montagem do lápis ------- //		
		glBegin(GL_QUAD_STRIP); // Irá montar o corpo
    		glVertex2f(400,250);
    		glVertex2f(400,50);
    		glVertex2f(450,250);
    		glVertex2f(450,50);  
    	glEnd();
		glBegin(GL_TRIANGLE_STRIP);  // Monta a ponta 
	 		glColor3ub( rand()%255, rand()%255, rand()%255 );
			glVertex2f(400,250);
			glVertex2f(450,250);
			glVertex2f(425,300);
		glEnd(); 
		 
// ------- Montagem do lápis ------- //			
		glutPostRedisplay();
	}
	
}
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);    
	glLineWidth(3.0f);  
	// o Line strip necessita de ordenação, pois a linha anterior de código será conectada à próxima
	
// ------- Montagem da treliça ------- //		
	glBegin(GL_LINE_STRIP);    
 		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(30,200); // x = 30 y = 200
		glVertex2f(30,100); //      irá montar a treliça
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(200,100);    
		glVertex2f(200,200);
  		glVertex2f(30,200); // O ultimo vértice deve ser o primeiro, para assim serem ligados
	glEnd();    
	
// ----- Aqui ele irá traçar a parte de dentro ----- //	
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex2f(30,100);
		glVertex2f(58,200);
		glVertex2f(87,100);
		glVertex2f(115,200);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(144,100);
		glVertex2f(172,200);
		glVertex2f(200,100);
	glEnd;
	glBegin(GL_LINE_STRIP);
  	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(200,100);
  	glVertex2f(250,0);
  	glEnd();
  	
// ------- Montagem da linha divisória  ------- //	
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	    glVertex2f(250,0);
	    glVertex2f(250,800);
	glEnd();
	
	float random1 = rand();
	float random2 = rand();
	
   double  randomR = (double)rand() / (RAND_MAX);
   double  randomG = (double)rand() / (RAND_MAX);
   double  randomB = (double)rand() / (RAND_MAX);
	glBegin(GL_QUAD_STRIP);    
 		glColor3f( randomR, randomG, randomB );		
    		glVertex2f(400,250);
    		glVertex2f(400,50);
    		glVertex2f(450,250);
    		glVertex2f(450,50);
    		
    		 
	glEnd();    
	glBegin(GL_TRIANGLE_STRIP);   
 		glColor3ub( rand()%255, rand()%255, rand()%255 );
		glVertex2f(400,250);
		glVertex2f(450,250);
		glVertex2f(425,300);
	glEnd();    
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:                                         
	exit(0);
	break;
  }
}

