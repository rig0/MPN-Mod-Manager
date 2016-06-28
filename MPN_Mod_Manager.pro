#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T17:45:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MPN_Mod_Manager
TEMPLATE = app


SOURCES += main.cpp\
        modmanager.cpp

HEADERS  += modmanager.h

FORMS    += modmanager.ui

RC_ICONS = mpn.ico

#RC_FILE = MPN_Mod_Manager.rc #---Resource file to force UAC---#

RESOURCES += \
    res.qrc

#DISTFILES += \ #---List of files to for UAC---#
#   MPN_Mod_Manager.rc \
#   MPN_Mod_Manager.exe.manifest

