#include "myglwidget.h"

myglwidget::myglwidget(QWidget * parent):QOpenGLWidget(parent)
{
    // for mouse events
    flag_basis = false;

    // angles
    xRot = 0.0;
    yRot = 0.0;

    coef_diameter = 1.2;

    //  init. model
    model.facet_amount = 0;
    model.vertex_amount = 0;
    model.name = NULL;
    model.p_facet = NULL;
    model.p_vertex = NULL;
    model.xCenter = 0.0;
    model.yCenter = 0.0;
    model.zCenter = 0.0;

    //  init. model_copy
    model_copy.facet_amount = 0;
    model_copy.vertex_amount = 0;
    model_copy.name = NULL;
    model_copy.p_facet = NULL;
    model_copy.p_vertex = NULL;
    model_copy.xCenter = 0.0;
    model_copy.yCenter = 0.0;
    model_copy.zCenter = 0.0;

    // load settings :)
    load_settings();
}

myglwidget::~myglwidget()
{
    save_settings();
    free_model_copy();
    free_model();
}

// ----------------------------------------------------------- pravate
// GL trinity
void myglwidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);    // depth buffer
    glEnable(GL_CULL_FACE);     // do not draw backs
    glEnable(GL_LINE_SMOOTH);   // smooth lines
}

//void myglwidget::resizeGL(int w, int h) { ;}

void myglwidget::paintGL()
{
    // background
    glClearColor(set.color_background.redF(),
                 set.color_background.greenF(),
                 set.color_background.blueF(),
                 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear color & buffer

    // projection
    glMatrixMode(GL_MODELVIEW); // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (set.flag_projection) {
         glFrustum(-diameter * 0.7, diameter * 0.7,
                   -diameter * 0.7, diameter * 0.7,
                   diameter, diameter * 15);
         glTranslated(0, 0,  -diameter * 2);

    } else {
        glOrtho(-diameter * coef_diameter, diameter * coef_diameter,
                -diameter * coef_diameter, diameter * coef_diameter,
                -diameter * coef_diameter * 10, diameter * coef_diameter * 10);
    }

    // rotate basis
    glRotated(xRot, 1, 0, 0);   // rotate basis around Ox
    glRotated(yRot, 0, 1, 0);   // rotate basis around Oy

    draw_model();
}

void myglwidget::draw_model()
{
    glVertexPointer(3, GL_DOUBLE, 0, this->model_copy.p_vertex);
    glEnableClientState(GL_VERTEX_ARRAY);

    if (set.flag_vertex) {
        if (set.flag_round) {
            glEnable(GL_POINT_SMOOTH); // round dots on
        } else {
            glDisable(GL_POINT_SMOOTH); // round dots off
        }
        glColor3f(set.color_vertex.redF(), set.color_vertex.greenF(), set.color_vertex.blueF());
        glPointSize(set.w_vertex);  // dots size
        glDrawArrays(GL_POINTS, 0, this->model_copy.vertex_amount); // attention!
    }

    if (set.flag_facet) {
        if (set.flag_dashed) {
            glEnable(GL_LINE_STIPPLE);  // dashed facets on
            glLineStipple(2, 0x3333);
        } else {
            glDisable(GL_LINE_STIPPLE); // dashed facets off
        }
        glColor3f(set.color_facet.redF(), set.color_facet.greenF(), set.color_facet.blueF());
        glLineWidth(set.w_facet);   // facets size
        glDrawElements(GL_LINES, this->model_copy.facet_amount, GL_UNSIGNED_INT,
                       this->model_copy.p_facet);
    }

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

// recalc etc
void myglwidget::recalc_model()
{
    double xMin = model.p_vertex[0];
    double xMax = model.p_vertex[0];
    double yMin = model.p_vertex[1];
    double yMax = model.p_vertex[1];
    double zMin = model.p_vertex[2];
    double zMax = model.p_vertex[2];

    for (int i = 3; i < model.vertex_amount * 3; i += 3) {
        if (model.p_vertex[i] < xMin) {
            xMin = model.p_vertex[i];
        } else {
            if (model.p_vertex[i] > xMax) {
                xMax = model.p_vertex[i];
            }
        }
    }

    for (int i = 4; i < model.vertex_amount * 3; i += 3) {
        if (model.p_vertex[i] < yMin) {
            yMin = model.p_vertex[i];
        } else {
            if (model.p_vertex[i] > yMax) {
                yMax = model.p_vertex[i];
            }
        }
    }

    for (int i = 5; i < model.vertex_amount * 3; i += 3) {
        if (model.p_vertex[i] < zMin) {
            zMin = model.p_vertex[i];
        } else {
            if (model.p_vertex[i] > zMax) {
                zMax = model.p_vertex[i];
            }
        }
    }

    // set center
    model.xCenter = xMin + (xMax - xMin) / 2.0;
    model.yCenter = yMin + (yMax - yMin) / 2.0;
    model.zCenter = zMin + (zMax - zMin) / 2.0;

    // recalc model for camera
    for (int i = 0; i < model.vertex_amount * 3; i += 3) {
        model.p_vertex[i] -= model.xCenter;
    }

    for (int i = 1; i < model.vertex_amount * 3; i += 3) {
        model.p_vertex[i] -= model.yCenter;
    }

    for (int i = 2; i < model.vertex_amount * 3; i += 3) {
        model.p_vertex[i] -= model.zCenter;
    }

    // calc diameter for margins
    diameter = xMax - xMin;
    if (diameter < yMax -yMin) diameter = yMax - yMin;
    if (diameter < zMax -zMin) diameter = zMax - zMin;

    // reset center
    model.xCenter = 0;
    model.yCenter = 0;
    model.zCenter = 0;
}

void myglwidget::clone_model()
{
    // ptr to ptr_copy!
    model_copy.name = model.name;

    model_copy.vertex_amount = model.vertex_amount;
    model_copy.facet_amount = model.facet_amount;

    model_copy.p_vertex = (double *)malloc(3 * model.vertex_amount * sizeof(double));
    for (int i = 0; i < 3 * model.vertex_amount; i++) {
        model_copy.p_vertex[i] = model.p_vertex[i];
    }

    model_copy.p_facet = (int *)malloc(sizeof(int) * model.facet_amount);
    for (int i = 0; i < model.facet_amount; i++) {
        model_copy.p_facet[i] = model.p_facet[i];
    }
}

void myglwidget::copy_model()
{
    for (int i = 0; i < 3 * model.vertex_amount; i++) {
        model_copy.p_vertex[i] = model.p_vertex[i];
    }

    model_copy.xCenter = model.xCenter;
    model_copy.yCenter = model.yCenter;
    model_copy.zCenter = model.zCenter;
}

// mouse events
void myglwidget::mousePressEvent(QMouseEvent *m)
{
    if (m->buttons() & Qt::LeftButton){
        flag_basis = 0;
        mouse_position = m->pos();
    } else if (m->buttons() & Qt::RightButton) {
        flag_basis = 1;
    }
}

void myglwidget::mouseMoveEvent(QMouseEvent *m)
{
    if (!flag_basis) {
        xRot += (0.05 / M_PI) * (m->pos().y() - mouse_position.y());
        yRot += (0.05 / M_PI) * (m->pos().x() - mouse_position.x());
        emit basis_view_changed();
    }

    this->update();
}

// ----------------------------------------------------------------- save & load settings
void myglwidget::save_settings()
{
    FILE *file = fopen(SETT_FILE_NAME, "wb");

    if (fwrite(&set, sizeof(settings), 1, file) != 1)
        QMessageBox::critical(this, nullptr, "File write error!");

    if (!file) fclose(file);
}

void myglwidget::load_settings()
{
    FILE *file = NULL;

    if ((file = fopen(SETT_FILE_NAME, "rb")) == NULL) {
        load_settings_default();
    } else {
        if (fread(&set, sizeof(settings), 1, file) != 1) {
            QMessageBox::critical(this, nullptr,
                                  "File read error!\nThe default settings will be loaded");
        }
    }

    if (file != NULL) fclose(file);
}

void myglwidget::load_settings_default()
{
    set.flag_facet = true;
    set.flag_vertex = false;
    set.flag_full = false;
    set.flag_dashed = false;
    set.flag_round = false;
    set.w_facet = 1.0;
    set.w_vertex = 2.0;
    set.flag_projection = false;
    set.color_vertex = QColor(0, 255, 0);
    set.color_facet = QColor(0, 255, 0);
    set.color_background = QColor(0, 0, 0);
}

// ----------------------------------------------------------- public
void myglwidget::preparation_model()
{
    recalc_model();
    clone_model();
}

void myglwidget::reset_basis()
{
    xRot = 0.0;
    yRot = 0.0;
    update();
}

// for reopen file
void myglwidget::free_model()
{
    model.vertex_amount = 0;
    model.facet_amount = 0;

    model.xCenter = 0.0;
    model.yCenter = 0.0;
    model.zCenter = 0.0;

    if (model.name) {
        free(model.name);
        model.name = NULL;
    }

    if (model.p_vertex) {
        free(model.p_vertex);
        model.p_vertex = NULL;
    }

    if (model.p_facet) {
        free(model.p_facet);
        model.p_facet = NULL;
    }
}

void myglwidget::free_model_copy()
{
    model_copy.vertex_amount = 0;
    model_copy.facet_amount = 0;
    model_copy.xCenter = 0.0;
    model_copy.yCenter = 0.0;
    model_copy.zCenter = 0.0;

    if (model_copy.name ) {
        model_copy.name = NULL;
    }

    if (model_copy.p_vertex) {
        free(model_copy.p_vertex);
        model_copy.p_vertex = NULL;
    }

    if (model_copy.p_facet) {
        free(model_copy.p_facet);
        model_copy.p_facet = NULL;
    }
}

void myglwidget::return_model()
{
    copy_model();
    update();
}
