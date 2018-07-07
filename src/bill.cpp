#include <string>
#include <iostream>
#include "payer.hpp"
#include "bill.hpp"


Bill::Bill(std::string new_name, Payer payer):
  name(new_name), bill_payer(payer)
{
}

std::string Bill::Get_name()
{
  return name;
}

Payer Bill::Get_payer()
{
  return bill_payer;
}

Item* Bill::New_item()
{
  Item *nitem = new Item(Payer::Get_total_payers());
  items.push_back(*nitem);
  return nitem;
}

std::vector<Item> Bill::Get_items()
{
  return items;
}
