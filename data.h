#ifndef DATA_H
#define DATA_H

struct _vertex {
  float x;
  float y;
};

typedef struct _vertex vertex;

struct _ship {
  int numVertices;
  int accelerating;
  float dir_angle;
  vertex *coords;
};

typedef struct _ship ship;

ship s;
void setup_data(void);

#endif
