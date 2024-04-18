#include "mainwindow.h"
#include "myglwidget.h"
#include <QApplication>

#include "parser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000, 650);
    w.show();

    return a.exec();
}
