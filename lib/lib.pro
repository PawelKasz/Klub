QT += core gui widgets

TEMPLATE = lib
DEFINES += LIB_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    strzalka.cpp \
    wiatr.cpp \
    dialog.cpp \
    skrzydlo.cpp \
    mainwindow.cpp \
    plat.cpp

HEADERS += \
    strzalka.h \
    wiatr.h \
    lib_global.h \
    dialog.h \
    skrzydlo.h \
    mainwindow.h \
    plat.h

FORMS += \
    dialog_1.ui \
    mainwindow.ui

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
