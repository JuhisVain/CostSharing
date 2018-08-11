#ifndef COSH_ACTION_H
#define COSH_ACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QWidget>
#include <QtCore/QByteArray>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMainWindow>
#include <QtCore/QCoreApplication>

#include <iostream>

#include "control.hpp"

QT_BEGIN_NAMESPACE

extern Control controller;

class cosh_Action : public QAction
{
  Q_OBJECT
  
public:
  cosh_Action(QObject *parent) : QAction(parent)
  {
  }

public slots:
  void save()
  {
    QString savefile = QFileDialog::getSaveFileName((QWidget*)parent());
    controller.Save(savefile.toStdString());
  }

  void load()
  {
    QString loadfile = QFileDialog::getOpenFileName((QWidget*)parent());

    if (loadfile == NULL) return;
    
    controller.Load(loadfile.toStdString());

    //Can't access Ui_MainWindow class through any namespace, must be forced
    QCoreApplication::exit(666);

  }

};

QT_END_NAMESPACE

#endif
