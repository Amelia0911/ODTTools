#-------------------------------------------------
#
# Project created by QtCreator 2018-09-22T22:10:10
#
#-------------------------------------------------

QT       += core gui\
xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ODTTools
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parsexml.cpp \
    detect.cpp

HEADERS  += mainwindow.h \
    parsexml.h \
    detect.h

FORMS    += mainwindow.ui
