#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T09:18:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuGaussJordan
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DuDoubleItemDelegate.cpp \
    DuGaussJordan.cpp \
    SolveForm.cpp

HEADERS  += Widget.h \
    DuDoubleItemDelegate.h \
    DuGaussJordan.h \
    SolveForm.h

FORMS    += Widget.ui \
    SolveForm.ui

QMAKE_CXXFLAGS += -std=gnu++14
