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

  if (argc == 1) { //Poor man's arg parsing

    const int RESTART = 666;

    std::cout << "QT" << std::endl;

  restart:
    QApplication app(argc,argv);
    Ui_MainWindow test_gui;
    //test_gui.show();
    QMainWindow testmw;
    
    test_gui.setupUi(&testmw);
    testmw.show();
    if (app.exec() == RESTART) goto restart;
    return 0;

  }


  std::cout << "CLI" << std::endl;
  
  All_bills allbills;

  std::string input;

  while (input != "5") {
    std::cout << "1) New payer" << std::endl;
    std::cout << "2) New bill" << std::endl;
    std::cout << "3) Display bills" << std::endl;
    std::cout << "4) Calculate" << std::endl;
    std::cout << "5) End" << std::endl;

    std::cin >> input;

    if (input == "1") {
      Payer *in_payer = new Payer();
      
      std::cout << "Insert name: ";
      std::cin >> input;
      
      in_payer->Set_name(input);
      
      /* //Paid should be calculated by bills paid TODO
      // ps should only be calculated once all data input is in
      int cents_paid;
      
      std::cout << "Insert total paid: ";
      std::cin >> cents_paid;

      in_payer->Set_paid(cents_paid);
      */
      //allbills.payers.push_back(in_payer);
      
      allbills.New_payer(in_payer);

    } else if (input == "2") {
      std::string nameofbill;
      std::cout << "Insert name of bill: ";
      std::cin >> nameofbill;

      std::cout << "Who paid for this bill?" << std::endl;
      
      //std::list<Payer*>::iterator iter = allbills.payers.begin();
      //std::list<Payer*>::iterator iter = allbills.Get_payer_iterator();
      std::vector<Payer*> payer_vector = allbills.Get_payers();
      
      for (int i = 0; i < payer_vector.size(); ++i) {
	std::cout << payer_vector[i]->Get_id() << ") "
		  << payer_vector[i]->Get_name() << std::endl;
      }

      std::cin >> input;
      /*
      iter = allbills.payers.begin();
      for (int i = 0; i < std::stoi(input); ++i) {
	++iter;
      }
      */
      std::cout << "Creating new bill." << std::endl;
      
      Bill *in_bill = new Bill(nameofbill,payer_vector[std::stoi(input)]); //DANGER

      std::cout << "Pushing bill to allbills.bills." << std::endl;
      
      allbills.New_bill(in_bill);


      input = "xxx";
      while (input != "2") {
	std::cout << "1) New item" << std::endl;
	std::cout << "2) Back" << std::endl;

	std::cin >> input;

	if (input == "1") {
	  std::cout << "creating item... " << std::endl;
	  Item *in_item = in_bill->New_item();
	  std::cout << "Input name: ";
	  std::cin >> input;
	  in_item->Set_name(input);
	  
	  int price = -1;
	  std::cout << "Input price: ";
	  std::cin >> price;
	  in_item->Set_price(price);
	}
      }

      //Bill *lastbill = allbills.bills.back();
      std::vector<Bill*> bills = allbills.Get_bills();
      
      
      std::cout << "Bill " << bills.back()->Get_name();
      std::cout	<< ", paid by " << bills.back()->Get_payer()->Get_name()
		<< std::endl;
      
      std::vector<Item*> items = bills.back()->Get_items();
      for (int i = 0; i < items.size(); ++i) {
	std::cout << "\t" << items[i]->Get_name() << ", : "
		  << items[i]->Get_price() << " cents" << std::endl;
      }
      
    } else if (input == "3") {
      input = "x";

      while (input != "exit") {
	
	std::cout << "Bills / Payers";

	std::vector<Payer*> payer_vector = allbills.Get_payers();
      
	for (int i = 0; i < payer_vector.size(); ++i) { //Payer names
	  std::cout << "\t" << payer_vector[i]->Get_name();
	}
	std::cout << std::endl;

	std::vector<Bill*> bill_vector = allbills.Get_bills();
      
	for (int i = 0; i < bill_vector.size(); ++i) { //Bill data
	  std::cout << bill_vector[i]->Get_name() << " Paid by "
		    << bill_vector[i]->Get_payer()->Get_name() << std::endl;

	  for (int j = 0; j < bill_vector[i]->Get_items().size(); ++j) { //Item data
	    Item* item = bill_vector[i]->Get_item(j);
	    std::cout << " -" << item->Get_name();

	    for (int k = 0; k < item->Get_weights()->size(); ++k) { //Item weights
	      std::cout << "\t" << (*item->Get_weights())[k]; 
	    }
	    std::cout << "\t" << item->Get_price() << " cents" << std::endl;
	  
	  }
	  std::cout << std::endl;
	
	}

	std::cout << "Type name of bill to modify" << std::endl
		  << "type \"exit\" to go back" << std::endl;

	std::cin >> input;

	for (int i = 0; i < bill_vector.size(); ++i) {
	  if (input == bill_vector[i]->Get_name()) {
	    Modify_bill(bill_vector[i], allbills);
	  }
	}

      }
      
    } else if (input == "4") {

      allbills.Calculate();

      
      
    }

  }
  std::cout << "" << std::endl;

}

void Modify_bill(Bill *bill, All_bills ab)
{

  std::string input = "x";
  
  std::cout << "n) name    : " << bill->Get_name() << std::endl
	    << "p) paid by : " << bill->Get_payer()->Get_name() << std::endl;
  
  std::vector<Item*> items = bill->Get_items();
  for (int i = 0; i < items.size(); ++i) {
    std::cout << i << ") item    : " << items[i]->Get_name() << " : "
	      << items[i]->Get_price() << " c";

    for (int j = 0; j < items[i]->Get_weights()->size(); ++j) {
      std::cout << "\t" << (*items[i]->Get_weights())[j];
    }
    std::cout << std::endl;
  }

  std::cin >> input;

  if (input == "n") {
    std::cout << "Input new name for bill: ";
    std::cin >> input;
    bill->Set_name(input);
    return;
  } else if (input == "p") {

    std::vector<Payer*> payers = ab.Get_payers();
    for (int i = 0; i < Payer::Get_total_payers(); ++i) {
      std::cout << i << ") " << payers[i]->Get_name() << std::endl;
    }
    std::cout << "Input who paid for this bill: ";
    std::cin >> input;

    bill->Set_payer(payers[std::stoi(input)]);
    return;
  } else {
    if (std::stoi(input) >= items.size()) {
      std::cout << "No such item!" << std::endl;
      return;
    }

    Item *moditem = items[std::stoi(input)];
    int pw;
    
    std::cout << "(p)rice or (w)eight: ";
    std::cin >> input;
    if (input == "p") {
      std::cout << "Input new price: ";
      std::cin >> pw;
      moditem->Set_price(pw);
      
    } else if (input == "w") {
      for (int i = 0; i < Payer::Get_total_payers(); ++i) {
	std::cout << "Input new weights one at a time: " << std::endl;
	std::cin >> pw;
	moditem->Set_weight(i,pw);
      }
    } else {
      std::cout << "wrong input" << std::endl;
      return;
    }

  }
  
}
