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
//extern QByteArray ui_default;

class cosh_Action : public QAction
{
  Q_OBJECT
  
public:
  cosh_Action(QObject *parent) : QAction(parent) {}

public slots:
  void save()
  {
    QString savefile = QFileDialog::getSaveFileName((QWidget*)parent());
    controller.Save(savefile.toStdString());
  }

  void load()
  {

    
    QString loadfile = QFileDialog::getOpenFileName((QWidget*)parent());
    controller.Load(loadfile.toStdString());

    QCoreApplication::exit(666);

    

    //Destroying user interface:
    /*
    cosh_TabWidget *tabwid =
      (cosh_TabWidget*)(parent()->findChild<QTabWidget*>("tabWidget"));
    
    QWidget * old_parent = (QWidget *)(tabwid->parent());
    
    delete tabwid;

    tabwid = new cosh_TabWidget(old_parent);
    tabwid->setObjectName(QStringLiteral("tabWidget"));

    QVBoxLayout *verticalLayout_2 =
      old_parent->findChild<QVBoxLayout*>("verticalLayout_2");
    
    verticalLayout_2->insertWidget(0,tabwid);

    cosh_NewBillTab *new_bill_tab = new cosh_NewBillTab();
    new_bill_tab->setObjectName(QStringLiteral("New bill"));
    
    tabwid->addTab(new_bill_tab, QString());

    tabwid->SetupNewTabTab(new_bill_tab);
    tabwid->setTabText(tabwid->indexOf(new_bill_tab),
			  QApplication::translate("MainWindow", "+", nullptr));

	QObject::connect(tabWidget, SIGNAL(tabBarClicked(int)),
			 tabWidget, SLOT(Add_tab(int))); //New bill
	QObject::connect(tabWidget, SIGNAL(tabBarDoubleClicked(int)),
			 tabWidget, SLOT(Rename_tab(int))); //Rename bill
	QObject::connect(addPayerButton, SIGNAL(clicked()),
			 tabWidget, SLOT(Update_payer_columns())); //New payer
	QObject::connect(lineEdit, SIGNAL(returnPressed()),
			 tabWidget, SLOT(Update_payer_columns()));
	QObject::connect(tabWidget, SIGNAL(PayerNameSignal()),
			 lineEdit, SLOT(PayerNameCalled()));
	QObject::connect(lineEdit, SIGNAL(SendName(QString)),
			 tabWidget, SLOT(Rename_columns(QString)));
	QObject::connect(calculateButton, SIGNAL(clicked()),
			 tabWidget, SLOT(Calculate()));
    */ //pos

  }

};

//QByteArray cosh_Action::ui_default;


#endif
