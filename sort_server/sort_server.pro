#-------------------------------------------------
#
# Project created by QtCreator 2011-02-04T12:29:42
#
#-------------------------------------------------

CONFIG   += qxt
QXT      += core network

QT       -= gui

TARGET = sort_server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    server.cpp \
    sorttask.cpp

HEADERS += \
    server.h \
    sorttask.h
