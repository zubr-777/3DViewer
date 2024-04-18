#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <math.h>

#include "parser.h"

#define OX_ROTATE 1
#define OY_ROTATE 2
#define OZ_ROTATE 3

// void move_model(double *p_vertex, int vertex_amount, double xMove, double
// yMove, double zMove);
void move_model(shared *model_copy, double xMove, double yMove, double zMove);
void rotate(shared *model_copy, int line, double angle);
void scaling(shared *model_copy, double k);

#endif  // TRANSFORMATION_H
