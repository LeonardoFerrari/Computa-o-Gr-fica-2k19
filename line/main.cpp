/*

Nome: Leonardo Ferrari Soares 					RA: 201164
Nome: Nykson Souza Krenkin da Silva				RA: 175352


*/






#include <GL/glut.h>
#include <stdlib.h>

// prototipos das funcoes
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);


// funcao principal
int main(int argc, char** argv){
  glutInit(&argc, argv);                              // inicializa o glut
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);           // especifica o uso de cores e buffers
  glutInitWindowSize (256, 256);                          // especifica as dimensoes da janela
  glutInitWindowPosition (100, 100);                      // especifica aonde a janela aparece na tela
  glutCreateWindow ("Desenhando uma linha");              // cria a janela
  init();
  glutDisplayFunc(display);                               // funcao que sera redesenhada pelo GLUT
  glutKeyboardFunc(keyboard);                             // funcoes de teclado
  glutMainLoop();                                         // mostra todas as janelas criadas
  return 0;
}

// definicao de cada funcao

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);    // cor de fundo
  glOrtho (0, 500, 0, 500, -1 ,1);     // modo de projecao ortogonal
} 



void display(void){
  glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
  glColor3f (1, 0.0, 1);                  // cor da linha
  glPointSize(5); // Coloquei 5 como o tamanho do ponto para ser mais fácil de visualizar 
  glBegin(GL_POINTS);   
  glVertex2i(50,100); // Primeiro ponto
  glEnd();
  glBegin(GL_POINTS);
  glVertex2i(300,350);      // Segundo ponto
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}
