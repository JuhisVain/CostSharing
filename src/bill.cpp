#include <string>
#include <iostream>
#include "payer.hpp"
#include "bill.hpp"


Bill::Bill(std::string new_name, Payer *payer):
  name(new_name), bill_payer(payer)
{
}

std::string Bill::Get_name()
{
  return name;
}

void Bill::Set_name(std::string new_name)
{
  name = new_name;
}

Payer* Bill::Get_payer()
{
  return bill_payer;
}

void Bill::Set_payer(Payer *new_payer)
{
  bill_payer = new_payer;
}

Item* Bill::New_item()
{

  std::cout << "bill::newitem()" << std::endl;
  
  
  Item *nitem = new Item(Payer::Get_total_payers());
  items.push_back(nitem);
  return nitem;
}

std::vector<Item*> Bill::Get_items()
{
  return items;
}

Item* Bill::Get_item(int index)
{
  return items[index];
}

int Bill::Get_total_price()
{
  int total = 0;
  for (int i = 0; i < items.size(); ++i) {
    total += items[i]->Get_price();
  }
  return total;
}

void Bill::Update_payer_paid()
{
  bill_payer->Add_paid(Get_total_price());
}
