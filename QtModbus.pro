#-------------------------------------------------
#
# Project created by QtCreator 2014-11-24T15:28:57
#
#-------------------------------------------------
CONFIG+=c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtModbus
TEMPLATE = app


# Winsock libs
win32:LIBS += -lWS2_32

# Modbus dll location
#win32:LIBS += "H:\QtPrograms\QtModbus\libmodbus-5.dll"
win32:LIBS += "G:/QtPrograms/Modbus/QtModbus/libmodbus-5.dll"

SOURCES += main.cpp\
        qtmodbus.cpp

HEADERS  += qtmodbus.h \
    libMb/config.h \
    libMb/modbus.h \
    libMb/modbus-private.h \
    libMb/modbus-rtu.h \
    libMb/modbus-rtu-private.h \
    libMb/modbus-tcp.h \
    libMb/modbus-tcp-private.h \
    libMb/modbus-version.h

FORMS    += qtmodbus.ui

#include(deployment.pri)
#qtcAddDeployment()


