#include <stdlib.h>
#include <math.h>
#include <data.h>

vertex * tri_to_reference(const vertex *ref, const vertex *tri) {
  int i;
  float det;
  float a, b, c, d, x, y;
  vertex *t;

  t = (vertex *)malloc(sizeof(vertex) * 3);

  a = ref[2].y - ref[0].y;
  b = ref[0].x - ref[2].x;
  c = ref[0].y - ref[1].y;
  d = ref[1].x - ref[0].x;

  det = a * d - b * c;

  for (i = 0; i < 3; i++) {
    x = tri[i].x - ref[0].x;
    y = tri[i].y - ref[0].y;
    t[i].x = (a * x + b * y) / det;
    t[i].y = (c * x + d * y) / det;
  }

  return t;
}

void proj_pt_to_diag(vertex *x) {
  /*
   * Project the point x to the line y = x.
   *
   * Proj_{L}(x) = (x.v / v.v) v
   *
   */
  float norm = sqrtf(2.0);
  float dot = x->x + x->y;
  float q = dot / norm;

  x->x = q;
  x->y = q;
}

void proj_tri_to_diag(vertex *t) {
  proj_pt_to_diag(&t[0]);
  proj_pt_to_diag(&t[1]);
  proj_pt_to_diag(&t[2]);
}

int do_collide(const vertex *t1, const vertex *t2) {
  /*
   * Test whether two triangles overlap. Return 1 if they
   * collide, and 0 otherwise
   */

  int i, d = 1;
  float a, b;
  vertex *t;

  t = tri_to_reference(t1, t2);

  /* Check x-axis */
  if (t[0].x > 1 && t[1].x > 1 && t[2].x > 1) {
    return 0;
  }
  if (t[0].x < 0 && t[1].x < 0 && t[2].x < 0) {
    return 0;
  }

  /* Check y-axis */
  if (t[0].y > 1 && t[1].y > 1 && t[2].y > 1) {
    return 0;
  }
  if (t[0].y < 0 && t[1].y < 0 && t[2].y < 0) {
    return 0;
  }

  /* Check diagonal axis */
  proj_tri_to_diag(t);
  if (t[0].y > 0.5 && t[1].y > 0.5 && t[2].y > 0.5) {
    return 0;
  }
  if (t[0].y < 0 && t[1].y < 0 && t[2].y < 0) {
    return 0;
  }

  return 1;
}
