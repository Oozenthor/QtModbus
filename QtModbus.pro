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
win32:LIBS += "G:/QtGit/QtModbus/dll/libmodbus-5.dll"

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

OTHER_FILES += \
    dll/libmodbus-5.dll

# Add more folders to ship with the application, here
folder_01.source = ./dll/.
folder_01.target = ./
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# Deploy Qt Components
include(deployment.pri)
qtcAddDeployment()



