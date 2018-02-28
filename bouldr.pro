#-------------------------------------------------
#
# Project created by QtCreator 2018-02-17T13:47:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bouldr
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/ui/main.cpp \
        src/ui/mainwindow.cpp \
    src/ui/sceneview.cpp \
    src/ui/sceneviews.cpp \
    src/model/human.cpp \
    src/model/joint.cpp \
    src/model/section.cpp \
    src/model/torso.cpp \
    src/model/leg.cpp \
    src/model/limb.cpp \
    src/model/arm.cpp \
    src/static/triangle.cpp \
    src/geom/vector.cpp \
    src/geom/tensor.cpp \
    src/static/environment.cpp \
    src/geom/line.cpp \
    src/model/wall.cpp \
    src/model/scene.cpp \
    src/model/camera.cpp \
    src/model/sidelimbs.cpp

HEADERS += \
        src/ui/mainwindow.h \
    src/ui/sceneview.h \
    src/ui/sceneviews.h \
    src/model/human.h \
    src/model/joint.h \
    src/model/section.h \
    src/model/torso.h \
    src/model/leg.h \
    src/model/limb.h \
    src/model/arm.h \
    src/static/triangle.h \
    src/geom/vector.h \
    src/geom/tensor.h \
    src/static/environment.h \
    src/geom/line.h \
    src/model/wall.h \
    src/model/scene.h \
    src/model/camera.h \
    src/model/sidelimbs.h \
    src/static/body.h \
    src/model/vectorproxy.h

FORMS += \
        src/ui/mainwindow.ui
