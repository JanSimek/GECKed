#-------------------------------------------------
#
# Project created by QtCreator 2017-07-08T20:58:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GECKed
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/Format/Dat/Entry.cpp \
    src/Format/Dat/File.cpp \
    src/Format/Dat/Item.cpp \
    src/Format/Dat/MiscFile.cpp \
    src/Format/Dat/Stream.cpp \
    src/Exception.cpp

HEADERS += \
    src/mainwindow.h \
    src/Format/Dat/Entry.h \
    src/Format/Dat/File.h \
    src/Format/Dat/Item.h \
    src/Format/Dat/MiscFile.h \
    src/Format/Dat/Stream.h \
    src/Exception.h \
    src/Base/Buffer.h \
    src/Format/Enums.h

FORMS += \
    src/mainwindow.ui

unix: LIBS += -lzlib
win32: LIBS += -L$$OUT_PWD/../zlib123dllx64/static_x64 -lzlibstat
win32: INCLUDEPATH += $$PWD/../zlib-1.2.11
