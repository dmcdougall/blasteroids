#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

#include "data.h"

#define TIMERMSECS 17

float CURRENT_TIME = 0.0;
float PREV_TIME = 0.0;
float dt = 0.0;
float rotrate = 50.0;

void renderScene(int value) {
  PREV_TIME = CURRENT_TIME;
  CURRENT_TIME = glutGet(GLUT_ELAPSED_TIME);
  dt = (CURRENT_TIME - PREV_TIME) / 1000.0;

  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();
  glRotatef(s.dir_angle, 0.0, 0.0, 1.0);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, s.coords);
  glDrawArrays(GL_LINE_LOOP, 0, s.numVertices);
  glDisableClientState(GL_VERTEX_ARRAY);
 
  glutSwapBuffers();
  glutPostRedisplay();
  s.dir_angle += rotrate * dt;
}

void changeSize(int w, int h) {
  float ratio;

  if (h == 0) {
    h = 1;
  }
  ratio = (float) 1.0 * w / h;

  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-320, 320, -200, 200);
  glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
  if (key == 27) {
    exit(0);
  }
}

void processSpecialKeys(int key, int x, int y) {
  float fraction = 0.1;
  switch (key) {
    case GLUT_KEY_LEFT:
      break;
    case GLUT_KEY_RIGHT:
      break;
    case GLUT_KEY_UP:
      break;
    case GLUT_KEY_DOWN:
      break;
  }
}

void displayScene(void) {
  renderScene(0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 400);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutCreateWindow("Blasteroids");
  glutDisplayFunc(displayScene);
  glutReshapeFunc(changeSize);

  /* glutKeyboardFunc(processNormalKeys); */
  /* glutSpecialFunc(processSpecialKeys); */

  setup_data();
  CURRENT_TIME = glutGet(GLUT_ELAPSED_TIME);
  glutMainLoop();

  return 0;
}
