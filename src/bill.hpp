#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>
#include "payer.hpp"

class Bill
{
public:
  Bill(std::string new_name, Payer payer);
  std::string Get_name();
  Payer Get_payer();
  
private:
  std::string name; //Name of store or whatever
  Payer bill_payer; //Who paid for this bill

};


#endif
