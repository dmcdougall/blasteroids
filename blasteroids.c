#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "data.h"

float CURRENT_TIME = 0.0;
float PREV_TIME = 0.0;
float dt = 0.0;

void updateShip(void) {
  float angRad = s.dirAngle * M_PI / 180.0;
  float dirx = -sin(angRad);
  float diry = cos(angRad);
  float ax = s.acceleration * dirx;
  float ay = s.acceleration * diry;
  float newXSpeed = s.speedx + dt * ax - s.acceleration * s.speedx * dt / s.maxSpeed;
  float newYSpeed = s.speedy + dt * ay - s.acceleration * s.speedy * dt / s.maxSpeed;

  s.dirAngle += s.rotateDir * s.rotSpeed * dt;
  s.posx += dt * s.speedx;
  s.posy += dt * s.speedy;
  printf("%f %f\n", s.speedx, s.speedy);
  if (s.accelerating) {
    s.speedx = newXSpeed;
    s.speedy = newYSpeed;
  }

  glPushMatrix();

  glTranslatef(s.posx, s.posy, 0.0);
  glRotatef(s.dirAngle, 0.0, 0.0, 1.0);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, s.coords);
  glDrawArrays(GL_LINE_LOOP, 0, s.numVertices);
  glDisableClientState(GL_VERTEX_ARRAY);

  glPopMatrix();

  if (s.posx > 480.0) {
    s.posx -= 960.0;
  }
  if (s.posx < -480.0) {
    s.posx += 960.0;
  }
  if (s.posy > 300.0) {
    s.posy -= 600.0;
  }
  if (s.posy < -300.0) {
    s.posy += 600.0;
  }
}

void updateRoid(void) {
  float xInc = dt * r->speedx;
  float yInc = dt * r->speedy;

  glPushMatrix();

  glTranslatef(r->posx + xInc, r->posy + yInc, 0.0);
  glRotatef(r->dirAngle, 0.0, 0.0, 1.0);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, r->coords);
  glDrawArrays(GL_LINE_LOOP, 0, r->numVertices);
  glDisableClientState(GL_VERTEX_ARRAY);

  glPopMatrix();

  r->dirAngle += r->rotateDir * r->rotSpeed * dt;
  r->posx += xInc;
  r->posy += yInc;

  if (r->posx > 480.0) {
    r->posx -= 960.0;
  }
  if (r->posx < -480.0) {
    r->posx += 960.0;
  }
  if (r->posy > 300.0) {
    r->posy -= 600.0;
  }
  if (r->posy < -300.0) {
    r->posy += 600.0;
  }
}

void renderScene() {
  PREV_TIME = CURRENT_TIME;
  CURRENT_TIME = glutGet(GLUT_ELAPSED_TIME);
  dt = (CURRENT_TIME - PREV_TIME) / 1000.0;

  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.1, 0.1, 0.1, 1.0);

  updateShip();
  updateRoid();

  glutSwapBuffers();
  glutPostRedisplay();
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
  gluOrtho2D(-480, 480, -300, 300);
  glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
  if (key == 27) {
    exit(0);
  }
}

void processSpecialKeys(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_LEFT:
      s.rotateDir = 1;
      break;
    case GLUT_KEY_RIGHT:
      s.rotateDir = -1;
      break;
    case GLUT_KEY_UP:
      s.accelerating = 1;
      break;
  }
}

void processSpecialUpKeys(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_LEFT:
      s.rotateDir = 0;
      break;
    case GLUT_KEY_RIGHT:
      s.rotateDir = 0;
      break;
    case GLUT_KEY_UP:
      s.accelerating = 0;
      break;
    case GLUT_KEY_DOWN:
      s.accelerating = 0;
      break;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(960, 600);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutCreateWindow("Blasteroids");
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);

  glutIgnoreKeyRepeat(1);
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);
  glutSpecialUpFunc(processSpecialUpKeys);

  srand(time(NULL));
  setup_data();
  r = random_roid();
  CURRENT_TIME = glutGet(GLUT_ELAPSED_TIME);
  glutMainLoop();

  return 0;
}
