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
  void Set_name(std::string new_name);
  Payer *Get_payer();
  void Set_payer(Payer *new_payer);
  Item *New_item();
  std::vector<Item*> Get_items();
  Item *Get_item(int index);

  int Get_total_price();
  void Update_payer_paid();
  
  
private:
  std::string name; //Name of store or whatever
  Payer *bill_payer; //Who paid for this bill
  std::vector<Item*> items;

};


#endif
