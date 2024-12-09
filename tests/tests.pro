include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread

DEFINES += EXAMPLE_LIBRARY

SOURCES += \
        main.cpp \
        tst_casename.cpp

LIBS += -L../lib -llib
