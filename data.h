#ifndef DATA_H
#define DATA_H

struct _vertex {
  float x;
  float y;
};

typedef struct _vertex vertex;

struct _ship {
  int rotatingLeft;
  int rotatingRight;
  int movingForward;
  int movingBackward;
  int accelerating;
  int numVertices;
  float dirAngle;
  float speed;
  float rotSpeed;
  vertex *coords;
};

typedef struct _ship ship;

ship s;
void setup_data(void);

#endif
