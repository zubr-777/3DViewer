#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QColor>
#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLWidget>

#define SETT_FILE_NAME "3dvsetsettings"

typedef struct settings {
  bool flag_facet;
  bool flag_vertex;
  bool flag_full;
  bool flag_dashed;
  bool flag_round;
  float w_facet;
  float w_vertex;
  bool flag_projection;
  QColor color_vertex;
  QColor color_facet;
  QColor color_background;
} settings;

//
extern "C" {
#include <math.h>

#include "parser.h"
}

class myglwidget : public QOpenGLWidget {
  Q_OBJECT

 private:
  // ---------------------------------------------- fields
  // for widget margins
  double diameter;
  double coef_diameter;

  // rotate basis
  bool flag_basis;
  double xRot, yRot;
  QPoint mouse_position;

  // ---------------------------------------------- methods
  // GL trinity
  void initializeGL() override;
  void paintGL() override;
  //  resizeGL(int w, int h); // in future

  // draw model
  void draw_model();

  // preparation model
  void recalc_model();
  void clone_model();
  void copy_model();

  // mouse events
  void mousePressEvent(QMouseEvent *m) override;
  void mouseMoveEvent(QMouseEvent *m) override;

  // save & load settings
  void save_settings();
  void load_settings();
  void load_settings_default();

 public:
  myglwidget(QWidget *parent = Q_NULLPTR);

  // ---------------------------------------------- fields
  // 3D model
  shared model;
  shared model_copy;

  // mode view settings
  settings set;

  // ---------------------------------------------- methods
  ~myglwidget();

  void preparation_model();
  void reset_basis();

  void free_model();
  void free_model_copy();
  void return_model();

 signals:
  void basis_view_changed();
};

#endif  // MYGLWIDGET_H
