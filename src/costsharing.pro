TEMPLATE = app
TARGET = CostSharing

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp allbills.cpp bill.cpp item.cpp payer.cpp control.cpp int_fract.cpp
HEADERS += allbills.hpp bill.hpp item.hpp payer.hpp ui_test.hpp control.hpp int_fract.hpp cosh_Action.hpp
