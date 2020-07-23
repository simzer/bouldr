#-------------------------------------------------
#
# Project created by QtCreator 2018-02-17T13:47:33
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++1z silent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bouldr
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS _USE_MATH_DEFINES

msvc: QMAKE_CXXFLAGS += /std:c++17

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
    src/model/sidelimbs.cpp \
    src/geom/plane.cpp

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
    src/model/vectorproxy.h \
    src/geom/plane.h

FORMS += \
        src/ui/mainwindow.ui
