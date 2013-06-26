#-------------------------------------------------
#
# Project created by QtCreator 2013-06-26T11:52:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DelegteTestFinnal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui


CONFIG += qwt


unix:!macx: LIBS += -L$$PWD/../../../../usr/local/qwt-6.1.0-rc3/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../usr/local/qwt-6.1.0-rc3/include
DEPENDPATH += $$PWD/../../../../usr/local/qwt-6.1.0-rc3/include
