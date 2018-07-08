#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>
#include "payer.hpp"
#include "item.hpp"

class Bill
{
public:
  Bill(std::string new_name, Payer *payer);
  std::string Get_name();
  Payer *Get_payer();
  Item *New_item();
  std::vector<Item*> Get_items();
  
  
private:
  std::string name; //Name of store or whatever
  Payer *bill_payer; //Who paid for this bill
  std::vector<Item*> items;

};


#endif
