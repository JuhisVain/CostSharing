#include <iostream>

#include <qt/QtWidgets/QMainWindow>
#include <qt/QtWidgets/QApplication>
#include <qt/QtCore/QByteArray>

#include "payer.hpp"
#include "allbills.hpp"
#include "ui_test.hpp"
#include "cosh_Action.hpp"

void Modify_bill(Bill *bill, All_bills ab);
Control controller;

int main(int argc, char **argv)
{

  const int RESTART = 666;

 restart:
    
  QApplication app(argc,argv);
  Ui_MainWindow test_gui;
  QMainWindow testmw;

  test_gui.setupUi(&testmw);
  testmw.show();
  if (app.exec() == RESTART) {
    goto restart;
  }
  return 0;
}
