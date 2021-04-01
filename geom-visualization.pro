TEMPLATE = lib 
TARGET = visualization
CONFIG += static

CONFIG += QtGui
QT += opengl

OBJECTS_DIR = bin

DEPENDPATH += src \
              headers/common \
              headers/geom/primitives \
              headers/io \
              headers/visualization \
              src/io \
              src/visualization \

INCLUDEPATH += headers \
               src \
               "C:\Program Files\boost\boost_1_75_0" \

QMAKE_CXXFLAGS = -std=c++0x -Wall

macx {
    QMAKE_CXXFLAGS += -stdlib=libc++  
}

CONFIG += precompile_header
PRECOMPILED_HEADER = src/stdafx.h

# Input
HEADERS += src/stdafx.h \
           headers/common/* \
           headers/io/* \
           headers/visualization/* \
           src/visualization/*.h \
           headers/geom/primitives/* \
           headers/type_aliases.cpp \

SOURCES += src/io/primitives.cpp \
           src/visualization/drawer_impl.cpp \
           src/visualization/printer_impl.cpp \
           src/visualization/main_window.cpp \
           src/visualization/visualization.cpp \
           src/visualization/draw_util.cpp \

