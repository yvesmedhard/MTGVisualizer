QT       += core gui widgets
CONFIG	+= c++14

TARGET = MTGVisualizer
TEMPLATE = app

SOURCES += main.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp \
    backengine.cpp

HEADERS += \
    mainwidget.h \
    geometryengine.h \
    backengine.h

RESOURCES += \
    shaders.qrc \
    textures.qrc
