include(../coverage.pri)
include(../common_top.pri)
TARGET = ut_lowbatterynotifier

SOURCES += \
    ut_lowbatterynotifier.cpp \
    $$SRCDIR/debug.cpp \
    $$SRCDIR/batterybusinesslogic.cpp

HEADERS += \
    ut_lowbatterynotifier.h \
    $$SRCDIR/debug.h \
    $$SRCDIR/batterybusinesslogic.h

include(../common_bot.pri)
