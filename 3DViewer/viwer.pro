QT       += core gui
#QT += openglwidgets #in comment for qmake!

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
#CONFIG += c11

#CONFIG += console   # delete!

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    myglwidget.cpp \
    parser.c \
    transformation.c \
    validate.c


HEADERS += \
    mainwindow.h \
    myglwidget.h \
    parser.h \
    transformation.h \
    validate.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
