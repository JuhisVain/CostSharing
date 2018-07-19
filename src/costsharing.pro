TEMPLATE = app
TARGET = CostSharing

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp allbills.cpp bill.cpp item.cpp payer.cpp
HEADERS += allbills.hpp bill.hpp item.hpp payer.hpp ui_test.hpp
