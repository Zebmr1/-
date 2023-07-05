QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    completelevel.cpp \
    easyriddle.cpp \
    fifthround.cpp \
    firstround.cpp \
    fourthround.cpp \
    hardriddle.cpp \
    helpui.cpp \
    main.cpp \
    mainwindow.cpp \
    prompt.cpp \
    ranklist.cpp \
    secondround.cpp \
    secondui.cpp \
    selectlevel.cpp \
    thirdround.cpp

HEADERS += \
    completelevel.h \
    easyriddle.h \
    fifthround.h \
    firstround.h \
    fourthround.h \
    hardriddle.h \
    helpui.h \
    mainwindow.h \
    prompt.h \
    ranklist.h \
    secondround.h \
    secondui.h \
    selectlevel.h \
    thirdround.h

FORMS += \
    completelevel.ui \
    fifthround.ui \
    firstround.ui \
    fourthround.ui \
    helpui.ui \
    mainwindow.ui \
    ranklist.ui \
    secondround.ui \
    secondui.ui \
    selectlevel.ui \
    thirdround.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
