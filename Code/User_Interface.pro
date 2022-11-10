QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvtest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += resources_big

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RC_FILE = myapp.rc

INCLUDEPATH += $$PWD\opencv\build\include

LIBS += -L$$PWD/opencv/bin/ -lcore454
LIBS += -L$$PWD/opencv/bin/ -lhighgui454
LIBS += -L$$PWD/opencv/bin/ -limgcodecs454
LIBS += -L$$PWD/opencv/bin/ -limgproc454
LIBS += -L$$PWD/opencv/bin/ -lfeatures2d454
LIBS += -L$$PWD/opencv/bin/ -lcalib3d454
LIBS += -L$$PWD/opencv/bin/ -lvideoio454
LIBS += -L$$PWD/opencv/bin/ -ldnn454


#LIBS += C:\opencv-build-v33\bin\libopencv_core454.dll
#LIBS += C:\opencv-build-v33\bin\libopencv_highgui454.dll
#LIBS += C:\opencv-build-v33\bin\libopencv_imgcodecs454.dll
#LIBS += C:\opencv-build-v33\bin\libopencv_imgproc454.dll
#LIBS += C:\opencv-build-v33\bin\libopencv_features2d454.dll
#LIBS += C:\opencv-build-v33\bin\libopencv_calib3d454.dll
#LIBS += C:\opencv-build-v33\lib\libopencv_videoio454.dll.a
#LIBS += C:\opencv-build-v33\lib\libopencv_dnn454.dll.a

RESOURCES += \
    Source.qrc

DISTFILES += \
    C:/Users/manud/OneDrive - DIT University/Documents/UntitledProject2/UntitledProject2.qmlproject
