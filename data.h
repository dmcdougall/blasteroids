#ifndef DATA_H
#define DATA_H

struct _vertex {
  float x;
  float y;
};

typedef struct _vertex vertex;

struct _ship {
  int rotateDir;
  int movingForward;
  int movingBackward;
  int accelerating;
  int numVertices;
  float dirAngle;
  float speedx;
  float speedy;
  float maxSpeed;
  float posx;
  float posy;
  float acceleration;
  float rotSpeed;
  vertex *coords;
};

typedef struct _ship ship;

ship s;
void setup_data(void);

#endif
