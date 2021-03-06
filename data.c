#include <stdlib.h>
#include <math.h>
#include "data.h"

void setup_data(void) {
  s.rotateDir = 0;
  s.movingForward = 0;
  s.movingBackward = 0;
  s.accelerating = 0;

  s.numVertices = 3;
  s.dirAngle = 0.0;
  s.speedx = 0.0;
  s.speedy = 0.0;
  s.maxSpeed = 300.0;
  s.acceleration = 250.0;
  s.rotSpeed = 250.0;
  s.coords = (vertex *)malloc(sizeof(vertex) * s.numVertices);

  s.coords[0].x = -4.0;
  s.coords[0].y = -10.0 / 3.0;
  s.coords[1].x = 4.0;
  s.coords[1].y = -10.0 / 3.0;
  s.coords[2].x = 0.0;
  s.coords[2].y = 10 - (10.0 / 3.0);

  s.posx = 0.0;
  s.posy = 0.0;
}

roid* random_roid(void) {
  int i;
  float theta, rad;
  roid *r;

  r = (roid *)malloc(sizeof(roid));

  r->rotateDir = 1;
  r->numVertices = 8;
  r->dirAngle = 0.0;
  r->speedx = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
  r->speedy = ((float)rand() / RAND_MAX) * 200.0 - 100.0;
  r->rotSpeed = 200.0;

  r->coords = (vertex *)malloc(sizeof(vertex) * r->numVertices);
  for (i = 0; i < r->numVertices; i++) {
    theta = 2.0f * M_PI * i / r->numVertices;
    rad = ((float)rand() / RAND_MAX) * 5.0f + 10.0f;
    r->coords[i].x = rad * cos(theta);
    r->coords[i].y = rad * sin(theta);
  }
  r->posx = ((float)rand() / RAND_MAX) * 930.0 - 465.0;
  r->posy = ((float)rand() / RAND_MAX) * 570.0 - 285.0;

  return r;
}
