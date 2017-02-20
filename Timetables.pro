#-------------------------------------------------
#
# Project created by QtCreator 2017-02-18T16:56:30
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Timetables
TEMPLATE = app
RC_FILE = ico.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    button.cpp \
    addclass.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    about.h \
    button.h \
    addclass.h \
    classmsg.h \
    database.h

FORMS    += mainwindow.ui \
    about.ui \
    addclass.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    ico.rc



