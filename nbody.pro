
QT += core gui widgets
TEMPLATE = app
CONFIG += c++14

SOURCES += src/barrier.cc src/bhtree.cc src/body.cc src/graphics.cc src/map.cc src/quadrant.cc src/main.cc 
HEADERS += src/barrier.hh src/bhtree.hh src/body.hh src/graphics.hh src/map.hh src/quadrant.hh src/vector2d.hh

OBJECTS_DIR = build
MOC_DIR = build/moc
DESTDIR = bin
TARGET = nbody