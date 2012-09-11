#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

#include "data.h"

void renderScene(void) {
  int i;
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, s.coords);
  glDrawArrays(GL_LINE_LOOP, 0, s.numVertices);
  glDisableClientState(GL_VERTEX_ARRAY);
 
  /* glBegin(GL_LINE_LOOP); */
  /*   glVertex2f(-319.5, -199.5); */
  /*   glVertex2f(-319.5, 200); */
  /*   glVertex2f(320, 200); */
  /*   glVertex2f(320, -199.5); */
  /* glEnd(); */

  glutSwapBuffers();
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

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 400);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("Blasteroids");
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);
  setup_data();
  glutMainLoop();
  return 0;
}
