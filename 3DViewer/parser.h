#ifndef PARSER_H
#define PARSER_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct shared {
  char *name;
  double *p_vertex;
  int vertex_amount;
  int *p_facet;
  int facet_amount;
  double xCenter;
  double yCenter;
  double zCenter;

} shared;

int parser(const char *str, shared *model);
void add_vertex(shared *p_figure, double coord_x, double coord_y,
                double coord_z);
void add_facet(shared *p_figure, int *tmp_int, int counter);

#endif  // PARSER_H
