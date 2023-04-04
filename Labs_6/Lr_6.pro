QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    estate.cpp \
    facade/apartmentcalc.cpp \
    facade/calculationfacade.cpp \
    facade/cottagecalc.cpp \
    facade/luxuriousapartmentcalc.cpp \
    facade/townhousecalc.cpp \
    main.cpp \
    states.cpp \
    widget.cpp

HEADERS += \
    estate.h \
    facade/apartmentcalc.h \
    facade/calculationfacade.h \
    facade/cottagecalc.h \
    facade/luxuriousapartmentcalc.h \
    facade/townhousecalc.h \
    states.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
