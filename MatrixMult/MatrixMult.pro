TARGET = TwoMatrixMult
TEMPLATE = app
VERSION = 1.0.1

QT += core widgets

DESTDIR = ./bin

RCC_DIR = ./build
MOC_DIR = ./build
OBJECTS_DIR = ./build
UI_DIR = ./build

SOURCES += src/MatrixModel.cpp \
           src/MultMatrixThread.cpp \
           src/main.cpp \
           src/MainWindow.cpp

HEADERS += src/MainWindow.h \
           src/MatrixModel.h \
           src/MultMatrixThread.h

FORMS += src/MainWindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:QMAKE_POST_LINK += windeployqt $$OUT_PWD/$$DESTDIR
