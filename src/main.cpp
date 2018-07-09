#include <iostream>

#include "payer.hpp"
#include "allbills.hpp"

int main()
{

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

      int cents_paid;
      
      std::cout << "Insert total paid: ";
      std::cin >> cents_paid;

      in_payer->Set_paid(cents_paid);

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
      std::cout << "Bills / Payers";

      //std::list<Payer*>::iterator payiter = allbills.payers.begin();
      std::vector<Payer*> payer_vector = allbills.Get_payers();
      
      for (int i = 0; i < payer_vector.size(); ++i) { //Payer names
	std::cout << "\t" << payer_vector[i]->Get_name();
      }
      std::cout << std::endl;

      //std::list<Bill*>::iterator billiter = allbills.bills.begin();
      std::vector<Bill*> bill_vector = allbills.Get_bills();
      
      for (int i = 0; i < bill_vector.size(); ++i) { //Bill data
	std::cout << bill_vector[i]->Get_name() << "Paid by "
		  << bill_vector[i]->Get_payer()->Get_name() << std::endl;

	for (int j = 0; j < bill_vector[i]->Get_items().size(); ++j) { //Item data
	  Item* item = bill_vector[i]->Get_item(j);
	  std::cout << " -" << item->Get_name();

	  for (int k = 0; k < item->Get_weights()->size(); ++k) { //Item weights
	    std::cout << "\t" << (*item->Get_weights())[k]; 
	  }
	  std::cout << std::endl;
	  
	}
	std::cout << std::endl;
	
      }
      
    }

    


  }
  std::cout << "" << std::endl;

}
