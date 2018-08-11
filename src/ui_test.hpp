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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QList>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QByteArray>

#include <QtWidgets/QFileDialog>

#include <QMouseEvent>

#include <vector>
#include <iostream>

#include "cosh_Action.hpp"
#include "control.hpp"

QT_BEGIN_NAMESPACE

extern Control controller; //4 hours down the drain


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
    this->clear();
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

  ~cosh_NewBillTab()
  {
    std::cout << "Newbilltab DELETE!!!" << std::endl;
  }

};

//A bill-tab for the tabwidget
class cosh_Tab : public QWidget
{
  Q_OBJECT

public:
  cosh_Tab(QTabWidget *owner) :QWidget()
  {
    my_tabwidget = owner; 
  }

  ~cosh_Tab()
  {
    std::cout << "cosh_Tab DELETE" << std::endl;
  }

  void Link_bill(Bill *link)
  {
    linked_bill = link;
  }

  Bill* Get_bill()
  {
    return linked_bill;
  }

  //olololo
  void Set_pointer_to_table_has_final_bool(bool *table_has_final)
  {
    my_table_has_final = table_has_final;
  }

public slots:

  void rename(QString new_name)
  {
    std::cout << "rename(" << new_name.toStdString() << std::endl;
    std::cout << "MY ADDRESS IS : " << (void*)this << std::endl; // WTF
    this->setObjectName(new_name);

    my_tabwidget->setTabText(my_tabwidget->indexOf(this),new_name);

    controller.Rename_bill(linked_bill, (new_name.toStdString()));
  }

  void handleCell(QTableWidgetItem *handle)
  {
    if (*my_table_has_final) { //No fiddling with the totals row
      if (handle->row() == handle->tableWidget()->rowCount()-1) {
	return;
      }
    }

    if (handle->column() == 0) { //Name column

      controller.Rename_item(linked_bill, handle->row(),
			     (handle->text().toStdString()));
      
    } else if (handle->column() == 1) { //Price column

      //func called after every letter:
      //itemChanged signal + setText = carnage, disable it temporarily:
      QObject::disconnect(this->findChild<QTableWidget*>("tableWidget"),
			  SIGNAL(itemChanged(QTableWidgetItem*)),
			  this, SLOT(handleCell(QTableWidgetItem*)));
      
      handle->setText(QString::fromStdString(
	      controller.Reprice_item(
		  linked_bill, handle->row(),(handle->text().toStdString()))
      ));
      
      QObject::connect(this->findChild<QTableWidget*>("tableWidget"),
		       SIGNAL(itemChanged(QTableWidgetItem*)),
		       this, SLOT(handleCell(QTableWidgetItem*)));
      
    } else { //Weight columns
      handle->setText(QString::fromStdString(
	      controller.Reweight_item(linked_bill, handle->row(),handle->column()-2,
				       (handle->text().toStdString()))));
    }
  }

  
  void Set_billpayer(QString payer_name)
  {

    std::cout << "Tab's set_billpayer(" << payer_name.toStdString() << ")" <<std::endl;
    
    controller.Set_billpayer(payer_name.toStdString(), linked_bill);
  }


private:
  QTabWidget *my_tabwidget; //This should have been just done with parent()?
  Bill *linked_bill;
  bool *my_table_has_final; //...
};



//
class cosh_TableWidget : public QTableWidget
{
  Q_OBJECT
  
public:
  cosh_TableWidget(QWidget *owner) : QTableWidget(owner)
  {
    has_final = false;
  }
  int Add_final() //For computed shares
  {
    Remove_final();

    std::cout << "Add_final() called, rowcount= " << rowCount() << std::endl;
    
    has_final = true;
    setRowCount(rowCount()+1);

    std::cout << "set rowcount= " << rowCount() << std::endl;

    //????? Not only will this create items of rowCount-1 line,
    //but all the other rows' items as well.
    //Dont know what happens to the apparently existing items of
    //name and price columns...
    for (int i = 0; i < columnCount(); ++i) {
      setItem(rowCount()-1, i, new QTableWidgetItem());
    }
    
    std::cout << "returning: " << rowCount()-1 << std::endl;

    return rowCount()-1; //Final line index
  }

  bool *Get_has_final_pointer() {
    return &has_final;
  }
  
  bool Has_final()
  {
    return has_final;
  }
  
  void Remove_final()
  {
    if (has_final) {
      std::cout << "REMOVE FINAL" << std::endl;
      has_final = false;
      setRowCount(rowCount()-1);
    }
  }
  void Nuke_finals()
  {
    /*
    cosh_TableWidget *parent1 = (cosh_TableWidget*)parent();
    cosh_TabWidget *parent2 = (cosh_TabWidget*)parent1->parent();
    parent2->Nuke_all_finals();
    */

    if (has_final) {
      std::cout << "Nuke finals called when has final" << std::endl;
      QList<cosh_Tab*> tabs = parent()->parent()->findChildren<cosh_Tab*>();
      std::cout << "Tabs size: " << tabs.size() << std::endl;
      for (int i = 0; i < tabs.size(); ++i) {
	std::cout << "i: " << i << std::endl;
	((cosh_TableWidget*)(tabs[i]->findChild<QTableWidget*>()))->Remove_final();
      }
    }
  }

public slots:
  void Add_row()
  {
    Nuke_finals(); //Rows are table specific: All tables need finalnuking
    controller.New_item(((cosh_Tab*)parent())->Get_bill());
    setRowCount(rowCount()+1);
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

private:
  bool has_final;
  
};




//Popup window when double clicking bill tab to rename bill
class Rename_window : public QWidget
{
  Q_OBJECT

private:
  QVBoxLayout *layout;
  QLineEdit *name_edit;
  QPushButton *button;

public:
  Rename_window(QString name, QWidget *tab_to_rename) : QWidget()
  {
    layout = new QVBoxLayout(this);
    name_edit = new QLineEdit(this);
    button = new QPushButton(this);

    name_edit->setPlaceholderText(name);
    layout->addWidget(name_edit);
    layout->addWidget(button);
    button->setText(QString("Close"));

    QObject::connect(name_edit, SIGNAL(textChanged(QString)),
		     tab_to_rename, SLOT(rename(QString)));
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(Delete_window()));

    this->show();
  }

  ~Rename_window()
  {
    delete layout;
    delete name_edit;
    delete button;
  }

public slots:
  void Delete_window()
  {
    delete this;
  }
  
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

  void Nuke_all_finals()
  {
    for (int i = 0; i < table_v.size(); ++i) { 
      table_v[i]->Remove_final();
    }
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

    Rename_window *popup = new Rename_window(to_rename, tab);

  }

  void Update_payer_columns()
  {

    Nuke_all_finals();

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
  //Update: Also adds the name to billpayer combobox of already existing bills
  void  Rename_columns(QString col_name)
  {

    std::cout << "Rename_columns" << std::endl;
    if (col_name.isNull()) {
      col_name = "XXX";
    }

    controller.New_payer(col_name.toStdString());

    payers.push_back(col_name);

    QList<QComboBox*> combo_boxes = this->findChildren<QComboBox*>("BillPayerCombo");
    QList<QComboBox*>::iterator combo_iter = combo_boxes.begin();

    for (int i = 0; i < this->count()-1; ++i) {  //-1 for the new tab tab

      QTableWidgetItem *to_rename = table_v[i]->horizontalHeaderItem(table_v[i]->columnCount()-1);
      to_rename->setText(col_name);

      (*combo_iter)->addItem(QString());
      (*combo_iter)->setItemText((*combo_iter)->count()-1, col_name);
      ++combo_iter;

    }
  }

  void Repopulate_tabs()
  {
    
    std::vector<Payer*> payer_vector = controller.Get_payers();
    for (int i = 0; i < payer_vector.size(); ++i) {
      std::string payername = payer_vector[i]->Get_name();
      payers.push_back(QString::fromStdString(payername));
    }

    std::vector<Bill*> bills_vector = controller.Get_bills();
    for (int i = 0; i < bills_vector.size(); ++i) {
      cosh_Tab *tab = Add_tab(-1,bills_vector[i]); //Create a tab for a bill
      tab->rename(QString::fromStdString(bills_vector[i]->Get_name()));
      QComboBox * combo = tab->findChild<QComboBox*>();
      cosh_TableWidget* table = tab->findChild<cosh_TableWidget*>();

      
      QObject::disconnect(combo, SIGNAL(currentTextChanged(QString)),
		       tab, SLOT(Set_billpayer(QString )));

      std::cout << "combo default index: " << combo->currentIndex() << std::endl;
      std::cout << "Trying to find index for name: "
		<< bills_vector[i]->Get_payer()->Get_name();

      combo->setCurrentIndex(
	  combo->findText(
	      QString::fromStdString(bills_vector[i]->Get_payer()->Get_name())));

      std::cout << "combo new index: " << combo->currentIndex() << std::endl;

      
      QObject::connect(combo, SIGNAL(currentTextChanged(QString)),
		       tab, SLOT(Set_billpayer(QString )));
      
      QObject::disconnect(table, SIGNAL(itemChanged(QTableWidgetItem*)),
		     tab, SLOT(handleCell(QTableWidgetItem*)));
      
      
      std::vector<Item*> items_vector = bills_vector[i]->Get_items();
      for (int j = 0; j < items_vector.size(); ++j) {
	table->Add_row();
	table->setItem(table->rowCount()-1,0,new QTableWidgetItem()); //Name column
	table->item(table->rowCount()-1,0)
	  ->setText(QString::fromStdString(items_vector[j]->Get_name()));
	table->setItem(table->rowCount()-1,1,new QTableWidgetItem()); //Price column

	std::string temp = std::to_string(items_vector[j]->Get_price());
	while (temp.size() < 3) temp.insert(0,"0");
	temp.insert(temp.size()-2,",");

	table->item(table->rowCount()-1,1)
	  ->setText(QString::fromStdString(temp));
	//tab->handleCell(table->item(table->rowCount()-1,1));

	for (int weight_i = 0; weight_i < payer_vector.size(); ++weight_i) {
	  //Weight columns:
	  table->setItem(table->rowCount()-1,weight_i+2,new QTableWidgetItem());
	  table->item(table->rowCount()-1,weight_i+2)
	    ->setText(QString::number(items_vector[j]->Get_weight(weight_i)));
	}
      }
      
      QObject::connect(table, SIGNAL(itemChanged(QTableWidgetItem*)),
		     tab, SLOT(handleCell(QTableWidgetItem*)));
      
      QMetaObject::connectSlotsByName(tab);    

    }


    
  }

  //index used to check for new tab tab, load used when loading stored bills
  cosh_Tab *Add_tab(int index, Bill* load = NULL) //New bill
  {
    std::cout << "tabwidget Add_tab() called with "<< index << std::endl;
    std::cout << "index of new bill tab : " << indexOf(new_bill_tab) << std::endl;

    if (index == indexOf(new_bill_tab) || index == -1) { //Generate new bill
    
      cosh_Tab *new_tab = new cosh_Tab(this);
      new_tab->setObjectName(QStringLiteral("Bill"));

      if (load) {
	new_tab->Link_bill(load);
      } else {
	new_tab->Link_bill(controller.New_bill());
      }
	
      QVBoxLayout *verticalLayout_3;
      QFrame *frame_2;
      QPushButton *AddItemButton;
      cosh_TableWidget *tableWidget;
      QLabel *paidByLabel;
      QComboBox *BillPayerCombo;

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

      paidByLabel = new QLabel(frame_2);
      paidByLabel->setObjectName(QStringLiteral("paidbylabel"));
      paidByLabel->setGeometry(QRect(150,10,50,24));
      paidByLabel->setText(QString("Paid by:"));

      BillPayerCombo = new QComboBox(frame_2);
      BillPayerCombo->setObjectName(QStringLiteral("BillPayerCombo"));
      BillPayerCombo->setGeometry(QRect(200,10,100,24));

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
	//Columns:
	QTableWidgetItem *tableitem = new QTableWidgetItem();
	font.setBold(false);
	tableitem->setFont(font);
	tableWidget->setHorizontalHeaderItem(i+2, tableitem);
	tableitem->setText(payers[i]);
	//Populate combobox:
	BillPayerCombo->addItem(QString());
	BillPayerCombo->setItemText(i,payers[i]);
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
      QObject::connect(tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)),
		       new_tab, SLOT(handleCell(QTableWidgetItem*)));

      QObject::connect(BillPayerCombo, SIGNAL(currentTextChanged(QString)),
		       new_tab, SLOT(Set_billpayer(QString )));

      QMetaObject::connectSlotsByName(this);

      /* Does bad things when loading file
      //Force payer for new tab's bill
      BillPayerCombo->setCurrentIndex(0);
      new_tab->Set_billpayer(BillPayerCombo->currentText());
      */

      new_tab->Set_pointer_to_table_has_final_bool(tableWidget->Get_has_final_pointer());
            
      this->addTab(new_tab, QString());

      if (index != -1) {
	this->setTabText(index+1,QStringLiteral("Bill"));
      }
      int nbt_index = indexOf(new_bill_tab);
      this->tabBar()->moveTab(nbt_index,nbt_index+1);
      this->setCurrentIndex(indexOf(new_bill_tab)-1);

      std::cout << "I will return : " << (void*)new_tab << std::endl;
      return new_tab;
    }
    std::cout << "I WILL RETURN NULL!" << std::endl;
    return NULL;
  }

  void Calculate()
  {
    std::cout << "controller calculate" << std::endl;
    
    std::vector<int_fract> computed = controller.Calculate();

    std::cout << "vector computed" << std::endl;

    if (computed.empty()) {
      return;
    }

    

    //Make new line with computed values on every billtab:
    for (std::vector<cosh_TableWidget*>::iterator table_iter = table_v.begin();
	 table_iter != table_v.end(); ++table_iter) {

      QObject::disconnect(*table_iter,
			  SIGNAL(itemChanged(QTableWidgetItem*)),
			  (*table_iter)->parent(),
			  SLOT(handleCell(QTableWidgetItem*)));

      std::cout << "table from "
		<< ((cosh_Tab*) ((*table_iter)->parent()))->Get_bill()->Get_name()
		<< std::endl;

      int line_index = (*table_iter)->Add_final();

      std::cout << "lineindex: " << line_index << std::endl;
      
      QTableWidgetItem *item_handle = (*table_iter)->item(line_index, 0);

      for (int i = 0; i < (*table_iter)->columnCount(); ++i) {
	for (int j = 0; j < (*table_iter)->rowCount(); ++j) {
	  std::cout << j << "," << i << ": " << ((void*)((*table_iter)->item(j,i))) << std::endl;
	}
      }

      std::cout << "address of itemhandle " << ((void*)item_handle) << std::endl;
      std::cout << "Rows in table: " << (*table_iter)->rowCount() << std::endl;
      std::cout << "Columns in table: " << (*table_iter)->columnCount() << std::endl;
      
      item_handle->setText(QStringLiteral("TOTAL"));
      
      std::cout << "set text" << std::endl;
      for (int i = 0; i < computed.size(); ++i) {
	item_handle = (*table_iter)->item(line_index, i+1);
	//QString str = QString::number(computed[i]);

	std::string string_fract;
	string_fract = computed[i].To_string();
	
	QString str = QString::fromStdString(string_fract);
	
	//str.insert(str.size()-2,QString("."));
	item_handle->setText(str);
      }

      QObject::connect(*table_iter,
		       SIGNAL(itemChanged(QTableWidgetItem*)),
		       (*table_iter)->parent(),
		       SLOT(handleCell(QTableWidgetItem*)));
      
    }
      
  }

private:
  cosh_NewBillTab *new_bill_tab;
  std::vector<cosh_TableWidget*> table_v;
  std::vector<QString> payers;

  //Error: Meta object features not supported for nested class
  //what's a meta object feature?
  //Denested class Rename_window
};

//
class Ui_MainWindow
{
public:
  cosh_Action *actionSave;
  cosh_Action *actionLoad;
  cosh_Action *actionNew;
  cosh_Action *actionExit;
  QWidget *centralwidget;
  QVBoxLayout *verticalLayout_2;
  cosh_TabWidget *tabWidget;
  cosh_NewBillTab *new_bill_tab;
  QFrame *frame;
  QPushButton *addPayerButton;
  QPushButton *calculateButton;
  cosh_LineEdit *lineEdit;
  QMenuBar *menubar;
  QMenu *menuFile;
  //QMenu *menuSettings; //add later if needed
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
    calculateButton = new QPushButton(frame);
    calculateButton->setObjectName(QStringLiteral("calculateButton"));
    calculateButton->setGeometry(QRect(840, 30, 90, 28));
    lineEdit = new cosh_LineEdit(frame);
    lineEdit->setObjectName(QStringLiteral("lineEdit"));
    lineEdit->setGeometry(QRect(10, 20, 171, 28));

    verticalLayout_2->addWidget(frame);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 1034, 22));
    MainWindow->setMenuBar(menubar);

    std::cout << "Doing menus!" << std::endl;

    actionNew = new cosh_Action(MainWindow);
    actionLoad = new cosh_Action(MainWindow);
    actionSave  = new cosh_Action(MainWindow);
    actionExit  = new cosh_Action(MainWindow);

    actionNew->setText(QStringLiteral("New"));
    actionLoad->setText(QStringLiteral("Open"));
    actionSave->setText(QStringLiteral("Save"));
    actionExit->setText(QStringLiteral("Quit"));

    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QStringLiteral("menuFile"));
    menuFile->setTitle(QStringLiteral("File"));

    menubar->addAction(menuFile->menuAction());
    menuFile->addAction(actionNew);
    menuFile->addAction(actionLoad);
    menuFile->addSeparator();
    menuFile->addAction(actionSave);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
	
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QStringLiteral("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

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

    QObject::connect(actionSave, SIGNAL(triggered()), actionSave, SLOT(save()));
    QObject::connect(actionLoad, SIGNAL(triggered()), actionLoad, SLOT(load()));

    QMetaObject::connectSlotsByName(MainWindow);

    repopulate_data();

  } // setupUi

  void repopulate_data()
  {
    
    tabWidget->Repopulate_tabs();
  }


  void retranslateUi(QMainWindow *MainWindow)
  {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(new_bill_tab), QApplication::translate("MainWindow", "+", nullptr));
    addPayerButton->setText(QApplication::translate("MainWindow", "Add payer", nullptr));
    calculateButton->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
    lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "New payer name", nullptr));
  } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _13HEINADCVWZU_H
