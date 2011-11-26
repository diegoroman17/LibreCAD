#-------------------------------------------------
#
# Project created by QtCreator 2011-03-22T19:33:11
#
#-------------------------------------------------

QT       -= core gui
TEMPLATE = lib

#CONFIG += dll \
CONFIG += static \
    warn_on

VERSION = 0.0.1

DLL_NAME = dxfrw
TARGET = $$DLL_NAME

DEFINES += DRW_DBG

win32 {
    COPY = copy /y
} else {
    COPY = cp
}

SOURCES += \
    src/libdxfrw.cpp \
    src/drw_entities.cpp \
    src/dxfreader.cpp

HEADERS += \
    src/libdxfrw.h \
    src/dxfreader.h \
    src/drw_entities.h \
    src/drw_interface.h

win32 {
        DLLDESTDIR = ../intermediate
}
unix {
        DESTDIR = ../intermediate
}

# Store intermedia stuff somewhere else
OBJECTS_DIR = ../intermediate/obj
MOC_DIR = ../intermediate/moc
RCC_DIR = ../intermediate/rcc
TS_DIR = ../intermediate/ts
UI_DIR = ../intermediate/ui
UI_HERADERS_DIR = ../intermediate/ui
UI_SOURCES_DIR = ../intermediate/ui
