/********************************************************************************
** Form generated from reading UI file '13heinadcVWzu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _13HEINADCVWZU_H
#define _13HEINADCVWZU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <QMouseEvent>

#include <vector>
#include <iostream>

QT_BEGIN_NAMESPACE

//
class cosh_TableWidget : public QTableWidget
{
  Q_OBJECT
  
public:
  cosh_TableWidget(QWidget *owner) : QTableWidget(owner) {}

public slots:
  void Add_row()
  {
    setRowCount(rowCount()+1);
  }

  void Add_column()
  {
    setColumnCount(columnCount()+1);

    QFont font;
    font.setWeight(75);
    font.setBold(false);

    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    __qtablewidgetitem->setFont(font);
    this->setHorizontalHeaderItem(columnCount()-1, __qtablewidgetitem);
    
    emit PayerNameSignal();
  }

  void Rename_column(QString col_name)
  {
    if (col_name.isNull()) {
      col_name = "XXX";
    }

    QTableWidgetItem *to_rename = this->horizontalHeaderItem(this->columnCount()-1);
      
    to_rename->setText(col_name);
  }

signals:
  void PayerNameSignal();
  
};

//
class cosh_LineEdit : public QLineEdit
{
  Q_OBJECT

public:
  cosh_LineEdit(QFrame *frame) : QLineEdit(frame) { }

public slots:
  void PayerNameCalled()
  {
    QString col_name = this->text();
    emit SendName(col_name);
  }

signals:
  void SendName(QString col_name);
  
};

//
class cosh_NewBillTab : public QWidget
{
  Q_OBJECT

public:
  cosh_NewBillTab() : QWidget()
  {
    std::cout << "NewBillTab constructor" << std::endl;
  }

};

//
class cosh_Tab : public QWidget
{
  Q_OBJECT

public:
  cosh_Tab(QTabWidget *owner) :QWidget()
  {
    my_tabwidget = owner;
  }

public slots:

  void rename(QString new_name)
  {
    std::cout << "rename(QString)" << std::endl;
    this->setObjectName(new_name);
    my_tabwidget->setTabText(my_tabwidget->indexOf(this),new_name);
  }

private:
  QTabWidget *my_tabwidget;
};

//
class cosh_TabWidget : public QTabWidget
{
  Q_OBJECT

public:
  cosh_TabWidget(QWidget *centralwidget) : QTabWidget(centralwidget)
  {
    std::cout << "cosh_TabWidget constructor" << std::endl;
  }

  void SetupNewTabTab(cosh_NewBillTab *nbt)
  {
    new_bill_tab = nbt;
  }

signals:
  void PayerNameSignal();

public slots:

  void Rename_tab(int index)
  {
    std::cout << "rename_tab()" << std::endl;
    if (index == indexOf(new_bill_tab)) {
      return;
    }

    QString to_rename = this->tabText(index);
    QWidget *tab = this->widget(index);

    QWidget *rename_window = new QWidget();

    QVBoxLayout *verticalLayout = new QVBoxLayout(rename_window);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    
    QLineEdit *name_edit = new QLineEdit(rename_window);
    name_edit->setPlaceholderText(to_rename);
    QPushButton *ok_button = new QPushButton(rename_window);

    ok_button->setObjectName(QStringLiteral("OK"));

    verticalLayout->addWidget(name_edit);
    verticalLayout->addWidget(ok_button);

    QObject::connect(name_edit, SIGNAL(textChanged(QString)), tab, SLOT(rename(QString)));
    //QObject::connect(ok_button, SIGNAL(clicked()), name_edit, SLOT()); //make this close the window OR just remove whole button
    
    rename_window->show();

  }

  void Update_payer_columns()
  {

    std::cout << "Update_payer_columns" << std::endl;
    
    for (int i = 0; i < this->count()-1; ++i) { //-1 for the new tab tab
      std::cout << "this->count()=" << this->count() <<  "i=" << i << std::endl;
      table_v[i]->setColumnCount(table_v[i]->columnCount()+1);

      QFont font;
      font.setWeight(75);
      font.setBold(false);

      std::cout << "font done" << std::endl;
      
      QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
      __qtablewidgetitem->setFont(font);
      table_v[i]->setHorizontalHeaderItem(table_v[i]->columnCount()-1, __qtablewidgetitem);

    }
    std::cout << "Rename_payer_columns OUT" << std::endl;
    emit PayerNameSignal();
  }

  //This will add a new payer's name to the column headers of all bills' itemtables:
  void  Rename_columns(QString col_name)
  {

    std::cout << "Rename_columns" << std::endl;
    if (col_name.isNull()) {
      col_name = "XXX";
    }

    payers.push_back(col_name);

    for (int i = 0; i < this->count()-1; ++i) {  //-1 for the new tab tab

      QTableWidgetItem *to_rename = table_v[i]->horizontalHeaderItem(table_v[i]->columnCount()-1);

      to_rename->setText(col_name);

    }
  }
  
  void Add_tab(int index) //New bill
  {
    std::cout << "tabwidget Add_tab() called with "<< index << std::endl;

    if (index == indexOf(new_bill_tab)) { //Generate new bill
    
      cosh_Tab *new_tab = new cosh_Tab(this);
      new_tab->setObjectName(QStringLiteral("Bill"));

      QVBoxLayout *verticalLayout_3;
      QFrame *frame_2;
      QPushButton *AddItemButton;
      cosh_TableWidget *tableWidget;

      verticalLayout_3 = new QVBoxLayout(new_tab);
      verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
      frame_2 = new QFrame(new_tab);
      frame_2->setObjectName(QStringLiteral("frame_2"));
      frame_2->setMinimumSize(QSize(0, 50));
      frame_2->setMaximumSize(QSize(16777215, 50));
      frame_2->setFrameShape(QFrame::StyledPanel);
      frame_2->setFrameShadow(QFrame::Raised);
      AddItemButton = new QPushButton(frame_2);
      AddItemButton->setObjectName(QStringLiteral("AddItemButton"));
      AddItemButton->setGeometry(QRect(10, 10, 90, 28));

      verticalLayout_3->addWidget(frame_2);

      tableWidget = new cosh_TableWidget(new_tab);
      if (tableWidget->columnCount() < 2) {
	tableWidget->setColumnCount(2);
      }
      QFont font;
      font.setBold(true);
      font.setWeight(75);
      QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
      __qtablewidgetitem->setFont(font);
      tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
      QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
      __qtablewidgetitem1->setFont(font);
      tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
      tableWidget->setObjectName(QStringLiteral("tableWidget"));

      std::cout << "payers vector size is " << payers.size() << std::endl;
      //setHorizontalHeaderItem does !!NOT!! increase columncount
      tableWidget->setColumnCount(tableWidget->columnCount()+payers.size());
      for (int i = 0; i < payers.size(); ++i) {
	QTableWidgetItem *tableitem = new QTableWidgetItem();
	font.setBold(false);
	tableitem->setFont(font);
	tableWidget->setHorizontalHeaderItem(i+2, tableitem);
	tableitem->setText(payers[i]);
      }

      verticalLayout_3->addWidget(tableWidget);

      table_v.push_back(tableWidget);
      std::cout << "Table vector now has " << table_v.size() << " elements" << std::endl;
      
      AddItemButton->setText(QApplication::translate("MainWindow", "Add item", nullptr));
      __qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
      __qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", nullptr));
      __qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
      __qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Price", nullptr));

      QObject::connect(AddItemButton, SIGNAL(clicked()), tableWidget, SLOT(Add_row())); //New item

      QMetaObject::connectSlotsByName(this);
            
      this->addTab(new_tab, QString());

      this->setTabText(index+1,QStringLiteral("Bill"));
      int nbt_index = indexOf(new_bill_tab);
      this->tabBar()->moveTab(nbt_index,nbt_index+1);
      this->setCurrentIndex(indexOf(new_bill_tab)-1);
    }
  }

private:
  cosh_NewBillTab *new_bill_tab;
  std::vector<cosh_TableWidget*> table_v;
  std::vector<QString> payers;
  
};

//
class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    cosh_TabWidget *tabWidget;
    cosh_NewBillTab *new_bill_tab;
    QFrame *frame;
    QPushButton *addPayerButton;
    QPushButton *pushButton_3;
    cosh_LineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1034, 774);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new cosh_TabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
	
	tabWidget->Add_tab(0);
	
        new_bill_tab = new cosh_NewBillTab();
        new_bill_tab->setObjectName(QStringLiteral("New bill"));
        tabWidget->addTab(new_bill_tab, QString());
	tabWidget->SetupNewTabTab(new_bill_tab);

        verticalLayout_2->addWidget(tabWidget);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        addPayerButton = new QPushButton(frame);
        addPayerButton->setObjectName(QStringLiteral("addPayerButton"));
        addPayerButton->setGeometry(QRect(10, 60, 90, 28));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(840, 30, 90, 28));
        lineEdit = new cosh_LineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 171, 28));

        verticalLayout_2->addWidget(frame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1034, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        //QObject::connect(AddItemButton, SIGNAL(clicked()), tableWidget, SLOT(Add_row())); //New item

	QObject::connect(tabWidget, SIGNAL(tabBarClicked(int)), tabWidget, SLOT(Add_tab(int))); //New bill
	QObject::connect(tabWidget, SIGNAL(tabBarDoubleClicked(int)), tabWidget, SLOT(Rename_tab(int))); //Rename bill
	
        //QObject::connect(lineEdit, SIGNAL(returnPressed()), tableWidget, SLOT(clearContents()));
	
        //QObject::connect(addPayerButton, SIGNAL(clicked()), tableWidget, SLOT(Add_column())); //New payer
	QObject::connect(addPayerButton, SIGNAL(clicked()), tabWidget, SLOT(Update_payer_columns())); //New payer
	QObject::connect(tabWidget, SIGNAL(PayerNameSignal()), lineEdit, SLOT(PayerNameCalled()));
	QObject::connect(lineEdit, SIGNAL(SendName(QString)), tabWidget, SLOT(Rename_columns(QString)));
	
	//QObject::connect(tableWidget, SIGNAL(PayerNameSignal()), lineEdit, SLOT(PayerNameCalled()));

	//QObject::connect(lineEdit, SIGNAL(SendName(QString)), tableWidget, SLOT(Rename_column(QString)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(new_bill_tab), QApplication::translate("MainWindow", "+", nullptr));
        addPayerButton->setText(QApplication::translate("MainWindow", "Add payer", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "New payer name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _13HEINADCVWZU_H
