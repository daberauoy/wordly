QT += \
    core gui \
    multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    letter.cpp \
    main.cpp \
    mainwindow.cpp \
    nameinput.cpp \
    word.cpp

HEADERS += \
    letter.h \
    mainwindow.h \
    nameinput.h \
    word.h

FORMS += \
    mainwindow.ui \
    nameinput.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_6_9_0_MinGW_64_bit-Release/wordsRU.txt
