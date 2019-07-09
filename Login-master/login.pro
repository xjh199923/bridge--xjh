#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T16:52:48
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QT       += widgets

TARGET = login
TEMPLATE = app

RC_FILE = myapp.rc


SOURCES += main.cpp\
    adddeflectsensor.cpp \
    adddisplacesensor.cpp \
    addstrainsensor.cpp \
    bradge.cpp \
    deflectpoint.cpp \
    deflectpointline.cpp \
    deflectsensor.cpp \
    displacepoint.cpp \
    displacepointline.cpp \
    displacesensor.cpp \
        login.cpp \
    exam.cpp \
    passwdedit.cpp \
    pointline.cpp \
    qcustomplot.cpp \
    register.cpp \
    strainpoint.cpp \
    strainpointline.cpp \
    strainsensor.cpp \
    systemtrayicon.cpp

HEADERS  += login.h \
    adddeflectsensor.h \
    adddisplacesensor.h \
    addstrainsensor.h \
    bradge.h \
    deflectpoint.h \
    deflectpointline.h \
    deflectsensor.h \
    displacepoint.h \
    displacepointline.h \
    displacesensor.h \
    exam.h \
    passwdedit.h \
    pointline.h \
    qcustomplot.h \
    register.h \
    strainpoint.h \
    strainpointline.h \
    strainsensor.h \
    systemtrayicon.h

FORMS    += login.ui \
    adddeflectsensor.ui \
    adddisplacesensor.ui \
    addstrainsensor.ui \
    bradge.ui \
    deflectpoint.ui \
    deflectpointline.ui \
    deflectsensor.ui \
    displacepoint.ui \
    displacepointline.ui \
    displacesensor.ui \
    exam.ui \
    passwdedit.ui \
    pointline.ui \
    register.ui \
    strainpoint.ui \
    strainsensor.ui

RESOURCES += \
    myqrc.qrc
