QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alu.cpp \
    controlunit.cpp \
    cpu.cpp \
    instructioninfodialog.cpp \
    instructionregister.cpp \
    machine.cpp \
    main.cpp \
    mainwindow.cpp \
    memory.cpp \
    programcounter.cpp \
    register.cpp \
    registersingle.cpp

HEADERS += \
    alu.h \
    controlunit.h \
    cpu.h \
    instructioninfodialog.h \
    instructionregister.h \
    machine.h \
    mainwindow.h \
    memory.h \
    programcounter.h \
    register.h \
    registersingle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
