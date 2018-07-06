#include <iostream>

#include "payer.hpp"
#include "allbills.hpp"

int main()
{

  struct All_bills allbills;

  std::string input;

  while (input != "4") {
    std::cout << "1) New payer" << std::endl;
    std::cout << "2) New bill" << std::endl;
    std::cout << "3) Calculate" << std::endl;
    std::cout << "4) End" << std::endl;

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

      allbills.payers.push_back(*in_payer);
      
    } else if (input == "2") {
      std::string nameofbill;
      std::cout << "Insert name of bill: ";
      std::cin >> nameofbill;

      std::cout << "Who paid for this bill?" << std::endl;
      //linter doesn't like comma operator for this:
      std::list<Payer>::iterator iter = allbills.payers.begin();
      for (int i = 0; i < allbills.payers.size(); ++i, ++iter) {
	std::cout << iter->Get_id() << ") " << iter->Get_name() << std::endl;
      }

      std::cin >> input;

      iter = allbills.payers.begin();
      for (int i = 0; i < std::stoi(input); i++) {
	++iter;
      }
      
      Bill *in_bill = new Bill(nameofbill,*iter);
      allbills.bills.push_back(*in_bill);
    }


  }
  std::cout << "" << std::endl;

}
