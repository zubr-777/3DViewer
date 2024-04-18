#include "transformation.h"

void move_model(shared *model, double xMove, double yMove, double zMove) {
  if (xMove != 0.0) {
    for (int i = 0; i < model->vertex_amount * 3; i += 3) {
      model->p_vertex[i] += xMove;
    }
    model->xCenter += xMove;
  }

  if (yMove != 0.0) {
    for (int i = 1; i < model->vertex_amount * 3; i += 3) {
      model->p_vertex[i] += yMove;
    }
    model->yCenter += yMove;
  }

  if (zMove != 0.0) {
    for (int i = 2; i < model->vertex_amount * 3; i += 3) {
      model->p_vertex[i] += zMove;
    }
    model->zCenter += zMove;
  }
}

void rotate(shared *model, int line, double angle) {
  double temp;

  if (line == OX_ROTATE) {
    for (int i = 1; i < model->vertex_amount * 3; i += 3) {
      temp = model->p_vertex[i] - model->yCenter;
      // y
      model->p_vertex[i] =
          temp * cos(angle) -
          (model->p_vertex[i + 1] - model->zCenter) * sin(angle) +
          model->yCenter;
      // z
      model->p_vertex[i + 1] =
          temp * sin(angle) +
          (model->p_vertex[i + 1] - model->zCenter) * cos(angle) +
          model->zCenter;
    }
  }

  if (line == OY_ROTATE) {
    for (int i = 0; i < model->vertex_amount * 3; i += 3) {
      temp = model->p_vertex[i] - model->xCenter;
      // x
      model->p_vertex[i] =
          temp * cos(angle) -
          (model->p_vertex[i + 2] - model->zCenter) * sin(angle) +
          model->xCenter;
      // z
      model->p_vertex[i + 2] =
          temp * sin(angle) +
          (model->p_vertex[i + 2] - model->zCenter) * cos(angle) +
          model->zCenter;
    }
  }

  if (line == OZ_ROTATE) {
    for (int i = 0; i < model->vertex_amount * 3; i += 3) {
      temp = model->p_vertex[i] - model->xCenter;
      // x
      model->p_vertex[i] =
          temp * cos(angle) -
          (model->p_vertex[i + 1] - model->yCenter) * sin(angle) +
          model->xCenter;
      // y
      model->p_vertex[i + 1] =
          temp * sin(angle) +
          (model->p_vertex[i + 1] - model->yCenter) * cos(angle) +
          model->yCenter;
    }
  }
}

void scaling(shared *model, double k) {
  for (int i = 0; i < model->vertex_amount * 3; i += 3) {
    model->p_vertex[i] =
        (model->p_vertex[i] - model->xCenter) * k + model->xCenter;
    model->p_vertex[i + 1] =
        (model->p_vertex[i + 1] - model->yCenter) * k + model->yCenter;
    model->p_vertex[i + 2] =
        (model->p_vertex[i + 2] - model->zCenter) * k + model->zCenter;
  }
}
