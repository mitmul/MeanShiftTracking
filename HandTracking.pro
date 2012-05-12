#-------------------------------------------------
#
# Project created by QtCreator 2012-04-26T02:16:50
#
#-------------------------------------------------

QT       += core gui

TARGET = HandTracking
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    CamCapture.cpp \
    SkinExtraction.cpp

HEADERS  += MainWindow.h \
    CamCapture.h \
    SkinExtraction.h

FORMS    += MainWindow.ui

# OpenCV
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib \
    -lopencv_calib3d \
    -lopencv_contrib \
    -lopencv_features2d \
    -lopencv_flann \
    -lopencv_gpu \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_legacy \
    -lopencv_ml \
    -lopencv_nonfree \
    -lopencv_objdetect \
    -lopencv_photo \
    -lopencv_stitching \
    -lopencv_ts \
    -lopencv_video \
    -lopencv_videostab \
    -lopencv_core

# Boost
INCLUDEPATH += /opt/local/include
LIBS += -L/opt/local/lib \
    -lboost_chrono-mt \
    -lboost_chrono \
    -lboost_date_time-mt \
    -lboost_date_time \
    -lboost_filesystem-mt \
    -lboost_filesystem \
    -lboost_graph-mt \
    -lboost_graph \
    -lboost_iostreams-mt \
    -lboost_iostreams \
    -lboost_locale-mt \
    -lboost_math_c99-mt \
    -lboost_math_c99 \
    -lboost_math_c99f-mt \
    -lboost_math_c99f \
    -lboost_math_c99l-mt \
    -lboost_math_c99l \
    -lboost_math_tr1-mt \
    -lboost_math_tr1 \
    -lboost_math_tr1f-mt \
    -lboost_math_tr1f \
    -lboost_math_tr1l-mt \
    -lboost_math_tr1l \
    -lboost_prg_exec_monitor-mt \
    -lboost_prg_exec_monitor \
    -lboost_program_options-mt \
    -lboost_program_options \
    -lboost_random-mt \
    -lboost_random \
    -lboost_regex-mt \
    -lboost_regex \
    -lboost_serialization-mt \
    -lboost_serialization \
    -lboost_signals-mt \
    -lboost_signals \
    -lboost_system-mt \
    -lboost_system \
    -lboost_thread-mt \
    -lboost_timer-mt \
    -lboost_timer \
    -lboost_unit_test_framework-mt \
    -lboost_unit_test_framework \
    -lboost_wave-mt \
    -lboost_wave \
    -lboost_wserialization-mt \
    -lboost_wserialization
