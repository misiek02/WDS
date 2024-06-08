QT       += core gui network 3dcore 3drender 3dinput 3dlogic 3dextras 3danimation charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accelerationchart.cpp \
    canvas.cpp \
    distancesensors.cpp \
    gyroscope.cpp \
    main.cpp \
    mainwindow.cpp \
    speedometer.cpp \
    tcpserv.cpp \
    model3d.cpp

HEADERS += \
    accelerationchart.hh \
    canvas.hh \
    distancesensors.hh \
    gyroscope.hh \
    mainwindow.hh \
    speedometer.hh \
    tcpserv.hh \
    model3d.hh

FORMS += \
    accelerationchart.ui \
    distancesensors.ui \
    gyroscope.ui \
    mainwindow.ui \
    model3d.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
