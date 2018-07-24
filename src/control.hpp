#ifndef CONTROL_H
#define CONTROL_H

#include "allbills.hpp"
#include "bill.hpp"
#include "payer.hpp"
#include "item.hpp"

#include <iostream>
#include <list>
#include <string>
#include <cstring>

class Control
{
public:
  Bill *New_bill();
  void Rename_bill(Bill *bill, std::string name);
  void New_payer(std::string name);
  void New_item(Bill *bill);
  void Rename_item(Bill *bill, int index, std::string name);
  std::string Reprice_item(Bill *bill, int index, std::string price);

private:
  All_bills allbills;

};

#endif