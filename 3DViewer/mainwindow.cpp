#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // open file
    flag_open = false;

    // hide checkbox projection
    ui->checkBox_projection->hide();

    // for hide button Reset on glwidget
    ui->pushButton_resetBasis->setVisible(false);
    connect(ui->glWidget, SIGNAL(basis_view_changed()), this, SLOT(lock_resetBasis()));

    //lock return & screenshot
    ui->pushButton_resetMove->setEnabled(false);


    // set tools from set
    set_tools();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//  style
void MainWindow::on_radio_vertex_clicked(bool checked)
{
    if (checked) {
        ui->glWidget->set.flag_vertex = true;
        ui->glWidget->set.flag_facet = false;
        ui->glWidget->set.flag_full = false;
    }

    ui->glWidget->update();
}

void MainWindow::on_radio_facet_clicked(bool checked)
{
    if (checked) {
        ui->glWidget->set.flag_vertex = false;
        ui->glWidget->set.flag_facet = true;
        ui->glWidget->set.flag_full = false;
    }

    ui->glWidget->update();
}

void MainWindow::on_radio_full_clicked(bool checked)
{
    if (checked) {
        ui->glWidget->set.flag_vertex = true;
        ui->glWidget->set.flag_facet = true;
        ui->glWidget->set.flag_full = true;
    }

    ui->glWidget->update();
}



void MainWindow::on_checkBox_dashed_clicked()
{
    if (ui->checkBox_dashed->isChecked()) {
        ui->glWidget->set.flag_dashed = true;
        ui->glWidget->update();
    } else {
        ui->glWidget->set.flag_dashed = false;
        ui->glWidget->update();
    }
}

void MainWindow::on_checkBox_round_clicked()
{
    if (ui->checkBox_round->isChecked()) {
        ui->glWidget->set.flag_round = true;
        ui->glWidget->update();
    } else {
        ui->glWidget->set.flag_round = false;
        ui->glWidget->update();
    }
}

//  colors
void MainWindow::on_pushButton_setColor_clicked()
{
    QColor tmp = QColorDialog::getColor(Qt::white, this, tr("Select color lapochka!"));
    if (tmp.isValid()) {
        ui->glWidget->set.color_facet = tmp;
        ui->glWidget->update();
    }
}

void MainWindow::on_pushButton_setColor_2_clicked()
{
    QColor tmp = QColorDialog::getColor(Qt::white, this, tr("Select color lapochka!"));
    if (tmp.isValid()) {
        ui->glWidget->set.color_vertex = tmp;
        ui->glWidget->update();
    }
}

void MainWindow::on_pushButton_setColor_3_clicked()
{
    QColor tmp = QColorDialog::getColor(Qt::white, this, tr("Select color lapochka!"));
    if (tmp.isValid()) {
        ui->glWidget->set.color_background = tmp;
        ui->glWidget->update();
    }
}

// basis
// slot for signal from glvidget
void MainWindow::lock_resetBasis()
{
    ui->pushButton_resetBasis->setVisible(true);
}

void MainWindow::on_pushButton_resetBasis_clicked()
{
    ui->glWidget->reset_basis();
    ui->pushButton_resetBasis->setVisible(false);
}

// transformations
void MainWindow::on_pushButton_go_clicked()
{
    if ((ui->doubleSpinBox_xMove->value() != 0.0) ||
        (ui->doubleSpinBox_yMove->value() != 0.0) ||
        (ui->doubleSpinBox_zMove->value() != 0.0))
    {
        move_model(&ui->glWidget->model_copy,
                   ui->doubleSpinBox_xMove->value(),
                   ui->doubleSpinBox_yMove->value(),
                   ui->doubleSpinBox_zMove->value());

        ui->glWidget->update();
    }

    ui->pushButton_resetMove->setEnabled(true);
}

void MainWindow::on_pushButton_rotate_clicked()
{
    // around Ox
    if (ui->spinBox_xRotate->value()) {
        rotate(&ui->glWidget->model_copy, OX_ROTATE,
               ui->spinBox_xRotate->value() * M_PI / 180.00);
        ui->glWidget->update();
    }

    // around Oy
    if (ui->spinBox_yRotate->value()) {
        rotate(&ui->glWidget->model_copy, OY_ROTATE,
               ui->spinBox_yRotate->value() * M_PI / 180.00);
        ui->glWidget->update();
    }

    // around Oz
    if (ui->spinBox_zRotate->value()) {
        rotate(&ui->glWidget->model_copy, OZ_ROTATE,
               ui->spinBox_zRotate->value() * M_PI / 180.00);
        ui->glWidget->update();
    }

    // enable "Return" button
    if (ui->spinBox_xRotate->value() ||
        ui->spinBox_yRotate->value() ||
        ui->spinBox_zRotate->value()) {
        ui->pushButton_resetMove->setEnabled(true);
    }
}

void MainWindow::on_pushButton_scale_clicked()
{
    if (ui->doubleSpinBox_Scale->value() == 0.0) {
        QMessageBox::information(this, "I think that...", "the coefficients should be non-zero");
    } else {
        scaling(&ui->glWidget->model_copy, ui->doubleSpinBox_Scale->value());
        ui->pushButton_resetMove->setEnabled(true);
        ui->glWidget->update();
    }
}

//  reset tools
void MainWindow::on_pushButton_moveReset_clicked()
{
    ui->doubleSpinBox_xMove->setValue(0.0);
    ui->doubleSpinBox_yMove->setValue(0.0);
    ui->doubleSpinBox_zMove->setValue(0.0);
}

void MainWindow::reset_tools()
{
    ui->doubleSpinBox_xMove->setValue(0.0);
    ui->doubleSpinBox_yMove->setValue(0.0);
    ui->doubleSpinBox_zMove->setValue(0.0);

    ui->spinBox_xRotate->setValue(0);
    ui->spinBox_yRotate->setValue(0);
    ui->spinBox_zRotate->setValue(0);

    ui->doubleSpinBox_Scale->setValue(0.0);
}

void MainWindow::on_pushButton_rotateReset_clicked()
{
    ui->spinBox_xRotate->setValue(0);
    ui->spinBox_yRotate->setValue(0);
    ui->spinBox_zRotate->setValue(0);
}

//  set tools
void MainWindow::set_tools()
{
    // mode view
    if (ui->glWidget->set.flag_full) {
        ui->radio_full->setChecked(true);
    } else {
        if (ui->glWidget->set.flag_facet) {
            ui->radio_facet->setChecked(true);
        } else {
            ui->radio_vertex->setChecked(true);
        }
    }

    // vertex & facet properties
    if (ui->glWidget->set.flag_dashed)
        ui->checkBox_dashed->setChecked(true);
    if (ui->glWidget->set.flag_round)
        ui->checkBox_round->setChecked(true);

    ui->Facet_slider->setValue(ui->glWidget->set.w_facet);
    ui->Vertex_slider->setValue(ui->glWidget->set.w_vertex);

    if (ui->glWidget->set.flag_projection)
        ui->checkBox_projection->setChecked(true);
}

// return model
void  MainWindow::on_pushButton_resetMove_clicked()
{
    ui->glWidget->return_model();
    ui->pushButton_resetMove->setEnabled(false);
}

void MainWindow::on_checkBox_projection_clicked(bool checked)
{
    ui->glWidget->set.flag_projection = checked;
    ui->glWidget->update();
}


// open file

void MainWindow::on_actionOpen_triggered()
{
    QString q_file_name = QFileDialog::getOpenFileName();

    if (!q_file_name.isEmpty())
    {
        std::string cpp_file_name = q_file_name.toStdString();
        const char *c_file_name = cpp_file_name.c_str();

        if (validate(c_file_name)) {
            QMessageBox::critical(this, nullptr, "Incorrect file!");
        } else {
            // second open
            if(flag_open) {
                // free model
                ui->glWidget->free_model();
                ui->glWidget->free_model_copy();
            } else {
                flag_open = true;
            }
            // reset spinboxes
            reset_tools();
            // parsing & preparation model
            if (parser(c_file_name, &ui->glWidget->model)) {
                QMessageBox::critical(this, nullptr, "Parser error!");
            } else {
                ui->glWidget->preparation_model();
                // filename to statusbar
                ui->statusbar->showMessage(QString(" file: %1").arg(q_file_name));
                // model name on glwidget
                if (ui->glWidget->model.name) {
                    ui->label_modelName->setText(ui->glWidget->model_copy.name);
                } else {
                    ui->label_modelName->setText("no name");
                }
                // amount on glwidget
                ui->label_vertex_amount->setText(
                    QString("vertex: %1").arg(ui->glWidget->model_copy.vertex_amount));
                ui->label_facet_amount->setText(
                    QString("facet: %1").arg(ui->glWidget->model_copy.facet_amount));
                // reset basis and show
                ui->checkBox_projection->show();
                ui->pushButton_resetBasis->hide();
                ui->glWidget->reset_basis();
            }
        }
    }
}

// saving gif jpeg bmp

void MainWindow::on_actionsave_gif_triggered()
{
    QImage captireImage;

    ui->glWidget->makeCurrent();

    QPixmap pixmap = QPixmap::fromImage(ui->glWidget->grabFramebuffer());
    captireImage = pixmap.toImage();

//    QtGiImage gif;
}


void MainWindow::on_actionsave_png_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "screenshot.bmp", NULL, "BMP (*.bmp)");
    if (!filename.isNull()) {
        this->ui->glWidget->grabFramebuffer().save(filename, NULL, -1);
    }
}


void MainWindow::on_Vertex_slider_valueChanged(int value)
{
    ui->glWidget->set.w_vertex = (float)value;
    ui->glWidget->update();
}

// thikness

void MainWindow::on_Facet_slider_valueChanged(int value)
{
    ui->glWidget->set.w_facet = (float)value;
    ui->glWidget->update();
}


void MainWindow::on_actionsave_JPEG_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "screenshot.jpg", NULL,
                                        "JPEG (*.jpg)");
    if (!filename.isNull()) {
        this->ui->glWidget->grabFramebuffer().save(filename, NULL, -1);
    }
}

