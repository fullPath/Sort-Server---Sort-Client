#-------------------------------------------------
#
# Project created by QtCreator 2011-02-04T12:57:06
#
#-------------------------------------------------

CONFIG   += qxt
QXT      += core network

QT       -= gui

TARGET = sort_client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sorttask.cpp \
    client.cpp

HEADERS += \
    sorttask.h \
    client.h
