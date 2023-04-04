QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculation/basecalc.cpp \
    estate.cpp \
    calculation/apartmentcalc.cpp \
    calculation/luxuriousapartmentcalc.cpp \
    calculation/townhousecalc.cpp \
    calculation/cottagecalc.cpp \
    facade/apartmentfactory.cpp \
    facade/basefactory.cpp \
    facade/calculationfacade.cpp \
    facade/cottagefactory.cpp \
    facade/luxuriousapartmentfactory.cpp \
    facade/townhousefactory.cpp \
    main.cpp \
    states.cpp \
    widget.cpp

HEADERS += \
    calculation/basecalc.h \
    estate.h \
    calculation/apartmentcalc.h \
    calculation/luxuriousapartmentcalc.h \
    calculation/townhousecalc.h \
    calculation/cottagecalc.h \
    facade/apartmentfactory.h \
    facade/basefactory.h \
    facade/calculationfacade.h \
    facade/cottagefactory.h \
    facade/luxuriousapartmentfactory.h \
    facade/townhousefactory.h \
    states.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
