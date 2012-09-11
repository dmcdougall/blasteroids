#include <stdlib.h>
#include "data.h"

void setup_data(void) {
  s.numVertices = 3;
  s.accelerating = 0;
  s.dir_angle = 0.0;
  s.coords = (vertex *)malloc(sizeof(vertex) * s.numVertices);

  s.coords[0].x = -4.0;
  s.coords[0].y = 0.0;
  s.coords[1].x = 4.0;
  s.coords[1].y = 0.0;
  s.coords[2].x = 0.0;
  s.coords[2].y = 10.0;
}
