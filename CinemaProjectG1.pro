QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Users.cpp \
    bookingview.cpp \
    checkmark.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    welcomewindow.cpp

HEADERS += \
    Exceptions.h \
    Users.h \
    bookingview.h \
    checkmark.h \
    mainwindow.h \
    registerwindow.h \
    welcomewindow.h

FORMS += \
    mainwindow.ui \
    registerwindow.ui \
    welcomewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
